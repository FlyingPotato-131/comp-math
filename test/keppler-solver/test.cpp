#include "../../src/keppler-solver.h"
#include <iostream>
#include <math.h>

int main(){
	double eccArray[] = {0.1, 0.2, 0.5, 0.8};
	double solutions[4];
	for(size_t eccI = 0; eccI < 4; eccI++){
		solutions[eccI] = kepplerSolver(eccArray[eccI], M_PI / 4, 100, 1e-6);
		for(size_t i = 1; i < 10; i++){
			std::cout << abs(kepplerSolver(eccArray[eccI], M_PI / 4, i, 0) - solutions[eccI]) << "\n";
		}
		std::cout << "\n";
	}
}
