#include "../testlib.h"

static void test_identical_strings(void)
{
    const char *s1 = "Hello world";
    const char *s2 = "Hello world";
    assert(ft_strncmp(s1, s2, strlen(s1)) == strncmp(s1, s2, strlen(s1)));
}

static void test_different_strings(void)
{
    const char *s1 = "Hello world";
    const char *s2 = "Hello there";
    assert(ft_strncmp(s1, s2, strlen(s1)) > 0);
    assert(ft_strncmp(s2, s1, strlen(s1)) < 0);
}

static void test_partial_comparison(void)
{
    const char *s1 = "Hello world";
    const char *s2 = "Hello there";
    assert(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
}

static void test_zero_length(void)
{
    const char *s1 = "Hello";
    const char *s2 = "World";
    assert(ft_strncmp(s1, s2, 0) == strncmp(s1, s2, 0));
}

static void test_null_bytes(void)
{
    const char *s1 = "Hello\0world";
    const char *s2 = "Hello\0there";
    assert(ft_strncmp(s1, s2, 11) == strncmp(s1, s2, 11));
}

static void test_unsigned_comparison(void)
{
    const char *s1 = "\200";
    const char *s2 = "\0";
    assert(ft_strncmp(s1, s2, 1) == strncmp(s1, s2, 1));
}

static void test_different_lengths(void)
{
    const char *s1 = "Hello";
    const char *s2 = "Hello world";
    assert(ft_strncmp(s1, s2, 5) == strncmp(s1, s2, 5));
    assert(ft_strncmp(s1, s2, 6) == -32);
}

static void test_empty_strings(void)
{
    const char *s1 = "";
    const char *s2 = "";
    assert(ft_strncmp(s1, s2, 1) == strncmp(s1, s2, 1));
}

void test_ft_strncmp(void)
{
    test_identical_strings();
    test_different_strings();
    test_partial_comparison();
    test_zero_length();
    test_null_bytes();
    test_unsigned_comparison();
    test_different_lengths();
    test_empty_strings();
}