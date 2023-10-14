#include <iostream>
#include <cstdlib>// Habilita funções de system
#include <ctime> // Habilitar a função Time para gerar numeros aleatórios no rand
#include <locale.h> // Caracteres especiais

using namespace std;

void inicio()//Ascii Para O layout intuitivo
{
	cout << "\n";
	cout << ".______    __           ___        ______  __  ___           __       ___        ______  __  ___ \n";
	cout << "|   _  \\  |  |         /   \\      /      ||  |/  /          |  |     /   \\      /      ||  |/  / \n";
	cout << "|  |`_) | |  |        /  ^  \\    |  ,----'|  '  /           |  |    /  ^  \\    |  ,----'|  '  /  \n";
	cout << "|   _  <  |  |       /  /_\\  \\   |  |     |    <      .--.  |  |   /  /_\\  \\   |  |     |    <   \n";
	cout << "|  |_)  | |  `----. /  _____  \\  |  `----.|  .  \\     |  `--'  |  /  _____  \\  |  `----.|  .  \\  \n";
	cout << "|______/  |_______|/__/     \\__\\  \\______||__|\\__\\     \\______/  /__/     \\__\\  \\______||__|\\__\\ \n";
	cout << "                                                                       \n";

}

int main()// Função main para inicialização do código principal
{

	setlocale(LC_ALL, "");//Função para caractéres especiais e na lingua pt-BR

	// Inicializa a semente para a função rand()
	srand(time(0));

	char JogarNovamente;//Função para jogar SIM ou Não
	int rodadas = 0;//Contador de rodadas
	int moedas = 10; // adiciona a quantidade de moedas do jogador
	int limiteApostas = 1; // Define o limite de apostas da mesa
	int vitoriasPlayer = 0; // Contador de vitorias do Player Principal
	int vitoriasDealer = 0;// Contador de vitorias do Player Computador
	int opcao; // Função para o Menu
	int playerTotal = 0;//Contador de carta do player Principal
	int dealerTotal = 0;//Contador de carta do player Computador
	int aposta;

	inicio();// Função Ascii para layout


	// Loop para jogar várias rodadas
	// O jogo continua enquanto o jogador tiver moedas
	while (moedas > 0)
	{
		// Variável de controle do jogo
		bool jogoEmAndamento = true;

		playerTotal = 0;
		dealerTotal = 0;

		cout << "\nMenu:\n";
		cout << "1. Iniciar Jogo\n";
		cout << "2. Sobre\n";
		cout << "3. Sair\n";
		cout << "Escolha uma opção: ";
		cin >> opcao;

		switch (opcao)
		{
		case 1:
		{
			if (moedas < limiteApostas)
			{
				//Verifica se o player tem moedas para apostar e jogar
				cout << "Você não tem moedas suficientes para jogar." << endl;
				break;
			}
			//Mostra a quantidade de moedas e permite insereri um valor para apostar
			cout << "Suas moedas: " << moedas << endl;
			cout << "Digite sua aposta (limite: " << limiteApostas << " moedas): ";
			cin >> aposta;

			if (aposta < limiteApostas || aposta > moedas)
			{
				cout << "Aposta inválida. Por favor, insira uma aposta válida." << endl;
				break;
			}
			//contador de moedas para perdas
			moedas -= aposta;
			// Dobrar a aposta
			aposta *= 2;
			//Contador de Rodadas
			rodadas++;
			
			//Inicia o Jogo enquanto "jogoEmAndamento" for true
			while (jogoEmAndamento)
			{
				system("cls");

				// Gera cartas aleatórias para o jogador e o dealer
				int playerCard = rand() % 10 + 1;
				int dealerCard = rand() % 10 + 1;

				// Tratar o valor do Ás
				if (playerCard == 1)
				{
					if (playerTotal + 11 <= 21)
					{
						playerCard = 11;
					}
				}

				if (dealerCard == 1)
				{
					if (dealerTotal + 11 <= 21)
					{
						dealerCard = 11;
					}
				}

				// Atualiza o total do jogador e exibe sua carta
				playerTotal += playerCard;
				cout << "Sua carta: " << playerCard << endl;
				cout << " Seu total: " << playerTotal << endl;

				// Atualiza o total do dealer e exibe sua carta
				dealerTotal += dealerCard;
				cout << " Carta do dealer: " << dealerCard << endl;
				cout << " Total dealer: " << dealerTotal << endl;

				// Verificia quem estourou o 21 e ganha a rodada
				if(playerTotal > 21 && dealerTotal > 21)
				{
					cout<<"Você player e Dealer Estouraram, ambos perderam"<<endl;
					moedas += limiteApostas;
					break;
				}
				
				else if (playerTotal > 21)
				{
					cout << "Você estourou! Dealer vence." << endl;
					vitoriasDealer++;
					break;
				}
				else if (dealerTotal > 21)
				{
					cout << "Dealer estourou! Você vence." << endl;
					moedas += aposta; // Jogador ganha o dobro da aposta
					vitoriasPlayer++;
					break;
				}
				else if (playerTotal == 21)
				{
					cout << "Você tem 21! Você vence." << endl;
					moedas += aposta; // Jogador ganha o dobro da aposta
					vitoriasPlayer++;
					break;
				}
				else if (dealerTotal == 21)
				{
					cout << "Dealer tem 21! Dealer vence." << endl;
					vitoriasDealer++;
					break;
				}

				// Pergunta ao jogador se ele quer continuar jogando
				cout << "Deseja continuar jogando ? (s / n) : ";
				cin >> JogarNovamente;

				if (JogarNovamente == 'n' || JogarNovamente == 'N')
				{
					jogoEmAndamento = false;
				}
			}
			if (playerTotal > dealerTotal && playerTotal < 21)
			{
				cout << "Você venceu a rodada!" << endl;
				moedas += aposta; // Jogador ganha o dobro da aposta
				vitoriasPlayer++;
			}
			else if (playerTotal < dealerTotal && dealerTotal < 21)
			{
				cout << "Dealer venceu a rodada." << endl;
				vitoriasDealer++;
			}
			else if (playerTotal == dealerTotal)
			{
				cout << "Rodada empatada." << endl;
				moedas += limiteApostas;
			}

			break;
		}
		case 2:
		{
			system("cls");
			cout << "Professora: Cristina Onorio" << endl;
			cout << "Aluno: Hemerson Augusto da Silva Nascimento" << endl;
			cout << "Matéria: Algoritmo e Programação!" << endl;
			cout << "Curso: Ciência da Computação" << endl;
			cout << "Trabalho sobre o jogo Black Jack" << endl;
			cout << "Data de entrega 30/10/2023" << endl;

			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			moedas = 0;
			break;
		}
		default:
		{
			system("cls");
			cout << "Opção inválida. Por favor, escolha uma opção válida." << endl;
			break;
		}

		}
	}
	// Exibe os totais finais
	if (rodadas > 0)
	{
		cout << "Vitórias do jogador : " << vitoriasPlayer << endl;
		cout << "Vitórias do dealer : " << vitoriasDealer << endl;
	}
	// Exibe a contagem de rodadas ao sair do jogo
	//Quantas vezes o jogo foi jogado
	cout << "Você jogou um total de " << rodadas  << "x o Jogo Black jack." << endl;
	// Pausa para que o jogador possa ver o resultado antes de fechar
	system("pause");

	return 0;
}
