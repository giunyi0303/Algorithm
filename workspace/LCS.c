#include <stdio.h>

  int elephant[1000][2];
  int num = 0; // count 
  int W[1000];
  int S[1000];

int main()
{
  while(1)
    {
      // 입력 받기 시작
     if(scanf("%d %d" , &elephant[num][0],&elephant[num][1]) == 2)
     {
       if(elephant[num][0] == -1 && elephant[num][1] == -1)
       break;
     }
       W[num] =num+1; // 우리가 나타낼 index는 1부터 시작 
       S[num] = num+1;
      num++;
    }
  // bubble sort 로 첫번째 원소 오름차순 정렬 
  for(int i=0; i<num; i++)
    {
      for(int j = 0; j < num -1; j++)
        {
      if(elephant[j][0] > elephant[j+1][0]) 
      {
        int temp = elephant[j][0];
        elephant[j][0] = elephant[j+1][0];
        elephant[j+1][0] = temp;
        temp = W[j];
        W[j] = W[j+1];
        W[j+1] = temp;
        } 
      }
    }
 // bubble sort 로 두번쨰 원소 내림차순 정렬 
  for(int i=0; i<num; i++)
    {
      for(int j = 0; j < num -1; j++)
        {
      if(elephant[j][1] < elephant[j+1][1])
      {
        int temp = elephant[j][1];
        elephant[j][1] = elephant[j+1][1];
        elephant[j+1][1] = temp;
        temp = S[j];
        S[j] = S[j+1];
        S[j+1] = temp;
         }
          
        }
    }
  // 정렬 상 동일 값이 있을때 뒤에 값을 비교로 swap 
  // 동일한 배열의 행이 같으면 열의 값을 기준으로 바꿈 아까 넣을때 늘려놓은 1값을 빼고 비교 
  for(int i = 0; i<=num -1; i++) 
      {
        if(elephant[W[i]-1][0] == elephant[W[i+1]-1][0])
        {
          if(elephant[W[i]-1][1] > elephant[W[i+1]-1][1])
          {
             int temp = elephant[W[i]-1][0];
             elephant[W[i]-1][0] = elephant[W[i+1]-1][0];
             elephant[W[i+1]-1][0] = temp;
              temp = W[i];
              W[i] = W[i+1];
             W[i+1] = temp;
          }
        }
      }
    
  // 앞배열은 내림차순 뒤는 오름차순 배열 완료후 인덱스 까지 저장완료 
   int table[1000][1000] ={0};
  for(int i =0; i<=num;i++)
    {
      table[i][0] = 0;
    }
  for(int j=0; j<=num;j++)
    {
      table[0][j] = 0;
    }
  for(int i =1; i<=num; i++)
    {
      for(int j=1; j<=num; j++)
        {
          if(S[i-1] == W[j-1]){ // 세로축으로 놓는게 먼저 들어가야함 ㅜ 
            table[i][j] = table[i-1][j-1]+1;
          }
        else 
      {
        if (table[i - 1][j] > table[i][j - 1])
          table[i][j] = table[i - 1][j];
          
        else
          table[i][j] = table[i][j - 1];
      }
        }
    }
    

 /* printf("\n---------------------------------------\n");  실제 배열확인용 
 for(int i =0; i<num; i++)
  {
  printf("%d ",W[i]);
  }
  printf("\n");
  for(int i =0; i<num; i++)
  {
  printf("%d ",S[i]);
  }
  printf("\n---------------------------------------\n");
  */
  
  printf("%d\n",table[num][num]); // 몇개가 존재하는지 테이블의 마지막 값이 됨 
  // back tracking
  
  int max = table[num][num]; // 가장 큰값
  int LCS[1000]; // backtracking 결과를 담을 배열 선언 
  int index = 0;
  int i = num;
  int j = num;
  while(i>0 && j>0)
    {
      if(table[i][j]==max && table[i-1][j]==max-1 &&table[i][j-1]==max-1){
        LCS[index] = S[i-1];
        index++;
        max--;
        j--;
        i--;
      }
        else if(table[i-1][j]>table[i][j-1])
      {
        i--;
      }
      else
        j--;
      }
    
    for(int i = index -1; i>=0; i--) // LCS 배열 거꾸로 순서대로 출력 
      {
        printf("%d\n",LCS[i]);
      }
      
  /* printf("\n---------------------------------------\n");
  for(int i = 0; i<=num; i++)
    {
      for(int j =0; j<=num; j++)
        {
          printf("%d ",table[i][j]);
        }
        printf("\n");
    }
  printf("\n---------------------------------------\n");
  */
  
  return 0;
}


