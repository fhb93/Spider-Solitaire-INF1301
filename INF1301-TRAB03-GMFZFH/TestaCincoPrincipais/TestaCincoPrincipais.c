/***************************************************************************
*  $MCI M�dulo de implementa��o: TLIS Teste lista de s�mbolos
*
*  Arquivo gerado:             TestaCincoPrincipais.c
*  Letras identificadoras:      TCP
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes do m�dulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*   	1.0    gff  24/mai/2015 in�cio desenvolvimento
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

/* Vari�veis flags de controle para que as estruturas teste sejam inicializadas apenas quando necess�rias*/
int flag = 0;
int flag2 = 0;
/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void DestruirValor(void * pValor);

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


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
	/*		Fim da Ativa: Pedir Monte com uma sequ�ncia vazia	*/

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
			"Condicao de retorno errada ao pedir cartas para uma sequ�ncia vazia.");
	}
	/*		Fim da Ativa: Pedir Monte com uma sequ�ncia vazia	*/


	return TST_CondRetNaoConhec;

} /* Fim fun��o: TLIS &Testar Cinco Principais */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim fun��o: Destruir valor */


/********** Fim do m�dulo de implementa��o: TCP Teste Cinco Principais **********/
