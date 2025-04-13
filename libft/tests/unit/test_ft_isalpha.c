#include "../testlib.h"

static void test_lowercase_letters(void)
{
    for (int c = 'a'; c <= 'z'; c++)
        assert(ft_isalpha(c) != 0);
}

static void test_uppercase_letters(void)
{
    for (int c = 'A'; c <= 'Z'; c++)
        assert(ft_isalpha(c) != 0);
}

static void test_non_alpha_chars(void)
{
    // Test digits
    for (int c = '0'; c <= '9'; c++)
        assert(ft_isalpha(c) == 0);
    
    // Test whitespace and special chars
    assert(ft_isalpha(' ') == 0);
    assert(ft_isalpha('\t') == 0);
    assert(ft_isalpha('\n') == 0);
    assert(ft_isalpha('@') == 0);
    assert(ft_isalpha('[') == 0);
    assert(ft_isalpha('`') == 0);
    assert(ft_isalpha('{') == 0);

    // Characters just outside alpha range
    assert(ft_isalpha('A' - 1) == 0);
    assert(ft_isalpha('Z' + 1) == 0);
    assert(ft_isalpha('a' - 1) == 0);
    assert(ft_isalpha('z' + 1) == 0);

    // Test extended ASCII and negative values
    assert(ft_isalpha(128) == 0);
    assert(ft_isalpha(255) == 0);
    assert(ft_isalpha(-1) == 0);
    assert(ft_isalpha(-42) == 0);
}

void test_ft_isalpha(void)
{
    test_lowercase_letters();
    test_uppercase_letters();
    test_non_alpha_chars();
}