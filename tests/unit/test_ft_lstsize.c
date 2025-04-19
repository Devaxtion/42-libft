#include "../testlib.h"

static void test_empty_list(void)
{
    assert(ft_lstsize(NULL) == 0);
}

static void test_single_node_list(void)
{
    t_list *lst = ft_lstnew("Node 1");
    assert(ft_lstsize(lst) == 1);
    free(lst);
}

static void test_multiple_node_list(void)
{
    t_list *lst = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");
    
    lst->next = node2;
    node2->next = node3;
    
    assert(ft_lstsize(lst) == 3);
    
    free(lst);
    free(node2);
    free(node3);
}

static void test_large_list(void)
{
    t_list *lst = NULL;
    t_list *new;
    int count = 100;
    int i;
    
    // Create a list with 100 nodes
    for (i = 0; i < count; i++)
    {
        new = ft_lstnew("Node");
        ft_lstadd_front(&lst, new);
    }
    
    assert(ft_lstsize(lst) == count);
    
    // Free all nodes
    while (lst)
    {
        new = lst->next;
        free(lst);
        lst = new;
    }
}

void test_ft_lstsize(void)
{
    TEST_START();
    test_empty_list();
    test_single_node_list();
    test_multiple_node_list();
    test_large_list();
    TEST_PASS();
}