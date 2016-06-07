/***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:             TestaCincoPrincipais.c
*  Letras identificadoras:      TCP
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes do módulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*   	1.0    gff  24/mai/2015 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include	"Carta.h"
#include    "Lista.h"
#include	"Sequencias.h"
#include	"CincoPrincipais.h"

#define DIM_VALOR	2 

static const char PEDIR_MNT_CMD[] = "=pedirmonte";
static const char PEDIR_VAZIA_CMD[] = "=pedirparavazia";


LIS_tppCabeca * CabecaDaSequencia = NULL;
LIS_tppCabeca * CabecaDoMonte = NULL;

/* Variáveis flags de controle para que as estruturas teste sejam inicializadas apenas quando necessárias*/
int flag = 0;
int flag2 = 0;
/***** Protótipos das funções encapuladas no módulo *****/

static void DestruirValor(void * pValor);

/*****  Código das funções exportadas pelo módulo  *****/


TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	MNT_tpCondRet CondRetObtido = MNT_CondRetOK;
	MNT_tpCondRet CondRetEsperada = MNT_CondRetSequenciaVazia;
	/* inicializa para qualquer coisa */
	int numLidos = -1,
		CondRetEsp = -1;

	Crt * vetCarta[5];
	Crt * CartasDaSequencia[7];
	TST_tpCondRet CondRet;
	

	/* Testar Pedir Monte */

	if (strcmp(ComandoTeste, PEDIR_MNT_CMD) == 0)
	{
		numLidos = LER_LerParametros("i",
			&CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		if (flag == 0)
		{
			CabecaDaSequencia = LIS_CriaLista(DestruirValor);

			CabecaDoMonte = LIS_CriaLista(DestruirValor);

			vetCarta[0] = CTA_CriaCarta("A", 4, 1, 1);
			vetCarta[1] = CTA_CriaCarta("2", 6, 1, 1);
			vetCarta[2] = CTA_CriaCarta("3", 3, 1, 1);
			vetCarta[3] = CTA_CriaCarta("4", 5, 1, 1);
			vetCarta[4] = CTA_CriaCarta("5", 6, 1, 1);

			CartasDaSequencia[0] = CTA_CriaCarta("A", 4, 1, 1);
			CartasDaSequencia[1] = CTA_CriaCarta("2", 3, 1, 1);
			CartasDaSequencia[2] = CTA_CriaCarta("3", 5, 1, 1);
			CartasDaSequencia[3] = CTA_CriaCarta("4", 6, 1, 1);
			CartasDaSequencia[4] = CTA_CriaCarta("5", 4, 1, 1);
			CartasDaSequencia[5] = CTA_CriaCarta("6", 4, 1, 1);
			CartasDaSequencia[6] = CTA_CriaCarta("7", 5, 1, 1);


			SEQ_InsereCartas(CabecaDoMonte, vetCarta, 5);

			SEQ_InsereCartas(CabecaDaSequencia, CartasDaSequencia, 7);

			flag = 1;
		}

		if (LIS_AcessaListaIni(CabecaDoMonte) == NULL)
		{
			CondRetObtido = MNT_CondRetSemMontesRestantes;
		}

		else
		{
			CondRetObtido = MNT_PedeMonte(CabecaDaSequencia, CabecaDoMonte);
		}



		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao pedir cartas do monte.");
	}
	/*		Fim da Ativa: Pedir Monte com uma sequência vazia	*/

	else if (strcmp(ComandoTeste, PEDIR_VAZIA_CMD) == 0)
	{
		numLidos = LER_LerParametros("i",
			&CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */


		if (flag2 == 0)
		{
			CabecaDaSequencia = LIS_CriaLista(DestruirValor);

			CabecaDoMonte = LIS_CriaLista(DestruirValor);

			vetCarta[0] = CTA_CriaCarta("A", 4, 1, 1);
			vetCarta[1] = CTA_CriaCarta("2", 6, 1, 1);
			vetCarta[2] = CTA_CriaCarta("3", 3, 1, 1);
			vetCarta[3] = CTA_CriaCarta("4", 5, 1, 1);
			vetCarta[4] = CTA_CriaCarta("5", 6, 1, 1);

			SEQ_InsereCartas(CabecaDoMonte, vetCarta, 5);

			flag2 = 1;
		}

		if (LIS_AcessaListaIni(CabecaDoMonte) == NULL)
		{
			CondRetObtido = MNT_CondRetSemMontesRestantes;
		}
		else if (LIS_AcessaListaIni(CabecaDaSequencia) == NULL)
		{
			CondRetObtido = MNT_CondRetSequenciaVazia;
		}
		else
		{
			CondRetObtido = MNT_PedeMonte(CabecaDaSequencia, CabecaDoMonte);
		}



		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao pedir cartas para uma sequência vazia.");
	}
	/*		Fim da Ativa: Pedir Monte com uma sequência vazia	*/


	return TST_CondRetNaoConhec;

} /* Fim função: TLIS &Testar Cinco Principais */


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


/********** Fim do módulo de implementação: TCP Teste Cinco Principais **********/
