#include "../testlib.h"

static void test_normal_copy(void)
{
    char dst[20];
    const char *src = "Hello World";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(strcmp(dst, "Hello World") == 0);
    assert(result == strlen(src));
}

static void test_exact_fit(void)
{
    char dst[12];
    const char *src = "Hello World";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(strcmp(dst, "Hello World") == 0);
    assert(result == strlen(src));
}

static void test_truncation(void)
{
    char dst[6];
    const char *src = "Hello World";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(strcmp(dst, "Hello") == 0);
    assert(result == strlen(src));
}

static void test_zero_size(void)
{
    char dst[20] = "Original";
    const char *src = "Hello World";
    size_t result = ft_strlcpy(dst, src, 0);

    assert(strcmp(dst, "Original") == 0);
    assert(result == strlen(src));
}

static void test_empty_source(void)
{
    char dst[20] = "Original";
    const char *src = "";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(strcmp(dst, "") == 0);
    assert(result == 0);
}

static void test_one_byte_buffer(void)
{
    char dst[1];
    const char *src = "Hello";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(dst[0] == '\0');
    assert(result == strlen(src));
}

static void test_no_null_termination_needed(void)
{
    char dst[5];
    const char *src = "Test";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));

    assert(strcmp(dst, "Test") == 0);
    assert(result == strlen(src));
}

static void test_source_longer_than_dstsize(void)
{
    char dst[5];
    const char *src = "This is much longer";
    size_t result = ft_strlcpy(dst, src, sizeof(dst));
    
    assert(strcmp(dst, "This") == 0);
    assert(result == strlen(src));
}

void test_ft_strlcpy(void)
{
    TEST_START();
    test_normal_copy();
    test_exact_fit();
    test_truncation();
    test_zero_size();
    test_empty_source();
    test_one_byte_buffer();
    test_no_null_termination_needed();
    test_source_longer_than_dstsize();
    TEST_PASS();
}