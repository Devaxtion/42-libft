#include "../testlib.h"
#include <limits.h>

static void test_lowercase_letters(void)
{
    for (int c = 'a'; c <= 'z'; c++)
    {
        assert(ft_toupper(c) == (c - 32));  // ASCII lowercase to uppercase conversion
    }
}

static void test_uppercase_letters(void)
{
    for (int c = 'A'; c <= 'Z'; c++)
    {
        assert(ft_toupper(c) == c);  // Uppercase should remain unchanged
    }
}

static void test_non_alpha_chars(void)
{
    assert(ft_toupper('0') == '0');
    assert(ft_toupper('@') == '@');
    assert(ft_toupper('[') == '[');
    assert(ft_toupper('`') == '`');
    assert(ft_toupper('{') == '{');
}

static void test_boundary_values(void)
{
    assert(ft_toupper('a' - 1) == 'a' - 1);  // '`'
    assert(ft_toupper('z' + 1) == 'z' + 1);  // '{'
    assert(ft_toupper('A' - 1) == 'A' - 1);  // '@'
    assert(ft_toupper('Z' + 1) == 'Z' + 1);  // '['
}

static void test_extended_ascii(void)
{
    assert(ft_toupper(128) == 128);
    assert(ft_toupper(255) == 255);
}

static void test_negative_values(void)
{
    assert(ft_toupper(-1) == -1);
    assert(ft_toupper(-42) == -42);
    assert(ft_toupper(INT_MIN) == INT_MIN);
}

void test_ft_toupper(void)
{
    TEST_START();
    test_lowercase_letters();
    test_uppercase_letters();
    test_non_alpha_chars();
    test_boundary_values();
    test_extended_ascii();
    test_negative_values();
    TEST_PASS();
}