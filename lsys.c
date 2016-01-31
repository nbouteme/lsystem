#include "lsys.h"
#include <stdlib.h>

void set_constant(t_lsys *self, const char *constants)
{
	self->consts = ft_strdup(constants);
}

void set_axiom(t_lsys *self, const char *axiom)
{
	self->axiom = ft_strdup(axiom);
}

int find_rule(t_dlist *elem, char *d)
{
	t_lrule *r;

	r = elem->content;
	return (r->symbol == *d);
}

void add_rule(t_lsys *self, char symbol, const char *rule)
{
	t_lrule *r;

	if (ftext_lstfind(self->rules, (void*)&find_rule, &symbol))
		return ;
	r = malloc(sizeof(*r));
	*r = (t_lrule) { symbol, ft_strdup(rule) };
	ftext_lstpush_back(self->rules, ftext_lstnewelemown(r, sizeof(*r)));
}

typedef struct	s_sizecalc
{
	int n;
	char *expr;
	const char *user;
}				t_sizecalc;

int expanded_size(t_lsys *self, char *expr)
{
	int n;
	t_dlist *tmp;
	t_lrule *r;

	n = 0;
	while (*expr)
	{
		if ((tmp = ftext_lstfind(self->rules, (void*)find_rule, expr)))
		{
			r = tmp->content;
			n += ft_strlen(r->expansion);
		}
		else
			++n;
		++expr;
	}
	return (n);
}

char *expand_into(t_lsys *self, char *input, char *out)
{
	int n;
	t_dlist *tmp;
	t_lrule *r;

	n = 0;
	while (*input)
	{
		if ((tmp = ftext_lstfind(self->rules, (void*)find_rule, input)))
		{
			r = tmp->content;
			ft_memcpy(out + n, r->expansion, ft_strlen(r->expansion) + 1);
			n += ft_strlen(r->expansion);
		}
		else
		{
			out[n] = *input;
			++n;
		}
		++input;
	}
	return (out);
}

char *get_command_string(t_lsys *self, int it)
{
	int i;
	char *result;
	char *tmp;
	int nsize;

	i = 1;
	result = ft_strdup(self->axiom);
	while (i++ < it)
	{
		nsize = expanded_size(self, result);
		tmp = result;
		result = expand_into(self, result, malloc(nsize + 1));
		free(tmp);
	}
	return (result);
}

#include <stdio.h>

int main(int argc, char *argv[])
{
    t_lsys *l = new_system();
	set_axiom(l, "FX");
	l->angle = 45;
	add_rule(l, 'X', "FFXX");
	char *r = get_command_string(l, 1);
	puts(r);
	free(r);

	r = get_command_string(l, 2);
	puts(r);
	free(r);

	r = get_command_string(l, 3);
	puts(r);
	free(r);

	del_system(l);
    return 0;
}
