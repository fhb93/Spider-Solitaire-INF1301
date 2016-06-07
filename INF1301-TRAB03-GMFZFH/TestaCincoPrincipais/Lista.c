/***************************************************************************
*
*  $MCD Módulo de definição: Módulo tpLista
*
*  Arquivo gerado:              Lista.c
*  Letras identificadoras:      LIS
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
*     O módulo Lista é usado para a criação de Listas duplamente
*	  encadeadas com cabeça, além de conter funçoes de manipulação
*	  e acesso da mesma
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Lista.h"



/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de tpLista
*
*  $ED Descrição do tipo
*     Descreve a organização de uma lista duplamente encadeada
*
***********************************************************************/

typedef struct lista
{
	void * pValor;
	/* Ponteiro para o valor contido no elemento */

	struct lista * pAnt;
	/* Ponteiro para o elemento predecessor */

	struct lista * pProx;
	/* Ponteiro para o elemento sucessor */
} tpLista;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Cabeça
*
*  $ED Descrição do tipo
*     Descreve a organização de uma cabeça
*
***********************************************************************/

typedef struct cabeca
{
	tpLista * pOrigemLista;
	/* Ponteiro para a origem da lista */

	tpLista * pFimLista;
	/* Ponteiro para o final da lista */

	tpLista * pElemCorr;
	/* Ponteiro para o elemento corrente da lista */

	int numElem;
	/* Número de elementos da lista */

	void(*ExcluirValor) (void * pValor);
	/* Ponteiro para a função de destruição do valor contido em um elemento */
} tpCabeca;


/***********************************************************************
*
*  $FC Função: LIS Limpa a Cabeça da tpLista
*
***********************************************************************/

void LimparCabeca(tpCabeca * cb)
{
	cb->pOrigemLista = NULL;
	cb->pFimLista = NULL;
	cb->pElemCorr = NULL;
	cb->numElem = 0;
} /* Fim função: LIS Limpa a Cabeça da tpLista */

/***********************************************************************
*
*  $FC Função: LIS Cria Elemento
*
***********************************************************************/

tpLista * CriarElemento(tpCabeca * cb, void * pValor)
{
	tpLista * pElem = NULL;

	pElem = (tpLista *)malloc(sizeof(tpLista));
	if (pElem == NULL)
	{
		return NULL;
	} /* if */

	pElem->pValor = pValor;
	pElem->pAnt = NULL;
	pElem->pProx = NULL;

	cb->numElem++;

	return pElem;
} /* Fim função: LIS Cria Elemento */

/***********************************************************************
*
*	Função: LIS Libera Elemento da tpLista
*
***********************************************************************/

void LiberarElemento(tpCabeca * cb, tpLista * pElem)
{
	if ((cb->ExcluirValor != NULL) && (pElem->pValor != NULL))
	{
		cb->ExcluirValor(pElem->pValor);
	} /* if */

	free(pElem);

	cb->numElem--;
} /* Fim função: LIS Libera Elemento da tpLista */

/***********************************************************************
*
*	Função: LIS Criar lista
*
***********************************************************************/

tpCabeca * LIS_CriaLista(void(*ExcluirValor) (void * pDado))
{
	tpCabeca * novo = NULL;

	novo = (tpCabeca *)malloc(sizeof(tpCabeca));

	if (novo == NULL)
	{
		return NULL;
	} /* if */

	LimparCabeca(novo);

	novo->ExcluirValor = ExcluirValor;

	return novo;
} /* Fim função: LIS Criar lista */

/***********************************************************************
*
*	Função: LIS Destroi tpLista
*
***********************************************************************/

LIS_tpCondRet LIS_DestroiLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		LIS_EsvaziarLista(cb);

		free(cb);

		return LIS_CondRetOK;
	}

	return LIS_CondRetListaVazia;
} /* Fim função: LIS Destroi tpLista */

/***********************************************************************
*
*	Função: LIS Insere Elemento Antes
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes(tpCabeca * cb, void * pValor)
{
	tpLista * pElem = NULL;

	if (cb != NULL)
		/* Criar elemento a inerir antes */

		pElem = CriarElemento(cb, pValor);

	if (pElem == NULL)
	{
		return LIS_CondRetFaltouMemoria;
	} /* if */

	/* Encadear o elemento antes do elemento corrente */

	if (cb->pElemCorr == NULL)
	{
		cb->pOrigemLista = pElem;
		cb->pFimLista = pElem;
	}
	else
	{
		if (cb->pElemCorr->pAnt != NULL)
		{
			pElem->pAnt = cb->pElemCorr->pAnt;
			cb->pElemCorr->pAnt->pProx = pElem;
		}
		else
		{
			cb->pOrigemLista = pElem;
		} /* if */

		pElem->pProx = cb->pElemCorr;
		cb->pElemCorr->pAnt = pElem;
	} /* if */

	cb->pElemCorr = pElem;

	return LIS_CondRetOK;
} /* Fim função: LIS Insere Elemento Antes */

/***********************************************************************
*
*	Função: LIS Insere Elemento Após
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoApos(tpCabeca * cb, void * pValor)
{
	tpLista * pElem = NULL;

	if (cb != NULL)
	{
		/* Criar elemento a inserir após */

		pElem = CriarElemento(cb, pValor);
		if (pElem == NULL)
		{
			return LIS_CondRetFaltouMemoria;
		} /* if */

		/* Encadear o elemento após o elemento */

		if (cb->pElemCorr == NULL)
		{
			cb->pOrigemLista = pElem;
			cb->pFimLista = pElem;
		}
		else
		{
			if (cb->pElemCorr->pProx != NULL)
			{
				pElem->pProx = cb->pElemCorr->pProx;
				cb->pElemCorr->pProx->pAnt = pElem;
			}
			else
			{
				cb->pFimLista = pElem;
			} /* if */

			pElem->pAnt = cb->pElemCorr;
			cb->pElemCorr->pProx = pElem;

		} /* if */

		cb->pElemCorr = pElem;

		return LIS_CondRetOK;
	}
} /* Fim função: LIS Insere Elemento Após */

/***********************************************************************
*
*	Função: LIS Exclui Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento(tpCabeca * cb)
{
	tpLista * pElem = NULL;

	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return LIS_CondRetListaVazia;
		} /* if */

		pElem = cb->pElemCorr;

		/* Desencadeia à esquerda */

		if (pElem->pAnt != NULL)
		{
			pElem->pAnt->pProx = pElem->pProx;
			cb->pElemCorr = pElem->pAnt;
		} /* if */
		else
		{
			cb->pElemCorr = pElem->pProx;
			cb->pOrigemLista = cb->pElemCorr;
		} /* if */

		/* Desencadeia à direita */

		if (pElem->pProx != NULL)
		{
			pElem->pProx->pAnt = pElem->pAnt;
		} /* if */
		else
		{
			cb->pFimLista = pElem->pAnt;
		} /* if */

		LiberarElemento(cb, pElem);

		return LIS_CondRetOK;
	}
} /* Fim função: LIS Exclui Elemento */

/***********************************************************************
*
*	Função: LIS Obtém Valor Contido no Elemento
*
***********************************************************************/

void * LIS_ObterValor(tpCabeca * cb)
{
	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return NULL;
		} /* if */

		return cb->pElemCorr->pValor;
	} /* if */
} /* Fim função: LIS Obtém Valor Contido no Elemento */

/***********************************************************************
*
*	Função: LIS Ir para o Elemento Incial
*
***********************************************************************/

void LIS_IrInicioLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		cb->pElemCorr = cb->pOrigemLista;
	} /* if */
} /* Fim função: LIS Ir para o Elemento Incial */

/***********************************************************************
*
*	Função: LIS Ir para o Elemento Final
*
***********************************************************************/

void LIS_IrFinalLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		cb->pElemCorr = cb->pFimLista;
	} /* if */
} /* Fim função: LIS Ir para o Elemento Final */

/***********************************************************************
*
*	Função: LIS Avaçar Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente(tpCabeca * cb, int numElem)
{
	int i;

	tpLista * pElem = NULL;

	if (cb != NULL)
	{
		/* Tratar lista vazia */

		if (cb->pElemCorr == NULL)
		{

			return LIS_CondRetListaVazia;

		} /* fim ativa: Tratar lista vazia */

		/* Tratar avançar para frente */

		if (numElem > 0)
		{
			pElem = cb->pElemCorr;

			for (i = numElem; i > 0; i--)
			{
				if (pElem == NULL)
				{
					break;
				} /* if */
				pElem = pElem->pProx;
			} /* for */

			if (pElem != NULL)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */

			cb->pElemCorr = cb->pFimLista;
			return LIS_CondRetFimLista;

		} /* fim ativa: Tratar avançar para frente */

		/* Tratar avançar para trás */

		else if (numElem < 0)
		{

			pElem = cb->pElemCorr;
			for (i = numElem; i < 0; i++)
			{
				if (pElem == NULL)
				{
					break;
				} /* if */
				pElem = pElem->pAnt;
			} /* for */

			if (pElem != NULL)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */

			cb->pElemCorr = cb->pOrigemLista;
			return LIS_CondRetFimLista;

		} /* fim ativa: Tratar avançar para trás */

		/* Tratar não avançar */

		return LIS_CondRetOK;
	} /* if */
} /* Fim função: LIS Avaçar Elemento */

/***********************************************************************
*
*	Função: LIS Procura Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor(tpCabeca * cb, void * pValor, int (Compara)(void * pDado, void * pCorrente))
{
	tpLista * pElem = NULL;

	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return LIS_CondRetListaVazia;
		} /* if */

		for (pElem = cb->pElemCorr;
			pElem != NULL;
			pElem = pElem->pProx)
		{
			if (Compara(pElem->pValor, pValor) == 0)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */
		} /* for */

		return LIS_CondRetNaoAchou;
	} /* if */

	return LIS_CondRetListaInexistente;
} /* Fim função: LIS Procura Elemento */

/***********************************************************************
*
*	Função: LIS Acessa o Início da tpLista
*
***********************************************************************/

tpLista * LIS_AcessaListaIni(tpCabeca * cb)
{
	if (cb != NULL)
	{
		return cb->pOrigemLista;
	} /* if */
} /* Fim função: LIS Acessa o Início da Inicio */

/***********************************************************************
*
*	Função: LIS Acessa o Início da Fim
*
***********************************************************************/

tpLista * LIS_AcessaListaFim(tpCabeca * cb)
{
	if (cb != NULL)
	{
		return cb->pFimLista;
	} /* if */
} /* Fim função: LIS Acessa o Início da Fim */

/***********************************************************************
*
*	Função: LIS Aponta para Próximo
*
***********************************************************************/

tpLista * LIS_Proximo(tpLista * lst)
{
	if (lst != NULL)
	{
		return lst->pProx;
	} /* if */
} /* Fim função: LIS Aponta para Próximo */

/***********************************************************************
*
*	Função: LIS Aponta para Anterior
*
***********************************************************************/

tpLista * LIS_Anterior(tpLista * lst)
{
	if (lst != NULL)
	{
		return lst->pAnt;
	} /* if */
} /* Fim função: LIS Aponta para Anterior */

/***********************************************************************
*
*	Função: LIS Acessa Struct
*
***********************************************************************/

void * LIS_AcessaStruct(tpLista * lst)
{
	if (lst != NULL)
	{
		return lst->pValor;
	} /* if */
} /* Fim função: LIS Acessa Struct */

/***********************************************************************
*
*	Função: LIS Acessa Número de Elementos
*
***********************************************************************/

int LIS_AcessaNumElem(tpCabeca * cb)
{
	return cb->numElem;
} /* Fim função: LIS Acessa Número de Elementos */

/***************************************************************************
*
*  Função: LIS  &Esvaziar lista
*  ****/

void  LIS_EsvaziarLista(tpCabeca * cb)
{

	tpLista * pElem = NULL;
	tpLista * pProx;

	if (cb != NULL)
	{

		pElem = cb->pOrigemLista;
		while (pElem != NULL)
		{
			pProx = pElem->pProx;
			LiberarElemento(cb, pElem);
			pElem = pProx;
		} /* while */

		LimparCabeca(cb);
	}

} /* Fim função: LIS  &Esvaziar lista */

/********** Fim do módulo de definição: Módulo tpLista **********/