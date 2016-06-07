/***************************************************************************
*  $MCI Módulo de implementação: TLIS Teste lista de símbolos
*
*  Arquivo gerado:             TestaSave.c
*  Letras identificadoras:      TSV
*
*  Nome da base de software:    Arcabouço para a automação de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatização dos testes do módulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Histórico de evolução:
*     Versão  Autor    Data     Observações
*	    1.0    gff   26/mai/2015 início desenvolvimento
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

/**** Variável flag, utilizada para garantir que a estrutura teste será
	inicializada apenas uma vez  ****/
int flag = 0;

/***** Protótipos das funções encapsuladas no módulo *****/

static void DestruirValor(void * pValor);
static void inicializa_estrutura(LIS_tppCabeca * Princ);

/*****  Código das funções exportadas pelo módulo  *****/



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
			"Condição de retorno errada ao carregar");
	}
	/*		Fim da Ativa: Carregar Jogo		*/
	
	return TST_CondRetNaoConhec;

} /* Fim função: TSV  &Testar Save */


/*****  Código das funções encapsuladas no módulo  *****/


/***********************************************************************
*
*  $FC Função: TBAR -Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim função: Destruir valor */

/***********************************************************************
*
*  $FC Função: Inicializa Estrutura
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
/* Fim função: Inicializar Estrutura */

/********** Fim do módulo de implementação: TSV Testar Save **********/
