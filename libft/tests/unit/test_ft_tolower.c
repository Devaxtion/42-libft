#include "../testlib.h"
#include <ctype.h>

static void test_uppercase_letters(void)
{
    for (int c = 'A'; c <= 'Z'; c++)
    {
        assert(ft_tolower(c) == tolower(c));
    }
}

static void test_lowercase_letters(void)
{
    for (int c = 'a'; c <= 'z'; c++)
    {
        assert(ft_tolower(c) == tolower(c));
    }
}

static void test_non_alpha_chars(void)
{
    assert(ft_tolower('0') == tolower('0'));
    assert(ft_tolower('@') == tolower('@'));
    assert(ft_tolower('[') == tolower('['));
    assert(ft_tolower('`') == tolower('`'));
    assert(ft_tolower('{') == tolower('{'));
}

static void test_boundary_values(void)
{
    assert(ft_tolower('A' - 1) == tolower('A' - 1));
    assert(ft_tolower('Z' + 1) == tolower('Z' + 1));
    assert(ft_tolower('a' - 1) == tolower('a' - 1));
    assert(ft_tolower('z' + 1) == tolower('z' + 1));
}

static void test_extended_ascii(void)
{
    assert(ft_tolower(128) == tolower(128));
    assert(ft_tolower(255) == tolower(255));
}

static void test_negative_values(void)
{
    assert(ft_tolower(-1) == tolower(-1));
    assert(ft_tolower(-42) == tolower(-42));
    assert(ft_tolower(INT_MIN) == tolower(INT_MIN));
}

void test_ft_tolower(void)
{
    test_uppercase_letters();
    test_lowercase_letters();
    test_non_alpha_chars();
    test_boundary_values();
    test_extended_ascii();
    test_negative_values();
}