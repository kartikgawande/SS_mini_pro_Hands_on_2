/*
=====================================================================================================================================
Name : Progaram34_ac.c
Author : Kartik Satish Gawande
Roll No : MT2023045
Description :Write a program to create a concurrent server. a. use fork
Date: 21st Oct, 2023.
=====================================================================================================================================
*/

#include <sys/types.h>  
#include <sys/socket.h> 
#include <netinet/ip.h> 
#include <stdio.h>      
#include <unistd.h>    

void main()
{
    int socketFD; 
    int connectStatus;       

    struct sockaddr_in address; 

    ssize_t readBytes, writeBytes; 
    char message[100];

    
    socketFD = socket(AF_INET, SOCK_STREAM, 0);
    if (socketFileDescriptor == -1)
    {
        perror("Error while creating socket!");
        _exit(0);
    }
    printf("Client side socket successfully created!\n");

   
    address.sin_addr.s_addr = htonl(INADDR_ANY);
    address.sin_family = AF_INET;
    address.sin_port = htons(8080);

    connectStatus = connect(socketFD, (struct sockaddr *)&address, sizeof(address));
    if (connectStatus == -1)
    {
        perror("Error while connecting to server!");
        _exit(0);
    }
    printf("Client to serrver connection successfully established!\n");

   

    readBytes = read(socketFD, message, 100);
    
    if (readBytes == -1)
        perror("Error while reading from network via socket!");
    else
        printf("Data from server: %s\n", message);

    writeBytes = write(socketFD, "I'm the client!", 15);
    if (writeBytes == -1)
        perror("Error while writing to network via socket!");
    else
        printf("Data sent to server!");
    

    

    close(socketFileDescriptor);
}
