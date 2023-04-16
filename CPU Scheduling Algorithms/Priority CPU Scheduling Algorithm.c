#include<stdio.h>

struct process
{
	int at,bt,ct,pr,tat,wt;
};

int total_tat,total_wt;
main()
{
  int n;
  printf("Enter number of process:");
  scanf("%d",&n);
  process p[n];
  printf("\nEnter Burst Time:\n");
  for(int i=0;i<n;i++)
  { 
   printf("p[%d]:",i+1);
   scanf("%d",&p[i].bt);
  }
  printf("\nEnter process Arival Time\n"); 
  for(int i=0;i<n;i++)
  {
    printf("P[%d]: ",i+1);
    scanf("%d",&p[i].at);
  }
    printf("\nEnter process Priority\n"); 
  for(int i=0;i<n;i++)
  {
    printf("P[%d]: ",i+1);
    scanf("%d",&p[i].pr);
  }
	
	//sorting priority in ascending order using selection sort
	process temp;
	for(int i=1;i<n;i++) {
    int pos=i;
    for(int j=i+1;j<n;j++)
    {
    if(p[j].pr>p[pos].pr) pos=j;
    }
    temp=p[i];          // swapping 
    p[i]=p[pos];       
    p[pos]=temp;
    }     // The output sort in descending order

    process p2[n];     // initialization just for swapping
	for(int i=0;i<n;i++)
	{
	   p2[i]=p[i];
	}
	int j=0;
    for(int i=3;i>=0;i--)
	{
	   p[i]=p2[j];
	   j++;
	}   // The output sort in ascending order
	for(int i=0;i<n;i++)
    {   p[i].ct=0;   
        for(j=0;j<=i;j++)
        {
        p[i].ct=p[j].bt+p[i].ct;
        }
    }
    for(int i=0;i<n;i++)
    {
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    total_tat+=p[i].tat;
    total_wt+=p[i].wt;
    }
    printf("\nProcess Burst Time Priority Completion Time Waiting Time Turnaround Time");
    for(int i=0;i<n;i++)
    { printf("\np%d       %d             %d            %d        \t%d           \t%d",i+1,p[i].bt,p[i].pr,p[i].ct,p[i].wt,p[i].tat); }
  
    float avg_tat=(float)total_tat/n; //average turnaround time
    float avg_wt=(float)total_wt/n;
    printf("\n\nAverage Waiting Time=%f",avg_wt);
    printf("\nAverage Turnaround Time=%f\n",avg_tat);
    return 0;
}