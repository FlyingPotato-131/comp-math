#include "../../src/simple-iter.h"
#include <iostream>
#include <math.h>

double F(double x){return x * x + tan(x) * tan(x) - 1;}

int main(){
	double x1 = solveSIM<double(double)>(F, 0.14, 1, 30, 1e-6);
	double y1 = tan(x1);
	std::cout << x1 << " " << y1 << "\n";

	double x2 = solveSIM<double(double)>(F, -0.14, -1, 30, 1e-6);
	double y2 = tan(x2);
	std::cout << x2 << " " << y2 << "\n";
}
