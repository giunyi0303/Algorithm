#include <stdio.h>
#include <math.h>
double get_distance();
void sort();
struct EDGE
{
  int dot1;
  int dot2;
  double length;
};


struct dot {
  double x;
  double y;
};

double get_distance(struct dot dot1, struct dot dot2)
{
  double distance;
  distance = sqrt((dot1.x - dot2.x) * (dot1.x - dot2.x) + (dot1.y - dot2.y) * (dot1.y - dot2.y));
  return distance;
}
void sort(EDGE a[] , int n)
{
  for(int i =0; i<n-1; i++)
    {
      for(int j = 0; j<n-1-i; j++)
        {
          if(a[j].length > a[j+1].length)
          {
            struct EDGE temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
          }
        }
    }
}


int main() {
  int n;
  double answer;
  scanf("%d", &n);
  struct dot dots[n];
  struct EDGE edge[n*(n-1)/2];
  for (int i = 0; i < n; i++) {
    scanf("%lf %lf", &dots[i].x, &dots[i].y);
  }
  int a = 0;
  for(int i = 0; i<n; i++)
    {
      for(int j = i+1; j<n; j++)
        {
          edge[a].dot1 = i;
          edge[a].dot2 = j;
          edge[a].length = get_distance(dots[i], dots[j]);
          a++;
        }
    }
  sort(edge , a);

  int meet[100];
  for(int i =0; i<n; i++)
    {
      meet[i] = i;
    }
  double total = 0;
  for(int i = 0; i<a; i++)
    {
      if(meet[edge[i].dot1]!= meet[edge[i].dot2])
      {
        int temp = meet[edge[i].dot1];
        for(int j=0; j<n; j++)
          {
            if(meet[j] == temp)
              meet[j] = meet[edge[i].dot2];
          }
        total += edge[i].length;
      }
    }
  

  printf("%.2lf" ,total);
}
