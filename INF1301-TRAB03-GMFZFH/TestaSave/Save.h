/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Save
*
*  Arquivo gerado:              Save.h
*  Letras identificadoras:      SV
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
*     Contem as funçoes carregar e salvar um jogo
*
***************************************************************************/

#ifndef SAVE_H_
#define SAVE_H_

#include "Lista.h"

/***********************************************************************
*
*  $TC Tipo de dados: SV Condicoes de retorno
*
***********************************************************************/

typedef enum {

	SV_CondRetOK = 0,
	/* Concluiu corretamente */

	SV_CondRetErroAbrirArquivo = 1,
	/* Não conseguiu abrir o arquivo */

	SV_CondRetErroCriarArquivo = 2,
	/* Não conseguiu criar o arquivo */

} SV_tpCondRet;

/***********************************************************************
*
*  $FC Função: SV Save Game
*
*  $ED Descrição da função
*		Cria um arquivo texto com todos os dados referentes ao
*		andamento do jogo corrente
*
*	$EP	Parâmetros
*		$P Princ - Cabeça da estrutura principal
*
*	$FV Valor Retornado
*		SV_CondRetOK caso o arquivo de texto seja criado corretamente
*		SV_CondRetErroCriarArquivo caso por algum motivo não seja
*		possível criar o arquivo de texto
*
***********************************************************************/
SV_tpCondRet SV_SaveGame(LIS_tppCabeca * Princ);


/***********************************************************************
*
*  $FC Função: SV Save Game
*
*  $ED Descrição da função
*		Lê o arquivo Save.txt encontrado na pasta do executável
*		Cria um jogo com os dados encontrados no arquivo texto
*
*	$EP	Parâmetros
*		$P Princ - Cabeça da estrutura principal
*
*	$FV Valor Retornado
*		SV_CondRetOK caso o arquivo de texto seja criado corretamente
*		SV_CondRetErroAbrirArquivo caso por algum motivo o arquivo não
*		seja aberto (como não se encontrar na pasta por exemplo)
*
***********************************************************************/
SV_tpCondRet SV_LoadGame(LIS_tppCabeca * Princ);

/********** Fim do módulo de definição: Módulo Baralho **********/
#endif

