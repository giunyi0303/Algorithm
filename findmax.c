#include <stdio.h>
#define ARRAY_SIZE 30

int n;
int arr[ARRAY_SIZE];

void flip(int x)
{
  for(int i =0; i<x / 2; i++)
    {
      int temp = arr[i];
      arr[i] = arr[x-i -1];
      arr[x-i - 1] = temp;
    }
}

int find_max(int x)
{
  int max_index = 0;
  for(int i =1; i<=x; i++)
    {
      if(arr[i]>arr[max_index]){
        max_index = i;
      }
    }
    return max_index;
}

int main()
{
  int input;
  while(scanf("%d" , &input) == 1 && input !=-1)
    {
  n = 0;
  arr[n++] = input;
  while(getchar()!= '\n' && scanf("%d" , &input)==1)
    arr[n++] = input;

  for(int i = 0; i<n ; i++)
    {
      printf("%d " , arr[i]);
    }
  printf("\n");
  for(int i = n - 1; i>=0; i--)
    {
      int max = find_max(i);
      if(max == i)
      continue;
      
      if(max != 0){
        flip(max +1);
        printf("%d ", n- max );
      }
        flip(i +1);
      printf("%d ", n - i );
      }
  printf("0\n");
    }
  return 0;
    }

