#include<stdio.h>

struct process
{
	int at,bt,ct,rem_bt,wt,tat;
};

int t=0,total_tat,total_wt;
main()
{
  int n,quantum;
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
  printf("\nEnter process Quantum Time:");
  scanf("%d",&quantum);
  for(int i=0;i<n;i++)
  {
	p[i].rem_bt=p[i].bt;
  }
  int b=n-1;
  while(b!=-1)
  {
	for(int i=0; i<n;i++)
	{
	    if(p[i].rem_bt>quantum && p[i].rem_bt!=0)
		{ 
		    t=t+quantum;
			p[i].rem_bt-=quantum;
		}
		else 
		{
			if(p[i].rem_bt==0)
			{}
        else
        {
			t=t+p[i].rem_bt;
			p[i].ct=t;
			p[i].rem_bt= 0;
			b--;	
        }
		}
    }
  }
  
  for(int i=0;i<n;i++)
  {
    p[i].tat=p[i].ct-p[i].at;
    p[i].wt=p[i].tat-p[i].bt;
    total_tat+=p[i].tat;
    total_wt+=p[i].wt;
  }
  printf("%d   %d",total_tat,total_wt);
  printf("\nProcess \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time");
  for(int i=0;i<n;i++)
  { printf("\np%d           \t%d              \t%d         \t\t%d  \t\t%d",i+1,p[i].bt,p[i].ct,p[i].wt,p[i].tat); }
  
  float avg_tat=(float)total_tat/n; //average turnaround time
  float avg_wt=(float)total_wt/n;
  printf("\n\nAverage Waiting Time=%f",avg_wt);
  printf("\nAverage Turnaround Time=%f\n",avg_tat);
  return 0;
  	
}