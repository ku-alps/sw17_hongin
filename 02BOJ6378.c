#include <stdio.h>
#include <math.h>
void toChArr(char* N, int number)
{
		int n = log10(number) + 1;
		int i;

		//printf("\nnumber : %d\n", number);
		//printf("n : %d\n", n);
		*(N+n) = '\n';
		for (i = n-1; i>=0; i--, number /= 10)
		{
				//printf("%d", number % 10);
				*(N + i) = '0' + number % 10;
		}
		for (i=0; *(N+i) != '\n'; i++){
				//printf("%c", *(N+i));
		}
		//printf("\n\n");
}		

int main()
{

		char N [1002];
		int answer[1000], count = 0;	
		while(1)	
		{
				fgets(N, sizeof(N), stdin);
				if (N[0] == '0')
						break;
				//int i;
				//for (i = 0; N[i]!='\0'; i++)
				//		printf("%c", N[i]);
				int sum = 0, i;
				do
				{
						sum = 0;
						for (i = 0; N[i] != '\n'; i++)
						{
								//printf("C : %c", N[i]);
								sum += N[i] - '0';
								//printf(" - D :  %d\n", sum);
						}
						//printf("%d", sum);
						toChArr(N, sum);
				}
				while(sum > 9);
				//printf("%d\n", sum);
				answer[count++] = sum;
		}

		int i;
		for (i = 0 ; i < count; i++) 
		{
				printf("%d\n", answer[i]);
		}

		return 0;
}

