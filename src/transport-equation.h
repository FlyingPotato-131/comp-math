#include "mesh.h"

mesh_t corner_solve(double L, double h, double T, double tau, double a, double (*f)(double, double), double (*u)(double)){
	mesh_t mesh(L, h, T, tau);
	for(size_t i = 0; i < L / h + 1; i++){
		mesh(0, i) = u(h * i);
	}
	for(size_t t = 0; t < T / tau; t++){
		mesh(t+1, 0) = mesh(t, L / h);
		for(size_t x = 1; x < L / h + 1; x++){
			mesh(t+1, x) = mesh(t, x) + tau * a / h * (mesh(t, x-1) - mesh(t, x)) + tau * f(t, x);
		}
	}
	return mesh;
}