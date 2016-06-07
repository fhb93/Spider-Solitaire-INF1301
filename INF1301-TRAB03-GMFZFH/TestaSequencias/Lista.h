/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Lista
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contem as funçoes para criação e manipulação de uma Lista
*	  duplamente encadeada com cabeça
*
***************************************************************************/

#ifndef LISTA_H_
#define LISTA_H_

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
	/* A lista não contém elementos */

	LIS_CondRetFimLista = 2,
	/* Foi atingido o fim de lista */

	LIS_CondRetFaltouMemoria = 3,
	/* Faltou memória ao tentar criar um elemento de lista */

	LIS_CondRetNaoAchou = 4,
	/* A busca não encontrou o valor desejado na lista */

	LIS_CondRetListaInexistente = 5
	/*  A Lista manipulada não existe  */

} LIS_tpCondRet;


/***********************************************************************
*
*  $FC Função: LIS Criar lista
*
*  $ED Descrição da função
*     Cria uma lista genérica duplamente encadeada.
*     Os possíveis tipos são desconhecidos a priori.
*     A tipagem é implicita.
*     Não existe identificador de tipo associado à lista.
*
*  $EP Parâmetros
*     ExcluirValor  - ponteiro para a função que processa a
*                     exclusão do valor referenciado pelo elemento
*                     a ser excluído.
*                     Ver descrição do módulo.
*
*  $FV Valor retornado
*     Se executou corretamente retorna o ponteiro para a lista.
*     Este ponteiro será utilizado pelas funções que manipulem esta lista.
*
*     Se ocorreu algum erro, por exemplo falta de memória ou dados errados,
*     a função retornará NULL.
*     Não será dada mais informação quanto ao problema ocorrido.
*
***********************************************************************/

LIS_tppCabeca * LIS_CriaLista(void(*ExcluirValor) (void * pDado));

/***********************************************************************
*
*  $FC Função: LIS Destroi Lista
*
*  $ED Descrição da função
*     Destrói a lista fornecida.
*     O parâmetro ponteiro para a lista não é modificado.
*     Se ocorrer algum erro durante a destruição, a lista resultará
*     estruturalmente incorreta.
*     OBS. não existe previsão para possíveis falhas de execução.
*
*  $FV Valor retornado
*     LIS_CondRetOK    - destruiu sem problemas
*
***********************************************************************/

LIS_tpCondRet LIS_DestroiLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Esvazia Lista
*
*  $ED Descrição da função
*     Elimina todos os elementos, sem contudo eliminar a lista
*
*  $EP Parâmetros
*     cb - ponteiro para a lista a ser esvaziada
*
***********************************************************************/

void LIS_EsvaziarLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Insere Elemento Antes
*
*  $ED Descrição da função
*     Insere novo elemento antes do elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâmetros
*     cb - ponteiro para a lista onde deve ser inserido o elemento
*     pValor - ponteiro para o valor do novo elemento
*              Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetFaltouMemoria
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes(LIS_tppCabeca * cb, void * pValor);

/***********************************************************************
*
*  $FC Função: LIS Insere Elemento Após
*
*  $ED Descrição da função
*     Insere novo elemento apás o elemento corrente.
*     Caso a lista esteja vazia, insere o primeiro elemento da lista.
*
*  $EP Parâmetros
*     Parâmetros
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

LIS_tpCondRet LIS_InserirElementoApos(LIS_tppCabeca * cb, void * pValor);

/***********************************************************************
*
*  $FC Função: LIS Exclui Elemento
*
*  $ED Descrição da função
*     Exclui o elemento corrente da lista dada.
*     Se existir o elemento aa esquerda do corrente será o novo corrente.
*     Se não existir e existir o elemento à direita, este se tornará corrente.
*     Se este também não existir a lista tornou-se vazia.
*
*  $EP Parâmetros
*     cb - ponteiro para a lista na qual deve excluir.
*
*  $FV Valor retornado
*     LIS_CondRetOK
*     LIS_CondRetListaVazia
*
***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Obtém Valor Contido no Elemento
*
*  $ED Descrição da função
*     Obtem a referência para o valor contido no elemento corrente da lista
*
*  $EP Parâmetros
*     cb - ponteiro para a lista de onde se quer o valor
*
*  $FV Valor retornado
*     não NULL - se o elemento corrente existe
*     NULL     - se a lista estiver vazia
*                Pode retornar NULL se o valor inserido no elemento for NULL.
*
***********************************************************************/

void * LIS_ObterValor(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Ir para o Elemento Incial
*
*  $ED Descrição da função
*     Torna corrente o primeiro elemento da lista.
*     Faz nada se a lista está vazia.
*
*  $EP Parâmetros
*     cb - ponteiro para a lista a manipular
*
***********************************************************************/

void LIS_IrInicioLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Ir para o Elemento Final
*
*  $ED Descrição da função
*     Torna corrente o elemento final da lista.
*     Faz nada se a lista está vazia.
*
*  $EP Parâmetros
*     cb - ponteiro para a lista a manipular
*
***********************************************************************/

void LIS_IrFinalLista(LIS_tppCabeca * cb);

/***********************************************************************
*
*  $FC Função: LIS Avaçar Elemento
*
*  $ED Descrição da função
*     Avança o elemento corrente numElem elementos na lista
*     Se numElem for positivo avança em direção ao final
*     Se numElem for negativo avança em direção ao início
*     numElem pode ser maior do que o númro de elementos existentes na
*               direção desejada
*     Se numElem for zero somente verifica se a lista está vazia
*
*  $EP Parâmetros
*     cb  - ponteiro para a lista a ser manipulada
*     numElem - o número de elementos a andar
*
*  $FV Valor retornado
*     CondRetOK         - se numElem elementos tiverem sido andados
*     CondRetFimLista   - se encontrou o fim da lista antes de andar numElem
*                         elementos
*     CondRetListaVazia - se a lista está vazia
*
***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente(LIS_tppCabeca * cb, int numElem);

/***********************************************************************
*
*  $FC Função: LIS Procura Elemento
*
*  $ED Descrição da função
*     Procura o elemento que referencia o valor dado.
*     A função compara ponteiro e não conteúdo apontado.
*
*  $EP Parâmetros
*     cb  - ponteiro para a lista onde procura
*     pValor  - ponteiro para o valor procurado
*               Pode ser NULL
*
*  $FV Valor retornado
*     LIS_CondRetOK  - se encontrou.
*                      O elemento corrente é o primeiro elemento do
*                      elemento corrente inclusive para o fim da lista
*                      e que contém o ponteiro procurado
*
*     LIS_CondRetNaoEncontrou - se o ponteiro não foi encontrado
*                      O elemento corrente continua o mesmo
*     LIS_CondRetListaVazia   - se a lista estiver vazia
*
***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor(LIS_tppCabeca * cb, void * pValor);

/***********************************************************************
*
*	Função: LIS Acessa o Início da Lista
*
*  $ED Descrição da função
*	   Acessa o primeiro elemento da Lista contida em uma
*	   determinada Cabeça
*
*  $EP Parâmetros
*     $P cb - recebe a Cabeça a qual deseja acessa o primeiro
*	  elemento da Lista
*
*  $FV Valor retornado
*     Retorna o primeiro elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_AcessaListaIni(LIS_tppCabeca * cb);

/***********************************************************************
*
*	Função: LIS Acessa o Fim da Lista
*
*  $ED Descrição da função
*	   Acessa o último elemento da Lista contida em uma
*	   determinada Cabeça
*
*  $EP Parâmetros
*     $P cb - recebe a Cabeça a qual deseja acessa o último
*	  elemento da Lista
*
*  $FV Valor retornado
*     Retorna o último elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_AcessaListaFim(LIS_tppCabeca * cb);

/***********************************************************************
*
*	Função: LIS Aponta para Próximo
*
*  $ED Descrição da função
*	   Aponta para o próximo elemento da Lista
*
*  $EP Parâmetros
*     $P lst - recebe a Lista a qual deseja apontar para
*	  o próximo elemnto
*
*  $FV Valor retornado
*     Retorna o próximo elemento da Lista
*
***********************************************************************/

LIS_tppLista * LIS_Proximo(LIS_tppLista * lst);

/***********************************************************************
*
*	Função: LIS Aponta para Anterior
*
*  $ED Descrição da função
*	   Aponta para o elemento anterior da Lista
*
*  $EP Parâmetros
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
*	Função: LIS Acessa Struct
*
*  $ED Descrição da função
*	   Acessa a estrutura contida na atual posição da Lista
*
*  $EP Parâmetros
*     $P lst - recebe a Cabeça a qual deseja procurar a Carta
*
***********************************************************************/

void * LIS_AcessaStruct(LIS_tppLista * lst);

/*****************************************************
*
*	Função: LIS Acessa Número de Elementos
*	$ED Descrição da função
*		Descobre a quantidade de nós contidos na lista para a qual
*		a cabeça passada aponta
*
*	$EP Parâmetros
*		$P cb - recebe a Cabeca a qual deseja acessar o número de elementos
*
*	$FV	Valor Retornado
*		Retorna a quantidade de nós contidos na lista para a qual
*		a cabeça aponta
****************************************************/
int LIS_AcessaNumElem(LIS_tppCabeca * cb);

/********** Fim do módulo de definição: Módulo Lista **********/

#endif