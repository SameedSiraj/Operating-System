#include<stdio.h>
int main()
{
int n,bt[20],wt[20],av[20],tat[20],ct[20],avwt=0,avtat=0,i,j;
printf("Enter total number of processes(maximum 20):");
scanf("%d",&n);

printf("\nEnter Process Burst Time\n");
for(i=0;i<n;i++)
{ printf("P[%d]:",i+1); scanf("%d",&bt[i]);
}

printf("Enter process Arival Time\n");
{
        for(i=0;i<n;i++)
        {  printf("P[%d]: ",i+1);
           scanf("%d",&av[i]);
}}

for(i=0;i<n;i++)
{       
        for(j=0;j<=i;j++)
        {
        ct[i]=bt[j]+ct[i];
        }
}

for(int i=0;i<n;i++)
{
tat[i]=ct[i]-av[i];
wt[i]=tat[i]-bt[i];
avtat+=tat[i];
avwt+=wt[i];
}

for(int i=0;i<n;i++)
{}


for(int i=0;i<n;i++)
{}
for(int i=0;i<n;i++)
{}

printf("\nProcess \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time");
for(i=0;i<n;i++)
{ printf("\np%d           \t%d              \t%d         \t\t%d  \t\t%d",i+1,bt[i],ct[i],wt[i],tat[i]); }

avwt/=n;
avtat/=n;
printf("\n\nAverage Waiting Time:%d",avwt);
printf("\nAverage Turnaround Time:%d",avtat);
return 0;
}