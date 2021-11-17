// lab7.2_iter.cpp
// <Сташкевич Владислав>
// Лабораторна робота № 7.2
// Опрацювання багатовимірних масивів ітераційними та рекурсивними способами
// Варіант 19

#include <iostream>
#include <iomanip>

using namespace std;

int** ArrayBuilder(const int size, const int Low, const int High);
int** DiagChanger(int** arr, const int size);
void PrintArray(int** arr, const int size);
int IndexMax(int* arr, const int size);

int main() {
	srand((unsigned)time(NULL));
	int n	 = 5,
		Low  = 0,
		High = 99;


	cout << " Matrix:\n\n";
	int** arr = ArrayBuilder(n, Low, High);
	PrintArray(arr, n);


	cout << "\n\n New matrix: \n\n";
	arr = DiagChanger(arr, n);
	PrintArray(arr, n);

	return 0;
}

int **ArrayBuilder(const int size, const int Low, const int High) {
	int** arr = new int*[size];
	for (int i = 0; i < size; i++)
		arr[i] = new int[size];

	for (int i = 0; i < size; i++) 
		for (int j = 0; j < size; j++) 
			arr[i][j] = Low + rand() % (High - Low + 1);
		
	return arr;
}

void PrintArray(int** arr, const int size) {
	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			cout << setw(3) << arr[i][j];
		cout << endl;
	}
}

int IndexMax(int* arr, const int size) {
	int max = arr[0],
		index = 0;

	for (int i = 0; i < size; i++)
		if (arr[i] > max) {
			index = i;
			max = arr[i];
		}

	return index;
}

int** DiagChanger(int** arr, const int size) {
	int temp, 
		index;

	for (int i = 0; i < size; i++) {
		index = IndexMax(arr[i], size);
		temp = arr[i][index];
		arr[i][index] = arr[i][i];
		arr[i][i] = temp;
	}

	return arr;
}