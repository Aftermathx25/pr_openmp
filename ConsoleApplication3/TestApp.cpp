#include <omp.h>
#include <iostream>
#include <Windows.h>

using namespace std;

#include <stdio.h>
#include <time.h>

long long num_steps = 100000000;
double step;

void function()
{
	omp_set_num_threads(4);
	clock_t start, stop;
	double x, pi, sum = 0.0;
	int i;
	step = 1. / (double)num_steps;
	start = clock();
	double suma1 = 0.0;
	double* tablica = (double*) malloc(4*sizeof(double));
#pragma omp parallel  
	{
		suma1 = 0.0;
#pragma omp for reduction (+: sum) private (suma1, x)
		for (i = 0; i < num_steps; i++)
		{
			x = (i + .5)*step;
			suma1 += 4.0 / (1. + x*x);
#pragma omp critical
			tablica[omp_get_thread_num()] += 4.0 / (1. + x*x);
		}
		//#pragma omp atomic
		printf("%d, Suma1:%f\n", omp_get_thread_num(), suma1*step);
		printf("%d, tablica[%d]:%f\n", omp_get_thread_num(), omp_get_thread_num(), tablica[omp_get_thread_num()] * step);
		//sum += suma1;

	}

	for (int i = 0; i < 4; i++){
		sum += tablica[i];
	}

	pi = sum*step;
	stop = clock();
	free(tablica);
	FILE* plik;
	fopen_s(&plik, "wyniki5.csv", "a");
	if (plik == NULL) printf("Coœ posz³o nie tak.\n");
	else
	{
		fprintf(plik, "%f;%d\n", ((double)(stop - start) / 1000.0), num_steps);
	}

	printf("Wartosc liczby PI wynosi %15.12f\n\n", pi);


	fclose(plik);
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < 5; i++) function();
	return 0;
}