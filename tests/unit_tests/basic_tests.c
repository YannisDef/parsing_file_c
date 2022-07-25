/*
**
** STD::VECTOR IN C
** Rigolo2015, Yannis, 2022
** 
*/

#include <criterion/criterion.h>
#include "value.h"

Test(project, function_test)
{
    cr_assert_eq(function_test(2), 4);
}

Test(project, start_project)
{
    char const * const av[] = {"./project"};

    cr_assert_eq(start_project(av), SUCCESS);
}
