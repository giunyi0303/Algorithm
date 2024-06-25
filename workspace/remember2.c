#include <stdio.h>
#define min(a,b) ((a) < (b) ? (a) : (b))

int find_min_3(int a, int b, int c);

int find_min_3(int a, int b, int c)
{
 return min(min(a, b), c);
}
int main()
{  
  int n , m;
  scanf("%d %d" , &n , &m);
  int matrix[n][m];
  int answer[1000];
  int dp[n][m];
  
  for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<m; j++)
        {
          scanf("%d" , &matrix[i][j]);
        }
    }
  //입력받기

  //이전과 다르게 행 부터 비교 
  for(int i = 0; i<m; i++)
    {
      for(int j = 0; j<n; j++)
        {
          if(i == 0) //첫번째는 연결이 없기때문에 첫번째 값입력 
          {
            dp[j][0] = matrix[j][0];
          }
          else
          {
            if(j == 0) // 행이 0 인경우 반대쪽이 이어져 있다고 생각해서 n-1 의 index 
            {
              dp[j][i] = matrix[j][i] + find_min_3(dp[n-1][i-1],dp[j][i-1],dp[j+1][i-1]);
            }
            else if(j == n-1) // 행이 n-1 인 경우 반대쪽과 이어져 있다고 생각해 0 을기준 
            {
              dp[j][i] = matrix[j][i] + find_min_3(dp[0][i-1],dp[j-1][i-1],dp[j][i-1]);
            }
            else
            dp[j][i] = matrix[j][i]+find_min_3(dp[j-1][i-1],dp[j+1][i-1],dp[j][i-1]);
          }
        }
    }
  /*for(int i = 0; i<n; i++)
    {
      for(int j = 0; j<m; j++)
        {
          printf("%d " , dp[i][j]);
        }
      printf("\n");
    } 제대로 만들어졌나 확인 */

  
  int min_cost =100; //1~100 까지의 기준
  int min_index = -1; // index의 범위 
  for(int i =0; i<n; i++)
    {
      if(dp[i][m-1]<min_cost)
      {
        min_cost = dp[i][m-1];
        min_index = i; // 시작점 찾기 
      }
    }
    
    int row = m-1; // 시작점의 열을 기준
    answer[row] = matrix[min_index][row]; // 시작점의 행렬을 정답이라는 table에 저장
      //start
  // 각각의 경우의수 다 생각해보기 뭐가 어떤거 보다 클때 기준을 나누면 될꺼 같은데 막상 다하고 보니까 %n 했으면 될꺼 같다는 생각 
    while(row >= 0)
      { 
        if(min_index == n-1)
        {
          if(dp[0][row-1]< min(dp[min_index][row-1],dp[min_index-1][row-1]))
          {
            min_index = 0;
            row --;
            answer[row] = matrix[0][row];
          }
          else if(dp[min_index][row-1]<min(dp[0][row-1],dp[min_index-1][row-1]))
          {
            row --;
            answer[row] = matrix[min_index][row];
          }
          else
          {
            min_index = min_index -1;
            row --;
            answer[row] = matrix[min_index][row];
          }
        }
        else if(min_index == 0)
        {
          if(dp[n-1][row -1] < min(dp[min_index][row-1] , dp[min_index+1][row-1]))
          {
            min_index = n-1;
            row --;
            answer[row] = matrix[min_index][row];
          }
          else if (dp[min_index][row-1] < min(dp[n-1][row -1],dp[min_index+1][row-1]))
          {
            row --;
            answer[row] = matrix[min_index][row];
          }
          else
          {
            min_index = min_index +1;
            row --;
            answer[row] = matrix[min_index][row];
          }
        }
        else
        {
          if(dp[min_index][row-1]<min(dp[min_index-1][row-1],dp[min_index+1][row-1]))
          {
            row --;
            answer[row] = matrix[min_index][row];
          }
        else if (dp[min_index-1][row-1]< min(dp[min_index][row-1],dp[min_index+1][row-1]))
          {
            min_index = min_index -1;
            row --;
            answer[row] = matrix[min_index][row];
          }
          else
          {
             min_index = min_index +1;
            row --;
            answer[row] = matrix[min_index][row];
          }
        }
      }


      //print 
        for(int i = 0; i<m; i++)
          {
            printf("%d " , answer[i]);
          } 
        printf("\n");

   printf("%d\n" , min_cost);
      
  return 0;
}
