#include<stdio.h>
struct process
{
int bt,wt,av,tat,ct;
};

int main()
{
int n=4,avwt=0,avtat=0,i,j,roll_no;
printf("Enter Your Roll No : ");
scanf("%d",&roll_no);
int roll_no_copy=roll_no;
process p[n];

for(i=0;i<n;i++)
{ p[i].bt=roll_no+(roll_no_copy*(i+1));
  roll_no++;
}

printf("\nEnter process Arival Time\n");
{
        for(i=0;i<n;i++)
        {  printf("P[%d]: ",i+1);
           scanf("%d",&p[i].av);
        }
}

p[0].ct=0;    // just for initialization
p[2].ct=0;
for(i=0;i<n;i++)
{       
        for(j=0;j<=i;j++)
        {
        p[i].ct=p[j].bt+p[i].ct;
        }
}

for(int i=0;i<n;i++)
{
p[i].tat=p[i].ct-p[i].av;
}

for(int i=0;i<n;i++)
{
	p[i].wt=p[i].tat-p[i].bt;
}

for(int i=0;i<n;i++)
{
	avtat+=p[i].tat;
}
for(int i=0;i<n;i++)
{
	avwt+=p[i].wt;
}

printf("\nProcess \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time");
for(i=0;i<n;i++)
{ printf("\np%d           \t%d              \t%d         \t%d          \t%d",i+1,p[i].bt,p[i].ct,p[i].wt,p[i].tat); }

avwt/=n;
avtat/=n;
printf("\n\nAverage Waiting Time:%d",avwt);
printf("\nAverage Turnaround Time:%d",avtat);
return 0;
}