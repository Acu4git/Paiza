#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
int dp[2000001] = {0};

void swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int main() {
  int N, A, B;
  scanf("%d%d%d", &N, &A, &B);
  dp[0] = true;
  dp[N] = true;
  for (int i = 1; i <= N; i++) {
    if ((i - A >= 0 && dp[i - A] == true) || (i - B >= 0 && dp[i - B] == true))
      dp[i] = true;
  }
  int cnt = 0;
  for (int i = 1; i <= N; i++) {
    if (dp[i] == false) cnt++;
  }
  printf("%d\n", cnt);
  return 0;
}