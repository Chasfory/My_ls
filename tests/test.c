/*
** EPITECH PROJECT, 2021
** test_my_printf
** File description:
** my_printf
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "my_lib_ls.h"

void redirect_all_std(void)
{
    cr_redirect_stdout();
    cr_redirect_stdout();
}

Test(main_c, error, .init = redirect_all_std)
{
    int a = 0;

    a = main(0, )
    my_printf("hello world");
    cr_assert_stdout_eq_str("hello world");
}

Test(my_printf, percentage_d, .init = redirect_all_std)
{
    my_printf("j'ai %d", 19);
    cr_assert_stdout_eq_str("j'ai 19");
}