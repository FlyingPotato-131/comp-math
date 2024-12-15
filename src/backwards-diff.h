#include <vector>
#include "runge-kutta.h"
#include "simple-iter.h"

template<typename rhs>
using bd_abs_t = double(typename rhs::vals);

template<typename bdf, typename rhs, typename abs_t>
struct arg_t{ //argument type to pass additional arguments into function for simple iteration method
	typename rhs::vals y;
	double h;
	typename rhs::vals inc;
	typename rhs::time t;
	rhs f;
	abs_t *absy; //absolute value function for rhs::vals
};

template<typename bdf, typename rhs, typename abs_t>
arg_t<bdf, rhs, abs_t> operator-(arg_t<bdf, rhs, abs_t> a, arg_t<bdf, rhs, abs_t> b){
	return {a.y - b.y, a.h, a.inc, a.t, a.f, a.absy};
}

template<typename bdf, typename rhs, typename abs_t>
arg_t<bdf, rhs, abs_t> operator*(double a, arg_t<bdf, rhs, abs_t> args){
	return {a * args.y, args.h, args.inc, args.t, args.f, args.absy};
}

template<typename bdf, typename rhs, typename abs_t>
arg_t<bdf, rhs, abs_t> F(arg_t<bdf, rhs, abs_t> args){
	return {bdf().coeffs[bdf().steps] * args.h * args.f.calc({args.t + args.h, args.y}) - args.inc - args.y, args.h, args.inc, args.t, args.f, args.absy};
}

template<typename bdf, typename rhs, typename abs_t>
double absa(arg_t<bdf, rhs, abs_t> args){ //abs of argument type is abs of current vector
	return args.absy(args.y);
}

template<typename bdf, typename rhs, typename table>
std::vector<typename rhs::coord> bdintegrate(const typename rhs::coord &initial, const typename rhs::time &endt, const double h, const double tol, const double maxiter, const rhs &f, const bd_abs_t<rhs> &absf = std::abs){

	std::vector<typename rhs::coord> ret = rkintegrate<table, rhs>(initial, initial.t + h * bdf().steps, h, f); //acceleration
	ret.resize(size_t((endt - initial.t) / h));

	for(size_t i = bdf().steps - 1; i < size_t((endt - initial.t) / h) - 1; i++){ //step
		typename rhs::vals inc = initial.v - initial.v;
		for(size_t j = 0; j < bdf().steps; j++){
			inc += bdf().coeffs[j] * ret[i - j].v;
		}
		typename rhs::vals approx = bdf().coeffs[bdf().steps] * h * f.calc({ret[i].t, ret[i].v}) - inc; //initial approximation for SIM
		arg_t<bdf, rhs, bd_abs_t<rhs>> approx_args = {approx, h, inc, ret[i].t, f, absf}; //put initial approximation into argument type

		ret[i + 1] = {ret[i].t + h, solveSIM<arg_t<bdf, rhs, bd_abs_t<rhs>>(arg_t<bdf, rhs, bd_abs_t<rhs>>), double>(F, -1, approx_args, maxiter, tol, absa).y};
	}

	return ret;
}