#include <stdio.h>

int main() {
  int H, W, N;
  scanf("%d%d%d", &H, &W, &N);
  char s[20][21];
  for (int i = 0; i < H; i++) scanf("%s", s[i]);
  for (int i = 0; i < N; i++) {
    int y, x;
    scanf("%d%d", &y, &x);
    putchar(s[y][x]);
    putchar('\n');
  }
  return 0;
}