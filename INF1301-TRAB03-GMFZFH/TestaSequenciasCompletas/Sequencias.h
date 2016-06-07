#if ! defined( SEQUENCIAS_ )
#define SEQUENCIAS_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Sequ�ncias
*
*  Arquivo gerado:              Sequencias.h
*  Letras identificadoras:      SEQ
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
*     Cont�m as fun��es referentes a mover cartas da sequencia
*	  e imprimir as mesmas.
*	  Este m�dulo � referente ao controle e manuseio das dez
*	  sequ�ncias do jogo
*
***************************************************************************/

#if defined( SEQUENCIAS_OWN )
#define SEQUENCIAS_EXT
#else
#define SEQUENCIAS_EXT extern
#endif

#include "Lista.h"

/***********************************************************************
*
*  $TC Tipo de dados: SEQ Condicoes de retorno
*
***********************************************************************/

typedef enum {

	SEQ_CondRetOK = 0,
	/* Executou correto */
	SEQ_CondRetSequenciaVazia = 1,
	/* Sequ�ncia sendo manipulada est� vazia */
	SEQ_CondRetCartaNaoEncontrada = 2
	/* Carta que se deseja mover n�o existe na sequ�ncia fonte */
} SEQ_tpCondRet;

/***********************************************************************
*
*	Fun��o: SEQ Imprimir Sequ�ncias
*
*  $ED Descri��o da fun��o
*     Imprime as dez sequencias principais de cartas do jogo
*
*  $EP Par�metros
*   $P cb - Cabe�a que aponta para a sequ�ncia que se deseja imprimir
*	$P index - N�mero da sequ�ncia sendo impressa
*
*  $FV Valor retornado
*     SEQ_CondRetOK caso execute corretamente
*
***********************************************************************/

SEQ_tpCondRet SEQ_ImprimeSequencias(LIS_tppCabeca * cb, int index);

/***********************************************************************
*
*	Fun��o: SEQ Retirar Cartas
*
*  $ED Descri��o da fun��o
*     Encontra a carta que se deseja retirar na sequ�ncia
*	  Retira da sequ�ncia a carta que se deseja mover junto
*	  junto de todas as cartas anteriores a ela
*
*  $EP Par�metros
*   $P cb - Cabe�a que aponta para a sequ�ncia que se deseja modificar
*	$P valor[] - String contendo o valor da carta que se deseja mover
*	$P naipe - Caractere com a inicial do naipe da carta que se deseja mover
*	$P contador - conta quantos n�s existem do in�cio da sequencia at� a carta
*	que se deseja mover
*
*  $FV Valor retornado
*     Vetor com ponteiros para as cartas retiradas da sequ�ncia
*
***********************************************************************/

Crt ** SEQ_RetiraCartas(LIS_tppCabeca * cb, char valor[], char naipe, int * contador);

/***********************************************************************
*
*	Fun��o: SEQ Inserir Carta
*
*  $ED Descri��o da fun��o
*     Insere as cartas do vetor passado uma por uma na sequ�ncia apontada
*	  pela cabe�a passada.
*
*  $EP Par�metros
*   $P cb - Cabe�a que aponta para a sequ�ncia que se deseja modificar
*	$P vCarta - Vetor com ponteiros para as cartas que se deseja inserir
*	$P vTamanho - Tamanho do vetor de cartas que se deseja inserir
*
*  $FV Valor retornado
*	 SEQ_CondRetOK caso execute com sucesso
*
***********************************************************************/
SEQ_tpCondRet SEQ_InsereCartas(LIS_tppCabeca * cb, Crt ** vCarta, int vTamanho);

/********** Fim do m�dulo de defini��o: M�dulo Sequ�ncias **********/
#endif