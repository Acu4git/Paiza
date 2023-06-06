#include <stdio.h>

int main() {
  int N, c, t[101], max = 0;
  scanf("%d%d", &N, &c);
  for (int i = 0; i < N; i++) scanf("%d", &t[i]);
  for (int i = 0; i < N; i++) {
    int time = c;
    for (int j = i + 1; j < N; j++) {
      if (t[j - 1] >= t[j] - c)
        time += t[j] - t[j - 1];
      else
        break;
    }
    if (time > max) max = time;
  }
  printf("%d\n", max);
}