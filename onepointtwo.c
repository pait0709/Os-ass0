#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<unistd.h>
#include <sys/wait.h>
#include <time.h>
#include <math.h>
#include <sys/resource.h>

//double xx=pow(10,9);
void clocktimeret(struct timespec t1,struct timespec t2, char a){
    double totaltime=(((t2.tv_sec*pow(10,9))+t2.tv_nsec)-((t1.tv_nsec+t1.tv_sec*pow(10,9))))/pow(10,9);
    printf("Total tie taken by process %c:%lf\n",a,totaltime);
}


int main(void){
    struct timespec time1_start,time2_start,time3_start,time1_end,time2_end,time3_end;
    clock_gettime(CLOCK_REALTIME,&time1_start);
    pid_t process1=fork();
    if(process1==0){
        setpriority(0, PRIO_PROCESS, 35);
        execl("./bruh.sh","bruh.sh", NULL);
    }
    clock_gettime(CLOCK_REALTIME,&time2_start);
    
    pid_t process2=fork();
    if(process2==0){
    setpriority(0, PRIO_PROCESS, 25);
    execl("./bruh.sh","bruh.sh", NULL);
    }
    clock_gettime(CLOCK_REALTIME,&time3_start);

    pid_t process3=fork();
    if(process3==0){
    setpriority(0, PRIO_PROCESS, 5);
    execl("./bruh.sh","bruh.sh", NULL);
    }


    for(int i=0;i<3;i++){
    pid_t x=waitpid(-1,NULL,0);
    if(x==process1){
        clock_gettime(CLOCK_REALTIME,&time1_end);
        clocktimeret(time1_start,time1_end,'1');
        }
    if(x==process2){
        clock_gettime(CLOCK_REALTIME,&time2_end);
        clocktimeret(time2_start,time2_end,'2');
        }
    else if(x==process3){
        clock_gettime(CLOCK_REALTIME,&time3_end);
        clocktimeret(time3_start,time3_end,'3');
    }
    }
    return 0;
}
