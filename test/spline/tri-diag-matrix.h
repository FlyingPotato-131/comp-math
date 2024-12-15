#include <vector>

template<typename T>
struct triDiagMatrix{
	std::vector<T> a;
	std::vector<T> b;
	std::vector<T> c;
};

template<typename num_t, typename denom_t>
using divis_t = decltype(std::declval<num_t>() / std::declval<denom_t>());

template<typename T>
using diff_t = decltype(std::declval<T>() - std::declval<T>());

template<typename m_t, typename c_t>
std::vector<divis_t<c_t, m_t>> thomasMethod(const triDiagMatrix<m_t> &A, const std::vector<c_t> &f){
	std::vector<divis_t<c_t, m_t>> x(f.size());

	size_t n = f.size() - 1;
	if(x.size() != n + 1){
		x.resize(n + 1);
	}

	std::vector<divis_t<m_t, m_t>> p(n + 1);
	std::vector<divis_t<c_t, m_t>> q(n + 1);
	p[1] = A.c[0] / A.b[0];
	q[1] = f[0] / A.b[0];

	for(size_t i = 2; i <= n; i++){
		p[i] = (A.c[i - 1]) / (-A.a[i-2] * p[i-1] + A.b[i-1]);
		q[i] = (f[i-1] - A.a[i-2] * q[i-1]) / (-A.a[i-2] * p[i-1] + A.b[i-1]);
	}

	x[n] = (f[n] - A.a[n-1] * q[n]) / (-A.a[n-1] * p[n] + A.b[n]);
	for(size_t i = n-1; i > 0; i--){
		x[i] = -p[i+1] * x[i+1] + q[i+1];
	}
	x[0] = -p[1] * x[1] + q[1];
	return x;
}
