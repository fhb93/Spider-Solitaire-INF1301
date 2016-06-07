#define BARALHO_
/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Baralho
*
*  Arquivo gerado:              Baralho.h
*  Letras identificadoras:      BAR
*
*  Nome da base de software:    Jogo paciencia spider
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
*     Contem a fun��o embaralhar.
*	  Este modulo randomiza as cartas do baralho e cria uma lista
*	  randomizada
*
***************************************************************************/

#if defined( BARALHO_OWN )
#define BARALHO_EXT
#else
#define BARALHO_EXT extern
#endif

/***********************************************************************
*
*  $TC Tipo de dados: BAR Condicoes de retorno
*
*
***********************************************************************/

typedef enum {

	BAR_CondRetOK = 0,
	/* Executou correto */
	BAR_CondRetBaralhoVazio = 1,
	/* O baralho para ser embaralho n�o possui cartas */
	BAR_CondRetModoDeCriacaoInexistente = 2,
	/* Se o modo de jogo passado como par�mentro n�o constar
	no modo de cria��o do baralho */
	BAR_CondRetFaltouMemoria = 3,
	/* Mem�ria Insuficiente para alocar um novo baralho */
	BAR_CondRetBaralhoInexistente = 4
	/* O baralho que est� se tentando usar n�o existe */
} BAR_tpCondRet;


/***********************************************************************
*
*    Fun��o: BAR Cria Baralho
*
*  $EP Par�metros
*     $P cb - recebe a cabe�a onde o baralho ser� inicializado
*     $P modo - recebe o modo a qual o baralho deve ser inicializado
*
*  $FV Valor retornado
*     BAR_CondRetModoDeCriacaoInexistente caso n�o exista o modo
*	  de inicializa��o fornecido
*     BAR_CondRetOK caso execute corretamente
*
************************************************************************/

BAR_tpCondRet BAR_CriaBaralho(LIS_tppCabeca * cb, int modo);

/***********************************************************************
*
*	Fun��o: BAR Embaralhar
*
*  $ED Descri��o da fun��o
*     Embaralha uma lista, ela transfere uma Lista de Cartas
*      de uma sequencia fonte para um vetor, e randomiza a mesma
*	   retornando depois o elemsntos randomizados para a lista
*
*  $EP Par�metros
*     $P cb - recebe a cabe�a que contem o baralho inicializado
*
*  $FV Valor retornado
*     BAR_CondRetBaralhoInexistente caso n�o exista um baralho
*     ordenado na Cabe�a referente a Baralho da estrutura principal
*     BAR_CondRetOK caso execute corretamente
*
***********************************************************************/

BAR_tpCondRet BAR_Embaralhar(LIS_tppCabeca * cb);


/***********************************************************************
*
*	Fun��o: BAR Distribuir Baralho
*
*  $ED Descri��o da fun��o
*      Distribui uma quantidade passada como par�metro de cartas contidas no Baralho para a
*	   sequ�ncia tamb�m passada como par�metro
*
*
*
*  $EP Par�metros
*     $P baralho - Cabe�a que aponta para o Baralho inicializado
*     $P cb - Cabe�a que aponta para a sequ�ncia para a qual se deseja distribuir as cartas
*     $P NumCartas - Quantidade de cartas que se deseja distribuir
*
*  $FV Valor retornado
*     BAR_CondRetBaralhoInexistente caso n�o exista um baralho
*     ordenado na Cabe�a referente a Baralho da estrutura principal
*     BAR_CondRetOK caso execute corretamente
*
***********************************************************************/

BAR_tpCondRet BAR_DistribuiBaralho(LIS_tppCabeca * baralho, LIS_tppCabeca * cb, int NumCartas);

/********** Fim do m�dulo de defini��o: M�dulo Baralho **********/