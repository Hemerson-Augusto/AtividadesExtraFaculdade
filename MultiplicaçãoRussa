#include <iostream>
#include <locale.h>
using namespace std;

/*Esse loop está implementando o algoritmo de multiplicação Russa,
que envolve dividir um dos números (no caso, A) por 2 repetidamente até que ele se torne
0 ou negativo, enquanto o outro número (no caso, B)
é multiplicado por 2 a cada iteração e somado à variável soma sempre que A for ímpar.
O resultado final é armazenado em soma.*/
int main()
{
	setlocale(LC_ALL, "");
	int A, B;
	cout << "Digite o numero A: ";
	cin >> A ;
	cout << "Digite o numero B: ";
	cin >> B ;

	int soma = 0;

	while (A > 0)
	{
		if (A % 2 == 1)
		{
			soma += B;
		}
		A /= 2;
		B *= 2;
	}

	cout << "O resultado da multiplicação à Russa é: " << soma << endl;

	return 0;
}
/*A multiplicação à Russa consiste em:
a) Escrever os números A e B, que se deseja multiplicar na parte superior das colunas.
b) Dividir A por 2, sucessivamente, ignorando o resto até chegar à unidade, escrevendo os
resultados da coluna A.
c) Multiplicar B por 2 tantas vezes quantas se haja dividido A por 2, escrevendo os
resultados sucessivos na coluna B.
d) Somar todos os números da coluna B que estejam ao lado de um *número ímpar da coluna A*.
A      B      Parcelas
27     82       82
13     164     164
6      328      -
3      656      656
1     1312     1312
Soma: 2214
Faça um programa que solicite dois valores ao usuário (um por vez, sendo que não podem
ser menores que 0), e exiba o resultado da multiplicação entre os dois valores utilizando a
multiplicação à Russa*/

/*ex: 15 e 7
soma = 115
resultado é a soma*/
