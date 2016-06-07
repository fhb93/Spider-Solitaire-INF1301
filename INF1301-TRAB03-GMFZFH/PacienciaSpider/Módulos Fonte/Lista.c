/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo tpLista
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   gff   13/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     O m�dulo Lista � usado para a cria��o de Listas duplamente
*	  encadeadas com cabe�a, al�m de conter fun�oes de manipula��o
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
*  $ED Descri��o do tipo
*     Descreve a organiza��o de uma lista duplamente encadeada
*
***********************************************************************/

typedef struct lista 
{
	void * pValor ;
	/* Ponteiro para o valor contido no elemento */

	struct lista * pAnt ;
	/* Ponteiro para o elemento predecessor */

	struct lista * pProx ;
	/* Ponteiro para o elemento sucessor */
} tpLista ;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Cabe�a
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o de uma cabe�a
*
***********************************************************************/

typedef struct cabeca
{
	tpLista * pOrigemLista ;
	/* Ponteiro para a origem da lista */

	tpLista * pFimLista ;
	/* Ponteiro para o final da lista */

	tpLista * pElemCorr ;
	/* Ponteiro para o elemento corrente da lista */

	int numElem ;
	/* N�mero de elementos da lista */

	void ( * ExcluirValor ) ( void * pValor ) ;
	/* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */
} tpCabeca ;


/***********************************************************************
*
*  $FC Fun��o: LIS Limpa a Cabe�a da tpLista
*
***********************************************************************/

void LimparCabeca( tpCabeca * cb )
{
	cb->pOrigemLista = NULL ;
	cb->pFimLista = NULL ;
	cb->pElemCorr = NULL ;
	cb->numElem   = 0 ;
} /* Fim fun��o: LIS Limpa a Cabe�a da tpLista */

/***********************************************************************
*
*  $FC Fun��o: LIS Cria Elemento
*
***********************************************************************/

tpLista * CriarElemento( tpCabeca * cb , void * pValor  )
{
	tpLista * pElem ;

	pElem = ( tpLista * )malloc( sizeof( tpLista ) ) ;
	if ( pElem == NULL )
	{
		return NULL ;
	} /* if */

	pElem->pValor = pValor ;
	pElem->pAnt   = NULL  ;
	pElem->pProx  = NULL  ;

	cb->numElem ++ ;

	return pElem ;
} /* Fim fun��o: LIS Cria Elemento */

/***********************************************************************
*
*	Fun��o: LIS Libera Elemento da tpLista
*
***********************************************************************/

void LiberarElemento( tpCabeca * cb , tpLista * pElem   )
{
	if ( ( cb->ExcluirValor != NULL ) && ( pElem->pValor != NULL ) )
	{
		cb->ExcluirValor( pElem->pValor ) ;
	} /* if */

	free( pElem ) ;

	cb->numElem-- ;
} /* Fim fun��o: LIS Libera Elemento da tpLista */

/***********************************************************************
*
*	Fun��o: LIS Criar lista
*
***********************************************************************/

tpCabeca * LIS_CriaLista( void ( * ExcluirValor ) ( void * pDado ) )
{
	tpCabeca * novo = NULL ;

	novo = ( tpCabeca * )malloc( sizeof( tpCabeca ) ) ;

	if ( novo == NULL )
	{
		return NULL ;
	} /* if */

	LimparCabeca( novo ) ;

	novo->ExcluirValor = ExcluirValor ;

	return novo ;
} /* Fim fun��o: LIS Criar lista */

/***********************************************************************
*
*	Fun��o: LIS Destroi tpLista
*
***********************************************************************/

LIS_tpCondRet LIS_DestroiLista( tpCabeca * cb )
{
	if ( cb != NULL ) 
	{
		LIS_EsvaziarLista( cb ) ;

		free( cb ) ;

		return LIS_CondRetOK ;
	} /* if */

	return LIS_CondRetListaVazia ;
} /* Fim fun��o: LIS Destroi tpLista */

/***********************************************************************
*
*	Fun��o: LIS Insere Elemento Antes
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes( tpCabeca * cb , void * pValor )
{
	tpLista * pElem ;

	if ( cb != NULL )
		/* Criar elemento a inerir antes */

		pElem = CriarElemento( cb , pValor ) ;

	if ( pElem == NULL )
	{
		return LIS_CondRetFaltouMemoria ;
	} /* if */

	/* Encadear o elemento antes do elemento corrente */

	if ( cb->pElemCorr == NULL )
	{
		cb->pOrigemLista = pElem ;
		cb->pFimLista = pElem ;
	} /* if */
	else
	{
		if ( cb->pElemCorr->pAnt != NULL )
		{
			pElem->pAnt  = cb->pElemCorr->pAnt ;
			cb->pElemCorr->pAnt->pProx = pElem ;
		} /* if */
		else
		{
			cb->pOrigemLista = pElem ;
		} /* if */

		pElem->pProx = cb->pElemCorr ;
		cb->pElemCorr->pAnt = pElem ;
	} /* if */

	cb->pElemCorr = pElem ;

	return LIS_CondRetOK ;
} /* Fim fun��o: LIS Insere Elemento Antes */

/***********************************************************************
*
*	Fun��o: LIS Insere Elemento Ap�s
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoApos( tpCabeca * cb ,void * pValor )
{
	tpLista * pElem ;

	if ( cb != NULL )
	{
		/* Criar elemento a inerir ap�s */

		pElem = CriarElemento( cb , pValor ) ;

		if ( pElem == NULL )
		{
			return LIS_CondRetFaltouMemoria ;
		} /* if */

		/* Encadear o elemento ap�s o elemento */

		if ( cb->pElemCorr == NULL )
		{
			cb->pOrigemLista = pElem ;
			cb->pFimLista = pElem ;
		} /* if */ 
		else
		{
			if ( cb->pElemCorr->pProx != NULL )
			{
				pElem->pProx  = cb->pElemCorr->pProx ;
				cb->pElemCorr->pProx->pAnt = pElem ;
			} /* if */ 
			else
			{
				cb->pFimLista = pElem ;
			} /* if */

			pElem->pAnt = cb->pElemCorr ;
			cb->pElemCorr->pProx = pElem ;

		} /* if */

		cb->pElemCorr = pElem ;

		return LIS_CondRetOK ;
	}
} /* Fim fun��o: LIS Insere Elemento Ap�s */

/***********************************************************************
*
*	Fun��o: LIS Exclui Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento( tpCabeca * cb )
{
	tpLista * pElem ;

	if ( cb != NULL )
	{
		if ( cb->pElemCorr == NULL )
		{
			return LIS_CondRetListaVazia ;
		} /* if */

		pElem = cb->pElemCorr ;

		/* Desencadeia � esquerda */

		if ( pElem->pAnt != NULL )
		{
			pElem->pAnt->pProx   = pElem->pProx ;
			cb->pElemCorr    = pElem->pAnt ;
		} /* if */
		else
		{
			cb->pElemCorr    = pElem->pProx ;
			cb->pOrigemLista = cb->pElemCorr ;
		} /* if */

		/* Desencadeia � direita */

		if ( pElem->pProx != NULL )
		{
			pElem->pProx->pAnt = pElem->pAnt ;
		} /* if */
		else
		{
			cb->pFimLista = pElem->pAnt ;
		} /* if */

		LiberarElemento( cb , pElem ) ;

		return LIS_CondRetOK ;
	}
} /* Fim fun��o: LIS Exclui Elemento */

/***********************************************************************
*
*	Fun��o: LIS Obt�m Valor Contido no Elemento
*
***********************************************************************/

void * LIS_ObterValor( tpCabeca * cb )
{
	if ( cb != NULL )
	{
		if ( cb->pElemCorr == NULL )
		{
			return NULL ;
		} /* if */

		return cb->pElemCorr->pValor ;
	} /* if */
} /* Fim fun��o: LIS Obt�m Valor Contido no Elemento */

/***********************************************************************
*
*	Fun��o: LIS Ir para o Elemento Incial
*
***********************************************************************/

void LIS_IrInicioLista( tpCabeca * cb )
{
	if ( cb != NULL )
	{
		cb->pElemCorr = cb->pOrigemLista ;
	} /* if */
} /* Fim fun��o: LIS Ir para o Elemento Incial */

/***********************************************************************
*
*	Fun��o: LIS Ir para o Elemento Final
*
***********************************************************************/

void LIS_IrFinalLista( tpCabeca * cb )
{
	if ( cb != NULL )
	{
		cb->pElemCorr = cb->pFimLista ;
	} /* if */
} /* Fim fun��o: LIS Ir para o Elemento Final */

/***********************************************************************
*
*	Fun��o: LIS Ava�ar Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente( tpCabeca * cb , int numElem )
{
	int i ;

	tpLista * pElem ;

	if ( cb != NULL )
	{
		/* Tratar lista vazia */

		if ( cb->pElemCorr == NULL )
		{

			return LIS_CondRetListaVazia ;

		} /* fim ativa: Tratar lista vazia */

		/* Tratar avan�ar para frente */

		if ( numElem > 0 )
		{
			pElem = cb->pElemCorr ;

			for( i = numElem ; i > 0 ; i-- )
			{
				if ( pElem == NULL )
				{
					break ;
				} /* if */
				pElem = pElem->pProx ;
			} /* for */

			if ( pElem != NULL )
			{
				cb->pElemCorr = pElem ;
				return LIS_CondRetOK ;
			} /* if */

			cb->pElemCorr = cb->pFimLista ;
			return LIS_CondRetFimLista ;

		} /* fim ativa: Tratar avan�ar para frente */

		/* Tratar avan�ar para tr�s */

		else if ( numElem < 0 )
		{

			pElem = cb->pElemCorr ;
			for( i = numElem ; i < 0 ; i++ )
			{
				if ( pElem == NULL )
				{
					break ;
				} /* if */
				pElem    = pElem->pAnt ;
			} /* for */

			if ( pElem != NULL )
			{
				cb->pElemCorr = pElem ;
				return LIS_CondRetOK ;
			} /* if */

			cb->pElemCorr = cb->pOrigemLista ;
			return LIS_CondRetFimLista ;

		} /* fim ativa: Tratar avan�ar para tr�s */

		/* Tratar n�o avan�ar */

		return LIS_CondRetOK ;
	} /* if */
} /* Fim fun��o: LIS Ava�ar Elemento */

/***********************************************************************
*
*	Fun��o: LIS Procura Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor( tpCabeca * cb , void * pValor )
{
	tpLista * pElem ;

	if ( cb != NULL )
	{
		if ( cb->pElemCorr == NULL )
		{
			return LIS_CondRetListaVazia ;
		} /* if */

		for ( pElem  = cb->pElemCorr ;
			pElem != NULL ;
			pElem  = pElem->pProx )
		{
			if ( pElem->pValor == pValor )
			{
				cb->pElemCorr = pElem ;
				return LIS_CondRetOK ;
			} /* if */
		} /* for */

		return LIS_CondRetNaoAchou ;
	} /* if */

	return LIS_CondRetListaVazia ;
} /* Fim fun��o: LIS Procura Elemento */

/***********************************************************************
*
*	Fun��o: LIS Acessa o In�cio da tpLista
*
***********************************************************************/

tpLista * LIS_AcessaListaIni( tpCabeca * cb )
{
	if ( cb != NULL )
	{
		return cb->pOrigemLista ;
	} /* if */
} /* Fim fun��o: LIS Acessa o In�cio da Inicio */

/***********************************************************************
*
*	Fun��o: LIS Acessa o In�cio da Fim
*
***********************************************************************/

tpLista * LIS_AcessaListaFim( tpCabeca * cb )
{
	if ( cb != NULL )
	{
		return cb->pFimLista ;
	} /* if */
} /* Fim fun��o: LIS Acessa o In�cio da Fim */

/***********************************************************************
*
*	Fun��o: LIS Aponta para Pr�ximo
*
***********************************************************************/

tpLista * LIS_Proximo( tpLista * lst )
{
	if ( lst != NULL )
	{
		return lst->pProx;
	} /* if */
} /* Fim fun��o: LIS Aponta para Pr�ximo */

/***********************************************************************
*
*	Fun��o: LIS Aponta para Anterior
*
***********************************************************************/

tpLista * LIS_Anterior( tpLista * lst )
{
	if ( lst != NULL )
	{
		return lst->pAnt;
	} /* if */
} /* Fim fun��o: LIS Aponta para Anterior */

/***********************************************************************
*
*	Fun��o: LIS Acessa Struct
*
***********************************************************************/

void * LIS_AcessaStruct( tpLista * lst )
{
	if ( lst != NULL )
	{
		return lst->pValor ;
	} /* if */
} /* Fim fun��o: LIS Acessa Struct */

/***********************************************************************
*
*	Fun��o: LIS Acessa Numero de Elementos
*
***********************************************************************/

int LIS_AcessaNumElem( tpCabeca * cb )
{
	return cb->numElem ;
} /* Fim fun��o: LIS Acessa Numero de Elementos */

/***********************************************************************
*
*	Fun��o: LIS Esvaziar Lista
*
***********************************************************************/

void LIS_EsvaziarLista( tpCabeca * lst )
{

	tpLista * pElem ;
	tpLista * pProx ;

	if( lst != NULL ) 
	{

		pElem = lst->pOrigemLista ;
		while ( pElem != NULL )
		{
			pProx = pElem->pProx ;
			LiberarElemento( lst , pElem ) ;
			pElem = pProx ;
		} /* while */

		LimparCabeca( lst ) ;
	}

} /* Fim fun��o: LIS Esvaziar lista */

/********** Fim do m�dulo de defini��o: M�dulo tpLista **********/