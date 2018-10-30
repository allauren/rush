#include "segment.h"

void	*key_event(void *buf)
{
	t_buffer	*b;
	char	c = 0;

	b = (t_buffer *)buf;
	while (1)
	{
		read(0, &c, 1);
		switch (c)
		{
			case 'x':
				b->p = MILLION / 240;
			break;
			case 'y':
				b->p = MILLION / (MILLION / b->p + 0.001);
			break;
			case 'h':
				b->p = MILLION / (MILLION / b->p - 0.001);
			break;
			case 't':
				b->p = MILLION / (MILLION / b->p + 0.01);
			break;
			case 'g':
				b->p = MILLION / (MILLION / b->p - 0.01);
			break;
			case 'r':
				b->p = MILLION / (MILLION / b->p + 0.1);
			break;
			case 'f':
				b->p = MILLION / (MILLION / b->p - 0.1);
			break;
			case 'e':
				b->p = MILLION / (MILLION / b->p + 1);
			break;
			case 'd':
				b->p = MILLION / (MILLION / b->p - 1);
			break;
			case 'w':
				b->p = MILLION / (MILLION / b->p + 10);
			break;
			case 's':
				b->p = MILLION / (MILLION / b->p - 10);
			break;
			case 'q':
				b->p = MILLION / (MILLION / b->p + 100);
			break;
			case 'a':
				b->p = MILLION / (MILLION / b->p - 100);
			break;
		}
		printf ("Frequency : %f\tPeriod : %d\n", MILLION / b->p, b->p);
	}
	return (buf);
}


