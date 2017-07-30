/*
** unarchiver.c for decompresse frero in /home/binary/All/Rush1/form/unarchive/srcs
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sat Mar  4 20:50:24 2017 Laroche Achille
** Last update Sun Jul 30 20:23:33 2017 Laroche Achille
*/

#include "unarc.h"

#define RED	"\x1b[1;31m"
#define WHT	"\x1b[1;37m"
#define RST	"\x1b[0;37m"

static int	count;

char	*getln(FILE *arc)
{
  int	i;
  char	*new;

  i = 0;
  if ((new = malloc(sizeof(char) * 100)) == NULL)
    return (NULL);
  while ((new[i] = fgetc(arc)) > 30)
    i++;
  if ((new[i] < 30 && new[i] != '\n') || new[i] > 127)
    return (NULL);
  new[i] = '\0';
  return (new);
}

int	copy(FILE *inp, char *output, int i, int *data)
{
  char	*dir;
  FILE	*newcopy;
  int	d;
  int	c;

  dir = cutdir(output);
  if (isdir(dir) == 0 && strcmp(dir, output) != 0)
    createdir(dir);
  newcopy = fopen(output, "w");
  if (!inp || !newcopy)
    {
      fclose(newcopy);
      return (-1);
    }
  while (i < data[0])
    {
      c = fgetc(inp);
      fputc(c, newcopy);
      i++;
    }
  fclose(newcopy);
}

int	untar(char *arch)
{
  int	*data;
  FILE	*arc;
  char	*line;

  arc = fopen(arch, "r");
  line = getln(arc);
  if (strcmp(line, "*HEAD*") != 0 && count == 1)
    return (-1);
  mymotd();
  while ((line = getln(arc)))
    {
      if (count > 1 && line[0] != '%' && line[2] != '[')
	line = getln(arc);
      data = getinfo(line);
      if ((line = getname(line, '|')) == NULL)
	return (-1);
      printf("\\\\ +%s - %i Bytes\n", line, data[0]);
      if (copy(arc, line, 0, data) < 0)
	return (1);
      chmod(line, data[1]);
      count++;
    }
  return (0);
}

int	main(int ac, char **av)
{
  int	i;

  if (ac != 2)
    {
      printf("%s/      un%sFuck You %s:)    \\\n", WHT, RED, WHT);
      printf("\\ The logical extension /\n");
      printf("%sUsage: ./unfuck [archive name]\n", RST);
      return (84);
    }
  count = 1;
  i = untar(av[1]);
  if (i < 0)
    {
      putstr("This file is not an archive");
      return (84);
    }
  else if (i == 1)
    printf("Aborted: Cannot override file!\n");
  else
    printf("\\\\\\\\Total: %i\n", count - 1);
  return (0);
}

