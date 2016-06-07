/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Pilha de Cartas
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     O módulo Pilha de Cartas é utilizado para inicalização do
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
*    Função: PDCRT Criar Pilha
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
}/* Fim função: Criar Pilha*/


/***********************************************************************
*
*    Função: PDCRT Destruir Pilha
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
}/* Fim função: PDCRT Destruir Pilha*/


/***********************************************************************
*
*    Função: PDCRT Push
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
} /* Fim função: PDCRT Push */

/***********************************************************************
*
*    Função: PDCRT Pop
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
} /* Fim função: PDCRT Pop */

/***********************************************************************
*
*    Função: PDCRT Acessar Topo
*
************************************************************************/

LIS_tppLista * PDCRT_AcessaTopo(PDCRT_tpPilhaCartas * pilha)
{
	
		return LIS_AcessaListaIni(pilha->pCabecaPilha);

}/* Fim função: PDCRT Acessar Topo */

/***********************************************************************
*
*    Função: PDCRT Acessar Cabeça Pilha
*
************************************************************************/

LIS_tppCabeca *PDCRT_AcessaCabeca(PDCRT_tpPilhaCartas * pilha)
{
	return pilha->pCabecaPilha;
}/* Fim função: PDCRT Acessar Cabeça Pilha */
#ifdef _DEBUG

/***********************************************************************
*
*   Função: PDCRT Verifica
*
*   Essa função é do modo DEBUG e tem o objetivo de destruir as
*	assertivas estruturais do módulo Desenho com intuito de testar
*	possíveis falhas/inconsistências no tempo de execução.
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
			printf("\n Erro no ponteiro para Nó predecessor no Nó : %d \n", no);
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
			printf("\n Erro no ponteiro para Nó sucessor no Nó : %d \n", no);
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

 
	
}/* Fim função: PDCRT Verifica */

/***********************************************************************
*
*   Função: PDCRT Deturpar
*
*   Essa função é do modo DEBUG e tem o objetivo de destruir as
*	assertivas estruturais do módulo Desenho com intuito de testar
*	possíveis falhas/inconsistências no tempo de execução.
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
		printf("Caso de deturpação inválido\n");
		break;
	}

	return PDCRT_CondRetOK;
}/* Fim função: PDCRT Deturpa */

#endif 


/**************   Fim do módulo de implementação: Pilha de Cartas  *****************/