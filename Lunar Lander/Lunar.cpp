#include "Lunar.h"
#include <iostream>

namespace lunarLander
{
	Lunar::Lunar()
	{
		fuelRate = 0.0f; 
		vert_Speed = 0.0f;
		alt = 1000.0f;
		fuel = 1700.0f;
		mass = 900.0f;
		maxFuelRate = 10.0f;
		maxThrust = 5000.0f;
	}
	Lunar::~Lunar()
	{
		
	}
	void Lunar::setFuelRate(float fuelRatei)
	{
		if(fuelRatei > 0.0f && fuel == 0.0f)
		{
			fuelRate = 0.0f;
		} 
		else
		{
			fuelRate = fuelRatei;
		}
	}
	void Lunar::setVert_Speed(float vert_Speedi)
	{
		vert_Speed = vert_Speedi;
	}
	void Lunar::setAlt(float alti)
	{
		alt = alti;
	}
	void Lunar::setFuel(float fueli)
	{
		fuel = fueli;
	}
	void Lunar::setMass(float massi)
	{
		mass = massi;
	}
	void Lunar::setMaxFuelRate(float maxFuelRatei)
	{
		maxFuelRate = maxFuelRatei;
	}
	void Lunar::setMaxThrust(float maxThrusti)
	{
		maxThrust = maxThrusti;
	}
	float Lunar::getFuelRate() const
	{
		return fuelRate;
	}
	float Lunar::getVert_Speed() const
	{
		return vert_Speed;
	}
	float Lunar::getAlt() const
	{
		return alt;
	}
	float Lunar::getFuel() const
	{
		return fuel;
	}
	float Lunar::getMass() const
	{
		return mass;
	}
	float Lunar::getMaxFuelRate() const
	{
		return maxFuelRate;
	}
	float Lunar::getMaxThrust() const
	{
		return maxThrust;
	}
	void Lunar::time()
	{
		float t = 0.3f;
		vert_Speed = t * (((fuelRate*maxThrust)/(fuel+mass))-1.62f); 
		alt = alt + (t * vert_Speed);
		if(alt < 0.0f)
		{
			alt = 0.0f;
		}
		fuel = fuel - (t * fuelRate * maxFuelRate);
		if(fuel < 0.0f)
		{
			fuel = 0.0f;
		}
	}
	void Lunar::fuelRateChange()
	{
		std::cin >> fuelRate;
		if(fuel <= 0.0f)
		{
			fuelRate = 0;
		}
		time();
	}
}
