
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "fibo_compute.h"


int main(int argc, const char* argv[]) {

	int i = 0;
	clock_t tic =0;
	clock_t tac = 0;
	while ((double)(tac - tic)*10000 / CLOCKS_PER_SEC<=1000){
		tic = clock();
		//printf("fibo_rec (%d) = %d ",i, fibo_rec(i));
		fibo_rec(i);
		tac = clock();
		i++;
		//printf(": %f mseconds rec\n", (double)(tac - tic)*10000 / CLOCKS_PER_SEC);		
	}

	printf("i = %d ",i);
	printf(": %f mseconds rec\n", (double)(tac - tic)*10000 / CLOCKS_PER_SEC);

	// plus d'une seconde a partir de 45
	//somme des deux puissance i pour i allant de o à environ n 

	int j = 160000000;
	clock_t tic2 =0;
	clock_t tac2 =000000000000000000;
	while ((double)(tac2 - tic2)*10000 / CLOCKS_PER_SEC<=1000){
		tic2 = clock();
		//printf("fibo_iter (%d) = %d ",j, fibo_iter(j));
		fibo_iter(j);
		tac2 = clock();
		j+= 1;
		//printf(": %f mseconds iter\n", (double)(tac2 - tic2)*10000 / CLOCKS_PER_SEC);		
	}

	printf("j = %d ",j);
	printf(": %f mseconds iter\n", (double)(tac2 - tic2)*10000 / CLOCKS_PER_SEC);

	//plus d'une seconde à partir de 16 000 000 000
	//complexité en grand O de n

	unsigned long long int k = 0000000;
	clock_t tic3 =0;
	clock_t tac3 =000000000000000000;
	while ((double)(tac3 - tic3)*10000 / CLOCKS_PER_SEC<=1000){
		tic3 = clock();
		//printf("fibo_iter (%d) = %d ",j, fibo_iter(j));
		fibo_rec2(k);
		tac3 = clock();
		k+= 1000000;
		//printf(": %f mseconds iter\n", (double)(tac2 - tic2)*10000 / CLOCKS_PER_SEC);		
	}

	printf("k = %llu ",k);
	printf(": %f mseconds rec2\n", (double)(tac3 - tic3)*10000 / CLOCKS_PER_SEC);


	printf("%f puissance %llu  = %llu \n", 2.0f, (unsigned long long int) 10, puissance(2.0f, (unsigned long long int)10));


	printf("fibo_golden %llu  = %llu \n",(unsigned long long int) 100, fibo_golden((unsigned long long int)100));
	printf("fibo_iter (%d) = %llu \n ",100, fibo_iter((unsigned long long int) 100));
	
		return 0;
}
