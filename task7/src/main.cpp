#include <iostream>
#include <sstream>
#include "matrix.h"
#include "gradient.h"

using namespace std;
using namespace gradient;
using namespace matrix;

int main(int argc, char **argv){
	ifstream fin;
	double item;
	vector<double> b;
	fin.open(argv[2]);
	while(true){
		fin >> item;
		if(fin.eof()) break;
		b.push_back(item);
	}
	fin.close();
	
	string s;
	fin.open(argv[1]);
	if (!fin.is_open()) throw IOErrors::NoInputFile;
	getline(fin, s);
	if(s == "Dense"){
		int n = 0, m = -1;
		vector<double> temp_row;
		DenseMatrix a;
		while(true){
			getline(fin, s);
			if(fin.eof()) break;
			stringstream to_double(s);
			while(!to_double.eof()){
				to_double >> item;
				a.push_item(item);
				temp_row.push_back(item);
			}
			if(m == -1)
				m = temp_row.size();
			n++;
		}
		a.set_n(n); a.set_m(m);
		auto x = conj_gradient(a, b);
		ofstream out(argv[3]);
		for(int i = 0; i < x.size(); i++)
			out << x[i] << " ";
		out.close();
	}
	else if(s == "Sparse"){
		int j, n = 0, m = -1;
		vector<double> temp_row;
		SparseMatrix a;
		while(true){
			j = 0;
			getline(fin, s);
			if(fin.eof()) break;
			stringstream to_double(s);
			while(!to_double.eof()){
				to_double >> item;
				temp_row.push_back(item);
				if(item != 0) a.add_item(n, j, item);
				j++;
			}
			n++;
			if(m == -1)
				m = temp_row.size();
		}
		a.set_n(n); a.set_m(m);
		auto x = conj_gradient(a, b);
		ofstream out("answer.txt");
		for(int i = 0; i < x.size(); i++)
			out << x[i] << " ";
		out.close();
	}
	else throw IOErrors::IncorrectInputData;
	fin.close();
	return 0;
}
