#include <array>
#include <vector>

template<typename table, typename rhs>
std::vector<typename rhs::coord> rkintegrate(const typename rhs::coord &initial, const typename rhs::time &endt, double h, const rhs &f){
	std::vector<typename rhs::coord> ret(size_t((endt - initial.t) / h));
	ret[0] = initial;

	for(size_t i = 0; i < size_t((endt - initial.t) / h) - 1; i++){
		std::array<typename rhs::vals, table().steps> k;
		typename rhs::vals inc = initial.v - initial.v;

		for(size_t j = 0; j < table().steps; j++){ //calculate k values
			typename rhs::vals kinc = initial.v - initial.v;
			for(size_t l = 0; l < j; l++){
				kinc += table().amtr[j][l] * k[l];
			}
			k[j] = f.calc({ret[i].t + h * table().ccol[j], ret[i].v + h * kinc});
			inc += table().bstr[j] * k[j];
		}
		ret[i+1] = {ret[i].t + h, ret[i].v + h * inc};
	}

	return ret;
}