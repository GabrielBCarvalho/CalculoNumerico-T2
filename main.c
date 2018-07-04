#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Calcula f(x) para um dado x
double calculaFx(double x){
	double res = (pow(M_E, (-pow(x, 2)) / 2)) / sqrt(2*M_PI);

	return res;
}

// Calcula a integral I(F)(x) para um dado x e um valor de N, utilizando a Fórmula de Simpson 1/3 Composta
double simpsonComposta(double x, int N){
	double h, fx0, fxN, integral, sum1 = 0, sum2 = 0; 

	h = (x - 0)/N;
	fx0 = calculaFx(0);
	fxN = calculaFx(x);

	for(int j = 1; j < N/2; j++){
		sum1 += calculaFx(2*j*h - 1);
		sum2 += calculaFx(2*j*h);
	}
	sum1 += calculaFx(2*(N/2)*h);

	integral = h/3*(fx0 + fxN + 4*sum1 + 2*sum2);

	return integral;
}

int main(int argc, char *argv[]){
	int x, N;
	double res;

	printf("Digite o valor de X a ser usado na integral: ");
	scanf("%d", &x);

	printf("Digite o valor de N a ser usado nos sub-intervalos da integral: ");
	scanf("%d", &N);

	res = simpsonComposta(x, N);

	printf("O valor aproximado da integral: %lf\n", res);

	res = simpsonComposta(1, N) - 0.45;
	res *= simpsonComposta(2, N) - 0.45;

	printf("F(1)F(2) = %lf", res);

	return 0;
}