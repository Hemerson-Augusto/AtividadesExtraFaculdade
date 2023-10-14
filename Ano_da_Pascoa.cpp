#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int ano;
	cout << "Digite um ano (1901-2099): ";
	cin >> ano;

	int A = ano % 19;
	int B = ano % 4;
	int C = ano % 7;
	int D = (19 * A + 24) % 30;
	int E = (2 * B + 4 * C + 6 * D + 5) % 7;

	int dia, mes;

	if (D + E > 9)
	{
		dia = D + E - 9;
		mes = 4;
	}
	else
	{
		dia = D + E + 22;
		mes = 3;
	}

	if (dia == 26 && mes == 4)
	{
		dia = 19;
	}
	else if (dia == 25 && D == 28 && A > 10)
	{
		dia = 18;
	}

	cout << "A Páscoa será no dia " << dia << " de ";
	if (mes == 3)
	{
		cout << "março";
	}
	else
	{
		cout << "abril";
		cout << " de " << ano << endl;
	}

	return 0;
}
/*1) (3,5) O Domingo de Páscoa é o primeiro domingo depois da primeira lua cheia posterior ao
equinócio da primavera e é determinado pelo seguinte cálculo (para os anos de 1901 a
2099):
A = ano mod 19
B = ano mod 4
C = ano mod 7
D = (19 * A + 24) mod 30
E = (2 * B + 4 * C + 6 * D + 5) mod 7
Sendo:
• Se a soma de D + E for maior que 9, então a Páscoa será em abril e o dia será
calculado pela fórmula (D + E – 9).
• Caso contrário o mês será março e o dia será calculado pela fórmula (D + E + 22).
Existem dois casos especiais, que ocorrem duas vezes por século:
• Quando o domingo de Páscoa cair em abril e o dia for 26, corrige-se para uma
semana antes, ou seja, vai para o dia 19.
• Quando o domingo de Páscoa cair em abril e o dia for 25, a variável D for igual a 28
e A maior que 10, o dia será corrigido para 18.
Faça um programa que solicite ao usuário um ano e informe, ao final, a data completa
(dia, mês e ano) do Domingo de Páscoa. Exemplo: A Páscoa será no dia 4 de abril de
2010. Obs.: mod é a operação de resto de divisão inteira (%).
*/

/*Ano: 2020
Resultado: A Páscoa será no dia 12 de abril de 2020.
Ano: 2023
Resultado: A Páscoa será no dia 26 de março de 2023.
Ano: 1988
Resultado: A Páscoa será no dia 3 de abril de 1988.
Ano: 2000
Resultado: A Páscoa será no dia 23 de abril de 2000.
Ano: 2050
Resultado: A Páscoa será no dia 9 de abril de 2050.*/
