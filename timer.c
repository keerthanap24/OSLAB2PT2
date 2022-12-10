#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
//<Author: Keerthana Pullela>
//Worked with Khalil Scott-Shepherd, asked Nia Anderson from 2021 class for help
//Coded in repl.it
int alarmOn = 0;
int numAlarm = 0;

time_t start, stop;

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  sleep(2);
  alarmOn = 1;
  numAlarm++;

}

void sigHandler(int signum){
  int timeTotal;
  stop = time(NULL);
  timeTotal = stop - start;
  
  printf("The number of alarms is %d\n", timeTotal);
}

int main(int argc, char * argv[])
{
  signal(SIGALRM, handler); //register handler to handle SIGALRM
  signal(SIGINT, sigHandler);
  start = time(NULL);
  while(1){
    alarmOn = 0;
    alarm(2);
    while(!alarmOn);
      printf("Turing was right!\n");
  }
  return 0;
}