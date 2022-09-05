#ifndef SORT_SORT_HPP
#define SORT_SORT_HPP

namespace sort {
	//♦♦♦♦♦Algoritmos de Ordenacion Genericos♦♦♦♦♦♦

	//Crear Insercion Sort
	void selectionSort(float* A, int n);
	int split_qs(float* A, int i, int j);
	void quickSort(float* A, int i, int j);
	void quickSort(float* A, int n);
	void merge(int arr[], int p, int q, int r);
	void mergeSort(int arr[], int l, int r);
	//Crear bucketsort
	
	//♦♦♦♦♦Algoritmos de Ordenacion especifica♦♦♦♦♦
	//Crear RadixSort

}

#endif
