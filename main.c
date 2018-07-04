#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calcula f(x) para um dado x
double calculaFx(double x){
	double res = (pow(M_E, (-pow(x, 2)) / 2)) / (sqrt(2*M_PI));

	return res;
}

// Calcula a integral I(F)(x) para um dado x e um valor de N, utilizando a Fórmula de Simpson 1/3 Composta
double simpsonComposta(double x, int N){
	double h, fx0, fxN, integral, sum1 = 0, sum2 = 0; 

	h = (x - 0)/N;
	fx0 = calculaFx(0);
	fxN = calculaFx(x);

	for(int j = 1; j < N/2; j++){
		sum1 += calculaFx((2*j-1)*h);
		sum2 += calculaFx(2*j*h);
	}
	sum1 += calculaFx((2*(N/2)-1)*h);

	integral = (h/3)*(fx0 + fxN + 4*sum1 + 2*sum2);

	return integral;
}

// Usa o método de Newton para determinar a raiz da equação descrita
double metodoDeNewton(int N){
	double xn1 = 0.5, xn, eps = pow(10, -10);
	
	do{
		xn = xn1;
		xn1 = xn - ((simpsonComposta(xn, N) - 0.45) / calculaFx(xn));
	}
	while (fabs(xn1 - xn) >= eps);

	return xn1;
}

int main(int argc, char *argv[]){
	int N;
	double res, x;

	printf("Digite o valor de X a ser usado no intervalo da integral: ");
	scanf("%lf", &x);

	printf("Digite o valor de N a ser usado nos sub-intervalos da integral: ");
	scanf("%d", &N);

	res = simpsonComposta(x, N);

	printf("O valor aproximado da integral: %lf\n", res);

	res = simpsonComposta(1, N) - 0.45;
	res *= simpsonComposta(2, N) - 0.45;

	printf("F(1)F(2) = %lf\n", res);

	res = metodoDeNewton(N);
	printf("Raiz = %lf\n", res);

	return 0;
}