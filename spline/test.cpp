#include "spline.h"
#include <iostream>
#include <vector>
#include <math.h>

int main(){
	//natural spline
	std::cout << "natural,\n";
	for(size_t N = 5; N < 161; N *= 2){
		std::vector<float> args(N);
		std::vector<float> vals(N);
		// std::cout << "test\n";
		for(size_t i = 0; i < N; i++){
			args[i] = 10.0 / (N - 1) * i;
			vals[i] = exp(args[i]);
			// std::cout << args[i] << " ";
		}

		cspline sp(args, vals, 0, 0);
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(sp.interp(i / 100.f) - exp(i / 100.f)) > err)
				err = abs(sp.interp(i / 100.f) - exp(i / 100.f));
		}
		std::cout << N << "," << err << "\n";
	}
	std::cout << "\n\n";

	//unnatural spline
	std::cout << "unnatural,\n";
	for(size_t N = 5; N < 161; N *= 2){
		std::vector<float> args(N);
		std::vector<float> vals(N);
		// std::cout << "test\n";
		for(size_t i = 0; i < N; i++){
			args[i] = 10.0 / (N - 1) * i;
			vals[i] = exp(args[i]);
			// std::cout << args[i] << " ";
		}

		cspline sp(args, vals, 1, exp(10));
		float err = 0;
		for(size_t i = 0; i < 1000; i++){
			if(abs(sp.interp(i / 100.f) - exp(i / 100.f)) > err)
				err = abs(sp.interp(i / 100.f) - exp(i / 100.f));
		}
		std::cout << N << "," << err << "\n";
	}
}