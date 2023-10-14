#include <iostream>
#include <locale.h>

using namespace std;

int main()
{
	setlocale(LC_ALL, "");

	int dia, mes, ano;

	cout << "Digite uma data no formato (dia/mês/ano): ";
	cin >> dia >> mes >> ano;

	bool dataValida = true;
	//Verificica se o ano é negativo, mes nao pode ser menor que 1 e nem maior que 12
	if (ano < 0 || mes < 1 || mes > 12)
	{
		dataValida = false;
	}
	//verifica se o mes de fevereiro é bissexto ou não
	else if (mes == 2)
	{
		//verifica se o ano do mes de fevereiro é bissexto ou não é conforme o ano
		if ((ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0))
		{
			if (dia < 1 || dia > 29)
				dataValida = false;
		}
		else
		{
			if (dia < 1 || dia > 28)
				dataValida = false;
		}
	}
	//mes 4(abril),6(junho),9(setembro),11(novembro) possuem 30 dias
	else if (mes == 4 || mes == 6 || mes == 9 || mes == 11)
	{
		if (dia < 1 || dia > 30)
			dataValida = false;
	}
	//Verifica os meses de janeiro, março, maio, julho, agosto, outubro e dezembro possuem 31 dias.
	else
	{
		if (dia < 1 || dia > 31)
			dataValida = false;
	}

	if (dataValida)
		cout << "A data é válida, e é Ano Bissexto." << endl;
	else
		cout << "A data não é válida ou não é um Ano Bissexto." << endl;

	return 0;
}
/*3) (3,5) Faça um algoritmo que solicite ao usuário uma data, composta de 3 variáveis: dia, mês
e ano. Informe se a data digitada é válida ou não, considerando:
• Anos bissextos (considerando todas as regras dos anos bissextos): em anos
bissextos fevereiro possui 29 dias. Nos outros anos 28 dias.
• Meses: existem somente meses de 1 a 12.
• Dias: os meses de janeiro, março, maio, julho, agosto, outubro e dezembro
possuem 31 dias. O mês de fevereiro pode possuir 28 ou 29 dias. O restante possui
30 dias.
• Anos, meses e dias nunca serão negativos.
Obs: anos bissextos são dados pelas regras (segundo o calendário Gregoriano):
i) De 4 em 4 anos é ano bissexto.
ii) De 100 em 100 anos não é ano bissexto.
iii) De 400 em 400 anos é ano bissexto.
iv) Prevalecem as últimas regras sobre as primeiras.
A título de curiosidade, o ano de 1900 foi o último ano a ser aplicada a regra ii (não é
bissexto). A próxima vez será em 2100.*/

/*Exemplos
Data: 29 02 2020 (Ano bissexto)
Resultado: A data é válida.

Data: 29 02 2023 (Não é um ano bissexto)
Resultado: A data não é válida.

Data: 31 04 2023 (Abril não possui 31 dias)
Resultado: A data não é válida.

Data: 25 12 2022 (Data válida)
Resultado: A data é válida.

Data: 0 11 2025 (Dia não pode ser 0)
Resultado: A data não é válida.
*/
