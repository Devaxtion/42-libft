#include "../testlib.h"

static void test_find_existing_char(void)
{
    const char *str = "Hello world!";
    char *result = ft_strchr(str, 'w');
    char *expected = strchr(str, 'w');
    assert(result == expected);
}

static void test_find_first_char(void)
{
    const char *str = "test string";
    char *result = ft_strchr(str, 't');
    char *expected = strchr(str, 't');
    assert(result == expected);
}

static void test_find_last_char(void)
{
    const char *str = "search me";
    char *result = ft_strchr(str, 'e');
    char *expected = strchr(str, 'e');
    assert(result == expected);
}

static void test_char_not_found(void)
{
    const char *str = "abcdefgh";
    char *result = ft_strchr(str, 'z');
    char *expected = strchr(str, 'z');
    assert(result == expected);
}

static void test_null_terminator(void)
{
    const char *str = "find the end";
    char *result = ft_strchr(str, '\0');
    char *expected = strchr(str, '\0');
    assert(result == expected);
}

static void test_null_input(void)
{
    assert(ft_strchr(NULL, 'a') == NULL);
}

static void test_empty_string(void)
{
    const char *str = "";
    char *result = ft_strchr(str, 'a');
    char *expected = strchr(str, 'a');
    assert(result == expected);
}

static void test_int_to_char_conversion(void)
{
    const char *str = "ASCII conversion";
    char *result = ft_strchr(str, 0x80);  // Test with value > CHAR_MAX
    char *expected = strchr(str, 0x80);
    assert(result == expected);
}

static void test_find_zero(void)
{
    const char *str = "string\0with\0nulls";
    char *result = ft_strchr(str, '\0');
    char *expected = strchr(str, '\0');
    assert(result == expected);
}
static void test_return_value_address(void)
{
    const char *str = "test";
    char *dup = ft_strdup(str);
    assert(dup != str);  // Should be different addresses
    free(dup);
}

void test_ft_strchr(void)
{
    TEST_START();
    test_find_existing_char();
    test_find_first_char();
    test_find_last_char();
    test_char_not_found();
    test_null_terminator();
    test_null_input();
    test_empty_string();
    test_int_to_char_conversion();
    test_find_zero();
    test_return_value_address();
    TEST_PASS();
}