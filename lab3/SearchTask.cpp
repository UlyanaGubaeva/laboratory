#include "pch.h"
#include <iostream>
#include <ctime>
#include <time.h>

using namespace std;

void Search(int *arr, int arrLength, int element)
{
	bool beFound = false;
	for (int i = 0; i < arrLength; i++) 
		if (arr[i] == element) 
		{
		cout << arr[i] << endl;
		beFound = true;
		break;
		}
	
	if (!beFound) cout << "Значение " << element <<" не найдено.\n" << endl;
}

void QuickSort(int *arr, int first, int last, bool recursion)
{
	if (recursion) {
		int mid, count;
		int f = first, l = last;
		mid = arr[(f + l) / 2];
		do
		{
			while (arr[f] < mid) f++;
			while (arr[l] > mid) l--;
			if (f <= l)
			{
				count = arr[f];
				arr[f] = arr[l];
				arr[l] = count;
				f++;
				l--;
			}
		} while (f < l);
		if (first < l) QuickSort(arr, first, l, recursion);
		if (f < last) QuickSort(arr, f, last, recursion);
	}
	else {
		int i, j, s, w, ist = 1, stL[100], stR[100];
		while (ist > 0) {
			i = first; j = last; s = arr[(first + last) / 2];
			while (i <= j)
			{
				while (s > arr[i]) i++; 
				while (arr[j] > s) j--; 
				if (i <= j) { w = arr[i]; arr[i] = arr[j]; arr[j] = w; i++; j--; }
			}
			if (j - first > last - i) 
			{
				stL[++ist] = first; stR[ist] = j; 
				if (i < last) first = i; 
				else { first = stL[ist]; last = stR[ist--]; }
			}
			else
			{
				if (i < last) { stL[++ist] = i; stR[ist] = last; } 
				if (first < j) last = j; 
				else { first = stL[ist]; last = stR[ist--]; } 
			}
		} 
	}
}

int BSearch(int* arr, int targetValue, int left, int right, bool recursion)
{
	int middle = 0;
	if (recursion)
	{
		middle = (left + right) / 2;
		if (*(arr + middle) == targetValue)
			return middle;
		if (middle == left || middle == right)
			return -1;
		if (*(arr + middle) < targetValue)
			BSearch(arr, targetValue, middle, right, recursion);
		else BSearch(arr, targetValue, middle, left, recursion);
	}
	else while (true)
	{
		middle = (left + right) / 2;
		if (targetValue < arr[middle])
			right = middle - 1;
		else if (targetValue > arr[middle])
			left = middle + 1;
		else return middle;
		if (left > right)
			return -1;
	}
}

int main()
{
	setlocale(LC_ALL, "Russian");
	clock_t start1, stop1, start2, stop2;
	//Task 1
	const int n1 = 10000, max1 = 1000, min1 = -1000;
	int arr1[n1];
	srand(time(NULL));
	for (int i = 0; i < n1; i++)
		arr1[i] = rand() % (max1 - min1 + 1) + min1;
	cout << "Задание 1. Search \n";
	start1 = clock();
	Search(arr1, n1, 10);
	stop1 = clock();
	Search(arr1, n1, 100001);

	//Task 2
	const int n2 = 100, max2 = 10, min2 = -10;
	int arr2[n2];
	srand(time(NULL));
	for (int i = 0; i < n2; i++)
		arr2[i] = rand() % (max2 - min2 + 1) + min2;

	cout << "Задание 2. QuickSort \nИсходный массив (первые 50 значений): \n";
	for (int i = 0; i < 50; i++)
		cout << arr2[i] << ", ";
	QuickSort(arr2, 0, n2-1, !true);
	cout << "\nОтсортированный массив (первые 50 значений): \n";
	for (int i = 0; i < 50; i++)
		cout << arr2[i] << ", ";

	//Task 3
	start2 = clock();
	int ind = BSearch(arr2, -7, 0, n2 - 1, false); 
	stop2 = clock();
	cout << "\n\nЗадание 3. BSearch \n";
	if (ind != -1)
		cout << "Найденное значение: " << arr2[ind] << endl;
	else cout << "Значение не найдено.\n";

	//Task 4
	cout << "\nЗадание 4. \n";
	clock_t unsorted = stop1-start1, sorted = stop2 - start2;
	if (unsorted > sorted) cout << "Поиск элемента в отсортирвоанном массиве быстрее.\n";
	else cout << "Поиск элемента в неотсортирвоанном массиве быстрее.\n";
}

