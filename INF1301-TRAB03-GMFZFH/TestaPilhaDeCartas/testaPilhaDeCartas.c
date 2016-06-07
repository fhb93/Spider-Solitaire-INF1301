/***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:              testaPilhaDeCartas.c
*  Letras identificadoras:      TPDCRT
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: gff
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data        Observações
*      1.0    gff   24/mai/2015    Inicio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include	"Lista.h"
#include	"Carta.h"
#include	"PilhaDeCartas.h"


static const char PUSH_CMD[] = "=adicionar"; 
static const char POP_CMD[] = "=remover"; 


#define DIM_VALOR     3


LIS_tppCabeca * CabecaTeste = NULL;
Crt * CartaTeste = NULL ;


/***** Protótipos das funções encapuladas no módulo *****/

static void DestruirValor(void * pValor);


/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TPDCRT &Testar Pilha De Cartas
*
*  $ED Descrição da função
*     Podem ser criadas até 10 listas, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*		=adicionar
*
*		=remover
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

	
	/* Testar Push */

	if (strcmp(ComandoTeste, PUSH_CMD) == 0)
	{

		numLidos = LER_LerParametros("iscii",
			&CondRetEsp, ValorDado, &NaipeDado, &estado, &situacao);    

		if (numLidos != 5)
		{
			return TST_CondRetParm;
		} /* if */

		if (CabecaTeste == NULL)
		{
			CabecaTeste = LIS_CriaLista(DestruirValor);
		}
		
		pDado = (char *)malloc(strlen(ValorDado) + 1);

		if (pDado == NULL)
		{
			return TST_CondRetMemoria;
		} /* if */

		strcpy(pDado, ValorDado);

		CartaTeste = CTA_CriaCarta(pDado, NaipeDado, estado, situacao);
		
		if (CartaTeste == NULL)
		{
			CondRetObtido = TST_CondRetMemoria;
		}


		else if (CabecaTeste == NULL)
		{
			CondRetObtido = PDCRT_CondRetBaralhoInexistente;
		}

		else
		{
			PDCRT_Push(CabecaTeste, CartaTeste);
			CondRetObtido = PDCRT_CondRetOK;
		} /* if */


		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condição de retorno errada ao mover adicionar carta."); 

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


		if (LIS_AcessaListaIni(CabecaTeste) == NULL)
		{
			CondRetObtido = PDCRT_CondRetPilhaVazia ;
		}

		else
		{
			CartaTeste = PDCRT_Pop(CabecaTeste);
			if (CartaTeste == NULL)
			{
				CondRetObtido = PDCRT_CondRetCartaInexistente;
			}

			else {
				CondRetObtido = PDCRT_CondRetOK;
			}
		}


		return TST_CompararInt(CondRetEsp, CondRetObtido,
			"Condicao de retorno errada ao inserir antes.");
		
	} /* fim ativa: Testar Pop */

	return TST_CondRetNaoConhec;

} /* Fim função: PDCRT &Testar Pilha de Cartas */



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
