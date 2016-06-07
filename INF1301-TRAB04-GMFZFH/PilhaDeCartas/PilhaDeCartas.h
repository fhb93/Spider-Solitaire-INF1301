#if ! defined (PILHADECARTAS_)
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


typedef struct PDCRT_PilhaCartas PDCRT_tpPilhaCartas;
typedef enum {

	PDCRT_CondRetOK = 0,
	/* Executou correto */
	PDCRT_CondRetCartaInexistente = 1,
	/*	Carta não existe */
	PDCRT_CondRetPilhaVazia = 2,
	/*  Pilha de Cartas está vazia */
	PDCRT_CondRetPilhaInexistente = 3,
	/* Erro ao Criar Pilha */
	PDCRT_CondRetFaltouMemoria = 4
	/* Falta de Memória */

} PDCRT_tpCondRet;


#ifdef _DEBUG
typedef enum{
	D_DESTROI_CORRENTE = 1,
	/* Elimina o elemento corrente da estrutura escolhida */
	D_NULL_SUCESSOR = 2,
	/* Atribui NULL ao ponteiro para um nó sucessor */
	D_NULL_PREDECESSOR = 3,
	/* Atribui NULL ao ponteiro para um nó predecessor */
	D_LIXO_SUCESSOR = 4,
	/* Atribui lixo ao ponteiro para a referência a um nó sucessor */
	D_LIXO_PREDECESSOR = 5,
	/* Atribui lixo ao ponteiro para a referência a um nó predecessor */
	D_NULL_CONTEUDO = 6,
	/* Atribui NULL ao ponteiro para o conteúdo do nó */
	D_ALTERA_TIPO = 7,
	/* Altera o tipo de estrutura apontado no nó */
	D_FREE_PARCIAL = 8,
	/* Destaca nó da pilha sem liberá-lo com free */
	D_NULL_CORRENTE = 9,
	/* Atribui NULL ao ponteiro corrente */
	D_NULL_ORIGEM = 10
	/* Atribui NULL a um ponteiro de origem */
};
#endif





/***********************************************************************
*
*  $FC Função: PDCRT Criar Pilha de Cartas
*
*  $ED Descrição da função
*		Inicializa a Pilha de Cartas que será utilizada pela estrutura
*		principal do jogo
*
*	$EP	Parâmetros
*		$P pilha - Ponteiro para a estrutura que será inicializada
*
*	$FV Valor retornado
*		PDCRT_CondRetPilhaInexistente - Caso haja algum erro e a Pilha
*										não seja inicializada
*		PDCRT_CondRetOK - Caso a Pilha seja inicializada com sucesso
***********************************************************************/
PDCRT_tpPilhaCartas * PDCRT_CriaPilha( void );

/***********************************************************************
*
*  $FC Função: PDCRT Criar Pilha de Cartas
*
*  $ED Descrição da função
*		Destrói a Pilha passada por parâmetro
*
*	$EP	Parâmetros
*		$P pilha - Ponteiro para a estrutura que será inicializada
*
*	$FV Valor retornado
*		PDCRT_CondRetPilhaInexistente - Caso não haja Pilha para ser
*										destruída
*		PDCRT_CondRetOK - Caso a Pilha seja destruída com sucesso
***********************************************************************/
PDCRT_tpCondRet PDCRT_DestroiPilha(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Função: PDCRT Push
*
*  $ED Descrição da função
*		Cria um nó contendo a carta passada como parâmetro
*		Insere um nó no ínicio da lista (pilha) cuja cabeça passada aponta
*
*	$EP	Parâmetros
*		$P pilha - ponteiro para a Pilha a qual se quer adicionar uma carta
*		$P carta - Ponteiro para a carta a qual se quer adicionar à Pilha
*
***********************************************************************/
void PDCRT_Push(PDCRT_tpPilhaCartas * pilha, Crt * carta);


/***********************************************************************
*
*  $FC Função: PDCRT Pop
*
*  $ED Descrição da função
*     Retira um nó do início da lista (pilha) apontada pela cabeça passada
*	  como parâmetro
*  $EP Parâmetros
*   $P pilha - ponteiro para a Pilha da qual se deseja retirar a carta
*
*  $FV Valor retornado
*     Ponteiro para a carta que foi retirada da pilha
**********************************************************************/
Crt * PDCRT_Pop(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Função: PDCRT Acessar Topo
*
*  $ED Descrição da função
*     Retorna um ponteiro para o topo da Pilha de Cartas
*
*  $EP Parâmetros
*   $P pilha - ponteiro para a Pilha de Cartas
*
*  $FV Valor retornado
*     Ponteiro para o topo da Pilha de Cartas passada
**********************************************************************/
LIS_tppLista * PDCRT_AcessaTopo(PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Função: PDCRT Acessar Topo
*
*  $ED Descrição da função
*     Retorna a cabeça da pilha de cartas passada por parâmetro
*
*  $EP Parâmetros
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
*  $FC Função: PDCRT Verifica
*
*  $ED Descrição da função
*     Verifica as assertivas estruturais do teste da estrutura
*
*  $EP Parâmetros
*   $P pilha - ponteiro para a Pilha de Cartas
*
*  $FV Valor retornado
*		PDCRT_CondRetOK - Caso a Pilha seja destruída com sucesso
**********************************************************************/


PDCRT_tpCondRet PDCRT_Verifica(int* numErros, PDCRT_tpPilhaCartas * pilha);

/***********************************************************************
*
*  $FC Função: PDCRT Deturpa
*
*  $ED Descrição da função
*     Realiza as deturpações da estrutura auto-verificável
*
*  $EP Parâmetros
*   $P cb - ponteiro para a Cabeça da lista que se deseja acessar
*
*  $FV Valor retornado
*		PDCRT_CondRetOK - Caso a Pilha seja destruída com sucesso
**********************************************************************/


PDCRT_tpCondRet PDCRT_Deturpar(int caso, LIS_tppCabeca * CabecaTeste); 


/**************   Fim do módulo de definição : Pilha de Cartas  *****************/
#else
#endif