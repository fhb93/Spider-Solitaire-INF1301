/***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:              testaLista.c
*  Letras identificadoras:      TLIS
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes de módulos C
*  Gestor:  LES/DI/PUC-Rio
*  Autores: avs
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data		 Observações
*     1.0	   gff   5/mai/2015	 Inicio do desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"

static const char CRIAR_LISTA_CMD         [ ] = "=criarlista"     ; 
static const char DESTRUIR_LISTA_CMD      [ ] = "=destruirlista"  ; 
static const char ESVAZIAR_LISTA_CMD      [ ] = "=esvaziarlista"  ; 
static const char INS_ELEM_ANTES_CMD      [ ] = "=inselemantes"   ; 
static const char INS_ELEM_APOS_CMD       [ ] = "=inselemapos"    ; 
static const char OBTER_VALOR_CMD         [ ] = "=obtervalorelem" ; 
static const char EXC_ELEM_CMD            [ ] = "=excluirelem"    ;
static const char IR_INICIO_CMD           [ ] = "=irinicio"       ; 
static const char IR_FIM_CMD              [ ] = "=irfinal"        ; 
static const char AVANCAR_ELEM_CMD        [ ] = "=avancarelem"    ;
static const char PROCURAR_ELEM_CMD       [ ] = "=procurarelem"   ;

#define DIM_VALOR     2 


LIS_tppCabeca * CabecaTeste ;

/***** Protótipos das funções encapuladas no módulo *****/

static void DestruirValor( void * pValor ) ;

static int  Compara ( void * pDado, void * pCorrente ) ;

/*****  Código das funções exportadas pelo módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS &Testar lista
*
*  $ED Descrição da função
*     Podem ser criadas até 10 listas, identificadas pelos índices 0 a 10
*
*     Comandos disponíveis:
*
*     =resetteste
*           - anula o vetor de listas. Provoca vazamento de memória
*     =criarlista                   inxLista
*     =destruirlista                inxLista
*     =esvaziarlista                inxLista
*     =inselemantes                 inxLista  string  CondRetEsp
*     =inselemapos                  inxLista  string  CondRetEsp
*     =obtervalorelem               inxLista  string  CondretPonteiro
*     =excluirelem                  inxLista  CondRetEsp
*     =irinicio                     inxLista
*     =irfinal                      inxLista
*     =avancarelem                  inxLista  numElem CondRetEsp
*
***********************************************************************/

TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	LIS_tpCondRet CondRetObtido = LIS_CondRetOK;
	LIS_tpCondRet CondRetEsperada = LIS_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa */
	int inxLista = -1,
		numLidos = -1,
		CondRetEsp = -1;

	TST_tpCondRet CondRet;

	char ValorDado[DIM_VALOR] = "";
	char ValorObtido[DIM_VALOR ] = "";
	char * pDado;

	int i ;

	int numElem = -1 ;

	/* Testar CriarLista */

	if ( strcmp( ComandoTeste , CRIAR_LISTA_CMD ) == 0 ) 
	{

		numLidos = LER_LerParametros( "i" ,
			&CondRetEsp ) ;     

		if ( numLidos != 1 )
		{
			return TST_CondRetParm ; 
		} /* if */

		CabecaTeste = LIS_CriaLista( DestruirValor ) ;

		return TST_CompararPonteiroNulo( 0 , LIS_AcessaListaIni(CabecaTeste) ,
			"Erro em ponteiro de nova lista."  ) ;  

	} /* fim ativa: Testar CriarLista */

	/* Testar Destruir lista */

	else if ( strcmp( ComandoTeste , DESTRUIR_LISTA_CMD ) == 0 ) //parece OK
	{

		numLidos = LER_LerParametros( "i" ,
			&CondRetEsp ) ;

		if ( numLidos != 1 )    
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = LIS_DestroiLista( CabecaTeste );

		return TST_CompararInt( CondRetEsp , CondRetObtido ,
			"Condicao de retorno errada ao inserir antes.") ;

	} /* fim ativa: Testar Destruir lista */

	/* Testar inserir elemento antes */

	else if ( strcmp( ComandoTeste , INS_ELEM_ANTES_CMD ) == 0 ) //parece OK
	{

		numLidos = LER_LerParametros( "si" ,
			ValorDado , &CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		} /* if */

		pDado = (char *)malloc(strlen(ValorDado) + 1);

		if (pDado == NULL)
		{
			return TST_CondRetMemoria;
		} /* if */

		strcpy(pDado, ValorDado);
		
		
		CondRetObtido = LIS_InserirElementoAntes( CabecaTeste , pDado ) ;

		if (CondRetObtido != LIS_CondRetOK)
		{
			free(pDado);
		} /* if */


		return TST_CompararInt( CondRetEsp , CondRetObtido ,
			"Condicao de retorno errada ao inserir antes.") ;

	} /* fim ativa: Testar inserir elemento antes */

	/* Testar inserir elemento apos */

	else if ( strcmp( ComandoTeste , INS_ELEM_APOS_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "si" ,
			ValorDado , &CondRetEsp ) ;

		if ( numLidos != 2 )
		{
			return TST_CondRetParm ;
		} /* if */
		
		pDado = (char *)malloc(strlen(ValorDado) + 1);

		if (pDado == NULL)
		{
			return TST_CondRetMemoria;
		} /* if */

		strcpy(pDado, ValorDado);


		CondRetObtido = LIS_InserirElementoApos(CabecaTeste, pDado);

		if (CondRetObtido != LIS_CondRetOK)
		{
			free(pDado);
		} /* if */
		

		return TST_CompararInt( CondRetEsp , CondRetObtido,
			"Condicao de retorno errada ao inserir apos." ) ;

	} /* fim ativa: Testar inserir elemento apos */

	/* Testar excluir simbolo */

	else if ( strcmp( ComandoTeste , EXC_ELEM_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,&CondRetEsp ) ;

		if ( numLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		return TST_CompararInt( CondRetEsp ,
			LIS_ExcluirElemento( CabecaTeste ) ,
			"Condição de retorno errada ao excluir."   ) ;

	} /* fim ativa: Testar excluir simbolo */

	/* Testar obter valor do elemento corrente */

	else if ( strcmp( ComandoTeste , OBTER_VALOR_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "si" ,
			ValorDado , &CondRetEsp ) ;

		if (  numLidos != 2  )
		{
			return TST_CondRetParm ;
		} /* if */

		if(LIS_AcessaListaIni(CabecaTeste) == NULL)
		{
			CondRetObtido = LIS_CondRetListaVazia;
			return TST_CompararInt(CondRetEsp, CondRetObtido, "A Lista está vazia" );
		}

		pDado = (char *)malloc(strlen(ValorDado) + 1);

		if (pDado == NULL)
		{
			return TST_CondRetMemoria;
		} /* if */

		strcpy(pDado, ValorDado);


		strcpy(ValorObtido, (char*) LIS_ObterValor(CabecaTeste));

		return TST_CompararString(pDado ,
			ValorObtido ,
			"Condição de retorno errada ao Obter Valor" );
		

	} /* fim ativa: Testar obter valor do elemento corrente */

	/* Testar ir para o elemento inicial */

	else if ( strcmp( ComandoTeste , IR_INICIO_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" , &CondRetEsp ) ;

		if ( numLidos != 1 )
		{
			return TST_CondRetParm ;
		} /* if */

		LIS_IrInicioLista( CabecaTeste ) ;

		return TST_CondRetOK ;

	} /* fim ativa: Testar ir para o elemento inicial */

	/* LIS  &Ir para o elemento final */

	else if ( strcmp( ComandoTeste , IR_FIM_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" , &CondRetEsp ) ;

		if ( ( numLidos != 1 ) )
		{
			return TST_CondRetParm ;
		} /* if */

		LIS_IrFinalLista( CabecaTeste ) ;

		return TST_CondRetOK ;

	} /* fim ativa: LIS  &Ir para o elemento final */

	/* LIS  &Avançar elemento */

	else if ( strcmp( ComandoTeste , AVANCAR_ELEM_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "ii" , &numElem ,
			&CondRetEsp ) ;

		if ( ( numLidos != 2 ) )
		{
			return TST_CondRetParm ;
		} /* if */

		return TST_CompararInt( CondRetEsp ,
			LIS_AvancarElementoCorrente( CabecaTeste , numElem ) ,
			"Condicao de retorno errada ao avancar" ) ;

	} /* fim ativa: LIS  &Avançar elemento */


	/* LIS  &Procurar elemento */

	else if ( strcmp( ComandoTeste , PROCURAR_ELEM_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "si" , ValorDado ,
			&CondRetEsp ) ;

		if ( ( numLidos != 2 ) )
		{
			return TST_CondRetParm ;
		} /* if */

		CondRetObtido = LIS_ProcurarValor(CabecaTeste, ValorDado, Compara);

		return TST_CompararInt(CondRetEsp, CondRetObtido, "Condicao de retorno errada ao procurar elemento");

	} /* fim ativa: LIS  &Procurar elemento */


	/* LIS  &Esvaziar lista */

	else if ( strcmp( ComandoTeste , ESVAZIAR_LISTA_CMD ) == 0 )
	{

		numLidos = LER_LerParametros( "i" ,	&CondRetEsp ) ;

		if ( ( numLidos != 1 ) )
		{
			return TST_CondRetParm ;
		} /* if */

		LIS_EsvaziarLista(CabecaTeste);

		return TST_CondRetOK;

	} /* fim ativa: LIS  &Esvaziar Lista */


	return TST_CondRetNaoConhec ;

} /* Fim função: TLIS &Testar lista */



/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TLIS -Destruir valor
*
***********************************************************************/

void DestruirValor( void * pValor )
{

	free( pValor ) ;

} /* Fim função: TLIS -Destruir valor */

int  Compara ( void * pDado, void * pCorrente ) 
{

	  if ( strcmp ( ( char * )pDado, ( char * )pCorrente) == 0 )
	  {
		  return 0;
	  } /* if */

	  else

		  return 1;
  }

/********** Fim do módulo de implementação: TLIS Teste lista de símbolos **********/
