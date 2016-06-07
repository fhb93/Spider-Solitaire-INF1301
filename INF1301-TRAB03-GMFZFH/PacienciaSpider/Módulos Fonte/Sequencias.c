/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Sequências
*
*  Arquivo gerado:              Sequencias.c
*  Letras identificadoras:      SEQ
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
*     O módulo Sequências é usado para mover cartas de uma
*	  sequência fonte para uma destino, além de imprimir as
*	  dez sequências do jogo
*
***************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#include "Lista.h"
#include "Carta.h"
#include "Sequencias.h"
#include "PilhaDeCartas.h"



/***********************************************************************
*
*	Função: SEQ Retira Cartas
*
***********************************************************************/

Crt ** SEQ_RetiraCartas( LIS_tppCabeca * cb , char valor[], char naipe, int * contador )
{
	int i ;

	char ComparaValor[3], ComparaNaipe, val[3] ;
	int ComparaSituacao, ComparaEstado ;

	LIS_tppLista * temp ;
	Crt ** vCarta ;

	Crt * crttemp ;

	LIS_IrInicioLista( cb ) ;

	temp = LIS_AcessaListaIni( cb ) ;

	strcpy( val, CTA_ConverteValor( CTA_VerificaValor( valor ) ) ) ;

	for( ( * contador ) = 0 ; temp != NULL ; temp = LIS_Proximo( temp ) )
	{
		crttemp = ( Crt * )LIS_AcessaStruct( temp ) ;

		strcpy( ComparaValor, CTA_AcessaValor( crttemp ) ) ;
		ComparaNaipe = CTA_AcessaNaipe( crttemp ) ;

		( * contador )++ ;

		if ( strcmp( ComparaValor, val ) == 0 && ComparaNaipe == ( char )CTA_VerificaNaipe( naipe ) ) 
		{
			ComparaEstado = CTA_AcessaEstado( crttemp ) ;
			ComparaSituacao = CTA_AcessaSituacao( crttemp ) ;

			if ( ComparaEstado == 1 && ComparaSituacao == 1 )
			{
				break ;
			} /* if */
			else
			{
				printf( "Voce nao pode mover esta carta!" ) ;

				Sleep( 2500 ) ;
			} /* if */
		} /* if */ 
	} /* for */

	if( temp == NULL )
	{
		return NULL ;
	} /* if */

	vCarta = ( Crt ** )malloc( sizeof( Crt * ) * ( * contador ) ) ;

	for( i = 0 ; i < ( * contador ) ; i++ )
	{
		vCarta[i] = PDCRT_Pop( cb ) ;
	} /* if */

	return vCarta ;
} /* Fim função: SEQ Retira Cartas */

/***********************************************************************
*
*	Função: SEQ Insere Cartas
*
***********************************************************************/

SEQ_tpCondRet SEQ_InsereCartas( LIS_tppCabeca * cb , Crt ** vCarta, int vTamanho )
{
	while( vTamanho != 0 )
	{
		PDCRT_Push( cb, vCarta[vTamanho-1] ) ;

		vTamanho-- ;
	} /* while */

	return SEQ_CondRetOK ;
} /* Fim função: SEQ Insere Cartas */

/***********************************************************************
*
*	Função: SEQ Imprimir Sequências
*
***********************************************************************/

SEQ_tpCondRet SEQ_ImprimeSequencias( LIS_tppCabeca * cb, int index )
{
	LIS_tppLista * aux ;

	Crt * carta ;
	char * valor ;
	char naipe ;
	int estado ;
	int situacao ;

	aux = LIS_AcessaListaFim( cb ) ;

	printf( "(%i)", index+1 ) ;

	for ( aux = LIS_AcessaListaFim( cb ) ; aux != NULL ; aux = LIS_Anterior( aux ) )
	{
		carta = ( Crt * )LIS_AcessaStruct( aux ) ;
		valor = CTA_AcessaValor( carta ) ;
		naipe = CTA_AcessaNaipe( carta ) ;
		estado = CTA_AcessaEstado( carta ) ;
		situacao = CTA_AcessaSituacao( carta ) ;

		if ( estado == 0 )
		{
			printf (" X ") ;
		} /* if */
		else if ( estado == 1 && situacao == 0 )
		{
			printf(" |%s%c| ", valor, naipe ) ;
		} /* if */
		else
		{
			printf(" %s%c ", valor, naipe ) ;
		} /* if */
	} /* for */

	return SEQ_CondRetOK ;
} /*Fim função: SEQ Imprimir Sequências*/

/********** Fim do módulo de definição: Módulo Sequências **********/