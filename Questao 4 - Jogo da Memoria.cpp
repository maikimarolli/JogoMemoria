#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>
#include <windows.h>


int i = 0, j, k, sorteioValores[20], sorteioVetores[2] = { -1, -1}, OP;

int vetor[20] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};




int sorteioValor(void)
{
	srand(time(NULL));
	for(j = 0; j < 10; j++)
	{
		sorteioValores[j] = rand() % 300;
	}
	sorteioValores[10] = sorteioValores[0];
	sorteioValores[11] = sorteioValores[1];
	sorteioValores[12] = sorteioValores[2];
	sorteioValores[13] = sorteioValores[3];
	sorteioValores[14] = sorteioValores[4];
	sorteioValores[15] = sorteioValores[5];
	sorteioValores[16] = sorteioValores[6];
	sorteioValores[17] = sorteioValores[7];
	sorteioValores[18] = sorteioValores[8];
	sorteioValores[19] = sorteioValores[9];
// mostrar valores sorteados se necessario
//	for(i = 0; i < 20; i++)
//	{
//		printf("%d - %d \n", i, sorteioValores[i]);
//	}

	printf("Os valores sorteados para o jogo, foram: ");
	printf("\n");
	for(i = 0; i < 10; i++)
		printf("[%d]", sorteioValores[i]);
	printf("\n");
	printf("Mas agora, esses valores estao embaralhados e possuem um par.");
	printf("\n");
	return 0;
}

int sorteioVetor(void)
{
	int aux, n;
	srand(time(NULL));
	// embaralhamento do vetor
	for (i = 20 - 1; i > 0; i--)
	{
		n = rand() % 20;
		aux = sorteioValores[i];
		sorteioValores[i] = sorteioValores[n];
		sorteioValores[n] = aux;
	}
	// transfere valores para o vetor
	for(i = 0; i < 20; i++)
	{
		vetor[i] = sorteioValores[i];
	}
// mostrar vetor se necessario
//	for(i = 0; i < 20; i++)
//		printf("%d = %d\n", i, vetor[i]);

	return 0;
}

int usuarioPreencherVetor(void)
{
	printf("Voce escolheu para preencher o vetor, lembre-se, voce deve colocar 10 pares de numeros.\n");
	for(i = 0; i < 20; i++)
	{
		printf("Valor que vai ficar no vetor[%d]: ", i);
		scanf("%d", &vetor[i]);
	}
	printf("Os valores sorteados para o jogo, foram: ");
	for(i = 0; i < 10; i++)
		printf("[%d] ", vetor[i]);

	return 0;
}

int startJogo(void)
{
	int jogadorA[2] = {-1,-1}, jogadorB[2] = {-1,-1}, jogadorAQNT = 0, jogadorBQNT = 0;

	printf("Jogo iniciado, cada jogador ira fazer uma jogada por vez.\n");
	printf("Lembre-se, para sair, basta digitar o numero 22.\n");

	printf("\n");
	do
	{
jogadaA:
		printf("Jogador A, qual sua primeira jogada? ");
		scanf("%d", &jogadorA[0]);
		if(jogadorA[0] == 22)

		{
			system("cls");
			break;

		}
		else if((vetor[jogadorA[0]] == -1))
		{
			printf("O valor informado ja foi acertado.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaB;
		}
		printf("Jogador A, qual sua segunda jogada?\n");
		scanf("%d", &jogadorA[1]);
		if(jogadorA[1] == 22)
		{
			system("cls");
			break;

		}
		else if((vetor[jogadorA[1]] == -1))
		{
			printf("O valor informado ja foi acertado.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaB;
		}
		else if(jogadorA[0] > 19 || jogadorA[0] < 0 || jogadorA[1] > 19 || jogadorA[1] < 0)
		{
			printf("Jogada invalida.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaB;
		}
		else if(jogadorA[0] == jogadorA[1])
		{
			printf("Voce inseriu o mesmo valor, nao pode! Perdeu a vez.\n");
			goto jogadaB;
		}
		if(vetor[jogadorA[0]] == vetor[jogadorA[1]])
		{
			printf("Voce acertou, os pares eram: %d e %d!\n", vetor[jogadorA[0]], vetor[jogadorA[1]]);
			jogadorAQNT++;
			vetor[jogadorA[0]] = -1;
			vetor[jogadorA[1]] = -1;
		}
		else if(vetor[jogadorA[0]] != vetor[jogadorA[1]])
		{
			printf("Que triste, voce errou! Os pares foram [%d] e [%d].\n", vetor[jogadorA[0]], vetor[jogadorA[1]]);
		}

		printf("\nAgora eh a vez do jogador B.\n");

jogadaB:
		printf("Jogador B, qual sua primeira jogada? \n");
		scanf("%d", &jogadorB[0]);
		if(jogadorB[0] == 22)
		{
			system("cls");
			break;

		}
		else if((vetor[jogadorB[0]] == -1))
		{
			printf("O valor informado ja foi acertado.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaA;
		}
		printf("Jogador B, qual sua segunda jogada?\n");
		scanf("%d", &jogadorB[1]);
		if(jogadorB[1] == 22)
		{
			system("cls");
			break;

		}
		else if((vetor[jogadorB[1]] == -1))
		{
			printf("O valor informado ja foi acertado.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaA;
		}
		else if(jogadorB[0] > 19 || jogadorB[0] < 0 || jogadorB[1] > 19 || jogadorB[1] < 0)
		{
			printf("Jogada invalida.\n");
			printf("Voce perdeu a vez!\n");
			goto jogadaA;
		}
				else if(jogadorB[0] == jogadorB[1])
		{
			printf("Voce inseriu o mesmo valor, nao pode! Perdeu a vez.\n");
			goto jogadaA;
		}
		if(vetor[jogadorB[0]] == vetor[jogadorB[1]])
		{
			printf("Voce acertou, os pares era: %d e %d!\n", vetor[jogadorB[0]], vetor[jogadorB[1]]);
			jogadorBQNT++;
			vetor[jogadorB[0]] = -1;
			vetor[jogadorB[1]] = -1;
		}
		else if(vetor[jogadorB[0]] != vetor[jogadorB[1]])
		{
			printf("Que triste, voce errou! Os pares foram [%d] e [%d].\n\n", vetor[jogadorB[0]], vetor[jogadorB[1]]);
		}
	}
	while((jogadorAQNT + jogadorBQNT < 11));

	if(jogadorAQNT > jogadorBQNT)
		printf("Jogador A ganhou, parabens!\n");
	else if(jogadorBQNT > jogadorAQNT)
		printf("Jogador B ganhou, parabens!\n");
	else if(jogadorAQNT == jogadorBQNT)
		printf("Houve empate.\n");

	return 0;
}

int main()
{

	while(1)
	{
		printf("Bem vindo ao jogo da memoria! Escolha uma das opcoes para o \n   preenchimento dos valores que deverao ser encontrados.\n");
		printf("1 - Preencher valores aleatoriamente.\n");
		printf("2 - Usuario preencher valores.\n");
		printf("3 - Sair\n");
		scanf("%d", &OP);
		if(OP == 1)
		{
			sorteioValor();
			sorteioVetor();
			startJogo();
		}
		else if(OP == 2)
		{
			usuarioPreencherVetor();
			startJogo();
		}
		else if(OP == 3)
		{
			break;
		}
		else
		{
			break;
		}

	}
}
