#include <stdio.h>

int Extended_Euclid(int a , int b);



int Extended_Euclid(int a , int b , int *x , int *y)
{
  if(b ==0)
  {
    *x =1;
    *y =0;
    return a;
  }
  else
  {
    int d = Extended_Euclid(b, a%b , y , x);
    *y -=(a/b)* (*x);
    return d;
 }
}



int main()
{
  int num;
  scanf("%d" , &num);
for(int i = 0; i<num; i++)
  {
    int a , b;
    scanf("%d %d" , &a , &b);
    int x , y;
    int d = Extended_Euclid(a , b , &x , &y);
    printf("%d %d %d" , x ,y , d);
    printf("\n");
    
  }
  
  
  
  return 0;
}
