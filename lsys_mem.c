#include "lsys.h"
#include <stdlib.h>

t_lsys *new_system()
{
	t_lsys *ret;

	ret = ft_memalloc(sizeof(t_lsys));
	ret->rules = ftext_lstnew();
	return (ret);
}

void del_rule(t_lrule *r, size_t dontcare)
{
	(void)dontcare;
	free(r->expansion);
	free(r);
}

void del_system(t_lsys *self)
{
	free(self->axiom);
	free(self->consts);
	ftext_lstdel(&self->rules, (void*)&del_rule);
	free(self);
}
