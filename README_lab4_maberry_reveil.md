proc.c:
Modified to hold function definitions of thread_create, thread_join, thread_exit, lock_init, lock_aquire, and lock_release.

defs.h:
Added function declaritions, defined lock_t struct and used typedef to define struct lock_t as lock_t.

Makefile:
Modified to compile threads_nosync.c