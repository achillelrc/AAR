/*
** unarc.h for unarch in /home/binary/All/Rush1/form/unarchive/include
** 
** Made by Laroche Achille
** Login   <binary>
** 
** Started on  Sun Mar  5 14:15:50 2017 Laroche Achille
** Last update Sun Mar  5 23:16:16 2017 Laroche Achille
*/

#ifndef UNARC_H_
# define UNARC_H_

#include <libgen.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <assert.h>

char	*getln(FILE *arc);
char	*getname(char *lin, char lim);
char	*iota(int nb);
char	*sdup(char *s);
char	*stck(char *o, char *t);
char	*cutdir(char *);

int	main(int ac, char **av);
int	my_getnbr(char *tab);
int	isdir(char *path);
int	untar(char *arch);
int	lil(char *o, int i);
int	*getinfo(char *lin);
int	fsize(char *file);
int	createdir(char *dir);
int	copy(FILE *inp, char *output, int i, int *data);

void	my_putchar(char c);
void	putstr(char *s);
void	mymotd();

#endif /* !UNARC_H_ */
