#ifndef LUNARLANDER_H
#define LUNARLANDER_H
class LunarLander {
public:
	LunarLander(); 
	float getCurrentFuelFlow() const; 
	float getVerticleSpeed() const; 
	float getAltitude() const; 
	float getMass() const; 
	float getFullConsumptionRate() const; 
	float getAmountOfFuel() const; 
	float getMaximumThrust() const; 
	void modifyCurrentFuelFlow(); 
	void modifyVelocity(int); 
	void modifyAltitude(int); 
	void modifyRemainingFuel(int); 


private:
	float curr_Fuel; // current fuel
	float verticle_Speed;
	float altitude; 
	float fuel; // overall fuel
	float mass;
	float thrust;
	float fuel_ConsumptionRate; // fuel loss per second
};
#endif