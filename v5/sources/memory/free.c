#include "../../includes/memory.h"

t_node_malloc *_memory_check(t_node_malloc **list, void *ptr)
{
    if (list && *list && ptr)
    {
        while (*list)
        {
            if ((*list)->ptr == ptr)
                return (*list);
            list = &(*list)->next;
        }
    }
    return (NULL);
}

void _memory_free(void *ptr)
{
    t_node_malloc **list;
    t_node_malloc *node;

    list = _memory_list();
    node = _memory_check(list, ptr);
    if (!*list || !node)
        return;
    if (*list && *list == node)
        *list = node->next;
    if (node->next)
        node->next->prev = node->prev;
    if (node->prev)
        node->prev->next = node->next;
    if (*list)
    {
        free(node->ptr);
        free(node);
    }
}

void _memory_free_all(void)
{
    while (*_memory_list())
        _memory().free(*_memory_list());
}