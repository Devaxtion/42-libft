#include "../testlib.h"

static void test_printable_chars(void)
{
    // Test all printable ASCII characters (32-126)
    for (int c = 32; c <= 126; c++)
    {
        assert(ft_isprint(c) != 0);
    }
}

static void test_non_printable_chars(void)
{
    // Test control characters (0-31 and 127)
    for (int c = 0; c <= 31; c++)
    {
        assert(ft_isprint(c) == 0);
    }
    assert(ft_isprint(127) == 0);
}

static void test_whitespace_chars(void)
{
    // Special cases for whitespace (which are printable except \t, \n etc.)
    assert(ft_isprint(' ') != 0);  // Space is printable
    assert(ft_isprint('\t') == 0);
    assert(ft_isprint('\n') == 0);
    assert(ft_isprint('\r') == 0);
    assert(ft_isprint('\v') == 0);
    assert(ft_isprint('\f') == 0);
}

static void test_boundary_values(void)
{
    // Test exact boundaries
    assert(ft_isprint(31) == 0);
    assert(ft_isprint(32) != 0);
    assert(ft_isprint(126) != 0);
    assert(ft_isprint(127) == 0);
}

static void test_extended_ascii(void)
{
    // Test extended ASCII (128-255)
    for (int c = 128; c <= 255; c++)
    {
        assert(ft_isprint(c) == 0);
    }
}

static void test_negative_values(void)
{
    // Test negative values
    assert(ft_isprint(-1) == 0);
    assert(ft_isprint(-42) == 0);
    assert(ft_isprint(INT_MIN) == 0);
}

void test_ft_isprint(void)
{
    TEST_START();
    test_printable_chars();
    test_non_printable_chars();
    test_whitespace_chars();
    test_boundary_values();
    test_extended_ascii();
    test_negative_values();
    TEST_PASS();
}