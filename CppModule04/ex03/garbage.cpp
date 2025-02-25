#include "garbage.hpp"

int	ft_lstsize(t_garbage *lst)
{
	int	count;

	if (!lst)
		return (0);
	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

t_garbage	*ft_lstlast(t_garbage *lst)
{
	int	last;

	last = ft_lstsize(lst);
	while (last-- > 1)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back(t_garbage **lst, t_garbage *newlst)
{
	t_garbage	*head;

	if (!lst)
		return ;
	if (!*lst)
		*lst = newlst;
	else
	{
		head = ft_lstlast(*lst);
		head->next = newlst;
	}
}

t_garbage	*ft_lstnew(AMateria *content)
{
	t_garbage	*head;

	head = new t_garbage;
	if (!head)
		return (NULL);
	head->ptr = content;
	head->next = NULL;
	return (head);
}

void	ft_lstdelone(t_garbage *lst)
{
	if (lst)
	{
		if (lst->ptr != NULL)
		{
			delete lst->ptr;
			lst->ptr = NULL;
		}
		delete lst;
		lst = NULL;
	}
}

void	ft_lstclear(t_garbage **lst)
{
	t_garbage	*next;
	if (!lst)
		return ;
	while (*lst)
	{
		next = (*lst)->next;
		ft_lstdelone(*lst);
		*lst = next;
	}
}