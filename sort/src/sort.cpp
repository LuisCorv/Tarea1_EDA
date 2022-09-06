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
	void merge(float* A, int p, int q, int r){
		int a1 = q - p +1;
		int a2 = r - q;

		
		int l[a1], m[a2];

		for (int i = 0; i < a1; i++){
			l[i] = A[p + i];
		}
			
		for (int j = 0; j < a2; j++){
			m[j] = A[q + 1 + j];
		}
	
		int x = 0;
		int y = 0;
		int z = p;

		while (x < a1 && y < a2) {
			if (l[x] <= m[y]) {
				A[z] = l[x];
				x++;
			}
			else {
				A[z] = m[y];
				y++;
			}
			z++;
		}

		while(x < a1) {
			A[z] = l[x];
			x++;
			z++;
		}

		while(y < a2) {
			A[z] = m[y];
			y++;
			z++;
		}

	}
	
	void mergeSort(float* A, int l, int r){ //revisar para ver como hacer funcionar con solo A y n como datos de ingreso
		if (l < r) {
			int f = l + (r-1) / 2;

			mergeSort(A, l, f);
			mergeSort(A, f + 1, r);
			merge(A, l, f, r);
		}
	}
	

	//Crear el metodo de RadixSort
	

}



