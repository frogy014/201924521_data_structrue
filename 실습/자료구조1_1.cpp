#include <stdio.h>


int get_data(int(*p)[ACOLS], int n) {
	for (int i = 0;i < n;i++)
		for (int j = 0;j < n;j++)
			p[i][j] = rand() % (N * M);
}