/*
=====================================================================================================================================
Name : Progaram15.c
Author : Kartik Satish Gawande
Roll No : MT2023045
Description : Write a simple program to send some data from parent to the child process.
Date: 21st Oct, 2023.
=====================================================================================================================================
*/	
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<errno.h>
#include<string.h>


int main(){

	int fd[2];

	pid_t pid;

	char msg[100] = "Hello child, How are you?";

	if(pipe(fd) == -1){

		perror("Pipe");
		return 1;
	}

	pid = fork();

	if(pid == -1){

		perror("Fork");
		return 1;
	}

	if(pid > 0){

		close(fd[0]);

		ssize_t bytwr = write(fd[1], msg, strlen(msg));

		if(bytwr == -1){

			perror("Write");
			return 1;
		}

		close(fd[1]);
	}
	else{

		close(fd[1]);

		char buff[100];

		ssize_t bytrd = read(fd[0], buff, sizeof(buff));

		if(bytrd == -1){

			perror("Read");
			return 1;
		}

		buff[bytrd] = '\0';

		printf("Child received this message from parent : %s \n", buff);

		close(fd[0]);

	}

	
	return 0;

}
