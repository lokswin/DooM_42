/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   editor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dorange- <dorange-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/10 16:05:19 by dorange-          #+#    #+#             */
/*   Updated: 2020/01/12 19:56:46 by dorange-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

int		main(int c, char **v)
{
	// t_wolf3d	w;

	// w.sdl = sdl_init(w.sdl);
	// while (w.sdl->running)
	// {
	// 	ft_editor_renderer(&w);
	// }
	// ft_clean_sdl(&w);
	// return (0);

	t_wolf3d	w;

	// Set map type
	w.type = 0;
	if (c == 2)
		w.type = 1;
	if (c == 3 && ft_strcmp(v[2], "nmap"))
		w.type = 2;

	// Check arguments and file
	if (w.type < 1)
		ft_error("Error: wrong parameters");
	if ((w.fd = open(v[1], O_RDONLY)) < 0)
		ft_error("Error: bad file");

	ft_editor_init(&w);
	ft_parser_nnmp(w.fd, &w);
	ft_editor_sector_special_debug(w.sector);

	w.sdl = sdl_init(w.sdl);
	ft_init_wolf(&w);

	ft_load_textures(&w);
	ft_init_anim(&w);
	ft_init_view_map(&w);
	ft_init_sound(&w);
	fpsinit();
	while (w.sdl->running)
	{
		ft_editor_renderer(&w);
		ft_editor_handle_events(&w);
		ft_editor_use_events(&w);
		fpsthink();
	}
	ft_clean_sdl(&w);
	return (0);
}