#if ! defined( CINCOPRINCIPAIS_ )
#define CINCOPRINCIPAIS_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Cinco Principais
*
*  Arquivo gerado:              CincoPrincipais.h
*  Letras identificadoras:      MNT
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
*     Cont�m as fun��es referentes � a��o de pedir cartas dos
*     cinco montes principais.
*
***************************************************************************/

#if defined( CINCOPRINCIPAIS_OWN )
#define CINCOPRINCIPAIS_EXT
#else
#define CINCOPRINCIPAIS_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: MNT Condicoes de retorno
*
*
***********************************************************************/

typedef enum {

	MNT_CondRetOK = 0,
	/* Executou correto */
	MNT_CondRetSequenciaVazia = 1,
	/* Existe uma sequ�ncia em jogo sem cartas */
	MNT_CondRetSemMontesRestantes = 2
	/* O jogador j� utilizou os cinco montes para pedir cartas*/
} MNT_tpCondRet;



/***********************************************************************
*
*  $FC Fun��o: Pedir Monte
*
*  $ED Descri��o da fun��o
*     Efetua as transfer�ncias necess�rias ao ser
*     requisitadas cartas dos cinco montes principais
*     pelo usu�rio.
*
*  $EP Par�metros
*     $P Princ - recebe a cabe�a da estrutura principal
*
*  $FV Valor retornado
*	  MNT_CondRetOK
*	  MNT_CondRetSequenciaVazia
*	  MNT_CondRetSemMontesRestantes
*
***********************************************************************/
MNT_tpCondRet MNT_PedeMonte(LIS_tppCabeca * cbseq, LIS_tppCabeca * cbmnt);

/********** Fim do m�dulo de defini��o: M�dulo Cinco Principais **********/

#endif