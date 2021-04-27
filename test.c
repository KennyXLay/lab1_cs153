#include "types.h"
#include "stat.h"
#include "user.h"



int main(int argc, char *argv[]) {
	int waitpid(void);

	waitpid();

	exitS(0);
	return 0;
}


int waitpid(void){

	int ret_pid, exit_status;
	int pid_a[3] = {0, 0, 0};
	int i = 0;

	printf(1, "Testing waitpid\n");
	
	for(i = 0; i < 3; i++){
		pid_a[i] = fork();
		if(pid_a[i] == 0){
			printf(1, "\n This is child with PID# %d and I will exit with status %d\n", getpid(), getpid() + 2);
		exitS(getpid() + 2);
		}
	}
	sleep(3);
	printf(1, "\n This is the parent: Waiting for child with PID# %d\n",pid_a[1]);
        ret_pid = waitPID(pid_a[1], &exit_status, 0);
        printf(1, "\n Child# %d exited with status %d\n",ret_pid, exit_status);
        sleep(3);
        printf(1, "\n This is the parent: Waiting for child with PID# %d\n",pid_a[2]);
        ret_pid = waitPID(pid_a[2], &exit_status, 0);
        printf(1, "\n Child# %d exited with status %d\n",ret_pid, exit_status);
        sleep(3);
        printf(1, "\n This is the parent: Waiting for child with PID# %d\n",pid_a[0]);
        ret_pid = waitPID(pid_a[0], &exit_status, 0);
        printf(1, "\n Child# %d exited with status %d\n",ret_pid, exit_status);	

	return 0;
}
	

