#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <cmath> // for pow function

//NOTE TO MR. ARK https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

typedef std::vector <double> dvector;
typedef std::vector <dvector> dmatrix;


/**
 * \brief Gets the A matrix from the user.
 * \return A-dmatrix.
 */
dmatrix get_a();

/**
 * \brief Gets the B vector from the user.
 * \param size Size of the expected vector.
 * \return  B-Dvector
 */
dvector get_b(const int & size);


/**
 * \brief Displays the contents of vector x_vector.
 * \param x_vector dvector to display.
 */
void display(const dvector & x_vector);


/**
 * \brief displays the contents of matrix a_matrix (Note: display function is overloaded)
 * \param a_matrix dmatrix to display.
 */
void display(const dmatrix & a_matrix);


/**
 * \brief Solves for systems of linear equations in the form Ax=b using Cramer's rule.
 * \param a_matrix Input matrix.
 * \param b_vector Known values.
 * \return returns unknown dvector X
 */
dvector solve_x(const dmatrix & a_matrix, const dvector & b_vector);


/**
 * \brief Uses recursion to determine the determinant of a matrix. Base case is 2x2.
 * \param a_matrix Input matrix.
 * \return The Determinant of a_matrix.
 */
double det(const dmatrix & a_matrix);


/**
 * \brief Replaces a column with a vector.
 * \param replace_matrix The matrix to replace a column in.
 * \param col Column position.
 * \param b_vector What to replace with.
 * \return Matrix with the replaced column.
 */
dmatrix replace(dmatrix replace_matrix, int col, const dvector & b_vector);


/**
 * \brief Gets the minor matrix of a_matrix by crossing out the first row and a column position.
 * \param a_matrix The matrix to perform the operation on.
 * \param col Column position.
 * \return The smaller matrix
 */
dmatrix minor(const dmatrix & a_matrix, int col);


//-------------------------------------------
int main() {

	auto a_matrix = get_a();
	display(a_matrix);
	const auto b_vector = get_b(a_matrix.size());
	const auto x_vector = solve_x(a_matrix, b_vector);
	display(x_vector);

	return (0);
}
//-------------------------------------------

dmatrix get_a() {
	std::cout << "Please input Columns A. Format: <Matrix Size> <A11> <A12> <A13> etc." << std::endl;
	int index;
	scanf("%d", &index);
	auto matrix = dmatrix();
	matrix.reserve(index);

	for (auto i = 0; i < index; i++)
	{
		auto row = dvector();
		row.reserve(index);

		for (auto o = 0; o < index; o++)
		{
			double elem = 0;
			scanf("%lf", &elem);
			row.push_back(elem);
		}
		matrix.push_back(row);
	}
	return matrix;
}

dvector get_b(const int & size) {
	std::cout << "Please input Column B. Format: <b1> <b2> <b3> etc." << std::endl;
	auto vec = dvector();
	for (auto i = 0; i < size; i++)
	{
		double elem = 0;
		scanf("%lf", &elem);
		vec.push_back(elem);
	}
	return vec;
}

void display(const dvector & x_vector) {
	std::cout << std::endl;
	for (auto i : x_vector)
	{
		std::cout << i << " " << std::endl;
	}
	std::cout << std::endl;
}

void display(const dmatrix & a_matrix) {
	std::cout << std::endl;
	for (const auto & i : a_matrix)
	{
		for (auto j : i)
			std::cout << j << " ";
		std::cout << std::endl;
	}
}

dvector solve_x(const dmatrix & a_matrix, const dvector & b_vector) {
	auto solution = dvector();
	for (size_t i = 0; i < a_matrix.size(); i++)
	{
		solution.push_back(det(replace(a_matrix, i, b_vector)) / det(a_matrix));
	}
	return solution;
}

double det(const dmatrix & a_matrix) {
	auto det_value = 0.0;
	if (a_matrix.size() == 1)
	{
		return a_matrix[0][0];
	}
	if (a_matrix.size() == 2)
	{
		det_value = a_matrix[0][0] * a_matrix[1][1] - a_matrix[0][1] * a_matrix[1][0];
		return det_value;
	}
	for (size_t p = 0; p < a_matrix[0].size(); p++)
	{
		det_value = det_value + a_matrix[0][p] * pow(-1, p) * det(minor(a_matrix, p));
	}
	return det_value;
}

dmatrix replace(dmatrix replace_matrix, const int col, const dvector & b_vector) {
	for (size_t i = 0; i < replace_matrix.size(); i++)
	{
		replace_matrix[i].at(col) = b_vector[i];
	}
	return replace_matrix;
}

dmatrix minor(const dmatrix & a_matrix, const int col) {
	dmatrix temp_matrix;
	for (auto i = 1; i < a_matrix.size(); i++)
	{
		dvector temp_row;
		for (auto j = 0; j < a_matrix[i].size(); j++)
		{
			if (j != col)
			{
				temp_row.push_back(a_matrix[i][j]);
			}
		}
		if (!temp_row.empty())
			temp_matrix.push_back(temp_row);
	}
	return temp_matrix;
}