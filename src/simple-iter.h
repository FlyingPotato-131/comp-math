#include <math.h>
#include "../Eigen/Dense"

template<typename A>
struct argGetter;

template<typename R, typename arg_t>
struct argGetter<R(arg_t)>{
	using arg = arg_t;
};

template<typename func_t, typename T>
using sim_abs_t = T(typename argGetter<func_t>::arg);

template<typename func_t, typename T>
typename argGetter<func_t>::arg solveSIM(const func_t &f, const T tau, const typename argGetter<func_t>::arg &startApprox, const unsigned int maxIter, const T &tol, const sim_abs_t<func_t, T> &absf = std::abs){
	typename argGetter<func_t>::arg estimate = startApprox;
	for(unsigned int i  = 0; i < maxIter; i++){
		if(absf(f(estimate)) < tol){
			return estimate - tau * f(estimate);
		}
		estimate = estimate - tau * f(estimate);
	}
	return estimate;
}