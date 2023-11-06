#include<stdio.h>
int main(){
  int i,n,sum=0,count=0,at[10],bt[10],temp[10],wt=0,tat=0,quant,y;
  float avg_tat,avg_wt;
  printf("enter the number of processes to be entered\n");
  scanf("%d",&n);
  printf("enter the time quantam\n");
  scanf("%d",&quant);
  printf("Enter the process details: \n");
  for(i=0;i<n;i++){
    printf("Enter the arrival time for Process P%d :",i+1);
    scanf("%d",&at[i]);
    printf("Enter the burst time for Process P%d :",i+1);
    scanf("%d",&bt[i]);
    temp[i]=bt[i];
  }
  y=n;
  printf("\nProcess no\t\tBurst T\t\tTAT\t\twait time");
  for(sum = 0,i = 0 ; y != 0;){
    if(temp[i]<=quant && temp[i]>0){
      sum = sum +temp[i];
      temp[i]=0;
      count=1;
    }
    else if(temp[i]>0){
      temp[i]=temp[i]-quant;
      sum= sum + quant;
    }
    if(temp[i]==0 && count==1){
      y--;  
      printf("\nProcess %d \t\t%d\t\t%d\t\t%d ",i+1,bt[i],sum-at[i],sum-at[i]-bt[i]);
      wt=wt+sum-at[i]-bt[i];
      tat=tat+sum-at[i];
      count=0;
    }
    if(i==n-1)
      i=0;
    
    else if(at[i+1]<=sum)
      i++;
    else
      i=0;
  }
  avg_wt=wt*1.0 /n;
  avg_tat=tat*1.0 /n;
  printf("\naverage waiting time is :%f",avg_wt);
  printf("\naverage trt is :%f",avg_tat);
  
}
/*

at  bt
0   10
1   8
2   7
*/
