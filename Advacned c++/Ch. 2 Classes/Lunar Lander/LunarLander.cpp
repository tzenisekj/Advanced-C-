#include "LunarLander.h"
#include <iostream>

LunarLander::LunarLander() {
	fuel = 1700.0f; // max amount of fuel
	mass = 1700.0f + 900.0f; // default is 900 + fuel
	thrust = 5000.0f; // velocity based on newtons
	verticle_Speed = 0.0f; // speed of craft going up
	altitude = 1000.0f; // height of aircraft
	curr_Fuel = 1700.0f / 1; // fractional to max fuel amount
	fuel_ConsumptionRate = 10.0f; // 10 kg's a second
}

float LunarLander::getCurrentFuelFlow() const {
	return curr_Fuel; 
}

float LunarLander::getVerticleSpeed() const {
	return verticle_Speed; 
}

float LunarLander::getAltitude() const {
	return altitude; 
}

float LunarLander::getMass() const {
	return mass; 
}

float LunarLander::getFullConsumptionRate() const {
	return fuel_ConsumptionRate; 
}

float LunarLander::getAmountOfFuel() const {
	return fuel; 
}

float LunarLander::getMaximumThrust() const {
	return thrust; 
}

void LunarLander::modifyCurrentFuelFlow() {
	
}

void LunarLander::modifyAltitude(int num) {

}

void LunarLander::modifyVelocity(int num) {

}

void LunarLander::modifyRemainingFuel(int num) {

}