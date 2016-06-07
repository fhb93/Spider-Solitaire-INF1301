/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Lista
*
*  Arquivo gerado:              Lista.h
*  Letras identificadoras:      LIS
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
*     Contem as fun�oes para cria��o e manipula��o de uma Lista
*	  duplamente encadeada com cabe�a
*
***************************************************************************/

#ifndef LISTA_H_
#define LISTA_H_

#ifdef _DEBUG
#include "CONTA.H"
#include "CESPDIN.H"
#endif

typedef struct cabeca LIS_tppCabeca;

typedef struct lista LIS_tppLista;

/***********************************************************************
*
*  $TC Tipo de dados: MNT Condicoes de retorno
*
*
***********************************************************************/

typedef enum {

	LIS_CondRetOK = 0,
	/* Concluiu corretamente */

	LIS_CondRetListaVazia = 1,
	/* A lista n�o cont�m elementos */

	LIS_CondRetFimLista = 2,
	/* Foi atingido o fim de lista */

	LIS_CondRetNaoAchou = 3,
	/* N�o encontrou o valor procurado */

	LIS_CondRetFaltouMemoria = 4
	/* Faltou mem�ria ao tentar criar um elemento de lista */

} LIS_tpCondRet;


/***********************************************************************
*
*  $FC Fun��o: LIS Criar lista
*
*  $ED Descri��o da fun��o
*     Cria uma lista gen�rica duplamente encadeada.
*     Os poss�veis tipos s�o desconhecidos a priori.
*     A tipagem � implicita.
*     N�o existe identificador de tipo associado � lista.
*
*  $EP Par�metros
*     ExcluirValor  - ponteiro para a fun��o que processa a
*                     exclus�o do valor referenciado pelo elemento
*                     a ser exclu�do.
*                     Ver descri��o do m�dulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro ser� utilizado pelas fun��es que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de mem�ria ou dados errados,
*     a fun��o retornar� NULL.
*     N�o ser� dada mais informa��o quanto ao problema ocorrido.
*
***********************************************************************/

LIS_tppCabeca * LIS_CriaLista(
	void(*ExcluirValor) (void * pDado)
#ifdef _DEBUG 
	, char tipoElemento
#endif
	);
/***********************************************************************
*
*  $FC Fun��o: LIS Destroi Lista
*
*  $ED Descri��o da fun��o
*     Destr�i a lista fornecida.
*     O par�metro ponteiro para a lista n�o � modificado.
*     Se ocorrer algum erro durante a destrui��o, a lista resultar�
*     estruturalmente incorreta.
*     OBS. n�o existe previs�o para poss�veis falhas de execu��o.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

LIS_tpCondRet LIS_DestroiLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Esvazia Lista
*
*  $ED Descri��o da fun��o
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Par�metros
*     cb - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

void LIS_EsvaziarLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Insere Elemento Antes
*
*  $ED Descri��o da fun��o
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     cb - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetFaltouMemoria
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes(LIS_tppCabeca * cb, void * pValor
#ifdef _DEBUG
	, char tipoElemento
#endif
	);



/***********************************************************************
*
*  $FC Fun��o: LIS Acessa Elemento Corrente
*
*  $ED Descri��o da fun��o
*     Acessa o elemento corrente da Lista, por meio da cabe�a da mesma
*
*  $EP Par�metros
*     cb - ponteiro para a lista a ser esvaziada
*
*	$FV Valor retornado
*	  retorna o elemento corrente da lista 	
*
***********************************************************************/

LIS_tppLista * LIS_AcessaElementoCorrente(LIS_tppCabeca * cb);


/***********************************************************************
*
*  $FC Fun��o: LIS Insere Elemento Ap�s
*
*  $ED Descri��o da fun��o
*     Insere novo elemento ap�s o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Par�metros
*     Par�metros
*        cb - ponteiro para a lista onde deve ser inserido o elemento
*        pValor - ponteiro para o valor do novo elemento
*                 Pode ser NULL
*
*  $FV Valor retornado
*     Valor retornado
*        LTS_CondRetOK
*        LTS_CondRetFaltouMemoria
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoApos(LIS_tppCabeca * cb, void * pValor
#ifdef _DEBUG
	, char tipoElemento
#endif
	);

/***********************************************************************
*
*  $FC Fun��o: LIS Exclui Elemento
*
*  $ED Descri��o da fun��o
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente ser� o novo corrente.
*     Se n�o existir e existir o elemento � direita, este se tornar� corrente.
*     Se este tamb�m n�o existir a lista tornou-se vazia.
*
*  $EP Par�metros
*     cb - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento(LIS_tppCabeca * cb
#ifdef _DEBUG
	, int qtdLiberar
#endif
	);

/***********************************************************************
*
*  $FC Fun��o: LIS Obt�m Valor Contido no Elemento
*
*  $ED Descri��o da fun��o
*     Obtem a refer�ncia para o valor contido no elemento corrente da lista
*
*  $EP Par�metros
*     cb - ponteiro para a lista de onde se quer o valor
*
*  $FV Valor retornado
*     n�o NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

void * LIS_ObterValor(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Ir para o Elemento Incial
*
*  $ED Descri��o da fun��o
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     cb - ponteiro para a lista a manipular
*
***********************************************************************/

void LIS_IrInicioLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Ir para o Elemento Final
*
*  $ED Descri��o da fun��o
*     Torna corrente o elemento final da lista.
*     Faz nada se a lista est� vazia.
*
*  $EP Par�metros
*     cb - ponteiro para a lista a manipular
*
***********************************************************************/

void LIS_IrFinalLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Ava�ar Elemento
*
*  $ED Descri��o da fun��o
*     Avan�a o elemento corrente numElem elementos na lista
*     Se numElem for positivo avan�a em dire��o ao final
*     Se numElem for negativo avan�a em dire��o ao in�cio
*     numElem pode ser maior do que o n�mro de elementos existentes na
*               dire��o desejada
*     Se numElem for zero somente verifica se a lista est� vazia
*
*  $EP Par�metros
*     cb  - ponteiro para a lista a ser manipulada
*     numElem - o n�mero de elementos a andar
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista est� vazia
*
***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente(LIS_tppCabeca * cb, int numElem);

/***********************************************************************
*
*  $FC Fun��o: LIS Procura Elemento
*
*  $ED Descri��o da fun��o
*     Procura o elemento que referencia o valor dado.
*     A fun��o compara ponteiro e n�o conte�do apontado.
*
*  $EP Par�metros
*     cb  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK  - se encontrou.
*                      O elemento corrente � o primeiro elemento do
*                      elemento corrente inclusive para o fim da lista
*                      e que cont�m o ponteiro procurado
*
*     LIS_CondRetNaoEncontrou - se o ponteiro n�o foi encontrado
*                      O elemento corrente continua o mesmo
*     LIS_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor(LIS_tppCabeca * cb, void * pValor);

/***********************************************************************
*
*	Fun��o: LIS Acessa o In�cio da Lista
*
*  $ED Descri��o da fun��o
*	   Acessa o primeiro elemento da Lista contida em uma
*	   determinada Cabe�a
*
*  $EP Par�metros
*     $P cb - recebe a Cabe�a a qual deseja acessa o primeiro
*	  elemento da Lista
*
*  $FV Valor retornado
*     Retorna o primeiro elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_AcessaListaIni(LIS_tppCabeca * cb);

/***********************************************************************
*
*	Fun��o: LIS Acessa o Fim da Lista
*
*  $ED Descri��o da fun��o
*	   Acessa o �ltimo elemento da Lista contida em uma
*	   determinada Cabe�a
*
*  $EP Par�metros
*     $P cb - recebe a Cabe�a a qual deseja acessa o �ltimo
*	  elemento da Lista
*
*  $FV Valor retornado
*     Retorna o �ltimo elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_AcessaListaFim(LIS_tppCabeca * cb);

/***********************************************************************
*
*	Fun��o: LIS Aponta para Pr�ximo
*
*  $ED Descri��o da fun��o
*	   Aponta para o pr�ximo elemento da Lista
*
*  $EP Par�metros
*     $P lst - recebe a Lista a qual deseja apontar para
*	  o pr�ximo elemnto
*
*  $FV Valor retornado
*     Retorna o pr�ximo elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_Proximo(LIS_tppLista * lst);

/***********************************************************************
*
*	Fun��o: LIS Aponta para Anterior
*
*  $ED Descri��o da fun��o
*	   Aponta para o elemento anterior da Lista
*
*  $EP Par�metros
*     $P lst - recebe a Lista a qual deseja apontar para
*	  o elemento anterior
*
*  $FV Valor retornado
*     Retorna o elemento anterior da Lista
*
***********************************************************************/

LIS_tppLista * LIS_Anterior(LIS_tppLista * lst);

/***********************************************************************
*
*	Fun��o: LIS Acessa Struct
*
*  $ED Descri��o da fun��o
*	   Acessa a estrutura contida na atual posi��o da Lista
*
*  $EP Par�metros
*     $P lst - recebe a Cabe�a a qual deseja procurar a Carta
*
***********************************************************************/

void * LIS_AcessaStruct(LIS_tppLista * lst);

/***********************************************************************
*
*	Fun��o: LIS AcessaNumElem
*
*  $ED Descri��o da fun��o
*	   acessa o n�mero de elementos da lista
*
*  $EP Par�metros
*     cb - recebe a Cabe�a a qual deseja acessa o n�mero
*	  de elementos da Lista
*
*  $FV Valor retornado
*     Retorna o n�mero inteiro de elementos na lista
*
***********************************************************************/

int LIS_AcessaNumElem(LIS_tppCabeca * cb);

#ifdef _DEBUG

/***********************************************************************
*
*  $FC Fun��o: LIS Preenche Lixo Sucessor.
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*     ponteiro - ponteiro que deseja alterar
*
*  $ED Descri��o da fun��o
*	  Percorre a lista preenchendo o ponteiro sucessor do elemento com lixo.
*
*
***********************************************************************/


void LIS_PreencheLixoSucessor(LIS_tppLista *pLista, LIS_tppLista **ponteiro) ;

/***********************************************************************
*
*  $FC Fun��o: LIS Preenche Lixo Predecessor.
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*     ponteiro - ponteiro que deseja alterar
*
*  $ED Descri��o da fun��o
*	  Percorre a lista preenchendo o ponteiro predecessor do elemento com lixo.
*
*
***********************************************************************/

void LIS_PreencheLixoPredecessor(LIS_tppLista *pLista, LIS_tppLista **ponteiro) ;

/***********************************************************************
*
*  $FC Fun��o: LIS Altera Ponteiro Sucessor.
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*     ponteiro - ponteiro do tipo void que deseja alterar
*
*  $ED Descri��o da fun��o
*	  Percorre a lista alterando o ponteiro sucessor do elemento dado.
*
*
***********************************************************************/

void LIS_AlteraPonteiroSucessor(LIS_tppLista *pLista, void *ponteiro);

/***********************************************************************
*
*  $FC Fun��o: LIS Altera Ponteiro Predecessor.
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*     ponteiro - ponteiro do tipo void que deseja alterar
*
*  $ED Descri��o da fun��o
*	  Percorre a lista alterando o ponteiro predecessor do elemento dado.
*
*
***********************************************************************/

void LIS_AlteraPonteiroPredecessor(LIS_tppLista *pLista, void *ponteiro);

/***********************************************************************
*
*  $FC Fun��o: LIS Free Parcial.
*
*  $EP Par�metros
*     cb - recebe a Cabe�a a qual deseja acessa o n�mero
*	  de elementos da Lista
*
*  $ED Descri��o da fun��o
*	  Destaca o elemento corrente sem dar free
*
*
***********************************************************************/


void LIS_FreeParcial(LIS_tppCabeca * cb) ;

/***********************************************************************
*
*  $FC Fun��o: LIS Nulo Origem .
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista definindo como Nulo o ponteiro para a origem.
*
*
***********************************************************************/

void LIS_NuloOrigem(LIS_tppCabeca* pCabeca);

/***********************************************************************
*
*  $FC Fun��o: LIS Altera Ponteiro Valor
*
*  $EP Par�metros
*		cb - recebe a Cabe�a a qual deseja acessa o n�mero
*			 de elementos da Lista
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista mudando o valor para o qual o ponteiro aponta
*
*
***********************************************************************/

void LIS_AlteraPonteiroValor(LIS_tppLista * pLista) ;

/***********************************************************************
*
*  $FC Fun��o: LIS Nulo Corrente .
*
*  $EP Par�metros
*     pLista - lista que deseja alterar.
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista definindo como Nulo o ponteiro para o no corrente.
*
*
***********************************************************************/

void LIS_NuloCorrente(LIS_tppCabeca* pCabeca);


/***********************************************************************
*
*  $FC Fun��o: LIS Altera Tipo Elemento No 
*
*  $EP Par�metros
*     cb - ponteiro para a cabe�a  
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista definindo como Nulo o ponteiro para a origem.
*
*
***********************************************************************/

void LIS_AlteraTipoElementoNo(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertiva do ponteiro para pr�ximo elemento
*
*  $EP Par�metros
*     pLista - lista que deseja verificar.
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se o ponteiro para proximo elemento
*	  no elemento corrente esta OK.
*
*
***********************************************************************/

int LIS_VerificaAssertivaProx(LIS_tppCabeca *pLista);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertiva do ponteiro para o elemento anterior
*
*  $EP Par�metros
*     pLista - lista que deseja verificar.
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se o ponteiro para elemento anterior
*	  no elemento corrente esta OK.
*
*
***********************************************************************/

int LIS_VerificaAssertivaAnt(LIS_tppCabeca *pLista);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertivas da Lista Vazia
*
*  $EP Par�metros
*     pLista - lista que deseja verificar.
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se as assertivas para uma lista vazia
*	  est�o OK.
*
*
***********************************************************************/

int LIS_VerificaAssertivaListaVazia(LIS_tppCabeca* pCabeca);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertivas da Lista com 1 elemento
*
*  $EP Par�metros
*     pLista - lista que deseja verificar.
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se as assertivas para uma lista com elementos unico
*	  est�o OK.
*
*
***********************************************************************/

int LIS_VerificaAssertivaListaElemUnico(LIS_tppCabeca* pCabeca);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertivas da Lista Preenchida
*
*  $EP Par�metros
*     pLista - lista que deseja verificar.
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se as assertivas para uma lista com mais de 1 elemento
*	  est�o OK.
*
***********************************************************************/

int LIS_VerificaAssertivaListaPreenchida(LIS_tppCabeca* pCabeca);

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica assertivas Tipo Lista Elementos
*
*  $EP Par�metros
*     pCabeca - ponteiro para a Cabeca da Lista
*
*  $FV Valor retornado
*	  int -> 0 ou 1
*
*  $ED Descri��o da fun��o
*	  Acessa a Lista verificando se as assertivas para o tipo de elemento
*	  da lista est�o OK.
*
***********************************************************************/



int LIS_VerificaAssertivaTipoListaElementos(LIS_tppCabeca* pCabeca);

#endif


/********** Fim do m�dulo de defini��o: M�dulo Lista **********/
#else
#endif