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

#ifndef _RPOS_LOG_H
#define _RPOS_LOG_H 1

struct LogTarget{
    int (*emitc)(char);
    void (*initialize)(void);
};

struct Logger {
    void (*putc)(char);
    void (*puts)(char*);
    void (*printf)(const char*, ...);
    void (*attach)(struct LogTarget*);
};

extern const struct Logger log;

#endif /* ! _RPOS_LOG_H */
