#include <iostream>
#include <math.h>
#include <functional>
#include "integral.h"

int main(){
	//N = 1
	std::cout << "N=1,\n";
	float I_true = cos(0) - cos(10);
	for(int n = 1; n < 100; n++){
		float I = integrate<float(float), 1>(sin, 0, 10, 1.0 / n);
		std::cout << 1.0 / n << "," << abs(I - I_true) << "\n";
	}
	std::cout << "\n\n";

	//N = 4
	std::cout << "N=4,\n";
	for(int n = 1; n < 100; n++){
		float I = integrate<float(float), 4>(sin, 0, 10, 1.0 / n);
		std::cout << 1.0 / n << "," << abs(I - I_true) << "\n";
	}
	std::cout << "\n\n";

	//richardson
	std::cout << "richardson,\n";
	int n = 100;
	float I_2h = integrate<float(float), 4>(sin, 0, 10, 1.0 / n);
	float I_h = integrate<float(float), 4>(sin, 0, 10, 0.5 / n);
	int p = 2 * (4 + 1) - 1;
	float I = I_h - (I_2h - I_h) / (pow(2, p+1) - 1);
	std::cout << 1.0 / n << "," << abs(I - I_true) << "\n";
}