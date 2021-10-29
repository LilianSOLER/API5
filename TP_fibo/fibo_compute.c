#include "fibo_compute.h"

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
	

matrice22 mult(matrice22 m, matrice22 l){
	matrice22 res;
	res.a = m.a*l.a + m.b*l.b;
	res.b = m.a*l.b + m.b*l.a;
	res.c = m.c*l.a + m.d*l.b;
	res.d = m.c*l.b + m.d*l.a;
	return res;
}

matrice21 mult_dif(matrice22 m, matrice21 l){
	matrice21 res;
	res.a = m.a*l.a + m.b*l.b;
	res.b = m.c*l.a + m.d*l.b;
	return res;
}

matrice22 puissancem (matrice22 m,unsigned long long int n){
	matrice22 res = m;
	if(n==1){
		return m;
	}
	else if (n%2==0){
		return puissancem(mult(m,m),n/2);
	}
	else {
		return mult(m,puissancem(mult(m,m),(n-1)/2));
	}
	return res;
	}

	matrice21 fibo_matrice(unsigned long long int n){
		matrice21 a,b;
		matrice22 c,d;
		c.a = 0; c.b = 1; c.c = 1; c.d = 1;
		a.a = 0 ; a.b = 1;
		d = puissancem(c,n-1);
		b = mult_dif(d,a);
		return b;
	}