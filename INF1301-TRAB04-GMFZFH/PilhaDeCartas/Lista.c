/***************************************************************************
*
*  $MCD M�dulo de defini��o: M�dulo tpLista
*
*  Arquivo gerado:              Lista.c
*  Letras identificadoras:      LIS
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
*     O m�dulo Lista � usado para a cria��o de Listas duplamente
*	  encadeadas com cabe�a, al�m de conter fun�oes de manipula��o
*	  e acesso da mesma
*
***************************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "Lista.h"

#ifdef _DEBUG

#include "CONTA.H"
#include "CESPDIN.H"

#endif

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de tpLista
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o de uma lista duplamente encadeada
*
***********************************************************************/

typedef struct lista
{
	void * pValor;
	/* Ponteiro para o valor contido no elemento */

	struct lista * pAnt;
	/* Ponteiro para o elemento predecessor */

	struct lista * pProx;
	/* Ponteiro para o elemento sucessor */

#ifdef _DEBUG
	char tipoElemento;
#endif

} tpLista;

/***********************************************************************
*
*  $TC Tipo de dados: LIS Descritor de Cabe�a
*
*  $ED Descri��o do tipo
*     Descreve a organiza��o de uma cabe�a
*
***********************************************************************/

typedef struct cabeca
{
	tpLista * pOrigemLista;
	/* Ponteiro para a origem da lista */

	tpLista * pFimLista;
	/* Ponteiro para o final da lista */

	tpLista * pElemCorr;
	/* Ponteiro para o elemento corrente da lista */

	int numElem;
	/* N�mero de elementos da lista */

	void(*ExcluirValor) (void * pValor);
	/* Ponteiro para a fun��o de destrui��o do valor contido em um elemento */


#ifdef _DEBUG
	char tipoElemento;
#endif

} tpCabeca;


/***********************************************************************
*
*  $FC Fun��o: LIS Limpa a Cabe�a da tpLista
*
***********************************************************************/

void LimparCabeca(tpCabeca * cb
#ifdef _DEBUG
				  , char tipoElemento
#endif
				  )
{
	cb->pOrigemLista = NULL;
	cb->pFimLista = NULL;
	cb->pElemCorr = NULL;
	cb->numElem = 0;

#ifdef _DEBUG
	cb->tipoElemento = tipoElemento;
#endif	
} /* Fim fun��o: LIS Limpa a Cabe�a da tpLista */

/***********************************************************************
*
*  $FC Fun��o: LIS Cria Elemento
*
***********************************************************************/

tpLista * CriarElemento(tpCabeca * cb, void * pValor
#ifdef _DEBUG
						, char tipoElemento
#endif
						)
{
	tpLista * pElem;

	pElem = (tpLista *)malloc(sizeof(tpLista));
	if (pElem == NULL)
	{
		return NULL;
	} /* if */
#ifdef _DEBUG
	CED_MarcarEspacoAtivo(pElem);
#endif		
	pElem->pValor = pValor;
	pElem->pAnt = NULL;
	pElem->pProx = NULL;
#ifdef _DEBUG
	pElem->tipoElemento = tipoElemento;
#endif	

	cb->numElem++;

	return pElem;
} /* Fim fun��o: LIS Cria Elemento */

/***********************************************************************
*
*	Fun��o: LIS Libera Elemento da tpLista
*
***********************************************************************/

void LiberarElemento(tpCabeca * cb, tpLista * pElem)
{
	if ((cb->ExcluirValor != NULL) && (pElem->pValor != NULL))
	{
		cb->ExcluirValor(pElem->pValor);
	} /* if */

#ifdef _DEBUG
	CED_MarcarEspacoNaoAtivo(pElem);
#endif

	free(pElem);

	cb->numElem--;

} /* Fim fun��o: LIS Libera Elemento da tpLista */

/***********************************************************************
*
*	Fun��o: LIS Criar lista
*
***********************************************************************/

tpCabeca * LIS_CriaLista(void(*ExcluirValor) (void * pDado)
#ifdef _DEBUG
						 , char tipoElemento
#endif
						 )
{
	tpCabeca * novo;

	novo = (tpCabeca *)malloc(sizeof(tpCabeca));

	if (novo == NULL)
	{
		return NULL;
	} /* if */

#ifdef _DEBUG
	CED_MarcarEspacoAtivo(novo);
#endif

	LimparCabeca(novo
#ifdef _DEBUG
		, tipoElemento
#endif
		);

	novo->ExcluirValor = ExcluirValor;

	return novo;
} /* Fim fun��o: LIS Criar lista */

/***********************************************************************
*
*	Fun��o: LIS Destroi tpLista
*
***********************************************************************/

LIS_tpCondRet LIS_DestroiLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		LIS_EsvaziarLista(cb);

#ifdef _DEBUG
		CED_MarcarEspacoNaoAtivo(cb);
#endif

		free(cb);

		return LIS_CondRetOK;
	} /* if */

	return LIS_CondRetListaVazia;
} /* Fim fun��o: LIS Destroi tpLista */

/***********************************************************************
*
*	Fun��o: LIS Insere Elemento Antes
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoAntes(tpCabeca * cb, void * pValor
#ifdef _DEBUG
									   , char tipoElemento
#endif
									   )
{
	tpLista * pElem;

	if (cb != NULL)
		/* Criar elemento a inerir antes */

			pElem = CriarElemento(cb, pValor
#ifdef _DEBUG
			, tipoElemento
#endif
			);

	if (pElem == NULL)
	{
		return LIS_CondRetFaltouMemoria;
	} /* if */

	/* Encadear o elemento antes do elemento corrente */

	if (cb->pElemCorr == NULL)
	{
		cb->pOrigemLista = pElem;
		cb->pFimLista = pElem;
	} /* if */
	else
	{
		if (cb->pElemCorr->pAnt != NULL)
		{
			pElem->pAnt = cb->pElemCorr->pAnt;
			cb->pElemCorr->pAnt->pProx = pElem;
		} /* if */
		else
		{
			cb->pOrigemLista = pElem;
		} /* if */

		pElem->pProx = cb->pElemCorr;
		cb->pElemCorr->pAnt = pElem;
	} /* if */

	cb->pElemCorr = pElem;
#ifdef _DEBUG
	cb->tipoElemento = tipoElemento;
#endif
	return LIS_CondRetOK;
} /* Fim fun��o: LIS Insere Elemento Antes */

/***********************************************************************
*
*	Fun��o: LIS Insere Elemento Ap�s
*
***********************************************************************/

LIS_tpCondRet LIS_InserirElementoApos(tpCabeca * cb, void * pValor
#ifdef _DEBUG
									  , int tipoElemento
#endif
									  )
{
	tpLista * pElem;

	if (cb != NULL)
	{
		/* Criar elemento a inerir ap�s */

		pElem = CriarElemento(cb, pValor
#ifdef _DEBUG
			, tipoElemento
#endif
			);

		if (pElem == NULL)
		{
			return LIS_CondRetFaltouMemoria;
		} /* if */

		/* Encadear o elemento ap�s o elemento */

		if (cb->pElemCorr == NULL)
		{
			cb->pOrigemLista = pElem;
			cb->pFimLista = pElem;
		} /* if */
		else
		{
			if (cb->pElemCorr->pProx != NULL)
			{
				pElem->pProx = cb->pElemCorr->pProx;
				cb->pElemCorr->pProx->pAnt = pElem;
			} /* if */
			else
			{
				cb->pFimLista = pElem;
			} /* if */

			pElem->pAnt = cb->pElemCorr;
			cb->pElemCorr->pProx = pElem;

		} /* if */

		cb->pElemCorr = pElem;
#ifdef _DEBUG
		cb->tipoElemento = tipoElemento;
#endif

		return LIS_CondRetOK;
	}
} /* Fim fun��o: LIS Insere Elemento Ap�s */

/***********************************************************************
*
*	Fun��o: LIS Exclui Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ExcluirElemento(tpCabeca * cb
#ifdef _DEBUG
								  , int qtdLiberar
#endif
								  )
{
	tpLista * pElem;

	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return LIS_CondRetListaVazia;
		} /* if */

		pElem = cb->pElemCorr;

		/* Desencadeia � esquerda */

		if (pElem->pAnt != NULL)
		{
			pElem->pAnt->pProx = pElem->pProx;
			cb->pElemCorr = pElem->pAnt;
		} /* if */
		else
		{
			cb->pElemCorr = pElem->pProx;
			cb->pOrigemLista = cb->pElemCorr;
		} /* if */

		/* Desencadeia � direita */

		if (pElem->pProx != NULL)
		{
			pElem->pProx->pAnt = pElem->pAnt;
		} /* if */
		else
		{
			cb->pFimLista = pElem->pAnt;
		} /* if */

#ifdef _DEBUG
		if (qtdLiberar)
#endif


			LiberarElemento(cb, pElem);

		return LIS_CondRetOK;
	}
} /* Fim fun��o: LIS Exclui Elemento */

/***********************************************************************
*
*	Fun��o: LIS Obt�m Valor Contido no Elemento
*
***********************************************************************/

void * LIS_ObterValor(tpCabeca * cb)
{
	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return NULL;
		} /* if */

		return cb->pElemCorr->pValor;
	} /* if */
} /* Fim fun��o: LIS Obt�m Valor Contido no Elemento */

/***********************************************************************
*
*	Fun��o: LIS Ir para o Elemento Inicial
*
***********************************************************************/

void LIS_IrInicioLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		cb->pElemCorr = cb->pOrigemLista;
	} /* if */
} /* Fim fun��o: LIS Ir para o Elemento Incial */

/***********************************************************************
*
*	Fun��o: LIS Ir para o Elemento Final
*
***********************************************************************/

void LIS_IrFinalLista(tpCabeca * cb)
{
	if (cb != NULL)
	{
		cb->pElemCorr = cb->pFimLista;
	} /* if */
} /* Fim fun��o: LIS Ir para o Elemento Final */

/***********************************************************************
*
*	Fun��o: LIS Avan�ar Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_AvancarElementoCorrente(tpCabeca * cb, int numElem)
{
	int i;

	tpLista * pElem;

	if (cb != NULL)
	{
		/* Tratar lista vazia */

		if (cb->pElemCorr == NULL)
		{

			return LIS_CondRetListaVazia;

		} /* fim ativa: Tratar lista vazia */

		/* Tratar avan�ar para frente */

		if (numElem > 0)
		{
			pElem = cb->pElemCorr;

			for (i = numElem; i > 0; i--)
			{
				if (pElem == NULL)
				{
					break;
				} /* if */
				pElem = pElem->pProx;
			} /* for */

			if (pElem != NULL)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */

			cb->pElemCorr = pElem;
			return LIS_CondRetFimLista;

		} /* fim ativa: Tratar avan�ar para frente */

		/* Tratar avan�ar para tr�s */

		else if (numElem < 0)
		{

			pElem = cb->pElemCorr;
			for (i = numElem; i < 0; i++)
			{
				if (pElem == NULL)
				{
					break;
				} /* if */
				pElem = pElem->pAnt;
			} /* for */

			if (pElem != NULL)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */

			cb->pElemCorr = pElem;
			return LIS_CondRetFimLista;

		} /* fim ativa: Tratar avan�ar para tr�s */

		/* Tratar n�o avan�ar */

		return LIS_CondRetOK;
	} /* if */
} /* Fim fun��o: LIS Avan�ar Elemento */

/***********************************************************************
*
*	Fun��o: LIS Procura Elemento
*
***********************************************************************/

LIS_tpCondRet LIS_ProcurarValor(tpCabeca * cb, void * pValor)
{
	tpLista * pElem;

	if (cb != NULL)
	{
		if (cb->pElemCorr == NULL)
		{
			return LIS_CondRetListaVazia;
		} /* if */

		for (pElem = cb->pElemCorr;
			pElem != NULL;
			pElem = pElem->pProx)
		{
			if (pElem->pValor == pValor)
			{
				cb->pElemCorr = pElem;
				return LIS_CondRetOK;
			} /* if */
		} /* for */

		return LIS_CondRetNaoAchou;
	} /* if */

	return LIS_CondRetListaVazia;
} /* Fim fun��o: LIS Procura Elemento */

/***********************************************************************
*
*	Fun��o: LIS Acessa o In�cio da tpLista
*
***********************************************************************/

tpLista * LIS_AcessaListaIni(tpCabeca * cb)
{
	if (cb != NULL)
	{
		return cb->pOrigemLista;
	} /* if */
	return NULL;
} /* Fim fun��o: LIS Acessa o In�cio da Lista */

/***********************************************************************
*
*	Fun��o: LIS Acessa o Fim da Lista
*
***********************************************************************/

tpLista * LIS_AcessaListaFim(tpCabeca * cb)
{
	if (cb != NULL)
	{
		return cb->pFimLista;
	} /* if */
} /* Fim fun��o: LIS Acessa o Fim da Lista */

/***********************************************************************
*
*	Fun��o: LIS Aponta para Pr�ximo
*
***********************************************************************/

tpLista * LIS_Proximo(tpLista * LIS)
{
	if (LIS != NULL)
	{
		return LIS->pProx;
	} /* if */
} /* Fim fun��o: LIS Aponta para Pr�ximo */

/***********************************************************************
*
*	Fun��o: LIS Aponta para Anterior
*
***********************************************************************/

tpLista * LIS_Anterior(tpLista * LIS)
{
	if (LIS != NULL)
	{
		return LIS->pAnt;
	} /* if */
} /* Fim fun��o: LIS Aponta para Anterior */

/***********************************************************************
*
*	Fun��o: LIS Acessa Struct
*
***********************************************************************/

void * LIS_AcessaStruct(tpLista * LIS)
{
	if (LIS != NULL)
	{
		return LIS->pValor;
	} /* if */
} /* Fim fun��o: LIS Acessa Struct */

/***********************************************************************
*
*	Fun��o: LIS Acessa Numero de Elementos
*
***********************************************************************/

int LIS_AcessaNumElem(tpCabeca * cb)
{
	if (cb == NULL)
	{
		return 0;
	} /* if */

	return cb->numElem;
} /* Fim fun��o: LIS Acessa Numero de Elementos */

/***********************************************************************
*
*	Fun��o: LIS Esvaziar Lista
*
***********************************************************************/

void LIS_EsvaziarLista(tpCabeca * LIS)
{

	tpLista * pElem;
	tpLista * pProx;

	if (LIS != NULL)
	{

		pElem = LIS->pOrigemLista;
		while (pElem != NULL)
		{
			pProx = pElem->pProx;
			LiberarElemento(LIS, pElem);
			pElem = pProx;
		} /* while */

		LimparCabeca(LIS
#ifdef _DEBUG
			, ' '
#endif		
			);
	}

} /* Fim fun��o: LIS Esvaziar lista */

LIS_tppLista * LIS_AcessaElementoCorrente(LIS_tppCabeca * cb)
{
	return cb->pElemCorr;
}

#ifdef _DEBUG

/***********************************************************************
*
*  $FC Fun��o: LIS Preenche Lixo Sucessor
*
***********************************************************************/
void LIS_PreencheLixoSucessor(tpLista *pLista, tpLista **ponteiro)
{
	pLista->pProx = *ponteiro;
} 
/* Fim fun��o: LIS  Preenche Lixo Sucessor*/

/***********************************************************************
*
*  $FC Fun��o: LIS Preenche Lixo Predecessor
*
***********************************************************************/

void LIS_PreencheLixoPredecessor(tpLista *pLista, tpLista **ponteiro)
{
	pLista->pAnt = *ponteiro;
}
/* Fim fun��o: LIS  Preenche Lixo Predecessor*/

void LIS_AlteraPonteiroSucessor(tpLista *pLista, tpLista *ponteiro)
{
	pLista->pProx = ponteiro;
} 
/* Fim fun��o: LIS  Altera Ponteiro Sucessor*/

/***********************************************************************
*
*  $FC Fun��o: LIS Altera Ponteiro Predecessor
*
***********************************************************************/

void LIS_AlteraPonteiroPredecessor(tpLista *pLista, tpLista *ponteiro)
{
	pLista->pAnt = ponteiro;
}
/* Fim fun��o: LIS  Altera Ponteiro Predecessor*/

/***********************************************************************
*
*  $FC Fun��o: LIS Altera Ponteiro Valor
*
***********************************************************************/

void LIS_AlteraPonteiroValor(tpLista * pLista)
{
	pLista->pValor = NULL ;
}
/* Fim fun��o: LIS  Altera Ponteiro Valor*/

/***********************************************************************
*
*  $FC Fun��o: LIS Nulo Corrente
*
***********************************************************************/

void LIS_NuloCorrente(tpCabeca * cb)
{
	cb->pElemCorr = NULL;
}
/* Fim fun��o: LIS  Nulo Corrente */



/***********************************************************************
*
*  $FC Fun��o: LIS Altera Tipo Elemento No
*
***********************************************************************/
void LIS_AlteraTipoElementoNo(tpCabeca * cb)
{
	cb->pElemCorr->tipoElemento = 'F';
}
/* Fim fun��o: LIS Altera Tipo Elemento No */



/***********************************************************************
*
*  $FC Fun��o: LIS Free Parcial
*
***********************************************************************/
void LIS_FreeParcial(tpCabeca * cb)
{
	LIS_ExcluirElemento(cb, 0);
}
/* Fim fun��o: LIS Free Parcial */

/***********************************************************************
*
*  $FC Fun��o: LIS Nulo Origem
*
***********************************************************************/

void LIS_NuloOrigem(tpCabeca * cb)
{
	cb->pOrigemLista = NULL;
}/* Fim fun��o: LIS  Nulo Origem */


/***********************************************************************
*
*  $FC Fun��o: LIS Acessa Tipo Espaco Cab
*
***********************************************************************/
char LIS_AcessaTipoEspacoCab(tpCabeca *cb)
{
	if (cb->tipoElemento != NULL)
	{
		return cb->tipoElemento;
	}
	return NULL;
} /* Fim fun��o: LIS Acessa Tipo Espaco Cab */


/***********************************************************************
*
*  $FC Fun��o: LIS Acessa Tipo Espaco No
*
***********************************************************************/
char LIS_AcessaTipoEspacoNo(tpLista *lst)
{
	if (lst->tipoElemento != NULL)
	{
		return lst->tipoElemento;
	}
	return NULL;

} /* LIS Acessa Tipo Espaco Cab */ 

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Prox
*
***********************************************************************/

int LIS_VerificaAssertivaProx(tpCabeca * pLista)
{
	tpCabeca *aux;
	tpLista *temp;
	int i = 1;
	aux = pLista;
	temp = LIS_AcessaListaIni(aux);

	if (temp != NULL)
	{
		
		while (temp->pProx != NULL && LIS_AcessaTipoEspacoNo(temp->pProx) == LIS_AcessaTipoEspacoCab(aux))
		{
			CNT_CONTAR("LIS_AssertivaProx_While1");
			if (temp != temp->pProx->pAnt){
				printf("\nErro: pNoCorrente != pNoCorrente->pProx->pAnt\n");
				CNT_CONTAR("LIS_AssertivaProx_Erro");
				return 1;
			}
			else {
				CNT_CONTAR("LIS_AssertivaProx_No_Ok");
			}

			i++;
			temp = temp->pProx;
		}
		CNT_CONTAR("LIS_AssertivaProx_if1");
	}
	else {
		CNT_CONTAR("LIS_AssertivaProx_else1");
	}

	if (i == LIS_AcessaNumElem(pLista))
	{
		CNT_CONTAR("LIS_AssertivaProx_if2");
		return 0;
	} /* if*/
	else
	{
		printf("\nErro: nao foi possivel percorrer toda a lista, significa que algum no foi desencadeado\n");
		CNT_CONTAR("LIS_AssertivaProx_else2");
		return 1;
	} /* if*/

}/* Fim fun��o: LIS  Verifica Assertiva Prox  */

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Ant
*
***********************************************************************/

int LIS_VerificaAssertivaAnt(tpCabeca *pLista)
{
	tpCabeca *aux = NULL;
	tpLista * temp;
	int i = 1;
	aux = pLista;
	temp = LIS_AcessaListaFim(aux);


	if (temp != NULL)
	{
		CNT_CONTAR("LIS_AssertivaAnt_if1");
		while (temp->pAnt != NULL && CED_ObterTipoEspaco(temp->pAnt) == CED_ObterTipoEspaco(aux))
		{
			CNT_CONTAR("LIS_AssertivaAnt_while1");
			if (temp != temp->pAnt->pProx){
				printf("\nErro: pNoCorrente != pNoCorrente->pAnt->pProx\n");
				CNT_CONTAR("LIS_AssertivaAnt_Erro");
				return 1;
			}
			else {
				CNT_CONTAR("LIS_AssertivaAnt_No_ok");
			}

			i++;
			temp = temp->pAnt;
		}
	}
	else {
		CNT_CONTAR("LIS_AssertivaAnt_else1");
	}/* if*/

	if (i == LIS_AcessaNumElem(pLista))
	{
		CNT_CONTAR("LIS_AssertivaAnt_if2");
		return 0;
	} /* if*/
	else
	{
		printf("\nErro: nao foi possivel percorrer toda a lista, significa que algum no foi desencadeado\n");
		CNT_CONTAR("LIS_AssertivaAnt_else2");
		return 1;
	} /* if*/

}/* Fim fun��o: LIS  Verifica Assertiva Ant  */

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Lista Vazia
*
***********************************************************************/

int LIS_VerificaAssertivaListaVazia(tpCabeca *cb)
{

	if (LIS_AcessaNumElem(cb) == 0)
	{
		CNT_CONTAR("LIS_AssertivaListaVazia_if1");
		if (cb->pElemCorr != NULL || cb->pOrigemLista != NULL || cb->pFimLista != NULL)
		{
			CNT_CONTAR("LIS_AssertivaListaVazia_Erro");
			return 1;
		}
		else {
			CNT_CONTAR("LIS_AssertivaListaVazia_Ok");
		} /* if */
		return 0;
	}
	else {
		CNT_CONTAR("LIS_AssertivaListaVazia_else1");
	}
	return 0;
}/* Fim fun��o: LIS  Verifica Assertiva Lista Vazia  */

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Lista Elemento Unico
*
***********************************************************************/

int LIS_VerificaAssertivaListaElemUnico(tpCabeca * cb)
{
	if (LIS_AcessaNumElem(cb) == 1)
	{
		CNT_CONTAR("LIS_AssertivaListaElemUnico_if1");
		if (cb->pElemCorr != cb->pOrigemLista || cb->pElemCorr != cb->pFimLista)
		{
			printf("\n Lista com Um elemento e ponteiro corrente diferente do ponteiro origem ou do ponteiro fim\n");
			CNT_CONTAR("LIS_AssertivaListaElemUnico_if2");
			return 1;
		}
		else {
			CNT_CONTAR("LIS_AssertivaListaElemUnico_else2");
		}/* if */

		if (cb->pElemCorr->pProx != NULL || cb->pElemCorr->pAnt != NULL)
		{
			printf("\n Lista com Um elemento e ponteiro proximo/anterior do no corrente nao eh nulo\n");
			CNT_CONTAR("LIS_AssertivaListaElemUnico_if3");
			return 1;
		}
		else {
			CNT_CONTAR("LIS_AssertivaListaElemUnico_else3");
		}/* if */

		return 0;
	}
	else {
		CNT_CONTAR("LIS_AssertivaListaElemUnico_else1");
	}
	return 0;
}/* Fim fun��o: LIS  Verifica Assertiva Lista Elemento Unico  */

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Lista Preenchida
*
***********************************************************************/

int LIS_VerificaAssertivaListaPreenchida(tpCabeca * cb)
{
	if (LIS_AcessaNumElem(cb) > 1)
	{
		CNT_CONTAR("LIS_AssertivaListaPreenchida_if1");
		if (cb->pElemCorr == NULL || cb->pFimLista == NULL || cb->pOrigemLista == NULL)
		{
			printf("\nLista Preenchida: erro pNoCorrente ou pFimLista ou pOrigemLista nulo(s)\n");
			CNT_CONTAR("LIS_AssertivaListaPreenchida_if2");
			return 1;
		}
		else {
			CNT_CONTAR("LIS_AssertivaListaPreenchida_else2");
		}/* if */

		return 0;
	}
	else {
		CNT_CONTAR("LIS_AssertivaListaPreenchida_else1");
	}
	return 0;
}/* Fim fun��o: LIS  Verifica Assertiva Lista Preenchida  */

/***********************************************************************
*
*  $FC Fun��o: LIS Verifica Assertiva Tipo de Elementos da Lista
*
***********************************************************************/

int LIS_VerificaAssertivaTipoListaElementos(tpCabeca * cb)
{
	tpCabeca* aux;
	tpLista * temp;
	aux = cb;
	temp = LIS_AcessaListaIni(aux);


	while (temp != NULL)
	{
		CNT_CONTAR("LIS_AssertivaTipoElemento_while");
		if (temp->pValor == NULL)
		{
			CNT_CONTAR("LIS_AssertivaTipoElemento_Null_ComErro");
			printf("\nErro: Ponteiro para conteudo da celula nulo!\n");
			return 1;
		}
		else {
			CNT_CONTAR("LIS_AssertivaTipoElemento_NotNull_Ok");
		}
		if (cb->pElemCorr != NULL)
		{
			if (aux->tipoElemento != cb->pElemCorr->tipoElemento)
			{
				CNT_CONTAR("LIS_AssertivaTipoElemento_ComErro");
				printf("\nErro: Tipo do conteudo da celula diferente do registrado na cabeca da lista!\n");
				return 1;
			}
		}
		else {
			CNT_CONTAR("LIS_AssertivaTipoElemento_Ok");
		}

		temp = temp->pProx;
	}
	CNT_CONTAR("LIS_AssertivaTipoElemento_Fim");
	return 0;
}


#endif

/********** Fim do m�dulo de implementa��o : M�dulo tpLista **********/