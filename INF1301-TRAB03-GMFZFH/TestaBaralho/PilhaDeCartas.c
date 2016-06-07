/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Pilha de Cratas
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


#include "Carta.h"
#include "Lista.h"
#include "PilhaDeCartas.h"

/*********************************************************************
*
*	Fun��o: PDCRT Push
*
*********************************************************************/

void PDCRT_Push(LIS_tppCabeca * cb, Crt * carta)
{
	LIS_InserirElementoAntes(cb, carta);
}/*Fim fun��o: PDCRT Push*/

/*********************************************************************
*
*	Fun��o: PDCRT Pop
*
*********************************************************************/


Crt * PDCRT_Pop(LIS_tppCabeca * cb)
{
	Crt * carta, *temp;

	char * valor;
	char naipe;
	int estado;
	int situacao;



	LIS_IrInicioLista(cb);

	temp = (Crt *)LIS_ObterValor(cb);
	valor = CTA_AcessaValor(temp);
	naipe = CTA_AcessaNaipe(temp);
	estado = CTA_AcessaEstado(temp);
	situacao = CTA_AcessaSituacao(temp);

	carta = CTA_CriaCarta(valor, naipe, estado, situacao);

	LIS_ExcluirElemento(cb);



	return carta;
}/*Fim fun��o: PDCRT Pop*/

/**************   Fim do m�dulo de implementa��o: Pilha de Cartas  *****************/