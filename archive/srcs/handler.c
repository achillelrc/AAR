/*
** base3.c for bas3 in /home/binary/All/Rush1/form/compress
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sat Mar  4 20:32:58 2017 Laroche Achille
** Last update Sun Mar  5 23:21:02 2017 Laroche Achille
*/

#include "arc.h"

double	copy(char *input, char *output, int i)
{
  FILE	*inp;
  FILE	*arch;
  int	c;

  inp = fopen(input, "r");
  arch = fopen(output, "a");
  if (!inp || !arch)
    {
      fclose(inp);
      fclose(arch);
      return (-1);
    }
  while ((c = fgetc(inp)) != EOF && i < fsize(input))
    {
      fputc(c, arch);
      i++;
    }
  fclose(arch);
  fclose(inp);
  return (fsize(input));
}

char	*checkdir(char *s)
{
  char	*cop;
  int	i;

  i = 0;
  while (s[i] != '\0')
    i++;
  if (s[i - 1] == '/')
    return (s);
  if ((cop = malloc(sizeof(char) * (cnt(s) + 1))) == NULL)
    return (NULL);
  cop[i + 1] = '\0';
  cop[i] = '/';
  i--;
  while (i >= 0)
    {
      cop[i] = s[i];
      i--;
    }
  return (cop);
}

void	add_dir(char *arname, char *dir)
{
  DIR	*rep;
  int	nb;
  struct dirent *read;

  rep = opendir(dir);
  rewinddir(rep);
  while ((read = readdir(rep)) != NULL)
    {
      dir = checkdir(dir);
      if (read->d_name[0] != '.')
	addfil(arname, stck(dir, read->d_name));
    }
}

void	addfil(char *arname, char *file)
{
  FILE	*arch;
  FILE	*fil;
  char	*sz;
  char	*chmod;

  arch = fopen(arname, "a");
  fil = fopen(file, "r");
  printf("\\\\ +%s\n", file);
  if (isdir(file) != 0)
    add_dir(arname, file);
  if (!fil || isdir(file) != 0)
    return ;
  sz = iota(fsize(file));
  chmod = getchmod(file);
  fputs("%%[", arch);
  fputs(file, arch);
  fputs("|", arch);
  fputs(sz, arch);
  fputs("|", arch);
  fputs(chmod, arch);
  putc('\n', arch);
  fclose(arch);
  copy(file, arname, 0);
}

int	head(char *new_arch)
{
  FILE *arch;

  if (access(new_arch, F_OK) == -1)
    arch = fopen(new_arch, "w");
  else
    {
      printf("This name is already taken!\n");
      return (-1);
    }
  if (!arch)
    {
      printf("Impossible to write new archive.. Try 'chmod +x' on me\n");
      return (-1);
    }
  fputs("*HEAD*", arch);
  putc('\n', arch);
  fclose(arch);
  return (0);
}
