/***************************************************************************
*  $MCI M�dulo de implementa��o: TLIS Teste lista de s�mbolos
*
*  Arquivo gerado:              testaPilhaDeCartas.c
*  Letras identificadoras:      TPDCRT
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes de m�dulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: gff
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data        Observa��es
*      1.0    gff   24/mai/2015    Inicio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <stdlib.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"
#include	"CONTA.H"


#include	"Lista.h"
#include	"Carta.h"
#include	"PilhaDeCartas.h"

static const char CRIA_CMD[] = "=criarpilha";
static const char DESTROI_CMD[] = "=destruirpilha";
static const char PUSH_CMD[] = "=adicionar";
static const char POP_CMD[] = "=remover";
#ifdef _DEBUG
static const char DETURPA_CMD[] = "=deturpa";
static const char VERIFICA_CMD[] = "=verifica";

#endif

#define DIM_VALOR     3

PDCRT_tpPilhaCartas * PilhaTeste;
//LIS_tppCabeca * CabecaTeste = NULL;
Crt * CartaTeste = NULL;
int AcaoDeturpadora;


/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void DestruirValor(void * pValor);


/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TPDCRT &Testar Pilha De Cartas
*
*  $ED Descri��o da fun��o
*     Podem ser criadas at� 10 listas, identificadas pelos �ndices 0 a 10
*
*     Comandos dispon�veis:
*		
*		=criarpilha
*
*		=destruirpilha
*		
*		=adicionar
*
*		=remover
*
*	   Comandos dispon�veis em modo DEBUG:
*
*		=deturpar
*	
*		=verificar
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	PDCRT_tpCondRet CondRetObtido = PDCRT_CondRetOK;
	PDCRT_tpCondRet CondRetEsperada = PDCRT_CondRetCartaInexistente;
	/* inicializa para qualquer coisa */
	int	numLidos = -1,
		CondRetEsp = -1;

	TST_tpCondRet CondRet;

	char ValorDado[DIM_VALOR];
	char NaipeDado;
	char * pDado;

	int estado = -1;
	int situacao = -1;

	/* Testar Criar Pilha*/

	if (strcmp(ComandoTeste, CRIA_CMD) == 0)
	{

		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		PilhaTeste = PDCRT_CriaPilha();

		if (PilhaTeste != NULL)
		{
			CondRetObtido = PDCRT_CondRetOK;
		}
		else
		{
			CondRetObtido = PDCRT_CondRetFaltouMemoria;
		}

		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condi��o de retorno errada ao criar Pilha!");

	} /* fim ativa: Testar Criar Pilha */

	/* Testar Destruir Pilha */

	if (strcmp(ComandoTeste, DESTROI_CMD) == 0)
	{

		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PDCRT_DestroiPilha(PilhaTeste);

		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condi��o de retorno errada ao destruir pilha!");

	} /* fim ativa: Testar Destruir Pilha */

	/* Testar Push */

	else if (strcmp(ComandoTeste, PUSH_CMD) == 0)
	{

		numLidos = LER_LerParametros("sciii",
			 ValorDado, &NaipeDado, &estado, &situacao, &CondRetEsp);

		if (numLidos != 5)
		{
			return TST_CondRetParm;
		} /* if */

		pDado = (char *)malloc(strlen(ValorDado) + 1);

		if (pDado == NULL)
		{
			return TST_CondRetMemoria;
		} /* if */

		strcpy(pDado, ValorDado);

		CartaTeste = CTA_CriaCarta(pDado, NaipeDado, estado, situacao);

		if (CartaTeste == NULL)
		{
			CondRetObtido = PDCRT_CondRetFaltouMemoria;
		}


		else if (PilhaTeste == NULL)
		{
			CondRetObtido = PDCRT_CondRetPilhaInexistente;
		}

		else
		{
			PDCRT_Push(PilhaTeste, CartaTeste);
			CondRetObtido = PDCRT_CondRetOK;
		} /* if */

		free(pDado);
		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condi��o de retorno errada ao adicionar carta.");

	} /* fim ativa: Testar Push */


	/*  Testar Pop */
	else if (strcmp(ComandoTeste, POP_CMD) == 0)
	{

		numLidos = LER_LerParametros("i",
			&CondRetEsp);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */


		if (PDCRT_AcessaTopo(PilhaTeste) != NULL)
		{

			CartaTeste = PDCRT_Pop(PilhaTeste);
			if (CartaTeste == NULL)
			{
				CondRetObtido = PDCRT_CondRetCartaInexistente;
			}

			else {
				CondRetObtido = PDCRT_CondRetOK;
			}

		}
		else{
			CondRetObtido = PDCRT_CondRetPilhaVazia;
		}

		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condicao de retorno errada ao retirar carta!");

	} /* fim ativa: Testar Pop */

#ifdef _DEBUG
	/* Testar PDCRT Deturpa */

	else if (strcmp(ComandoTeste, DETURPA_CMD) == 0)
	{
		
		numLidos = LER_LerParametros("ii", &AcaoDeturpadora, &CondRetEsperada);
		if (numLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = PDCRT_Deturpar(AcaoDeturpadora, PDCRT_AcessaCabeca(PilhaTeste));

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"A contagem de erro n�o bate.");

	} /* fim ativa: Testar PDCRT Deturpa */

	/* Testar PDCRT Verifica */

	else if (strcmp(ComandoTeste, VERIFICA_CMD) == 0)
	{
		int numErrosEsperados;
		int numErrosOcorridos;

		numLidos = LER_LerParametros("i", &numErrosEsperados);
		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		PDCRT_Verifica(&numErrosOcorridos, PilhaTeste, AcaoDeturpadora);

		return TST_CompararInt(numErrosEsperados, numErrosOcorridos,
			"Erro na contagem de falhas.");

	} /* fim ativa: Testar PDCRT Verifica */
#endif

	return TST_CondRetNaoConhec;

} /* Fim fun��o: PDCRT &Testar Pilha de Cartas */



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
