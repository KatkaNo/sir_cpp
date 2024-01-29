#ifndef MATRIX_HPP
#define MATRIX_HPP
#include <string>
#include <vector>
#include <fstream>

enum class IOErrors {NoFileName = -999, NoInputFile, IncorrectInputData, NoOutputFile, CannotWriteData, NoError = 0};
std::string error_name(const IOErrors &error);

namespace matrix{
	class Matrix{
	protected:
		int n, m;
	public:
		inline int get_n() const {return n;};
		inline int get_m() const {return m;};
		virtual std::vector<double> mul_by_vector(const std::vector<double>& vec) const = 0;
	};

	class DenseMatrix : public Matrix{
	private:
		std::vector<double> matrix;
	public:
		void set_n(int n);
		void set_m(int m);
		void push_item(double item);
		void set_item(int i, int j, double item);
		double get_item(int i, int j) const;
		std::vector<double> mul_by_vector(const std::vector<double>& vec) const override;
		friend std::ostream& operator<<(std::ostream& out, DenseMatrix matrix);
	};

	class SparseMatrix : public Matrix{
	private:
		std::vector<int> row_i;
		std::vector<int> col_i;
		std::vector<double> items;
	public:
		void set_n(int n);
		void set_m(int m);
		void add_item(int i, int j, double item);
		double get_item(int i_, int j_) const;
		std::vector<double> mul_by_vector(const std::vector<double>& vec) const override;
		friend std::ostream& operator<<(std::ostream& out, SparseMatrix matrix);
	};
}

#endif
