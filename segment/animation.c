#include "segment.h"

long long framecount;

void	test_animation(t_segment *s, long long t)
{
		(void)t;
		s->length = (sin(  ((double)(framecount % 60) / (double)60) * ((double)M_PI*(double)2) ) + (double)1) / (double)8;
	//	printf("frame : %lld\telong : %f\n", framecount, s->elongation);
		s->speed *= s->acceleration;
		s->end += s->elongation;
		s->start -= s->speed;
		s->end = s->start + s->length;
		if (s->start < 0 || s->end < 0)
		{
			s->start += 10;
			s->end += 10;
		}
}

void	standard_animation(t_segment *s, long long t)
{
		(void)t;
		s->speed *= s->acceleration;
		s->end += s->elongation;
		s->start += s->speed;
		s->end += s->speed;
		if (s->start < 0 || s->end < 0)
		{
			s->start += 10;
			s->end += 10;
		}
}

void	update_segment(t_buffer *b, long long t)
{
	for (int i = 0; i < b->s_nb; i++)
		b->animate[b->s_buf[i].animation](&(b->s_buf[i]), t);
}
