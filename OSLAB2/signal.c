/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//Keerthana Pullela
//Worked with Khalil Scott-Shepherd and Jamarri White, asked Nia Anderson from 2021 class for help
//Coded in repl.it

int alarmOn = 0;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmOn = 1;
}


int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  alarm(2);
  while(1){
    alarmOn = 0;
    alarm(2);
    while(!alarmOn);
      printf("Turing was right!\n");
    
  }
  return 0;
}