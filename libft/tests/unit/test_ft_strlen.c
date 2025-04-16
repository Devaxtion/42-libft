#include "../testlib.h"

static void test_normal_cases() {
    assert(ft_strlen("") == strlen(""));
    assert(ft_strlen("hello") == strlen("hello"));
    assert(ft_strlen("42") == strlen("42"));
}

static void test_long_strings() {
    char long_str[1000] = {0};
    memset(long_str, 'a', 999);
    assert(ft_strlen(long_str) == strlen(long_str));
}

static void test_special_chars() {
    assert(ft_strlen("\n\t\r") == strlen("\n\t\r"));
    assert(ft_strlen("\0hidden") == strlen("\0hidden"));
    assert(ft_strlen("çåéî") == strlen("çåéî"));
}

void test_ft_strlen()
{
    TEST_START();
    test_normal_cases();
    test_long_strings();
    test_special_chars(); 
    TEST_PASS();
}
