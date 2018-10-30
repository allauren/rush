#include "segment.h"

void	*draw_buffer(void *buf)
{
	char		**b;
	struct timespec	raw_time;
	long long		time_elapsed;

	while (1)
	{
		b = (char**)buf;
		clock_gettime(CLOCK_REALTIME, &raw_time);
		time_elapsed = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
			digitalWrite(LASER, b->p_buf[time_elapsed % b->p]);
	}
}
