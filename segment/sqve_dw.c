#include "segment.h"


void	*draw_buffer(void *buf)
{
	t_ressale		*b;
	struct timespec	raw_time;
	long long		time_elapsed;

	b = (t_ressale *)buf;
	while (1)
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
