/*
 * tsunami.h - AlphaServer systems (tsunami family)
 *
 *  Created on: Nov 22, 2020
 *      Author: Tim Stark
 */

#pragma once

#define ES40_NCPU	1 /* up to 4 processors */
#define ES45_NCPU	1 /* up to 32 processors */

class tsunami_sysDevice : public sysDevice
{
public:
	tsunami_sysDevice(const SystemConfig &config, const DeviceType &type, cstag_t &tagName, uint64_t clock)
	: sysDevice(config, type, tagName, clock),
	  config("system", LittleEndian, 64, 16, 8, 44, 16, 0)
	{

	}
	~tsunami_sysDevice() = default;

	// System creator routines
	void es40(SystemConfig &config);
	void es45(SystemConfig &config);

	// Model-specific system initialize routines
	static void es40_init();
	static void es45_init();

	void es40_sbus(aspace::AddressList &map);
	void es45_sbus(aspace::AddressList &map);

private:
	dec21264_cpuDevice *cpu[ES40_NCPU];

	mapAddressConfig config;
};
