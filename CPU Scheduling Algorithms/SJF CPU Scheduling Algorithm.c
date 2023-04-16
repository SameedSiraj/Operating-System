#include<stdio.h>
int main() {
int bt[20],p[20],av[20],ct[20],wt[20],tat[20],i,j,n,total_tat,total_wt=0,pos,temp; float avg_wt,avg_tat;

printf("Enter number of process:");
scanf("%d",&n);
printf("\nEnter Burst Time:\n");

for(i=0;i<n;i++)

{ printf("p%d:",i+1);
scanf("%d",&bt[i]); p[i]=i+1; //contains process number
}

printf("\nEnter process Arival Time\n");
{ 
        for(i=0;i<n;i++)
        {printf("P[%d]: ",i+1);
        scanf("%d",&av[i]);
}}

ct[0]=bt[0];
//sorting burst time in ascending order using selection sort
for(i=1;i<n;i++) {
pos=i;
for(j=i+1;j<n;j++)
{
if(bt[j]<bt[pos]) pos=j;
}
temp=bt[i];          // swapping of burst time
bt[i]=bt[pos];       
bt[pos]=temp;
temp=p[i];           // swapping of process position
p[i]=p[pos];         
p[pos]=temp;
temp=av[i];           // swapping of arrival time
av[i]=av[pos];         
av[pos]=temp;
}


for(i=1;i<n;i++)
{
        for(j=i;j<=i;j++)
        {
        ct[i]=bt[j]+ct[i-1];
        }
}


for(i=0;i<n;i++)
{
   tat[i]=ct[i]-av[i];
   wt[i]=tat[i]-bt[i];
   total_tat+=tat[i];
   total_wt+=wt[i];
}

printf("\nProcess \tBurst Time \tCompletion Time \tWaiting Time \tTurnaround Time");
for(i=0;i<n;i++)
{ printf("\np%d           \t%d              \t%d         \t\t%d  \t\t%d",i+1,bt[i],ct[i],wt[i],tat[i]); }

avg_tat=(float)total_tat/n; //average turnaround time
avg_wt=(float)total_wt/n;
printf("\n\nAverage Waiting Time=%f",avg_wt);
printf("\nAverage Turnaround Time=%f\n",avg_tat);
return 0;
}