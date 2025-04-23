#include "../testlib.h"

static void test_normal_move(void)
{
    char src[] = "Hello, world!";
    char dest1[20];
    char dest2[20];

    ft_memmove(dest1, src, strlen(src) + 1);
    memmove(dest2, src, strlen(src) + 1);

    assert(memcmp(dest1, dest2, strlen(src) + 1) == 0);
}

static void test_partial_move(void)
{
    char src[] = "Partial move";
    char dest1[20] = {0};
    char dest2[20] = {0};

    ft_memmove(dest1, src, 7);
    memmove(dest2, src, 7);

    assert(memcmp(dest1, dest2, 20) == 0);
}

static void test_zero_length_move(void)
{
    char src[] = "Shouldn't move";
    char dest1[20] = "Original";
    char dest2[20] = "Original";

    ft_memmove(dest1, src, 0);
    memmove(dest2, src, 0);

    assert(strcmp(dest1, dest2) == 0);
}

static void test_non_string_data_move(void)
{
    int src[] = {1, 2, 3, 4, 5};
    int dest1[5] = {0};
    int dest2[5] = {0};

    ft_memmove(dest1, src, sizeof(src));
    memmove(dest2, src, sizeof(src));

    assert(memcmp(dest1, dest2, sizeof(src)) == 0);
}

static void test_overlap_forward(void)
{
    char buffer1[20] = "1234567890";
    char buffer2[20] = "1234567890";

    ft_memmove(buffer1 + 2, buffer1, 8);  // overlap: dest after src
    memmove(buffer2 + 2, buffer2, 8);

    assert(memcmp(buffer1, buffer2, 20) == 0);
}

static void test_overlap_backward(void)
{
    char buffer1[20] = "abcdefghij";
    char buffer2[20] = "abcdefghij";

    ft_memmove(buffer1, buffer1 + 2, 8);  // overlap: dest before src
    memmove(buffer2, buffer2 + 2, 8);

    assert(memcmp(buffer1, buffer2, 20) == 0);
}

static void test_return_value_move(void)
{
    char src[] = "Test return";
    char dest1[20];
    char dest2[20];

    void *ret1 = ft_memmove(dest1, src, strlen(src) + 1);
    void *ret2 = memmove(dest2, src, strlen(src) + 1);

    assert(ret1 == dest1);
    assert(ret2 == dest2);
}

void test_ft_memmove(void)
{
    TEST_START();
    test_normal_move();
    test_partial_move();
    test_zero_length_move();
    test_non_string_data_move();
    test_overlap_forward();
    test_overlap_backward();
    test_return_value_move();
    TEST_PASS();
}
