#include <gtest/gtest.h>

#include "cadastro.h"

TEST(cadastroTest, cadastroCheckRegexTest)
{
	const char float_er[] = "[1-9][0-9]*\\.?[0-9]*([Ee][+-]?[0-9]+)?";

	EXPECT_EQ(0, check_regex(float_er, "65000.00"));
	EXPECT_EQ(-1, check_regex(NULL, NULL));
}

TEST(cadastroTest, cadastroValorImovelTest)
{
	EXPECT_EQ(-1, get_valor_imovel(NULL));
	EXPECT_EQ(-2, get_valor_imovel("6300.00"));

	EXPECT_FLOAT_EQ(65000.00, get_valor_imovel("65000.00"));
}

