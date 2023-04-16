#include<stdio.h>
#include<conio.h>

int main()

{
	int p;
	int cl_r[3][2];
	int al_r[3][2];
	int cl_al_r[3][2];
	int r[2]={5,3};
	int av_r[2]={3,2};
	
	printf("Enter the no of Processes : ");
	scanf("%d",&p);
	
	printf("\nEnter the Resources Claim by the Processes\n");
	printf("        A     B\n");
	for(int i=0;i<3;i++)
	{
		printf("p[%d]    ",i);
		for(int j=0;j<2;j++)
		{   
		    scanf("%d",&cl_r[i][j]);
		}
	}
	
               printf("\nEnter the Resources Allocated to the Processes\n");
	printf("        A     B\n");
	for(int i=0;i<3;i++)
	{
		printf("p[%d]    ",i);
		for(int j=0;j<2;j++)
		{   
		    scanf("%d",&cl_r[i][j]);
		}
	}
	
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<2;j++)
		{   
		   cl_al_r[i][j]=cl_r[i][j]-al_r[i][j];   
		}
	}
    
    for(int i=0;i<3;i++)	
    {
       int count=0;
       for(int j=0;j<2;j++)	
    	{
    	   if(cl_al_r[i][j]>av_r[j])
    	   {
    	   	  count++;
		   }
		   else
		   {
		   	 break;
		   }
		}
		if(count==0)
		{
			printf("\nSafe State");
			break;
		}
	}
}