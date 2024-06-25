#include <stdio.h>
#include <stdlib.h>


int main() {
 int n;
  int num = 0;
  while (1)
    {
  scanf("%d" , &n);
  int *start_h = (int *) malloc (n * sizeof(int));
  int *start_m =(int *) malloc (n * sizeof(int));
  int *finish_h =(int *) malloc (n * sizeof(int));
  int *finish_m =(int *) malloc (n * sizeof(int));
  int nap_time;
  int nap_start_h;
  int nap_start_m;
  int long_naptime =0;
  char schedule_name[300];
      if(n == -1)
        break;
       for(int i=0; i<=n -1 ; i++) 
      {
        scanf("%d:%d %d:%d %[^\n]s" ,&start_h[i] ,&start_m[i] , &finish_h[i], &finish_m [i] ,schedule_name);
      }
        //%[^\n]s 공백포함 문자 
      for(int i=0; i<n; i++){
      
        nap_time = (start_h[i+1] *60 + start_m[i+1]) -   
           (finish_h[i] * 60 + finish_m[i] );
        
        if(nap_time > long_naptime)
        {
          long_naptime = nap_time;
          nap_start_h = finish_h[i];
          nap_start_m = finish_m[i];
        }
      if(start_h[0] != 10 && start_m[0] != 0)   
      {
    nap_time = (start_h[0] - 10) * 60 + start_m[0]; 
    if(nap_time > long_naptime)
    {
        long_naptime = nap_time;
        nap_start_h = 10;
        nap_start_m = 0;
    }
}
        
if(finish_h[n-1] != 18)  
{
    nap_time = (18 - finish_h[n-1]) * 60 - finish_m[n-1]; 
    if(nap_time > long_naptime)
    {
        long_naptime = nap_time;
        nap_start_h = finish_h[n-1];
        nap_start_m = finish_m[n-1];
    }
}
      }
      

       printf("Day #%d: the longest nap starts at %02d:%02d and will last for ",++num , nap_start_h ,nap_start_m);
      if(long_naptime >59)
      {
      int long_nap_h = long_naptime / 60;
      int long_nap_m = long_naptime % 60;
        printf("%d hours and %d minutes.\n" , long_nap_h , long_nap_m);
      }
      else
      {
        printf("%d minutes.\n" ,long_naptime);
      }
        
        
      }
    return 0;
      
       
        
        
      
    }