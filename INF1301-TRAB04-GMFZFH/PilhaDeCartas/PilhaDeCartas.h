#if ! defined (PILHADECARTAS_)
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


typedef struct PDCRT_PilhaCartas PDCRT_tpPilhaCartas;
typedef enum {

	PDCRT_CondRetOK = 0,
	/* Executou correto */
	PDCRT_CondRetCartaInexistente = 1,
	/*	Carta n�o existe */
	PDCRT_CondRetPilhaVazia = 2,
	/*  Pilha de Cartas est� vazia */
	PDCRT_CondRetPilhaInexistente = 3,
	/* Erro ao Criar Pilha */
	PDCRT_CondRetFaltouMemoria = 4
	/* Falta de Mem�ria */

} PDCRT_tpCondRet;


#ifdef _DEBUG
typedef enum{
	D_DESTROI_CORRENTE = 1,
	/* Elimina o elemento corrente da estrutura escolhida */
	D_NULL_SUCESSOR = 2,
	/* Atribui NULL ao ponteiro para um n� sucessor */
	D_NULL_PREDECESSOR = 3,
	/* Atribui NULL ao ponteiro para um n� predecessor */
	D_LIXO_SUCESSOR = 4,
	/* Atribui lixo ao ponteiro para a refer�ncia a um n� sucessor */
	D_LIXO_PREDECESSOR = 5,
	/* Atribui lixo ao ponteiro para a refer�ncia a um n� predecessor */
	D_NULL_CONTEUDO = 6,
	/* Atribui NULL ao ponteiro para o conte�do do n� */
	D_ALTERA_TIPO = 7,
	/* Altera o tipo de estrutura apontado no n� */
	D_FREE_PARCIAL = 8,
	/* Destaca n� da pilha sem liber�-lo com free */
	D_NULL_CORRENTE = 9,
	/* Atribui NULL ao ponteiro corrente */
	D_NULL_ORIGEM = 10
	/* Atribui NULL a um ponteiro de origem */
};
#endif





/***********************************************************************
*
*  $FC Fun��o: PDCRT Criar Pilha de Cartas
*
*  $ED Descri��o da fun��o
*		Inicializa a Pilha de Cartas que ser� utilizada pela estrutura
*		principal do jogo
*
*	$EP	Par�metros
*		$P pilha - Ponteiro para a estrutura que ser� inicializada
*
*	$FV Valor retornado
*		PDCRT_CondRetPilhaInexistente - Caso haja algum erro e a Pilha
*										n�o seja inicializada
*		PDCRT_CondRetOK - Caso a Pilha seja inicializada com sucesso
***********************************************************************/
PDCRT_tpPilhaCartas * PDCRT_CriaPilha( void );

/***********************************************************************
*
*  $FC Fun��o: PDCRT Criar Pilha de Cartas
*
*  $ED Descri��o da fun��o
*		Destr�i a Pilha passada por par�metro
*
*	$EP	Par�metros
*		$P pilha - Ponteiro para a estrutura que ser� inicializada
*
*	$FV Valor retornado
*		PDCRT_CondRetPilhaInexistente - Caso n�o haja Pilha para ser
*										destru�da
*		PDCRT_CondRetOK - Caso a Pilha seja destru�da com sucesso
***********************************************************************/
PDCRT_tpCondRet PDCRT_DestroiPilha(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Fun��o: PDCRT Push
*
*  $ED Descri��o da fun��o
*		Cria um n� contendo a carta passada como par�metro
*		Insere um n� no �nicio da lista (pilha) cuja cabe�a passada aponta
*
*	$EP	Par�metros
*		$P pilha - ponteiro para a Pilha a qual se quer adicionar uma carta
*		$P carta - Ponteiro para a carta a qual se quer adicionar � Pilha
*
***********************************************************************/
void PDCRT_Push(PDCRT_tpPilhaCartas * pilha, Crt * carta);


/***********************************************************************
*
*  $FC Fun��o: PDCRT Pop
*
*  $ED Descri��o da fun��o
*     Retira um n� do in�cio da lista (pilha) apontada pela cabe�a passada
*	  como par�metro
*  $EP Par�metros
*   $P pilha - ponteiro para a Pilha da qual se deseja retirar a carta
*
*  $FV Valor retornado
*     Ponteiro para a carta que foi retirada da pilha
**********************************************************************/
Crt * PDCRT_Pop(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Fun��o: PDCRT Acessar Topo
*
*  $ED Descri��o da fun��o
*     Retorna um ponteiro para o topo da Pilha de Cartas
*
*  $EP Par�metros
*   $P pilha - ponteiro para a Pilha de Cartas
*
*  $FV Valor retornado
*     Ponteiro para o topo da Pilha de Cartas passada
**********************************************************************/
LIS_tppLista * PDCRT_AcessaTopo(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Fun��o: PDCRT Acessar Topo
*
*  $ED Descri��o da fun��o
*     Retorna a cabe�a da pilha de cartas passada por par�metro
*
*  $EP Par�metros
*   $P pilha - ponteiro para a Pilha de Cartas
*
*  $FV Valor retornado
*     Ponteiro para o topo da Pilha de Cartas passada
**********************************************************************/

LIS_tppCabeca *PDCRT_AcessaCabeca(PDCRT_tpPilhaCartas * pilha);
/***********************************************************************************/
#undef	PILHADECARTAS_EXT

/***********************************************************************
*
*  $FC Fun��o: PDCRT Verifica
*
*  $ED Descri��o da fun��o
*     Verifica as assertivas estruturais do teste da estrutura
*
*  $EP Par�metros
*   $P pilha - ponteiro para a Pilha de Cartas
*
*  $FV Valor retornado
*		PDCRT_CondRetOK - Caso a Pilha seja destru�da com sucesso
**********************************************************************/


PDCRT_tpCondRet PDCRT_Verifica(int* numErros, PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Fun��o: PDCRT Deturpa
*
*  $ED Descri��o da fun��o
*     Realiza as deturpa��es da estrutura auto-verific�vel
*
*  $EP Par�metros
*   $P cb - ponteiro para a Cabe�a da lista que se deseja acessar
*
*  $FV Valor retornado
*		PDCRT_CondRetOK - Caso a Pilha seja destru�da com sucesso
**********************************************************************/


PDCRT_tpCondRet PDCRT_Deturpar(int caso, LIS_tppCabeca * CabecaTeste); 


/**************   Fim do m�dulo de defini��o : Pilha de Cartas  *****************/
#else
#endif