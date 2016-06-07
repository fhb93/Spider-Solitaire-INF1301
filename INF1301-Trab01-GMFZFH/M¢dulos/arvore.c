/***************************************************************************
*  $MCI Módulo de implementação: Módulo árvore
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*		5.00 gmfzfh  24/03/2015 Reestruturação e correção
*		4.00 gmfzfh  18/03/2015 Início da implementação das funções
*								auxiliares da costura
*       3.00   avs   28/02/2003 Uniformização da interface das funções e
*                               de todas as condições de retorno.
*       2.00   avs   03/08/2002 Eliminação de código duplicado, reestruturação
*       1.00   avs   15/08/2001 Início do desenvolvimento
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
*  $TC Tipo de dados: ARV Descritor do nó da árvore
*
*
*  $ED Descrição do tipo
*     Descreve a organização do nó
*
***********************************************************************/

int	numFolhas = 0;

typedef struct tgNoArvore {

	struct tgNoArvore * pNoPai ;
	/* Ponteiro para pai
	*
	*$EED Assertivas estruturais
	*   É NULL sse o nó é raiz
	*   Se não for raiz, um de pNoEsq ou pNoDir de pNoPai do nó
	*   corrente apontam para o nó corrente */

	struct tgNoArvore * pNoEsq ;
	/* Ponteiro para filho à esquerda
	*
	*$EED Assertivas estruturais
	*   se pNoEsq do nó X != NULL então pNoPai de pNoEsq aponta para o nó X */

	struct tgNoArvore * pNoDir ;
	/* Ponteiro para filho à direita
	*
	*$EED Assertivas estruturais
	*   se pNoDir do nó X != NULL então pNoPai de pNoDir aponta para o nó X */

	struct tgNoArvore * pNoCostura ;	
	/* Ponteiro para costura
	*
	*$EED Assertivas estruturais
	*   Não é NULL se o nó é folha */

	char Valor ;
	/* Valor do nó */

	char Chave;
	/* Valor para alfanumerico */
} tpNoArvore ;

/***********************************************************************
*
*  $TC Tipo de dados: ARV Descritor da cabeça de uma árvore
*
*
*  $ED Descrição do tipo
*     A cabe‡a da árvore é o ponto de acesso para uma determinada árvore.
*     Por intermédio da referência para o nó corrente e do ponteiro
*     pai pode-se navegar a árvore sem necessitar de uma pilha.
*     Pode-se, inclusive, operar com a árvore em forma de co-rotina.
*
***********************************************************************/

typedef struct tgArvore {

	tpNoArvore * pNoRaiz ;
	/* Ponteiro para a raiz da árvore */

	tpNoArvore * pNoCorr ;
	/* Ponteiro para o nó corrente da árvore */

} tpArvore ;

/*****  Dados encapsulados no módulo  *****/

static tpArvore * pArvore = NULL ;
/* Ponteiro para a cabe‡a da árvore */

tpNoArvore ** nosFolha;
/* Vetor de ponteiros para estrutura da árvore */
int index = 0;
/* Variável utilizada como contador de loops */

/***** Protótipos das funções encapsuladas no módulo *****/

static tpNoArvore * CriarNo( char ValorParm , char ChaveParm ) ;

static ARV_tpCondRet CriarNoRaiz( char ValorParm , char ChaveParm ) ;

static void DestroiArvore( tpNoArvore * pNo ) ;

/*****  Código das funções exportadas pelo módulo  *****/

/***************************************************************************
*
*  Função: ARV Criar árvore
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

} /* Fim função: ARV Criar árvore */

/***************************************************************************
*
*  Função: ARV Destruir árvore
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

} /* Fim função: ARV Destruir árvore */

/***************************************************************************
*
*  Função: ARV Adicionar filho à esquerda
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

	/* Criar nó à esquerda de folha */

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

	/* Tratar não folha à esquerda */

	return ARV_CondRetNaoEhFolha ;

} /* Fim função: ARV Adicionar filho à esquerda */

/***************************************************************************
*
*  Função: ARV Adicionar filho à direita
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

	/* Criar nó à direita de folha */

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

	/* Tratar não folha à direita */

	return ARV_CondRetNaoEhFolha ;

} /* Fim função: ARV Adicionar filho à direita */

/***************************************************************************
*
*  Função: ARV Ir para nó pai
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

} /* Fim função: ARV Ir para nó pai */

/***************************************************************************
*
*  Função: ARV Ir para nó à esquerda
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

} /* Fim função: ARV Ir para nó à esquerda */

/***************************************************************************
*
*  Função: ARV Ir para nó à direita
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

} /* Fim função: ARV Ir para nó à direita */

/***************************************************************************
*
*  Função: ARV Obter valor corrente
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

} /* Fim função: ARV Obter valor corrente */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: ARV Criar nó da árvore
*
*  $FV Valor retornado
*     Ponteiro para o nó criado.
*     Será NULL caso a memória tenha se esgotado.
*     Os ponteiros do nó criado estarão nulos e o valor é igual ao do
*     parâmetro.
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

} /* Fim função: ARV Criar nó da árvore */


/***********************************************************************
*
*  $FC Função: ARV Criar nó raiz da árvore
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

} /* Fim função: ARV Criar nó raiz da árvore */


/***********************************************************************
*
*  $FC Função: ARV Destruir a estrutura da árvore
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

} /* Fim função: ARV Destruir a estrutura da árvore */

/***********************************************************************
*
*  $FC Função: ARV Conta o número de nós folha
*
*  $EAE Assertivas de entradas esperadas
*		arvore != NULL
*     
*  $FV Valor retornado
*		Número de nós folha
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

} /* Fim função: ARV Conta o número de nós folha */

/***********************************************************************
*
*  $FC Função: ARV Preenche vetor com os valores alfa 
*				numéricos dos nós folha
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
} /* Fim função: ARV Preenche vetor com os valores alfanuméricos (Chave) dos nós folha */

/***********************************************************************
*
*  $FC Função: Compara caracteres
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

} /* Fim função: Compara caracteres */

/***********************************************************************
*
*  $FC Função: Costura
*     
***********************************************************************/

void costura( tpArvore * arvore, tpNoArvore ** nosFolha , int numFolhas )
{
	for( index = 0; index < numFolhas -1 ; index++)
	{
		nosFolha[index] -> pNoCostura = nosFolha[index+1];
	} /* for */

} /* Fim função: Costura */

/***********************************************************************
*
*  $FC Função: Imprime os campos Chave do vetor nosFolha
*     
***********************************************************************/

void ImprimeVetorNosFolha( int numFolhas )
{
	printf("\n\t**A costura é:");

	for( index = 0 ; index < numFolhas ; index++ )
	{
		printf(" %c", nosFolha[index] -> Chave);
	} /* for */

} /* Fim função: Imprime vetor nos folha */

/***********************************************************************
*
*  $FC Função: Costurar árvore
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

} /* Fim função: Costura árvore */


/********** Fim do módulo de implementação: Módulo árvore **********/