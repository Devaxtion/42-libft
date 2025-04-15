#include "../testlib.h"

static void test_int_content(void)
{
    int num = 42;
    t_list *node = ft_lstnew(&num);
    
    assert(node != NULL);
    assert(*(int *)node->content == 42);
    assert(node->next == NULL);
    free(node);
}

static void test_string_content(void)
{
    char *str = "Hello, world!";
    t_list *node = ft_lstnew(str);
    
    assert(node != NULL);
    assert(strcmp(node->content, str) == 0);
    assert(node->next == NULL);
    free(node);
}

static void test_null_content(void)
{
    t_list *node = ft_lstnew(NULL);
    
    assert(node != NULL);
    assert(node->content == NULL);
    assert(node->next == NULL);
    free(node);
}

static void test_struct_content(void)
{
    typedef struct {
        int x;
        int y;
    } Point;
    
    Point p = {10, 20};
    t_list *node = ft_lstnew(&p);
    
    assert(node != NULL);
    assert(((Point *)node->content)->x == 10);
    assert(((Point *)node->content)->y == 20);
    assert(node->next == NULL);
    free(node);
}

void test_ft_lstnew(void)
{
    test_int_content();
    test_string_content();
    test_null_content();
    test_struct_content();
}