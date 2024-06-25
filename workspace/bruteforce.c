#include <stdio.h>
#include <stdlib.h>
#include <math.h>
typedef struct point
{
int x;
int y;
}DOT;

DOT * sorting(struct point a[] , int n)
{
  for(int i = 0 ; i<n; i++)
    {
      for(int j = i+1; j<n; j++)
        {
          if(a[i].x > a[j].x)
          {
            DOT temp = a[i];
            a[i] = a[j];
            a[j] = temp;
          }
        }
    }
  return a;
}

double find_min_2(double a , double b)
{
  if(a<b)
  {
    return a;
  }
  else
    return b;
}

double find_midian(struct point a[] , int n)
{
  double sum = 0;
  double mid;
  for(int i =0; i<n; i++)
    {
      sum += a[i].x;
    }
  mid = sum / n;
  return mid;
}


double brute_force(struct point a[] ,int mid)
{
  double min = 10000;
  double distance;
  for(int i = 0; i<mid; i++)
    {
      for(int j = i+1; j<mid; j++)
        {
             distance = sqrt((a[i].x - a[j].x) *  (a[i].x - a[j].x) + (a[i].y - a[j].y) * (a[i].y - a[j].y));      
        if(distance < min)
        {
          min = distance;
        }
        }
    }
  return min;
}


int main()
{ 
  int n;
  double mid;
  if (scanf("%d", &n) <= 0) return 1;
  DOT p[n];
  for(int i =0; i<n; i++)
    {
     if(scanf("%d %d" , &p[i].x , &p[i].y) <= 0) return 1; 
    }
  
  mid = find_midian(p,n);
  DOT *section1 = (DOT*) malloc(sizeof(DOT)*n);
  DOT *section2 = (DOT*) malloc(sizeof(DOT)*n);
  DOT *section3 = (DOT*) malloc(sizeof(DOT)*n);
  int count1 = 0;
  int count2 = 0;
  int count3 = 0;
  for(int i = 0; i<n; i++)
    {
      if(p[i].x <mid)
      {
        section1[count1] = p[i];
        count1++;
      }
      else
      {
        section2[count2] = p[i];
        count2++;
      }
      
    }
    
    double d1 = brute_force(sorting(section1, count1),count1);
    double d2 = brute_force(sorting(section2, count2),count2);
    double d = find_min_2(d1,d2);

  for(int i = 0; i<n; i++)
    {
      if(p[i].x > mid - d && p[i].x <mid +d )
      {
        section3[count3] = p[i];
        count3++;
      }
    }
  double d3 = brute_force(sorting(section3, count3),count3);
  printf("%.2lf" , find_min_2(d,d3));
  free(section1);
  free(section2);
  free(section3);
  return 0;
}

