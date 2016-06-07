#if ! defined( CINCOPRINCIPAIS_ )
#define CINCOPRINCIPAIS_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Cinco Principais
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contém as funções referentes à ação de pedir cartas dos
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
	/* Existe uma sequência em jogo sem cartas */
	MNT_CondRetSemMontesRestantes = 2
	/* O jogador já utilizou os cinco montes para pedir cartas*/
} MNT_tpCondRet;



/***********************************************************************
*
*  $FC Função: Pedir Monte
*
*  $ED Descrição da função
*     Efetua as transferências necessárias ao ser
*     requisitadas cartas dos cinco montes principais
*     pelo usuário.
*
*  $EP Parâmetros
*     $P Princ - recebe a cabeça da estrutura principal
*
*  $FV Valor retornado
*	  MNT_CondRetOK
*	  MNT_CondRetSequenciaVazia
*	  MNT_CondRetSemMontesRestantes
*
***********************************************************************/
MNT_tpCondRet MNT_PedeMonte(LIS_tppCabeca * cbseq, LIS_tppCabeca * cbmnt);

/********** Fim do módulo de definição: Módulo Cinco Principais **********/

#endif