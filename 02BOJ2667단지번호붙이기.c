#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void dfs(int* matrix, int N, int i, int j, int* dangi, int dangind) 
{	
	if ( *(matrix + N * i + j) == 0)
		return;
	
	*(dangi + dangind) += 1;
	*(matrix + i * N + j ) = 0;
	
	if (j < N-1)
		dfs(matrix, N, i, j+1, dangi, dangind);
	if (i < N-1)
		dfs(matrix, N, i+1, j, dangi, dangind);
	if (0 < j)
		dfs(matrix, N, i, j-1, dangi, dangind);
	if (0 < i)
		dfs(matrix, N, i-1, j, dangi, dangind);
}
int main()
{
		int N;
		scanf("%d", &N);

		int matrix[N][N], i, j;
		char str[25];
		for (i =0; i < N; i++)
		{
				scanf("%s", str);
				for (j = 0; j< N; j++)
				{
						matrix[i][j] = str[j] - '0';
				}
		}
		
		int dangi[N*N], dangind = 0;
		memset(dangi, 0, N*N*sizeof(int));
		
		for (i =0; i < N; i++)
		{
				for (j = 0; j< N; j++)
				{
					dfs(matrix[0], N, i, j, dangi, dangind++);
				}
		}
		
		int dangicnt = 0;
		for (i = 0 ; i < N*N; i++)
		{
				if(dangi[i] > 0)
				{
						dangicnt++;
				}

		}

		printf("%d\n", dangicnt);

		int temp = 0;
		for (i = 0; i < N*N-1; i++)
		{
			for( j = i; j < N*N-1-i; j++)
			{
				if(dangi[j] > dangi[j+1])
				{
						temp = dangi[j];
						dangi[j] = dangi[j+1];
						dangi[j+1] = temp;
				}
			}
		}

		for (i = 0; i < N*N; i++)
		{
				if(dangi[i]>0)
						printf("%d\n", dangi[i]);
		}
		return 0;
}
