/* File name AnalogIn.cpp
 *
 * class for performing deposit, withdraw, and checking balance
 * Written by Joshua Gillespie, november 3, 2021.
 */

#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

#include "AnalogIn.h"

#define ADC_PATH "/sys/bus/iio/devices/iio:device0/in_voltage"

using namespace std;

//constructor.

AnalogIn::AnalogIn(){ }


AnalogIn::AnalogIn(unsigned int n){
	//cout<<"inside constructor"<<endl;
	number = n;
}

void AnalogIn::setNumber(unsigned int n){
	//cout<<"inside setnumber"<<endl;
	number = n;
}

int AnalogIn::readADCsample(){
	//cout<<"readADCsample"<<endl;
	int adc_value;
	std::stringstream ss;
	ss << ADC_PATH << number << "_raw";
	std::fstream fs;
	fs.open(ss.str().c_str(), std::fstream::in);
	fs >> adc_value;
	fs.close();
	return adc_value;
}

AnalogIn::~AnalogIn(){
	//cout <<"destroying the bank account objects before exiting." << endl;
}
