#include "../testlib.h"

static void test_identical_memory(void)
{
    char str1[] = "Hello world";
    char str2[] = "Hello world";
    assert(ft_memcmp(str1, str2, sizeof(str1)) == 0);
}

static void test_different_memory(void)
{
    char str1[] = "Hello world";
    char str2[] = "Hello there";
    assert(ft_memcmp(str1, str2, sizeof(str1)) == 3);
}

static void test_partial_comparison(void)
{
    char str1[] = "Hello world";
    char str2[] = "Hello there";
    assert(ft_memcmp(str1, str2, 5) == 0);
}

static void test_zero_length(void)
{
    char str1[] = "Hello";
    char str2[] = "World";
    assert(ft_memcmp(str1, str2, 0) == 0);
}

static void test_null_bytes(void)
{
    char str1[] = "Hello\0world";
    char str2[] = "Hello\0there";
    assert(ft_memcmp(str1, str2, 11) == 3);
}

static void test_unsigned_comparison(void)
{
    unsigned char arr1[] = {0, 1, 200};
    unsigned char arr2[] = {0, 1, 100};
    assert(ft_memcmp(arr1, arr2, 3) == 100);
}

static void test_non_string_data(void)
{
    int arr1[] = {1, 2, 3, 4};
    int arr2[] = {1, 2, 3, 5};
    assert(ft_memcmp(arr1, arr2, sizeof(arr1)) == -1);
}

static void test_completely_different(void)
{
    char str1[] = "ABCDEF";
    char str2[] = "abcdef";
    assert(ft_memcmp(str1, str2, 6) == -32);
}

void test_ft_memcmp(void)
{
    test_identical_memory();
    test_different_memory();
    test_partial_comparison();
    test_zero_length();
    test_null_bytes();
    test_unsigned_comparison();
    test_non_string_data();
    test_completely_different();
}