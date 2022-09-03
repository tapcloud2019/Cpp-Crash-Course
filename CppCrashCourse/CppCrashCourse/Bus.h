#pragma once

#include "SpeedCarBrake.h"

struct ServiceBus
{
	void publish(const BrakeCommand&);
};