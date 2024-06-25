#include <stdio.h>
#include <string.h>

char X[10000]; 
char Z[10000];

int main()
{

int num;
  scanf("%d" , &num);
  for(int i =0; i<num; i++)
    {
     
      scanf("%s" , X);
      scanf("%s" , Z);
    int n = strlen(X) +1; // 실제 크기만큼 해야함 
    int m = strlen(Z) +1;
  
int matrix[m][n];

for(int i =1; i<m; i++)
  {
    matrix[i][0] = 0;
  }
for(int j =0; j<n; j++)
  {
    matrix[0][j] =1;
  }

  for(int i =1; i<m; i++)
    {
      for(int j =1; j<n; j++)
        {
          if(Z[i-1] == X[j-1])
          {
            if(Z[i-1] == X[j-1])
            {
              matrix[i][j] = matrix[i-1][j-1]+matrix[i][j-1];
            }
            else
            {
              matrix[i][j] = matrix[i][j-1]+1;
            }
              }
          else
          {
             matrix[i][j] = matrix[i][j-1];
          }
        }
    }
      
      printf("%d\n",matrix[m-1][n-1]);
  
    }
  
  return 0;
}
