/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Save
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
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*       1.00   gff   13/04/2015 In�cio do desenvolvimento
*
*  $ED Descri��o do m�dulo
*     Contem as fun�oes carregar e salvar um jogo
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
	/* N�o conseguiu abrir o arquivo */

	SV_CondRetErroCriarArquivo = 2,
	/* N�o conseguiu criar o arquivo */

} SV_tpCondRet;

/***********************************************************************
*
*  $FC Fun��o: SV Save Game
*
*  $ED Descri��o da fun��o
*		Cria um arquivo texto com todos os dados referentes ao
*		andamento do jogo corrente
*
*	$EP	Par�metros
*		$P Princ - Cabe�a da estrutura principal
*
*	$FV Valor Retornado
*		SV_CondRetOK caso o arquivo de texto seja criado corretamente
*		SV_CondRetErroCriarArquivo caso por algum motivo n�o seja
*		poss�vel criar o arquivo de texto
*
***********************************************************************/
SV_tpCondRet SV_SaveGame(LIS_tppCabeca * Princ);


/***********************************************************************
*
*  $FC Fun��o: SV Save Game
*
*  $ED Descri��o da fun��o
*		L� o arquivo Save.txt encontrado na pasta do execut�vel
*		Cria um jogo com os dados encontrados no arquivo texto
*
*	$EP	Par�metros
*		$P Princ - Cabe�a da estrutura principal
*
*	$FV Valor Retornado
*		SV_CondRetOK caso o arquivo de texto seja criado corretamente
*		SV_CondRetErroAbrirArquivo caso por algum motivo o arquivo n�o
*		seja aberto (como n�o se encontrar na pasta por exemplo)
*
***********************************************************************/
SV_tpCondRet SV_LoadGame(LIS_tppCabeca * Princ);

/********** Fim do m�dulo de defini��o: M�dulo Baralho **********/
#endif

