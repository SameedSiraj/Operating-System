#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <stdlib.h>

sem_t e;
sem_t m;


sem_t full;
void * producer();
void * consumer();

 int main() 
 { 
   pthread_t thread_r, thread_w;        
  int result1, result2; 
   sem_init(&e , 0 , 3);    
   sem_init(&m,0,1);
   sem_init(&full,0,0);
   result1 = pthread_create(&thread_r,NULL,producer,NULL);   
   if (result1 == 0) 
   { 
     printf ("Thread 1 created successfully\n"); 
   }
   else 
   { 
     printf("Sorry.Thread 1 is not created!!\n");
     exit(EXIT_FAILURE); 
   } 
   result2 = pthread_create(&thread_w,NULL,consumer,NULL); 
   if (result2 == 0) 
   { 
     printf("Thread 2 created successfully\n\n"); 
   }
   else 
   { 
     printf("Sorry....Thread 2 is not created!!\n"); 
     exit(EXIT_FAILURE); 
   } 
     pthread_join (thread_r,NULL);  
     pthread_join (thread_w,NULL); 
     return 0; 
} 

void * producer( ) 
{ 
   printf("I am in Producer\n");
   for(int i=0;i<5;i++)
   {
  
   sem_wait(&e);
   sem_wait(&m);
   printf("Produce\n");
   sem_post(&m); 
   sem_post(&full);
   }
} 

void * consumer( ) 
{
   printf("I am in Consumer\n");
   for(int i=0;i<3;i++)
   {
   sem_wait(&full);
   sem_wait(&m);
   printf("Consume\n");
   sem_post(&m);
   sem_post(&e);
   }
}