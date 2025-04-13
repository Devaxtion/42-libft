#include "../testlib.h"

static void test_digit_chars(void)
{
    for (int c = '0'; c <= '9'; c++)
        assert(ft_isdigit(c) != 0);
}

static void test_non_digit_chars(void)
{
    // Test letters
    for (int c = 'A'; c <= 'Z'; c++)
        assert(ft_isdigit(c) == 0);

    for (int c = 'a'; c <= 'z'; c++)
        assert(ft_isdigit(c) == 0);

    // Test special characters
    assert(ft_isdigit(' ') == 0);
    assert(ft_isdigit('@') == 0);
    assert(ft_isdigit('\t') == 0);
    assert(ft_isdigit('\n') == 0);

    // Characters immediately before and after digit range
    assert(ft_isdigit('0' - 1) == 0);
    assert(ft_isdigit('9' + 1) == 0);

    // Test extended ASCII values
    assert(ft_isdigit(128) == 0);
    assert(ft_isdigit(255) == 0);

    // Test negative values
    assert(ft_isdigit(-1) == 0);
    assert(ft_isdigit(-42) == 0);
    assert(ft_isdigit(INT_MIN) == 0);
}

void test_ft_isdigit(void)
{
    test_digit_chars();
    test_non_digit_chars();
}