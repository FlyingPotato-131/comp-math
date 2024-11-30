#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
#include <math.h>
#include "Eigen/Dense"

template<typename T, unsigned int N>
struct derivcoeff{
	T center;
	std::array<T, N> coeffs;
};

template<typename T, unsigned int N, unsigned int L>
derivcoeff<T, N> nderivc(const std::array<T, N>& points) noexcept{
	Eigen::Matrix<T, N+1, N+1> mtr(N+1, N+1);
	std::array<T, (N+1) * (N+1)> mtrarray;
	Eigen::Vector<T, N+1> v;
	for(unsigned int k = 0; k < N+1; k++){
		mtr(0, k) = 1;
	}
	v[0] = 1;
	for(unsigned int h = 1; h < N+1; h++){
		mtr(h, N) = 0;
		for(unsigned int k = 0; k < N; k++){
			mtr(h, k) = pow(points[k], h);
		}
		v[h] = h * v[h - 1];
		if(h - 1 != L)
			v[h - 1] = 0;
	}
	Eigen::Vector<T, N+1> result = mtr.colPivHouseholderQr().solve(v);
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