#include <iostream>
#include <cmath>
#include <bitset>
#include "float_shredder/float_shredder.h"

int main (int argc, char** argv) {
	float input_float;
	std::cout << "Enter the float value you want to analyze: ";
	std::cin >> input_float;
	std::cout << "" << std::endl;


	std::cout << "The binary representation of your float is: " << std::endl;
	std::cout 
		<< std::bitset<32>(shredder_raw_float_data(input_float)) 
		<< std::endl;
	std::cout << "" << std::endl;

	std::cout << 
		"The binary representation of the float's unbiased exponent is: " 
		<< std::endl;
	std::cout << std::bitset<8>(shredder_float_exp_unbiased(input_float)) << std::endl;
	std::cout << "The decimal representation of the float's unbiased exponent is: "
		<< std::endl;
	std::cout << shredder_float_exp_unbiased(input_float) << std::endl;
	std::cout << "" << std::endl;

	std::cout 
		<< "IEEE 754 32-bit floats have a bias of 2^(e-1)-1, "
		<< "where e is the bits of the exponent. ";
	std::cout << "In this case, the bias is 127" << std::endl;
	std::cout 
		<< "We subtract the raw exponent value by the bias to get the true exponent value"
		<< std::endl;
	std::cout << "" << std::endl;

	std::cout << "The float's true (biased) exponent is: " << std::endl;
	std::cout << shredder_float_exp_biased(input_float) << std::endl;
	std::cout << "" << std::endl;

	std::cout << 
		"The binary value of the mantissa (the fractional part of the number in binary scientific notation)"
		<< std::endl;
	std::cout << std::bitset<23>(shredder_raw_float_mantissa(input_float)) << std::endl;
	std::cout << "The decimal value of the mantissa is: " << std::endl;
	std::cout << shredder_mantissa(input_float) << std::endl;
	std::cout << "The 1 is implicit if the raw exponent value is greater than 0" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Approximate maximum that can represent this fractional value: " << std::endl;
	std::cout << std::pow(2, (24 + (shredder_float_exp_biased(input_float)))) << std::endl;
}
