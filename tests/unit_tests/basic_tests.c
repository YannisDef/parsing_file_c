/*
** EPITECH PROJECT, 2021
** B-CPE-200-PAR-2-1-matchstick-yannis.defontaine
** File description:
** test_ia_brain
*/

#include <criterion/criterion.h>
#include "project.h"
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
