#include "segment.h"

pthread_mutex_t		end_buf;
pthread_cond_t		end_change;

void	*set_buffer(void *buf)
{
	t_buffer		*b;
	struct timespec	raw_time;
	long long		t;
	b = (t_buffer *)buf;

	while (1)
	{
		segment_error2("debut");
		segment_error2("debut");
		segment_error2("debut");
		segment_error2("debut");
		pthread_cond_wait(&end_change, &end_buf);
		segment_error2("fin");
		clock_gettime(CLOCK_REALTIME, &raw_time);
		t = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
		update_segment(b, t);
		segment_error2("fin");
		memset(*(b->buf), 0, sizeof(bool) * b->p);
		for (int i = 0; i < b->s_nb; i++)
			for (long long j = (long long)(b->s_buf[i].start * b->p); j < (long long)(b->s_buf[i].end * b->p); j++)
		*(b->buf)[j % b->p] = 1;
		pthread_mutex_unlock(&end_buf);
		segment_error2("fin");
		segment_error2("fin");
		segment_error2("fin");
		segment_error2("fin");
	}
}
