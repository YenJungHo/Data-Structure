// Sort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <assert.h>

using namespace std;

void swap(int *a, int * b) {
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void exch(int *array, int i, int j) {
	int temp;
	temp = array[i];
	array[i] = array[j];
	array[j] = temp;
}

bool isSorted(int *array, int lo, int hi) {
	for (int i = lo; i < hi; i++)
		if (array[i] > array[i + 1])
			return false;
	return true;
}

void printArray(int *arr, int lo, int hi) {
	int i;
	cout << "lo = " << lo << ", hi = " << hi << ", ";
	for (i = lo; i <= hi; i++)
		cout << arr[i] << " ";
	cout << endl;
}

void printArray(int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
		cout << arr[i] << " ";
	cout << endl;
}

class CBubbleSort {
public:
	static void sort(int* array, int size) {
		bool bSwap;
		for (int i = size - 1; i > 0; i--) {
			bSwap = false;
			for (int j = 0; j < i; j++) {
				printArray(array, size);
				if (array[j] > array[j + 1]) {
					swap(&array[j], &array[j + 1]);
					bSwap = true;
				}
				printArray(array, size);
				cout << endl;
			}
			if (bSwap == false) {
				break;
			}
		}
	}
};

class CSelectSort {
public:
	static void sort(int* array, int size) {
		int min = 0;
		for (int i = 0; i < size; i++) {
			min = i;
			for (int j = i; j < size; j++) {
				if (array[j] < array[min]) {
					min = j;
				}
			}
			printArray(array, size);
			swap(&array[i], &array[min]);
			printArray(array, size);
			cout << endl;
		}
	}
};

class CInsertSort {
public:
	static void sort(int* array, int size) {
		for (int i = 0; i < size; i++) {
			for (int j = i; j > 0; j--) {
				if (array[j] < array[j - 1]) {
					swap(&array[j], &array[j - 1]);
					printArray(array, size);
				}
				else {
					printArray(array, size);
					cout << endl;
					break;
				}
			}
		}
	}
};

class CMergeSort {
public:
	static void sort(int *array, int size) {
		int *pAux = new int[size];
		sort(array, pAux, 0, size - 1);
		delete pAux;
	}

private:
	static void merge(int *array, int *aux, int lo, int mid, int hi) {
		assert(isSorted(array, lo, mid));
		assert(isSorted(array, mid + 1, hi));

		// copy
		for (int k = lo; k <= hi; k++) {
			aux[k] = array[k];
		}
		printArray(array, lo, mid);
		printArray(array, mid + 1, hi);

		// merge
		int i = lo, j = mid + 1;
		for (int k = lo; k <= hi; k++) {
			if (i > mid) {
				array[k] = aux[j++];
			}
			else if (j > hi) {
				array[k] = aux[i++];
			}
			else if (aux[j] < aux[i]) {
				array[k] = aux[j++];
			}
			else {
				array[k] = aux[i++];
			}
		}

		printArray(array, lo, hi);
		cout << endl;

		assert(isSorted(array, lo, hi));
	}

	static void sort(int *array, int *aux, int lo, int hi) {
		if (hi <= lo) {
			return;
		}

		int mid = lo + (hi - lo) / 2;
		sort(array, aux, lo, mid);
		sort(array, aux, mid + 1, hi);
		merge(array, aux, lo, mid, hi);
	}
};

class CQuickSort {
public:
	static void sort(int *array, int size) {
		sort(array, 0, size - 1);
	}

private:
	static int partition( int *array, int lo, int hi ) {
		// choose first item as pivot
		int i = lo, j = hi + 1;

		while (true) {
			// find the item on left to swap
			while (array[++i] < array[lo] && i < hi);

			// find the item on right to swap
			while (array[--j] > array[lo] && j > lo);

			// check if pointer cross
			if (i >= j) break;

			// exchange
			exch(array, i, j);
		}
		// change pivot
		exch(array, lo, j);

		return j;
	}

	static void sort(int *array, int lo, int hi) {
		if (lo >= hi) {
			return;
		}

		printArray(array, lo, hi);
		int j = partition(array, lo, hi);

		printArray(array, lo, hi);
		cout << endl;

		sort(array, lo, j - 1);
		sort(array, j + 1, hi);
	}
};

int main()
{
	int arr[] = { 64, 34, 25, 12, 22, 11, 90, 80 };
	int n = sizeof(arr) / sizeof(arr[0]);

	//CBubbleSort::sort(arr, n);
	//CSelectSort::sort(arr, n);
	//CInsertSort::sort(arr, n);
	//CMergeSort::sort(arr, n);
	CQuickSort::sort(arr, n);

	cout << "Sorted array: \n";
	printArray(arr, n);

	system("pause");
    return 0;
}

