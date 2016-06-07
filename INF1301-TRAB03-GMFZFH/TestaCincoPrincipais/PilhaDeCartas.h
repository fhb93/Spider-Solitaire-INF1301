#define PILHADECARTAS_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Pilha de Cartas
*
*  Arquivo gerado:              PilhaDeCartas.h
*  Letras identificadoras:      PDCRT
*
*  Nome da base de software:    Jogo Paciencia Spider
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
*     Cont�m as fun��es referentes a pilha de cartas
*
***************************************************************************/

#if defined( PILHADECARTAS_OWN )
#define PILHADECARTAS_EXT
#else
#define PILHADECARTAS_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: PDCRT Condicoes de retorno
*
*
***********************************************************************/

#include "Carta.h"
#include "Lista.h"

typedef enum {

	PDCRT_CondRetOK = 0,
	/* Executou correto */
	PDCRT_CondRetCartaInexistente = 1,
	/*	Carta n�o existe */
	PDCRT_CondRetBaralhoInexistente = 2,
	/*  Baralho n�o existe */
	PDCRT_CondRetPilhaVazia = 3
	/*  Pilha de Cartas est� vazia */
} PDCRT_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: PDCRT Push
*
*  $ED Descri��o da fun��o
*		Cria um n� contendo a carta passada como par�metro
*		Insere um n� no �nicio da lista (pilha) cuja cabe�a passada aponta
*
*	$EP	Par�metros
*		$P cb - Cabe�a que aponta para a lista a qual se quer modificar
*		$P carta - Ponteiro para a carta a qual se quer adicionar � pilha
*
***********************************************************************/

void PDCRT_Push(LIS_tppCabeca * cb, Crt * carta);

/***********************************************************************
*
*  $FC Fun��o: PDCRT Pop
*
*  $ED Descri��o da fun��o
*     Retira um n� do in�cio da lista (pilha) apontada pela cabe�a passada
*	  como par�metro
*  $EP Par�metros
*   $P cb - Cabe�a que aponta para a lista a qual se quer modificar
*
*  $FV Valor retornado
*     Ponteiro para a carta que foi retirada da pilha
*
***********************************************************************/
Crt * PDCRT_Pop(LIS_tppCabeca * cb);

/**************   Fim do m�dulo de implementa��o: Pilha de Cartas  *****************/