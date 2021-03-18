#include<stdio.h>
#include<stdlib.h>
#include<vector>
int main()
{
	int n;
	scanf("%d", &n);
	int i, leap = 1, j;
	int i1 = 0, i2 = n - 1, i3 = n - 1, i4 = 0;
	int** a = (int**)malloc(sizeof(int*) * n);
	for (i = 0; i < n; i++)
	{
		a[i] = (int*)malloc(sizeof(int) * n);
		memset(a[i], 0, sizeof(int) * n);
	}
	for (i = 1; i <= n * n; leap++)
	{
		if (leap % 4 == 1)//从左往右
		{
			for (j = i4; j <= i2; j++, i++)
			{
				a[i1][j] = i;
			}
			i1++;
		}
		if (leap % 4 == 2)//从上到下
		{
			for (j = i1; j <= i3; j++, i++)
			{
				a[j][i2] = i;
			}
			i2--;
		}
		if (leap % 4 == 3)//从右往左
		{
			for (j = i2; j >= i4; j--, i++)
			{
				a[i3][j] = i;
			}
			i3--;
		}
		if (leap % 4 == 0)//从下到上
		{
			for (j = i3; j >= i1; j--, i++)
			{
				a[j][i4] = i;
			}
			i4++;
		}
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			printf("%d ", a[i][j]);
		}
		printf("\n");
	}
	return 0;
}
