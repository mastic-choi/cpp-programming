#include <cstdlib>
#include <cstdio>
#include <iostream>


int cmp_asc(const void* a, const void* b){
	double& l = *(double*) a;
	double& r = *(double*) b;
	return (l < r)? -1 : 1;
}

int cmp_desc(const void* a, const void* b){
	double& l = *(double*) a;
	double& r = *(double*) b;
	return (l < r)? 1 : -1;
}

int main(void){


	double arr[] = {2.0, 3.2, 4.4, 2.9, 3.4};
	qsort(arr, 5, sizeof(double), cmp_asc);
	std::cout << arr << std::endl;
	qsort(arr, 5, sizeof(double), cmp_desc);
	std::cout << arr << std::endl;


	return 0;
}//end of main
