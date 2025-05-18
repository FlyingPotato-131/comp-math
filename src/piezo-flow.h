#include "mesh.h"
#include "tri-diag-matrix.h"
#include <iostream>

#define L 500
#define T 864000
#define pin 150 * 1e5
#define pout 50 * 1e5
#define p0 100 * 1e5
#define rho0 1000
#define Cf 1e-4 / 1e5
#define phi 0.2
#define kmu 1e-11

double rho(double p){
	return rho0 * (1 + Cf * (p - p0));
}

mesh_t piezo_solve(double h, double tau){
	mesh_t p(L, h, T, tau); //pressure mesh

	p(0, 0) = pin; //initial conditions
	p(0, L / h) = pout;
	for(size_t x = 1; x < L / h; x++){
		p(0, x) = p0;
	}

	for(size_t t = 0; t < T / tau; t++){
		std::vector<double> d(L / h + 1);
		std::vector<double> a(L / h - 1);
		std::vector<double> b(L / h - 1);
		std::vector<double> c(L / h - 1);

		for(size_t x = 0; x < L / h - 1; x++){ //construct matrix
			double rholeft = rho(std::max(p(t, x), p(t, x+1)));
			double rhoright = rho(std::max(p(t, x+1), p(t, x+2)));
			c[x] = kmu * rholeft / h / h;
			b[x] = kmu * rhoright / h / h;
			a[x] = - c[x] - b[x] - phi * Cf * rho0 / tau;
			d[x+1] = - phi * Cf * rho0 / tau * p(t, x+1);
		}

		p(t+1, 0) = pin; //boundary conditions
		p(t+1, L / h) = pout;

		d[1] = d[1] - c[0] * p(t, 0); //boundary equations
		d[L / h - 1] = d[L / h - 1] - b[L / h - 2] * p(t, L / h);

		triDiagMatrix<double> mtr = {{c.begin() + 1, c.end()}, a, {b.begin(), b.end() - 1}};

		std::vector<double> pnext = thomasMethod(mtr, {d.begin() + 1, d.end() - 1}); //solve matrix

		for(size_t x = 1; x < L / h; x++){
			p(t+1, x) = pnext[x - 1];
		}
	}

	return p;
}