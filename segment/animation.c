#include "segment.h"

void	standard_animation(t_segment *s, long long t)
{
		(void)t;
		s->speed *= s->acceleration;
		s->end += s->elongation;
		s->start += s->speed;
		s->end += s->speed;
}

void	update_segment(t_buffer *b, long long t)
{
	for (int i = 0; i < b->s_nb; i++)
		b->animate[b->s_buf[i].animation](&(b->s_buf[i]), t);
}
