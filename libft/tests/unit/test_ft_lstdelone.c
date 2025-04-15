#include "../testlib.h"

static void simple_free(void *content)
{
    free(content);
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
    free(str); // Clean up since del wasn't called
}

static void test_null_node(void)
{
    // Should not crash when passed NULL node
    ft_lstdelone(NULL, simple_free);
}

void test_ft_lstdelone(void)
{
    test_free_node_with_content();
    test_free_node_with_null_content();
    test_free_node_with_null_del();
    test_null_node();
}