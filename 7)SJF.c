#include<stdio.h>
int arrival_t[100],burst_t[100],ct[100],temp[100];

int main(){
  int i,smallest,j,n,count =0;
  double avg_trt =0, avg_wt = 0;
  printf("enter the no of processes \n");
  scanf("%d",&n);
  
  printf("enter the details if %d processes:\n",n);
  for(i=0;i<n;i++){
    printf("enter the arrival time for P%d process :",i+1);
    scanf("%d",&arrival_t[i]);
    printf("enter the burst time for P%d process :",i+1);
    scanf("%d",&burst_t[i]);
    temp[i]=burst_t[i];
  }
  burst_t[99]=1000;
  for(int i=0;count!=n;i++){
    smallest=99;
    for(int j=0;j<n;j++){
      if(arrival_t[j]<=i && burst_t[j]<burst_t[smallest] && burst_t[j]>0){
        smallest = j;
      }
    }
    burst_t[smallest]--;
    if(burst_t[smallest]==0){
      count ++;
      ct[smallest]=i+1;
    }
  }
  printf("\nP\tAT\tBT\tTAT\tWT");
  
  for(int i=0;i<n;i++){
    int TAT = ct[i] - arrival_t[i];
    int wt =TAT - temp[i];
    avg_trt+=TAT;
    avg_wt+= wt;
    printf("\nP%d\t%d\t%d\t%d\t%d",i+1,arrival_t[i],temp[i],TAT,wt);
  }
  printf("\nthe average turn around time is %lf\n",avg_trt/n);
  printf("the average wait time is %lf\n",avg_wt/n);
}

/* 
at  bt
0   5
1   3
2   4
4   1
*/
