#include "segment.h"

void	init_env(t_env *e, char **argv)
{
	e->frequency = atof(argv[1]);
	e->mode = atoi(argv[2]);
	e->s_nb = 2;
	e->s = (t_segment *)malloc(e->s_nb * sizeof(t_segment));
	e->s[0].start = 0;
	e->s[0].end = 0.25;
	e->s[0].speed = 0.0001;
	e->s[0].acceleration = 1.0000;
	e->s[0].elongation = 0;
	e->s[0].animation = 0;
	e->s[0].state = 1;
	e->s[1].start = 0.5;
	e->s[1].end = 0.75;
	e->s[1].speed = 0.0001;
	e->s[1].acceleration = 1.0000;
	e->s[1].elongation = 0;
	e->s[1].animation = 0;
	e->s[1].state = 1;
}

void	init_buffer(t_buffer *buf, t_env e)
{
	buf->lock = 1;
	buf->p = MILLION / e.frequency;
	buf->s_nb = e.s_nb;
	if (!(buf->p_buf = (bool *)calloc(1, sizeof(bool) * 1000000)))
		segment_error("malloc buf->p_buf");
	if(!(buf->s_buf = (t_segment *)malloc(sizeof(t_segment) * e.s_nb)))
		segment_error("malloc buf->s_buf");
	memcpy(buf->s_buf, e.s, e.s_nb * sizeof(t_segment));
	buf->animate = (t_animate *)malloc(1 * sizeof(t_animate));
	buf->animate[0] = &standard_animation;
}

void	init_stuff(int mode)
{
	if(wiringPiSetup() == -1)
		segment_error("wiringPiSetup error");
	pinMode(LASER, OUTPUT);
	if (mode == 0)
	{
		digitalWrite(LASER, HIGH);
		printf("On\n");
		exit(0);
	}
	if (mode == -1)
	{
		digitalWrite(LASER, LOW);
		printf("Off\n");
		exit(0);
	}
}
