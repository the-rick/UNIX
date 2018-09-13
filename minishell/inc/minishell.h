/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmandlan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/08 11:55:34 by nmandlan          #+#    #+#             */
/*   Updated: 2018/09/08 11:56:23 by nmandlan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <dirent.h>
# include "libft.h"

# define COLOR			"\033[32m"

char					**g_envv;

void					change_dir(char *path, int print_path);
int						cd_builtin(char **command);

void					exit_shell(void);
char					*parse_home_path(char *path, int reverse_parse);
void					display_prompt_msg(void);

int						echo_builtin(char **command);

int						get_commands(char **command);
int						run_shell(char *path, char **args);
void					get_input(char **input);

int						find_env_var(char *var);
char					*get_env_var(char *var);
char					**realloc_envv(int new_size);
void					set_env_var(char *key, char *value);
int						setenv_builtin(char **command);
int						setenv_builtin(char **args);

void					signal_handler(int signo);
void					proc_signal_handler(int signo);

void					print_env(void);
void					init_envv(int ac, char **av, char **envv);
int						unsetenv_builtin(char **command);

#endif
