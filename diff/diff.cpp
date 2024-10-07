#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include "dense-matrix.h"
#include <math.h>

unsigned int factorial(unsigned int N){
	return N == 0 ? 1 : N * factorial(N-1);
}

template<typename T, unsigned int N>
struct derivcoeff{
	T center;
	std::array<T, N> coeffs;
};

template<typename T, unsigned int N, unsigned int L>
derivcoeff<T, N> nderivc(const std::array<T, N>& points) noexcept{
	std::array<T, (N+1) * (N+1)> mtrarray;
	std::array<T, N+1> v;
	for(unsigned int h = 0; h < N+1; h++){
		mtrarray[(h + 1) * (N + 1) - 1] = (h == 0 ? 1 : 0);
		for(unsigned int k = 0; k < N; k++){
			mtrarray[h * (N + 1) + k] = pow(points[k], h);
		}
		v[h] = h == L ? factorial(h) : 0; 
	}
	const denseMatrix<T> mtr(std::vector<T>(mtrarray.begin(), mtrarray.end()), N+1);
	std::vector<T> result = QRsolve(mtr, std::vector<T>(v.begin(), v.end()));
	std::array<T, N> ret;
	std::copy_n(result.begin(), N, ret.begin());
	return {result[N], ret};
}

template<typename T, unsigned int N>
derivcoeff<T, N> derivc(const std::array<T, N> &points) noexcept{
	return nderivc<T, N, 1>(points);
}

template<typename T, unsigned int N, unsigned int L>
T deriv(derivcoeff<T, N> coeff, const std::array<T, N>& values, T x0, T y0, T h){
	T s = y0 * coeff.center;
	for(size_t i = 0; i < N; i++){
		s += coeff.coeffs[i] * values[i];
	}
	return s / pow(h, L);
}