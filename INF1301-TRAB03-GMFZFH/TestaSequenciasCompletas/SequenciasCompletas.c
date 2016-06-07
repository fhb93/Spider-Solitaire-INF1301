/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo Sequ�ncias Completas
*
*  Arquivo gerado:              SequenciasCompletas.h
*  Letras identificadoras:      SEC
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
*     O m�dulo Sequ�ncias Completas analisa se h� sequ�ncias completas
*	  OBS: O caso de jogo finalizado � tratado no m�dulo Principal
*
***************************************************************************/

#include <stdio.h>
#include <string.h>

#include "SequenciasCompletas.h"
#include "Lista.h"
#include "Carta.h"
#include "PilhaDeCartas.h"


/***********************************************************************
*
*	Fun��o: SEC Verifica Sequ�ncias Completas
*
***********************************************************************/

SEC_tpCondRet SEC_VerificaSequenciasCompletas(LIS_tppCabeca * cbFonte, LIS_tppCabeca * cbDestino)
{
	LIS_tppLista * temp;
	int cont = 0, i;
	Crt * carta;

	for (temp = LIS_AcessaListaIni(cbFonte); strcmp(CTA_AcessaValor((Crt *)LIS_AcessaStruct(temp)), "A") != 0; temp = LIS_Proximo(temp))
	{
		if (LIS_Proximo(temp) == NULL)
		{
			return SEC_CondRetSemSequenciasCompletas;
		} /* if */
	} /* for */

	while ((LIS_Proximo(temp) != NULL) && (CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(temp))) + 1 == CTA_VerificaValor(CTA_AcessaValor((Crt *)LIS_AcessaStruct(LIS_Proximo(temp))))))
	{
		if (CTA_AcessaSituacao(((Crt *)LIS_AcessaStruct(temp))) == 1 && CTA_AcessaEstado(((Crt *)LIS_AcessaStruct(temp))) == 1)
		{
			if ((CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(temp))) == (CTA_AcessaNaipe((Crt *)LIS_AcessaStruct(LIS_Proximo(temp)))))
			{
				cont++;
				temp = LIS_Proximo(temp);
			} /* if */
			else
			{
				break;
			} /* if */
		} /* if */
		else
		{
			break;
		} /* if */
	} /* while */

	if (cont == 12)
	{
		for (i = 0; i < (cont + 1); i++)
		{
			carta = PDCRT_Pop(cbFonte);

			PDCRT_Push(cbDestino, carta);
		}
	} /* if */
	else
	{
		return SEC_CondRetSemSequenciasCompletas;
	} /* if */

	return SEC_CondRetOK;
} /* Fim fun��o: SEC Verifica Sequ�ncias Completas */

/********** Fim do m�dulo de defini��o: M�dulo Sequ�ncias Completas **********/