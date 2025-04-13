#include "../testlib.h"

static void test_normal_cases() {
    assert(ft_atoi("42") == atoi("42"));
    assert(ft_atoi("-42") == atoi("-42"));
    assert(ft_atoi("+42") == atoi("+42"));
    assert(ft_atoi("0") == atoi("0"));
    assert(ft_atoi("2147483647") == atoi("2147483647")); // INT_MAX
    assert(ft_atoi("-2147483648") == atoi("-2147483648")); // INT_MIN
}

static void test_whitespace_cases() {
    assert(ft_atoi(" \t\n\r\v\f42") == atoi(" \t\n\r\v\f42"));
    assert(ft_atoi(" \t\n\r\v\f-42") == atoi(" \t\n\r\v\f-42"));
    assert(ft_atoi("    42") == atoi("    42"));
    assert(ft_atoi("\t\t-42") == atoi("\t\t-42"));
}

static void test_multiple_signs() {
    assert(ft_atoi("+-42") == atoi("+-42"));
    assert(ft_atoi("-+42") == atoi("-+42"));
    assert(ft_atoi("++42") == atoi("++42"));
    assert(ft_atoi("--42") == atoi("--42"));
    assert(ft_atoi("-+-+-42") == atoi("-+-+-42"));
}

static void test_mixed_cases() {
    assert(ft_atoi("  +42abc") == atoi("  +42abc"));
    assert(ft_atoi("42abc") == atoi("42abc"));
    assert(ft_atoi("-42abc") == atoi("-42abc"));
    assert(ft_atoi("abc42") == atoi("abc42"));
    assert(ft_atoi("123abc456") == atoi("123abc456"));
}

static void test_overflow_cases() {
    // Note: Behavior might differ from standard atoi for overflow cases
    assert(ft_atoi("2147483648") == atoi("2147483648")); // INT_MAX + 1
    assert(ft_atoi("-2147483649") == atoi("-2147483649")); // INT_MIN - 1
    assert(ft_atoi("99999999999999999999") == atoi("99999999999999999999"));
    assert(ft_atoi("-99999999999999999999") == atoi("-99999999999999999999"));
}

static void test_empty_string() {
    assert(ft_atoi("") == atoi(""));
    assert(ft_atoi("    ") == atoi("    "));
    assert(ft_atoi("  \t\n") == atoi("  \t\n"));
}

void test_ft_atoi() {
    test_normal_cases();
    test_whitespace_cases();
    test_multiple_signs();
    test_mixed_cases();
    test_overflow_cases();
    test_empty_string();
}
