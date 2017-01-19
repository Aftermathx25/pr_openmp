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
	omp_set_num_threads(32);
	clock_t start, stop;
	double x, pi, sum = 0.0;
	int i;
	step = 1. / (double)num_steps;
	start = clock();
	double suma1 = 0.0;
#pragma omp parallel  reduction (+: sum) private (suma1, x)
	{
		suma1 = 0.0;
#pragma omp for 
		for (i = 0; i < num_steps; i++)
		{
			x = (i + .5)*step;
			suma1 += 4.0 / (1. + x*x);

		}
		//#pragma omp atomic
		sum += suma1;
	}
	pi = sum*step;
	stop = clock();

	FILE* plik;
	fopen_s(&plik, "wyniki5.csv", "a");
	if (plik == NULL) printf("Co� posz�o nie tak.\n");
	else
	{
		fprintf(plik, "%f;%d\n", ((double)(stop - start) / 1000.0), num_steps);
	}

	printf("Wartosc liczby PI wynosi %15.12f\n", pi);


	fclose(plik);
}

int main(int argc, char* argv[])
{
	for (int i = 0; i < 50; i++) function();
	return 0;
}