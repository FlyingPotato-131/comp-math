#include "../../src/transport-equation.h"
#include <iostream>

double f(double t, double x){
	return 0;
}

double u(double x){
	return x < 2 ? 1 : 0;
}

int main(){
	double T = 18;
	double tau = 0.25;
	double L = 20;
	double h = 0.5;
	mesh_t mesh = corner_solve(L, h, T, tau, 1, f, u);
	for(size_t t = 0; t < T / tau + 1; t++){
		for(size_t x = 0; x < L / h + 1; x++){
			std::cout << mesh(t, x) << " ";
		}
		std::cout << "\n";
	}
}