#ifndef SEGMENT_H
# define SEGMENT_H

# include <time.h>
# include <wiringPi.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <signal.h>
# include <pthread.h>
# include <string.h>
# include <math.h>
# include <unistd.h>

# define LASER 7
# define MILLION (double)1000000

typedef struct		s_segment
{
	double			start;
	double			end;
	double			length;
	double			elongation;
	double			speed;
	double			acceleration;
	bool			state;
	int				animation;
}					t_segment;

void				*key_event(void *buf);
typedef				void(*t_animate)(t_segment *, long long);

typedef struct		s_env
{
	float			frequency;
	int				mode;
	int				s_nb;
	t_segment		*s;
}					t_env;

typedef struct		s_buffer
{
	bool			*p_buf;
	t_segment		*s_buf;
	int				p;
	int				s_nb;
	bool 			lock;
	t_animate		*animate;
}					t_buffer;

typedef struct		s_ale
{
	t_buffer		*buf0;
	t_buffer		*buf1;
	int				buf;
}					t_ressale;


void				segment_error(char *err_msg);

void				init_env(t_env *e, char **argv);
void				init_stuff(int mode);
void				init_buffer(t_buffer *buf, t_env e);
void				engine_start(t_env e);

void				*draw_buffer(void *e);
void				*set_buffer(void *e);

void				update_segment(t_buffer *b, long long t);
void				standard_animation(t_segment *s, long long t); 

#endif
