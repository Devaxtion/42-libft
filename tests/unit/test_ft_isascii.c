#include "../testlib.h"

static void test_standard_ascii(void)
{
    // Test all standard ASCII characters (0-127)
    for (int c = 0; c <= 127; c++)
        assert(ft_isascii(c) != 0);
}

static void test_extended_ascii(void)
{
    // Test extended ASCII (128-255)
    for (int c = 128; c <= 255; c++)
        assert(ft_isascii(c) == 0);
}

static void test_negative_values(void)
{
    // Test negative values
    assert(ft_isascii(-1) == 0);
    assert(ft_isascii(-42) == 0);
    assert(ft_isascii(INT_MIN) == 0);
}

static void test_large_values(void)
{
    // Test values beyond 255
    assert(ft_isascii(256) == 0);
    assert(ft_isascii(1024) == 0);
    assert(ft_isascii(INT_MAX) == 0);
}

void test_ft_isascii(void)
{
    TEST_START();
    test_standard_ascii();
    test_extended_ascii();
    test_negative_values();
    test_large_values();
    TEST_PASS();
}