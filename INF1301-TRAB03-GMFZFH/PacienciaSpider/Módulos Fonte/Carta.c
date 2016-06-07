/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Carta
*
*  Arquivo gerado:              Carta.c
*  Letras identificadoras:      CTA
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
*     O m�dulo Cartas � usado para cria��o de uma carta e 
*	  manuten��o e acesso da mesma, al�m de fun��es auxiliares
*	  para conver��o de char naipe e valor para inteiros
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Carta.h"


/***********************************************************************
*
*  $TC Tipo de dados: CTA Descritor do n� de carta
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o de carta
*
***********************************************************************/

typedef struct carta
{
	char valor[3] ;
	/* Vari�vel alfanum�rica com valor da carta 
	*
	*$EED Assertivas estruturais
	*	Assume o valor de uma carta presente no baralho:
	*		A, 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K */

	char naipe ;
	/* Vari�vel para definir o na�pe a qual o valor pertence 
	*
	*$EED Assertivas estruturais
	*	C para Copas
	*	P para Paus
	*	O para Ouros
	*	E para Espadas */

	int estado ;
	/* Define o estado em que se encontra a carta
	*
	*$EED Assertivas estruturais
	*	0 se a face est� voltada para baixo
	*	1 se a face est� voltada para cima */

	int situacao ;
	/*Define a situa��o de uma carta
	*
	*$EED Assertivas estruturais
	*	0 se a carta se encontra bloqueada para movimenta-la
	*	1 se a carta se encontra desbloqueada para movimenta-la */

} Carta ;


/***********************************************************************
*
*	Fun��o: CTA Criar uma nova carta
*
***********************************************************************/

Carta * CTA_CriaCarta ( char valor[], char naipe, int estado, int situacao )
{
	Carta * nova_carta = ( Carta * )malloc( sizeof ( Carta ) ) ;

	if ( nova_carta == NULL )
	{
		printf( "Faltou memoria!" ) ;

		exit( 0 ) ;
	} /* if */

	strcpy( nova_carta->valor, valor ) ;
	nova_carta->naipe = naipe ;
	nova_carta->estado = estado ;
	nova_carta->situacao = situacao ; 

	return nova_carta ;
} /* Fim fun��o: CTA Criar uma nova carta */

/***********************************************************************
*
*	Fun��o: CTA Acessa valor de uma carta
*
***********************************************************************/

char * CTA_AcessaValor ( Carta * crt )
{
	if ( crt != NULL )
	{
		return crt->valor ;
	} /* if */
} /* Fim fun��o: CTA Acessa valor de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Acessa naipe de uma carta
*
***********************************************************************/

char CTA_AcessaNaipe ( Carta* crt )
{
	if ( crt != NULL )
	{
		return crt->naipe ;
	} /* if */
}/* Fim fun��o: Acessa naipe de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Acessa estado de uma carta
*
***********************************************************************/

int CTA_AcessaEstado ( Carta* crt )
{
	if ( crt != NULL )
	{
		return crt->estado ;
	} /* if */
}/* Fim fun��o: CTA Acessa estado de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Acessa situa��o de uma carta
*
***********************************************************************/

int CTA_AcessaSituacao ( Carta* crt )
{
	if ( crt != NULL )
	{
		return crt->situacao ;
	} /* if */
} /* Fim fun��o: CTA Acessa situa��o de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Verificar naipe de uma carta
*
***********************************************************************/

int CTA_VerificaNaipe( char naipe_desejado ) 
{
	switch ( naipe_desejado )
	{
	case 'C':
	case 'c':
		return 3 ;
		break ;
	case 'O':
	case 'o':
		return 4 ;
		break ;
	case 'P':
	case 'p':
		return 5 ;
		break;
	case 'E':
	case 'e':
		return 6 ;
		break ;
	default:
		printf("Naipe invalido, digite novamente.") ;
	} /* switch */
} /* Fim fun��o: CTA Verificar naipe de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Verificar valor de uma carta
*
***********************************************************************/

int CTA_VerificaValor( char * valor ) 
{
	if ( ( strcmp( valor, "A" ) == 0 ) || ( strcmp( valor, "a" ) == 0 ) )
	{
		return 0 ;
	} /* if */
	else if ( strcmp( valor, "2" ) == 0 )
	{
		return 1 ;
	} /* if */
	else if ( strcmp( valor, "3" ) == 0 )
	{
		return 2 ;
	} /* if */
	else if ( strcmp( valor, "4" ) == 0 )
	{
		return 3 ;
	} /* if */
	else if ( strcmp( valor, "5" ) == 0 )
	{
		return 4 ;
	} /* if */
	else if ( strcmp( valor, "6" ) == 0 )
	{
		return 5 ;
	} /* if */
	else if ( strcmp( valor, "7" ) == 0 )
	{
		return 6 ;
	} /* if */
	else if ( strcmp( valor, "8" ) == 0 )
	{
		return 7 ;
	} /* if */
	else if ( strcmp( valor, "9" ) == 0 )
	{
		return 8 ;
	} /* if */
	else if ( strcmp( valor, "10" ) == 0 )
	{
		return 9 ;
	} /* if */
	else if ( strcmp( valor, "J" ) == 0 || strcmp( valor, "j" ) == 0 )
	{
		return 10 ;
	} /* if */
	else if ( strcmp( valor, "Q" ) == 0 || strcmp( valor, "q" ) == 0 )
	{
		return 11 ;
	} /* if */
	else if ( strcmp( valor, "K" ) == 0 || strcmp( valor, "k" ) == 0 )
	{
		return 12 ;
	} /* if */
} /* Fim fun��o: CTA Verificar valor de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Converter valor de uma carta
*
***********************************************************************/

char * CTA_ConverteValor ( int num )
{
	char val[3] ;

	switch ( num ) 
	{
	case 0 :
		strcpy( val, "A" ) ;
		break ;
	case 1 :
		strcpy( val, "2" ) ;
		break ;
	case 2 :
		strcpy( val, "3" ) ;
		break ;
	case 3 :
		strcpy( val, "4" ) ;
		break ;
	case 4 :
		strcpy( val, "5" ) ;
		break ;
	case 5 :
		strcpy( val, "6" ) ;
		break ;
	case 6 :
		strcpy( val, "7" ) ;
		break ;
	case 7 :
		strcpy( val, "8" ) ;
		break ;
	case 8 :
		strcpy( val, "9" ) ;
		break ;
	case 9 :
		strcpy( val, "10" ) ;
		break ;
	case 10 :
		strcpy( val, "J" ) ;
		break ;
	case 11 :
		strcpy( val, "Q" ) ;
		break ;
	case 12 :
		strcpy( val, "K" ) ;
		break ;
	} /* switch */

	return val ;
} /* Fim fun��o: CTA Converter valor de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Alterar situa��o de uma carta
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraSituacao( Carta * crt )
{
	if ( crt != NULL )
	{
		if (crt->situacao == 0)
		{
			crt->situacao = 1 ;
			return CRT_CondRetOK ;
		} /* if */
		else
		{
			crt->situacao = 0 ;
			return CRT_CondRetOK ;
		} /* if */
	} /* if */

	return CRT_CondRetCartaVazia ;
} /* Fim fun��o: CTA Alterar situa��o de uma carta */

/***********************************************************************
*
*	Fun��o: CTA Alterar estado de uma carta
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraEstado( Carta * crt )
{
	if ( crt != NULL )
	{
		if ( crt->estado == 0 )
		{
			crt->estado = 1 ;
			return CRT_CondRetOK ;
		} /* if */
		else
		{
			crt->estado = 1 ;
			return CRT_CondRetOK ;
		} /* if */
	} /* if */

	return CRT_CondRetCartaVazia ;
} /* Fim fun��o: CTA Alterar estado de uma carta */

/********** Fim do m�dulo de defini��o: M�dulo Carta **********/