/// \file	DeviceTreeDevice.h
/// \brief	Interface of the class DeviceTreeDevice.
///
/// \version 	1.0
/// \date		2017
/// \copyright	SPDX: BSD-3-Clause 2016-2017 Trenz Electronic GmbH

#pragma once

#include <memory>	// std::shared_ptr
#include <string>	// std::string
#include <map>		// std::map

#include <stdint.h>	// uint32_t


/// Fetch information from the Linux Device Tree.
/// @code
///	std::shared_ptr<DeviceTreeDevice>	dev = DeviceTreeDevice::findByProperty("compatible", "foc");
///	if (dev) {
///		printf("Device found at %p\n", (void*)dev->address);
///	} else {
///		printf("FOC device not found.\n");
///	}
/// @endcode
class DeviceTreeDevice {
public:
	/// Name of the compatible property: "compatible".
	static const char* const	PROPERTY_COMPATIBLE;

	/// Name of the name property: "trenz.biz,name".
	static const char* const	PROPERTY_TRENZ_BIZ_NAME;

	/// \brief Create new object for fetching data for the given device.
	/// Normally, this should not be called directly.
	/// \param pDeviceDirectoryPath	Absolute path to the device in the device tree.
	/// \param pName		Name of the device.
	/// \param pCompatible		Value of the device tree property "compatible".
	/// \param pAddress		First value in the device tree property "reg".
	/// \param pLength		Second value in the device tree property "reg".
	DeviceTreeDevice(const std::string& pDeviceDirectoryPath, const std::string& pName, const std::string& pCompatible, const uintptr_t pAddress, const unsigned int pLength);

	/// \brief Find the device by the given property value.
	/// This doesn't throw exceptions, just returns empty shared_ptr on errors.
	/// 
	/// \param propertyName		Name of the property to search for.
	/// \param propertyValue	Value of the property to search for.
	/// \return Smart pointer to the device; in the case none found, the pointer will be empty.
	static std::shared_ptr<DeviceTreeDevice>	findByProperty(const char* propertyName, const char* propertyValue);

	/// Read one or more UInt32-s.
	///
	/// \param value		Buffer to store values read.
	/// \param nValues		Number of values to be read.
	/// \param propertyName		Name of the property to read values from.
	/// \return Number of values read, or -1 on failure.
	int readUInt32Array(uint32_t* value, const unsigned int nValues, const char* propertyName) const;

	/// Read property as unsigned 32-bit integer.
	///
	/// \param value		Buffer to store the value read.
	/// \param propertyName		Name of the property to read the value from.
	/// \return 1 on success, 0 when the property doesn't contain enough data, -1 on failure.
	int readUInt32(uint32_t& value, const char* propertyName) const;

	/// Path to the device directory in the device tree.
	const std::string	deviceDirectoryPath;

	/// Name.
	const std::string	name;

	/// Compatible string.
	const std::string	compatible;

	/// HW-address.
	const uintptr_t		address;

	/// Length of the memory area that can be mapped.
	const unsigned int	length;

public:
	/// Small demo program of the capabilities, specific to ARTY-Z7 FOC project.
	static void demo();
};
