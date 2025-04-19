#include "../testlib.h"

// Test function that alternates case based on index
static char alternate_case(unsigned int i, char c)
{
    if (i % 2 == 0)
        return ft_toupper(c);
    else
        return ft_tolower(c);
}

// Test function that adds index to character
static char add_index(unsigned int i, char c)
{
    return c + i;
}

// Wrapper function for ft_toupper to match strmapi signature
static char toupper_wrapper(unsigned int i, char c)
{
    (void)i; // We don't use the index in this case
    return ft_toupper(c);
}

static void test_alternate_case(void)
{
    const char *input = "hello";
    char *result = ft_strmapi(input, alternate_case);
    assert(result != NULL);
    assert(strcmp(result, "HeLlO") == 0);
    free(result);
}

static void test_add_index(void)
{
    const char *input = "abcd";
    char *result = ft_strmapi(input, add_index);
    assert(result != NULL);
    assert(result[0] == 'a' + 0);
    assert(result[1] == 'b' + 1);
    assert(result[2] == 'c' + 2);
    assert(result[3] == 'd' + 3);
    free(result);
}

static void test_empty_string(void)
{
    const char *input = "";
    char *result = ft_strmapi(input, alternate_case);
    assert(result != NULL);
    assert(strcmp(result, "") == 0);
    free(result);
}

static void test_null_input(void)
{
    char *result = ft_strmapi(NULL, alternate_case);
    assert(result == NULL);
    
    result = ft_strmapi("test", NULL);
    assert(result == NULL);
    
    result = ft_strmapi(NULL, NULL);
    assert(result == NULL);
}

static void test_identity_function(void)
{
    const char *input = "No Change";
    char *result = ft_strmapi(input, toupper_wrapper);
    assert(result != NULL);
    assert(strcmp(result, "NO CHANGE") == 0);
    free(result);
}

void test_ft_strmapi(void)
{
    TEST_START();
    test_alternate_case();
    test_add_index();
    test_empty_string();
    test_null_input();
    test_identity_function();
    TEST_PASS();
}