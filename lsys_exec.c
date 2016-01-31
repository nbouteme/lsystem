/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsys_exec.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:54:42 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/31 23:58:10 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lsys.h"

static void	rotate(t_point *dir, float angle)
{
	int tmpx;

	tmpx = dir->x;
	dir->x = dir->x * cos(angle) + dir->y * sin(angle);
	dir->y = -tmpx * sin(angle) + dir->y * cos(angle);
}

t_dlisthead	*make_draw_list(t_lsys *self, char *r)
{
	t_point		dir;
	t_dlisthead	*ret;

	ret = ftext_lstnew();
	dir = (t_point) { 0, 10 };
	while (*r)
	{
		if (*r == '+')
			rotate(&dir, -self->angle);
		else if (*r == '-')
			rotate(&dir, self->angle);
		else
		{
			ftext_lstpush_back(ret, ftext_lstnewelem(&(t_drawcall) {
						self->pos,
						(t_point) {	self->pos.x + dir.x, self->pos.y + dir.y }
					}, sizeof(t_drawcall)));
			self->pos.x += dir.x;
			self->pos.y += dir.y;
		}
		++r;
	}
	return (ret);
}
