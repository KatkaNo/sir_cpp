#ifndef GRADIENT_HPP
#define GRADIENT_HPP
#include <vector>
#include <cmath>
#include "matrix.h"

namespace gradient{
	std::vector<double> add(const std::vector<double> &a, const std::vector<double> &b);
	std::vector<double> sub(const std::vector<double> &a, const std::vector<double> &b);
	double scal_mul(const std::vector<double> &a, const std::vector<double> &b);
	std::vector<double> mul_by_num(double k, const std::vector<double> &a);
	std::vector<double> conj_gradient(const matrix::Matrix &matrix, const std::vector<double> &b);
}

#endif
