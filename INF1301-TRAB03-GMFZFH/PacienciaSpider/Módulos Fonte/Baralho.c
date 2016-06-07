/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Baralho
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   gff   13/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     O m�dulo Baralho � usado para embaralhar uma lista,
*	  ela transfere uma Lista de Cartas para um vetor de Cartas
*	  e randomiza a mesma, inserindo na lista novamente ap�s
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
*    Fun��o: BAR Distribui Baralho
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
} /* Fim fun��o: BAR Distribui Baralho */

/***********************************************************************
*
*    Fun��o: BAR Cria Baralho
*
************************************************************************/

BAR_tpCondRet BAR_CriaBaralho( LIS_tppCabeca * cb, int modo )
{
	int i, j ;
	char val[3] ;
	Crt * carta ;

	/* Modo de jogo f�cil ( um naipe ) */
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
	/* Fim ativa: modo de jogo f�cil ( um naipe ) */

	/* Modo de jogo intermedi�rio ( dois naipes ) */			
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
	/* Fim ativa: Modo de jogo intermedi�rio ( dois naipes ) */

    /* Modo de jogo dif�cil( tr�s naipes ) */				
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
	/* Fim ativa: Modo de jogo dif�cil( tr�s naipes ) */	

	/* Modo de jogo muito dif�cil( quatro naipes ) */	
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
	/* Fim ativa: Modo de jogo muito dif�cil( quatro naipes ) */	

	else
	{
		return BAR_CondRetModoDeCriacaoInexistente ;
	} /* if */
	
	return BAR_CondRetOK ;
} /* Fim fun��o: BAR Cria Baralho */

/***********************************************************************
*
*	Fun��o: BAR Embaralhar
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
} /* Fim fun��o: BAR Embaralhar */

/********** Fim do m�dulo de defini��o: M�dulo Baralho **********/

