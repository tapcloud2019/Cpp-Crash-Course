#pragma once

#include "SpeedCarBrake.h"

template <typename T>
struct AutoBrake
{
	AutoBrake(const T& publish);
	void observe(const SpeedUpdate&);
	void observe(const CarDetected&);

private:
	const T& publish;
};