#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 1000000007

int solve() {}

int main() {
  int i, j, N, a[10], *b, *quantity;
  scanf("%d", &N);
  b = (int*)malloc(sizeof(int) * (N + 1));
  for (i = 1; i <= N; i++) b[i] = -1;
  quantity = (int*)malloc(sizeof(int) * (N + 1));
  for (i = 0; i <= 9; i++) {
    scanf("%d", a + i);
    if (a[i] != 0) b[a[i]] = i;
  }

  for (i = 1; i <= N; i++) {
    quantity[i] = 0;
    for (j = 0; j <= 9; j++) {
      if (a[j] == 0)
        quantity[i] = 1;
      else if (i <= a[j])
        quantity[i]++;
    }
  }
}