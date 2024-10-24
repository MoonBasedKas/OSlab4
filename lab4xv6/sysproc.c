#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"

int
sys_fork(void)
{
  return fork();
}
// --- system call definitions of our functions
int sys_thread_create(){
  void (*fn)(void *);
  void *stack;
  void *args;
  argint(0, &fn);
  argint(1, &stack);
  argint(2, &args);

  return thread_create(fn, stack, args);
}

int sys_thread_join(){

  return thread_join();
}

int sys_thread_exit(){

  return thread_exit();
}

int sys_lock_init(){
  lock_t *lock;
  argint(0, &lock);
  return lock_init(lock);
}

int sys_lock_aquire(){
  lock_t *lock;
  argint(0, &lock);
  return lock_aquire(lock);
}

int sys_release(){
  lock_t *lock;
  argint(0, &lock);
  return lock_release(lock);
}
// --- end

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}
