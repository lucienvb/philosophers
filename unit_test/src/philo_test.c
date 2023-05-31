#include "../include/unit_test.h"
//#include <unit_test.h>
#include <criterion/redirect.h>

/*******************************************************************************/
/*                                basic_cases                                  */
/*******************************************************************************/

Test(philo, basic_test)
{
	bool	status;

	cr_redirect_stdout();
	status = philo("hallo");
//	cr_assert_eq(status, false);
//	cr_assert_eq(status, true);

	cr_assert_eq(status, true);
	cr_assert_stdout_eq_str("hallo");
}