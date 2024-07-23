/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: flfische <flfische@student.42heilbronn.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 15:35:17 by flfische          #+#    #+#             */
/*   Updated: 2024/07/22 16:14:08 by flfische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#define RESET "\033[0m"
#define BOLD "\033[1m"
#define SEMIBOLD "\033[2m"
#define ITALIC "\033[3m"
#define RED "\033[38;2;255;4;42m"
#define GREEN "\033[32m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define CYAN "\033[36m"

#define ERROR RED BOLD
#define WARNING YELLOW BOLD
#define INFO CYAN BOLD
#define SUCCESS GREEN BOLD
#define PROMPT BLUE ITALIC
