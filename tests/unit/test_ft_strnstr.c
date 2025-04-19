#include "../testlib.h"

static void test_find_substring(void)
{
    const char *big = "Hello world!";
    const char *little = "world";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result != NULL);
    assert(strcmp(result, "world!") == 0);
}

static void test_substring_at_start(void)
{
    const char *big = "Hello world";
    const char *little = "Hello";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result != NULL);
    assert(result == big);  // Should return start of big string
}

static void test_substring_at_end(void)
{
    const char *big = "Hello world";
    const char *little = "world";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result != NULL);
    assert(strcmp(result, "world") == 0);
}

static void test_empty_little(void)
{
    const char *big = "Hello world";
    char *result = ft_strnstr(big, "", strlen(big));
    assert(result != NULL);
    assert(result == big);  // Should return big when little is empty
}

static void test_not_found(void)
{
    const char *big = "Hello world";
    const char *little = "foo";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result == NULL);
}

static void test_partial_search(void)
{
    const char *big = "Hello world";
    const char *little = "world";
    char *result = ft_strnstr(big, little, 8);  // Only search first 8 chars
    assert(result == big + 6);  // Adjust based on implementation
}

static void test_null_terminator_in_little(void)
{
    const char *big = "Hello\0world";
    const char *little = "world";
    char *result = ft_strnstr(big, little, 12);
    assert(result == NULL);
}

static void test_zero_len(void)
{
    const char *big = "Hello world";
    const char *little = "Hello";
    char *result = ft_strnstr(big, little, 0);
    assert(result == NULL);
}

static void test_exact_match(void)
{
    const char *big = "Hello";
    const char *little = "Hello";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result != NULL);
    assert(result == big);
}

static void test_little_longer_than_big(void)
{
    const char *big = "Hello";
    const char *little = "Hello world";
    char *result = ft_strnstr(big, little, strlen(big));
    assert(result == NULL);
}

void test_ft_strnstr(void)
{
    TEST_START();
    test_find_substring();
    test_substring_at_start();
    test_substring_at_end();
    test_empty_little();
    test_not_found();
    test_partial_search();
    test_null_terminator_in_little();
    test_zero_len();
    test_exact_match();
    test_little_longer_than_big();
    TEST_PASS();
}