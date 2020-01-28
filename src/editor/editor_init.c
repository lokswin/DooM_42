/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/12 12:07:54 by dorange-          #+#    #+#             */
/*   Updated: 2020/01/28 19:50:13 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_editor_add_new_txtr(t_wolf3d *w, char *path)
**
**	Function that set new texture surface and convert surface format.
** **************************************************************************
*/

void		ft_editor_add_new_txtr(t_wolf3d *w, char *path)
{
	t_txtr			txtr;
	t_list			*new_list;
	SDL_Surface		*temp_surf;

	txtr.id = w->txtr_count + 1;
	// txtr.color = color;
	temp_surf = IMG_Load(path);
	txtr.surf = SDL_ConvertSurfaceFormat(temp_surf, SDL_PIXELFORMAT_ARGB8888, 0);
	// temp_surf
	SDL_FreeSurface(temp_surf);
	txtr.color = *(int*)txtr.surf->pixels;
	new_list = ft_lstnew(&txtr, sizeof(txtr));
	// sleep(10);
	// exit(0);
	if (w->txtr == NULL)
		w->txtr = new_list;
	else
		ft_lstadd(&w->txtr, new_list);
	w->txtr_count++;
}

/*
** **************************************************************************
**	void ft_editor_init_txtr_list(t_wolf3d *w)
**
**	Function that set texture surface list.
** **************************************************************************
*/

void		ft_editor_init_txtr_list(t_wolf3d *w)
{
	// Теряется много памяти
	ft_editor_add_new_txtr(w, "Textures/wall1.png");
	ft_editor_add_new_txtr(w, "Textures/wall1.png");
	// ft_editor_add_new_txtr(w, "Textures/wood.png");
	// ft_editor_add_new_txtr(w, "Textures/wall2.png");
	// ft_editor_add_new_txtr(w, "Textures/wall1.png");
	// ft_editor_add_new_txtr(w, "Textures/wood.png");
	// ft_editor_add_new_txtr(w, "Textures/wall2.png");
}

/*
** **************************************************************************
**	void ft_editor_init(t_wolf3d *w)
**
**	Function that set some editor parameters.
** **************************************************************************
*/

void		ft_editor_init(t_wolf3d *w)
{
	w->sector_count = 0;
	w->sector = NULL;
	w->txtr = NULL;
	w->txtr_count = 0;
	ft_editor_init_txtr_list(w);
	w->gui_map.r1 = (t_vector3){0, 0, 0, 0};
	w->gui_map.r2 = (t_vector3){VER_WIDTH, VER_HEIGHT, 0, 0};
}