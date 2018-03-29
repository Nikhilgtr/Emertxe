#ifndef MSH_H
#define MSH_H
#define FOREGROUND 'F'
#define BACKGROUND 'B'
#define SUSPENDED 'S'
#define WAITING_INPUT 'W'

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>
#include<readline/readline.h>
#include<readline/history.h>


#define RED   "\033[1;31m"        /* 0 -> normal ;  31 -> RED */
#define CYAN  "\033[1;36m"        /* 1 -> bold ;  36 -> CYAN */
#define GREEN "\033[1;32m"        /* 4 -> underline ;  32 -> GREEN */
#define NONE   "\033[0m"        /* to flush the previous property */
#define BLUE    "\033[1;34m"

#define SIZE 512






#endif
