#include "segment.h"

int		main(int argc, char **argv)
{
	t_env		e;

	if (argc == 3)
	{
		init_env(&e, argv);
		engine_start(e);
	}
	else
		segment_error("Usage : ./Segment Frequency Mode");
	return 0;
}
