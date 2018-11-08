#include "segment.h"

void	init_env(t_env *e, char **argv)
{
	e->frequency = atof(argv[1]);
	e->p = MILLION / e->frequency;
	e->s_nb = atoi(argv[2]);
	e->mode = atoi(argv[3]);
	e->s = (t_segment *)malloc(e->s_nb * sizeof(t_segment));
	for (int i = 0; i < e->s_nb; i++)
	{
		e->s[i].start = (double)i/(double)e->s_nb;
		e->s[i].end = e->s[i].start + (double)1/(double)(3 * e->s_nb);
		e->s[i].length = e->s[i].end - e->s[i].start;
		e->s[i].acceleration = 1;
		e->s[i].elongation = 0;
		e->s[i].state = 1;
		if (i % 2 == 1)
		{
			e->s[i].speed = 0.000;
			e->s[i].animation = 1;
		}
		else
		{
			e->s[i].speed = 0.0002 * i;
			if (e->s[i].speed > 0.0024)
				e->s[i].speed = 0.0024;
			if (i % 4 == 2)
				e->s[i].speed = -e->s[i].speed;
			e->s[i].animation = 0;
		}
	}
}

void	init_buffer(t_buffer *buf, t_env *e)
{
	buf->lock = 1;
//	buf->p = MILLION / FREQUENCY;
	buf->p = &(e->p);
	buf->s_nb = e->s_nb;
	if (!(buf->p_buf = (bool *)calloc(1, sizeof(bool) * MILLION)))
		segment_error("malloc buf->p_buf");
	if(!(buf->s_buf = (t_segment *)malloc(sizeof(t_segment) * e->s_nb)))
		segment_error("malloc buf->s_buf");
	memcpy(buf->s_buf, e->s, e->s_nb * sizeof(t_segment));
	buf->animate = (t_animate *)malloc(3 * sizeof(t_animate));
	buf->animate[0] = &standard_animation;
	buf->animate[1] = &sin_length_animation;
	buf->animate[2] = &fill_animation;
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
