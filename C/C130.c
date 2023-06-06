#include <stdio.h>

int main() {
  int i, N, cnt = 0;
  char a[1003], b[1003];
  scanf("%d", &N);
  for (i = 1; i <= N; i++) {
    scanf(" %c %c", &a[i], &b[i]);
    if (a[i] == 'y' && b[i] == 'y') continue;
    cnt++;
  }
  printf("%d\n", cnt);
  for (i = 1; i <= N; i++) {
    if (a[i] == 'y' && b[i] == 'y') continue;
    printf("%d\n", i);
  }
  return 0;
}