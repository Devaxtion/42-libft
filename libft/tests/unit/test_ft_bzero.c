#include "../testlib.h"

static void test_normal_case() {
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_bzero(str1, 5);
    memset(str2, 0, 5);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_zero_count() {
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_bzero(str1, 0);
    memset(str2, 0, 0);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_full_overwrite() {
    char str1[10] = "abcdefghi";
    char str2[10] = "abcdefghi";
    
    ft_bzero(str1, 10);
    memset(str2, 0, 10);
    
    assert(memcmp(str1, str2, 10) == 0);
}

static void test_non_char_buffer() {
    int arr1[5] = {1, 2, 3, 4, 5};
    int arr2[5] = {1, 2, 3, 4, 5};
    
    ft_bzero(arr1, 5 * sizeof(int));
    memset(arr2, 0, 5 * sizeof(int));
    
    assert(memcmp(arr1, arr2, 5 * sizeof(int)) == 0);
}

static void test_large_buffer() {
    char buf1[1000];
    char buf2[1000];
    
    memset(buf1, 'x', 1000);
    memset(buf2, 'x', 1000);
    
    ft_bzero(buf1, 1000);
    memset(buf2, 0, 1000);
    
    assert(memcmp(buf1, buf2, 1000) == 0);
}

static void test_partial_clear() {
    char str1[20] = "This is a test";
    char str2[20] = "This is a test";
    
    ft_bzero(str1 + 5, 5);
    memset(str2 + 5, 0, 5);
    
    assert(memcmp(str1, str2, 20) == 0);
}

static void test_null_with_zero() {
    ft_bzero(NULL, 0);
}

void test_ft_bzero() {
    TEST_START();
    test_normal_case();
    test_zero_count();
    test_full_overwrite();
    test_non_char_buffer();
    test_large_buffer();
    test_partial_clear();
    test_null_with_zero();
    TEST_PASS();
}
