/*
 * romentry.h - ROM entry
 *
 *  Created on: Feb 14, 2021
 *      Author: Tim Stark
 */

// Per-region entry flags
#define ROM_TYPE_MASK		0x0000000F	// Entry type
#define ROM_BITWIDTH		0x00000030  // Bit width (0=8-bit, 1=16-but, 2=32-bit, 3=64-bit)
#define ROM_ENDIANESS		0x00000040  // Endianess type (0=Little-endian, 1=Big-endian)
#define ROM_INVERT_DATA		0x00000080	// Inverted data
#define ROM_FILL_DATA		0x00008000  // Filled data
#define ROM_FILL_VAL		0x00FF0000	// Fill value (before loading)

// Per-image entry flag definitions



#define SET_WIDTH(x)		(((x) & 0x3) << 4)
#define SET_FILL(x)			((((x) & 0xFF) << 16) | ROM_FILL_DATA)

#define	GET_WIDTH(x)		((x) >> 4) & 0x3)
#define GET_FILL(x)			((x) >> 16) & 0xFF)


// ROM entry type token definitions
#define ROM_TYPE_END		0			// End of ROM entry table
#define ROM_TYPE_REGION		1			// Region entry
#define ROM_TYPE_IMAGE		2			// ROM image space
#define ROM_TYPE_FILL		3			// Filling ROM space

// Per-region ROM bit width definitions
#define ROM_REGION_8BIT		0x00000000	// 8-bit data width
#define ROM_REGION_16BIT	0x00000010	// 16-bit data width
#define ROM_REGION_32BIT	0x00000020	// 32-bit data width
#define ROM_REGION_64BIT	0x00000030	// 64-bit data width

// Per-region Endianess flag definitions
#define ROM_REGION_LE		0x00000000	// Little-endian
#define ROM_REGION_BE		0x00000040	// Big-endian

// Per-region invert flag definitions
#define ROM_REGION_NORMAL	0x00000000	// Normal data
#define ROM_REGION_INVERT	0x00000080	// Inverted data

// Per-region erase (filling) value definitions
#define ROM_ERASEVAL(x)		SET_FILL(x)
#define ROM_ERASE00			SET_FILL(0x00)
#define ROM_ERASEFF			SET_FILL(0xFF)


#define ROM_END		{ nullptr, nullptr, ROM_TYPE_END }


struct romEntry_t
{
	ctag_t		*name;		// Region/file name
	ctag_t		*hash;		// Hash checksum string
	uint32_t	flags;		// ROM entry flags
};
