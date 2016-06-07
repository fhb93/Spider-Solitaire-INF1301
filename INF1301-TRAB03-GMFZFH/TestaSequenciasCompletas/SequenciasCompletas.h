#if ! defined( SEQUENCIASCOMPLETAS_ )
#define SEQUENCIASCOMPLETAS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Sequências Completas
*
*  Arquivo gerado:              SequenciasCompletas.h
*  Letras identificadoras:      SEC
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
*     Contém as funções que verificam as sequências que foram
*     completas.
*	  OBS: O caso de jogo finalizado é tratado no módulo Principal
*
***************************************************************************/

#if defined( SEQUENCIASCOMPLETAS_OWN )
#define SEQUENCIASCOMPLETAS_EXT
#else
#define SEQUENCIASCOMPLETAS_EXT extern
#endif

#include "Lista.h"

typedef enum {

	SEC_CondRetOK = 0,
	/* Executou correto */
	SEC_CondRetSemSequenciasCompletas = 2,
	/* Não há sequência completa em jogo */

} SEC_tpCondRet;


/***********************************************************************
*
*	Função: SEC Verifica Sequências Completas
*
*  $ED Descrição da função
*	   Verifica se após uma mudança alguma sequência foi
*	   completa
*
*  $EP Parâmetros
*     $P cbFonte - Cabeça da sequência da carta que está sendo movida
*     $P cbDestino - Cabeça da sequência destino para onde está sendo movida a carta
*
*
*  $FV Valor retornado
*     SEC_CondRetSemSequenciasCompletas caso não tenha sequências
*	  completas
*	  SEC_CondRetOK caso tenha encontrado uma sequência
*	  completa de A a K e tenha retirado para uma lista
*	  separada
*
***********************************************************************/

SEC_tpCondRet SEC_VerificaSequenciasCompletas(LIS_tppCabeca * cbFonte, LIS_tppCabeca * cbDestino);

/********** Fim do módulo de definição: Módulo Sequências Completas **********/

#endif