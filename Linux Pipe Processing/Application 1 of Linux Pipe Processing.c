#include <unistd.h> 
#include<stdio.h>
#include<string.h>
 
int main() 
{ 
  int pid, pip[2]; 
  char instring[20]; 
  pipe(pip);  
  pid = fork(); 

  if (pid == 0)  /* child : sends message to parent*/ 
  { 
     close(pip[0]); 
     /* send 7 characters in the string, including end-of-string */ 
     write(pip[1], "Hi Parent!", 11);   
   } 
   else 	 	 	 
     /* parent : receives message from child */ 
   { 
     close(pip[1]); 
     /* read from the pipe */ 
     read(pip[0], instring,11); 
     printf("%s",instring);
   } 
}