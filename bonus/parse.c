#include "push_swap.h"

static int	is_existing(int n, t_list *list)
{
	while (list)
	{
		if (get_content_value(list) == n)
			return (1);
		list = list->next;
	}
	return (0);
}

int	is_sorted(t_list *list)
{
	while (list && list->next)
	{
		if (get_content_value(list->next) < get_content_value(list))
			return (0);
		list = list->next;
	}
	return (1);
}

static void	parse_error(t_list **list, char **parsed_args)
{
	int	i;

	i = 0;
	ft_putstr_fd("Error\n", 2);
	ft_lstclear(list, &free_stack_content);
	while (parsed_args && parsed_args[i])
	{
		free(parsed_args[i]);
		i++;
	}
	free(parsed_args);
	return ;
}

static char	**get_args(char **args, int argc, int *error)
{
	int		i;
	char	**parsed_args;

	i = 0;
	if (argc == 2)
		parsed_args = ft_split(args[1], ' ');
	else
	{
		parsed_args = malloc(sizeof(char *) * argc);
		if (!parsed_args) // Vérification de malloc
		{
			*error = 1;
			return (NULL);
		}
		i = 0;
		while (args[i + 1])
		{
			parsed_args[i] = ft_strdup(args[i + 1]);
			if (!parsed_args[i])
			{
				*error = 1;
				return (parsed_args);
			}
			i++;
		}
		parsed_args[i] = NULL;
	}
	return (parsed_args);
}

int	parse(char **args, int argc, t_list **a)
{
	int		i;
	int		error = 0; // Initialisation de error à 0
	long	*content;
	char	**parsed_args;

	parsed_args = get_args(args, argc, &error);
	if (error) // Vérification de l'erreur
		return (parse_error(a, parsed_args), 0);

	i = 0;
	content = NULL;
	while (parsed_args && parsed_args[i])
	{
		content = malloc(sizeof(long));
		if (!content) // Vérification de malloc
		{
			parse_error(a, parsed_args);
			return (0);
		}
		*content = ft_atol(parsed_args[i]);
		if ((*a && is_existing(*content, *a)) || !(INT_MIN < *content && *content < INT_MAX))
		{
			free(content);
			parse_error(a, parsed_args);
			return (0);
		}
		ft_lstadd_back(a, ft_lstnew((void *)content));
		i++;
	}
	i = 0;
	while (parsed_args && parsed_args[i])
	{
		free(parsed_args[i]);
		i++;
	}
	free(parsed_args);
	return (1);
}
