#include "spline.h"
#include <iostream>

int main(){
	cspline<float, float> sp({-2, -1, 0, 1, 2}, {0.135, 0.368, 1, 2.718, 7.389}, 0.135, 7.389);
	// for(size_t i = 0; i < 3; i++){
	// 	std::cout << sp.k[i] << " ";
	// }
	// std::cout << "\n";
	std::cout << sp.interp(1.5) << "\n";
}