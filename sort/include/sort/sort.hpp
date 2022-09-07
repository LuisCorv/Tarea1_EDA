#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	//♦♦♦♦♦Algoritmos de Ordenacion Genericos♦♦♦♦♦♦

	
	void insertionSort(float* A, int n);		// Insertion Sort
	void selectionSort(float* A, int n);		//Selection Sort

	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);		//QuickSort
	void quickSort(float* A, int n); 

	void merge(float* A, int p, int q, int r);
	void mergeSort(float* A, int l, int r);	// MergeSort
	void mergeSort(float* A, int n);

	
	//♦♦♦♦♦Algoritmos de Ordenacion especifica♦♦♦♦♦
	//Crear RadixSort

	void radixSort(float* A, int n);
}

#endif
