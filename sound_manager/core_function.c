#include "libsoundio/soundio/soundio.h"
#include "sound_manager.h"

///// buffer
//	left_chan
//	right_chan


float	sound_buffer[8000][2];	
		
const	char	*format_get_name(int format_id)
{
	switch (format_id)
	{
		case SoundIoFormatFloat32NE:
			return("SoundIoFormatFloat32NE");
			break;
		case SoundIoFormatFloat32FE:
			return("SoundIoFormatFloat32FE");
			break;
		case SoundIoFormatS32NE:
			return("SoundIoFormatS32NE");
			break;
		case SoundIoFormatS32FE:
			return("SoundIoFormatS32FE");
			break;
		case SoundIoFormatS24NE:
			return("SoundIoFormatS24NE");
			break;
		case SoundIoFormatS24FE:
			return("SoundIoFormatS24FE");
			break;
		case SoundIoFormatS16NE:
			return("SoundIoFormatS16NE");
			break;
		case SoundIoFormatS16FE:
			return("SoundIoFormatS16FE");
			break;
		case SoundIoFormatFloat64NE:
			return("SoundIoFormatFloat64NE");
			break;
		case SoundIoFormatFloat64FE:
			return("SoundIoFormatFloat64FE");
			break;
		case SoundIoFormatU32NE:
			return("SoundIoFormatU32NE");
			break;
		case SoundIoFormatU32FE:
			return("SoundIoFormatU32FE");
			break;
		case SoundIoFormatU24NE:
			return("SoundIoFormatU24NE");
			break;
		case SoundIoFormatU24FE:
			return("SoundIoFormatU24FE");
			break;
		case SoundIoFormatU16NE:
			return("SoundIoFormatU16NE");
			break;
		case SoundIoFormatU16FE:
			return("SoundIoFormatU16FE");
			break;
		case SoundIoFormatS8:
			return("SoundIoFormatS8");
			break;
		case SoundIoFormatU8:
			return("SoundIoFormatU8");
			break;
		case SoundIoFormatInvalid:
			return("SoundIoFormatInvalid");
			break;
	}
	return ("none");
}

void	describe_instream(struct SoundIoInStream *instream)
{
	int	samp_min = instream->device->sample_rates->min;
	int	samp_max = instream->device->sample_rates->max;
	int	samp_cur = instream->sample_rate;

	printf("=================================\n");
	printf("sample_rate:		%d\n", samp_cur);
	printf("latency:		%f\n", instream->software_latency);
	printf("nbr_chanel:		%d\n", instream->layout.channel_count);
	printf("bytes_per_frame:	%d\n", instream->bytes_per_frame);
	printf("bytes_per_sample	%d\n", instream->bytes_per_sample);
	printf("format:			%d	%s\n", instream->format, format_get_name(instream->format));
//	printf("latency->	min:%d	max:%d		actual:%d\n", instream->devices->software_latency_min, instream->software_latency_max, instream->software_latency_current);
	// latency
	// sample_rate
	// chanel number & ordona
//	instream->latency
}

long print_time_from_begin(char *msg)
{
	static	int		first = 1;
	static	struct timespec tstart={0,0}, tend={0,0};
	static	int64		ttstart = 0;
	int64			ttend;

	if (first)
	{
		first = 0;
		clock_gettime(CLOCK_MONOTONIC, &tstart);
		ttstart = (int64)BILLION * tstart.tv_sec +  tstart.tv_nsec;
	}
	clock_gettime(CLOCK_MONOTONIC, &tend);
	ttend = (int64)BILLION * tend.tv_sec + tend.tv_nsec;
	printf("%s time diff:%f\n", msg, (double)((ttend - ttstart) / (double)(BILLION)));
	return (0);
}


/*
	Il faut avoir un buffer d'un chanel (droite ou gauche).
	Il faut que ce buffer soit au format kiss_fft.
	Il faut gerer l'accumulation de buffer.
*/

void	acumulate_buffer(char *buff, int size)
{
	static	int	cursor = 0; // le nombre de frame (1 frame = 2 float)
	
//	if ()
	//memmove();	
}
