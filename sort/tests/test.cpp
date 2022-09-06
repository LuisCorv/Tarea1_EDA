#include "sort/sort.hpp"
#include "sort/utils.hpp"
#include <chrono>
#include <iostream>
#include <ctime>

long getElapsedTime(std::chrono::time_point<std::chrono::high_resolution_clock> t1,
		std::chrono::time_point<std::chrono::high_resolution_clock> t2){
	auto int_ms = std::chrono::duration_cast<std::chrono::milliseconds>(t2 - t1);
	return static_cast<long>(int_ms.count());
}

void testSort(int max_size, int n_sizes){
	int* sizes = sort::linspace(max_size, n_sizes);
	float* A = nullptr;
	int n = 0;
	for (int i = 0; i < n_sizes; i++){
		n = sizes[i];
		A = sort::createRandomArray(n);		//Para la parte de los alg. generales, se usa createRandomArray
		//A = sort::createRandomIntArray(n, 0, 100);		//Para la parte de los alg. especificos se ocupa el createRandomIntArray

		auto start = std::chrono::high_resolution_clock::now(); 

		//change the sort method here
		sort::insertionSort(A, n);		//Este metodo es el que se cambia para poder obtener los datos de cada alg. de ordenacion

		auto end = std::chrono::high_resolution_clock::now();
		long elapsed =  getElapsedTime(start, end);
		sort::deleteArray(A);
		std::cout << " [" << n << "," << elapsed << "]" << std::endl;
	}
	delete[] sizes;
}


int main(int nargs, char** nvargs){
	int n_sizes = 10;
	int max_size = 100000;		//Este max_size se cambia, es 100000 para tamaños pequeños y es 1000000 para tamaños grandes
	testSort(max_size, n_sizes);
	return 0;
}

/*
int main(int nargs, char** args){

	std::srand(std::time(nullptr));
	int n = 10;
	float* A = sort::createRandomIntArray(n, 0, 100);
	sort::printArray(A, n);
	std::cout << sort:: insertionSort( A, n );
	auto start = std::chrono::high_resolution_clock::now();
	sort::insertionSort(A, n);
	sort::printArray(A, n);
	sort::deleteArray(A);
	auto end = std::chrono::high_resolution_clock::now();
	std::cout<<" Elapsed : " << getElapsedTime(start, end) << std::endl;
	return 0;
}
*/