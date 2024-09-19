#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include<pthread.h>
void * routine (void *)
    {
        static int i=0;
        printf("Test for threads %d\n",i);
        i=i+1;
        sleep(3);
        printf("End Threds %d\n",i);
        i=i+1;
        return NULL;
    };
     
     int main()
     {
           pthread_t t1,t2;
           if(pthread_create(&t1,NULL,&routine,NULL)!=0) return 1;
           pthread_create(&t1,NULL,&routine,NULL);
           pthread_join(t1,NULL);
           pthread_join(t2,NULL);
           return 0;
     };