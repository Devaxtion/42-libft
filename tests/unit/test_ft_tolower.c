#include "../testlib.h"

static void test_uppercase_letters(void)
{
    for (int c = 'A'; c <= 'Z'; c++)
    {
        assert(ft_tolower(c) == (c + 32));  // ASCII uppercase to lowercase conversion
    }
}

static void test_lowercase_letters(void)
{
    for (int c = 'a'; c <= 'z'; c++)
    {
        assert(ft_tolower(c) == c);  // Lowercase should remain unchanged
    }
}

static void test_non_alpha_chars(void)
{
    assert(ft_tolower('0') == '0');
    assert(ft_tolower('@') == '@');
    assert(ft_tolower('[') == '[');
    assert(ft_tolower('`') == '`');
    assert(ft_tolower('{') == '{');
}

static void test_boundary_values(void)
{
    assert(ft_tolower('A' - 1) == 'A' - 1);  // '@'
    assert(ft_tolower('Z' + 1) == 'Z' + 1);  // '['
    assert(ft_tolower('a' - 1) == 'a' - 1);  // '`'
    assert(ft_tolower('z' + 1) == 'z' + 1);  // '{'
}

static void test_extended_ascii(void)
{
    assert(ft_tolower(128) == 128);
    assert(ft_tolower(255) == 255);
}

static void test_negative_values(void)
{
    assert(ft_tolower(-1) == -1);
    assert(ft_tolower(-42) == -42);
    assert(ft_tolower(INT_MIN) == INT_MIN);
}

void test_ft_tolower(void)
{
    TEST_START();
    test_uppercase_letters();
    test_lowercase_letters();
    test_non_alpha_chars();
    test_boundary_values();
    test_extended_ascii();
    test_negative_values();
    TEST_PASS();
}