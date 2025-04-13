#include "../testlib.h"

static void test_normal_string(void)
{
    const char *original = "Hello, world!";
    char *duplicate = ft_strdup(original);
    char *system_dup = strdup(original);

    assert(duplicate != NULL);
    assert(system_dup != NULL);
    assert(strcmp(duplicate, original) == 0);
    assert(strcmp(duplicate, system_dup) == 0);
    free(duplicate);
    free(system_dup);
}

static void test_empty_string(void)
{
    const char *original = "";
    char *duplicate = ft_strdup(original);
    char *system_dup = strdup(original);

    assert(duplicate != NULL);
    assert(system_dup != NULL);
    assert(strcmp(duplicate, original) == 0);
    assert(strcmp(duplicate, system_dup) == 0);
    free(duplicate);
    free(system_dup);
}

static void test_special_chars(void)
{
    const char *original = "\t\n\v\f\r";
    char *duplicate = ft_strdup(original);
    char *system_dup = strdup(original);

    assert(duplicate != NULL);
    assert(system_dup != NULL);
    assert(strcmp(duplicate, original) == 0);
    assert(strcmp(duplicate, system_dup) == 0);
    free(duplicate);
    free(system_dup);
}

static void test_null_termination(void)
{
    const char *original = "Test\0Hidden";
    size_t len = 5; // Length including null terminator
    char *duplicate = ft_strdup(original);
    char *system_dup = strdup(original);

    assert(duplicate != NULL);
    assert(system_dup != NULL);
    assert(memcmp(duplicate, original, len) == 0);
    assert(memcmp(duplicate, system_dup, len) == 0);
    free(duplicate);
    free(system_dup);
}

static void test_memory_allocation(void)
{
    // This test verifies the allocation size is correct
    const char *original = "Allocation test";
    size_t expected_len = strlen(original) + 1;
    char *duplicate = ft_strdup(original);

    assert(duplicate != NULL);
    // Verify we can write to all allocated bytes
    memset(duplicate, 'x', expected_len);
    free(duplicate);
}

void test_ft_strdup(void)
{
    test_normal_string();
    test_empty_string();
    test_special_chars();
    test_null_termination();
    test_memory_allocation();
}