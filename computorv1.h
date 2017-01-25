/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computorv1.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elemarch <elemarch@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/03 16:04:31 by elemarch          #+#    #+#             */
/*   Updated: 2015/05/05 21:04:49 by elemarch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTORV1_H
# define COMPUTORV1_H

# include "libft.h"
# include <stdio.h>

/*
** =============================== GENERAL ================================= **
** This program uses my libft only. 										 **
** Here are the options : 													 **
**  h: "hide" forbid the program to print anything else than results.		 **
**	m: "more" prints the different steps of the process.					 **
**	c: "color" adds some colors to the equations.							 **
** ========================================================================= **
*/

# define OPT_C (o >= 4)
# define OPT_M (o == 2 || o == 3 || o >= 6)
# define OPT_H (o % 2 == 1)
# define L_SIGN(x) (x == '-' || x == '+')
# define H_SIGN(x) (x == '*')

/*
** ============================== STRUCTURES =============================== **
*/

typedef struct	s_eq
{
	float		a;
	float		b;
	float		c;
	int			p;
}				t_eq;

/*
** ============================== PROTOTYPES =============================== **
** 																			 **
** = eq.c ===== 1 function ================================================= **
** eq_print		| prints the reduced form of an equation					 **
** ========================================================================= **
*/

void			eq_print(t_eq eq, int o);

/*
** = define.c = 3 function ================================================= **
** define_opts	| scans argv to define which options are acivated			 **
**				| 											  needs 1 static **
** ------------------------------------------------------------------------- **
** define_eq	| creates a t_eq from a char *src 							 **
** ========================================================================= **
*/

int				define_opts(const char **argv, int argc, int *o);
void			define_eq(char *src, t_eq *e, int o);

/*
** = float.c == 1 function ================================================= **
** ft_putstrf	| prints a string with a float inside						 **
** ========================================================================= **
*/

void			ft_putnbrf(float n);
float			ft_atof(const char *str);
void			ft_putstrf(const char *str, float n);

/*
** = print.c == 1 function ================================================= **
** ft_putstrf	| prints a string with a float inside						 **
** ========================================================================= **
*/

void			print_step(int step, char *src, int o);
void			parse_eq(char *src, t_eq *e, int o);
void			solve_eq(t_eq *e, int o);
float			solve_hard_discr(t_eq *e, int o);
void			solve_hard_one(t_eq *e, int o);
void			solve_hard_two(t_eq *e, int o);
float			solve_sqrt(float z);
void			shd_colors(t_eq *e);
void			shd_simple(t_eq *e);
void			solve_imagin(t_eq *e, int o);

#endif
