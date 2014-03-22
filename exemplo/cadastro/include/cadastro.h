#ifndef CADASTRO_H_INCLUDED
#define CADASTRO_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>

/**
 *	Valor do Imóvel:
 *		O itaú financia imóveis residenciais a partir de R$ 62 mil, sem limite máximo
 *
 *	Valor de Entrada:
 *		A entrada deve ser de, no mínimo, 20% do valor do imóvel. A entrada não pode ser superior o igual ao Valor do Imóvel.
 *
 *	Prazo de financiamento:
 *		O prazo para financiamento de imóveis é de mínimo, 12 meses e, no máximo, 360 meses
 *
 *	Data de Nascimento:
 *		A idade do comprado deve ser igual ou superior a 18 igual ou inferior a 65 anos.
 *		O parcelamento do financiamento deve terminar antes do comprador completar 65 anos
 *		(ou no mesmo ano em que o comprador completar 65 anos).
 *
 *	Renda líquida mensal:
 *		A renda líquida mensal deve ser superior a R$ 1.500,00.
 */

#define VALOR_IMOVEL_MIN		(62000L)	/* R$ 62.000,00 mil */

int check_regex(const char *er, const char *txt);

float get_valor_imovel(const char * valor_imovel);

#endif	/* CADASTRO_H_INCLUDED */
