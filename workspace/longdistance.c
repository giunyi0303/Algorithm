#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
  char cityname[20];
  int citynum;
} City;

typedef struct {
  int time;
  char city[20];
  int check;

} Train;

typedef struct {
  Train path[100];
  int path_length;
  int total_time;
} Answer;

int path_index = 0;

int getcitynum(char *name, City city[], int citynum) {
  int i;
  for (i = 0; i < citynum; i++) {
    if (strcmp(name, city[i].cityname) == 0)
      return city[i].citynum;
  }
  return -1;
}

void check(int start, int end, Train train[][100], int train_num, int visit_num,
           int city_num, City city[], Answer *answer, Answer possible_path[]) {
  if (start == end) {
    answer->total_time =
        answer->path[answer->path_length - 1].time - answer->path[0].time;
    possible_path[path_index] = *answer;
    path_index++;
    return;
  }
  for (int i = 0; i < train_num; i++) {
    if (train[i][0].check == 1 &&
        getcitynum(train[i][0].city, city, city_num) == start) {
      for (int j = 1; j < visit_num; j++) {
        if (train[i][j].check == 0) {
          int nextCity = getcitynum(train[i][j].city, city, city_num);
          if (nextCity != -1) {
            train[i][j].check = 1;
            answer->path[answer->path_length] = train[i][j];
            answer->path_length++;
            check(nextCity, end, train, train_num, visit_num, city_num, city,
                  answer, possible_path);
            answer->path_length--;
            train[i][j].check = 0;
          }
        }
      }
    }
  }
}

int main() {

  int schdeul_num;
  scanf("%d", &schdeul_num);
  int citynum;
  scanf("%d", &citynum);
  City city[citynum];
  Train train[100][100];
  for (int i = 0; i < citynum; i++) {
    scanf("%s", city[i].cityname);
    city[i].citynum = i;
  }
  int train_num;
  int visit_num;
  scanf("%d", &train_num);
  for (int i = 0; i < train_num; i++) {
    scanf("%d", &visit_num);
    for (int j = 0; j < visit_num; j++) {
      if (j == 0) {
        scanf("%d %s", &train[i][j].time, train[i][j].city);
        train[i][j].check = 1; // depart
      } else {
        scanf("%d %s", &train[i][j].time, train[i][j].city);
        train[i][j].check = 0; // arrive
      }
    }
  }
  int start_time;
  char start_city[100];
  char end_city[100];
  scanf("%d", &start_time);
  scanf("%s", start_city);
  scanf("%s", end_city);
  int start = getcitynum(start_city, city, citynum);
  int end = getcitynum(end_city, city, citynum);
  Answer possible_path[100];
  Answer best_path;
  best_path.path_length = 0;
  for (int i = 0; i < train_num; i++) {
    for (int j = 0; j < visit_num; j++) {
      if (train[i][j].check == 1 &&
          getcitynum(train[i][j].city, city, citynum) == start &&
          train[i][j].time >= start_time) {
        Answer current_path;
        current_path.path_length = 0;
        current_path.total_time = 0;
        train[i][j].check = 1;
        current_path.path[current_path.path_length] = train[i][j];
        current_path.path_length++;

        check(getcitynum(train[i][j].city, city, citynum), end, train,
              train_num, visit_num, citynum, city, &current_path,
              possible_path);
        train[i][j].check = 0;
      }
    }
  }
  if (path_index > 0) {
    int mintime = 100000;
    int answer_index = 0;
    int answer_path = 0;

    for (int i = 0; i < path_index; i++) {
      for (int j = 0; j < possible_path[i].path_length; j++) {
        if (possible_path[i].path[possible_path[i].path_length].time <
            mintime) {
          mintime = possible_path[i].path[possible_path[i].path_length].time;
          answer_path = i;
          answer_index = possible_path[i].path_length;
        }
      }
    }
    printf("Departure %04d %s\n", possible_path[answer_path].path[0].time,
           possible_path[answer_path].path[0].city);
    printf("Arrival %04d %s",
           possible_path[answer_path].path[answer_index - 1].time,
           possible_path[answer_path].path[answer_index - 1].city);
  }

  return 0;
}
