#if ! defined( SEQUENCIASCOMPLETAS_ )
#define SEQUENCIASCOMPLETAS_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Sequ�ncias Completas
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   gff   13/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Cont�m as fun��es que verificam as sequ�ncias que foram
*     completas.
*	  OBS: O caso de jogo finalizado � tratado no m�dulo Principal
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
	/* N�o h� sequ�ncia completa em jogo */

} SEC_tpCondRet;


/***********************************************************************
*
*	Fun��o: SEC Verifica Sequ�ncias Completas
*
*  $ED Descri��o da fun��o
*	   Verifica se ap�s uma mudan�a alguma sequ�ncia foi
*	   completa
*
*  $EP Par�metros
*     $P cbFonte - Cabe�a da sequ�ncia da carta que est� sendo movida
*     $P cbDestino - Cabe�a da sequ�ncia destino para onde est� sendo movida a carta
*
*
*  $FV Valor retornado
*     SEC_CondRetSemSequenciasCompletas caso n�o tenha sequ�ncias
*	  completas
*	  SEC_CondRetOK caso tenha encontrado uma sequ�ncia
*	  completa de A a K e tenha retirado para uma lista
*	  separada
*
***********************************************************************/

SEC_tpCondRet SEC_VerificaSequenciasCompletas(LIS_tppCabeca * cbFonte, LIS_tppCabeca * cbDestino);

/********** Fim do m�dulo de defini��o: M�dulo Sequ�ncias Completas **********/

#endif