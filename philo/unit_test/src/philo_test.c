#include "../include/unit_test.h"
//#include <unit_test.h>
//#include <criterion/redirect.h>

/*******************************************************************************/
/*                                parser_cases                                 */
/*******************************************************************************/

static void	parser_cases(int input, bool expected_status)
{
	bool	status;

	status = false;
	status = parser(input);
	cr_assert_eq(status, expected_status);
}

Test(parser, to_low)
{
	parser_cases(4, false);
}

Test(parser, exact_five)
{
	parser_cases(5, true);
}

Test(parser, to_six)
{
	parser_cases(6, true);
}

Test(parser, to_high)
{
	parser_cases(7, false);
}
