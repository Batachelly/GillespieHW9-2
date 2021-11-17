/* File name: read_resistance.cpp
 * written by Joshua Gillespie 11/17/2021
 *
 * this program takes no arguments
 * uses the AnalogIn class
 * Reads ADC value on p9.39
 * and calcuates the resistance on the voltage divider circut
 *
 * 
 */

#include <iostream>
#include "AnalogIn.h"

using namespace std;

#define MAX_ADC 4000
#define Vin 1.8f
#define R1 10000

int main(int argc, char* argv[]){
	AnalogIn AIN(0);

	int adc_val=AIN.readADCsample();
	float Vout=(Vin*adc_val)/MAX_ADC;
	float R2=(Vout*R1)/(Vin-Vout);

	cout << "Using AIN" << AIN.getNumber() << " to read analog value." << std::endl;
	cout << "Measuring resistance... " << endl;
	cout << "ADC Value is: " << adc_val << endl;
	cout << "Resistance: " << R2 << "Ohms" << endl;
	cout << endl;
	cout << endl;
}
