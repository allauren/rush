#include "segment.h"

void	*set_buffer(void *buf)
{
	t_buffer		*b;
	struct timespec	raw_time;
	struct timespec raw_time_framerate;
	long long		t;
	long long		t_framerate;

	b = (t_buffer *)buf;
	clock_gettime(CLOCK_REALTIME, &raw_time);
	t = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
	update_segment(b, t);

	memset(b->p_buf, 0, sizeof(bool) * b->p);
	for (int i = 0; i < b->s_nb; i++)
		for (long long j = (long long)(b->s_buf[i].start * b->p); j < (long long)(b->s_buf[i].end * b->p); j++)
			b->p_buf[j % b->p] = 1;
	clock_gettime(CLOCK_REALTIME, &raw_time_framerate);
	t_framerate = (long long)(raw_time_framerate.tv_sec * MILLION + raw_time.tv_nsec / 1000);
	if(t_framerate - t > FRAMETIME)
		printf("Framerate too high\n");
	while (t_framerate - t < FRAMETIME)
	{
		clock_gettime(CLOCK_REALTIME, &raw_time_framerate);
		t_framerate = (long long)(raw_time_framerate.tv_sec * MILLION + raw_time_framerate.tv_nsec / 1000);
	}
	return (buf);
}
