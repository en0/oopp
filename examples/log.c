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

#include <stdlib.h>
#include <stddef.h>
#include <stdarg.h>
#include <rpos/log.h>

static struct LogTarget *device;

static void attach(struct LogTarget *d) { 
    d->initialize(); device = d; 
}

static inline int emitc(char c) {
    if(device != NULL)
        return device->emitc(c);
    else
        return 0;
};

static void putc(char c) {
    emitc(c);
}

static void puts(char *c) {
    for(;*c != '\0';emitc(*c), c++);
    emitc('\n');
}

static void printf(const char *format, ...) {

    const char *p;

    int va_char;
    char *va_str;
    char buffer[32];

    va_list params;
    va_start(params, format);

    for(p = format; *p != '\0'; p++) {
        if(*p != '%') {
            emitc(*p);
            continue;
        }

        switch(*++p) {
            case '%' : /* Literal % */
                emitc('%');
                break;

            case 'c' : /* Charater */
                va_char = va_arg(params, int);
                emitc((char)va_char);
                break;

            case 's' : /* C String */
                va_str = (char*)va_arg(params, int);
                for(;*va_str != '\0'; va_str++)
                    emitc((*va_str));
                break;

            case 'd' : /* Signed Integer */
            case 'i' :
                va_char = (int)va_arg(params, int);
                itoa(va_char, buffer, 10);
                printf(buffer);
                break;

            case 'u' : /* Unsigned Integer */
                va_char = (int)va_arg(params, int);
                utoa(va_char, buffer, 10);
                printf(buffer);
                break;

            case 'x' : /* Unsigned Hex (lower case only) */
            case 'X' :
                va_char = (int)va_arg(params, int);
                utoa(va_char, buffer, 16);
                printf(buffer);
                break;

            case 'o' : /* Unsigned Octal */
                va_char = (int)va_arg(params, int);
                utoa(va_char, buffer, 8);
                printf(buffer);
                break;

            case 'p' : /* Pointer */
                va_char = (int)va_arg(params, int);
                utoa(va_char, buffer, 16);
                printf("0x%s", buffer);
                break;

            case 'b' : /* Binary */
                va_char = (int)va_arg(params, int);
                utoa(va_char, buffer, 2);
                printf("%sb", buffer);

            case 'n' : /* nothing (Param must be an int) */
                va_char = (int)va_arg(params, int);
                break;
        }
    }

    va_end(params);
}

const struct Logger log = {
    .putc = putc,
    .puts = puts,
    .printf = printf,
    .attach = attach
};
