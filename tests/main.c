#include <stdio.h>
#include <time.h>
#include "testlib.h"

// Part 1 (22 files)
#define TEST_LIST_P1 \
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
    X(test_ft_memmove) \
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

// Part 2 (7 files)
#define TEST_LIST_P2 \
    X(test_ft_substr) \
    X(test_ft_strjoin) \
    X(test_ft_strtrim) \
    X(test_ft_split) \
    X(test_ft_itoa) \
    X(test_ft_strmapi) \
    X(test_ft_striteri)

// Bonus (9 files)
#define TEST_LIST_BONUS \
    X(test_ft_lstnew) \
    X(test_ft_lstadd_front) \
    X(test_ft_lstsize) \
    X(test_ft_lstlast) \
    X(test_ft_lstadd_back) \
    X(test_ft_lstdelone) \
    X(test_ft_lstclear) \
    X(test_ft_lstiter) \
    X(test_ft_lstmap)

// Generate function declarations
#define X(test) int test(void);
TEST_LIST_P1
TEST_LIST_P2
TEST_LIST_BONUS
#undef X

int main() {
    printf(COLOR_CYAN "=== Running libft tests ===\n\n" COLOR_RESET);

    #define X(test) test();

    printf(COLOR_YELLOW "Part 1 Tests:\n" COLOR_RESET);
    TEST_LIST_P1
    
    printf(COLOR_YELLOW "Part 2 Tests:\n" COLOR_RESET);
    TEST_LIST_P2
    
    printf(COLOR_YELLOW "Bonus Tests:\n" COLOR_RESET);
    TEST_LIST_BONUS
    
    #undef X

    printf(COLOR_GREEN "\nAll tests completed!\n" COLOR_RESET);
    return (0);
}
