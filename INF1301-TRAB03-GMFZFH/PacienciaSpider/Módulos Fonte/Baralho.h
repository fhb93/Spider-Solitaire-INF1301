#define BARALHO_
/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Baralho
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contem a função embaralhar.
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
	/* O baralho para ser embaralho não possui cartas */
	BAR_CondRetModoDeCriacaoInexistente = 2,
	/* Se o modo de jogo passado como parâmentro não constar
	no modo de criação do baralho */
	BAR_CondRetFaltouMemoria = 3,
	/* Memória Insuficiente para alocar um novo baralho */
	BAR_CondRetBaralhoInexistente = 4
	/* O baralho que está se tentando usar não existe */
} BAR_tpCondRet;


/***********************************************************************
*
*    Função: BAR Cria Baralho
*
*  $EP Parâmetros
*     $P cb - recebe a cabeça onde o baralho será inicializado
*     $P modo - recebe o modo a qual o baralho deve ser inicializado
*
*  $FV Valor retornado
*     BAR_CondRetModoDeCriacaoInexistente caso não exista o modo
*	  de inicialização fornecido
*     BAR_CondRetOK caso execute corretamente
*
************************************************************************/

BAR_tpCondRet BAR_CriaBaralho(LIS_tppCabeca * cb, int modo);

/***********************************************************************
*
*	Função: BAR Embaralhar
*
*  $ED Descrição da função
*     Embaralha uma lista, ela transfere uma Lista de Cartas
*      de uma sequencia fonte para um vetor, e randomiza a mesma
*	   retornando depois o elemsntos randomizados para a lista
*
*  $EP Parâmetros
*     $P cb - recebe a cabeça que contem o baralho inicializado
*
*  $FV Valor retornado
*     BAR_CondRetBaralhoInexistente caso não exista um baralho
*     ordenado na Cabeça referente a Baralho da estrutura principal
*     BAR_CondRetOK caso execute corretamente
*
***********************************************************************/

BAR_tpCondRet BAR_Embaralhar(LIS_tppCabeca * cb);


/***********************************************************************
*
*	Função: BAR Distribuir Baralho
*
*  $ED Descrição da função
*      Distribui uma quantidade passada como parâmetro de cartas contidas no Baralho para a
*	   sequência também passada como parâmetro
*
*
*
*  $EP Parâmetros
*     $P baralho - Cabeça que aponta para o Baralho inicializado
*     $P cb - Cabeça que aponta para a sequência para a qual se deseja distribuir as cartas
*     $P NumCartas - Quantidade de cartas que se deseja distribuir
*
*  $FV Valor retornado
*     BAR_CondRetBaralhoInexistente caso não exista um baralho
*     ordenado na Cabeça referente a Baralho da estrutura principal
*     BAR_CondRetOK caso execute corretamente
*
***********************************************************************/

BAR_tpCondRet BAR_DistribuiBaralho(LIS_tppCabeca * baralho, LIS_tppCabeca * cb, int NumCartas);

/********** Fim do módulo de definição: Módulo Baralho **********/