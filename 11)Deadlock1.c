#include<stdio.h>
#include<stdbool.h>
int main(){
  int n,m;
  
  printf("enter the number of processes: \n");
  scanf("%d",&n);
  printf("enter the number of resources: \n");
  scanf("%d",&m);
  
  int alloc[n][m];
  int max[n][m];
  int avail[m];
  
  printf("Enter the allocation matrix");
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&alloc[i][j]);
    }
  }
  
  printf("Enter the maximum matrix");
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      scanf("%d",&max[i][j]);
    }
  }
  
  printf("Enter the available resources");
  for(int i=0;i<m;i++){
    scanf("%d",&avail[i]);
  }
  
 int need[n][m];
  for (int i=0;i<n;i++){
    for(int j=0;j<m;j++){
      need[i][j]=max[i][j]-alloc[i][j];
    }
  }
  
  int f[n],ind=0,ans[n];
  for(int k=0;k<n;k++){
    f[k]=0;
  }
  
  int y=0;
  for(int k=0;k<n;k++){
    for(int i=0;i<n;i++){
      if(f[i]==0){
        int flag=0;
        for(int j=0;j<m;j++){
          if(need[i][j]>avail[j])
            flag = 1;
            break; 
        }
        if(flag==0){
          ans[ind++]=i;
          for(int y=0;y<n;y++){
            avail[y]+=alloc[i][y];
          }
          f[i]=1;
        }
      }
    }
  }
  int flag =1;
  
  for(int i=0;i<n;i++){
    if(f[i]==0){
      flag=0;
      printf("the sequence is not safe\n");
      break;
    }
  }
  if(flag == 1){
   printf("the foll sequence is safe sequence \n");
   for(int i=0;i<n-1;i++){
      printf("P%d-->",ans[i]);
   }
   printf("P%d\n",ans[n-1]);
  }
  return 0;
}

/* 
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2

7 5 3 
3 2 2
9 0 2
4 2 2 
5 3 3

3 3 2
*/
