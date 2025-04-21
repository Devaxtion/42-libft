#include "../testlib.h"

static void test_normal_cases() {
    assert(ft_atoi("42") == 42);
    assert(ft_atoi("-42") == -42);
    assert(ft_atoi("+42") == 42);
    assert(ft_atoi("0") == 0);
    assert(ft_atoi("2147483647") == INT_MAX);
    assert(ft_atoi("-2147483648") == INT_MIN);
}

static void test_whitespace_cases() {
    assert(ft_atoi(" \t\n\r\v\f42") == 42);
    assert(ft_atoi(" \t\n\r\v\f-42") == -42);
    assert(ft_atoi("    42") == 42);
    assert(ft_atoi("\t\t-42") == -42);
}

static void test_multiple_signs() {
    assert(ft_atoi("+-42") == 0);
    assert(ft_atoi("-+42") == 0);
    assert(ft_atoi("++42") == 0);
    assert(ft_atoi("--42") == 0);
    assert(ft_atoi("-+-+-42") == 0);
}

static void test_mixed_cases() {
    assert(ft_atoi("  +42abc") == 42);
    assert(ft_atoi("42abc") == 42);
    assert(ft_atoi("-42abc") == -42);
    assert(ft_atoi("abc42") == 0);
    assert(ft_atoi("123abc456") == 123);
    assert(ft_atoi("42!@#") == 42);
    assert(ft_atoi("-42!@#") == -42);
}

static void test_empty_string() {
    assert(ft_atoi("") == 0);
    assert(ft_atoi("    ") == 0);
    assert(ft_atoi("  \t\n") == 0);
}

void test_ft_atoi() {
    TEST_START();
    test_normal_cases();
    test_whitespace_cases();
    test_multiple_signs();
    test_mixed_cases();
    test_empty_string();
    TEST_PASS();
}
