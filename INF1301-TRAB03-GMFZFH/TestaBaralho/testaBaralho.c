/***************************************************************************
*  $MCI M�dulo de implementa��o: TLIS Teste lista de s�mbolos
*
*  Arquivo gerado:              testaBaralho.c
*  Letras identificadoras:      TBAR
*
*  Nome da base de software:    Arcabou�o para a automa��o de testes de programas redigidos em C
*  Arquivo da base de software: D:\AUTOTEST\PROJETOS\LISTA.BSW
*
*  Projeto: INF 1301 / 1628 Automatiza��o dos testes do m�dulo Baralho
*  Autores: gff	- Gabriel Maia, Felipe Holanda, Felipe Zarattini
*
*  $HA Hist�rico de evolu��o:
*     Vers�o  Autor    Data     Observa��es
*
*
*
*     1       gff   25/mai/2015 in�cio desenvolvimento
*
***************************************************************************/

#include    <string.h>
#include    <stdio.h>
#include    <malloc.h>

#include    "TST_Espc.h"

#include    "Generico.h"
#include    "LerParm.h"

#include    "Lista.h"
#include    "Baralho.h"

static const char CRIAR_BAR_CMD[] = "=criarbaralho";
static const char EMBARALHAR_CMD[] = "=embaralhar";
static const char DISTRIBUIR_CMD[] = "=distribuir";

LIS_tppCabeca * CabecaTeste;
LIS_tppCabeca * CabecaTeste2;

/***** Prot�tipos das fun��es encapuladas no m�dulo *****/

static void DestruirValor(void * pValor);

/*****  C�digo das fun��es exportadas pelo m�dulo  *****/


TST_tpCondRet TST_EfetuarComando(char * ComandoTeste)
{
	BAR_tpCondRet CondRetObtido = BAR_CondRetOK;
	BAR_tpCondRet CondRetEsperada = BAR_CondRetFaltouMemoria;
	/* inicializa para qualquer coisa */
	int modo = -1,
		numLidos = -1,
		CondRetEsp = -1,
		Quant = -1;

	int i;

	/* Testar Criar Baralho */

	if (strcmp(ComandoTeste, CRIAR_BAR_CMD) == 0)
	{
		numLidos = LER_LerParametros("ii",
			&modo, &CondRetEsperada);
		

		if (numLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */

		CabecaTeste = LIS_CriaLista(DestruirValor);

		if (CabecaTeste == NULL)
		{
			CondRetObtido = BAR_CondRetFaltouMemoria;
		} /* if */

		else if ((modo < 0) || (modo > 4))
		{
			CondRetObtido = BAR_CondRetModoDeCriacaoInexistente;
		} /* if */

		else
		{
			CondRetObtido = BAR_CriaBaralho(CabecaTeste, modo);
		}
		return TST_CompararInt(CondRetEsperada, CondRetObtido,
			"Condicao de retorno errada ao criar o baralho.");
	} /*    Fim da Ativa: Testar Criar Baralho    */


	/*		Testar Embaralhar		*/
	else if (strcmp(ComandoTeste, EMBARALHAR_CMD) == 0)
	{
		numLidos = LER_LerParametros("i",
			&CondRetEsperada);

		if (numLidos != 1)
		{
			return TST_CondRetParm;
		} /* if */


		CondRetObtido = BAR_Embaralhar(CabecaTeste);

		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao embaralhar.");

	}
	/*		Fim da Ativa: Testar Embaralhar		*/

	/*		Testar Distribuir Baralho		*/
	else if (strcmp(ComandoTeste, DISTRIBUIR_CMD) == 0)
	{
		numLidos = LER_LerParametros("ii", &Quant,
			&CondRetEsperada);

		if (numLidos != 2)
		{
			return TST_CondRetParm;
		} /* if */


		CabecaTeste2 = LIS_CriaLista(DestruirValor);
		if (CabecaTeste2 == NULL)
		{
			CondRetObtido = BAR_CondRetFaltouMemoria;
		}
		else if (CabecaTeste == NULL)
		{
			CondRetObtido = BAR_CondRetBaralhoInexistente;
		}
		else{
			CondRetObtido = BAR_DistribuiBaralho(CabecaTeste, CabecaTeste2, Quant);
		}

		return TST_CompararInt(CondRetObtido, CondRetEsperada,
			"Condicao de retorno errada ao distribuir baralho.");

	}
	/*		Fim da Ativa: Testar Distribuir Baralho		*/



	return TST_CondRetNaoConhec;

} /* Fim fun��o: TBAR &Testar Baralho */


/*****  C�digo das fun��es encapsuladas no m�dulo  *****/


/***********************************************************************
*
*  $FC Fun��o: TBAR Destruir valor
*
***********************************************************************/

void DestruirValor(void * pValor)
{

	free(pValor);

} /* Fim fun��o: TBAR Destruir valor */


/********** Fim do m�dulo de implementa��o: TBAR Teste Baralho **********/
