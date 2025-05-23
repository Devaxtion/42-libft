#include "../testlib.h"

static void content_deleter(void *content)
{
    free(content);
}

static void test_clear_empty_list(void)
{
    t_list *lst = NULL;
    ft_lstclear(&lst, content_deleter);
    assert(lst == NULL);
}

static void test_clear_single_node_list(void)
{
    char *str = strdup("Node content");
    t_list *lst = ft_lstnew(str);
    
    ft_lstclear(&lst, content_deleter);
    assert(lst == NULL);
    // Can't assert content is freed, but shouldn't crash
}

static void test_clear_multiple_node_list(void)
{
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew(strdup("Node 1"));
    t_list *node2 = ft_lstnew(strdup("Node 2"));
    t_list *node3 = ft_lstnew(strdup("Node 3"));
    
    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);
    ft_lstadd_back(&lst, node3);
    
    ft_lstclear(&lst, content_deleter);
    assert(lst == NULL);
}

static void test_null_list_pointer(void)
{
    // Should not crash when passed NULL list pointer
    ft_lstclear(NULL, content_deleter);
}

static void test_mixed_content_types(void)
{
    int *num = malloc(sizeof(int));
    *num = 42;
    t_list *lst = ft_lstnew(num);
    
    ft_lstclear(&lst, content_deleter);
    assert(lst == NULL);
}

void test_ft_lstclear(void)
{
    TEST_START();
    test_clear_empty_list();
    test_clear_single_node_list();
    test_clear_multiple_node_list();
    test_null_list_pointer();
    test_mixed_content_types();
    TEST_PASS();
}