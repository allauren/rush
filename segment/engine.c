#include "segment.h"

static volatile bool keepRunning = true;

static void sigintHandler(int x)
{
	keepRunning = x;
	keepRunning = false;
}

void	init_function (t_env e; t_buffer *buf)
{
	init_stuff(e.mode); // Init GPIO, SIGINT management and manage ON/OFF static modes
	init_buffer(buf, e);
}
void	engine_start(t_env e)
{
	pthread_t	threads[2]; 
	t_buffer	*segmenter;
	char	*bufs[2]; 
	struct timespec	raw_time;
	long long		time_elapsed;
	int				period;
	int				i;

	i = 0;
	pthread_mutex_lock(&end_buf);
	signal(SIGINT, &sigintHandler);
	if (!(segmenter = (bool *)calloc(1, sizeof(t_buffer))))
		segment_error("malloc error buf");
	if (!(bufs[0] = (bool *)calloc(1, sizeof(bool) * MILLION)))
		segment_error("malloc error buf");
	if (!(bufs[1] = (bool *)calloc(1, sizeof(bool) * MILLION)))
		segment_error("malloc error buf");
	init_function(e, segmenter);
	segmenter->buf = &bufs[i];
	while (1)
	{
		i = !i;
		pthread_cond_signal(&end_change);
		while (pthread_mutex_trylock(end_buf))
		{

			clock_gettime(CLOCK_REALTIME, &raw_time);
			time_elapsed = (long long)(raw_time.tv_sec * MILLION + raw_time.tv_nsec / 1000);
			digitalWrite(LASER, bufs[i][time_elapsed % period]);
		}
		segmenter->buf = &bufs[i];
	}
}
