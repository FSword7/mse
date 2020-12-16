/*
 * map.h - Mapping system bus package
 *
 *  Created on: Dec 12, 2020
 *      Author: Tim Stark
 */

#pragma once

// address space types
#define AS_PROGRAM  0	// Program address space
#define AS_DATA		1	// Data address space
#define AS_IO		2	// I/O port address space

//using offs_t = uint64_t;
typedef uint64_t offs_t;

class ProcessorDevice;

class mapAddressConfig
{
public:
	mapAddressConfig() = default;
	mapAddressConfig(ctag_t *name, uint16_t dWidth, uint16_t aWidth, int16_t aShift);
	~mapAddressConfig() = default;

	// Getter function calls
	inline ctag_t *getName() const { return name; }

	inline uint16_t getDataWidth() const { return dataWidth; }
	inline uint16_t getDataRadix() const { return dataRadix; }
	inline uint16_t getAddrWidth() const { return addrWidth; }
	inline uint16_t getAddrRadix() const { return addrRadix; }
	inline int16_t  getAddrShift() const { return addrShift; }
	inline int16_t  getPageShift() const { return pageShift; }

private:
	ctag_t *name = nullptr;

	uint16_t dataWidth = 0;
	uint16_t dataRadix = 0;
	uint16_t addrWidth = 0;
	uint16_t addrRadix = 0;
	int16_t  addrShift = 0;
	int16_t  pageShift = 0;
};

class mapAddressSpace
{
public:
	mapAddressSpace() = default;
	virtual ~mapAddressSpace() = default;

	inline uint16_t getDataWidth() const { return config.getDataWidth(); }
	inline uint16_t getDataRadix() const { return config.getDataRadix(); }
	inline uint16_t getAddrWidth() const { return config.getAddrWidth(); }
	inline uint16_t getAddrRadix() const { return config.getAddrRadix(); }
	inline int16_t  getAddrShift() const { return config.getAddrShift(); }
	inline int16_t  getPageShift() const { return config.getPageShift(); }

	// Virtual function calls
	virtual uint8_t  read8(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint16_t read16(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint16_t read16u(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint32_t read32(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint32_t read32u(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint64_t read64(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;
	virtual uint64_t read64u(offs_t addr, ProcessorDevice *cpu = nullptr) = 0;

	virtual void write8(offs_t addr, uint8_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write16(offs_t addr, uint16_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write16u(offs_t addr, uint16_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write32(offs_t addr, uint32_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write32u(offs_t addr, uint32_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write64(offs_t addr, uint64_t data, ProcessorDevice *cpu = nullptr) = 0;
	virtual void write64u(offs_t addr, uint64_t data, ProcessorDevice *cpu = nullptr) = 0;

protected:
	mapAddressConfig &config;
};

class mapMemoryBlock
{
public:
	mapMemoryBlock(mapAddressSpace &space, offs_t sAddr, offs_t eAddr, void *base = nullptr);
	~mapMemoryBlock() = default;

	inline offs_t getStartAddress() const { return addrStart; }
	inline offs_t getEndAddress() const   { return addrEnd; }
	inline uint8_t *getData() const       { return dataBase; }
	inline offs_t getSize() const         { return dataSize; }

private:
	mapAddressSpace &space;

	offs_t   addrStart;
	offs_t   addrEnd;
	uint8_t *dataBase;
	offs_t   dataSize;

	vector<uint8_t> allocated;
};
