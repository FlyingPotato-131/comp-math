#include <math.h>

double kepplerSolver(double e, double meanAnomaly, size_t maxIter, double tolerance){
	double eccAnomaly = meanAnomaly;
	for(size_t i = 0; i < maxIter; i++){
		double tmp = eccAnomaly - (eccAnomaly - e * sin(eccAnomaly) - meanAnomaly) / (1 - e * cos(eccAnomaly));
		if(abs(tmp - eccAnomaly) <= tolerance)
			return tmp;
		eccAnomaly = tmp;
	}
	return eccAnomaly;
}