#include <stdio.h>
#include <stdlib.h>
#include "time.h"
#define AROWS 3
#define ACOLS 4
#define BROWS 4
#define BCOLS 5
#define CROWS 3
#define CCOLS 5
/*
행렬이 여러개일떄 하나의 function으로 처리하는 방법을 고안
*/

int get_data(int(*p)[ACOLS], int n) {
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			p[i][j] = rand() % (n * n);
	return 1;
}

int show_data(int(*p)[ACOLS], int n) {
	for (int i = 0;i < n;i++)
	{
		for (int j = 0;j < n;j++)
			printf("%d", p[i][j]);
		printf("\n");
	}
}

void multiply(int martixA[][ACOLS], int ar, int matrixB[][BCOLS], int br, int matrixC[][CCOLS], int cr) {

}

int main() {
	int matrixA[AROWS][ACOLS];
	int matrixB[BROWS][BCOLS];
	int matrixC[CROWS][CCOLS];

	srand(time(NULL));
	get_data(matrixA, AROWS);
	show_data(matrixA, AROWS);
	get_data(matrixB, BROWS);
	show_data(matrixB, BROWS);

	multiply(matrixA, AROWS, matrixB, BROWS, matrixC, CROWS);
	show_data(matrixC, AROWS);
	system("pause");

	return 0;



}