#include <array>
#include <iostream>

template<typename x_t, typename y_t, unsigned int N>
class newtonInterp{
	std::array<y_t, N> coeffs;
	std::array<x_t, N> points;
public:
	newtonInterp(const std::array<x_t, N> &xarr, const std::array<y_t, N> &values) noexcept;
	y_t interp(const x_t &x) const noexcept;
};

template<typename x_t, typename y_t, unsigned int N>
newtonInterp<x_t, y_t, N>::newtonInterp(const std::array<x_t, N> &xarr, const std::array<y_t, N> &values) noexcept : coeffs(values), points(xarr){
	for(size_t w = 1; w < N; w++){
		for(size_t h = N-1; h > w-1; h--){
			coeffs[h] = (coeffs[h] - coeffs[h-1]) / (points[h] - points[h-w]);
		}
	}

	// debug
	// for(size_t i = 0; i < N; i++){
	// 	std::cout << coeffs[i] << " ";
	// }
	// std::cout << "\n";
}

template<typename x_t, typename y_t, unsigned int N>
y_t newtonInterp<x_t, y_t, N>::interp(const x_t &x) const noexcept{
	y_t ret = (x - this->points[N-2]) * this->coeffs[N-1];
	for(size_t i = N-2; i > 0; i--){
		ret = (x - this->points[i-1]) * (this->coeffs[i] + ret);
	}
	return this->coeffs[0] + ret;
}
