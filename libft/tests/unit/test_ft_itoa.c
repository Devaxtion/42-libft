#include "../testlib.h"

static void test_positive_number(void)
{
    char *result = ft_itoa(12345);
    assert(result != NULL);
    assert(strcmp(result, "12345") == 0);
    free(result);
}

static void test_negative_number(void)
{
    char *result = ft_itoa(-12345);
    assert(result != NULL);
    assert(strcmp(result, "-12345") == 0);
    free(result);
}

static void test_zero(void)
{
    char *result = ft_itoa(0);
    assert(result != NULL);
    assert(strcmp(result, "0") == 0);
    free(result);
}

static void test_int_max(void)
{
    char *result = ft_itoa(INT_MAX);
    assert(result != NULL);
    assert(strcmp(result, "2147483647") == 0);
    free(result);
}

static void test_int_min(void)
{
    char *result = ft_itoa(INT_MIN);
    assert(result != NULL);
    assert(strcmp(result, "-2147483648") == 0);
    free(result);
}

static void test_single_digit_positive(void)
{
    char *result = ft_itoa(7);
    assert(result != NULL);
    assert(strcmp(result, "7") == 0);
    free(result);
}

static void test_single_digit_negative(void)
{
    char *result = ft_itoa(-3);
    assert(result != NULL);
    assert(strcmp(result, "-3") == 0);
    free(result);
}

void test_ft_itoa(void)
{
    test_positive_number();
    test_negative_number();
    test_zero();
    test_int_max();
    test_int_min();
    test_single_digit_positive();
    test_single_digit_negative();
}