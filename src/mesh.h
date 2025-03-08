#include <vector>

struct mesh_t{
	size_t width;
	std::vector<double> data;

	mesh_t(double L, double h, double T, double t) : width(L / h + 1), data(size_t(L / h + 1) * size_t(T / t + 1)){}

	double &operator()(size_t t, size_t x){
		return data[t * width + x];
	}
};