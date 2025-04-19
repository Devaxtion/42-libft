#include "../testlib.h"

static int freed_count = 0;
static void simple_free(void *content)
{
    free(content);
    freed_count++;
}

static void test_free_counting(void)
{
    freed_count = 0;
    char *str = strdup("Test content");
    t_list *node = ft_lstnew(str);
    
    ft_lstdelone(node, simple_free);
    assert(freed_count == 1);  // Verify deleter was called
}

static void test_free_node_with_content(void)
{
    char *str = strdup("Test content");
    t_list *node = ft_lstnew(str);
    
    ft_lstdelone(node, simple_free);
    // Can't assert much here since memory is freed
    // Mainly checking it doesn't crash
}

static void test_free_node_with_null_content(void)
{
    t_list *node = ft_lstnew(NULL);
    
    ft_lstdelone(node, simple_free);
    // Should handle NULL content gracefully
}

static void test_free_node_with_null_del(void)
{
    char *str = strdup("Test content");
    t_list *node = ft_lstnew(str);
    
    ft_lstdelone(node, NULL);
    // Should free node but not content when del is NULL
    assert(strcmp(str, "Test content") == 0);
    free(str); // Clean up since del wasn't called
}

static void test_null_node(void)
{
    // Should not crash when passed NULL node
    ft_lstdelone(NULL, simple_free);
}

static void test_next_pointer_unmodified(void)
{
    char *str1 = strdup("Node1");
    char *str2 = strdup("Node2");
    t_list *node1 = ft_lstnew(str1);
    t_list *node2 = ft_lstnew(str2);
    node1->next = node2;
    
    ft_lstdelone(node1, simple_free);
    // node2 should still exist and be valid
    assert(strcmp(node2->content, "Node2") == 0);
    ft_lstdelone(node2, simple_free);
}

static void test_int_content(void)
{
    int *num = malloc(sizeof(int));
    *num = 42;
    t_list *node = ft_lstnew(num);
    
    ft_lstdelone(node, simple_free);
    // Mainly checking it doesn't crash
}

void test_ft_lstdelone(void)
{
    TEST_START();
    test_free_counting();
    test_free_node_with_content();
    test_free_node_with_null_content();
    test_free_node_with_null_del();
    test_null_node();
    test_next_pointer_unmodified();
    test_int_content();
    TEST_PASS();
}