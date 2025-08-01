/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   frame_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nasser <nasser@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/10 23:54:04 by fcaldas-          #+#    #+#             */
/*   Updated: 2025/07/15 00:04:30 by nasser           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cub3d.h"

void	frame_loop(void *param)
{
	t_game	*game;

	game = (t_game *)param;
	check_player_life(game);
	enemy_texture_reset(game);
	objective_check(game);
	move_player(game);
	enemy_shots(game);
	draw_background(game, game->data);
	draw_raycasting(game);
	render_elements(game);
	draw_weapon(game);
	mouse_rotation(game);
	ui_init(game);
	if (game->game_won || game->game_lost || game->menu_active)
	{
		fill_with_black(game);
		// return ;
	}
}
