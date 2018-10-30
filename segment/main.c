#include "segment.h"

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc == 4)
	{
		init_env(&e, argv);
		engine_start(e);
	}
	else
		segment_error("Usage : ./Segment Frequency Number_of_segments Mode");
	return 0;
}
