/*
** base2.c for bas2 compress in /home/binary/All/Rush1/form/compress
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sat Mar  4 20:30:49 2017 Laroche Achille
** Last update Sun Mar  5 23:20:24 2017 Laroche Achille
*/

#include "arc.h"

char	*iota(int nb)
{
  int	i;
  char	*nbr;
  int   div;

  if ((nbr = malloc(sizeof(char) * 15)) == NULL)
    return (NULL);
  div = 1;
  if (nb > 0)
    nb = nb * -1;
  while (nb / div < -9)
    div = div * 10;
  i = 0;
  while (div >= 1)
    {
      nbr[i] = nb / div * -1 + 48;
      nb = nb % div;
      div = div / 10;
      i++;
    }
  nbr[i] = '\0';
  return (nbr);
}

int	isdir(char *path)
{
  struct stat stats;

  if (stat(path, &stats) != 0)
    return (0);
  return (S_ISDIR(stats.st_mode));
}

char	*decoct(int dec)
{
  char	*s;
  int	oct;
  int	i;

  i = 1;
  oct = 0;
  while (dec != 0)
    {
      oct += i * (dec % 8);
      dec = dec / 8;
      i = i * 10;
    }
  return (iota(oct));
}

char	*getchmod(char *fil)
{
  struct stat	stats;
  int	oct;

  stat(fil, &stats);
  oct = stats.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO);
  return (iota(oct));
}

int	fsize(char *file)
{
  struct stat	stats;

  if (stat(file, &stats) == 0)
    return (stats.st_size);
  return (0);
}
