#include "../testlib.h"

#include <assert.h>
#include <stdlib.h>
#include "../../libft.h"

static void test_add_to_empty_list(void)
{
    t_list *lst = NULL;
    t_list *new = ft_lstnew("First");
    
    ft_lstadd_front(&lst, new);
    assert(lst == new);
    assert(lst->next == NULL);
    assert(strcmp(lst->content, "First") == 0);
    free(new);
}

static void test_add_to_existing_list(void)
{
    t_list *lst = ft_lstnew("Second");
    t_list *new = ft_lstnew("First");

    ft_lstadd_front(&lst, new);
    assert(lst == new);
    assert(lst->next != NULL);
    assert(strcmp(lst->content, "First") == 0);
    assert(strcmp(lst->next->content, "Second") == 0);

    t_list *temp = lst->next;
    free(lst);
    free(temp);

}

static void test_add_multiple_nodes(void)
{
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew("Third");
    t_list *node2 = ft_lstnew("Second");
    t_list *node3 = ft_lstnew("First");
    
    ft_lstadd_front(&lst, node1);
    ft_lstadd_front(&lst, node2);
    ft_lstadd_front(&lst, node3);
    
    assert(lst == node3);
    assert(lst->next == node2);
    assert(lst->next->next == node1);
    assert(lst->next->next->next == NULL);
    
    free(node1);
    free(node2);
    free(node3);
}

static void test_null_parameters(void)
{
    t_list *lst = NULL;
    t_list *new = ft_lstnew("Test");
    
    // Should not crash when given NULL parameters
    ft_lstadd_front(NULL, new);
    ft_lstadd_front(&lst, NULL);
    ft_lstadd_front(NULL, NULL);
    
    free(new);
}

void test_ft_lstadd_front(void)
{
    TEST_START();
    test_add_to_empty_list();
    test_add_to_existing_list();
    test_add_multiple_nodes();
    test_null_parameters();
    TEST_PASS();
}