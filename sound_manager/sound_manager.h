#ifndef	SOUND_MANAGER
#define	SOUND_MANAGER

#include <time.h>
#include <stdio.h>
#include "libsoundio/soundio/soundio.h"
typedef	long	long	int	int64;
#define BILLION 1000000000

const	char	*format_get_name(int format_id);
void	describe_instream(struct SoundIoInStream *instream);
long	print_time_from_begin(char *msg);

extern float	sound_buffer[8000][2];	

#endif
