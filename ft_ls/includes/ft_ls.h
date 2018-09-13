/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/22 15:22:37 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:40:32 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_H
# define FT_LS_H

# include <stdlib.h>
# include <fcntl.h>
# include <errno.h>
# include <unistd.h>
# include <time.h>
# include <grp.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/time.h>
# include <sys/ioctl.h>
# include <sys/acl.h>
# include <sys/xattr.h>
# include <glob.h>
# include <pwd.h>
# include <dirent.h>
# include "../func/libft.h"

typedef struct timespec		t_time;

typedef struct stat			t_stat;

typedef struct				s_ls
{
	t_stat		*stat;
	char		*d_name;
	struct s_ls	*next;
}							t_ls;

typedef struct				s_save
{
	int			x;
	int			y;
	char		*flag;
}							t_save;

# define LIST				(flag[0])
# define R					(flag[1])
# define LOW_R				(flag[2])
# define ALL				(flag[3])
# define TIME				(flag[4])
# define N					(flag[5])
# define O					(flag[6])
# define G					(flag[7])
# define T_SEC				(ptr->stat->st_mtimespec.tv_sec)
# define T_NSEC				(ptr->stat->st_mtimespec.tv_nsec)
# define T_SECN				(ptr->next->stat->st_mtimespec.tv_sec)
# define T_NSECN			(ptr->next->stat->st_mtimespec.tv_nsec)
# define TV_SEC				(s.st_mtimespec.tv_sec)
# define TV_NSEC			(s.st_mtimespec.tv_nsec)

int							print_file_info(t_ls *ptr, char *flag);
void						print_list(t_ls *lst, char *flag, int err);
int							ft_print_error(char *o_dir);
void						free_list(t_ls *ptr);
t_ls						*create_list(char *d_name, char *flag);
void						push_front(t_ls ***start, char *d_name, char *flag);
void						push_back(t_ls **end, char *d_name, char *flag);
void						alpha_sort(t_ls **list, char *d_name, char *flag);
void						sort_time(t_ls *ptr, char **d_name, char flag, \
		struct stat s);
void						reverse_sort(t_ls **list, char *d_name, char *flag);
void						reverse_time(t_ls **list, char *d_name, char *flag);
void						sort_list(t_ls **list, char *d_name, char *flag);
t_ls						*ft_ls(char *o_dir, char *flag);
int							check_argument(char *str, char *flag);
char						*filename(char *str, int err);
void						time_sort(t_ls *ptr, char *d_name, char *flag, \
		struct stat s);
void						handle_time(t_ls **list, char *d_name, char *flag);

#endif
