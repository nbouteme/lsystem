/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsys_access.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:55:19 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/31 23:55:25 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsys.h"

void	set_constant(t_lsys *self, const char *constants)
{
	self->consts = ft_strdup(constants);
}

void	set_axiom(t_lsys *self, const char *axiom)
{
	self->axiom = ft_strdup(axiom);
}

int		find_rule(t_dlist *elem, char *d)
{
	t_lrule *r;

	r = elem->content;
	return (r->symbol == *d);
}

void	add_rule(t_lsys *self, char symbol, const char *rule)
{
	t_lrule *r;

	if (ftext_lstfind(self->rules, (void*)&find_rule, &symbol))
		return ;
	r = malloc(sizeof(*r));
	*r = (t_lrule) { symbol, ft_strdup(rule) };
	ftext_lstpush_back(self->rules, ftext_lstnewelemown(r, sizeof(*r)));
}
