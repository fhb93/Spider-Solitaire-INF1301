/***************************************************************************
*  $MCI Módulo de implementação: TSEQ Teste Sequências
*
*  Arquivo gerado:             TestaSequencias.c
*  Letras identificadoras:      TSEQ
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes do módulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*     1.0      gff   26/mai/2015 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include    "Carta.h"
#include	"PilhaDeCartas.h"
#include    "Sequencias.h"

#define DIM_VALOR     2 

static const char RETIRA_SEQ_CMD[] = "=retirarcarta";
static const char RETIRAVAZIA_SEQ_CMD[] = "=retirarseqvazia";
static const char INSERE_SEQ_CMD[] = "=inserircarta";
static const char IMPRIME_SEQ_CMD[] = "=imprimirsequencia";

LIS_tppCabeca * CabecaTeste;
LIS_tppCabeca * CabecaTeste2;
LIS_tppCabeca * CabecaTesteVazia;

Crt * vetCartas[7];
Crt ** vetCartas2;
int vTam;

/* Variável flag utilizada para controlar a estrutura teste que deve ser
	inicializada apenas uma vez*/
int flag = 0;

/***** Protótipos das funções encapsuladas no módulo *****/

static void DestruirValor(void * pValor);

/*****  Código das funções exportadas pelo módulo  *****/



TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	SEQ_tpCondRet CondRetObtido = SEQ_CondRetOK;
	SEQ_tpCondRet CondRetEsperada = SEQ_CondRetOK;
	/* inicializa para qualquer coisa */

	int numLidos = -1,
		CondRetEsp = -1;
	char NaipeDado;
	char ValorDado[DIM_VALOR];
	
	int i;

	if (flag == 0)
	{
		CabecaTeste = LIS_CriaLista(DestruirValor);
		CabecaTeste2 = LIS_CriaLista(DestruirValor);
		CabecaTesteVazia = LIS_CriaLista(DestruirValor);

		vetCartas[0] = CTA_CriaCarta("A", 3, 1, 1);
		vetCartas[1] = CTA_CriaCarta("2", 4, 1, 1);
		vetCartas[2] = CTA_CriaCarta("3", 5, 1, 1);
		vetCartas[3] = CTA_CriaCarta("4", 3, 1, 1);
		vetCartas[4] = CTA_CriaCarta("5", 5, 1, 1);
		vetCartas[5] = CTA_CriaCarta("6", 6, 1, 1);
		vetCartas[6] = CTA_CriaCarta("7", 6, 1, 1);

		SEQ_InsereCartas(CabecaTeste, vetCartas, 7);

		flag = 1;
	}
	
	/* Testar Inserir Carta */

	if (strcmp(ComandoTeste, INSERE_SEQ_CMD) == 0)
	{
		numLidos = LER_LerParametros("i", &CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = SEQ_InsereCartas(CabecaTeste2, vetCartas2, vTam);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Condicao de retorno errada ao inserir carta");
	} /*    Fim da Ativa: Testar Inserir Carta   */


	/*		Testar Retirar Carta		*/
	else if (strcmp(ComandoTeste, RETIRA_SEQ_CMD) == 0)
	{
		numLidos = LER_LerParametros("sci", ValorDado, &NaipeDado, &CondRetEsperada);

		if (numLidos != 3)
		{
			return TST_CondRetParm;
		} /* if */
		if (LIS_AcessaListaIni(CabecaTeste) == NULL)
		{
			CondRetObtido = SEQ_CondRetSequenciaVazia;
		}/* if */
		else
		{
			vetCartas2 = SEQ_RetiraCartas(CabecaTeste, ValorDado, NaipeDado, &vTam);
			if (vetCartas2 == NULL)
			{
				CondRetObtido = SEQ_CondRetCartaNaoEncontrada;
			}/* if */
			else {
				CondRetObtido = SEQ_CondRetOK;
			}
		}
		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao retirar carta");
	}
	/*		Fim da Ativa: Testar Retirar Carta		*/

	/*		Testar Retirar de uma sequência vazia		*/
	else if (strcmp(ComandoTeste, RETIRAVAZIA_SEQ_CMD) == 0)
	{
		numLidos = LER_LerParametros("sci", ValorDado, &NaipeDado, &CondRetEsperada);

		if (numLidos != 3)
		{
			return TST_CondRetParm;
		} /* if */
		
		if (LIS_AcessaListaIni(CabecaTesteVazia) == NULL)
		{
			CondRetObtido = SEQ_CondRetSequenciaVazia;
		}/* if */
		else
		{
			vetCartas2 = SEQ_RetiraCartas(CabecaTesteVazia, ValorDado, NaipeDado, &vTam);
			if (vetCartas2 == NULL)
			{
				CondRetObtido = SEQ_CondRetCartaNaoEncontrada;
			}/* if */
			else {
				CondRetObtido = SEQ_CondRetOK;
			}
		}
		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao retirar carta de sequência vazia");
	}
	/*		Fim da Ativa: Testar Retirar de uma sequência vazia		*/




	/*		Testar Imprimir Sequências		*/
	else if (strcmp(ComandoTeste, IMPRIME_SEQ_CMD) == 0)
	{
		numLidos = LER_LerParametros("i", &CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		printf("\n");
		CondRetObtido = SEQ_ImprimeSequencias(CabecaTeste, 0);
		printf("\n");
		CondRetObtido = SEQ_ImprimeSequencias(CabecaTeste2, 1);
		
		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao imprimir sequencias");
	}
	/*		Fim da Ativa: Testar Imprimir Sequências		*/



	return TST_CondRetNaoConhec;

} /* Fim função: TSEQ &Testar Sequências */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim função: Destruir valor */


/********** Fim do módulo de implementação: TSEQ Testar Sequências **********/
