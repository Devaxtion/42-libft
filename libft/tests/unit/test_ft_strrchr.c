#include "../testlib.h"

static void test_find_last_occurrence(void)
{
    const char *str = "Hello world!";
    char *result = ft_strrchr(str, 'o');
    assert(result != NULL);
    assert(strcmp(result, "orld!") == 0);
}

static void test_find_null_terminator(void)
{
    const char *str = "Find the end";
    char *result = ft_strrchr(str, '\0');
    assert(result != NULL);
    assert(result == str + strlen(str));
}

static void test_char_not_found(void)
{
    const char *str = "abcdefgh";
    char *result = ft_strrchr(str, 'z');
    assert(result == NULL);
}

static void test_first_char(void)
{
    const char *str = "first character";
    char *result = ft_strrchr(str, 'f');
    assert(result != NULL);
    assert(result == str);  // Should point to first character
}

static void test_last_char(void)
{
    const char *str = "last character";
    char *result = ft_strrchr(str, 'r');
    assert(result != NULL);
    assert(strcmp(result, "r") == 0);
}

static void test_empty_string(void)
{
    const char *str = "";
    char *result = ft_strrchr(str, 'a');
    assert(result == NULL);
}

static void test_int_to_char_conversion(void)
{
    const char *str = "char conversion";
    char *result = ft_strrchr(str, 0x80);  // Test with value > CHAR_MAX
    assert(result == NULL);
}

static void test_multiple_occurrences(void)
{
    const char *str = "multiple/matches/here";
    char *result = ft_strrchr(str, '/');
    assert(result != NULL);
    assert(strcmp(result, "/here") == 0);
}

void test_ft_strrchr(void)
{
    test_find_last_occurrence();
    test_find_null_terminator();
    test_char_not_found();
    test_first_char();
    test_last_char();
    test_empty_string();
    test_int_to_char_conversion();
    test_multiple_occurrences();
}