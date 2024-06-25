#include <stdio.h>


struct job
{  
  int job_num;
  int day;
  int penalty;
  int penalty_density;
};
int main() 
{
  int n;
  scanf("%d" , &n);
  struct job jobs[n];
  for(int i = 0; i<n; i++)
    {
      scanf("%d %d" , &jobs[i].day , &jobs[i].penalty);
      jobs[i].job_num = i+1;
      jobs[i].penalty_density = jobs[i].penalty/jobs[i].day ;
    }
  for(int i = 0; i<n-1; i++)
    {
      for(int j =0; j<n-1-i; j++)
        {
          if(jobs[j].penalty_density < jobs[j+1].penalty_density)
          {
             struct job temp = jobs[j+1];
            jobs[j+1] = jobs[j];
            jobs[j] = temp;
          }
        }
    }
  for(int i = 0; i<n; i++)
    {
        printf("%d " , jobs[i].job_num);
    }


  



  
}
