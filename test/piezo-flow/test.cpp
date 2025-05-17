#include "../../src/piezo-flow.h"
#include <iostream>

int main(){
	mesh_t mesh = piezo_solve(1, 3600);
	for(size_t t = 0; t < mesh.data.size() / mesh.width; t++){
	// for(size_t t = 0; t < 4; t++){
		for(size_t x = 0; x < mesh.width - 1; x++){
			std::cout << mesh(t, x) << ",";
		}
		std::cout << mesh(t, mesh.width - 1) << "\n";
	}
}