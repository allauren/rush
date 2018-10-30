#include "segment.h"
static volatile bool keepRunning = true;


static void sigintHandler(int x)
{
	keepRunning = x;
	keepRunning = false;
}

void	*set_buffer(void *buf)
{
	t_buffer		*b;
	struct timespec	raw_time;
	long long		t;

	b = (t_buffer *)buf;
	clock_gettime(CLOCK_REALTIME, &raw_time);
	t = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
	update_segment(b, t);

	memset(b->p_buf, 0, sizeof(bool) * b->p);
	for (int i = 0; i < b->s_nb; i++)
		for (long long j = (long long)(b->s_buf[i].start * b->p); j < (long long)(b->s_buf[i].end * b->p); j++)
			b->p_buf[j % b->p] = 1;
	return (buf);
}

/*
void	*draw_buffer(void *buf)
{
	t_buffer		*b;
	struct timespec	raw_time;
	long long		time_elapsed;

	b = (t_buffer *)buf;
//	while (keepRunning)
//	{
		while (b->lock == 0)
		{
			clock_gettime(CLOCK_REALTIME, &raw_time);
			time_elapsed = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
			digitalWrite(LASER, b->p_buf[time_elapsed % b->p]);
		}
//	}
	return (buf);
}
*/

void	*draw_buffer(void *buf)
{
	t_ressale		*b;
	struct timespec	raw_time;
	long long		time_elapsed;

	b = (t_ressale *)buf;
	while (keepRunning)
	{
		while (b->buf == 0)
		{
			clock_gettime(CLOCK_REALTIME, &raw_time);
			time_elapsed = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
			digitalWrite(LASER, b->buf0->p_buf[time_elapsed % b->buf0->p]);
		}
		while (b->buf == 1)
		{
			clock_gettime(CLOCK_REALTIME, &raw_time);
			time_elapsed = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
			digitalWrite(LASER, b->buf1->p_buf[time_elapsed % b->buf1->p]);
		}

	}
	return (buf);
}
void	engine_start(t_env e)
{
	pthread_t	set_buf_thread;
	pthread_t	draw_buf_thread;
	pthread_t	key_event_thread;

	t_buffer	*set_buf;
//	t_buffer	*draw_buf;
	t_buffer	buf1;
	t_buffer	buf2;
	t_ressale	bufx;
	signal(SIGINT, &sigintHandler);
	init_stuff(e.mode); // Init GPIO, SIGINT management and manage ON/OFF static modes
	init_buffer(&buf1, e);
	init_buffer(&buf2, e);
//	draw_buf = &buf1;
	set_buf = &buf2;
	bufx.buf0 = &buf1;
	bufx.buf1 = &buf2;
	bufx.buf = 0;
	pthread_create(&set_buf_thread, NULL, set_buffer, set_buf);
	pthread_join(set_buf_thread, NULL);
	set_buf = (set_buf == &buf1) ? &buf2 : &buf1;
	pthread_create(&set_buf_thread, NULL, set_buffer, set_buf);
	pthread_join(set_buf_thread, NULL);
	pthread_create(&draw_buf_thread, NULL, draw_buffer, &bufx);

	pthread_create(&key_event_thread, NULL, key_event, &bufx);

	while (keepRunning)
	{
//		pthread_join(draw_buf_thread, NULL);
//		pthread_create(&draw_buf_thread, NULL, draw_buffer, draw_buf);
		pthread_create(&set_buf_thread, NULL, set_buffer, set_buf);
		pthread_join(set_buf_thread, NULL);
//		set_buf->lock = 0;
//		draw_buf = set_buf;
		set_buf = (set_buf == &buf1) ? &buf2 : &buf1;
		bufx.buf = (set_buf == &buf1) ? 1 : 0;
//		set_buf->lock = 1;
	}
	pthread_join(draw_buf_thread, NULL);
	digitalWrite(LASER, LOW);
	printf("Laser turned off, program will exit\n");
}
