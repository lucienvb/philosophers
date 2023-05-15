

/* ************************************************************************** */
/*                                                                            */
/*                                                    .--.  _                 */
/*   unit_test.h                                     |o_o || |                */
/*                                                   |:_/ || |_ _   ___  __   */
/*   By: safoh <safoh@student.codam.nl>             //   \ \ __| | | \ \/ /   */
/*                                                 (|     | )|_| |_| |>  <    */
/*   Created: 2022/03/25 17:34:35 by safoh        /'\_   _/`\__|\__,_/_/\_\   */
/*   Updated: 2022/09/20 11:09:28 by safoh        \___)=(___/                 */
/*                                                                            */
/* ************************************************************************** */

#ifndef UNIT_TEST_H
# define UNIT_TEST_H
# include <criterion/criterion.h>
# include <criterion/redirect.h>
# include <criterion/new/assert.h>
# include <criterion/new/memory.h>
# include <criterion/new/stream.h>
# include <criterion/alloc.h>
# include <criterion/abort.h>
# include <criterion/event.h>
# include <criterion/options.h>
# include <criterion/output.h>
# include <criterion/parameterized.h>
# include <criterion/stats.h>
# include <criterion/types.h>
# include "include/philo.h"
# include <criterion/assert.h>
# include <criterion/internal/assert.h>
# include "custom_malloc.h"

void redirect_all_std(void);

#endif
