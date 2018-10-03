/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_select.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/21 10:48:51 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/25 16:01:05 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SELECT_H
# define FT_SELECT_H

# include <stdlib.h>
# include <termcap.h>
# include <curses.h>
# include <../libft/libft.h>
# include <stdio.h>
# include <sys/ioctl.h>
# include <signal.h>
# include <termios.h>
# include <dirent.h>
# include <sys/stat.h>
# include <ftw.h>
# include <unistd.h>
# include <sys/param.h>

# define C_COLOR				"\033[35m"
# define O_COLOR				"\033[36m"
# define H_COLOR				"\033[34m"
# define MAKEFILE_COLOR			"\033[33m"
# define DOT_COLOR				"\033[32m"
# define DEFAULT_COLOR			"\033[0m"
# define REVERSE_VIDEO_COLOR	"\033[7m"
# define UNDERLINED				"\033[4m"
# define MENU					"\033[37m"

# define WINCH					28

# define ENTER					10
# define ESC					27
# define SPACE					32
# define STAR_KEY				42
# define MINUS_KEY				45
# define BACKSPACE				127
# define LEFT_KEY				4479771
# define UP_KEY					4283163
# define RIGHT_KEY				4414235
# define DOWN_KEY				4348699
# define DELETE					2117294875L

typedef enum					e_type
{
	DOT_C,
	DOT_O,
	DOT_H,
	DOT_A,
	MAKEFILE,
	DOT_T,
	UNKNOWN_T
}								t_type;

typedef enum					e_key
{
	UP_ARROW,
	RIGHT_ARROW,
	DOWN_ARROW,
	LEFT_ARROW,
	DEFAULT
}								t_key;

typedef struct					s_arg
{
	char						*value;
	int							is_selected;
	t_type						type;
	struct s_arg				*prev;
	struct s_arg				*next;
}								t_arg;

typedef struct					s_select
{
	t_arg						**current;
	struct termios				attr;
	struct termios				new_attr;
	int							argc;
	char						*term_name;
	int							mode;
	t_arg						*args;
	int							selected_count;
}								t_select;

t_select						g_var;

void							move_curs(t_key direction);
int								ft_printnbr(int nbr);

void							column_display();
int								count_columns();
void							display_value(t_arg *arg, int fd);

void							init_args(char **av);
void							free_mem(void);
void							delete_arg(void);
void							put_arg(char *value);

void							error_handler(char *entry_name);
void							print_selected_args(void);

void							init_custom_conf();
void							signal_handler();

void							proc_signal(int signo);
void							kill_signals(void);

void							check_flags(char *arg);
void							control_keys(void);
void							default_conf(void);

int								count_max_arg_len(void);
void							reset_default_conf(void);
void							toggle_all_args(long key);
void							toggle_selection(void);

void							system_delete_arg(char *path);

#endif
