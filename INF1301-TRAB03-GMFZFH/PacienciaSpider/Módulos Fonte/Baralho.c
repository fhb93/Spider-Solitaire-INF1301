/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Baralho
*
*  Arquivo gerado:              Baralho.c
*  Letras identificadoras:      BAR
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
*     O módulo Baralho é usado para embaralhar uma lista,
*	  ela transfere uma Lista de Cartas para um vetor de Cartas
*	  e randomiza a mesma, inserindo na lista novamente após
*	  randomizar
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#include "Carta.h"
#include "PilhaDeCartas.h"
#include "Lista.h"
#include "Baralho.h"

/***********************************************************************
*
*    Função: BAR Distribui Baralho
*
************************************************************************/

BAR_tpCondRet BAR_DistribuiBaralho(LIS_tppCabeca * baralho, LIS_tppCabeca * cb, int NumCartas)
{
	int i;
	if (baralho != NULL)
	{
		if (LIS_AcessaListaIni(baralho) != NULL){
			for (i = 0; i < NumCartas; i++)
			{
				PDCRT_Push(cb, PDCRT_Pop(baralho));
			} /* for */

			return BAR_CondRetOK;
		} /* if */

		return BAR_CondRetBaralhoVazio;
	} /* if */

	return BAR_CondRetBaralhoInexistente;
} /* Fim função: BAR Distribui Baralho */

/***********************************************************************
*
*    Função: BAR Cria Baralho
*
************************************************************************/

BAR_tpCondRet BAR_CriaBaralho( LIS_tppCabeca * cb, int modo )
{
	int i, j ;
	char val[3] ;
	Crt * carta ;

	/* Modo de jogo fácil ( um naipe ) */
	if ( modo == 1 )
	{
		for( i = 0 ; i < 8 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 6, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */
	} /* if */
	/* Fim ativa: modo de jogo fácil ( um naipe ) */

	/* Modo de jogo intermediário ( dois naipes ) */			
	else if ( modo == 2 )
	{
		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 6, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */

		for( i = 0 ; i < 4 ; i++ )
		{
			for( j = 0; j < 13; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 3, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */
	} /* if */
	/* Fim ativa: Modo de jogo intermediário ( dois naipes ) */

    /* Modo de jogo difícil( três naipes ) */				
	else if ( modo == 3 )
	{
		for( i = 0 ; i < 3 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 6, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */

		for( i = 0 ; i < 3 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 3, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */
 
		for( i = 0 ; i < 2 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 5, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */
	} /* if */
	/* Fim ativa: Modo de jogo difícil( três naipes ) */	

	/* Modo de jogo muito difícil( quatro naipes ) */	
	else if ( modo == 4 )
	{
		for( i = 0 ; i < 2 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 5, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */

		for( i = 0 ; i < 2 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 3, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */

		for( i = 0 ; i < 2 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 4, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */

		for( i = 0 ; i < 2 ; i++ )
		{
			for( j = 0 ; j < 13 ; j++ )
			{
				strcpy(val, CTA_ConverteValor( j )) ;
				carta = CTA_CriaCarta( val, 6, 0, 0 ) ;
				PDCRT_Push( cb, carta ) ;
			} /* for */
		} /* for */
	} /* if */
	/* Fim ativa: Modo de jogo muito difícil( quatro naipes ) */	

	else
	{
		return BAR_CondRetModoDeCriacaoInexistente ;
	} /* if */
	
	return BAR_CondRetOK ;
} /* Fim função: BAR Cria Baralho */

/***********************************************************************
*
*	Função: BAR Embaralhar
*
***********************************************************************/

BAR_tpCondRet BAR_Embaralhar( LIS_tppCabeca * cb )
{
	int i = 0 ;

	Crt * vCrt[104] ;
	Crt * teste ;
	LIS_tppLista * temp ;

	if ( LIS_AcessaListaIni( cb ) == NULL )
	{
		return BAR_CondRetBaralhoInexistente ;
	} /* if */

	srand( time ( NULL ) ) ;

	for ( temp = LIS_AcessaListaIni( cb ) ; temp != NULL ; temp = LIS_AcessaListaIni( cb ) )
	{
		vCrt[i] = PDCRT_Pop( cb ) ;
		
		i++ ;
	} /* for */

	for ( i = 0 ; i < 104 ; i++ )
	{
		int r = rand() % 104 ;

		Crt * temp = vCrt[i] ;
		vCrt[i] = vCrt[r] ;
		vCrt[r] = temp ;
	}  /* for */
	
	for( i = 0 ; i < 104 ; i++ )
	{
		PDCRT_Push( cb, vCrt[i] ) ;
	}  /* for */
	
	return BAR_CondRetOK ;
} /* Fim função: BAR Embaralhar */

/********** Fim do módulo de definição: Módulo Baralho **********/

