#include <iostream>
#include "sort/sort.hpp"
#include "sort/utils.hpp"

namespace sort{
	//Crear el metodo de Insercion Sort
	void insertionSort(int arr[], int n) {
		for (int i = 1; i < n; i++){
			int k = arr[i];
			int j = i -1;

			while (k < arr[j] && j >= 0) {
				arr[j+1] = arr[j];
				--j;
			}
			arr[j + 1] = k;
		}
	}

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

	//Crear el metodo de MergeSort
	void merge(int arr[], int p, int q, int r){
		int a1 = q - p +1;
		int a2 = r - q;

		
		int l[a1], m[a2];

		for (int i = 0; i < a1; i++){
			l[i] = arr[p + i];
		}
			
		for (int j = 0; j < a2; j++){
			m[j] = arr[q + 1 + j];
		}
	
		int x = 0;
		int y = 0;
		int z = p;

		while (x < a1 && y < a2) {
			if (l[x] <= m[y]) {
				arr[z] = l[x];
				x++;
			}
			else {
				arr[z] = m[y];
				y++;
			}
			z++;
		}

		while(x < a1) {
			arr[z] = l[x];
			x++;
			z++;
		}

		while(y < a2) {
			arr[z] = m[y];
			y++;
			z++;
		}

	}
	
	void mergeSort(int arr[], int l, int r){
		if (l < r) {
			int f = l + (r-1) / 2;

			mergeSort(arr, l, f);
			mergeSort(arr, f + 1, r);
			merge(arr, l, f, r);
		}
	}
	

	//Crear el metodo de RadixSort
	

}



