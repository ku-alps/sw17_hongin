#include<stdio.h>
#include<stdbool.h>

bool chkcmp(int A, int B);

int main()
{
		int ts_sz, i, A, B;
		scanf("%d", &ts_sz);
		for ( i = 0; i < ts_sz ; i++){
				scanf("%d %d", &A, &B);
				if( chkcpt(A, B) )
				{
						printf("yes");
				} 
				else
				{
						printf("no");
				}
		}
		return 0;
}

bool chkcpt(int A, int B)
{
		int i;
		for(i = 1; i < A; i++)
		{
				

		return true;
}
