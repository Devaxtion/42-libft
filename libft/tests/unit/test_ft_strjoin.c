#include "../testlib.h"

static void test_normal_join(void)
{
    const char *s1 = "Hello";
    const char *s2 = " world!";
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strcmp(result, "Hello world!") == 0);
    free(result);
}

static void test_empty_first_string(void)
{
    const char *s1 = "";
    const char *s2 = "world";
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strcmp(result, "world") == 0);
    free(result);
}

static void test_empty_second_string(void)
{
    const char *s1 = "Hello";
    const char *s2 = "";
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strcmp(result, "Hello") == 0);
    free(result);
}

static void test_both_empty_strings(void)
{
    const char *s1 = "";
    const char *s2 = "";
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strcmp(result, "") == 0);
    free(result);
}

static void test_null_first_string(void)
{
    const char *s2 = "world";
    char *result = ft_strjoin(NULL, s2);
    assert(result == NULL);
}

static void test_null_second_string(void)
{
    const char *s1 = "Hello";
    char *result = ft_strjoin(s1, NULL);
    assert(result == NULL);
}

static void test_special_chars(void)
{
    const char *s1 = "\t\n";
    const char *s2 = "\v\f\r";
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strcmp(result, "\t\n\v\f\r") == 0);
    free(result);
}

static void test_large_strings(void)
{
    char s1[1000];
    char s2[1000];
    memset(s1, 'a', 999);
    memset(s2, 'b', 999);
    s1[999] = '\0';
    s2[999] = '\0';
    
    char *result = ft_strjoin(s1, s2);
    assert(result != NULL);
    assert(strlen(result) == 1998);
    assert(result[0] == 'a');
    assert(result[999] == 'b');
    free(result);
}

static void test_empty_result(void)
{
    char *result = ft_strjoin("", "");
    assert(result != NULL);
    assert(result[0] == '\0');  // Explicit empty string check
    free(result);
}

void test_ft_strjoin(void)
{
    TEST_START();
    test_normal_join();
    test_empty_first_string();
    test_empty_second_string();
    test_both_empty_strings();
    test_null_first_string();
    test_null_second_string();
    test_special_chars();
    test_large_strings();
    test_empty_result();
    TEST_PASS();
}