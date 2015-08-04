#ifndef LUNAR_H
#define LUNAR_H

namespace lunarLander
{
	class Lunar
	{
		public:
			//Constructor
			Lunar();
			//Destructor
			~Lunar();
			
			void setFuelRate(float fuelRatei);
			void setVert_Speed(float vert_Speedi);
			void setAlt(float alti);
			void setFuel(float fueli);
			void setMass(float massi);
			void setMaxFuelRate(float maxFuelRatei);
			void setMaxThrust(float maxThrusti);
			
			float getFuelRate() const;
			float getVert_Speed() const;
			float getAlt() const;
			float getFuel() const;
			float getMass() const;
			float getMaxFuelRate() const;
			float getMaxThrust() const;
			
			void fuelRateChange();
			void time();
	
		private:
			float fuelRate, vert_Speed, alt, fuel, mass, 			  		  maxFuelRate, maxThrust; 
	
	

	};
}

#endif
