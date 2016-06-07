/***************************************************************************
*  $MCI M�dulo de implementa��o: M�dulo �rvore
*
*  Arquivo gerado:              ARVORE.C
*  Letras identificadoras:      ARV
*
*  Nome da base de software:    Exemplo de teste automatizado
*
*  Projeto: Disciplinas INF 1301
*  Gestor:  DI/PUC-Rio
*  Autores: avs - Arndt von Staa, gm - Gabriel Maia, fh - Felipe Holanda, fz - Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*		5.00 gmfzfh  24/03/2015 Reestrutura��o e corre��o
*		4.00 gmfzfh  18/03/2015 In�cio da implementa��o das fun��es
*								auxiliares da costura
*       3.00   avs   28/02/2003 Uniformiza��o da interface das fun��es e
*                               de todas as condi��es de retorno.
*       2.00   avs   03/08/2002 Elimina��o de c�digo duplicado, reestrutura��o
*       1.00   avs   15/08/2001 In�cio do desenvolvimento
*
***************************************************************************/

#include   <malloc.h>
#include   <stdio.h>
#include   <stdlib.h>
#include   <string.h>

#define ARVORE_OWN
#include "ARVORE.H"
#undef ARVORE_OWN

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor do n� da �rvore
*
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o do n�
*
***********************************************************************/

int	numFolhas = 0;

typedef struct tgNoArvore {

	struct tgNoArvore * pNoPai ;
	/* Ponteiro para pai
	*
	*$EED Assertivas estruturais
	*   � NULL sse o n� � raiz
	*   Se n�o for raiz, um de pNoEsq ou pNoDir de pNoPai do n�
	*   corrente apontam para o n� corrente */

	struct tgNoArvore * pNoEsq ;
	/* Ponteiro para filho � esquerda
	*
	*$EED Assertivas estruturais
	*   se pNoEsq do n� X != NULL ent�o pNoPai de pNoEsq aponta para o n� X */

	struct tgNoArvore * pNoDir ;
	/* Ponteiro para filho � direita
	*
	*$EED Assertivas estruturais
	*   se pNoDir do n� X != NULL ent�o pNoPai de pNoDir aponta para o n� X */

	struct tgNoArvore * pNoCostura ;	
	/* Ponteiro para costura
	*
	*$EED Assertivas estruturais
	*   N�o � NULL se o n� � folha */

	char Valor ;
	/* Valor do n� */

	char Chave;
	/* Valor para alfanumerico */
} tpNoArvore ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabe�a de uma �rvore
*
*
*  $ED Descri��o do tipo
*     A cabe�a da �rvore � o ponto de acesso para uma determinada �rvore.
*     Por interm�dio da refer�ncia para o n� corrente e do ponteiro
*     pai pode-se navegar a �rvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a �rvore em forma de co-rotina.
*
***********************************************************************/

typedef struct tgArvore {

	tpNoArvore * pNoRaiz ;
	/* Ponteiro para a raiz da �rvore */

	tpNoArvore * pNoCorr ;
	/* Ponteiro para o n� corrente da �rvore */

} tpArvore ;

/*****  Dados encapsulados no m�dulo  *****/

static tpArvore * pArvore = NULL ;
/* Ponteiro para a cabe�a da �rvore */

tpNoArvore ** nosFolha;
/* Vetor de ponteiros para estrutura da �rvore */
int index = 0;
/* Vari�vel utilizada como contador de loops */

/***** Prot�tipos das fun��es encapsuladas no m�dulo *****/

static tpNoArvore * CriarNo( char ValorParm , char ChaveParm ) ;

static ARV_tpCondRet CriarNoRaiz( char ValorParm , char ChaveParm ) ;

static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/

/***************************************************************************
*
*  Fun��o: ARV Criar �rvore
*  ****/

ARV_tpCondRet ARV_CriarArvore( void )
{

	if ( pArvore != NULL )
	{
		ARV_DestruirArvore( ) ;
	} /* if */

	pArvore = ( tpArvore * ) malloc( sizeof( tpArvore )) ;
	if ( pArvore == NULL )
	{
		return ARV_CondRetFaltouMemoria ;
	} /* if */

	pArvore->pNoRaiz = NULL ;
	pArvore->pNoCorr = NULL ;

	return ARV_CondRetOK ;

} /* Fim fun��o: ARV Criar �rvore */

/***************************************************************************
*
*  Fun��o: ARV Destruir �rvore
*  ****/

void ARV_DestruirArvore( void )
{

	if ( pArvore != NULL )
	{
		if ( pArvore->pNoRaiz != NULL )
		{
			DestroiArvore( pArvore->pNoRaiz ) ;
		} /* if */
		free( pArvore ) ;
		pArvore = NULL ;
	} /* if */

} /* Fim fun��o: ARV Destruir �rvore */

/***************************************************************************
*
*  Fun��o: ARV Adicionar filho � esquerda
*  ****/

ARV_tpCondRet ARV_InserirEsquerda( char ValorParm , char ChaveParm )
{

	ARV_tpCondRet CondRet ;

	tpNoArvore * pCorr ;
	tpNoArvore * pNo ;

	/* Tratar vazio, esquerda */

	CondRet = CriarNoRaiz( ValorParm , ChaveParm ) ;
	if ( CondRet != ARV_CondRetNaoCriouRaiz )
	{
		return CondRet ;
	} /* if */

	/* Criar n� � esquerda de folha */

	pCorr = pArvore->pNoCorr ;
	if ( pCorr == NULL )
	{
		return ARV_CondRetErroEstrutura ;
	} /* if */

	if ( pCorr->pNoEsq == NULL )
	{
		pNo = CriarNo( ValorParm , ChaveParm ) ;
		if ( pNo == NULL )
		{
			return ARV_CondRetFaltouMemoria ;
		} /* if */
		pNo->pNoPai      = pCorr ;
		pCorr->pNoEsq    = pNo ;
		pArvore->pNoCorr = pNo ;
		return ARV_CondRetOK ;
	} /* if */

	/* Tratar n�o folha � esquerda */

	return ARV_CondRetNaoEhFolha ;

} /* Fim fun��o: ARV Adicionar filho � esquerda */

/***************************************************************************
*
*  Fun��o: ARV Adicionar filho � direita
*  ****/

ARV_tpCondRet ARV_InserirDireita( char ValorParm , char ChaveParm )
{

	ARV_tpCondRet CondRet ;

	tpNoArvore * pCorr ;
	tpNoArvore * pNo ;

	/* Tratar vazio, direita */

	CondRet = CriarNoRaiz( ValorParm , ChaveParm ) ;
	if ( CondRet != ARV_CondRetNaoCriouRaiz )
	{
		return CondRet ;
	} /* if */

	/* Criar n� � direita de folha */

	pCorr = pArvore->pNoCorr ;
	if ( pCorr == NULL )
	{
		return ARV_CondRetErroEstrutura ;
	} /* if */

	if ( pCorr->pNoDir == NULL )
	{
		pNo = CriarNo( ValorParm , ChaveParm ) ;
		if ( pNo == NULL )
		{
			return ARV_CondRetFaltouMemoria ;
		} /* if */
		pNo->pNoPai      = pCorr ;
		pCorr->pNoDir    = pNo ;
		pArvore->pNoCorr = pNo ;

		return ARV_CondRetOK ;
	} /* if */

	/* Tratar n�o folha � direita */

	return ARV_CondRetNaoEhFolha ;

} /* Fim fun��o: ARV Adicionar filho � direita */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� pai
*  ****/

ARV_tpCondRet ARV_IrPai( void )
{

	if ( pArvore == NULL )
	{
		return ARV_CondRetArvoreNaoExiste ;
	} /* if */
	if ( pArvore->pNoCorr == NULL )
	{
		return ARV_CondRetArvoreVazia ;
	} /* if */

	if ( pArvore->pNoCorr->pNoPai != NULL )
	{
		pArvore->pNoCorr = pArvore->pNoCorr->pNoPai ;
		return ARV_CondRetOK ;
	} else {
		return ARV_CondRetNohEhRaiz ;
	} /* if */

} /* Fim fun��o: ARV Ir para n� pai */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� � esquerda
*  ****/

ARV_tpCondRet ARV_IrNoEsquerda( void )
{

	if ( pArvore == NULL )
	{
		return ARV_CondRetArvoreNaoExiste ;
	} /* if */

	if ( pArvore->pNoCorr == NULL )
	{
		return ARV_CondRetArvoreVazia ;
	} /* if */

	if ( pArvore->pNoCorr->pNoEsq == NULL )
	{
		return ARV_CondRetNaoPossuiFilho ;
	} /* if */

	pArvore->pNoCorr = pArvore->pNoCorr->pNoEsq ;
	return ARV_CondRetOK ;

} /* Fim fun��o: ARV Ir para n� � esquerda */

/***************************************************************************
*
*  Fun��o: ARV Ir para n� � direita
*  ****/

ARV_tpCondRet ARV_IrNoDireita( void )
{

	if ( pArvore == NULL )
	{
		return ARV_CondRetArvoreNaoExiste ;
	} /* if */

	if ( pArvore->pNoCorr == NULL )
	{
		return ARV_CondRetArvoreVazia ;
	} /* if */

	if ( pArvore->pNoCorr->pNoDir == NULL )
	{
		return ARV_CondRetNaoPossuiFilho ;
	} /* if */

	pArvore->pNoCorr = pArvore->pNoCorr->pNoDir ;
	return ARV_CondRetOK ;

} /* Fim fun��o: ARV Ir para n� � direita */

/***************************************************************************
*
*  Fun��o: ARV Obter valor corrente
*  ****/

ARV_tpCondRet ARV_ObterValorCorr( char * ValorParm , char * ChaveParm )
{

	if ( pArvore == NULL )
	{
		return ARV_CondRetArvoreNaoExiste ;
	} /* if */
	if ( pArvore->pNoCorr == NULL )
	{
		return ARV_CondRetArvoreVazia ;
	} /* if */
	* ValorParm = pArvore->pNoCorr->Valor ;

	* ChaveParm = pArvore->pNoCorr->Chave ;

	return ARV_CondRetOK ;

} /* Fim fun��o: ARV Obter valor corrente */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� da �rvore
*
*  $FV Valor retornado
*     Ponteiro para o n� criado.
*     Ser� NULL caso a mem�ria tenha se esgotado.
*     Os ponteiros do n� criado estar�o nulos e o valor � igual ao do
*     par�metro.
*
***********************************************************************/

tpNoArvore * CriarNo( char ValorParm , char ChaveParm )
{

	tpNoArvore * pNo ;

	pNo = ( tpNoArvore * ) malloc( sizeof( tpNoArvore )) ;
	if ( pNo == NULL )
	{
		return NULL ;
	} /* if */

	pNo->pNoPai = NULL ;
	pNo->pNoEsq = NULL ;
	pNo->pNoDir = NULL ;
	pNo->Valor  = ValorParm ;
	pNo->Chave  = ChaveParm ;

	return pNo ;

} /* Fim fun��o: ARV Criar n� da �rvore */


/***********************************************************************
*
*  $FC Fun��o: ARV Criar n� raiz da �rvore
*
*  $FV Valor retornado
*     ARV_CondRetOK
*     ARV_CondRetFaltouMemoria
*     ARV_CondRetNaoCriouRaiz
*
***********************************************************************/

ARV_tpCondRet CriarNoRaiz( char ValorParm , char ChaveParm )
{

	ARV_tpCondRet CondRet ;
	tpNoArvore * pNo ;

	if ( pArvore == NULL )
	{
		CondRet = ARV_CriarArvore( ) ;

		if ( CondRet != ARV_CondRetOK )
		{
			return CondRet ;
		} /* if */
	} /* if */

	if ( pArvore->pNoRaiz == NULL )
	{
		pNo = CriarNo( ValorParm , ChaveParm ) ;
		if ( pNo == NULL )
		{
			return ARV_CondRetFaltouMemoria ;
		} /* if */
		pArvore->pNoRaiz = pNo ;
		pArvore->pNoCorr = pNo ;

		return ARV_CondRetOK ;
	} /* if */

	return ARV_CondRetNaoCriouRaiz ;

} /* Fim fun��o: ARV Criar n� raiz da �rvore */


/***********************************************************************
*
*  $FC Fun��o: ARV Destruir a estrutura da �rvore
*
*  $EAE Assertivas de entradas esperadas
*     pNoArvore != NULL
*
***********************************************************************/

void DestroiArvore( tpNoArvore * pNo )
{

	if ( pNo->pNoEsq != NULL )
	{
		DestroiArvore( pNo->pNoEsq ) ;
	} /* if */

	if ( pNo->pNoDir != NULL )
	{
		DestroiArvore( pNo->pNoDir ) ;
	} /* if */

	free( pNo ) ;

} /* Fim fun��o: ARV Destruir a estrutura da �rvore */

/***********************************************************************
*
*  $FC Fun��o: ARV Conta o n�mero de n�s folha
*
*  $EAE Assertivas de entradas esperadas
*		arvore != NULL
*     
*  $FV Valor retornado
*		N�mero de n�s folha
*
***********************************************************************/

int contaNosFolha( tpNoArvore * arvore ) 
{
	if( arvore == NULL )
	{
		return 0 ;
	} /* if */
	if( arvore->pNoEsq == NULL && arvore->pNoDir ==NULL )
	{
		return 1;
	} /* if */
    else
	{
        return contaNosFolha( arvore->pNoEsq ) + contaNosFolha( arvore->pNoDir ) ;
	} /* else */

} /* Fim fun��o: ARV Conta o n�mero de n�s folha */

/***********************************************************************
*
*  $FC Fun��o: ARV Preenche vetor com os valores alfa 
*				num�ricos dos n�s folha
*
*  $EAE Assertivas de entradas esperadas
*		arvore != NULL
*     
***********************************************************************/

void preencheVetorNosFolha( tpNoArvore * pNo )
{
	if( pNo == NULL )
	{
		return ;
	} /* if */
	else if(pNo -> pNoEsq == NULL && pNo -> pNoDir == NULL)
	{
		nosFolha[index++] = pNo ;
		return;
	} /* else if */
	else
	{
		preencheVetorNosFolha( pNo -> pNoEsq);
		preencheVetorNosFolha( pNo -> pNoDir);
	} /* else */
} /* Fim fun��o: ARV Preenche vetor com os valores alfanum�ricos (Chave) dos n�s folha */

/***********************************************************************
*
*  $FC Fun��o: Compara caracteres
*		     
***********************************************************************/

static int comparaChar(const void * a, const void * b)
{
	tpNoArvore ** c1 = ( tpNoArvore ** ) a ; 
	tpNoArvore ** c2 = ( tpNoArvore ** ) b ;

	if( (* c1)->Chave < (* c2)->Chave ) 
	{
		return -1 ;
	} /* if */
	else if( (* c1)->Chave > (* c2)->Chave )
	{
		return 1 ;
	} /* else if */
	return 0 ;

} /* Fim fun��o: Compara caracteres */

/***********************************************************************
*
*  $FC Fun��o: Costura
*     
***********************************************************************/

void costura( tpArvore * arvore, tpNoArvore ** nosFolha , int numFolhas )
{
	for( index = 0; index < numFolhas -1 ; index++)
	{
		nosFolha[index] -> pNoCostura = nosFolha[index+1];
	} /* for */

} /* Fim fun��o: Costura */

/***********************************************************************
*
*  $FC Fun��o: Imprime os campos Chave do vetor nosFolha
*     
***********************************************************************/

void ImprimeVetorNosFolha( int numFolhas )
{
	printf("\n\t**A costura �:");

	for( index = 0 ; index < numFolhas ; index++ )
	{
		printf(" %c", nosFolha[index] -> Chave);
	} /* for */

} /* Fim fun��o: Imprime vetor nos folha */

/***********************************************************************
*
*  $FC Fun��o: Costurar �rvore
*     
*  $EAE Assertivas de entradas esperadas
*		ARV_CondRetArvoreNaoExiste
*		ARV_CondRetArvoreVazia
*		ARV_CondRetOK
*
***********************************************************************/

ARV_tpCondRet ARV_CosturaArvore( void )
{
	if ( pArvore == NULL )
	{
		return ARV_CondRetArvoreNaoExiste ;
	} /* if */
	if ( pArvore->pNoCorr == NULL )
	{
		return ARV_CondRetArvoreVazia ;
	} /* if */

	pArvore->pNoCorr = pArvore->pNoRaiz;

	numFolhas = contaNosFolha( pArvore->pNoCorr ) ;

	nosFolha = ( tpNoArvore ** ) malloc ( numFolhas * sizeof( tpNoArvore * ) ) ;

	preencheVetorNosFolha( pArvore->pNoCorr ) ;
	
	qsort( nosFolha , numFolhas , sizeof( tpNoArvore * ) , comparaChar ) ;

	costura( pArvore , nosFolha , numFolhas ) ;

	ImprimeVetorNosFolha( numFolhas ) ;

	return ARV_CondRetOK ;

} /* Fim fun��o: Costura �rvore */


/********** Fim do m�dulo de implementa��o: M�dulo �rvore **********/