#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <time.h>
#include <stdlib.h>
const int MSG_LENGTH=80;
int main() 
{
    srand(time(NULL));
    pid_t child_pid, my_pid, parent_pid;
    child_pid = fork();
    parent_pid = getppid();
    my_pid = getpid();
    int status=0;
if(child_pid!=0 && child_pid>0){
    printf("Parent start waiting for child to end execution.\n");
    waitpid(child_pid,&status,0);
    int a=0;
    while(a<4){
        sleep(1);
        printf("I wait for child to end its execution.\n");
        //printf("Status:%d\n",status);
        a++;
        if(WIFEXITED(status)){
            int es=WEXITSTATUS(status);
            printf("Exit status: %d\n",es);
            exit(0);
        }
    }
}
else if(child_pid==0){
            printf("Child start execution.\n");
            sleep(3); //zombie process for 3 second starts
            printf("Child end execution.\n");
            int r=rand()%240+1;//random exit status is determined
            printf("Child exit code:%d\n",r);
            exit(r);
        }
}