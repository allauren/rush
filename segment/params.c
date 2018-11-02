#include "segment.h"

void	*key_event(void *buf)
{
	t_ressale	*b;
	char	c = 0;

	b = (t_ressale *)buf;
	while (1)
	{
		read(0, &c, 1);
		switch (c)
		{
			case 'x':
				b->buf0->p = MILLION / 240;
				b->buf1->p = MILLION / 240;
			break;
			case 'y':
				b->buf0->p += 1;
				b->buf1->p += 1;
			break;
			case 'h':
				b->buf0->p -= 1;
				b->buf1->p -= 1;
			break;
			case 't':
				b->buf0->p += 10;
				b->buf1->p += 10;
			break;
			case 'g':
				b->buf0->p -= 10;
				b->buf1->p -= 10;
			break;
			case 'r':
				b->buf0->p += 100;
				b->buf1->p += 100;
			break;
			case 'f':
				b->buf0->p -= 100;
				b->buf1->p -= 100;
			break;
			case 'e':
				b->buf0->p += 1000;
				b->buf1->p += 1000;
			break;
			case 'd':
				b->buf0->p -= 1000;
				b->buf1->p -= 1000;
			break;
			case 'w':
				b->buf0->p += 10000;
				b->buf1->p += 10000;
			break;
			case 's':
				b->buf0->p -= 10000;
				b->buf1->p -= 10000;
			break;
			case 'q':
				b->buf0->p += 100000;
				b->buf1->p += 100000;
			break;
			case 'a':
				b->buf0->p -= 100000;
				b->buf1->p -= 100000;
			break;
		}
		printf ("Frequency : %f\tPeriod : %d\n", MILLION / b->buf0->p, b->buf0->p);
	}
	return (buf);
}


