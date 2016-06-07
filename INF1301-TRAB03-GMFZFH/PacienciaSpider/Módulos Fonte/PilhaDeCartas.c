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


#include "Carta.h"
#include "Lista.h"
#include "PilhaDeCartas.h"

/***********************************************************************
*
*    Função: PDCRT Push
*
************************************************************************/

void PDCRT_Push( LIS_tppCabeca * cb, Crt * carta )
{
	LIS_IrInicioLista( cb ) ;

	LIS_InserirElementoAntes( cb, carta ) ;
} /* Fim função: PDCRT Push */

/***********************************************************************
*
*    Função: PDCRT Pop
*
************************************************************************/

Crt * PDCRT_Pop( LIS_tppCabeca * cb )
{
	Crt * carta , * temp;

	char * valor  ;
	char naipe ;
	int estado ;
	int situacao ;

	LIS_IrInicioLista( cb ) ;

	temp = ( Crt * ) LIS_ObterValor( cb ) ;
	valor = CTA_AcessaValor( temp ) ;
	naipe = CTA_AcessaNaipe( temp ) ;
	estado = CTA_AcessaEstado( temp ) ;
	situacao = CTA_AcessaSituacao( temp ) ;

	carta = CTA_CriaCarta ( valor , naipe , estado , situacao ) ;

	LIS_ExcluirElemento( cb ) ;

	return carta ;
} /* Fim função: PDCRT Pop */

/**************   Fim do módulo de implementação: Pilha de Cartas  *****************/