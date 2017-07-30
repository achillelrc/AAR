/*
** base2.c for bas2 compress in /home/binary/All/Rush1/form/compress
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sat Mar  4 20:30:49 2017 Laroche Achille
** Last update Sun Mar  5 23:22:53 2017 Laroche Achille
*/

#include "unarc.h"

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

int	my_getnbr(char *tab)
{
  int	ispos;
  int	nbr;
  int	i;

  nbr = 0;
  i = 0;
  ispos = 1;
  while (tab[i] != '\0' && (tab[i] == 45 || tab[i] == 43 )) {
    if (tab[i] == 45)
      ispos = ispos * -1;
    i = i + 1;
  }
  while (tab[i] <= 57 && tab[i] >= 48) {
    nbr = nbr * 10;
    nbr = (tab[i] - 48) + nbr;
    if (nbr < 0)
      {
	if (nbr != -2147483648)
	  return (84);
      }
    i = i + 1;
  }
  return (nbr * ispos);
}

int	isdir(char *path)
{
  struct stat stats;

  if (stat(path, &stats) != 0)
    return (0);
  return (S_ISDIR(stats.st_mode));
}

int	createdir(char *dir)
{
  char	*subdir;
  char	*fulldir;

  fulldir = strdup(dir);
  subdir = dirname(dir);
  if (strlen(subdir) > 1)
    createdir(subdir);
  mkdir(fulldir, 0777);
  free(fulldir);
}

int	fsize(char *file)
{
  struct stat	stats;

  if (stat(file, &stats) == 0)
    return (stats.st_size);
  return (0);
}
