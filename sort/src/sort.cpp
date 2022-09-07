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
	void merge(float* A, int i, int k, int j){
		int a1 = j - i +1;
		
		float * A_aux= createArray(a1);
		setAll(A_aux,a1,0);
		
		int q=0;
		int p1=i;
		int p2=k+1 ;
		
		while (p1 <= k && p2 <= j) {
			if (A[p1] <= A[p2]) {
				A_aux[q] = A[p1];
				p1++;
				
			}
			else if (A[p1]==A[p2]){
				A_aux[q] = A[p1];
				p1++;
				q++;
				A_aux[q] = A[p2];
				p2++;
			}
			else {
				A_aux[q] = A[p2];
				p2++;
			}
			q++;
		}

		while(p1 <= k) {
			A_aux[q] = A[p1];
			p1++;
			q++;
		}

		while(p2 <= j) {
			A_aux[q] = A[p2];
			p2++;
			q++;
		}
		
		for (int l = 0; l < a1-1; l++){
			A[i+l] = A_aux[l];
		}
		
		deleteArray(A_aux);
		printArray(A,j);
		
	}
	
	void mergeSort(float* A, int i, int j){ //Arreglar el mergeSort para que ordene los datos , ya que ahora no los ordena corectamente
		int k = (i + j) / 2;
		if (i < j) {
			mergeSort(A, i, k);
			mergeSort(A, k+ 1, j);
			merge(A, i, k , j);
		}
	}
	
	void mergeSort(float* A, int n){
		mergeSort(A, 0, n);
	}

	//Crear el metodo de RadixSort
	void bucketSort(float* A, int M, int h, int n){
		//se crean B con  M buckets
		//for n° perteneciente a A
			//
		int k=0;
		float * A_aux= createArray(n);
		setAll(A_aux,n,0);
		for (int i=0; i<M; i++){
			//if B[i] != vacio
				//for b perteneciente a B[i]
					//A_aux[k] = A[b];
					k++;

		}
		for (int l = 0; l < n; l++){
			A[l] = A_aux[l];
		}
	}

	void radixSort(float* A, int n){
		int M = 100;
		int h=n;
		while (h>-1){
			bucketSort(A,M,h,n);
			h--;
		}
	}

}



