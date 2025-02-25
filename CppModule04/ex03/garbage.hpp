#pragma once

#include "AMateria.hpp"

class AMateria;

typedef struct s_garbage
{
    AMateria *ptr;
    struct s_garbage *next;
} t_garbage;

void	ft_lstadd_back(t_garbage **lst, t_garbage *newlst);
t_garbage	*ft_lstnew(AMateria *content);
void	ft_lstclear(t_garbage **lst);