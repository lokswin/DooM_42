/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: drafe <drafe@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/14 18:46:09 by drafe             #+#    #+#             */
/*   Updated: 2020/01/20 15:36:51 by drafe            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

/*
** **************************************************************************
**	static int door_total(t_player *pl)
**	Function to init array of doors
** **************************************************************************
*/

static void	door_init(t_player *pl, int	*sec_arr)
{
	int	i;

	i = -1;
	while(++i < pl->door_all)
	{
		printf("i==%d sec_arr[i]==%d\n", i, sec_arr[i]);
		pl->doors[i].nb = sec_arr[i];
		pl->doors[i].dir = 0.1;
		pl->doors[i].max_d = 20;
		pl->doors[i].min_d = 0;
	}
}

/*
** **************************************************************************
**	static void door_total(t_player *pl)
**	Function to countdown doors and malloc them
**	pl->sectors[pl->door.nb].ceil = pl->sectors[pl->door.nb].ceil
** **************************************************************************
*/

static void	door_total(t_player *pl)
{	
	int	i;
	int	sec_arr[MAX_DOORS];
	int	*ptr;

	pl->door_all = 0;
	i = -1;
	while(++i < pl->sectors_nb)
	{
		printf("i==%d sec_arr[i]==%d\n", i, sec_arr[i]);
		if ((pl->sectors[i].ceil == 0) && (pl->sectors[i].floor == 0))
		{
			sec_arr[pl->door_all] = i;
			if (pl->door_all++ >= MAX_DOORS)
			{
				ft_putstr_fd("Too much doors", 2);
				exit(EXIT_FAILURE);
			}
		}
	}
	ptr = sec_arr;
	if (pl->door_all > 0)
		if (!(pl->doors = (t_door *)malloc(sizeof(t_door) * pl->door_all)))
			exit(EXIT_FAILURE);
	door_init(pl, ptr);
}


/*
** **************************************************************************
**	static int door_exist(t_player *pl)
**	Function to define doors in front of player
** **************************************************************************
*/

static int	door_exist(t_player *pl)
{
	t_xy	intersect;
	//t_xy	view_vec;
	t_vector3	vec;
	t_vector3	vec2;
	t_vector3	vec3;
	t_vector3	vec4;
	int		sec_nb;
	float	x2;
	float	y2;
	//float	x3;
	//float	y3;
	//float	pl_x;
	//float	pl_y;
	int		dist;

	dist = -1;
	sec_nb = 2;
	x2 = 0;
	y2 = 0;
	intersect.x = 0;
	printf("where x == %f where y == %f agl==%f aglcos==%f aglsin==%f\n", pl->where.x, pl->where.y, pl->angle, pl->anglecos, pl->anglesin);
	printf("v0  x==%f y==%f points==%d\n", pl->sectors[sec_nb].vertex[1].x, pl->sectors[sec_nb].vertex[1].y, pl->sectors[sec_nb].npoints);
	printf("v3  x==%f y==%f points==%d\n", pl->sectors[sec_nb].vertex[3].x, pl->sectors[sec_nb].vertex[3].y, pl->sectors[sec_nb].npoints);
	printf("\n pl->t1.x==%f, pl->t1.y==%f,\n pl->t2.x==%f, pl->t2.y==%f \n\n", pl->t1.x, pl->t1.y, pl->t2.x, pl->t2.y);
	printf("\n pl->x1==%f, pl->x2==%f\n\n", pl->x1, pl->x2);
	pl->t1.x = vec2.x * pl->anglesin - vec2.y * pl->anglecos;
	pl->t1.y = vec2.x * pl->anglecos + vec2.y * pl->anglesin;
	pl->t2.x = vec3.x * pl->anglesin - vec3.y * pl->anglecos;
	pl->t2.y = vec3.x * pl->anglecos + vec3.y * pl->anglesin;
	
	vec2.x = pl->sectors[sec_nb].vertex[1].x - pl->where.x;
	vec2.y = pl->sectors[sec_nb].vertex[1].y - pl->where.y;
	vec3.x = pl->sectors[sec_nb].vertex[3].x - pl->where.x;
	vec3.y = pl->sectors[sec_nb].vertex[3].y - pl->where.y;

	if ((vec2.y <= 0) || (vec2.y <= 0))
	{
		intersect = Intersect(vec2.x, vec2.y, vec3.x, vec3.y, -pl->nearside, pl->nearz, -pl->farside, pl->farz);

		printf("i1 x == %f y == %f\n", intersect.x, intersect.y);
		intersect = Intersect(vec2.x, vec2.y, vec3.x, vec3.y, pl->nearside, pl->nearz, pl->farside, pl->farz);
		printf("i2 x == %f y == %f\n", intersect.x, intersect.y);
	}
	//vec2 = ft_vec3_normalize(vec2);
	//vec3 = ft_vec3_normalize(vec3);
	//x2 = vxs(vec2.x, vec2.y, vec.x, vec.y);
	//y2 = vxs(vec3.x, vec3.y, vec.x, vec.y);
	
	printf("vec x==%f y==%f z==%f\n", vec.x, vec.y, vec.z);
	printf("vec 2 x==%f y==%f z==%f\n", vec2.x, vec2.y, vec2.z);
	printf("vec 3 x==%f y==%f z==%f\n", vec3.x, vec3.y, vec3.z);
	printf("vec 4 x==%f y==%f z==%f\n", vec4.x, vec4.y, vec4.z);
	//printf("nearside==%f nearz==%f farside==%f farz==%f\n", pl->nearside, pl->nearz, pl->farside, pl->farz);
	//printf("x2 == %f y2 == %f\n", x2, y2);
	//printf("x2 == %f y2 == %f x3 == %f y3 == %f pl_x == %f pl_y == %f\n", x2, y2, x3, y3, pl_x, pl_y);

	/*
	//ft_vec3_normalize()
	//x2 = vxs(pl->where.x, pl->where.y, pl->sectors[sec_nb].vertex[0].x, pl->sectors[sec_nb].vertex[0].y);
	//y2 = vxs(pl->where.x, pl->where.y, pl->sectors[sec_nb].vertex[3].x, pl->sectors[sec_nb].vertex[3].y);
	//x2 = vxs();
	//y2 = vxs();
	//D' = D / |D| 
	= (1, 1) / sqrt(12 + 12) 
	= (1, 1) / sqrt(2) 
	= (0.71, 0.71)
	//V' = V / |V| 
	= (2, -1) / sqrt(22 + (-1)2) 
	= (2,-1) / sqrt(5) 
	= (0.89, -0.45)//hero
	//Θ = acos(D'V') = acos(0.71*0.89 + 0.71*(-0.45)) = acos(0.31) = 72
*/
	/*	
	intersect = Intersect(pl->t1.x, pl->t1.y, pl->t2.x, pl->t2.y, pl->nearside, pl->nearz, pl->farside, pl->farz);
	x = fabs(pl->sectors[sec_nb].vertex[0].x - pl->sectors[sec_nb].vertex[3].x);
	y = fabs(pl->sectors[sec_nb].vertex[0].y - pl->sectors[sec_nb].vertex[3].y);
	x = pl->where.x - x;
	y = pl->where.y - y;
	intersect = Intersect(pl->sectors[sec_nb].vertex[0].x, pl->sectors[sec_nb].vertex[0].y, \
	pl->sectors[sec_nb].vertex[3].x, pl->sectors[sec_nb].vertex[3].x, pl->where.x, pl->where.y, x, y);



	x = pl->sectors[sec_nb].vertex->x - pl->where.x;
	y = pl->sectors[sec_nb].vertex->y - pl->where.y;
	
		view_vec.x = pl->where.x - pl->sectors[sec_nb].vertex->x;
	view_vec.y = pl->where.y - pl->sectors[sec_nb].vertex->y;
	dist = sqrt(pow(view_vec.x, 2) + pow(view_vec.y, 2));
	
	*/

	//printf("x==%d y==%d dist==%d\n", x, y, dist);
	//printf("x==%f y==%f\n", intersect.x, intersect.y);
	//printf("x==%f y==%f x2==%f y2==%f\n", pl->t1.x, pl->t1.y, pl->t2.x, pl->t2.y);
	return (1);
}

/*
** **************************************************************************
**	void door_button(t_player *pl, t_subevents *se)
**	Function to start lift door when button pressed
** **************************************************************************
*/

void		door_button(t_player *pl, t_subevents *se)
{
	int		d_nb;
	int		d_sec_nb;

	if (pl->door_all == -1)
		door_total(pl);
	else if (pl->door_all < 1)
		return ;
	d_nb = door_exist(pl);
	d_nb = 0;//always first
	pl->door_nb = d_nb;
	d_sec_nb = pl->doors[d_nb].nb;
	if ((pl->sectors[d_sec_nb].ceil) <= pl->doors[d_nb].max_d)
		se->wsad[4] = 1;
	else
		se->wsad[4] = 0;
	
	
}

/*
** **************************************************************************
**	void door(t_player *pl)
**	Function to door open process
** **************************************************************************
*/

void		door(t_player *pl, t_subevents *se)
{
	int		d_nb;
	int		d_sec_nb;

	
	d_nb = pl->door_nb;
	d_sec_nb = 0;
	if ((pl->door_all < 1) || (d_nb > pl->door_all))
		return ;
	d_sec_nb = pl->doors[d_nb].nb;
	if (((pl->sectors[d_sec_nb].ceil + pl->doors[d_nb].dir) \
	<= pl->doors[d_nb].max_d) && (se->wsad[4] == 1))
		pl->sectors[d_sec_nb].ceil += pl->doors[d_nb].dir;
	/**/d_sec_nb = se->wsad[4] == 1;
}

/*
//printf("wsad==%d, ceil==%f, dir==%f\n", se->wsad[4], pl->sectors[2].ceil, pl->door.dir);
	//printf("all_sec_nb == %d floor == %f\n", pl->sectors_nb, pl->sectors[2].floor);
	//if (((pl->sectors[2].ceil + pl->door.dir) >= 0) && se->wsad[4] && (pl->door.dir < 0))
	//	pl->sectors[2].ceil += pl->door.dir;printf("x == %f	y == %f	angle==%f\n", pl->where.x, pl->where.y, pl->angle);
	
	printf("pl->doors[0].nb == %d\n", pl->doors[0].nb);
	printf("pl->doors[1].nb == %d\n", pl->doors[1].nb);
	printf("pl->doors[2].nb == %d\n", pl->doors[2].nb);
	printf("pl->doors[3].nb == %d\n", pl->doors[3].nb);
	pl->door.nb = 2;
	pl->door.dir = 0.1;
	pl->door.max_d = 20;
	pl->door.min_d = 0;
	pl->door.doors_nb = -1;
	pl->door.nb = 0;

*/