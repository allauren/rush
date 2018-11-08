#include "segment.h"

void    recv_loop(int sock, t_env *e)
{
	int res = 0;
	char buf[65535];
	int period;

	memset(&buf, 0, sizeof(buf));
	while (!(res < 0))
	{
		res = recv(sock, buf, sizeof(buf), 0);
		buf[res] = 0;
		period = atoi(buf);
		printf("buf: %s\tperiod: %d\n", buf, period);
		e->p = period;
	}
	close(sock);
}

int		main(int argc, char **argv)
{
	t_env		*e;
	pthread_t	main_thread;
/*
	int sock;
	int res;
	int bind_port;
	struct sockaddr_in sa;
*/
	if (argc < 4)
	{
		fprintf(stderr, "Usage: %s frequency number_of_segments mode bind_port\n", argv[0]);
		return 1;
	}
/*
	bind_port = atoi(argv[4]);

	sock = socket(AF_INET, SOCK_DGRAM, 0);
	if (sock < 0) return 2;

	memset(&sa, 0, sizeof(sa));
	sa.sin_port = htons(bind_port);
	sa.sin_family = AF_INET;

	res = bind(sock, (struct sockaddr *)&sa, sizeof(sa));
	if (res < 0) {
		perror("bind");
		return 3;
	}
*/
	e = malloc(sizeof(*e));
	init_env(e, argv);
	pthread_create(&main_thread, NULL, engine_start, e);
//	recv_loop(sock, e);
	while(1);
return  (0);


		/*
		   if (argc == 4)
		   {
		   init_env(&e, argv);
		   engine_start(e);
		   }
		   else
		   segment_error("Usage : ./Segment frequency number_of_segments mode");
		   return 0;*/
}
