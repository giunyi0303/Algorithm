#include <stdio.h>
#include <stdlib.h>
#define list 2

struct Jewel_Box
{
    int value;
    int weight;
    double value_density;
    int count;
};

int min(int a, int b)
{
  return (a < b) ? a : b;
}

int main() 
{
    int weight;
    struct Jewel_Box arr[list];
    
    scanf("%d" , &weight);
    for(int i = 0 ; i < list; i++)
    {
        scanf("%d %d" , &arr[i].value ,&arr[i].weight);
        arr[i].value_density = (double) arr[i].value / arr[i].weight;
        arr[i].count = 0;
    }

    int m[weight+1];
    int used[weight+1];
    for(int i = 0; i <= weight; i++)
    {
        m[i] = 100000;
        used[i] = -1;  
    }
    
    m[0] = 0;
    
    for(int i = 0; i < list; i++)
    {
        for(int j = arr[i].weight; j <= weight; j++)
        {
            if(m[j] > arr[i].value + m[j-arr[i].weight])
            {
                m[j] = arr[i].value + m[j-arr[i].weight];
                used[j] = i;  
            }
        }
    }

    for(int i = 0; i<=weight; i++)
      {
        printf("%d  " , m[i]);
      }
  
    if(m[weight] == 100000)
    {
        printf("failed");
        exit(-1);
    }
    else
    {
        int w = weight;
        while(w != 0)
        {     
            arr[used[w]].count++;  
            w = w - arr[used[w]].weight;
        }
        
        for(int i = 0; i < list; i++)
        {
            printf("%d " , arr[i].count);
        }
 
        /*printf("가격 = %d\n" , m[weight]);
    */}

    return 0;
}
