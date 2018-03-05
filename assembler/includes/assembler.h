/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assembler.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psprawka <psprawka@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/19 10:56:16 by psprawka          #+#    #+#             */
/*   Updated: 2018/02/19 10:56:18 by psprawka         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <fcntl.h>
# include "../includes/op.h"
# include <stdio.h>
# include <string.h>

# define BUFF_SIZE 				100
# define LABEL_MAX_SIZE 		300
# define LINE_MAX_SIZE 			300
# define INSTRUCTION_MAX_SIZE 	5
# define TOKEN 					file->token

# define NORMAL		"\x1B[0m"
# define BLACK		"\x1B[30m"
# define RED		"\x1B[31m"
# define GREEN		"\x1B[32m"
# define YELLOW		"\x1B[33m"
# define BLUE		"\x1B[34m"
# define MAGNETA	"\x1B[35m"
# define CYAN		"\x1B[36m"
# define WHITE		"\x1B[37m"


typedef struct		header_s
{
	unsigned int		magic;
	char				prog_name[PROG_NAME_LENGTH + 1];
	unsigned int		prog_size;
	char				comment[COMMENT_LENGTH + 1];
}					header_t;

typedef struct	s_token
{
	char		*name;
	int			op_offset;
	char		*line;
	int			bytecode;
	int			pos;
}				t_token;

typedef struct	s_file
{
	int			fd;
	header_t 	*header;
	char		*data;
	char		*name;
	int			offset;
	int			op_offset;
	char		*line;
	char		**labels;
	int			labels_nb;
	t_token		*token;
	
}				t_file;

typedef struct	s_op
{
	char	*name;
	int		arg_nb;
	int		args[4];
	int		op_code;
	int		cycle;
	char	*des;
	int		coding_byte;
	int		dir_size;
}				t_op;

//extern t_op op_tab[17];



/* ft_libft */
char		*ft_strsub(char *s, int start, size_t len);
void		*ft_memset(void *s, int c, size_t n);
char		*ft_strchr(char *str, char to_find);
int			ft_strlen_chr(char *str, char c);
char 		*ft_strncpy(char *str, int size);
char		*ft_strjoin(char *s1, char *s2);
int			ft_strcmp(char *s1, char *s2);
void		ft_bzero(void *s, size_t n);
char		*ft_strnew(size_t size);
char		*ft_strdup(char *src);
int 		ft_strlen(char *str);
int			ft_isdigit(char c);
char    	*ft_itoa(int nbr);
long int	ft_atoi(char *s);

/* tools */
char 	*readandstore(char *filename);
void	op_offset(t_file *file);
int		gnl(t_file *file);

/* labels */
void	handle_labels(t_file *file);
void	vname(t_file *file);
void	vargs(t_file *file);
void	add_label(t_file *file, char *label);

/* header */
void	handle_header(t_file *file);
void	write_header(t_file *file);

/* prog_size */
int		varg(t_file *file, char t, int arg);
void	prog_size(t_file *file, int cycle);