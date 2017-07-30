/*
** archiver.c for archiv in /home/binary/All/Rush1/form/archive/srcs
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sun Mar  5 14:53:08 2017 Laroche Achille
** Last update Sun Jul 30 20:24:18 2017 Laroche Achille
*/

#include "arc.h"

#define RED	"\x1b[1;31m"
#define WHT	"\x1b[1;37m"
#define RST	"\x1b[0;37m"

int	main(int ac, char **av)
{
  int	i;

  if (ac < 3 || head(av[1]) < 0)
    {
      printf("%s/       %sFuck You %s:)     \\\n", WHT, RED, WHT);
      printf("%s\\  a simple compressor  /\n%s", WHT, RST);
      printf("Usage: ./fuck [archive.any] [files-or-dir] [...]\n");
      return (84);
    }
  i = 2;
  printf(" ____ ____ _     ____ ____ _________ ____ _ ____ _     \n");
  printf("/   _Y  _ Y \\__/|  __Y  __Y  __/ ___Y ___Y Y  _ Y \\  /|\n");
  printf("|  / | / \\| |\\/||  \\/|  \\/|  \\ |    \\    \\ | / \\| |\\ ||\n");
  printf("|  \\_| \\_/| |  ||  __/    /  /_\\___ |___ | | \\_/| | \\||\n");
  printf("\\____|____|_/  \\|_/  \\_/\\_\\____\\____|____|_|____|_/  \\|\n");
  while (i < ac)
    addfil(av[1], av[i++]);
  return (0);
}
