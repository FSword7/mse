/*
 * device.cpp - device handling package
 *
 *  Created on: Jul 5, 2020
 *      Author: Tim Stark
 */

#include "emu/core.h"
#include "emu/sysconfig.h"
#include "emu/device.h"

Device::Device(const SystemConfig &config, const BaseDeviceType &type)
: type(type)
{

}
