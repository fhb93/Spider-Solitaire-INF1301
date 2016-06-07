#define PILHADECARTAS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Pilha de Cartas
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contém as funções referentes a pilha de cartas
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
	/*	Carta não existe */
	PDCRT_CondRetBaralhoInexistente = 2,
	/*  Baralho não existe */
	PDCRT_CondRetPilhaVazia = 3
	/*  Pilha de Cartas está vazia */
} PDCRT_tpCondRet;



/***********************************************************************
*
*  $FC Função: PDCRT Push
*
*  $ED Descrição da função
*		Cria um nó contendo a carta passada como parâmetro
*		Insere um nó no ínicio da lista (pilha) cuja cabeça passada aponta
*
*	$EP	Parâmetros
*		$P cb - Cabeça que aponta para a lista a qual se quer modificar
*		$P carta - Ponteiro para a carta a qual se quer adicionar à pilha
*
***********************************************************************/
void PDCRT_Push( LIS_tppCabeca * cb, Crt * carta ) ;


/***********************************************************************
*
*  $FC Função: PDCRT Pop
*
*  $ED Descrição da função
*     Retira um nó do início da lista (pilha) apontada pela cabeça passada
*	  como parâmetro
*  $EP Parâmetros
*   $P cb - Cabeça que aponta para a lista a qual se quer modificar
*
*  $FV Valor retornado
*     Ponteiro para a carta que foi retirada da pilha*/
Crt * PDCRT_Pop( LIS_tppCabeca * cb ) ;

/**************   Fim do módulo de implementação: Pilha de Cartas  *****************/
