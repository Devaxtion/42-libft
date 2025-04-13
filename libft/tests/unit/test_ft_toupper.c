#include "../testlib.h"
#include <ctype.h>

static void test_lowercase_letters(void)
{
    for (int c = 'a'; c <= 'z'; c++)
    {
        assert(ft_toupper(c) == toupper(c));
    }
}

static void test_uppercase_letters(void)
{
    for (int c = 'A'; c <= 'Z'; c++)
    {
        assert(ft_toupper(c) == toupper(c));
    }
}

static void test_non_alpha_chars(void)
{
    assert(ft_toupper('0') == toupper('0'));
    assert(ft_toupper('@') == toupper('@'));
    assert(ft_toupper('[') == toupper('['));
    assert(ft_toupper('`') == toupper('`'));
    assert(ft_toupper('{') == toupper('{'));
}

static void test_boundary_values(void)
{
    assert(ft_toupper('a' - 1) == toupper('a' - 1));
    assert(ft_toupper('z' + 1) == toupper('z' + 1));
    assert(ft_toupper('A' - 1) == toupper('A' - 1));
    assert(ft_toupper('Z' + 1) == toupper('Z' + 1));
}

static void test_extended_ascii(void)
{
    assert(ft_toupper(128) == toupper(128));
    assert(ft_toupper(255) == toupper(255));
}

static void test_negative_values(void)
{
    assert(ft_toupper(-1) == toupper(-1));
    assert(ft_toupper(-42) == toupper(-42));
    assert(ft_toupper(INT_MIN) == toupper(INT_MIN));
}

void test_ft_toupper(void)
{
    test_lowercase_letters();
    test_uppercase_letters();
    test_non_alpha_chars();
    test_boundary_values();
    test_extended_ascii();
    test_negative_values();
}