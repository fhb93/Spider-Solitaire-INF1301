/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Sequências
*
*  Arquivo gerado:              Principal.c
*  Letras identificadoras:      PRN
*
*  Nome da base de software:    Jogo paciencia spider
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Gabriel Maia, Felipe Holanda e Felipe Zarattini
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Coordena o funcionamento do jogo Paciência Spider
*	  utilizando funções próprias e funções definidas em outros módulos
*	  que compõem este projeto
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Lista.h"
#include "Carta.h"
#include "Baralho.h"
#include "PilhaDeCartas.h"
#include "Sequencias.h"
#include "Save.h"
#include"CincoPrincipais.h"
#include "SequenciasCompletas.h"




/***********************************************************************
*
*	Função: Destruir Valor
*
***********************************************************************/
void DestruirValor(void * pValor)
{
	free(pValor);
}/* Fim função: Destruir Valor */


/***********************************************************************
*
*	Função: Inicializar Estrutura
*
***********************************************************************/

void inicializa_estrutura(LIS_tppCabeca * Princ)
{
	LIS_tppCabeca * cb1, *cb2, *cb3, *cb4, *cb5, *cb6, *cb7, *cb8, *cb9, *cb10, *cb11, *cb12, *cb13, *cb14, *cb15, *cb16, *cb17;

	cb1 = LIS_CriaLista(DestruirValor);
	cb2 = LIS_CriaLista(DestruirValor);
	cb3 = LIS_CriaLista(DestruirValor);
	cb4 = LIS_CriaLista(DestruirValor);
	cb5 = LIS_CriaLista(DestruirValor);
	cb6 = LIS_CriaLista(DestruirValor);
	cb7 = LIS_CriaLista(DestruirValor);
	cb8 = LIS_CriaLista(DestruirValor);
	cb9 = LIS_CriaLista(DestruirValor);
	cb10 = LIS_CriaLista(DestruirValor);
	cb11 = LIS_CriaLista(DestruirValor);
	cb12 = LIS_CriaLista(DestruirValor);
	cb13 = LIS_CriaLista(DestruirValor);
	cb14 = LIS_CriaLista(DestruirValor);
	cb15 = LIS_CriaLista(DestruirValor);
	cb16 = LIS_CriaLista(DestruirValor);
	cb17 = LIS_CriaLista(DestruirValor);

	LIS_InserirElementoAntes(Princ, cb17);
	LIS_InserirElementoAntes(Princ, cb16);
	LIS_InserirElementoAntes(Princ, cb15);
	LIS_InserirElementoAntes(Princ, cb14);
	LIS_InserirElementoAntes(Princ, cb13);
	LIS_InserirElementoAntes(Princ, cb12);
	LIS_InserirElementoAntes(Princ, cb11);
	LIS_InserirElementoAntes(Princ, cb10);
	LIS_InserirElementoAntes(Princ, cb9);
	LIS_InserirElementoAntes(Princ, cb8);
	LIS_InserirElementoAntes(Princ, cb7);
	LIS_InserirElementoAntes(Princ, cb6);
	LIS_InserirElementoAntes(Princ, cb5);
	LIS_InserirElementoAntes(Princ, cb4);
	LIS_InserirElementoAntes(Princ, cb3);
	LIS_InserirElementoAntes(Princ, cb2);
	LIS_InserirElementoAntes(Princ, cb1);
}/* Fim Função: Inicializar Estrutura*/

/***********************************************************************
*
*	Função: Modifica Bloqueio
*
***********************************************************************/

void ModificaBloqueio(LIS_tppCabeca * cb)
{
	LIS_tppLista * temp = LIS_AcessaListaIni(cb);

	if (temp != NULL)
	{
		if (CTA_AcessaEstado((Crt *)LIS_AcessaStruct(temp)) == 0)
		{
			CTA_AlteraEstado((Crt *)LIS_AcessaStruct(temp));
		} /* if */
		else
		{
			if (CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(temp)) == 0)
			{
				while ((LIS_Proximo(temp) == NULL) || (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(temp))) + 1) == (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))))))
				{
					if ((LIS_Proximo(temp) == NULL))
					{
						CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(temp));

						break;
					} /* if */
					else if ((CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(temp))) == (CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(LIS_Proximo(temp)))))
					{
						CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(temp));

						temp = LIS_Proximo(temp);
					} /* if */
				} /* while */
			} /* if */
		} /* if */

		if (CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(temp)) == 0)
		{
			CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(temp));
		} /* if */

		if (LIS_Proximo(temp) != NULL)
		{
			if (CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))) == 1)
			{
				while ((CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(temp))) + 1) == (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))))))
				{
					if ((CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(temp))) != (CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(LIS_Proximo(temp)))))
					{
						do
						{
							CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp)));

							temp = LIS_Proximo(temp);
						} while (CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))) == 1);
						/* do : while */
					} /* if */
					else
					{
						if (CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))) == 1 && LIS_Proximo(LIS_Proximo(temp)) != NULL)
						{
							temp = LIS_Proximo(temp);
						} /* if */
						else
						{
							break;
						} /* if */
					} /* if */
				} /* while */

				if ((CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(temp))) + 1) != (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))))))
				{
					if ((CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))) == 1))
					{
						do
						{
							CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp)));

							temp = LIS_Proximo(temp);
						} while ((LIS_Proximo(temp) != NULL) && CTA_AcessaSituacao((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))) == 1 && LIS_Proximo(temp) != NULL);
						/* do: while */
					} /* if */
				}
			} /* if */
		} /* if */
	} /* if */
} /* Fim função: Modifica Bloqueio */

/***********************************************************************
*
*	Função: Criar Novo Jogo
*
***********************************************************************/

void criar_novo_jogo(LIS_tppCabeca * Princ)
{
	int modojg;
	int i;

	LIS_tppCabeca * baralho, *destino;

	system("cls");

	printf("Aperte 1	-	para modo facil (1 naipe)!\n");
	printf("Aperte 2	-	para modo mediano (2 naipes)!\n");
	printf("Aperte 3	-	para modo dificil (3 naipes)!\n");
	printf("Aperte 4	-	para modo muito dificil (4 naipes)!\n");
	printf("Escolha: ");
	scanf(" %d", &modojg);

	baralho = (LIS_tppCabeca *)LIS_AcessaStruct(LIS_AcessaListaIni(Princ));

	BAR_CriaBaralho(baralho, modojg);

	system("cls");

	BAR_Embaralhar(baralho);

	for (i = 0; i < 5; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 2 + i);

		destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		BAR_DistribuiBaralho(baralho, destino, 10);
	}
	for (i = 0; i < 4; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 7 + i);

		destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		BAR_DistribuiBaralho(baralho, destino, 6);

		CTA_AlteraEstado((Crt *)LIS_AcessaStruct(LIS_AcessaListaIni(destino)));

		CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(LIS_AcessaListaIni(destino)));
	}
	for (i = 0; i < 6; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 11 + i);

		destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		BAR_DistribuiBaralho(baralho, destino, 5);

		CTA_AlteraEstado((Crt *)LIS_AcessaStruct(LIS_AcessaListaIni(destino)));

		CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(LIS_AcessaListaIni(destino)));
	}
}/* Fim função: Criar Novo Jogo*/

/***********************************************************************
*
*	Função: Imprimir
*
***********************************************************************/

void imprime(LIS_tppCabeca * Princ)
{
	int i;

	LIS_tppCabeca * cabeca;

	for (i = 0; i < 10; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 7 + i);

		cabeca = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		SEQ_ImprimeSequencias(cabeca, i);

		printf("\n\n");
	}
}/* Fim Função: Imprimir*/

/***********************************************************************
*
*	Função: Pedir Monte
*
***********************************************************************/

/***********************************************************************
*
*	Função: Pedir Monte
*
***********************************************************************/
void pedir_monte(LIS_tppCabeca * Princ, LIS_tppCabeca * completas)
{
	int verificador, i;

	LIS_tppCabeca * destino, *montes;

	verificador = 1;

	for (i = 0; i < 10; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 7 + i);

		destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		if (LIS_AcessaListaIni(destino) == NULL)
		{
			verificador = 0;

			printf("Voce nao deve ter sequencias vazias para pedir o monte!");

			Sleep(2500);
		}
	}

	if (verificador == 1)
	{
		for (i = 0; i < 5; i++)
		{
			LIS_IrInicioLista(Princ);

			LIS_AvancarElementoCorrente(Princ, 2 + i);

			montes = (LIS_tppCabeca *)LIS_ObterValor(Princ);

			if (LIS_AcessaListaIni(montes) != NULL)
			{
				break;
			}
		}

		if (LIS_AcessaListaIni(montes) == NULL)
		{
			printf("Voce nao pode mais pedir cartas do monte!");

			Sleep(2500);
		}
		else
		{
			for (i = 0; i < 10; i++)
			{
				LIS_IrInicioLista(Princ);

				LIS_AvancarElementoCorrente(Princ, 7 + i);

				destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

				MNT_PedeMonte(destino, montes);

				SEC_VerificaSequenciasCompletas(destino, completas);

				ModificaBloqueio(destino);
			}
		}
	}
}/* Fim Função: Pedir Monte*/

/***********************************************************************
*
*	Função: Mover Cartas das Sequências
*
***********************************************************************/

void move_cartas_sequencias(LIS_tppCabeca * Princ, LIS_tppCabeca * completas)
{
	char naipe_desejado;
	char valor_desejado[3];
	int sequencia_fonte;
	int sequencia_destino;

	int NumElem;

	LIS_tppCabeca * destino, *fonte;
	LIS_tppLista * lista;

	Crt ** vCarta;

	printf("Digite o valor da carta que deseja mover: ");
	scanf(" %[^\n]", valor_desejado);
	printf("Digite o naipe da carta que deseja mover: ");
	scanf(" %c", &naipe_desejado);
	printf("Digite o numero da sequencia em que a carta se encontra: ");
	scanf("%d", &sequencia_fonte);
	printf("Digite o numero da sequencia de destino: ");
	scanf("%d", &sequencia_destino);

	if ((sequencia_fonte > 10 || sequencia_fonte < 1))
	{
		printf("Posicao fonte invalida!");

		Sleep(2500);
	}
	else if (sequencia_destino > 10 || sequencia_destino < 1)
	{
		printf("Posicao destino invalida!");

		Sleep(2500);
	}
	else
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 6 + sequencia_fonte);

		fonte = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 6 + sequencia_destino);

		destino = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		LIS_IrInicioLista(destino);

		lista = LIS_AcessaListaIni(destino);

		if (lista == NULL || (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(lista))) - 1) == (CTA_VerificaValor(valor_desejado)))
		{
			vCarta = SEQ_RetiraCartas(fonte, valor_desejado, naipe_desejado, &NumElem);

			if (vCarta == NULL)
			{
				printf("Carta nao encontrada!");

				Sleep(2500);
			}
			else
			{
				SEQ_InsereCartas(destino, vCarta, NumElem);

				SEC_VerificaSequenciasCompletas(destino, completas);

				ModificaBloqueio(destino);

				ModificaBloqueio(fonte);
			}
		}
		else
		{
			printf("Esta carta nao pode ser movida para a poisicao desejada!");

			Sleep(2500);
		}
	}
}/* Fim da Função: Mover Cartas das Sequências*/

/***********************************************************************
*
*	Função: Main
*
***********************************************************************/

int main(void)
{
	char cond = '*';

	LIS_tppCabeca * completas;
	LIS_tppCabeca * Princ;

	Princ = LIS_CriaLista(DestruirValor);

	inicializa_estrutura(Princ);

	LIS_IrInicioLista(Princ);

	LIS_AvancarElementoCorrente(Princ, 1);

	completas = (LIS_tppCabeca *)LIS_ObterValor(Princ);

	do
	{
		system("cls");

		printf("Aperte N	-	para comecar um novo jogo!\n");
		printf("Aperte C	-	para continuar um jogo salvo!\n");
		printf("Escolha: ");
		scanf(" %c", &cond);

		if (cond == 'N' || cond == 'n')
		{
			criar_novo_jogo(Princ);
		}
		else if (cond == 'C' || cond == 'c')
		{
			SV_LoadGame(Princ);
		}
		else
		{
			printf("Opcao invalida!");

			Sleep(2500);
		}
	} while (cond != 'N' && cond != 'n' && cond != 'C' && cond != 'c');

	system("cls");

	imprime(Princ);

	printf("Digite P	-	para pedir cartas do monte\n");
	printf("Digite M	-	para mover cartas\n");
	printf("Digite S	-	para Sair e salvar o jogo corrente\n");
	printf("Escolha: ");
	scanf(" %c", &cond);

	while (cond != 'S' && cond != 's')
	{
		if (cond == 'P' || cond == 'p')
		{
			pedir_monte(Princ, completas);

			if (LIS_AcessaNumElem(completas) == 104)
			{
				cond = 'E';

				break;
			}
		}
		else if (cond == 'M' || cond == 'm')
		{
			move_cartas_sequencias(Princ, completas);

			if (LIS_AcessaNumElem(completas) == 104)
			{
				cond = 'E';

				break;
			}
		}

		system("cls");

		imprime(Princ);

		printf("Digite P	-	para pedir cartas do monte\n");
		printf("Digite M	-	para mover cartas\n");
		printf("Digite S	-	para Sair e salvar o jogo corrente\n");
		printf("Escolha: ");
		scanf(" %c", &cond);
	}

	if (cond == 'S' || cond == 's')
	{
		SV_SaveGame(Princ);
	}
	else if (cond == 'E')
	{
		system("cls");

		printf("Parabens, voce terminou o jogo!\n\n\n\t\tYou are a champion!\n");
	}

	LIS_DestroiLista(Princ);

	return 0;
}/* Fim Função: Main*/

