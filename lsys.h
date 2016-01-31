#ifndef LSYS_H
#define LSYS_H

#include <libft/std.h>

typedef struct	s_lsys
{
	char		*axiom;
	char		*consts;
	int			angle;
	t_dlisthead	*rules;
}				t_lsys;

typedef struct	s_lrule
{
	char symbol;
	char *expansion;
}				t_lrule;

t_lsys *new_system();
void set_constant(t_lsys *self, const char *constants);
void set_axiom(t_lsys *self, const char *axiom);
void set_angle(t_lsys *self, int angle);
void add_rule(t_lsys *self, char symbol, const char *rule);
char *get_command_string(t_lsys *self, int it);
void del_system(t_lsys *lsys);

#endif
