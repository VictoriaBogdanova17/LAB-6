#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

int main()
{
	setlocale(LC_ALL, "Rus");
	int  i, j, k, T, x;
	int** mt, n, m;
	printf("Задайте кол-во строк данного массива\n");
	scanf_s("%d", &n);
	printf("Задайте кол-во столбцов данного массива\n");
	scanf_s("%d", &m);
	mt = (int**)malloc(n * sizeof(int*));
	for (int i = 0; i < n; i++)
	{
		mt[i] = (int*)malloc(m * sizeof(int));
	}
	printf("Заполните массив\n");
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf_s("%d ", &mt[i][j]);
		}
	}
	for (i = 0; i < n; i++)
	{
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%d ", mt[i][j]);
	}

	for (k = 0; k < m; k++)
		for (i = 0; i < n - 1; i++)
			for (j = i + 1; j < n; j++) {
				if (mt[i][k] >= 0 || mt[j][k] >= 0)
					continue;
				if (mt[i][k] > mt[j][k]) // Сравниваем данные  элементы
				{
					T = mt[i][k];
					mt[i][k] = mt[j][k]; // Меняет значения этих элементов местами
					mt[j][k] = T;
				}
			}
	printf("\n");
	for (i = 0; i < n; i++) {
		printf("\n");
		for (j = 0; j < m; j++)
			printf("%d ", mt[i][j]);
	}
	for (int i = 0; i < n; i++)
	{
		free(mt[i]);
	}
	free(mt);
	return 0;
}