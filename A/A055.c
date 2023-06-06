#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 1000
#define next(a) ((a + 1) % Q_SIZE)
int queue[Q_SIZE];
int front, rear;

void initQ() {
  for (int i = 0; i < Q_SIZE; i++) queue[i] = 0;
  front = rear = 0;
}

void enqueue(int e) {
  if (next(rear) == front) {
    fprintf(stderr, "Error:Queue overflow.\n");
    exit(1);
  }
  queue[rear] = e;
  rear = next(rear);
}

int dequeue() {
  if (front == rear) {
    fprintf(stderr, "Error:Queue underflow.\n");
    exit(1);
  }
  int x = queue[front];
  front = next(front);
  return x;
}

bool emptyQ() {
  if (front == rear)
    return true;
  else
    return false;
}

int main() {
  // 左上(0,0)から見て、(x,y)にあるマスの番号をx*W+yとする
  int H, W, flag[10000];
  scanf("%d%d", &H, &W);
  char s[100][101];
  for (int i = 0; i < H; i++) {
    scanf("%s", s[i]);
  }

  int start;
  for (int i = 0; i < H; i++) {
    for (int j = 0; j < W; j++) {
      if (s[i][j] == 'S') {
        start = i * W + j;
      }
      flag[i * W + j] = false;
    }
  }
  enqueue(start);
  flag[start] = true;
  while (!emptyQ()) {
    int v = dequeue();
    if (v / W == 0 || v / W == H - 1 || v % W == 0 || v % W == W - 1) {
      puts("YES");
      exit(0);
    }

    if (s[v / W][v % W + 1] == '.' && flag[v + 1] == false) {
      enqueue(v + 1);
      flag[v + 1] = true;
    }
    if (s[v / W - 1][v % W] == '.' && flag[v - W] == false) {
      enqueue(v - W);
      flag[v - W] = true;
    }
    if (s[v / W][v % W - 1] == '.' && flag[v - 1] == false) {
      enqueue(v - 1);
      flag[v - 1] = true;
    }
    if (s[v / W + 1][v % W] == '.' && flag[v + W] == false) {
      enqueue(v + W);
      flag[v + W] = true;
    }
  }
  puts("NO");
  return 0;
}