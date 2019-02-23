/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ls.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsyveniu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/05 14:08:19 by vsyveniu          #+#    #+#             */
/*   Updated: 2018/06/05 14:48:16 by vsyveniu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LS_FT_LS_H
# define FT_LS_FT_LS_H
# define COLOR_RED  "\x1b[31m"
# define COLOR_BLUE "\x1b[34m"
# define COLOR_MAGENTA "\x1b[35m"
# define COLOR_CYAN "\x1b[36m"
# define COLOR_YELLOW "\x1b[33m"
# define COLOR_YELLOWBLINK "\x1b[33;5m"
# define COLOR_GREEN "\x1b[0;32m"
# define COLOR_BROWN "\x1b[0;33m"

# include <stdio.h>//////////////!!!!!!!!!!!!!!!!!!!
# include <sys/stat.h>
# include <time.h>
# include <dirent.h>
# include "ft_ls.h"
# include <unistd.h>
# include <pwd.h>
# include <grp.h>
# include <sys/xattr.h>
# include <sys/types.h>
# include <sys/acl.h>
# include "libft/libft.h"
# include "errno.h"

typedef struct		s_flags
{
	int				f_rec;
	int				f_r;
	int				f_l;
	int				f_t;
	int				f_a;
	int				f_i;
	int				f_one;
	int				f_color;
	int				f_type;
	int				f_ddash;
	int				f_s;
	int				isfile;
	int				aclcrutch;
	int				voiddircrutch;
	int				rflagpermcructh;

}					t_flags;

typedef struct		s_lst
{
	char			*data;
	struct s_lst	*next;
	char			*path;
	mode_t			stm;
	int				gate;
	int				timemark;
	long long		time;
	struct s_info	*meta;
	int				isfile;
	int				first;
	long long		inode;
	char			*usr;
	char			*group;
	off_t			size;
	char			*timestr;
	char			*color;
	char			*typesymbol;
	char			linkval[4096];
	long long		links;
	size_t			usrpad;
	size_t			gpad;
	int				linkpad;
	int				sizepad;
	long long		eachblk;
	long long		blkpad;
	int				islink;
	char			type;
	int				majorpad;
	int				minorpad;
	int				inodepad;
	long long		major;
	long long		minor;
	int				revnum;
	char			acl;
}					t_lst;

typedef struct		s_info
{
	off_t			size;
	size_t			usrpad;
	size_t			gpad;
	int				linkpad;
	int				sizepad;
	long long		blkpad;
	int				majorpad;
	int				minorpad;
	int				inodepad;
}					t_info;

typedef struct		s_cti
{
	int				color;
	int				type;
	int				inode;
	int				minmajpadcrutch;
}					t_cti;

t_lst				*ft_createlst(t_lst *node, t_lst *dirs, t_flags *flags);
void				ft_fillfiles(t_lst *dirs);
void				ft_filldirswithnull(t_lst *dirs);
void				ft_fillnullcticrutch(t_cti *cticrutch);
int					ft_f(t_lst *node, t_lst **files, t_flags *flags, int *cr);
void				ft_printinode(t_lst *dirs);
void				ft_printfiletypev2(t_lst *dirs);
void				ft_fillnull (t_info *meta);
long long			ft_gettotal(t_lst *head, t_flags *flags, int *totalcrutch);
void				ft_printtotal(long long total, t_flags *flags);
void				ft_printlinkcount(t_lst *meta, t_flags *flags);
void				ft_printusr(t_lst *meta);
void				ft_printgroup(t_lst *meta);
void				ft_printsize(t_cti *cticrutch, t_lst *meta);
void				ft_printminmaj(t_lst *meta);
void				ft_printtime(t_lst *meta);
void				ft_printfile(char *str, t_lst *meta, t_cti *cticrutch);
void				ft_printtypesym(t_lst *meta);
void				ft_printlink(t_lst *meta);
char				ft_getacl(char *path);
void				ft_getaclcrutch(t_flags *flags, t_lst *dirs);
void				ft_printv(t_lst *dirs, t_cti *cticrutch, t_flags *flags);
void				ft_printcat(t_lst *dirs, t_flags *flags, int count);
void				ft_filllistrec(t_lst *node, t_lst *dirs);
void				ft_ifsort(t_lst **dirs, t_flags *flags);
void				ft_printnosuchfile(t_lst *node);
t_lst				*ft_findhead(t_lst *node);
t_lst				*ft_cutthebullshit(t_lst *node, t_flags *flags);
void				ft_freenode(t_lst *node);
t_lst				*ft_findheadfiles(t_lst *node, t_flags *flags);
t_lst				*ft_findhead(t_lst *node);
void				ft_printfilepermissionsv2(t_lst *meta);
void				ft_printaclxattr(t_lst *dirs, t_flags *flags);
void				ft_printone(t_lst *dirs, t_cti *cticrutch);
void				ft_resetcolor();
void				ft_setcolor(char *str);
t_lst				*ft_alphasort(t_lst *node);
void				ft_sortbytime2(t_lst **node);
void				ft_reverse(t_lst **node);
void				ft_restside(t_lst *side, t_lst **node);
void				ft_splitm(t_lst *node, t_lst **lside, t_lst **rside);
int					ft_getintlen(long long num);
void				ft_freedirs(t_lst *dirs);
void				ft_recursion(t_lst *node, t_flags *flags);
void				ft_printdeep(t_lst *head, t_flags *flags, int count);
void				ft_printpermden(t_lst *dirs, t_flags *flags, int count);
t_lst				*ft_addnodemm(char *str);
void				ft_getpadding(t_lst *head, t_lst *node, t_flags *flags);
void				ft_filllist(t_lst *node);
void				ft_flagerrorchar(char c);
void				ft_flagerror(char *str);
int					ft_checkiflink(char *str);
void				ft_fillcolortype(t_lst *dirs, struct stat statbuf);
int					ft_check(t_lst *dirs);
t_lst				*ft_addnode(char *str);
void				ft_mergesort(t_lst **node);
void				ft_flagszero(t_flags *flags);
void				ft_fillflags(char *str, t_flags *flags);
void				ft_freeall(t_lst *nodes);
t_lst				*ft_cutfiles(t_lst *node, t_flags *flags);
void				ft_hendr(t_lst *node, t_flags *flags, int count, int ocr);
void				ft_pdir(t_lst *node, t_flags *flags, int count, int ocr);
void				ft_mergeexpand(t_lst **node, t_lst *lside, t_lst *rside);
void				ft_sortbytime(t_lst **node);
void				ft_ifsort2(t_lst **dirs, t_flags *flags);
int					ft_cutsymdir(char *data, t_flags *flags);
int					ft_checksymdir(char *data, t_flags *flags);
int					ft_keepsymdir(char *data, t_flags *flags);

#endif
