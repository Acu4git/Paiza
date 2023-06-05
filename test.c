#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define Q_SIZE 200001
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
  initQ();
  int N;
  char s[200001];
  scanf("%d%s", &N, s);
  int buf[200000];
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == 'B')
      buf[N - i - 1] = 0;
    else
      buf[N - i - 1] = 1;
  }
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == 'B')
      enqueue(0);
    else
      enqueue(1);
  }
  int cnt = 0;
  while (1) {
    bool flag = true;
    cnt++;
    int x = dequeue();
    enqueue(x);
    for (int i = 0; i < N; i++) {
      if (buf[i] != queue[(i + front) % Q_SIZE]) flag = false;
    }
    if (flag) break;
  }
  printf("%d\n", cnt);
}