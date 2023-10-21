/*
=====================================================================================================================================
Name : Progaram19_b.c
Author : Kartik Satish Gawande
Roll No : MT2023045
Description : Create a FIFO file by b.mkfifo
Date: 21st Oct, 2023.
=====================================================================================================================================
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {

    const char *filename = "myfifo2";

    // Create the FIFO with read and write permissions
    if (mkfifo(filename, 0666) == -1) {

        perror("mkfifo");
        exit(EXIT_FAILURE);
    }

    printf("FIFO file '%s' created successfully.\n", filename);

    return 0;
}

