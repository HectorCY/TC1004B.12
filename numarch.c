#include <stdio.h>
#include <unistd.h>

int main(){
    int fd[2];
    pipe(fd);
    int pid = fork();

    if(pid == 0){
        //close(0);
        dup(1, fd[0]);
        execlp("wc", "wc", "-1", NULL);
    }
    else{
        //close(1);
        dup(0, fd[1]);
        execlp("ls", "ls", NULL);
    }

    return 0;
}