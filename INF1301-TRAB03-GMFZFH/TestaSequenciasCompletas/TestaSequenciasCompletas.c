/***************************************************************************
*  $MCI Módulo de implementação: TSEC  Teste Sequências Completas
*
*  Arquivo gerado:             TestaSequenciasCompletas.c
*  Letras identificadoras:      TSEC
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes do módulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	   1.0     gff   26/mai/2015 início desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include	"TST_ESPC.H"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include    "Carta.h"
#include	"PilhaDeCartas.h"
#include	"SequenciasCompletas.h"
#include	"Sequencias.h"


#define DIM_VALOR     2 

static const char VERIFICASEQCOMP_SEC_CMD[] = "=verificarseqcomp";

LIS_tppCabeca * CabecaTeste;
LIS_tppCabeca * CabecaTeste2;
LIS_tppCabeca * CabecaTeste3;

Crt * vetCartas[13];
Crt * vetCartas2[92];
Crt * vetCartas3[1];
int vTam, index, Sequencia;

/*** Variável flag de controle para que a estrutura de teste seja inicializada
	apenas uma vez ***/
int flag = 0;


/***** Protótipos das funções encapsuladas no módulo *****/

static void DestruirValor(void * pValor);

/*****  Código das funções exportadas pelo módulo  *****/



TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	SEC_tpCondRet CondRetObtido = SEC_CondRetOK;
	SEC_tpCondRet CondRetEsperada = SEC_CondRetOK;
	/* inicializa para qualquer coisa */

	int numLidos = -1,
		CondRetEsp = -1;
	char NaipeDado;
	char ValorDado[DIM_VALOR];
	int i;

	if (flag == 0)
	{
		CabecaTeste = LIS_CriaLista(DestruirValor);
		CabecaTeste2 = LIS_CriaLista(DestruirValor);
		CabecaTeste3 = LIS_CriaLista(DestruirValor);

		vetCartas[0] = CTA_CriaCarta("A", 'e', 1, 1);
		vetCartas[1] = CTA_CriaCarta("2", 'e', 1, 1);
		vetCartas[2] = CTA_CriaCarta("3", 'e', 1, 1);
		vetCartas[3] = CTA_CriaCarta("4", 'e', 1, 1);
		vetCartas[4] = CTA_CriaCarta("5", 'e', 1, 1);
		vetCartas[5] = CTA_CriaCarta("6", 'e', 1, 1);
		vetCartas[6] = CTA_CriaCarta("7", 'e', 1, 1);
		vetCartas[7] = CTA_CriaCarta("8", 'e', 1, 1);
		vetCartas[8] = CTA_CriaCarta("9", 'e', 1, 1);
		vetCartas[9] = CTA_CriaCarta("10", 'e', 1, 1);
		vetCartas[10] = CTA_CriaCarta("J", 'e', 1, 1);
		vetCartas[11] = CTA_CriaCarta("Q", 'e', 1, 1);
		vetCartas[12] = CTA_CriaCarta("K", 'e', 1, 1);

		vetCartas3[0] = CTA_CriaCarta("K", 'e', 1, 1);
		
		for (index = 0; index < 91; index++)
		{
			vetCartas2[index] = CTA_CriaCarta("5", 'e', 1, 1);
			SEQ_InsereCartas(CabecaTeste2, vetCartas2, 92);
		}
		SEQ_InsereCartas(CabecaTeste, vetCartas, 13);
		SEQ_InsereCartas(CabecaTeste3, vetCartas3, 1);

		flag = 1;
	}
	
	
/* Testar Verificar Sequências Completas */

	if (strcmp(ComandoTeste, VERIFICASEQCOMP_SEC_CMD) == 0) 
	{
		numLidos = LER_LerParametros("ii",&Sequencia, &CondRetEsperada);

		if (numLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */

		if (Sequencia == 1)
		{
			CondRetObtido = SEC_VerificaSequenciasCompletas(CabecaTeste, CabecaTeste2);
		}
		else if (Sequencia == 2)
		{
			CondRetObtido = SEC_VerificaSequenciasCompletas(CabecaTeste3, CabecaTeste2);
		}
		else
		{
			return TST_CondRetParm;
		}
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Condicao de retorno errada ao verificar sequência completa");
	} /*    Fim da Ativa: Testar Verificar Sequências Completas   */

	
	return TST_CondRetNaoConhec;

} /* Fim função: TSEC &Testar Sequências Completas */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim função: Destruir valor */


/********** Fim do módulo de implementação: TSEC Teste Sequências Completas **********/
