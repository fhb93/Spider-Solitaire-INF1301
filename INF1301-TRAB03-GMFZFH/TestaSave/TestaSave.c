/***************************************************************************
*  $MCI M�dulo de implementa��o: TLIS Teste lista de s�mbolos
*
*  Arquivo gerado:             TestaSave.c
*  Letras identificadoras:      TSV
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes do m�dulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*	    1.0    gff   26/mai/2015 in�cio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include    "Carta.h"
#include	"PilhaDeCartas.h"
#include    "Save.h"


static const char SALVAR_SV_CMD[] = "=salvar";
static const char CARREGAR_SV_CMD[] = "=carregar";

LIS_tppCabeca * PrincTeste;

Crt * vetCartas[7];
Crt ** vetCartas2;
int vTam;

/**** Vari�vel flag, utilizada para garantir que a estrutura teste ser�
	inicializada apenas uma vez  ****/
int flag = 0;

/***** Prot�tipos das fun��es encapsuladas no m�dulo *****/

static void DestruirValor(void * pValor);
static void inicializa_estrutura(LIS_tppCabeca * Princ);

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/



TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	SV_tpCondRet CondRetObtido = SV_CondRetOK;
	SV_tpCondRet CondRetEsperada = SV_CondRetOK;
	/* inicializa para qualquer coisa */

	int numLidos = -1,
		CondRetEsp = -1;
	int i;
	
	
	if (flag == 0)
	{
		PrincTeste = LIS_CriaLista(DestruirValor);
		inicializa_estrutura(PrincTeste);
		flag++;
	}
	/* Testar Salvar Jogo */

	if (strcmp(ComandoTeste, SALVAR_SV_CMD) == 0)
	{
		numLidos = LER_LerParametros("i", &CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */

		CondRetObtido = SV_SaveGame(PrincTeste);

		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Condicao de retorno errada ao salvar");
	} /*    Fim da Ativa: Testar Salvar Jogo   */


	/*		Testar Carregar Jogo		*/
	else if (strcmp(ComandoTeste, CARREGAR_SV_CMD) == 0)
	{
		numLidos = LER_LerParametros("i", &CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */
		
		CondRetObtido = SV_LoadGame(PrincTeste);

		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condi��o de retorno errada ao carregar");
	}
	/*		Fim da Ativa: Carregar Jogo		*/
	
	return TST_CondRetNaoConhec;

} /* Fim fun��o: TSV  &Testar Save */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TBAR -Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim fun��o: Destruir valor */

/***********************************************************************
*
*  $FC Fun��o: Inicializa Estrutura
*
***********************************************************************/



void inicializa_estrutura(LIS_tppCabeca * Princ)
{
	LIS_tppCabeca * cb1, *cb2, *cb3, *cb4, *cb5, *cb6, *cb7, *cb8, *cb9, *cb10, *cb11, *cb12, *cb13, *cb14, *cb15, *cb16, *cb17;
	int conderro;

	cb1 = LIS_CriaLista(DestruirValor);
	cb2 = LIS_CriaLista(DestruirValor);
	cb3 = LIS_CriaLista(DestruirValor);
	cb4 = LIS_CriaLista(DestruirValor);
	cb5 = LIS_CriaLista(DestruirValor);
	cb6 = LIS_CriaLista(DestruirValor);
	cb7 = LIS_CriaLista(DestruirValor);
	cb8 = LIS_CriaLista(DestruirValor);
	cb9 = LIS_CriaLista(DestruirValor);
	cb10 = LIS_CriaLista(DestruirValor);
	cb11 = LIS_CriaLista(DestruirValor);
	cb12 = LIS_CriaLista(DestruirValor);
	cb13 = LIS_CriaLista(DestruirValor);
	cb14 = LIS_CriaLista(DestruirValor);
	cb15 = LIS_CriaLista(DestruirValor);
	cb16 = LIS_CriaLista(DestruirValor);
	cb17 = LIS_CriaLista(DestruirValor);

	LIS_InserirElementoAntes(Princ, cb17);
	LIS_InserirElementoAntes(Princ, cb16);
	LIS_InserirElementoAntes(Princ, cb15);
	LIS_InserirElementoAntes(Princ, cb14);
	LIS_InserirElementoAntes(Princ, cb13);
	LIS_InserirElementoAntes(Princ, cb12);
	LIS_InserirElementoAntes(Princ, cb11);
	LIS_InserirElementoAntes(Princ, cb10);
	LIS_InserirElementoAntes(Princ, cb9);
	LIS_InserirElementoAntes(Princ, cb8);
	LIS_InserirElementoAntes(Princ, cb7);
	LIS_InserirElementoAntes(Princ, cb6);
	LIS_InserirElementoAntes(Princ, cb5);
	LIS_InserirElementoAntes(Princ, cb4);
	LIS_InserirElementoAntes(Princ, cb3);
	LIS_InserirElementoAntes(Princ, cb2);
	LIS_InserirElementoAntes(Princ, cb1);
}
/* Fim fun��o: Inicializar Estrutura */

/********** Fim do m�dulo de implementa��o: TSV Testar Save **********/
