#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{
	//Metodos de Insertion Sort
	void insertionSort(float* A, int n) {
		for (int i = 1; i < n; i++){
			int k = A[i];
			int j = i -1;

			while (k < A[j] && j >= 0) {
				A[j+1] = A[j];
				--j;
			}
			A[j + 1] = k;
		}
	}
	//Metodos de Selection Sort
	void selectionSort(float* A, int n){
		int smallest = 0;
		int i = 0;
		int j = 0;
		for (i = 0; i < n - 1; i++){
			smallest = i;
			for (j = i + 1; j < n; j++){
				if (A[j] < A[smallest]){
					smallest = j;
				}
			}
			swap(A,i,smallest);
		}
	}

	//Metodos de QuickSort
	int split_qs(float* A, int i, int j){
		/***
		 * split for quicksort
		 * i,j are the endpoints
		 */
		int p = getRandomInt(i, j);

		while (i  < j) {

			while ( i < p && A[i] <= A[p]){
				i = i + 1;
			}

			while ( j > p && A[j] >= A[p]){
				j = j - 1;
			}

			swap(A, i, j);

			if (i == p){
				p = j;
			}
			else if (j == p){
				p = i;
			}
		}
		return p;
	}

	void quickSort(float* A, int i, int j){
		if (i < j){
			int k = split_qs(A, i, j);
			quickSort(A, i, k-1);
			quickSort(A, k + 1, j);
		}
	}

	void quickSort(float* A, int n){
		quickSort(A, 0, n - 1);
	}

	//Metodos de MergeSort
	void merge(float* A, int i, int m, int f){

		int i1 = i;
		int i2 = m + 1;
		int f1 = m;
		int f2 = f;
		int j = 0;

		float prueba[i, f];

		while((i1 <= f1) && (i2 <= f2)){
			if (A[i1] < A[i2]){
				prueba[j] = A[i1];
				i1 = i1 + 1;
				j++;
			}
			else{
				prueba[j] = A[i2];
				i2 = i2 + 1;
				j++;
			}

		}

		while (i1 <= f1){
			prueba[j] = A[i1];
			i1 = i1 +1;
			j++;
		}
		
		while(i2 <= f2){
			prueba[j] = A[i2];
			i2 = i2 + 1;
			j++;
		}

		int k;
		j = 0;
		for (k = i; k <= f; ++k) {
			A[k] = prueba[j++];
		}

	}
	
	void mergeSort(float* A, int i, int f){ //Arreglar el mergeSort para que ordene los datos , ya que ahora no los ordena corectamente
		int medio;
		if(i < f){
			medio = (i + f) / 2;
			mergeSort(A, i, medio);
			mergeSort(A, medio + 1, f);
			merge(A, i, medio, f);
		}
	}
	

	//Crear el metodo de RadixSort
	void bucketSort(float* A, int n, int h){ // https://www.geeksforgeeks.org/radix-sort/ (es el primer codigo de Radixsort)

		float * A_aux= createArray(n);
		setAll(A_aux,n,0);
		int i, count[10] = { 0 };
	
		// Store count of occurrences in count[]
		for (i = 0; i < n; i++)
			count[(((int)A[i]) / h) % 10]++;
	
		// Change count[i] so that count[i] now contains actual position of this digit in output[]
		for (i = 1; i < 10; i++)
			count[i] += count[i - 1];
	
		// Build the A_aux array
		for (i = n - 1; i >= 0; i--) {
			A_aux[count[(((int)A[i]) / h) % 10] - 1] = A[i];
			count[(((int)A[i]) / h) % 10]--;
		}
		// Copy the A_aux array to A, so that A now contains sorted numbers according to current digit
		for (i = 0; i < n; i++)
			A[i] = A_aux[i];

		deleteArray(A_aux);
	}

	void radixSort(float* A, int n){  // https://www.geeksforgeeks.org/radix-sort/ (es el primer codigo de Radixsort)
		int M = getMax(A,n);
		for (int h=1; M/h >0;h*=10){
			bucketSort(A,n,h);
		}
	}

}



