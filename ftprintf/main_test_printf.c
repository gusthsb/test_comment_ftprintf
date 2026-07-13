#include <stdio.h>
#include <limits.h>
#include "ft_printf.h"

/* Contadores globais simples pra saber quantos testes passaram */
int g_total = 0;
int g_ok = 0;

/*
** Compara o retorno e a saida do ft_printf com o printf original.
** Como nao da pra "capturar" facilmente a saida de dois printf
** diferentes ao mesmo tempo sem redirecionar stdout, aqui a gente
** so compara o RETORNO (numero de caracteres impressos), que já
** pega muito bug (ex: esquecer de contar o '-', o '0x', etc).
** A saida visual voce compara "a olho" entre as duas linhas.
*/
void	test_int(int n)
{
	int ret_ft;
	int ret_og;

	g_total++;
	printf("  libc  -> [");
	ret_og = printf("%d", n);
	printf("] (%d chars)\n", ret_og);

	printf("  ft    -> [");
	ret_ft = ft_printf("%d", n);
	printf("] (%d chars)\n", ret_ft);

	if (ret_ft == ret_og)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", ret_og, ret_ft);
}

void	test_str(char *s)
{
	int ret_ft;
	int ret_og;

	g_total++;
	printf("  libc  -> [");
	ret_og = printf("%s", s);
	printf("] (%d chars)\n", ret_og);

	printf("  ft    -> [");
	ret_ft = ft_printf("%s", s);
	printf("] (%d chars)\n", ret_ft);

	if (ret_ft == ret_og)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", ret_og, ret_ft);
}

void	test_hex(unsigned int n)
{
	int ret_ft;
	int ret_og;

	g_total++;
	printf("  libc  -> [");
	ret_og = printf("%x / %X", n, n);
	printf("] (%d chars)\n", ret_og);

	printf("  ft    -> [");
	ret_ft = ft_printf("%x / %X", n, n);
	printf("] (%d chars)\n", ret_ft);

	if (ret_ft == ret_og)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", ret_og, ret_ft);
}

void	test_ptr(void *p)
{
	int ret_ft;
	int ret_og;

	g_total++;
	printf("  libc  -> [");
	ret_og = printf("%p", p);
	printf("] (%d chars)\n", ret_og);

	printf("  ft    -> [");
	ret_ft = ft_printf("%p", p);
	printf("] (%d chars)\n", ret_ft);

	if (ret_ft == ret_og)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", ret_og, ret_ft);
}

int	main(void)
{
	int	x;
	int	y;

	/* Sem isso, o printf da libc fica em buffer e o write()
	** do ft_printf (sem buffer) aparece na tela antes dele,
	** mesmo rodando depois no codigo. Deixa a comparacao visual
	** mais confusa do que realmente eh. */
	setbuf(stdout, NULL);

	printf("===== TESTES BASICOS =====\n\n");

	printf("-- %%d / %%i --\n");
	test_int(42);
	test_int(-42);
	test_int(0);
	test_int(INT_MAX);
	test_int(INT_MIN); /* o caso especial que a gente comentou */

	printf("-- %%s --\n");
	test_str("Hello, 42!");
	test_str("");
	test_str("Gustavo");

	printf("-- %%u --\n");
	g_total++;
	printf("  libc  -> [");
	x = printf("%u", 4294967295U);
	printf("] (%d chars)\n", x);
	printf("  ft    -> [");
	y = ft_printf("%u", 4294967295U);
	printf("] (%d chars)\n", y);
	if (x == y)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", x, y);

	printf("-- %%x / %%X --\n");
	test_hex(255);
	test_hex(0);
	test_hex(4294967295U);

	printf("-- %%p --\n");
	int	var = 10;
	test_ptr(&var);
	test_ptr(NULL);

	printf("-- %%c --\n");
	g_total++;
	printf("  libc  -> [");
	x = printf("%c", 'A');
	printf("] (%d chars)\n", x);
	printf("  ft    -> [");
	y = ft_printf("%c", 'A');
	printf("] (%d chars)\n", y);
	if (x == y)
	{
		g_ok++;
		printf("  OK\n\n");
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", x, y);

	printf("-- misturado --\n");
	g_total++;
	printf("  libc  -> ");
	x = printf("%s tem %d anos e usa %c como inicial (%p)\n",
			"Gustavo", 20, 'G', &var);
	printf("  ft    -> ");
	y = ft_printf("%s tem %d anos e usa %c como inicial (%p)\n",
			"Gustavo", 20, 'G', &var);
	printf("Saida padrao pointer (%p)\n", &var);
	if (x == y)
	{
		g_ok++;
		printf("  OK (%d chars nos dois)\n\n", x);
	}
	else
		printf("  FALHOU (esperado %d, veio %d)\n\n", x, y);

	printf("\n===== RESULTADO: %d/%d passaram (baseado em retorno) =====\n",
		g_ok, g_total);
	return (0);
}
