#include <string.h>
#include <regex.h>

#include "cadastro.h"

#if (DEBUG >= 1)
#define DEBUG_MESSAGE(fmt, args...)		(fprintf(stderr, fmt, ##args))
#else
#define DEBUG_MESSAGE(fmt, args...)
#endif	/* (DEBUG >= 1) */

int check_regex(const char *er, const char *txt)
{
	regex_t regex;
	int ret;

	/** verify string to verify */
	if (!txt || !strlen(txt)) {
		return -1;
	}

	/** verify regular expression */
	if (!er || !strlen(er)) {
		return -1;
	}

	regcomp(&regex, er, REG_EXTENDED|REG_NOSUB);
	ret = regexec(&regex, txt,  0, NULL, 0);
	regfree(&regex);

	return ((ret != 0) ? -1 : 0);
}

float get_valor_imovel(const char * valor_imovel)
{
	float temp;
	/* expressão regular para convesão de strings para float */
	const char float_er[] = "[1-9][0-9]*\\.?[0-9]*([Ee][+-]?[0-9]+)?";

	if (check_regex(float_er, valor_imovel) != 0) {
		DEBUG_MESSAGE("\t\tvalor imóvel inválido %s\n", valor_imovel);
		return -1;
	}

	temp = atof(valor_imovel);
	if (temp < VALOR_IMOVEL_MIN) {
		DEBUG_MESSAGE("\t\tvalor do imóvel (%0.2f) abaixo do valor mínimo\n", temp);
		return -2;
	}
	return temp;
}

