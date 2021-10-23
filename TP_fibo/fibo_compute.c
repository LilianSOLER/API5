#include "fibo_compute.h"

matrice allouer_matrice(int l, int c) {
    
    matrice m = { 0, 0, NULL };
    m.l = l;
    m.c = c;
    if (l>0 && c>0){
        m.donnees = malloc (l*sizeof(unsigned long long int));
        for (int i = 0; i<m.l; i++){
            m.donnees[i] = malloc(c*sizeof(unsigned long long int));
        }
        
    }
    return m;
}

matrice mult(matrice m, matrice l,int n){
	matrice res = allouer_matrice(n,n);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			for(int k =0; k < n; k++){
				res.donnees[i][j] += m.donnees[i][k]*l.donnees[k][j];
			}
		}
	}
	return res;
}



unsigned long long int fibo_rec(int n) {
	if ( n<1){
		return 4;
	}
	else if (n == 1){
		return n;
	}

	return fibo_rec(n-2) + fibo_rec(n-1);

}

unsigned long long int fibo_iter(int n) {
	if (n<=0){
		return 4;
	}
	int fib1 = 0;
	int fib2 = 1;
	int res = 0;
	for (int i = 1; i<=n; i++){
		if ( i==1){
			res = fib2;
		}
		else {
			res = fib1+fib2;
			fib1 = fib2;
			fib2 = res;
		}
	}
	return res;


}

unsigned long long int fibo_rec2(unsigned long long int n) {
	if ( n<1){
		return 4;
	}
	return fibo_rec2_aux( n, 0, 1);

}

unsigned long long int fibo_rec2_aux(unsigned long long int n,unsigned long long int a, unsigned long long int b) {
	if (n==0){
		return (a);
	}
	if (n==1){
		return b; 
	}
	return fibo_rec2_aux(n-1,b,a+b);
}

unsigned long long int puissance (float x,unsigned long long int n){
	int long long res = 1;
	while (n>0){
		if (n%2 == 1){
			res *= x;
			n--;
		}
		x *= x;
		n /= 2;
	}
	return res;
	}

unsigned long long int fibo_golden(unsigned long long int n ){
	float rac_cinq = 2.236;
	float phi = (1+rac_cinq)/2;
	float delta = (1-rac_cinq)/2;
	return (1/rac_cinq)*(puissance(phi,n)-puissance(delta,n));
}
	
void identity(matrice m,int n){
	for(int i = 0; i < n ; i++){
		for(int j = 0; j < n; j++){
			if(i == j){
				m.donnees[i][i] = 1;
			} else {
				m.donnees[i][j] = 0;
			}
		}
	}
}
matrice puissancem (matrice m,unsigned long long int n){
	matrice res = allouer_matrice(2,2);
	identity(res,2);
	while(n>0){
		if (n%2 == 1){
			res = mult(res,m,2);
			n--;
		}
		m = mult(m,m,2);		
		n /= 2;
	}
	return res;
	}