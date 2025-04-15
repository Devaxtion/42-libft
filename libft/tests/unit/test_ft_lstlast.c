#include "../testlib.h"

static void test_empty_list(void)
{
    assert(ft_lstlast(NULL) == NULL);
}

static void test_single_node_list(void)
{
    t_list *lst = ft_lstnew("Only node");
    t_list *last = ft_lstlast(lst);
    
    assert(last == lst);
    assert(last->next == NULL);
    free(lst);
}

static void test_multiple_node_list(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *node3 = ft_lstnew("Node 3");
    
    node1->next = node2;
    node2->next = node3;
    
    t_list *last = ft_lstlast(node1);
    
    assert(last == node3);
    assert(last->next == NULL);
    
    free(node1);
    free(node2);
    free(node3);
}

static void test_large_list(void)
{
    t_list *lst = NULL;
    t_list *nodes[100];
    int i;
    
    // Create a list with 100 nodes
    for (i = 0; i < 100; i++)
    {
        nodes[i] = ft_lstnew("Node");
        ft_lstadd_front(&lst, nodes[i]);
    }
    
    t_list *last = ft_lstlast(lst);
    
    assert(last == nodes[0]);  // First added node is last in list
    assert(last->next == NULL);
    
    // Free all nodes
    while (lst)
    {
        t_list *tmp = lst->next;
        free(lst);
        lst = tmp;
    }
}

void test_ft_lstlast(void)
{
    test_empty_list();
    test_single_node_list();
    test_multiple_node_list();
    test_large_list();
}