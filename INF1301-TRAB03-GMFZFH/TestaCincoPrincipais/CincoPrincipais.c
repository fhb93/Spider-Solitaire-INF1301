/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Cinco Principais
*
*  Arquivo gerado:              CincoPrincipais.c
*  Letras identificadoras:      MNT
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
*     O m�dulo Cinco Principais � usado para pedir cartas, ele
*	  pede o monte e distribui nas dez sequ�ncias
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>

#include "Lista.h"
#include "CincoPrincipais.h"
#include "Carta.h"
#include "PilhaDeCartas.h"



/***********************************************************************
*
*	Fun��o: MNT Pedir Monte
*
***********************************************************************/

MNT_tpCondRet MNT_PedeMonte(LIS_tppCabeca * cbseq, LIS_tppCabeca * cbmnt)
{
	LIS_tppLista * temp;

	Crt * carta;

	int i;

	temp = LIS_AcessaListaIni(cbmnt);

	CTA_AlteraEstado((Crt *)LIS_AcessaStruct(temp));
	CTA_AlteraSituacao((Crt *)LIS_AcessaStruct(temp));

	carta = PDCRT_Pop(cbmnt);

	PDCRT_Push(cbseq, carta);

	return MNT_CondRetOK;
} /* Fim fun��o: MNT Pedir Monte*/

/********** Fim do m�dulo de defini��o: M�dulo Cinco Principais **********/

