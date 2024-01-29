#include "gradient.h"

namespace gradient{
std::vector<double> add(const std::vector<double> &a, const std::vector<double> &b){
	int n = a.size();
	std::vector<double> res;
	res.resize(n);
	for(int i = 0; i < n; i++){
		res[i] = a[i] + b[i];
	}
	return res;
}
std::vector<double> sub(const std::vector<double> &a, const std::vector<double> &b){
	int n = a.size();
	std::vector<double> res;
	res.resize(n);
	for(int i = 0; i < n; i++){
		res[i] = a[i] - b[i];
	}
	return res;
}
double scal_mul(const std::vector<double> &a, const std::vector<double> &b){
	double s = 0;
	for(int i = 0; i < a.size(); i++)
		s += a[i]*b[i];
	return s;
}
std::vector<double> mul_by_num(double k, const std::vector<double> &a){
	std::vector<double> res;
	res.resize(a.size());
	for(int i = 0; i < a.size(); i++)
		res[i] = a[i] * k;
	return res;
}

std::vector<double> conj_gradient(const matrix::Matrix &matrix, const std::vector<double> &b){
	double alpha, beta;
	std::vector<double> temp, temp2;
	double b_norm = sqrt(scal_mul(b, b));
	int n = b.size();
	std::vector<double> r1;
	std::vector<double> x0;
	x0.resize(n);
	temp = matrix.mul_by_vector(x0);
	std::vector<double> r0 = sub(b, temp);
	std::vector<double> z0 = r0;
	for(int i = 0; i < n; i++){
		temp = matrix.mul_by_vector(z0);
		alpha = scal_mul(r0, r0) / scal_mul(temp, z0);
		x0 = add(x0, mul_by_num(alpha, z0));
		r1 = sub(r0, mul_by_num(alpha, temp));
		beta = scal_mul(r1, r1) / scal_mul(r0, r0);
		z0 = add(r1, mul_by_num(beta, z0));
		r0 = r1;
	}
	return x0;
}
}