/*
** arc.h for arc.h in /home/binary/All/Rush1/form/archive/include
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sun Mar  5 14:47:43 2017 Laroche Achille
** Last update Sun Mar  5 23:16:38 2017 Laroche Achille
*/

#ifndef ARC_H_
# define ARC_H_

#include <unistd.h>
#include <stdio.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <dirent.h>

void	my_putchar(char c);
void	putstr(char *s);
void	add_dir(char *arname, char *dir);
void	addfil(char *arname, char *file);

double	copy(char *input, char *output, int i);

int	main(int ac, char **av);
int	isdir(char *path);
int	fsize(char *file);
int	head(char *new_arch);

char	*stck(char *o, char *t);
char	*sdup(char *s);
char	*iota(int nb);
char	*decoct(int dec);
char	*getchmod(char *fil);
char	*checkdir(char *s);

int	cnt(char *s);

#endif /* !ARC_H_ */
