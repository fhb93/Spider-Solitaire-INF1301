/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Carta
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     Contém a estrutura correspondente a uma carta	
*	  e as funções utilizadas para acessar, verificar 
*     e alterar seus campos.
*
***************************************************************************/

#ifndef CARTA_H_
#define CARTA_H_

/***********************************************************************
*
*  $TC Tipo de dados: CTA Descritor do nó de carta
*
***********************************************************************/

typedef struct carta Crt ;


typedef enum {

	CRT_CondRetOK = 0 ,
	/* Concluiu corretamente */

	CRT_CondRetCartaVazia = 1
	/* A Carta não contém elementos */

} CRT_tpCondRet ;

/***********************************************************************
*
*	Função: CTA Criar uma nova carta
*
*  $ED Descrição da função
*     Cria uma carta 
*
*  $EP Parâmetros
*     $P valor[] - recebe uma string para valor
*	  $P naipe - recebe um char referente ao naipe
*     $P estado - recebe um inteiro para estado da carta
*     $P vsituacao - recebe inteiro para situação da carta
*
*  $FV Valor retornado
*     Retorna a Carta criada
*
***********************************************************************/

Crt * CTA_CriaCarta ( char valor[] , char naipe , int estado , int situacao ) ;

/***********************************************************************
*
*	Função: CTA Acessa valor de uma carta
*
*  $ED Descrição da função
*     Acessa o valor de uma Carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
*  $FV Valor retornado
*     Retorna um ponteiro pro primeiro elemento de uma string
*	  referente ao valor da carta enviada como parâmetro
*
***********************************************************************/

char * CTA_AcessaValor ( Crt * crt ) ;

/***********************************************************************
*
*	Função: CTA Acessa naipe de uma carta
*
*  $ED Descrição da função
*     Acessa o naipe de uma Carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
*  $FV Valor retornado
*     Retorna um char referente ao naipe da carta enviada
*	  como parâmetro
*
***********************************************************************/

char CTA_AcessaNaipe ( Crt * crt ) ;

/***********************************************************************
*
*	Função: CTA Acessa estado de uma carta
*
*  $ED Descrição da função
*     Acessa o estado de uma Carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao estado da Carta enviada
*	  como parâmetro
*
***********************************************************************/

int CTA_AcessaEstado ( Crt * crt ) ;

/***********************************************************************
*
*	Função: CTA Acessa situação de uma carta
*
*  $ED Descrição da função
*     Acessa a situação de uma Carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
*  $FV Valor retornado
*     Retorna um inteiro referente a situação da Carta enviada
*	  como parâmetro
*
***********************************************************************/

int CTA_AcessaSituacao ( Crt * crt ) ;

/***********************************************************************
*
*	Função: CTA Verificar naipe de uma carta
*
*  $ED Descrição da função
*     Verifica o naipe
*
*  $EP Parâmetros
*	  $P naipe_desejado - recebe um char referente ao naipe
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao naipe
*
***********************************************************************/

int CTA_VerificaNaipe( char naipe_desejado ) ;    

/***********************************************************************
*
*	Função: CTA Converter valor de uma carta
*
*  $ED Descrição da função
*     Verifica o valor
*
*  $EP Parâmetros
*	  $P * valor - recebe uma string referente ao valor
*
*  $FV Valor retornado
*     Retorna um inteiro referente ao valor
*
***********************************************************************/

int CTA_VerificaValor( char * valor ) ;

/***********************************************************************
*
*	Função: CTA Converter valor de uma carta
*
*  $ED Descrição da função
*     Associa um inteiro ao valor de uma carta
*
*  $EP Parâmetros
*	  $P num - recebe um int referente a um valor de carta
*
*  $FV Valor retornado
*     Retorna um ponteiro pro primeiro elemento de uma string
*	  referente ao inteiro enviado
*
***********************************************************************/

char * CTA_ConverteValor ( int num ) ;

/***********************************************************************
*
*	Função: CTA Alterar situação de uma carta
*
*  $ED Descrição da função
*     Altera a situação de uma carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraSituacao( Crt * crt ) ;

/***********************************************************************
*
*	Função: CTA Alterar estado de uma carta
*
*  $ED Descrição da função
*     Altera o estado de uma carta
*
*  $EP Parâmetros
*	  $P crt - recebe uma Carta que será acessada
*
***********************************************************************/

CRT_tpCondRet CTA_AlteraEstado( Crt * crt ) ;

void CTA_DestroiCarta(Crt * cta);

/********** Fim do módulo de definição: Módulo Carta **********/

#endif