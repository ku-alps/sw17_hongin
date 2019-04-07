#include <stdio.h>

int main()
{
		char line[50+1+50+1+1];
		fgets(line, sizeof(line), stdin);

		int i, a_len, b, b_len, e;

		for (i = 0; i < 103; i++)
		{
				if ( line[i] == ' ')
				{
						a_len = i;
						b = i + 1;
				}
				
				if ( line[i] == '\n')
				{
						b_len = i - b;
						break;
				}
		}

		int diff = b_len - a_len;
		int offset, count, min = a_len;

		//printf("a: %d, b: %d, a_len: %d, b_len: %d, diff: %d, min: %d\n", 0, b, a_len, b_len, diff, min);

		for (offset = 0; offset <= diff ; offset++)
		{
				count = 0;
				//printf("Offset is %d\n", offset);
				for (i = 0; i < a_len; i++)
				{
						//printf("i: %d/%d, a: %c, b: %c", i, a_len, line[i], line[b+offset+i]);
						if (line[i] != line[b+i+offset])
						{
								//printf(" different");
								count++;
						}
						//printf("\n");
				}

				if(count < min)
						min = count;
				//printf("Min is %d\n", min);
		}
		
		printf("%d", min);

		return 0;
}
