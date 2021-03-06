/*
** getnextline.c for getnextline in /home/nguye_1//afs_loc/getnextline
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Mon Nov 19 17:42:29 2012 alexandre1 nguyen
** Last update Mon Apr  8 17:59:11 2013 alexandre1 nguyen
*/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

char	*get_next_line(const int fd, int i)
{ 
  int		k = 0;
  int		l;
  static int	j;
  char		*buff, *buff2;

  if (i == 1)
    {
      j = 0;
      return (NULL);
    }
  buff = malloc(4096);
  buff2 = malloc(4096);
  l = read(fd, buff, 4096);
  if (l == -1 || buff[j] == 0)
    return (NULL);
  while (buff[j] != '\n' && buff[j] != 0)
    {
      buff2[k] = buff[j];
      j += 1;
      k += 1;
    }
  if (buff[j] == 0) 
    return(buff2);
  j += 1;
  return (buff2);
}

int	main(int ac, char **av)
{
  int	fd;
  char	*buf;

  if (ac < 2)
    return (-1);
  fd = open(av[1], O_RDONLY);
  while ((buf = get_next_line(fd, 0)))
    {
      printf("%s\n", buf);
      write(1, "AA\n", 3);
      close(fd);
      fd = open(av[1], O_RDONLY);
    }
}
