/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui_redraw_font.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 17:40:10 by dorange-          #+#    #+#             */
/*   Updated: 2020/02/06 17:56:30 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_gui_fill_elem(t_wolf3d *w, t_list *list, int color)
**
**	Function that put text for elem area.
** **************************************************************************
*/

void	ft_gui_putstr_elem_font(t_wolf3d *w, t_list *list, int color)
{
	int			x;
	int			y;
	t_gui_elem	*elem;

	elem = list->content;
	if (elem == NULL)
		ft_error("ERROR (N6)");
	if (elem->type == GUI_BUTTON)
	{
		if (elem->status & GUI_ELEM_HOVER)
			color = ft_fdf_get_color(color, 0xffffff, 0.5);
		if (elem->status & GUI_ELEM_ACTIVE)
			color = ft_fdf_get_color(color, 0x000000, 0.5);
		if ((((color & C_R) >> 16) + ((color & C_G) >> 8) + (color & C_B)) / 3 > 128)
			color = 0x000000;
		else
			color = 0xffffff;
		ft_gui_font_preset_fsc(w, "fonts/RobotoMono-Medium.ttf", elem->fs, color);
		ft_gui_font_putstr_sdl(w, elem->str, (t_gui_coord){elem->v1.x + 10, elem->v1.y + 10, 0});
	}

	if (elem->type == GUI_TEXT)
	{
		ft_gui_font_preset_fsc(w, "fonts/RobotoMono-Medium.ttf", elem->fs, color);
		ft_gui_font_putstr_sdl(w, elem->str, (t_gui_coord){elem->v1.x + 10, elem->v1.y + 10, 0});
	}
	if (elem->type == GUI_INPUT || elem->type == GUI_INPUT_NUMB)
	{
		ft_gui_font_preset_fsc(w, "fonts/RobotoMono-Medium.ttf", elem->fs, color);
		ft_gui_font_putstr_sdl(w, elem->str, (t_gui_coord){elem->v1.x + 10, elem->v1.y + 10, 0});
	}
}

/*
** **************************************************************************
**	void ft_gui_redraw_elem(t_wolf3d *w, t_list *dom)
**
**	Function that print font for elements.
** **************************************************************************
*/

void	ft_gui_redraw_elem_font(t_wolf3d *w, t_list *dom)
{
	t_list		*list;
	t_gui_elem	*elem;

	list = dom;
	while (list != NULL)
	{
		elem = list->content;
		if (elem->status & GUI_ELEM_HIDDEN)
		{
			list = list->next;
			continue ;
		}
		ft_gui_putstr_elem_font(w, list, elem->color);
		ft_gui_redraw_elem_font(w, elem->child);
		list = list->next;
	}
}