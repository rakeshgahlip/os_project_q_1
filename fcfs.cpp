#include<stdio.h>
int main()
{
    int artm[20],n,butm[20],wtm[20],tatm[20],avwt=0,avtat=0,i,j;
    printf("Enter the total number of processes->maximum 15:");
    scanf("%d",&n);
    printf("Enter the Arrival Time->");
    for(i=0;i<=n-1;i++)
    {
    	printf("P[%d]:",i+1);
        scanf("%d",&artm[i]);
	}
    printf("\nEnter Process Burst Time\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&butm[i]);
    }
 
    wtm[0]=0;    //waiting time for first process is 0
 
    //calculating waiting time
    for(i=1;i<n;i++)
    {
        wtm[i]=0;
        for(j=0;j<i;j++)
            wtm[i]+=butm[j];
    }
    printf("\nProcess\t\tArrival time\t\tBurst Time\t\tWaiting Time\t\tTurnaround Time"); 
    //calculating turnaround time
    for(i=0;i<n;i++)
    {
        tatm[i]=butm[i]+wtm[i];
        avwt+=wtm[i];
        avtat+=tatm[i];
        printf("\nP[%d]\t\t\t%d\t\t\t%d\t\t\t%d\t\t\t%d",i+1,artm[i],butm[i],wtm[i],tatm[i]);
    }
 
    avwt/=i;
    avtat/=i;
    printf("\n\nAverage Waiting Time:%d",avwt);
    printf("\nAverage Turnaround Time:%d",avtat);
 
    return 0;
}
