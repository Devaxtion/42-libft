/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testlib.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: leramos- <leramos-@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 19:25:36 by leramos-          #+#    #+#             */
/*   Updated: 2025/04/21 13:28:23 by leramos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TESTLIB_H
# define TESTLIB_H

# include <assert.h>
# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <string.h>
# include <stdio.h>
# include <ctype.h>
# include <stdint.h>
# include "../libft.h"

// Color definitions
# define COLOR_RED "\033[0;31m"
# define COLOR_GREEN "\033[0;32m"
# define COLOR_YELLOW "\033[0;33m"
# define COLOR_BLUE "\033[0;34m"
# define COLOR_CYAN "\033[0;36m"
# define COLOR_RESET "\033[0m"

// Test macros
# define TEST_START() printf("  %-25s", __func__ + 5); fflush(stdout)
# define TEST_PASS() printf(COLOR_GREEN "[PASS]\n" COLOR_RESET)
# define TEST_FAIL() printf(COLOR_RED "[FAIL]\n" COLOR_RESET)

#endif