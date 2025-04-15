#include "../testlib.h"

static void test_add_to_empty_list(void)
{
    t_list *lst = NULL;
    t_list *new = ft_lstnew("New node");
    
    ft_lstadd_back(&lst, new);
    assert(lst == new);
    assert(lst->next == NULL);
    free(new);
}

static void test_add_to_single_node_list(void)
{
    t_list *lst = ft_lstnew("First node");
    t_list *new = ft_lstnew("New node");
    
    ft_lstadd_back(&lst, new);
    assert(lst->next == new);
    assert(new->next == NULL);
    
    free(lst);
    free(new);
}

static void test_add_to_multiple_node_list(void)
{
    t_list *node1 = ft_lstnew("Node 1");
    t_list *node2 = ft_lstnew("Node 2");
    t_list *new = ft_lstnew("New node");
    
    node1->next = node2;
    ft_lstadd_back(&node1, new);
    
    assert(node2->next == new);
    assert(new->next == NULL);
    
    free(node1);
    free(node2);
    free(new);
}

static void test_null_parameters(void)
{
    t_list *lst = NULL;
    t_list *new = ft_lstnew("Test");
    
    // Should not crash with NULL parameters
    ft_lstadd_back(NULL, new);
    ft_lstadd_back(&lst, NULL);
    ft_lstadd_back(NULL, NULL);
    
    free(new);
}

static void test_multiple_additions(void)
{
    t_list *lst = NULL;
    t_list *nodes[3];
    int i;
    
    for (i = 0; i < 3; i++)
    {
        nodes[i] = ft_lstnew("Node");
        ft_lstadd_back(&lst, nodes[i]);
    }
    
    assert(lst == nodes[0]);
    assert(lst->next == nodes[1]);
    assert(lst->next->next == nodes[2]);
    assert(lst->next->next->next == NULL);
    
    for (i = 0; i < 3; i++)
        free(nodes[i]);
}

void test_ft_lstadd_back(void)
{
    test_add_to_empty_list();
    test_add_to_single_node_list();
    test_add_to_multiple_node_list();
    test_null_parameters();
    test_multiple_additions();
}