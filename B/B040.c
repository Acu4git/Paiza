#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ALPHA_LEN 26
#define MAX_STR_LEN 1000

int main() {
  int n;
  char T[ALPHA_LEN + 1];
  scanf("%d%s%*c", &n, T);
  char s[MAX_STR_LEN + 1];
  scanf("%[^\n]", s);
  while (n-- > 0) {
    for (int i = 0; i < strlen(s); i++) {
      if (s[i] >= 'a' && s[i] <= 'z') {
        for (int j = 0; j < ALPHA_LEN; j++) {
          if (s[i] == T[j]) {
            s[i] = 'a' + j;
            break;
          }
        }
      }
    }
  }
  printf("%s\n", s);
  return 0;
}