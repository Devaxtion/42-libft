#include <stdio.h>

// Define a list of test functions
#define TEST_LIST \
    X(test_ft_atoi) \
    X(test_ft_bzero) \
    X(test_ft_calloc) \
    X(test_ft_isalnum) \
    X(test_ft_isalpha) \
    X(test_ft_isascii) \
    X(test_ft_isdigit) \
    X(test_ft_isprint) \
    X(test_ft_memchr) \
    X(test_ft_memcmp) \
    X(test_ft_memcpy) \
    X(test_ft_memset) \
    X(test_ft_strchr) \
    X(test_ft_strdup) \
    X(test_ft_strlcat) \
    X(test_ft_strlcpy) \
    X(test_ft_strlen) \
    X(test_ft_strncmp) \
    X(test_ft_strnstr) \
    X(test_ft_strrchr) \
    X(test_ft_tolower) \
    X(test_ft_toupper)

// Generate function declarations
#define X(test) void test(void);
TEST_LIST
#undef X

int main() {
    printf("Running libft tests...\n");

    // Call each test function
    #define X(test) test();
    TEST_LIST
    #undef X

    printf("All tests passed!\n");
    return 0;
}