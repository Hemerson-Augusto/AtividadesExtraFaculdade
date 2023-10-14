#include <iostream>
#include <fstream>  // Biblioteca para manipulação de arquivos.
#include <sstream>  // Biblioteca para operações de entrada/saída de dados em strings.
#include <string>
#include <locale.h>

using namespace std;

int main(int argc, char** argv)
{
	setlocale(LC_ALL, ""); // Configuração da localização para aceitar caracteres acentuados.
	int a, i = 0;
	string text, old, password1, password2, pass, nome, senha0, idade, usuario, palavra, palavra1;
	string credenciais[2], cp[2];

	cout << "-----Sistema de Segurança-----" << endl;

	cout << "__________________________" << endl << endl;
	cout << "|------1. Registrar------|" << endl;
	cout << "|------2. Login----------|" << endl;
	cout << "|------3. Mudar senha----|" << endl;
	cout << "|______4. Encerrar o programa___|" << endl << endl;

	do
	{
		cout << endl << endl;
		cout << "Escolha a sua opção: - ";
		cin >> a;

		switch(a)
		{
		case 1:
		{
			cout << "_________________________" << endl << endl;
			cout << "|--------Registrar-------|" << endl;
			cout << "|_______________________|" << endl;
			cout << "Por favor, insira o nome de usuário:- ";
			cin >> nome;
			cout << "Por favor, insira a senha:- ";
			cin >> senha0;
			cout << "Por favor, insira a idade:- ";
			cin >> idade;

			ofstream of1;
			of1.open("file.txt");  // Abre um arquivo para escrita.
			if(of1.is_open())
			{
				of1 << nome << "\n";
				of1 << senha0;
				cout << "Registro bem-sucedido" << endl;
			}

			break;
		}
		case 2:
		{
			i = 0;
			cout << "_________________________" << endl << endl;
			cout << "|----------Login--------|" << endl;
			cout << "|_______________________|" << endl << endl;

			ifstream of2;
			of2.open("file.txt");  // Abre um arquivo para leitura.
			cout << "Por favor, insira o nome de usuário:- ";
			cin >> usuario;
			cout << "Por favor, insira a senha:- ";
			cin >> pass;

			if(of2.is_open())
			{
				while(!of2.eof())
				{
					while(getline(of2, text))  // Lê uma linha do arquivo para a string 'text'.
					{
						istringstream iss(text);  // Cria um fluxo de string a partir da linha lida.
						iss >> palavra;  // Extrai dados do fluxo de string.
						credenciais[i] = palavra;  // Armazena os dados nas credenciais.
						i++;
					}

					if(usuario == credenciais[0] && pass == credenciais[1])
					{
						cout << "---Login bem-sucedido---";
						cout << endl << endl;

						cout << "Detalhes: " << endl;

						cout << "Nome de Usuário: " + nome << endl;
						cout << "Senha: " + pass << endl;
						cout << "Idade: " + idade << endl;
					}
					else
					{
						cout << endl << endl;
						cout << "Credencial Incorreta" << endl;
						cout << "|-----1.Pressione 2 para fazer login------------|" << endl;
						cout << "|-----2.Pressione 3 para mudar a senha---------|" << endl;
						break;
					}
				}
			}

			break;
		}
		case 3:
		{
			i = 0;

			cout << "---------------Mudar senha-----------" << endl;

			ifstream of0;
			of0.open("file.txt");  // Abre um arquivo para leitura.
			cout << "Insira a senha antiga:- ";
			cin >> old;
			if (of0.is_open())
			{
				bool senhaEncontrada = false;

				while (getline(of0, text))
				{
					istringstream iss(text);
					iss >> palavra1;
					cp[i] = palavra1;
					i++;

					if (old == cp[1])
					{
						senhaEncontrada = true;
						break;
					}
				}

				if (senhaEncontrada)
				{
					of0.close();

					ofstream of1("file.txt", ios::out | ios::trunc); // Abra o arquivo no modo de saída e substituição.

					if (of1.is_open())
					{
						cout << "Insira a nova senha:- ";
						cin >> password1;
						cout << "Insira a nova senha novamente:- ";
						cin >> password2;

						if (password1 == password2)
						{
							of1 << cp[0] << "\n"; // Reescreva o nome de usuário.
							of1 << password1;      // Escreva a nova senha.
							cout << "Senha alterada com sucesso" << endl;
						}
						else
						{
							// Se as senhas não coincidirem, mantenha a senha antiga.
							of1 << cp[0] << "\n";
							of1 << old;
							cout << "As senhas não coincidem" << endl;
						}
					}
					else
					{
						cout << "Falha ao abrir o arquivo para escrita." << endl;
					}
				}
				else
				{
					cout << "Por favor, insira uma senha válida" << endl;
				}
			}
			else
			{
				cout << "Falha ao abrir o arquivo para leitura." << endl;
			}
			break;
		}
		case 4:
		{
			cout << "__________Obrigado!__________";
			break;
		}
		default:
			cout << "Insira uma opção válida";
		}
	}
	while(a != 4);
	return 0;
}
