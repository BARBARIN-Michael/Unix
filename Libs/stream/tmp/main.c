#include <ft_stream.h>

#include <fcntl.h>

int		main(void)
{
	t_stream stream;

	ft_stream_new(open("/tmp/toto", O_RDONLY), 1, &stream);
	ft_stream_read(&stream);
	
	return (0);
}
