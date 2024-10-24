/*
   Problem :
            Every thread rolls a dice , saved its value in an array 
            the main thread calculate the winner then 
            each thread prints a message with whether or not they lost or won 

*/
#include< pthread.h>
#include< stdio.h>
#include< stdib.h>
#include<unistd.h >
#include<string.h >
#include<time.h >
#define THREAD_NUM 8;

int diceValues[8];
int status[8]={0};
void *rollDice(void *args)
{
       int index =();
}