#include "../testlib.h"

static void test_normal_split(void)
{
    char **result = ft_split("Hello world this is a test", ' ');
    assert(result != NULL);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "world") == 0);
    assert(strcmp(result[2], "this") == 0);
    assert(strcmp(result[3], "is") == 0);
    assert(strcmp(result[4], "a") == 0);
    assert(strcmp(result[5], "test") == 0);
    assert(result[6] == NULL);
    free(result);
}

static void test_consecutive_delimiters(void)
{
    char **result = ft_split("Hello   world", ' ');
    assert(result != NULL);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "world") == 0);
    assert(result[2] == NULL);
    free(result);
}

static void test_delimiter_at_start_end(void)
{
    char **result = ft_split(",Hello,world,", ',');
    assert(result != NULL);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "world") == 0);
    assert(result[2] == NULL);
    free(result);
}

static void test_no_delimiters(void)
{
    char **result = ft_split("Hello", ' ');
    assert(result != NULL);
    assert(strcmp(result[0], "Hello") == 0);
    assert(result[1] == NULL);
    free(result);
}

static void test_all_delimiters(void)
{
    char **result = ft_split(",,,,", ',');
    assert(result != NULL);
    assert(result[0] == NULL);
    free(result);
}

static void test_empty_string(void)
{
    char **result = ft_split("", ' ');
    assert(result != NULL);
    assert(result[0] == NULL);
    free(result);
}

static void test_null_input(void)
{
    char **result = ft_split(NULL, ' ');
    assert(result == NULL);
}

static void test_special_delimiter(void)
{
    char **result = ft_split("Hello\nworld\nthis\nis\na\ntest", '\n');
    assert(result != NULL);
    assert(strcmp(result[0], "Hello") == 0);
    assert(strcmp(result[1], "world") == 0);
    assert(strcmp(result[2], "this") == 0);
    assert(strcmp(result[3], "is") == 0);
    assert(strcmp(result[4], "a") == 0);
    assert(strcmp(result[5], "test") == 0);
    assert(result[6] == NULL);
    free(result);
}

void test_ft_split(void)
{
    TEST_START();
    test_normal_split();
    test_consecutive_delimiters();
    test_delimiter_at_start_end();
    test_no_delimiters();
    test_all_delimiters();
    test_empty_string();
    test_null_input();
    test_special_delimiter();
    TEST_PASS();
}