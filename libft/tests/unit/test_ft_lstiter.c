#include "../testlib.h"

static int counter = 0;

static void count_nodes(void *content)
{
    (void)content;
    counter++;
}

static void modify_content(void *content)
{
    char *str = (char *)content;
    if (str)
        str[0] = toupper(str[0]);
}

static void test_iterate_empty_list(void)
{
    counter = 0;
    ft_lstiter(NULL, count_nodes);
    assert(counter == 0);
}

static void test_count_nodes(void)
{
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew(strdup("node1"));
    t_list *node2 = ft_lstnew(strdup("node2"));
    t_list *node3 = ft_lstnew(strdup("node3"));
    
    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);
    ft_lstadd_back(&lst, node3);
    
    counter = 0;
    ft_lstiter(lst, count_nodes);
    assert(counter == 3);
    
    ft_lstclear(&lst, free);
}

static void test_modify_content(void)
{
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew(strdup("hello"));
    t_list *node2 = ft_lstnew(strdup("world"));
    
    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);
    
    ft_lstiter(lst, modify_content);
    
    assert(strcmp(node1->content, "Hello") == 0);
    assert(strcmp(node2->content, "World") == 0);
    
    ft_lstclear(&lst, free);
}

static void test_null_function_safety(void)
{
    t_list *lst = NULL;
    ft_lstadd_back(&lst, ft_lstnew(strdup("test1")));
    ft_lstadd_back(&lst, ft_lstnew(strdup("test2")));
    
    // Should not crash and should preserve content
    ft_lstiter(lst, NULL);
    
    assert(strcmp(lst->content, "test1") == 0);
    assert(strcmp(lst->next->content, "test2") == 0);
    
    ft_lstclear(&lst, free);
}

void test_ft_lstiter(void)
{
    TEST_START();
    test_iterate_empty_list();
    test_count_nodes();
    test_modify_content();
    test_null_function_safety();
    TEST_PASS();
}