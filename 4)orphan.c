#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>

void bubble_sort(int arr[],int n){
  for(int i=0;i<n-1;i++)
    for(int j=0;j<n-i-1;j++)
      if(arr[j]>arr[j+1]){
        int temp = arr[j];
        arr[j]= arr[j+1];
        arr[j+1] = temp;
      }
  printf("sorted array is :\n");
  for (int i=0;i<n;i++){
  printf(" %d" ,arr[i]);
  }
  printf("\n");
}

int main(){
  pid_t pid;
  int n;
  printf("enter the no of elements to be sorted");
  scanf("%d",&n);
  int arr[n];
  printf("enter the array to be sorted");
  for(int i=0;i<n;i++)
    scanf("%d",&arr[i]);
  pid = fork();
  if(pid == 0){
    wait(NULL);
    printf("\n**************CHILD PROCESS**************\n");
    printf("\nIt is a child process with pid = %d and ppid = %d \n",getpid(),getppid());
    bubble_sort(arr,n);
    printf("\n child process terminated\n");
  }
  else{
    printf("\n**************PARENT PROCESS**************\n");
    printf("\nIt is a parent process with pid = %d and ppid = %d \n",getpid(),getppid());
    bubble_sort(arr,n);
    printf("\n parent process terminated\n");
  }
}
