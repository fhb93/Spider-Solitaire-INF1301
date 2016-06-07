/***************************************************************************
*
*  $MCD Módulo de definição: Módulo Cinco Principais
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
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*       1.00   gff   13/04/2015 Início do desenvolvimento
*
*  $ED Descrição do módulo
*     O módulo Cinco Principais é usado para pedir cartas, ele
*	  pede o monte e distribui nas dez sequências
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
*	Função: MNT Pedir Monte
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
} /* Fim função: MNT Pedir Monte*/

/********** Fim do módulo de definição: Módulo Cinco Principais **********/

