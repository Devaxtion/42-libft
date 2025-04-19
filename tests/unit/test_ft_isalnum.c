#include "../testlib.h"

static void test_alphabetic_chars(void)
{
    for (int c = 'a'; c <= 'z'; c++)
        assert(ft_isalnum(c) != 0);
    
    for (int c = 'A'; c <= 'Z'; c++)
        assert(ft_isalnum(c) != 0);
}

static void test_numeric_chars(void)
{
    for (int c = '0'; c <= '9'; c++)
        assert(ft_isalnum(c) != 0);
}

static void test_negative_values(void)
{
    assert(ft_isalnum(-1) == 0);
    assert(ft_isalnum(-42) == 0);
    assert(ft_isalnum(-128) == 0);
    assert(ft_isalnum(-255) == 0);
}

static void test_non_alnum_chars(void)
{
    assert(ft_isalnum(' ') == 0);
    assert(ft_isalnum('\t') == 0);
    assert(ft_isalnum('\n') == 0);
    assert(ft_isalnum('@') == 0);
    assert(ft_isalnum('[') == 0);
    assert(ft_isalnum('`') == 0);
    assert(ft_isalnum('{') == 0);
    assert(ft_isalnum('_') == 0);
    assert(ft_isalnum('-') == 0);
    assert(ft_isalnum('+') == 0);
    assert(ft_isalnum('.') == 0);
}

void test_ft_isalnum(void)
{
    TEST_START();
    test_alphabetic_chars();
    test_numeric_chars();
    test_negative_values();
    test_non_alnum_chars();
    TEST_PASS();
}