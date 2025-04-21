#include "../testlib.h"

static void test_normal_case(void)
{
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_memset(str1, 'x', 5);
    memset(str2, 'x', 5);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_zero_count(void)
{
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_memset(str1, 'x', (size_t)0); // Explicit cast to suppress warning
    memset(str2, 'x', (size_t)0);   // Explicit cast to suppress warning
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_full_overwrite(void)
{
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_memset(str1, 'y', 10);
    memset(str2, 'y', 10);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_non_char_buffer(void)
{
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    
    ft_memset(arr1, 0, 5 * sizeof(int));
    memset(arr2, 0, 5 * sizeof(int));
    
    assert(memcmp(arr1, arr2, 5 * sizeof(int)) == 0);
}

static void test_large_buffer(void)
{
    char buf1[1000];
    char buf2[1000];
    
    memset(buf1, 'x', 1000);
    memset(buf2, 'x', 1000);
    
    ft_memset(buf1, 0, 1000);
    memset(buf2, 0, 1000);
    
    assert(memcmp(buf1, buf2, 1000) == 0);
}

static void test_int_to_unsigned_char_conversion(void)
{
    char str1[10] = {0};
    char str2[10] = {0};
    
    ft_memset(str1, 0xABCD, 5);  // Only lower byte should be used
    memset(str2, 0xABCD, 5);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_boundary_values(void)
{
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_memset(str1, INT_MAX, 5);
    memset(str2, INT_MAX, 5);
    
    assert(memcmp(str1, str2, 10) == 0);
}

void test_ft_memset(void)
{
    TEST_START();
    test_normal_case();
    test_zero_count();
    test_full_overwrite();
    test_non_char_buffer();
    test_large_buffer();
    test_int_to_unsigned_char_conversion();
    test_boundary_values();
    TEST_PASS();
}