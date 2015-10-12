/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sh.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbarbari <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/30 14:28:26 by mbarbari          #+#    #+#             */
/*   Updated: 2015/10/12 11:42:30 by mbarbari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_SH_H
# define FT_SH_H

# include <unistd.h>
# include <fcntl.h>
# include <libft.h>
# include <ft_printf.h>
# include <ft_checking.h>
# include <sys/wait.h>
# include <signal.h>
# include <errno.h>
# include <dirent.h>
# include <sys/types.h>

# define DEFAULT_BUILDIN			200
# define DEFAULT_MAX_LENGHT_PATH	512
# define DEFAULT_MAX_OPERAND		32
# define PERSONNAL_BUILD			4
# define OPTION_FILE				O_WRONLY | O_CREAT
# define STDERR						2
# define STDOUT						1
# define STDIN						0
# define BINARY						"binary"
# define FUNCTION					"function"

# define SIGNAL singleton_signal()

typedef struct s_env		t_env;
typedef struct s_btree		t_btree;
typedef enum e_operand		t_operand;
typedef struct s_lst_bdin	t_lst_bdin;

enum		e_operand
{
	o_undef,
	o_multi,
	o_pipe,
	o_pipe_d,
	o_and_d,
	o_red_dl,
	o_red_l,
	o_red_dr,
	o_red_r,
	o_red_e,
	o_string,
	o_empty
};

typedef int	(*t_exec)(const char *cmd, char *const args[],
									char *const envp[]);
typedef int	(*t_pipeline)(t_env *env, t_btree *l, t_btree *r,
										t_exec exec);

struct		s_btree
{
	struct s_btree				*left;
	struct s_btree				*right;
	t_operand					operand;
	char						*cde_name;
	char						**args_tab;
	int							fd;
	int							fd_prev;
	char						error;
};

struct		s_lst_bdin
{
	char						*cde_name;
	char						**args_tab;
	char						*sauvegarde;
	enum e_operand				operand;
	struct s_lst_bdin			*prev;
	struct s_lst_bdin			*next;
};

struct		s_env
{
	unsigned char				done		: 1;
	unsigned char				parse_error : 1;
	char						shell;
	char						error;
	t_pipeline					pipe[o_empty];
	int							fd_backup[3];
	char						**envp;
	int							commande;
	char						*old_path;
	char						*path;
	t_lst_bdin					*lst_bdin;
	t_btree						*bfirst;
};

/*
** ****************************************************************************
** ft_exec.c
** ****************************************************************************
*/
int			launch_cmd(t_env *env);
void		ft_exec(t_env *env);
int			*singleton_signal(void);

/*
** ****************************************************************************
** ft_setup.c
** ****************************************************************************
*/
int			ft_setup_pipeline(t_pipeline *pipeline);
t_uint		get_id_build(char *cmd, char ***build);
void		ft_lst_sh_addend(t_lst_bdin **alst, t_lst_bdin *new_elem);
t_lst_bdin	*ft_lst_sh_new(enum e_operand oper, char *str);
int			ft_which_op(char *str);
int			ft_parsing(char *str, t_env *env);

/*
** ****************************************************************************
** ft_parser.c
** ****************************************************************************
*/
int			ft_parser(char *str, t_env *env);

/*
** ****************************************************************************
** ft_env.c
** ****************************************************************************
*/
char		*ft_get_env(char **envp, char *env);
void		ft_set_env(char ***envp, char *env, char *new);
int			ft_unset_env(char ***envp, char *env);
char		**ft_cpy_env(char **env);

/*
** ****************************************************************************
** ft_pwd.c
** ****************************************************************************
*/
char		*ft_get_pwd(void);

/*
** ****************************************************************************
** ft_star.c
** ****************************************************************************
*/
char		**ft_star(t_env *env, char **tab_args);

/*
** ****************************************************************************
** ft_pwd.c
** ****************************************************************************
*/
int			ft_joinlst(t_env *env);

/*
** ****************************************************************************
** ft_lst_bdin.c
** ****************************************************************************
*/
int			ft_lstinbtree(t_env *env);
int			ft_join_red(t_lst_bdin *cpy);
int			ft_tabaddargs(t_lst_bdin *dst, t_lst_bdin *src);
void		ft_lst_sh_print(t_lst_bdin *first);
void		ft_lst_sh_addend(t_lst_bdin **alst, t_lst_bdin *new_elem);
t_lst_bdin	*ft_lst_sh_new(enum e_operand oper, char *str);
void		ft_lst_sh_print(t_lst_bdin *first);
void		ft_lst_sh_del(t_lst_bdin **first);
int			ft_wh1(char *str, int i);
int			ft_wh2(char *str, int j);
int			ft_wh3(char *str, int j);

/*
** ****************************************************************************
** ft_btree.c
** ****************************************************************************
*/

void		ft_clear_btree(t_btree **tree);
t_btree		*ft_create_node_btree(char *cde, char **args_tab, t_operand o);
void		ft_addnode_btree(t_btree **tree, t_operand op, t_btree *n);
void		ft_print_btree(t_btree *tree);
void		ft_printrev_btree(t_btree *tree);

/*
** ****************************************************************************
** ft_printenv.c
** ****************************************************************************
*/
void		ft_print_env(char **envp);
int			test_exit(int status);

/*
** ****************************************************************************
** ft_buildin_cd.c
** ****************************************************************************
*/
int			ft_buildin_cd(t_btree *btin, char **envp);

/*
** ****************************************************************************
** ft_manage_cmd.c
** ****************************************************************************
*/
int			manage_cmd(t_env *env, t_exec exec);
char		*command_path(t_env *env, char *cmd_name);

/*
** ****************************************************************************
** ft_red.c
** ****************************************************************************
*/
int			ft_red_dl(t_env *e, t_btree *l_p, t_btree *r_p, t_exec exec);
int			ft_red_l(t_env *e, t_btree *l_p, t_btree *r_p, t_exec exec);
int			ft_red_dr(t_env *e, t_btree *l_p, t_btree *r_p, t_exec exec);
int			ft_red_r(t_env *e, t_btree *l_p, t_btree *r_p, t_exec exec);
int			ft_pipe(t_env *env, t_btree *cmd, t_btree *file, t_exec exec);

/*
** ****************************************************************************
** ft_manage_exec.c
** ****************************************************************************
*/
void		error_management(t_env *env, int err);
int			ft_execve(t_env *env, t_btree *tree);
int			ft_exec_str(t_env *env, t_btree *tree, t_exec exec, pid_t *pid);

/*
** ****************************************************************************
** ft_file.c
** ****************************************************************************
*/
int			ft_writefile(t_env *env, t_btree *r_part, int fd, t_uint o_mod);
int			ft_microshell(t_env *env, t_btree *r_part, int fd);
#endif
