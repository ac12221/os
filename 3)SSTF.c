#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int main(){
  int n,head,avgseek,seektime=0;
  printf("Enter the number of disks requests: \n");
  scanf("%d",&n);
  int sequence[n];
  printf("Enter the disk sequence \n");
  for(int i=0;i<n;i++){
    scanf("%d",&sequence[i]);
  }
  printf("enter the position of head");
  scanf("%d",&head);
  
  int visited[n];
  for(int i =0;i<n;i++){
    visited[i]=0;
  }
  printf("the disk sequence is given as :\n");
  for(int i=0;i<n;i++){
    int min_distance= INT_MAX;
    int index = -1;
    for(int j=0;j<n;j++){
      if(!visited[j]){
        int distance = abs(sequence[j]-head);
        if(distance<min_distance){
          min_distance = distance;
          index = j;
        }
      }
    }
    visited[index]=1;
    seektime += min_distance;
    avgseek = seektime/(i+1);
    head = sequence[index];
    printf("> %d ",sequence[index]);
  }
  printf("\n seektime is %d :\n",seektime);
  printf("average seektime is z: %d \n",avgseek);
  
  return 0;
}

/* 
n = 7
82 170 43 140 24 16 190
head psn 50
*/
