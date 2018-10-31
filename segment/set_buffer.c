#include "segment.h"

pthread_mutex_t		end_buf;
pthread_cond_t		end_change;

void	*set_buffer(void *buf)
{
	t_buffer		*b;
	struct timespec	raw_time;
	long long		t = 0;
 	long long		j = 0;

	b = (t_buffer *)buf;
	while (1)
	{
		segment_error2("debut");
		pthread_mutex_lock(&end_buf);
		pthread_cond_signal(&end_change);
		clock_gettime(CLOCK_REALTIME, &raw_time);
		t = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
		update_segment(b, t);
		memset(*(b->buf), 0, sizeof(bool) * b->p);
		for (int i = 0; i < b->s_nb; i++)
		{
			j = (long long)(b->s_buf[i].start * b->p)
			for (j; j < (long long)(b->s_buf[i].end * b->p); j++)
			{
			*(b->buf)[j % b->p] = 1;
			}
		}
	pthread_mutex_unlock(&end_buf);
}
