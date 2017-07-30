/*
** basics.c for basic functions in /home/binary/Navy/new
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sun Feb  5 16:34:25 2017 Laroche Achille
** Last update Sun Mar  5 23:22:17 2017 Laroche Achille
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

void	putstr(char *s)
{
  while (*s != '\0')
    {
      my_putchar(*s);
      *s++;
    }
}

char	*sdup(char *s)
{
  int	i;
  char	*new;

  i = 0;
  while (s[i] != '\0')
    i++;
  if ((new = malloc(sizeof(char) * (i + 1))) == NULL)
    return (NULL);
  i = 0;
  while (*s != '\0')
    {
      new[i] = *s;
      *s++;
      i++;
    }
  return (new);
}

int	cnt(char *s)
{
  int	i;

  while (*s != '\0')
    {
      i++;
      *s++;
    }
  return (i);
}

char	*stck(char *o, char *t)
{
  char	*s;
  int	i;
  int	j;

  j = 0;
  i = 0;
  if ((s = malloc(sizeof(char) * (cnt(o) + cnt(t) + 1))) == NULL)
    return (NULL);
  while (o[i] != '\0')
    {
      s[i] = o[i];
      i++;
    }
  while (t[j] != '\0')
    {
      s[i + j] = t[j];
      j++;
    }
  s[i + j] = '\0';
  return (s);
}

