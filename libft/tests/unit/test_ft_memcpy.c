#include "../testlib.h"

static void test_normal_copy(void)
{
    char src[] = "Hello, world!";
    char dest1[20];
    char dest2[20];
    
    ft_memcpy(dest1, src, strlen(src) + 1);
    memcpy(dest2, src, strlen(src) + 1);
    
    assert(memcmp(dest1, dest2, strlen(src) + 1) == 0);
}

static void test_partial_copy(void)
{
    char src[] = "Partial copy";
    char dest1[20] = {0};
    char dest2[20] = {0};
    
    ft_memcpy(dest1, src, 7);
    memcpy(dest2, src, 7);
    
    assert(memcmp(dest1, dest2, 20) == 0);
}

static void test_zero_length(void)
{
    char src[] = "Shouldn't copy";
    char dest1[20] = "Original";
    char dest2[20] = "Original";
    
    ft_memcpy(dest1, src, 0);
    memcpy(dest2, src, 0);
    
    assert(strcmp(dest1, dest2) == 0);
}

static void test_non_string_data(void)
{
    int src[] = {1, 2, 3, 4, 5};
    int dest1[5] = {0};
    int dest2[5] = {0};
    
    ft_memcpy(dest1, src, sizeof(src));
    memcpy(dest2, src, sizeof(src));
    
    assert(memcmp(dest1, dest2, sizeof(src)) == 0);
}

static void test_return_value(void)
{
    char src[] = "Test return";
    char dest1[20];
    char dest2[20];
    
    void *ret1 = ft_memcpy(dest1, src, strlen(src) + 1);
    void *ret2 = memcpy(dest2, src, strlen(src) + 1);
    
    assert(ret1 == dest1);
    assert(ret2 == dest2);
}

void test_ft_memcpy(void)
{
    test_normal_copy();
    test_partial_copy();
    test_zero_length();
    test_non_string_data();
    test_return_value();
}