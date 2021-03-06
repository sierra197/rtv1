/*
** list.h for rt1 in /home/nguye_1//afs_loc/projects/tmp/rt1/tp
** 
** Made by alexandre1 nguyen
** Login   <nguye_1@epitech.net>
** 
** Started on  Mon Feb 11 09:53:49 2013 alexandre1 nguyen
** Last update Sun Mar 17 16:44:30 2013 alexandre1 nguyen
*/

#ifndef LIST_H_
# define LIST_H_

# define PI		(4 * atan(1.0))
# define CAR(x)		(x * x)
# define RAD(x)		(x * PI / 180)
# define TAN(x)		(tan(RAD(x)))
# define TANC(x)	(CAR(TAN(x)))

typedef struct	s_calc
{
  int		j;
  int		color;
  double	tmp;
  double	d;
}		t_calc;

typedef struct	s_term
{
  char		*cm;
  char		*cl;
  char		*gt;
  char		*us;
  char		*me;
  char		*mr;
  char		*vi;
  char		*ve;
}		t_term;

typedef struct	s_coord
{
  double	e[5];
  double	p[5];
  double	v[5];
  double	a;
  double	b;
  double	c;
  double	d;
}		t_c;

typedef struct	s_param
{
  void		*mlx;
  void		*win;
  void		*img;
  char		tmp_for_filling[1000];
  int		x;
  int		y;
  int		width;
  int		height;
  int		color;
  double	**objects;
  t_term	term;
  t_c		c;
  t_calc	calc;
}		t_param;

typedef struct	s_pars
{
  int	j;
  int	m;
  char	*buf;
}		t_pars;

/* objects.c		*/
double	cone(t_param *, int);
double	plan(t_param *, int);
double	sphere(t_param *, int);
double	cylindre(t_param *, int);
double	hyperboloide(t_param *, int);

/* calc.c		*/
void	calc_j1(t_param *, int);
void	calc_j0(t_param *, int);
int	calc(t_param *);
int	fill_img(t_param *);

/* exit.c		*/
  void	safety_exit(t_param *);

/* init_and_tools.c	*/
int	init_e_p_v(t_param *);
double	nearest_distance(t_param *);

/* loading_bar.c	*/
char	wheel(int);

/* main.c		*/
int	main(int, char **);

/* mlx_basic_func.c	*/
int	my_pixel_put_to_img(t_param *, void *, int, int);
int	display_img(t_param *);
int	gere_key(int, t_param *);

/* parsing_tool.c	*/
int	sttff_next(t_param *, t_pars *, int);
int	str_to_tab_for_filling(char *, t_param *);
int	filling(char *, t_param *);
int	parsing(char *, t_param *);

/* allocation_tools.c	*/
int	str_to_tab_for_allocating(char *);
int	parsing_alloc(t_param *, int);

/* parsing_tools_next.c	*/
int	reset__tmp_for_filling(t_param *);

/* termcap_func.c	*/
int	setting(t_param *);

/* init_and_tools.c	*/
int	init_e_p_v(t_param *);
double	nearest_distance(t_param *);

/* mlx_basic_func.c	*/
int	my_pixel_put_to_img(t_param *, void *, int, int);
int	display_img(t_param *);
int	gere_key(int, t_param *);


char    *get_next_line(const int, int);

#endif /* LIST_H_ */
