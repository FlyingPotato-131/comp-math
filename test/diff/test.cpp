#include <array>
#include <math.h>
#include <iostream>
#include "diff.h"
#include <iostream>

int main(){
	//3
	std::cout << "L=1,N=3\n";
	const std::array<float, 3> args3 = {-1, 1, 2};
	derivcoeff<float, 3> coeff3 = derivc<float, 3>(args3);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 3> vals;
		for(size_t i = 0; i < 3; i++){
			vals[i] = exp(1 + args3[i] * pow(10, pw));
		}
		float d = deriv<float, 3, 1>(coeff3, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";

	//4
	std::cout << "L=1,N=4\n";
	const std::array<float, 4> args4 = {-2, -1, 1, 2};
	derivcoeff<float, 4> coeff4 = derivc<float, 4>(args4);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 4> vals;
		for(size_t i = 0; i < 4; i++){
			vals[i] = exp(1 + args4[i] * pow(10, pw));
		}
		float d = deriv<float, 4, 1>(coeff4, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";

	//5
	std::cout << "L=1,N=5\n";
	const std::array<float, 5> args5 = {-2, -1, 1, 2, 3};
	derivcoeff<float, 5> coeff5 = derivc<float, 5>(args5);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 5> vals;
		for(size_t i = 0; i < 5; i++){
			vals[i] = exp(1 + args5[i] * pow(10, pw));
		}
		float d = deriv<float, 5, 1>(coeff5, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";
	std::cout << "\n";

	//second derivative
	//3
	std::cout << "L=2,N=3\n";
	// const std::array<float, 3> args3 = {-1, 1, 2};
	coeff3 = nderivc<float, 3, 2>(args3);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 3> vals;
		for(size_t i = 0; i < 3; i++){
			vals[i] = exp(1 + args3[i] * pow(10, pw));
		}
		float d = deriv<float, 3, 2>(coeff3, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";

	//4
	std::cout << "L=2,N=4\n";
	// const std::array<float, 4> args4 = {-2, -1, 1, 2};
	coeff4 = nderivc<float, 4, 2>(args4);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 4> vals;
		for(size_t i = 0; i < 4; i++){
			vals[i] = exp(1 + args4[i] * pow(10, pw));
		}
		float d = deriv<float, 4, 2>(coeff4, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";

	//5
	std::cout << "L=2,N=5\n";
	// const std::array<float, 5> args5 = {-2, -1, 1, 2, 3};
	coeff5 = nderivc<float, 5, 2>(args5);
	for(int pw = 1; pw > -16; pw--){
		std::array<float, 5> vals;
		for(size_t i = 0; i < 5; i++){
			vals[i] = exp(1 + args5[i] * pow(10, pw));
		}
		float d = deriv<float, 5, 2>(coeff5, vals, 1, M_E, pow(10, pw));

		float err = abs(d - M_E);
		std::cout << pow(10, pw) << "," << err << "\n";
	}
	std::cout << "\n";
}