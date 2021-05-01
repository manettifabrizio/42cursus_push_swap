/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   macros.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmanetti <fmanetti@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/30 22:50:56 by fmanetti          #+#    #+#             */
/*   Updated: 2021/05/01 20:50:47 by fmanetti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MACROS_H
# define MACROS_H

# define	NO_PRINT		0
# define	A				1
# define	B				2
# define	SLEEP_TIME		1000000

# define	CURSOR_HOME		"\e[H"
# define	CLEAR_SCREEN	"\e[J"

# define    RED             "\e[0;31m"
# define    GREEN           "\e[0;32m\e[1m"
# define    NO_COLOR        "\e[0m"

# define	ESCAPE			27
# define 	ARR_RIGHT		67
# define 	ARR_LEFT		68

# define	SWAP_A			"sa"
# define	SWAP_B			"sb"
# define	SWAP_AB			"ss"
# define	PUSH_A			"pa"
# define	PUSH_B			"pb"
# define	ROTATE_A		"ra"
# define	ROTATE_B		"rb"
# define	ROTATE_AB		"rr"
# define	REV_ROTATE_A	"rra"
# define	REV_ROTATE_B	"rrb"
# define	REV_ROTATE_AB	"rrr"

# define	ERROR			"\e[0;31m\e[1mError\n\e[0m"
# define	OK				"\e[0;32m\e[1mOK\e[0m"
# define	KO				"\e[0;31m\e[1mKO\e[0m"

#endif