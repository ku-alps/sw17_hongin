#include <iostream>
#include <stdio.h>

int main() {
	int e, f, c, bottles, exchanged, remained, drunk = 0;
	scanf("%d %d %d", &e, &f, &c);

	bottles = e + f;

	do {
		exchanged = bottles / c;
		remained = bottles % c;
		drunk += exchanged;
		bottles = exchanged + remained;
	} while (exchanged != 0);

	std::cout << drunk;
}
