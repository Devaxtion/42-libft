#include "../testlib.h"

static void test_normal_concatenation(void)
{
    char dst[20] = "Hello";
    const char *src = " World";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
    
    assert(strcmp(dst, "Hello World") == 0);
    assert(result == strlen("Hello") + strlen(" World"));
}

static void test_exact_fit(void)
{
    char dst[12] = "Hello";
    const char *src = " World";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
    
    assert(strcmp(dst, "Hello World") == 0);
    assert(result == strlen("Hello") + strlen(" World"));
}

static void test_truncation(void)
{
    char dst[10] = "Hello";
    const char *src = " World";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
    
    assert(strncmp(dst, "Hello Wor", sizeof(dst) - 1) == 0);
    assert(result == strlen("Hello") + strlen(" World"));
}

static void test_zero_size(void)
{
    char dst[20] = "Hello";
    const char *src = " World";
    size_t result = ft_strlcat(dst, src, 0);
    
    assert(strcmp(dst, "Hello") == 0);
    assert(result == strlen(src));
}

static void test_empty_destination(void)
{
    char dst[20] = "";
    const char *src = "Hello";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
    
    assert(strcmp(dst, "Hello") == 0);
    assert(result == strlen("Hello"));
}

static void test_empty_source(void)
{
    char dst[20] = "Hello";
    const char *src = "";
    size_t result = ft_strlcat(dst, src, sizeof(dst));
    
    assert(strcmp(dst, "Hello") == 0);
    assert(result == strlen("Hello"));
}

static void test_no_null_terminator(void)
{
    char dst[20] = {'H', 'i', '\0'};
    const char *src = " There";
    size_t result = ft_strlcat(dst, src, 5);  // Only space for 2 more chars
    
    assert(memcmp(dst, "Hi T", 5) == 0);
    assert(result == strlen("Hi") + strlen(" There"));
}

void test_ft_strlcat(void)
{
    test_normal_concatenation();
    test_exact_fit();
    test_truncation();
    test_zero_size();
    test_empty_destination();
    test_empty_source();
    test_no_null_terminator();
}