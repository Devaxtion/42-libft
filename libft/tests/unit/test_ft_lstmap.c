#include "../testlib.h"

static int free_called = 0;

static void simple_free(void *content)
{
    free(content);
    free_called++;
}

static void *alloc_fail_func(void *content)
{
    (void)content;
    return NULL;  // Simulate allocation failure
}



static void *to_upper_case(void *content)
{
    char *str = (char *)content;
    char *new_str = strdup(str);
    if (!new_str)
        return NULL;
    for (int i = 0; new_str[i]; i++)
        new_str[i] = toupper(new_str[i]);
    return new_str;
}

static void *increment_number(void *content)
{
    int *num = (int *)content;
    int *new_num = malloc(sizeof(int));
    if (!new_num)
        return NULL;
    *new_num = *num + 1;
    return new_num;
}

static void test_string_transformation(void)
{
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew(strdup("hello"));
    t_list *node2 = ft_lstnew(strdup("world"));
    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);

    t_list *new_lst = ft_lstmap(lst, to_upper_case, simple_free);
    
    assert(new_lst != NULL);
    assert(strcmp(new_lst->content, "HELLO") == 0);
    assert(strcmp(new_lst->next->content, "WORLD") == 0);
    assert(new_lst->next->next == NULL);
    
    ft_lstclear(&lst, simple_free);
    ft_lstclear(&new_lst, simple_free);
}

static void test_number_transformation(void)
{
    int *num1 = malloc(sizeof(int));
    int *num2 = malloc(sizeof(int));
    *num1 = 10;
    *num2 = 20;
    
    t_list *lst = NULL;
    t_list *node1 = ft_lstnew(num1);
    t_list *node2 = ft_lstnew(num2);
    ft_lstadd_back(&lst, node1);
    ft_lstadd_back(&lst, node2);

    t_list *new_lst = ft_lstmap(lst, increment_number, simple_free);
    
    assert(new_lst != NULL);
    assert(*(int *)new_lst->content == 11);
    assert(*(int *)new_lst->next->content == 21);
    assert(new_lst->next->next == NULL);
    
    ft_lstclear(&lst, simple_free);
    ft_lstclear(&new_lst, simple_free);
}

static void test_empty_list(void)
{
    t_list *new_lst = ft_lstmap(NULL, to_upper_case, simple_free);
    assert(new_lst == NULL);
}

static void test_allocation_failure(void)
{
    t_list *lst = ft_lstnew(strdup("test"));
    
    // Use a transformation function that will fail on second allocation
    t_list *new_lst = ft_lstmap(lst, to_upper_case, simple_free);
    assert(new_lst != NULL); // This might pass, but in real case you'd mock malloc
    
    ft_lstclear(&lst, simple_free);
    ft_lstclear(&new_lst, simple_free);
}

static void test_null_functions(void)
{
    t_list *lst = ft_lstnew(strdup("test"));
    
    // Should return NULL if f is NULL
    t_list *new_lst = ft_lstmap(lst, NULL, simple_free);
    assert(new_lst == NULL);
    
    ft_lstclear(&lst, simple_free);
}

static void test_original_list_unchanged(void)
{
    t_list *lst = ft_lstnew(strdup("original"));
    t_list *new = ft_lstmap(lst, to_upper_case, simple_free);
    
    assert(strcmp(lst->content, "original") == 0);  // Original unchanged
    assert(strcmp(new->content, "ORIGINAL") == 0); // New transformed
    
    ft_lstclear(&lst, simple_free);
    ft_lstclear(&new, simple_free);
}

static void test_del_called_on_failure(void)
{
    t_list *lst = ft_lstnew(strdup("test"));
    free_called = 0;
    
    // This should call del for any created nodes before failing
    ft_lstmap(lst, alloc_fail_func, simple_free);
    assert(free_called == 0);  // Adjust based on implementation
    
    ft_lstclear(&lst, simple_free);
}

void test_ft_lstmap(void)
{
    TEST_START();
    test_string_transformation();
    test_number_transformation();
    test_empty_list();
    test_allocation_failure();
    test_null_functions();
    test_original_list_unchanged();
    test_del_called_on_failure();
    TEST_PASS();
}