#include "../../src/backwards-diff.h"
#include "../../Eigen/Dense"
#include <array>
#include <iostream>
#include <math.h>

double absv(const Eigen::Vector<double, 2> v){
	return sqrt(v.dot(v));
}

struct bdf4{
	static constexpr size_t steps = 4;
	static constexpr std::array<double, steps + 1> coeffs = {-48.f / 25.f, 36.f / 25.f, -16.f / 25.f, 3.f / 25.f, 12.f / 25.f};
};

struct rk4table{
	static constexpr size_t steps = 4;
	static constexpr std::array<std::array<double, steps>, steps> amtr = {std::array<double, steps>{0.f, 0.f, 0.f, 0.f}, std::array<double, steps>{0.5, 0.f, 0.f, 0.f}, std::array<double, steps>{0.f, 0.5, 0.f, 0.f}, std::array<double, steps>{0.f, 0.f, 1.f, 0.f}};
	static constexpr std::array<double, steps> bstr = {1.f/6, 1.f/3, 1.f/3, 1.f/6};
	static constexpr std::array<double, steps> ccol = {0, 0.5, 0.5, 1};
};

struct p1{
	static constexpr size_t dim = 1;
	using time = double;
	using vals = double;
	struct coord{
		time t;
		vals v;
	};

	double calc(const coord &current) const {
		return current.t * current.t * current.t;
	}
};

struct p2{
	static constexpr size_t dim = 2;
	using time = double;
	using vals = Eigen::Vector<double, dim>;
	struct coord{
		time t;
		vals v;
	};

	Eigen::Vector<double, dim> calc(const coord &current) const {
		return Eigen::Vector<double, dim>{-current.v[1], current.v[0]};
	}
};

int main(){
	p1 f1;
	for(double h = 2.5; h >= 0.09; h-=0.05){
		std::vector<p1::coord> solution = bdintegrate<bdf4, p1, rk4table>({0, 0}, 5, h, 1e-10, 100, f1);
		double err = 0;
		for(p1::coord current : solution){
			if(abs(current.v - pow(current.t, 4) / 4) > err)
				err = abs(current.v - pow(current.t, 4) / 4);
		}
		std::cout << h << "," << err << "\n";
	}
	std::cout << "\n";

	p2 f2;
	for(double h = 2; h >= 0.04; h-=0.05){
		std::vector<p2::coord> solution = bdintegrate<bdf4, p2, rk4table>({0, {1, 0}}, 5, h, 1e-10, 100, f2, absv);
		double err = 0;
		for(p2::coord current : solution){
			if(abs(current.v[1] - sin(current.t)) > err)
				err = abs(current.v[1] - sin(current.t));
		}
		std::cout << h << "," << err << "\n";
	}
	std::cout << "\n";

}