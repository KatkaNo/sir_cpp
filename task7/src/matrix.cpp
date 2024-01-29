#include "matrix.h"

std::string error_name(const IOErrors &error){
    switch (error){

    case IOErrors::NoFileName:
        return "Filenames are not specified on the command line";
    
    case IOErrors::NoInputFile:
        return "Cannot open input file";

    case IOErrors::IncorrectInputData:
        return "Incorrect data in input file";

    case IOErrors::NoOutputFile:
        return "Cannot open file for writing";

    case IOErrors::CannotWriteData:
        return "Cannot write data to file";

    case IOErrors::NoError:
        return "No error";
    
    default:
        return "Unspecified error";
    }
}


void matrix::DenseMatrix::set_n(int n){
	this->n = n;
}
void matrix::DenseMatrix::set_m(int m){
	this->m = m;
}
void matrix::DenseMatrix::push_item(double item){
	matrix.push_back(item);
}
void matrix::DenseMatrix::set_item(int i, int j, double item){
	matrix[i*n + j] = item;
}
double matrix::DenseMatrix::get_item(int i, int j) const{
	return matrix[i*n + j];
}

std::vector<double> matrix::DenseMatrix::mul_by_vector(const std::vector<double> &vec) const {
	std::vector<double> res;
	res.resize(n);
	double s;
	for(int i = 0; i < n; i++){
		s = 0;
		for(int j = 0; j < m; j++){
			s += get_item(i, j) * vec[j];
		}
		res[i] = s;
	}
	return res;
}
std::ostream& operator<<(std::ostream& out, matrix::DenseMatrix matrix){
	for(int i = 0; i < matrix.get_n(); i++){
		for(int j = 0; j < matrix.get_m(); j++){
			out << matrix.get_item(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}

void matrix::SparseMatrix::set_n(int n){
	this->n = n;
}
void matrix::SparseMatrix::set_m(int m){
	this->m = m;
}
void matrix::SparseMatrix::add_item(int i, int j, double item){
	row_i.push_back(i);
	col_i.push_back(j);
	items.push_back(item);
}
double matrix::SparseMatrix::get_item(int i_, int j_) const{
	int index = -1;
	for(int i = 0; i < row_i.size(); i++){
		if(row_i[i] == i_ && col_i[i] == j_){
			index = i;
			break;
		}
	}
	if(index != -1) return items[index];
	else return 0;
}
std::vector<double> matrix::SparseMatrix::mul_by_vector(const std::vector<double>& vec) const {
	std::vector<double> res;
	res.resize(n);
	double s;
	for(int i = 0; i < n; i++){
		s = 0;
		for(int j = 0; j < m; j++){
			s += get_item(i, j) * vec[j];
		}
		res[i] = s;
	}
	return res;
}
std::ostream& operator<<(std::ostream& out, matrix::SparseMatrix matrix){
	for(int i = 0; i < matrix.get_n(); i++){
		for(int j = 0; j < matrix.get_m(); j++){
			out << matrix.get_item(i, j) << " ";
		}
		out << "\n";
	}
	return out;
}
