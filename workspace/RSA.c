#include <stdio.h>
#include <stdlib.h>
#include <string.h>



void encode(const char* str ,char *arr )
{
  int i = 0;
  while(*str)
    {
      if(*str == ' ')
      {
        arr[i++] = '0';
        arr[i++] = '0';
      }
        else if (*str >= 'A' && *str <= 'Z')
      {
        int val = *str - 'A' +1;
        arr[i++] = '0' + val/10;
        arr[i++] = '0' + val%10;
      }
    str++;
      }
  if((i%4 !=0))
  {
  arr[i++] = '0';
  arr[i++] = '0';
  }
  arr[i] = '\0';
}

int MODULAR_E(int a , int b, int n)
{
  int d;
  if(b ==0)
    return 1;
  else if(b % 2 ==0 )
    {
      d = MODULAR_E(a, b/2, n);
      return (d*d) % n;
    }
  else d = MODULAR_E(a, b-1, n);
  return (a*d) % n;
}


void RSA(int p , int q , int e , const char *arr)
{
  int n = p*q;
  int pi = (p-1) * (q-1);
  for(int i = 0; arr[i] != '\0'; i+=4)
    {
      int temp = 1000*(arr[i] - '0') + 100*(arr[i+1] - '0')  + 10 * (arr[i+2] - '0')  + arr[i+3] - '0';
      int answer = MODULAR_E(temp , e , n);
      printf("%04d " , answer);
    }
  printf("\n");
}

void decode(int p , int q , int e , const char *arr)
{
  int n = p*q;
  int pi = (p-1) * (q-1);
      int temp = 1000*(arr[0] - '0') + 100*(arr[1] - '0')  + 10 * (arr[2] - '0')  + arr[3] - '0';
      int D = 0;
     for(int d = 2; d<pi; d++)
       {
         if((d*e) % pi ==1)
         {
            D = d;
           break;
         }
       }
        printf("%d" , D);

  /*
  int answer = MODULAR_E(temp , e , n);
  int answer1 = MODULAR_E(answer ,D,n);
  printf("%d" , answer1);
  실제 d를넣어서 구하면 맞는지 확인 
  */
}


int main() 
{
  char str[100];
  char arr[100];
  fgets(str , sizeof(str) , stdin);
  int p , q , e;
  scanf("%d %d %d" , &p , &q , &e);
  encode(str , arr);
  for(int i = 0; arr[i] !='\0'; i++)
    {
  printf("%c" ,  arr[i]);
      if ( (i+1)%4 ==0)
      {
        printf(" ");
      }
    }
  printf("\n");
  RSA( p ,q ,e ,arr);
  decode(p ,q ,e ,arr);
 
  
  
  
}
