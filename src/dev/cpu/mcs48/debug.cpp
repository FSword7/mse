/*
 * debug.cpp - MCS-48 microcontroller - debugging routines
 *
 *  Created on: Mar 26, 2021
 *      Author: Tim Stark
 */

#include "emu/core.h"
#include "emu/didebug.h"
#include "dev/cpu/mcs48/mcs48.h"

string mcs48_cpuDevice::getStringAddress(offs_t addr)
{
	string strAddr;

	// Display 12-bit address
	strAddr = fmt::sprintf("%03X", addr & 0xFFF);

	return strAddr;
}

int mcs48_cpuDevice::list(Console *cty, offs_t vAddr)
{
	using namespace aspace;

	AddressSpace *space = getAddressSpace(AS_PROGRAM);
	uint32_t opWord, opc, fnc;
	uint32_t mdpAddr;
	int rb;
	string line, oprLine;

//	opcAlpha *opCode;
//
//	opWord = space->read32(vAddr);
//	opc = OP_GETOP(opWord);
//
//	switch (opc)
//	{
//	case 0x10: opCode = axpCodes10[OP_GETFNC(opWord) & 0x7F];  break;
//	case 0x11: opCode = axpCodes11[OP_GETFNC(opWord) & 0x7F];  break;
//	case 0x12: opCode = axpCodes12[OP_GETFNC(opWord) & 0x7F];  break;
//	case 0x13: opCode = axpCodes13[OP_GETFNC(opWord) & 0x7F];  break;
//	case 0x14: opCode = axpCodes14[OP_GETFNC(opWord) & 0x7F];  break;
//	case 0x15: opCode = axpCodes15[OP_GETFNC(opWord) & 0x7FF]; break;
//	case 0x16: opCode = axpCodes16[OP_GETFNC(opWord) & 0x7FF]; break;
//	case 0x17: opCode = axpCodes17[OP_GETFNC(opWord) & 0x7FF]; break;
//	case 0x18: opCode = axpCodes18[(opWord >> 8) & 0xFF];      break;
//	case 0x1A: opCode = axpCodes1A[OP_GETJMP(opWord)];         break;
//	case 0x1C: opCode = axpCodes1C[OP_GETFNC(opWord) & 0x7F];  break;
//	default:   opCode = axpCodes[opc]; break;
//	}
//
//	line = fmt::sprintf("%s %08X  ", getStringAddress(vAddr), opWord);
//
//	if (opCode == nullptr) {
//		line += fmt::sprintf("<Unknown opcode %02X>", opc);
//		cout << line << endl;
//		return 4;
//	}
//	line += fmt::sprintf("%-10s", opCode->opName);
//	uint32_t opFlags = opCode->opFlags;
//
//	if (opFlags & OPR_RA)
//		oprLine += fmt::sprintf("r%d", OP_GETRA(opWord));
//
//	if (opFlags & OPR_BDP)
//	{
//		if (oprLine.size() > 0)
//			oprLine += ",";
//		oprLine += fmt::sprintf("%llX", vAddr + (OP_GETBDP(opWord) << 2) + 4);
//	}
//	else if (opFlags & OPR_MDP)
//	{
//		if (oprLine.size() > 0)
//			oprLine += ",";
//		mdpAddr = OP_GETMDP(opWord) & 0xFFFF;
//		if ((rb = OP_GETRB(opWord)) < REG_ZERO)
//			oprLine += fmt::sprintf("%04X(r%d)", mdpAddr, rb);
//		else
//			oprLine += fmt::sprintf("%04X", mdpAddr);
//	}
//	else if (opFlags & OPR_RB)
//	{
//		rb = OP_GETRB(opWord) & 0x1F;
//		if (opFlags & OPR_IDX)
//			oprLine += fmt::sprintf("(r%d)", rb);
//		else
//		{
//			if (oprLine.size() > 0)
//				oprLine += ",";
//			if ((opFlags & OPR_LIT) && (opWord & OPC_LIT))
//				oprLine += fmt::sprintf("#%02X", OP_GETLIT(opWord));
//			else
//				oprLine += fmt::sprintf("r%d", rb);
//		}
//	}
//
//	if (opFlags & OPR_RC)
//	{
//		if (oprLine.size() > 0)
//			oprLine += ',';
//		oprLine += fmt::sprintf("r%d", OP_GETRC(opWord) & 0x1F);
//	}
//
//	fmt::printf("%s %s\n", line, oprLine);
//
//	// advance next PC address
//	return 4;
	return 0;
}

void mcs48_cpuDevice::initOpcodeTable()
{
	// Clear all opcode table
	for (int idx = 0; idx < 256; idx++)
		opCodes[idx] = nullptr;

	for (int idx = 0; opTable[idx].opName != nullptr; idx++)
	{
		fmt::printf("Opcode: %s\n", opTable[idx].opName);
	}
}
