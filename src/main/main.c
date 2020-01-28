/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/27 20:31:00 by dorange-          #+#    #+#             */
/*   Updated: 2020/01/28 20:05:59 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

/*
** **************************************************************************
**	void ft_main(int c, char **v)
**
**	General programm function.
** **************************************************************************
*/

void			ft_main(int c, char **v)
{
	t_wolf3d	w;
	t_new_temp	data;

	// exit(0);
	

	ft_bzero(&data, sizeof(t_new_temp));
	w.new_data = &data;

	w.sdl = sdl_init(w.sdl);
	ft_init_wolf(&w);
	ft_gui_init(&w);
	// init
	ft_editor_init(&w);
	// gui init
	ft_main_gui_init(&w);


	ft_editor_gui_init(&w);
	
	ft_game_init(&w, "map1"); // Пока что инициализирует конкретный файл

	ft_gui_redraw(&w);

	// sleep(10);
	// exit(0);



	// exit(0);


	while (w.sdl->running)
		ft_main_events(&w);
		// ft_gui_events(&w);
	ft_editor_sector_special_debug(w.sector);
	ft_editor_desctuct(&w);
	ft_gui_desctuct(w.gui.dom);
	ft_gui_desctuct_fonts(w.gui.fonts);
}

int				main(int c, char **v)
{
	ft_main(c, v);
	return (0);
}