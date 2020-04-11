#include "pch.h"
#include <iostream>
#include <ctime>
#include <stdlib.h>
#include <time.h>
using namespace std;

//	Gubaeva U.M.

class Matrix3x3
{
private:
	int arr[3][3]{ 0, 0, 0, 0, 0, 0, 0, 0, 0 };
public:
	int element(const int i, const int j) const 
	{
		return arr[i][j];
	} 
	void setElement(const int i, const int j, const int value) 
	{
		arr[i][j] = value;
	}	
	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 3; j++)
			{
				arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
	}
	int sumPrincipalDiag() const  
	{
		return arr[0][0] + arr[1][1] + arr[2][2];
	}
	int sumSecondaryDiag() const 
	{
		return arr[0][2] + arr[1][1] + arr[2][0];
	}
	int productPrincipalDiag() const 
	{
		return arr[0][0] * arr[1][1] * arr[2][2];
	}
	int productSecondaryDiag() const 
	{
		return arr[0][2] * arr[1][1] * arr[2][0];
	}
	int sumRow(const int iRow) const 
	{
		return arr[iRow][0] + arr[iRow][1] + arr[iRow][2];
	}
	int minColumn(const int iCol) const 
	{
		int min = arr[0][iCol];
		for (int i = 0; i < 3; i++)
			if (arr[i][iCol] < min)
				min = arr[i][iCol];
		return min;
	}
	int maxColumn(const int iCol) const 
	{
		int max = arr[0][iCol];
		for (int i = 0; i < 3; i++)
			if (arr[i][iCol] > max)
				max = arr[i][iCol];
		return max;
	}
};

class MatrixXnX 
{
private:
	int size;
	int **arr;

public:
	MatrixXnX(const int iDim) {
		size = iDim;
		arr = new int*[size];
		for (int i = 0; i < iDim; i++)
			arr[i] = new int[iDim];
		for (int i = 0; i < iDim; i++)
			for (int j = 0; j < iDim; j++)
				arr[i][j] = 0;
	}
	void delMatrixXnX() 
	{
		delete[] arr;
		arr = nullptr;
	}
	int element(const int i, const int j) const 
	{
		return arr[i][j];
	}
	void setElement(const int i, const int j, const int value) 
	{
		arr[i][j] = value;
	}
	void fillRandomElements(const int minVal, const int maxVal)
	{
		srand(time(NULL));
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				arr[i][j] = rand() % (maxVal - minVal + 1) + minVal;
			}
	}
	int sumPrincipalDiag() const  
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i == j)
					sum += arr[i][j];
			}
		return sum;
	}
	int sumSecondaryDiag() const 
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i + j == size-1)
					sum += arr[i][j];
			}
		return sum;
	}
	int productPrincipalDiag() const 
	{
		int pri = 1;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i == j)
					pri *= arr[i][j];
			}
		return pri;
	}
	int productSecondaryDiag() const 
	{
		int pri = 1;
		for (int i = 0; i < size; i++)
			for (int j = 0; j < size; j++)
			{
				if (i + j == size - 1)
					pri *= arr[i][j];
			}
		return pri;
	}
	int sumRow(const int iRow) const 
	{
		int sum = 0;
		for (int i = 0; i < size; i++)
			sum += arr[iRow][i];
		return sum;
	}
	int minColumn(const int iCol) const 
	{
		int min = arr[0][iCol];
		for (int i = 0; i < size; i++)
			if (arr[i][iCol] < min)
				min = arr[i][iCol];
		return min;
	}
	int maxColumn(const int iCol) const 
	{
		int max = arr[0][iCol];
		for (int i = 0; i < size; i++)
			if (arr[i][iCol] > max)
				max = arr[i][iCol];
		return max;
	}
	
};

int main()
{
	//Task 1.1
	cout << "Task 1.1 \n";
	Matrix3x3 m;
	m.fillRandomElements(-10, 10);
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
			cout << m.element(i, j) << "\t";
		cout << endl;
	}
	cout << "Minimum column elements:  \t" << m.minColumn(0) << "\t" << m.minColumn(1) << "\t" << m.minColumn(2)  << endl;
	cout << "Maximum column elements:  \t" << m.maxColumn(0) << "\t" << m.maxColumn(1) << "\t" << m.maxColumn(2) << endl;
	cout << "Principal Diagonal:  " << "\nSum = " << m.sumPrincipalDiag() << ";  Product = " << m.productPrincipalDiag() << endl;
	cout << "Secondary Diagonal:  " << "\nSum = " << m.sumSecondaryDiag() << ";  Product = " << m.productSecondaryDiag() << endl;
	
	//Task 1.2
	cout << "\nTask 1.2 \n";
	int size = 5;
	MatrixXnX mXnX(size); 
	mXnX.fillRandomElements(-10, 10);
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << mXnX.element(i, j) << "\t";
		cout << endl;
	}
	cout << "Minimum column elements:  ";
	for (int i = 0; i < size; i++)
		cout << mXnX.minColumn(i) << "\t";
	cout << "\nMaximum column elements:  ";
	for (int i = 0; i < size; i++)
		cout << mXnX.maxColumn(i) << "\t";
	cout << "\nPrincipal Diagonal:  " << "\nSum = " << mXnX.sumPrincipalDiag() << ";  Product = " << mXnX.productPrincipalDiag() << endl;
	cout << "Secondary Diagonal:  " << "\nSum = " << mXnX.sumSecondaryDiag() << ";  Product = " << mXnX.productSecondaryDiag() << endl;

	mXnX.delMatrixXnX();
}