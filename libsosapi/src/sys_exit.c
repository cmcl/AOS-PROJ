/*
 * Copyright 2018, Data61
 * Commonwealth Scientific and Industrial Research Organisation (CSIRO)
 * ABN 41 687 119 230.
 *
 * This software may be distributed and modified according to the terms of
 * the BSD 2-Clause license. Note that NO WARRANTY is provided.
 * See "LICENSE_BSD2.txt" for details.
 *
 * @TAG(DATA61_BSD)
 */
#include <stdio.h>
#include <stdlib.h>
#include <sel4/sel4.h>
#include "sos.h"

static void
sel4_abort()
{
    printf("sos aborting\n");
    sos_process_delete(sos_my_id());
    while (1); /* We don't return after this */
}

long
sys_rt_sigprocmask(va_list ap)
{
    /* abort messages with signals in order to kill itself */
    return 0;
}

long
sys_gettid(va_list ap)
{
    /* return dummy for now */
    return 0;
}

long
sys_getpid(va_list ap)
{
    /* assuming process IDs are the same as thread IDs*/
    return 0;
}

long
sys_exit(va_list ap)
{
    abort();
    return 0;
}

long
sys_exit_group(va_list ap)
{
    abort();
    return 0;
}

long
sys_tgkill(va_list ap)
{
    sel4_abort();
    return 0;
}

