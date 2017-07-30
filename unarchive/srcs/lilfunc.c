/*
** lilfunc.c for elle prennen trp de place  in /home/binary/All/Rush1/form/unarchive/srcs
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sun Mar  5 12:53:04 2017 Laroche Achille
** Last update Sun Mar  5 23:25:32 2017 Laroche Achille
*/

#include "unarc.h"

int	lil(char *o, int i)
{
  int	j;
  char	*t;

  i++;
  j = i;
  if ((t = malloc(sizeof(char) * 13)) == NULL)
    return (-1);
  while (o[i] >= '0' && o[i] <= '9')
    {
      t[i - j] = o[i];
      i++;
    }
  return (my_getnbr(t));
}

int	*getinfo(char *lin)
{
  int	*dat;
  int	i;

  if ((dat = malloc(sizeof(int) * 2)) == NULL)
    return (NULL);
  i = 0;
  while (lin[i] != '|')
    i++;
  dat[0] = lil(lin, i);
  i++;
  while (lin[i] != '|')
    i++;
  dat[1] = lil(lin, i);
  return (dat);
}

char	*getname(char *lin, char lim)
{
  char	*nam;
  int	i;

  if (lin[0] != '%' || lin[1] != '%' || lin[2] != '[')
    return (NULL);
  i = 3;
  while (lin[i] != lim)
    i++;
  if ((nam = malloc(sizeof(char) * (i - 2))) == NULL)
    return (NULL);
  nam[i - 3] = '\0';
  i--;
  while (lin[i] != '[')
    {
      nam[i - 3] = lin[i];
      i--;
    }
  return (nam);
}

char	*cutdir(char *dir)
{
  char	*cop;
  int	i;

  while (dir[i] != '\0')
    i++;
  while (dir[i] != '/')
    {
      if (i <= 0)
	return (dir);
      i--;
    }
  if ((cop = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  cop[i] = '\0';
  i--;
  while (i >= 0)
    {
      cop[i] = dir[i];
      i--;
    }
  return (cop);
}

void	mymotd()
{
  printf(" ________  ______ ____ ____ ____ _____ _ ____ _     \n");
  printf("/  __/\\  \\/ __ __Y  __Y  _ Y   _Y__ __Y Y  _ Y \\  /|\n");
  printf("|  \\   \\  /  / \\ |  \\/| / \\|  /   / \\ | | / \\| |\\ ||\n");
  printf("|  /_  /  \\  | | |    / |-||  \\_  | | | | \\_/| | \\||\n");
  printf("\\____\\/__/ \\ \\_/ \\_/\\_\\_/ \\|____/ \\_/ \\_|____|_/  \\|\n");
}
