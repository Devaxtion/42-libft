#include "../testlib.h"

static void test_normal_allocation(void)
{
    size_t nmemb = 5;
    size_t size = sizeof(int);
    int *arr = ft_calloc(nmemb, size);
    int *sys_arr = calloc(nmemb, size);

    assert(arr != NULL);
    assert(sys_arr != NULL);
    assert(memcmp(arr, sys_arr, nmemb * size) == 0);
    free(arr);
    free(sys_arr);
}

static void test_zero_nmemb(void)
{
    size_t nmemb = 0;
    size_t size = sizeof(int);
    int *arr = ft_calloc(nmemb, size);

    assert(arr != NULL);
    free(arr);
}

static void test_zero_size(void)
{
    size_t nmemb = 5;
    size_t size = 0;
    int *arr = ft_calloc(nmemb, size);

    assert(arr != NULL);
    free(arr);
}

static void test_both_zero(void)
{
    size_t nmemb = 0;
    size_t size = 0;
    int *arr = ft_calloc(nmemb, size);

    assert(arr != NULL);
    free(arr);
}

static void test_large_allocation(void)
{
    size_t nmemb = 10000;
    size_t size = sizeof(char);
    char *arr = ft_calloc(nmemb, size);
    char *sys_arr = calloc(nmemb, size);

    assert(arr != NULL);
    assert(sys_arr != NULL);
    assert(memcmp(arr, sys_arr, nmemb * size) == 0);
    free(arr);
    free(sys_arr);
}

static void test_content_initialization(void)
{
    size_t nmemb = 10;
    size_t size = sizeof(char);
    char *arr = ft_calloc(nmemb, size);

    for (size_t i = 0; i < nmemb; i++)
    {
        assert(arr[i] == 0);
    }
    free(arr);
}

void test_ft_calloc(void)
{
    TEST_START();
    test_normal_allocation();
    test_zero_nmemb();
    test_zero_size();
    test_both_zero();
    test_large_allocation();
    test_content_initialization();
    TEST_PASS();
}
