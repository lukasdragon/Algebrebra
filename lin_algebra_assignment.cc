// Mr. Arkiletian ICTP 12
// Simultaneous linear equation assignment (2 team members)
// Solved using the STL generic vector container class 

#define _CRT_SECURE_NO_DEPRECATE
#include <iostream>
#include <vector>
#include <cmath> // for pow function

using namespace std;

typedef vector <double> Dvector;
typedef vector <Dvector> Dmatrix;

// Prototypes (variable names included, but not needed)
// DO NOT change any prototypes!! NO other functions allowed.

Dmatrix GetA();
// gets the matrix A from the user and returns it

Dvector Getb(const int &siz);
// gets the vector b from the user and returns it

void Display(const Dvector &xvect);
// displays the contents of vector xvect

void Display(const Dmatrix &Amat);
// displays the contents of matrix Amat (Note: Display function is overloaded)

Dvector Solvex(const Dmatrix &Amat, const Dvector &bvect);
// Solves for systems of linear equations in the form Ax=b using cramer's rule 

double Det(const Dmatrix &Amat);
// returns the Determinant of matrix Amat using a recursive algorithm
// base case is 2x2 matrix 

Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector &bvect);
// Replaces the column 'col' in Rmat with bvect and returns Rmat

Dmatrix Minor(const Dmatrix &Amat, const int col);
// Gets the Minor matrix of Amat by crossing out the first row and 
// column 'col' then returns that smaller matrix


//-------------------------------------------
int main() {

	Dmatrix A;
	Dvector b, x;

	A = GetA();
	Display(A);
	b = Getb(A.size());
	x = Solvex(A, b);
	Display(x);

	system("PAUSE");

	return(0);
}
//-------------------------------------------

Dmatrix GetA() {
	cout << "Please input Columns A. Format: <Matrix Size> <A11> <A12> <A13> etc." << endl;
	int index;
	scanf("%d", &index);
	Dmatrix matrix = Dmatrix();
	matrix.reserve(index);

	for (int i = 0; i < index; i++)
	{
		Dvector row = Dvector();
		row.reserve(index);

		for (int i = 0; i < index; i++)
		{
			double elem = 0;
			scanf("%lf", &elem);
			row.push_back(elem);
		}
		matrix.push_back(row);
	}
	return matrix;
}

Dvector Getb(const int & siz) {
	cout << "Please input Column B. Format: <b1> <b2> <b3> etc." << endl;
	Dvector vec = Dvector();
	for (int i = 0; i < siz; i++)
	{
		double elem = 0;
		scanf("%lf", &elem);
		vec.push_back(elem);
	}
	return vec;
}

void Display(const Dvector & xvect) {
	cout << endl;
	for (size_t i = 0; i < xvect.size(); i++)
	{
		cout << xvect[i] << " ";
		cout << endl;
	}
}

void Display(const Dmatrix & Amat) {
	cout << endl;
	for (size_t i = 0; i < Amat.size(); i++)
	{
		for (size_t j = 0; j < Amat[i].size(); j++)
			cout << Amat[i][j] << " ";
		cout << endl;
	}
}

Dvector Solvex(const Dmatrix & Amat, const Dvector & bvect) {
	return Dvector();
}

double Det(const Dmatrix & Amat) {
	return 0.0;
}

// Replaces the column 'col' in Rmat with bvect and returns Rmat
Dmatrix Replace(Dmatrix Rmat, const int col, const Dvector & bvect) {

	for (size_t i = 0; i < Rmat.size(); i++)
	{
		Rmat[i].at(col) = bvect[i];
	}
	return Rmat;
}

Dmatrix Minor(const Dmatrix & Amat, const int col)
{
	return Dmatrix();
}
