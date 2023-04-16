#include <stdio.h> 
#include <pthread.h> 
#include <semaphore.h>
#include <stdlib.h>

char msg[1000];
sem_t semaphore;
void * read_message();
void * write_message();

int main() 
{ 
  pthread_t thread_r, thread_w;
  int result1, result2; 
  sem_init(&semaphore , 0 , 0);    

  result1 = pthread_create(&thread_r,NULL,read_message,NULL);   
  if (result1 == 0) 
  { 
    printf ("\nThread 1 created successfully");                            
  }      
  else                                                                         
  { 
    printf("SorryThread 1 is not created!!\n");   
    exit(EXIT_FAILURE);                        
  }              
                                                               
  result2 = pthread_create(&thread_w,NULL,write_message,NULL);                    if (result2 == 0)                          
  {                                                                         
     printf("\nThread 2 created successfull"); 
  }
  else 
  { 
     printf("SorryThread 2 is not created!!\n"); 
     exit(EXIT_FAILURE); 
  } 
  pthread_join (thread_r,NULL);
  pthread_join (thread_w,NULL); 
 
 return 0; 
} 

void * write_message()
{
  printf("\n\nI am on a write");
  sem_wait(&semaphore);
  printf("\nMessage : ");
  printf("%s",msg);
}

void * read_message()
{   
  printf("\n\nEnter a message: ");  
  scanf("%s",msg);
  sem_post(&semaphore);
}