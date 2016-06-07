/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Pilha de Cartas
*
*  Arquivo gerado:              PilhaDeCartas.c
*  Letras identificadoras:      PDCRT
*
*  Nome da base de software:    Jogo paciencia spider
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: Gabriel Maia, Felipe Holanda e Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   gff   13/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     O m�dulo Pilha de Cartas � utilizado para inicaliza��o do
*	  baralho, ele gera um baralho ordenado considerando o modo
*	  de jogo
*
***************************************************************************/

#include <string.h>
#include <stdio.h>

#ifdef _DEBUG
#include "CESPDIN.H"
#include "CONTA.H"
#endif

#include "Carta.h"
#include "Lista.h"

#include "PilhaDeCartas.h"

typedef struct PDCRT_PilhaCartas
{
	LIS_tppCabeca *	pCabecaPilha;
	int				numElem;

} PDCRT_tpPilhaCartas;

/***********************************************************************
*
*    Fun��o: PDCRT Criar Pilha
*
************************************************************************/

PDCRT_tpPilhaCartas * PDCRT_CriaPilha(void)
{
	#ifdef _DEBUG 
	char Tipo = 'k';
	#endif
	
	PDCRT_tpPilhaCartas * pilha;

	pilha = (PDCRT_tpPilhaCartas *)malloc(sizeof(PDCRT_tpPilhaCartas));
	if (pilha == NULL)
	{
		return NULL;
	}

	pilha->numElem = NULL;
	pilha->pCabecaPilha = LIS_CriaLista(CTA_DestroiCarta
	#ifdef _DEBUG
	, Tipo
	#endif
	);

#ifdef _DEBUG
	CED_MarcarEspacoAtivo(pilha);
#endif

	return pilha;
}/* Fim fun��o: Criar Pilha*/


/***********************************************************************
*
*    Fun��o: PDCRT Destruir Pilha
*
************************************************************************/

PDCRT_tpCondRet PDCRT_DestroiPilha(PDCRT_tpPilhaCartas * pilha)
{
	if (pilha == NULL)
	{
		return PDCRT_CondRetPilhaInexistente;
	}

	else if (LIS_AcessaListaIni(pilha->pCabecaPilha) != NULL)
	{
		LIS_EsvaziarLista(pilha->pCabecaPilha);
	}

	free(pilha->pCabecaPilha);
#ifdef _DEBUG
	CED_MarcarEspacoNaoAtivo(pilha);
#endif


	free(pilha);




	return PDCRT_CondRetOK;
}/* Fim fun��o: PDCRT Destruir Pilha*/


/***********************************************************************
*
*    Fun��o: PDCRT Push
*
************************************************************************/

void PDCRT_Push(PDCRT_tpPilhaCartas * pilha, Crt * carta)
{
	#ifdef _DEBUG
	char tipoElemento = 'k';
	#endif

	LIS_IrInicioLista(pilha->pCabecaPilha);

	LIS_InserirElementoAntes(pilha->pCabecaPilha, carta
	#ifdef _DEBUG
		, tipoElemento
	#endif
		);
} /* Fim fun��o: PDCRT Push */

/***********************************************************************
*
*    Fun��o: PDCRT Pop
*
************************************************************************/

Crt * PDCRT_Pop(PDCRT_tpPilhaCartas * pilha)
{
	Crt * carta, *temp;

	char * valor;
	char naipe;
	int estado;
	int situacao;
	
	#ifdef _DEBUG
	int i = 0;
	#endif

	LIS_IrInicioLista(pilha->pCabecaPilha);

	temp = (Crt *)LIS_ObterValor(pilha->pCabecaPilha);
	valor = CTA_AcessaValor(temp);
	naipe = CTA_AcessaNaipe(temp);
	estado = CTA_AcessaEstado(temp);
	situacao = CTA_AcessaSituacao(temp);

	carta = CTA_CriaCarta(valor, naipe, estado, situacao);

	LIS_ExcluirElemento(pilha->pCabecaPilha
	#ifdef _DEBUG
		, i
	#endif	
	);

	return carta;
} /* Fim fun��o: PDCRT Pop */

/***********************************************************************
*
*    Fun��o: PDCRT Acessar Topo
*
************************************************************************/

LIS_tppLista * PDCRT_AcessaTopo(PDCRT_tpPilhaCartas * pilha)
{
	
		return LIS_AcessaListaIni(pilha->pCabecaPilha);

}/* Fim fun��o: PDCRT Acessar Topo */

/***********************************************************************
*
*    Fun��o: PDCRT Acessar Cabe�a Pilha
*
************************************************************************/

LIS_tppCabeca *PDCRT_AcessaCabeca(PDCRT_tpPilhaCartas * pilha)
{
	return pilha->pCabecaPilha;
}/* Fim fun��o: PDCRT Acessar Cabe�a Pilha */
#ifdef _DEBUG

/***********************************************************************
*
*   Fun��o: PDCRT Verifica
*
*   Essa fun��o � do modo DEBUG e tem o objetivo de destruir as
*	assertivas estruturais do m�dulo Desenho com intuito de testar
*	poss�veis falhas/inconsist�ncias no tempo de execu��o.
*
***********************************************************************/
PDCRT_tpCondRet PDCRT_Verifica(int* numErros, PDCRT_tpPilhaCartas * pilha, int acao)
{
	LIS_tppCabeca * ListaTeste ;
	int erro = 0;
	int no = 0;
	ListaTeste = pilha->pCabecaPilha;
	
	*numErros = 0;

	do
	{
		no++;
		erro = LIS_VerificaAssertivaAnt(ListaTeste);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaPonteiroAnt");
			printf("\n Erro no ponteiro para N� predecessor no N� : %d \n", no);
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaPonteiroAnt_OK");
		} /* else */
		*numErros += erro;

		erro = LIS_VerificaAssertivaProx(ListaTeste);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaPonteiroProx");
			printf("\n Erro no ponteiro para N� sucessor no N� : %d \n", no);
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaPonteiroProx_OK");
		} /*else*/
		*numErros += erro;

		erro = LIS_VerificaAssertivaListaVazia(pilha->pCabecaPilha);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaVazia");
			printf("\nErro nas assertivas de uma lista vazia.\n");
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaVazia_OK");
		} /* else */
		*numErros += erro;

		erro = LIS_VerificaAssertivaListaElemUnico(pilha->pCabecaPilha);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaElemUnico");
			printf("\nErro nas assertivas de uma lista com elemento unico.\n");
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaElemUnico_OK");
		} /* else */
		*numErros += erro;

		erro = LIS_VerificaAssertivaListaPreenchida(pilha->pCabecaPilha);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaPreenchida");
			printf("\nErro nas assertivas de uma lista com mais 1 um elementos.\n");
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaPreenchida_OK");
		} /* else */
		*numErros += erro;

		erro = LIS_VerificaAssertivaTipoListaElementos(pilha->pCabecaPilha);
		if (erro > 0)
		{
			CNT_CONTAR("PDCRT_ErroAssertivaListaTipoListaElementos");
			printf("\nErro: Tipos de conteudo inconsistentes na lista.\n");
		} /* if */
		else
		{
			CNT_CONTAR("PDCRT_AssertivaListaTipoListaElementos_Ok");
		} /* else */
		*numErros += erro;

		LIS_AvancarElementoCorrente(ListaTeste, 1);
	} while (LIS_AcessaElementoCorrente(ListaTeste) != NULL) ; /* for */

 
	
}/* Fim fun��o: PDCRT Verifica */

/***********************************************************************
*
*   Fun��o: PDCRT Deturpar
*
*   Essa fun��o � do modo DEBUG e tem o objetivo de destruir as
*	assertivas estruturais do m�dulo Desenho com intuito de testar
*	poss�veis falhas/inconsist�ncias no tempo de execu��o.
*
***********************************************************************/

PDCRT_tpCondRet PDCRT_Deturpar(int caso, LIS_tppCabeca * CabecaTeste)
{
	LIS_tppLista * lixo;
	int valor_randomico = 97;
	LIS_tppLista * ListaTeste = LIS_AcessaListaIni(CabecaTeste);

	switch (caso)
	{
	case D_DESTROI_CORRENTE:
		LIS_ExcluirElemento( CabecaTeste, 1 );
		break;

	case D_NULL_SUCESSOR:
		LIS_AlteraPonteiroSucessor(ListaTeste , NULL);
		break;

	case D_NULL_PREDECESSOR:
		ListaTeste = LIS_AcessaListaFim(CabecaTeste);
		LIS_AlteraPonteiroPredecessor( ListaTeste , NULL);
		break;

	case D_LIXO_SUCESSOR:
		LIS_PreencheLixoSucessor(ListaTeste, &lixo);
		break;

	case D_LIXO_PREDECESSOR:
		ListaTeste = LIS_AcessaListaFim(CabecaTeste);
		LIS_AlteraPonteiroPredecessor(ListaTeste , &lixo);
		break;

	case D_NULL_CONTEUDO:
		LIS_AlteraPonteiroValor(ListaTeste);
		break;

	case D_NULL_CORRENTE:
		LIS_NuloCorrente(CabecaTeste);
		break;

	case D_ALTERA_TIPO:
		LIS_AlteraTipoElementoNo(CabecaTeste);
		break;

	case D_FREE_PARCIAL:
		LIS_FreeParcial(CabecaTeste);
		break;

	case D_NULL_ORIGEM:
		LIS_NuloOrigem(CabecaTeste);
		break;

	default:
		printf("Caso de deturpa��o inv�lido\n");
		break;
	}

	return PDCRT_CondRetOK;
}/* Fim fun��o: PDCRT Deturpa */

#endif 


/**************   Fim do m�dulo de implementa��o: Pilha de Cartas  *****************/