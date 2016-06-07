/***************************************************************************
*
*  $MCD Módulo de definição: Módulo tpLista
*
*  Arquivo gerado:              Save.c
*  Letras identificadoras:      SV
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
*     O módulo Save é usado para carregar um jogo salvo anteriorente
*	  ou para salvar um jogo corrente
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Carta.h"
#include "Save.h"
#include "Lista.h"
#include "PilhaDeCartas.h"



/***********************************************************************
*
*	Função: SV Save
*
***********************************************************************/

SV_tpCondRet SV_SaveGame(LIS_tppCabeca * Princ)
{
	FILE * SAVE;

	LIS_tppCabeca * cb;

	LIS_tppLista * lst = NULL;

	Crt * carta;

	char * val;
	char naipe;
	int estado;
	int situacao;

	int i;

	SAVE = fopen("Save.txt", "w");

	if (SAVE == NULL)
	{
		printf("Erro de criacao de arquivo!");

		return SV_CondRetErroCriarArquivo;
	} /* if */

	for (i = 0; i < 16; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 1 + i);

		cb = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		lst = LIS_AcessaListaFim(cb);

		while (lst != NULL)
		{
			carta = PDCRT_Pop(cb);

			val = CTA_AcessaValor(carta);
			naipe = CTA_AcessaNaipe(carta);
			estado = CTA_AcessaEstado(carta);
			situacao = CTA_AcessaSituacao(carta);

			fprintf(SAVE, "%d %d %d %d\n", CTA_VerificaValor(val), (int)naipe, estado, situacao);

			lst = LIS_AcessaListaFim(cb);
		} /* while */

		fprintf(SAVE, "-\n");
	} /* if */

	fclose(SAVE);

	return SV_CondRetOK;
} /* Fim função: SV Save */

/***********************************************************************
*
*	Função: SV Load
*
***********************************************************************/

SV_tpCondRet SV_LoadGame(LIS_tppCabeca * Princ)
{
	FILE * SAVE;

	int val;
	int naipe;
	int estado;
	int situacao;
	int i;

	char valor[3];

	Crt * carta;

	LIS_tppCabeca * temp;

	SAVE = fopen("Save.txt", "r");

	if (SAVE == NULL)
	{
		printf("Erro de abertura de arquivo!");

		return SV_CondRetErroAbrirArquivo;
	} /* if */

	for (i = 0; i < 16; i++)
	{
		LIS_IrInicioLista(Princ);

		LIS_AvancarElementoCorrente(Princ, 1 + i);

		temp = (LIS_tppCabeca *)LIS_ObterValor(Princ);

		while (fscanf(SAVE, " %d %d %d %d", &val, &naipe, &estado, &situacao) == 4)
		{
			strcpy(valor, CTA_ConverteValor(val));

			carta = CTA_CriaCarta(valor, (char)naipe, estado, situacao);

			LIS_InserirElementoApos(temp, carta);
		} /* while */
	} /* for */

	fclose(SAVE);

	return SV_CondRetOK;
} /* Fim função: SV Load */


/**************   Fim do módulo de implementação: Save  *****************/