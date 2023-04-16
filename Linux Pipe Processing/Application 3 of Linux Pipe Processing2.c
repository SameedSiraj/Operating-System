int main()
{

  int pid, pip[2];
  char instring[50];
  pipe(pip);
  pid = fork();

  if (pid == 0) 
  {
     close(pip[1]);
     read(pip[0], instring, 25);
     strcat(instring,". Your Roll No is 17B-127-SE.");
     printf("%s",instring); 
  }

  else
  {
    printf("Enter Your Name : ");
    scanf("%s",instring);
    close(pip[0]);
    write(pip[1], instring,25);
  }
}  