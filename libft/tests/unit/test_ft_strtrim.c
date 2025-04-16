#include "../testlib.h"

static void test_normal_trim(void)
{
    char *result = ft_strtrim("  Hello world!  ", " ");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_multiple_chars_to_trim(void)
{
    char *result = ft_strtrim(" \t\nHello world!\t\n ", " \t\n");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_trim_from_start_only(void)
{
    char *result = ft_strtrim("XXXHello world!", "X");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_trim_from_end_only(void)
{
    char *result = ft_strtrim("Hello world!ZZZ", "Z");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_no_trim_needed(void)
{
    char *result = ft_strtrim("Hello world!", "XYZ");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_empty_string(void)
{
    char *result = ft_strtrim("", "XYZ");
    assert(result != NULL);
    assert(strcmp(result, "") == 0);
    free(result);
}

static void test_all_trimmed(void)
{
    char *result = ft_strtrim("XXX", "X");
    assert(result != NULL);
    assert(strcmp(result, "") == 0);
    free(result);
}

static void test_null_input(void)
{
    char *result = ft_strtrim(NULL, "XYZ");
    assert(result == NULL);
    
    result = ft_strtrim("Hello", NULL);
    assert(result == NULL);
    
    result = ft_strtrim(NULL, NULL);
    assert(result == NULL);
}

static void test_complex_trim(void)
{
    char *result = ft_strtrim("abcHello world!cba", "abc");
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

void test_ft_strtrim(void)
{
    TEST_START();
    test_normal_trim();
    test_multiple_chars_to_trim();
    test_trim_from_start_only();
    test_trim_from_end_only();
    test_no_trim_needed();
    test_empty_string();
    test_all_trimmed();
    test_null_input();
    test_complex_trim();
    TEST_PASS();
}