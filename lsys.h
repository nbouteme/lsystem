/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lsys.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbouteme <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/31 23:20:18 by nbouteme          #+#    #+#             */
/*   Updated: 2016/01/31 23:56:34 by nbouteme         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LSYS_H
# define LSYS_H

# include <libft/std.h>

typedef struct	s_sizecalc
{
	int			n;
	char		*expr;
	const char	*user;
}				t_sizecalc;

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_drawcall
{
	t_point		from;
	t_point		to;
}				t_drawcall;

typedef struct	s_lsys_res
{
	t_dlisthead	*draw_calls;
	int			a;
	int			b;
	int			c;
	int			d;
}				t_lsys_res;

typedef struct	s_lsys
{
	char		*axiom;
	char		*consts;
	float		angle;
	t_dlisthead	*rules;
	t_point		pos;
}				t_lsys;

typedef struct	s_lrule
{
	char		symbol;
	char		*expansion;
}				t_lrule;

t_lsys			*new_system();
void			set_constant(t_lsys *self, const char *constants);
void			set_axiom(t_lsys *self, const char *axiom);
void			set_angle(t_lsys *self, int angle);
void			add_rule(t_lsys *self, char symbol, const char *rule);
char			*get_command_string(t_lsys *self, int it);
void			del_system(t_lsys *lsys);
int			find_rule(t_dlist *elem, char *d);
#endif
