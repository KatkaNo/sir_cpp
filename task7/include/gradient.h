#ifndef GRADIENT_HPP
#define GRADIENT_HPP
#include <vector>
#include <cmath>
#include "matrix.h"

namespace gradient{

	template <typename name1>
	std::vector<name1> add(const std::vector<name1> &a, const std::vector<name1> &b){
		int n = a.size();
		std::vector<name1> res;
		res.resize(n);
		for(int i = 0; i < n; i++){
			res[i] = a[i] + b[i];
		}
		return res;
	}

	template <typename name1>
	std::vector<name1> sub(const std::vector<name1> &a, const std::vector<name1> &b){
		int n = a.size();
		std::vector<name1> res;
		res.resize(n);
		for(int i = 0; i < n; i++){
			res[i] = a[i] - b[i];
		}
		return res;
	}

	template <typename name1>
	name1 scal_mul(const std::vector<name1> &a, const std::vector<name1> &b){
		name1 s = 0;
		for(int i = 0; i < a.size(); i++)
			s += a[i]*b[i];
		return s;
	}

	template <typename name1>
	std::vector<name1> mul_by_num(name1 k, const std::vector<name1> &a){
		std::vector<name1> res;
		res.resize(a.size());
		for(int i = 0; i < a.size(); i++)
			res[i] = a[i] * k;
		return res;
	}

	template <typename name1, typename name2>
	std::vector<name1> conj_gradient(const name2 &matrix, const std::vector<name1> &b){
		name1 alpha, beta;
		std::vector<name1> temp, temp2;
		name1 b_norm = sqrt(scal_mul(b, b));
		int n = b.size();
		std::vector<name1> r1;
		std::vector<name1> x0;
		x0.resize(n);
		temp = matrix.mul_by_vector(x0);
		std::vector<name1> r0 = sub(b, temp);
		std::vector<name1> z0 = r0;
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


#endif
