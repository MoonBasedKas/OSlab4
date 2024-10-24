proc.c:
Modified to hold function definitions of thread_create, thread_join, thread_exit, lock_init, lock_aquire, and lock_release.

defs.h:
Added function declaritions, defined lock_t struct and used typedef to define struct lock_t as lock_t.

syscall.h:
Gave our new system calls their call id in the system process table.

syscall.c:
Updated to make our new processes callable with the system call table.

usys.S:
Added syscall for each.

sysproc.c:
Implemented sysproc functions of our new system calls.

Makefile:
Modified to compile threads_nosync.c