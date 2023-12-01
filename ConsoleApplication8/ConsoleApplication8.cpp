#include<iostream>
#include "MatrixOuterLayer.h"

using namespace std;
int main()
{
	MatrixOuterLayer B;
	B.PrintMatrix();
	B.RoatateOuterLayerBy1();
	cout << endl << endl;
	B.PrintMatrix();



}