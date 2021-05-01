#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int i;
char name[20];

void inName()
{

printf("\nChild process no. %d\nPID=%d\nPlease enter a name:\n ", i, getpid());
scanf("%s",name);

}

void outName()
{

printf("\nChild process %d: %s\n", i, name);

}

int main(void)
{

for(i=1;i<5;i++)
{

pid_t pid = fork();

if(pid==0)
{

inName();
outName();
exit(0);

}

else
{

printf("\nProcessing.....\n");
wait(NULL);

}

}

printf("\nThe job is done\n");
return EXIT_SUCCESS;

}
