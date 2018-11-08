#include "segment.h"

long long framecount;

#define SPEED 360
//#define SPEED 30

void	sin_length_animation(t_segment *s, long long t)
{
//		double tmp;
		(void)t;
		s->length = (sin(((double)(framecount % SPEED) / (double)SPEED) * ((double)M_PI*(double)2)) + (double)1) / (double)32;
		if (s->length < 0.035)
			s->length = 0.035;
/*		tmp = s->length - 0.0625;
		if (tmp < 0 && tmp > -0.02)
			tmp = -0.02;
		if (tmp > 0 && tmp < 0.02)
			tmp = 0.02;
		s->speed = 0.0001 / tmp; */ 
		s->end = s->start + s->length;
		s->start += s->speed;
		s->end += s->speed;
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
		s->length += s->elongation;
		s->start += s->speed;
		s->end = s->start + s->length;
		if (s->start < 0 || s->end < 0)
		{
			s->start += 10;
			s->end += 10;
		}
}

void	fill_animation(t_segment *s, long long t)
{
	s->length += 0.0002;
	s->start += s->speed;
	s->end = s->start + s->length;
//	s->start += s->speed - s->length;
//	s->end = s->start + s->length + s->speed;
	if (s->start < 0 || s->end < 0)
	{
		s->start += 10;
		s->end += 10;
	}
}

void	update_segment(t_buffer *b, long long t)
{
	if (framecount > 1080)
		for (int i = 0; i < b->s_nb; i++)
			b->s_buf[i].animation = 2;
	for (int i = 0; i < b->s_nb; i++)
		b->animate[b->s_buf[i].animation](&(b->s_buf[i]), t);
}
