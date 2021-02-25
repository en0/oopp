/**
 ** Copyright (c) 2017 "Ian Laird"
 ** Research Project Operating System (rpos) - https://github.com/en0/rpos-kernel
 ** 
 ** This file is part of rpos
 ** 
 ** rpos is free software: you can redistribute it and/or modify
 ** it under the terms of the GNU General Public License as published by
 ** the Free Software Foundation, either version 3 of the License, or
 ** (at your option) any later version.
 ** 
 ** This program is distributed in the hope that it will be useful,
 ** but WITHOUT ANY WARRANTY; without even the implied warranty of
 ** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 ** GNU General Public License for more details.
 ** 
 ** You should have received a copy of the GNU General Public License
 ** along with this program.  If not, see <http://www.gnu.org/licenses/>.
 **/

#include <rpos/kernel.h>
#include <rpos/init.h>
#include <rpos/log.h>

static void do_initcalls() {
    for(int i = 0; &__initcall_start[i] < &__initcall_end; i++)
        __initcall_start[i]();
}

void start_kernel() {

    setup_arch();

    // TODO: mm_init (paging)

    do_initcalls();

    log.puts("");
    log.puts(" _ __ _ __   ___  ___ ");
    log.puts("| '__| '_ \\ / _ \\/ __|");
    log.puts("| |  | |_) | (_) \\__ \\");
    log.puts("|_|  | .__/ \\___/|___/");
    log.puts("     |_|              ");
    log.puts("");
}
