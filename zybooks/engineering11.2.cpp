// Define a function ComputeGasVolume that returns the volume of a gas given
//  parameters pressure, temperature, and moles. Use the gas equation PV = nRT, 
//  where P is pressure in Pascals, V is volume in cubic meters, n is number of 
//  moles, R is the gas constant 8.3144621 ( J / (mol*K)), and T is temperature
// in Kelvin. All parameter types and the return type are double.

#include <iostream>
using namespace std;

const double GAS_CONST = 8.3144621;

// YOUR SOLUTION HERE
double ComputeGasVolume(double& gasPressure, double& gasTemperature, double& gasMoles) {
   volume = (gasMoles * GAS_CONST * gasTemperature) / gasPressure;
   return volume;
}

int main() {
   double gasPressure;
   double gasMoles;
   double gasTemperature;
   double gasVolume;

   cin >> gasPressure;
   cin >> gasMoles;
   cin >> gasTemperature;

   gasVolume = ComputeGasVolume(gasPressure, gasTemperature, gasMoles);
   cout << "Gas volume: " << gasVolume << " m^3" << endl;

   return 0;
}