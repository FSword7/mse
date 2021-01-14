/*
 * map.cpp - Mapping system bus package
 *
 *  Created on: Dec 12, 2020
 *      Author: Tim Stark
 */

#include "emu/core.h"
#include "emu/dibus.h"
#include "emu/map/addrmap.h"
#include "emu/map/map.h"

using namespace map;

AddressConfig::AddressConfig(ctag_t *tagName, endian_t eType,
	uint16_t dWidth, uint16_t dRadix, uint16_t bWidth,
	uint16_t aWidth, uint16_t aRadix, int16_t aShift)
: name(tagName), endianType(eType),
  dataWidth(dWidth), dataRadix(dRadix), byteWidth(bWidth),
  addrWidth(aWidth), addrRadix(aRadix), addrShift(aShift)
{

}

// **********************************************************************

AddressSpace::AddressSpace(BusManager &manager, diExternalBus &bus, int space)
: config(*bus.getAddressConfig(space)),
  device(*bus.getDevice()), manager(manager),
  space(space)
{

}

void AddressSpace::prepare(Console *cty)
{

	AddressList *map = new AddressList(device, space);

}

// **********************************************************************

MemoryBlock::MemoryBlock(mapAddressConfig &config, offs_t sAddr, offs_t eAddr, void *base)
: config(config), addrStart(sAddr), addrEnd(eAddr),
  dataBase(reinterpret_cast<uint8_t *>(base))
{
	maxSize  = config.convertAddresstoByte(sAddr + 1 - eAddr);
	dataSize = maxSize;

	// allocate memory space as default
	if (dataBase != nullptr)
	{
		allocated.reserve(dataSize);
		memset(&allocated[0], 0, dataSize);
		dataBase = &allocated[0];
	}
}

void MemoryBlock::reserve(offs_t size)
{
	if (size > maxSize)
		size = maxSize;
	allocated.reserve(size);
	memset(&allocated[0], 0, size);
	dataBase = &allocated[0];
	dataSize = size;
}
