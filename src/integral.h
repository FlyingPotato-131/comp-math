#include <array>
#include <type_traits>

template<typename A>
struct argGetter;

template<typename R, typename arg_t>
struct argGetter<R(arg_t)>{
	using arg = arg_t;
};

template<typename T>
using diff_t = decltype(std::declval<T>() - std::declval<T>());


template<std::size_t N>
constexpr std::array<double, N> points();

template<std::size_t N>
constexpr std::array<double, N> weight();



template<typename func_t, size_t N>
decltype(auto) integrate(const func_t &func, const typename argGetter<func_t>::arg &start, const typename argGetter<func_t>::arg &end){
	std::array<typename argGetter<func_t>::arg, 4> args;
	std::array<typename argGetter<func_t>::arg, 4> weights;

	constexpr auto p = points<N>();
	constexpr auto w = weight<N>();
	
	switch(N){
	case 1:
		args = {0};
		weights = {2};
		break;
	case 2:
		args = {-0.57735, 0.57735};
		weights = {1, 1};
		break;
	case 3:
		args = {-0.774597, 0, 0.774597};
		weights = {0.555556, 0.888889, 0.555556};
		break;
	case 4:
		args = {-0.339981, -0.861136, 0.861136, 0.339981};
		weights = {0.652145, 0.347855, 0.347855, 0.652145};
		break;
	}

	typename argGetter<func_t>::arg sum = 0;
	for(size_t i = 0; i < N; i++){
		sum += weights[i] * func(args[i] * (end - start) / 2 + (end + start) / 2);
		// std::cout << weights[i] * func(args[i] * (end - start) / 2 + (end + start) / 2) << " ";
	}
	// std::cout << sum << " ";
	return (end - start) / 2 * sum;
}

template<typename func_t, size_t N>
decltype(auto) integrate(const func_t &func, const typename argGetter<func_t>::arg &start, const typename argGetter<func_t>::arg &end, const diff_t<typename argGetter<func_t>::arg> &dx){
	// std::cout << (end - start) / dx << " ";
	typename argGetter<func_t>::arg sum = 0;
	for(size_t i = 0; i < int((end - start) / dx); i++){
		sum += integrate<func_t, N>(func, start + i * dx, start + (i + 1) * dx);
	}
	sum += integrate<func_t, N>(func, start + int((end - start) / dx) * dx, end);
	return sum;
}