#include "../testlib.h"

static void test_normal_case(void)
{
    const char *str = "Hello, world!";
    char *sub = ft_substr(str, 7, 5);
    assert(sub != NULL);
    assert(strcmp(sub, "world") == 0);
    free(sub);
}

static void test_start_at_zero(void)
{
    const char *str = "Hello";
    char *sub = ft_substr(str, 0, 5);
    assert(sub != NULL);
    assert(strcmp(sub, "Hello") == 0);
    free(sub);
}

static void test_length_longer_than_string(void)
{
    const char *str = "Short";
    char *sub = ft_substr(str, 0, 10);
    assert(sub != NULL);
    assert(strcmp(sub, "Short") == 0);
    free(sub);
}

static void test_start_past_string_length(void)
{
    const char *str = "Hello";
    char *sub = ft_substr(str, 10, 5);
    assert(sub != NULL);
    assert(strcmp(sub, "") == 0);
    free(sub);
}

static void test_zero_length(void)
{
    const char *str = "Hello";
    char *sub = ft_substr(str, 2, 0);
    assert(sub != NULL);
    assert(strcmp(sub, "") == 0);
    free(sub);
}

static void test_empty_string(void)
{
    const char *str = "";
    char *sub = ft_substr(str, 0, 5);
    assert(sub != NULL);
    assert(strcmp(sub, "") == 0);
    free(sub);
}

static void test_null_input(void)
{
    char *sub = ft_substr(NULL, 0, 5);
    assert(sub == NULL);
}

static void test_middle_of_string(void)
{
    const char *str = "Extract this part";
    char *sub = ft_substr(str, 8, 4);
    assert(sub != NULL);
    assert(strcmp(sub, "this") == 0);
    free(sub);
}

void test_ft_substr(void)
{
    test_normal_case();
    test_start_at_zero();
    test_length_longer_than_string();
    test_start_past_string_length();
    test_zero_length();
    test_empty_string();
    test_null_input();
    test_middle_of_string();
}