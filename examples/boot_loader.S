## Copyright (c) 2017 "Ian Laird"
## Research Project Operating System (rpos) - https://github.com/en0/rpos-kernel
## 
## This file is part of rpos
## 
## rpos is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
## 
## This program is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
## GNU General Public License for more details.
## 
## You should have received a copy of the GNU General Public License
## along with this program.  If not, see <http://www.gnu.org/licenses/>.

#include <asm/proto.h>

.set VALID_MAGIC, 0x2BADB002


.section .tstack, "aw", @nobits
.skip 1024
stack:  nop     ## 1KB of stack space.


.section .bss
.align 4

GLOBAL(g_mboot_info)
    .4byte 0x00
END(g_mboot_info)


.section .text
.align 4

GLOBAL(_start)
    movl $stack, %esp       ## Setup temp stack
    pushl $0                ## Reset EFLAGS
    popf
    cmp $VALID_MAGIC, %eax  ## Check the multiboot magic number
    jnz die

    ## Initialize the system
    ## Setups memory, ISRs, and basic peripherals.
    mov %ebx, g_mboot_info  ## EBX points to multiboot_info_t
    call x86_boot_entry   ## Call main()
ENDPROC(_start)

GLOBAL(die)
    ## Either the system is not multiboot compliant or sysinit
    ## returned - Either way, we cannot do anything. System is dead.
    cli                     ## Stop all hardware interupts
    hlt                     ## Halt the CPU
    jmp die                 ## Infinite loop
ENDPROC(die)
