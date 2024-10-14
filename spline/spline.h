#include "tri-diag-matrix.h"
#include <iostream>

template<typename x_t, typename y_t>
class cspline{
	using dx_t = diff_t<x_t>;
	using ddx_t = divis_t<diff_t<y_t>, dx_t>;
	using ddx2_t = divis_t<diff_t<ddx_t>, dx_t>;

	std::vector<y_t> a;
	std::vector<y_t> b;
	std::vector<ddx_t> k; //N-1 cubic polynomials q(x) as written here https://en.wikipedia.org/wiki/Spline_interpolation#Algorithm_to_find_the_interpolating_cubic_spline
	std::vector<x_t> p_x; //x of given points
	std::vector<y_t> p_y; //y of given points

	const size_t pos(const x_t x, const size_t i, const size_t prev) const{
		// std::cout << x << "; " << prev << " " << i << "\n";
		// std::cout << x << " " << i << "\n";
		return (x >= p_x[i] && x <= p_x[i + 1]) ? i : (x < p_x[i] ? pos(x, (i + prev) / 2 == i ? i - 1 : (i + prev) / 2, prev) : pos(x, (3 * i - prev) / 2 == i ? i + 1 : (3 * i - prev) / 2, i));
	}

public:
	cspline(const std::vector<x_t> &points, const std::vector<y_t> &vals, const ddx2_t &left, const ddx2_t &right);
	y_t interp(const x_t &x) const noexcept;
};

template<typename x_t, typename y_t>
cspline<x_t, y_t>::cspline(const std::vector<x_t> &points, const std::vector<y_t> &vals, const ddx2_t &left, const ddx2_t &right) : a(points.size() - 1), b(points.size() - 1), k(points.size()), p_x(points), p_y(vals){
	size_t N = points.size();
	triDiagMatrix<float> mtr{std::vector<x_t>(N - 1), std::vector<x_t>(N), std::vector<x_t>(N - 1)};
	std::vector<ddx_t> v(N);
	for(size_t i = 1; i < N - 1; i++){ //set up matrix and free vector from 1 to N - 2
		mtr.a[i - 1] = 1 / (points[i] - points[i - 1]);
		mtr.b[i] = 2 / (points[i] - points[i - 1]) + 2 / (points[i + 1] - points[i]);
		mtr.c[i] = 1 / (points[i + 1] - points[i]);
		v[i] = 3 * ((vals[i] - vals[i - 1]) / (points[i] - points[i - 1]) / (points[i] - points[i - 1]) + (vals[i + 1] - vals[i]) / (points[i + 1] - points[i]) / (points[i + 1] - points[i]));
	}

	mtr.b[0] = 2 / (points[1] - points[0]); //set up equation 0
	mtr.c[0] = 1 / (points[1] - points[0]);
	v[0] = 3 * (vals[1] - vals[0]) / (points[1] - points[0]) / (points[1] - points[0]) - left / 2;

	mtr.a[N - 2] = 1 / (points[N - 1] - points[N - 2]); //set up equation N - 1
	mtr.b[N - 1] = 2 / (points[N - 1] - points[N - 2]);
	v[N - 1] = 3 * (vals[N - 1] - vals[N - 2]) / (points[N - 1] - points[N - 2]) / (points[N - 1] - points[N - 2]) + right / 2;

	k = thomasMethod(mtr, v); //solve

	for(size_t i = 0; i < N - 1; i++){
		a[i] = k[i] * (points[i + 1] - points[i]) - vals[i + 1] + vals[i];
		b[i] = -k[i + 1] * (points[i + 1] - points[i]) + vals[i + 1] - vals[i];
	}
}

template<typename x_t, typename y_t>
y_t cspline<x_t, y_t>::interp(const x_t &x) const noexcept{
	const size_t i = pos(x, p_x.size() / 2, 0);
	x_t t = (x - p_x[i]) / (p_x[i + 1] - p_x[i]);
	return (1 - t) * p_y[i] + t * p_y[i + 1] + t * (1 - t) * ((1 - t) * a[i] + t * b[i]);
}