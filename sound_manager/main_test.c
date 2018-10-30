#include "kiss_fft.h"
#include <stdlib.h>




void	freq_set(kiss_fft_cpx *buff, int buff_size, float f1, float f2, float amp1, float amp2)
{
	float	v1, v2, val;

	for (int i = 0; i < buff_size; i++)
	{
		v1 = ((float)(i * f1) / (float)(buff_size )) * amp1;
		v2 = ((float)(i * f2) / (float)(buff_size )) * amp2;
		buff[i].r = (sin(v1)) + sin(v2);
		buff[i].i = 0;

		printf("i:%d	sin(%10f):%10f	sin(%10f):%10f		buff.r:%10f	buff.i:%10f\n", i, v1, sin(v1), v2, sin(v2), buff[i].r, buff[i].i);
	}
}

void	buff_print(kiss_fft_cpx *buff, int buff_size)
{
	for (int i = 0; i < buff_size; i++)
	{
		printf(" val[%d]:	r->%10f i->%10f\n", i, buff[i].r, buff[i].i);
	}
}

//	Ou est-ce qu'on definie la frequence d'echantillonage du buffer

void	fft_testing()
{
	int		is_inverse_fft = 0;
	int		nfft = 100;
	kiss_fft_cpx	*buff_in;	
	kiss_fft_cpx	*buff_out;

	buff_in = malloc(sizeof(kiss_fft_cpx) * nfft);
	buff_out = malloc(sizeof(kiss_fft_cpx) * nfft);	

	

        kiss_fft_cfg cfg = kiss_fft_alloc( nfft ,is_inverse_fft ,0,0 );

	freq_set(buff_in, nfft, 1000, 500, 1, 0.7);
	printf("==== buff in\n");
	buff_print(buff_in, nfft);

        kiss_fft(cfg , buff_in, buff_out);

	printf("==== buff out\n");
	buff_print(buff_out, nfft);

        kiss_fft_free(cfg);
}

void	write_in_buffer()
{
	kiss_fft_cpx 	val;
	kiss_fft_scalar	real, imag;

	real = 0.5;
	imag = 0.7;
	val.r = 1;
	val.i = 2;
	
	printf("r:%f i:%f val.r:%f val.i:%f\n", real, imag, val.r, val.i);
}

int	main()
{
//	write_in_buffer();
	fft_testing();
	return (0);
}
