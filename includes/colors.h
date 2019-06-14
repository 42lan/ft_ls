/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amalsago <amalsago@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/14 15:33:28 by amalsago          #+#    #+#             */
/*   Updated: 2019/06/14 16:10:18 by amalsago         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLORS_H
# define COLORS_H

/*
** SGR (Set Graphic Rendition)
*/

# define SGR_NORMAL			"\e[0m"
# define SGR_BOLD			"\e[1m"
# define SGR_FAINT			"\e[2m"
# define SGR_ITALIC			"\e[3m"
# define SGR_UNDERLINE		"\e[4m"
# define SGR_SLOWBLINK		"\e[5m"
# define SGR_INVERSE		"\e[7m"
# define SGR_NORMALCOLOR	"\e[22m"
# define SGR_NOTITALIC		"\e[23m"
# define SGR_BLINKOFF		"\e[25m"
# define SGR_INVERSEOFF		"\e[27m"

/*
** FG/BG Colors
*/

# define SGR_FG_BLACK		"\e[30m"
# define SGR_FG_RED			"\e[31m"
# define SGR_FG_GREEN		"\e[32m"
# define SGR_FG_YELLOW		"\e[33m"
# define SGR_FG_BLUE		"\e[34m"
# define SGR_FG_MAGENTA		"\e[35m"
# define SGR_FG_CYAN		"\e[36m"
# define SGR_FG_WHITE		"\e[37m"

# define SGR_BG_BLACK		"\e[40m"
# define SGR_BG_RED			"\e[41m"
# define SGR_BG_GREEN		"\e[42m"
# define SGR_BG_YELLOW		"\e[43m"
# define SGR_BG_BLUE		"\e[44m"
# define SGR_BG_MAGENTA		"\e[45m"
# define SGR_BG_CYAN		"\e[46m"
# define SGR_BG_WHITE		"\e[47m"

/*
** Bright FG/BG Colors
*/

# define SGR_BFG_BLACK		"\e[90m"
# define SGR_BFG_RED		"\e[91m"
# define SGR_BFG_GREEN		"\e[92m"
# define SGR_BFG_YELLOW		"\e[93m"
# define SGR_BFG_BLUE		"\e[94m"
# define SGR_BFG_MAGENTA	"\e[95m"
# define SGR_BFG_CYAN		"\e[96m"
# define SGR_BFG_WHITE		"\e[97m"

# define SGR_BBG_BLACK		"\e[100m"
# define SGR_BBG_RED		"\e[101m"
# define SGR_BBG_GREEN		"\e[102m"
# define SGR_BBG_YELLOW		"\e[103m"
# define SGR_BBG_BLUE		"\e[104m"
# define SGR_BBG_MAGENTA	"\e[105m"
# define SGR_BBG_CYAN		"\e[106m"
# define SGR_BBG_WHITE		"\e[107m"

#endif
