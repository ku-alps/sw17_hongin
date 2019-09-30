#include<stdio.h>

void bubble(int * number, int arr_size)
{
	int i, j, temp;
	for (i = 0 ; i < arr_size; i++)
	{
			for (j = 0 ; j < arr_size - 1 - i ; j++)
			{
					if( *(number+j) > *(number+j+1) )
					{
							temp = *(number+j);
							*(number+j) = *(number+j+1);
							*(number+j+1) = temp;
					}
			}
	}
}
int main()
{
		int number[1000], arr_size, i;

		scanf("%d", &arr_size);

		for (i =0; i < arr_size; i++)
		{
				scanf("%d", &number[i]);
		}
		bubble(number, arr_size);

		for (i =0; i < arr_size; i++)
		{
				printf("%d\n", number[i]);
		}

}
