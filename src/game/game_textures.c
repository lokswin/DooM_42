/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjuana <tjuana@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/28 21:41:14 by dorange-          #+#    #+#             */
/*   Updated: 2020/01/29 15:29:02 by tjuana           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "doom.h"

int			ft_get_pixel(SDL_Surface *sur, int x, int y)//no da el pixel que vamos a usar
{
    int		*pixel;

    pixel = sur->pixels + y * (sur->pitch ) + x * sur->format->BytesPerPixel;
    return (*pixel);
}

int			color_transoform(int color, float percent)
{
    int		rgb[4];

    rgb[0] = ((color >> 0) & 0xFF) * percent;
    rgb[1] = ((color >> 8) & 0xFF) * percent;
    rgb[2] = ((color >> 16) & 0xFF) * percent;
    rgb[3] = (color >> 24) & 0xFF *0;
    color = ( (rgb[3] << 24) | (rgb[2] << 16) | (rgb[1] << 8) | rgb[0] << 0);
    //printf("color %d\n", rgb[3]);
    return (color);
}


void		pix1(t_new_player *pl, int image)//guarda la textura gun
{
    int *pix;
    unsigned int p;
    int hex;

    pix = (int *)pl->srf->pixels;
	p = ((pl->t.txtz % pl->srf->h) * pl->tex[image].w + (pl->t.txtx1 % pl->srf->w)% pl->tex[image].w);//formula = y*w + x
	hex = hexcolor(pl->tex[image].pixels[p].r, pl->tex[image].pixels[p].g, pl->tex[image].pixels[p].b);
	pix[pl->t.y * WIN_W + pl->t.x ] = color_transoform(hex, pl->light);
}
