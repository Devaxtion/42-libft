#include "../testlib.h"

static void test_find_existing_char(void)
{
    char str[] = "Hello world!";
    void *result = ft_memchr(str, 'w', strlen(str));
    void *expected = memchr(str, 'w', strlen(str));
    assert(result == expected);
}

static void test_find_first_char(void)
{
    char str[] = "test string";
    void *result = ft_memchr(str, 't', strlen(str));
    void *expected = memchr(str, 't', strlen(str));
    assert(result == expected);
}

static void test_find_last_char(void)
{
    char str[] = "search me";
    void *result = ft_memchr(str, 'e', strlen(str));
    void *expected = memchr(str, 'e', strlen(str));
    assert(result == expected);
}

static void test_char_not_found(void)
{
    char str[] = "abcdefgh";
    void *result = ft_memchr(str, 'z', strlen(str));
    void *expected = memchr(str, 'z', strlen(str));
    assert(result == expected);
}

static void test_null_input(void)
{
    assert(ft_memchr(NULL, 'a', 5) == NULL);
}

static void test_zero_length(void)
{
    char str[] = "test";
    void *result = ft_memchr(str, 't', 0);
    void *expected = memchr(str, 't', 0);
    assert(result == expected);
}

static void test_partial_search(void)
{
    char str[] = "abcdefghij";
    void *result = ft_memchr(str, 'd', 3);
    void *expected = memchr(str, 'd', 3);
    assert(result == expected);
}

static void test_find_null_byte(void)
{
    char str[] = "string with \0 null byte";
    void *result = ft_memchr(str, '\0', sizeof(str));
    void *expected = memchr(str, '\0', sizeof(str));
    assert(result == expected);
}

static void test_unsigned_char_conversion(void)
{
    char str[] = {0, 1, 2, 3, 4, 5};
    void *result = ft_memchr(str, 258, sizeof(str)); // 258 % 256 = 2
    void *expected = memchr(str, 258, sizeof(str));
    assert(result == expected);
}

void test_ft_memchr(void)
{
    TEST_START();
    test_find_existing_char();
    test_find_first_char();
    test_find_last_char();
    test_char_not_found();
    test_null_input();
    test_zero_length();
    test_partial_search();
    test_find_null_byte();
    test_unsigned_char_conversion();
    TEST_PASS();
}