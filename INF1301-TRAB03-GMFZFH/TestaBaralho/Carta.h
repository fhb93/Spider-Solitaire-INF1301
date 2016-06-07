/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Carta
*
*  Arquivo gerado:              Carta.h
*  Letras identificadoras:      CTA
*
*  Nome da base de software:    Jogo Paciencia Spider
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
*     Cont�m a estrutura correspondente a uma carta
*	  e as fun��es utilizadas para acessar, verificar
*     e alterar seus campos.
*
***************************************************************************/

#ifndef CARTA_H_
#define CARTA_H_

/***********************************************************************
*
*  $TC Tipo de dados: CTA Descritor do n� de carta
*
***********************************************************************/

typedef struct carta Crt;


typedef enum {

	CRT_CondRetOK = 0,
	/* Concluiu corretamente */

	CRT_CondRetCartaVazia = 1
	/* A Carta n�o cont�m elementos */

} CRT_tpCondRet;

/***********************************************************************
*
*	Fun��o: CTA Criar uma nova carta
*
*  $ED Descri��o da fun��o
*     Cria uma carta
*
*  $EP Par�metros
*     $P valor[] - recebe uma string para valor
*	  $P naipe - recebe um char referente ao naipe
*     $P estado - recebe um inteiro para estado da carta
*     $P vsituacao - recebe inteiro para situa��o da carta
*
*  $FV Valor retornado
*     Retorna a Carta criada
*
***********************************************************************/

Crt * CTA_CriaCarta(char valor[], char naipe, int estado, int situacao);

/***********************************************************************
*
*	Fun��o: CTA Acessa valor de uma carta
*
*  $ED Descri��o da fun��o
*     Acessa o valor de uma Carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
*  $FV Valor retornado
*     Retorna um ponteiro pro primeiro elemento de uma string
*	  referente ao valor da carta enviada como par�metro
*
***********************************************************************/

char * CTA_AcessaValor(Crt * crt);

/***********************************************************************
*
*	Fun��o: CTA Acessa naipe de uma carta
*
*  $ED Descri��o da fun��o
*     Acessa o naipe de uma Carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
*  $FV Valor retornado
*     Retorna um char referente ao naipe da carta enviada
*	  como par�metro
*
***********************************************************************/

char CTA_AcessaNaipe(Crt * crt);

/***********************************************************************
*
*	Fun��o: CTA Acessa estado de uma carta
*
*  $ED Descri��o da fun��o
*     Acessa o estado de uma Carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao estado da Carta enviada
*	  como par�metro
*
***********************************************************************/

int CTA_AcessaEstado(Crt * crt);

/***********************************************************************
*
*	Fun��o: CTA Acessa situa��o de uma carta
*
*  $ED Descri��o da fun��o
*     Acessa a situa��o de uma Carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
*  $FV Valor retornado
*     Retorna um inteiro referente a situa��o da Carta enviada
*	  como par�metro
*
***********************************************************************/

int CTA_AcessaSituacao(Crt * crt);

/***********************************************************************
*
*	Fun��o: CTA Verificar naipe de uma carta
*
*  $ED Descri��o da fun��o
*     Verifica o naipe
*
*  $EP Par�metros
*	  $P naipe_desejado - recebe um char referente ao naipe
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao naipe
*
***********************************************************************/

int CTA_VerificaNaipe(char naipe_desejado);

/***********************************************************************
*
*	Fun��o: CTA Converter valor de uma carta
*
*  $ED Descri��o da fun��o
*     Verifica o valor
*
*  $EP Par�metros
*	  $P * valor - recebe uma string referente ao valor
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao valor
*
***********************************************************************/

int CTA_VerificaValor(char * valor);

/***********************************************************************
*
*	Fun��o: CTA Converter valor de uma carta
*
*  $ED Descri��o da fun��o
*     Associa um inteiro ao valor de uma carta
*
*  $EP Par�metros
*	  $P num - recebe um int referente a um valor de carta
*
*  $FV Valor retornado
*     Retorna um ponteiro pro primeiro elemento de uma string
*	  referente ao inteiro enviado
*
***********************************************************************/

char * CTA_ConverteValor(int num);

/***********************************************************************
*
*	Fun��o: CTA Alterar situa��o de uma carta
*
*  $ED Descri��o da fun��o
*     Altera a situa��o de uma carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraSituacao(Crt * crt);

/***********************************************************************
*
*	Fun��o: CTA Alterar estado de uma carta
*
*  $ED Descri��o da fun��o
*     Altera o estado de uma carta
*
*  $EP Par�metros
*	  $P crt - recebe uma Carta que ser� acessada
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraEstado(Crt * crt);

/********** Fim do m�dulo de defini��o: M�dulo Carta **********/

#endif