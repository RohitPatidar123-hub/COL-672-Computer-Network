#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<pthread.h>
#include<errno.h>
#include<sys/types.h>
int fuel=0;
pthread_mutex_t mutexFuel;
pthread_cond_t  condFuel;  //is identifier work in two way wait and signal
void *fuel_filling(void *arg)
{  
     for(int i=0;i<5;i++)
       {
          pthread_mutex_lock(&mutexFuel);
          fuel=fuel+15;
          printf("Filled fuel...%d\n",fuel);
          pthread_mutex_unlock(&mutexFuel);
          pthread_cond_signal(&condFuel);   //signal message to only one thread

          
       }
       
   return NULL;
};
void* car(void *arg)
{
          pthread_mutex_lock(&mutexFuel);
          while(fuel<40)
            { 
                printf("No fuel.Waiting...\n");
                pthread_cond_wait(&condFuel,&mutexFuel);  
                //equivalent to unlock mutex
                //wait for signal
                //lock mutex
            }
            fuel-=40;
        printf("Got fuel.Now left :%d\n",fuel);
        pthread_mutex_unlock(&mutexFuel);

    return NULL;
};

int main()
{
      pthread_t th[2];
      pthread_mutex_init(&mutexFuel,NULL);
        pthread_cond_init(&condFuel,NULL);
      for(int i=0;i<2;i++)
         {
            if(i==1)
                 {
                    if(pthread_create(&th[i],NULL,&fuel_filling,NULL)!=0)
                         {
                            perror("Failed to create thread\n");
                         }
                 }
            else {
                    if(pthread_create(&th[i],NULL,&car,NULL)!=0)
                         {
                            perror("Failed to create thread\n");
                         }
                     
                 }     
         }
       for(int i=0;i<2;i++)
         {
              if(pthread_join(th[i],NULL)!=0)
                 {
                    perror("Failed to join thread\n");
                 }
         }  
         pthread_mutex_destroy(&mutexFuel);
         pthread_cond_destroy(&condFuel);
         return 0;

};