#include "../testlib.h"

// Test function that modifies characters based on their index
static void modify_odd_indices(unsigned int i, char *c)
{
    if (i % 2 != 0)
        *c = ft_toupper(*c);
}

// Test function that replaces characters with their index
static void replace_with_index(unsigned int i, char *c)
{
    *c = '0' + (i % 10); // Simple way to convert single-digit index to char
}

// Test function that does nothing (for testing NULL cases)
static void no_operation(unsigned int i, char *c)
{
    (void)i;
    (void)c;
}

static void test_modify_odd_indices(void)
{
    char str[] = "abcdefgh";
    ft_striteri(str, modify_odd_indices);
    assert(strcmp(str, "aBcDeFgH") == 0);
}

static void test_replace_with_index(void)
{
    char str[] = "abcd";
    ft_striteri(str, replace_with_index);
    assert(str[0] == '0');
    assert(str[1] == '1');
    assert(str[2] == '2');
    assert(str[3] == '3');
}

static void test_empty_string(void)
{
    char str[] = "";
    ft_striteri(str, modify_odd_indices);
    assert(strcmp(str, "") == 0);
}

static void test_null_input(void)
{
    // Should not crash when given NULL parameters
    ft_striteri(NULL, modify_odd_indices);
    
    char str[] = "test";
    ft_striteri(str, NULL);
    
    ft_striteri(NULL, NULL);
}

static void test_no_operation(void)
{
    char str[] = "original";
    ft_striteri(str, no_operation);
    assert(strcmp(str, "original") == 0);
}

void test_ft_striteri(void)
{
    test_modify_odd_indices();
    test_replace_with_index();
    test_empty_string();
    test_null_input();
    test_no_operation();
}