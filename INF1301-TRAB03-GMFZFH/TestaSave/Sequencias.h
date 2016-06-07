#if ! defined( SEQUENCIAS_ )
#define SEQUENCIAS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Sequências
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contém as funções referentes a mover cartas da sequencia
*	  e imprimir as mesmas.
*	  Este módulo é referente ao controle e manuseio das dez
*	  sequências do jogo
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
	/* Sequência sendo manipulada está vazia */
	SEQ_CondRetCartaNaoEncontrada = 2
	/* Carta que se deseja mover não existe na sequência fonte */
} SEQ_tpCondRet;

/***********************************************************************
*
*	Função: SEQ Imprimir Sequências
*
*  $ED Descrição da função
*     Imprime as dez sequencias principais de cartas do jogo
*
*  $EP Parâmetros
*   $P cb - Cabeça que aponta para a sequência que se deseja imprimir
*	$P index - Número da sequência sendo impressa
*
*  $FV Valor retornado
*     SEQ_CondRetOK caso execute corretamente
*
***********************************************************************/

SEQ_tpCondRet SEQ_ImprimeSequencias(LIS_tppCabeca * cb, int index);

/***********************************************************************
*
*	Função: SEQ Retirar Cartas
*
*  $ED Descrição da função
*     Encontra a carta que se deseja retirar na sequência
*	  Retira da sequência a carta que se deseja mover junto
*	  junto de todas as cartas anteriores a ela
*
*  $EP Parâmetros
*   $P cb - Cabeça que aponta para a sequência que se deseja modificar
*	$P valor[] - String contendo o valor da carta que se deseja mover
*	$P naipe - Caractere com a inicial do naipe da carta que se deseja mover
*	$P contador - conta quantos nós existem do início da sequencia até a carta
*	que se deseja mover
*
*  $FV Valor retornado
*     Vetor com ponteiros para as cartas retiradas da sequência
*
***********************************************************************/

Crt ** SEQ_RetiraCartas(LIS_tppCabeca * cb, char valor[], char naipe, int * contador);

/***********************************************************************
*
*	Função: SEQ Inserir Carta
*
*  $ED Descrição da função
*     Insere as cartas do vetor passado uma por uma na sequência apontada
*	  pela cabeça passada.
*
*  $EP Parâmetros
*   $P cb - Cabeça que aponta para a sequência que se deseja modificar
*	$P vCarta - Vetor com ponteiros para as cartas que se deseja inserir
*	$P vTamanho - Tamanho do vetor de cartas que se deseja inserir
*
*  $FV Valor retornado
*	 SEQ_CondRetOK caso execute com sucesso
*
***********************************************************************/
SEQ_tpCondRet SEQ_InsereCartas(LIS_tppCabeca * cb, Crt ** vCarta, int vTamanho);

/********** Fim do módulo de definição: Módulo Sequências **********/
#endif