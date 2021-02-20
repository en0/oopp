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

#include <rpos/log.h>
#include <arch/io.h>

#include <log/serial.h>

static inline int is_transmit_empty(int port) {
    return inb(port + 5) & 0x20;
}
 
static inline void write_serial(int port, int a) {
    while (is_transmit_empty(port) == 0);
    outb(a, port);
}

static inline void init(int port) {
    outb(0x00, port+1);
    outb(0x80, port+3);
    outb(0x03, port+0);
    outb(0x00, port+1);
    outb(0x03, port+3);
    outb(0xC7, port+2);
    outb(0x0B, port+4);
}

static inline void init_com1() { init(COM1_ADDR); }
static inline void init_com2() { init(COM2_ADDR); }
static inline void init_com3() { init(COM3_ADDR); }
static inline void init_com4() { init(COM4_ADDR); }

static inline int write_com1(char c) { write_serial(COM1_ADDR, (int)c); return 1; }
static inline int write_com2(char c) { write_serial(COM2_ADDR, (int)c); return 1; }
static inline int write_com3(char c) { write_serial(COM3_ADDR, (int)c); return 1; }
static inline int write_com4(char c) { write_serial(COM4_ADDR, (int)c); return 1; }

struct LogTarget log_target_com1 = { .emitc = write_com1, .initialize = init_com1 };
struct LogTarget log_target_com2 = { .emitc = write_com2, .initialize = init_com2 };
struct LogTarget log_target_com3 = { .emitc = write_com3, .initialize = init_com3 };
struct LogTarget log_target_com4 = { .emitc = write_com4, .initialize = init_com4 };
