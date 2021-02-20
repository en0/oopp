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

#ifndef _x86_LOG_SERIAL_H
#define _x86_LOG_SERIAL_H

#define COM1_ADDR 0x3f8
#define COM2_ADDR 0x2f8
#define COM3_ADDR 0x3e8
#define COM4_ADDR 0x2e8

extern struct LogTarget log_target_com1;
extern struct LogTarget log_target_com2;
extern struct LogTarget log_target_com3;
extern struct LogTarget log_target_com4;

#endif /* ! _x86_LOG_SERIAL_H */
