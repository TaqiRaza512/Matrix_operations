#include "MatrixOuterLayer.h"
#include<iostream>
#include<fstream>
#include<iomanip>
using namespace std;
void RowsValues(int*&Matrix,int dimension,int&col,ifstream &Rdr)
{
	if (col < dimension)
	{
		Rdr >> Matrix[col];
		col++;
		RowsValues(Matrix, dimension, col, Rdr);
	}
	return;
}
void LoadMatrix(int**& Matrix,int dimension,int &row,ifstream&Rdr)
{
	if (row<dimension)
	{
		Matrix[row] = new int[dimension];
		int col = 0;
		RowsValues(Matrix[row], dimension, col, Rdr);
		row++;
		LoadMatrix(Matrix, dimension, row, Rdr);
	}
	return;
}
MatrixOuterLayer::MatrixOuterLayer()
{
	ifstream Rdr("Matrix.txt");
	int row=0;
	Rdr >> dimension;
	Matrix = new int*[dimension];
	LoadMatrix(Matrix, dimension,row,Rdr);
}
void PrintCols(int dimension, int** Matrix, int& cols,int rows)
{
	if (cols<dimension)
	{
		cout <<setw(4)<<left<< *(*(Matrix + rows) + cols);
		cols++;
		PrintCols(dimension, Matrix, cols, rows);
	}
	return;
}
void PrintRows(int dimension,int**Matrix,int& rows)
{
	if (rows<dimension)
	{
		int cols = 0;
		PrintCols(dimension, Matrix, cols, rows);
		rows++;
		cout << endl;
		PrintRows(dimension, Matrix, rows);
	}
	return;
}
void MatrixOuterLayer::PrintMatrix()
{
	int rows = 0;
	PrintRows(dimension,Matrix,rows);
}

void MatrixOuterLayer::RoatateOuterLayerBy1()
{
	int temp = Matrix[0][0];
	//upper row

	for (int ri=1;ri<dimension;ri++)
	{
		Matrix[0][ri-1] = Matrix[0][ri];
	}

	//Right Col

	for(int ci=0;ci+1<dimension;ci++)
	{
		Matrix[ci][dimension - 1] = Matrix[ci+1][dimension-1];
	}
	//Lower Row
	for (int ri=dimension-1;ri-1>=0;ri--)
	{
		Matrix[dimension-1][ri] = Matrix[dimension-1][ri-1];
	}
	//Left Col
	for (int ci=dimension-1;ci-1>=0;ci--)
	{
		Matrix[ci][0] = Matrix[ci-1][0];
	}
	Matrix[1][0] = temp;

}

