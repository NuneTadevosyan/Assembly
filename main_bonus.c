/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntadevos <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/01 17:34:40 by ntadevos          #+#    #+#             */
/*   Updated: 2021/05/01 17:35:20 by ntadevos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

/*
** Useful macro
*/
# define ATOI_BASE(s, b)	i = ft_atoi_base(s, b); printf("`%s`[%s] = %d\n", s, b, i);

typedef struct	s_list
{
	void			*data;
	struct s_list	*next;
}				t_list;

/*
** print a list elements one by line
*/
void
	printf_list(t_list *list)
{
	while (list)
	{
		printf("; %s\n", list->data);
		list = list->next;
	}
}

/*
** free a whole list and it's data field
*/
void
	ft_lstclear(t_list **list)
{
	t_list	*tmp;

	while (*list)
	{
		tmp = (*list)->next;
		if ((*list)->data)
			free((*list)->data);
		free(*list);
		*list = tmp;
	}
}

/*
** Function prototypes
*/
int		ft_atoi_base(char const *str, char const *base);

void	ft_list_push_front(t_list **begin_list, void *data);

int		ft_list_size(t_list *begin_list);

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void*));

void	ft_list_sort(t_list **begin_list,int (*cmp)());

/*
** Start !
*/
int		main(void)
{
	int	i = 0;

	t_list	list;
	t_list	list_next;
	t_list	list_last;
	list.data = strdup("toto");
	list.next = &list_next;
	list_next.data = strdup("bar");
	list_next.next = &list_last;
	list_last.data = strdup("monkaS");
	list_last.next = NULL;
	printf("\n--ft_list_size\n");
	printf("list content:\n");
	printf_list(&list);
	printf("%d (from first %d)\n", ft_list_size(&list), 3);
	printf("%d (from second %d)\n", ft_list_size(&list_next), 2);
	printf("%d (NULL %d)\n", ft_list_size(NULL), 0);
	printf("%d (from last %d)\n", ft_list_size(&list_last), 1);
	printf("-done\n");
	free(list_next.data);
	free(list_last.data);

	printf("\n--ft_list_push_front\n");
	t_list	*push_test = &list;
	ft_list_push_front(&push_test, strdup("toto"));
	printf("added: `%s` (next: %p)\n", push_test->data, push_test->next);
	printf("new list size: %d (%d)\n", ft_list_size(push_test), 4);
	free(list.data);
	free(push_test->data);
	free(push_test);
	push_test = NULL;
	ft_list_push_front(&push_test, strdup("barbar"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_list_push_front(&push_test, NULL);
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	free(push_test->next);
	push_test->next = NULL;
	ft_list_push_front(&push_test, strdup("toto_r"));
	printf("added: `%s` (s%p : n%p)\n", push_test->data, push_test, push_test->next);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf("\n--ft_list_remove_if\n");
	ft_list_push_front(&push_test, strdup("toto"));
	ft_list_push_front(&push_test, strdup("barbar"));
	ft_list_push_front(&push_test, strdup("tortor"));
	ft_list_push_front(&push_test, NULL);
	printf("before:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	printf("nothing removed:\n");
	printf_list(push_test);
	ft_list_remove_if(&push_test, "toto", &strcmp, &free);
	ft_list_remove_if(&push_test, "tortor", &strcmp, &free);
	ft_list_remove_if(&push_test, "barbar", &strcmp, &free);
	ft_list_remove_if(&push_test, "", &strcmp, &free);
	ft_list_remove_if(&push_test, NULL, &strcmp, &free);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("-done\n");

	printf("\n--ft_list_sort\n");
	ft_list_push_front(&push_test, strdup("zwxy"));
	ft_list_push_front(&push_test, strdup("toto"));
	ft_list_push_front(&push_test, strdup("0123456"));
	ft_list_push_front(&push_test, strdup("barbar"));
	ft_list_push_front(&push_test, strdup("rooooom"));
	ft_list_push_front(&push_test, strdup("lol"));
	ft_list_push_front(&push_test, strdup("tortor"));
	ft_list_push_front(&push_test, strdup("mdr"));
	ft_list_push_front(&push_test, strdup("0547"));
	ft_list_push_front(&push_test, strdup("000"));
	ft_list_push_front(&push_test, strdup("zzz"));
	printf("before:\n");
	printf_list(push_test);
	ft_list_sort(&push_test, &strcmp);
	printf("after:\n");
	printf_list(push_test);
	ft_lstclear(&push_test);
	printf("sort NULL:\n");
	ft_list_sort(NULL, &strcmp);
	ft_list_sort(&push_test, &strcmp);
	printf("-done\n");

	return (0);
}
