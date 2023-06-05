#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#define N_MAX 100
#define BUCKET_SIZE 7000
int dx[] = {1, 0, -1, 0};
int dy[] = {0, -1, 0, 1};

// ある小人についての座標と動作に関する情報
typedef struct {
  int x;
  int y;
  bool flag;  // 小人が動けるかどうか
} CIE;

typedef struct cell {
  int x;
  int y;
  struct cell *next;
} CELL;
CELL *table[BUCKET_SIZE];

void initHash() {
  int i;
  for (i = 0; i < BUCKET_SIZE; i++) {
    table[i] = NULL;
  }
}

int hash(int a, int b) {
  int ret = (37 * a + b) % BUCKET_SIZE;
  if (ret < 0) ret += BUCKET_SIZE;
  return ret;
}

CELL *find(int a, int b) {
  int h = hash(a, b);
  if (table[h] == NULL) {
    return NULL;
  }

  CELL *p = NULL;
  p = table[h];
  while (p != NULL) {
    if (p->x == a && p->y == b) {
      return p;
    }
    p = p->next;
  }
  return NULL;
}

void insert(int a, int b) {
  if (find(a, b) != NULL) return;
  int h = hash(a, b);
  CELL *new;
  new = (CELL *)malloc(sizeof(CELL));
  new->x = a;
  new->y = b;
  new->next = table[h];
  table[h] = new;
}

void delete(int a, int b) {
  CELL *p, *q;
  int h = hash(a, b);
  if (table[h] == NULL) return;
  if (table[h]->x == a && table[h]->y == b) {
    p = table[h];
    table[h] = p->next;
    free(p);
    p = NULL;
    return;
  }

  for (q = table[h], p = q->next; p != NULL; q = p, p = p->next) {
    if (p->x == a && p->y == b) {
      q->next = p->next;
      free(p);
      return;
    }
  }
}

bool isSquare(int a) {
  int i;
  for (i = 1; i * i <= a; i++) {
    if (a == i * i) return true;
  }
  return false;
}

// 「らせん状移動のシミュレーション」
// 座標の印の管理はハッシュ関数で行うことでO(1)の判定が出来る。
// 曲がり角に当たったときに方向を変えるようにする。ここで、規則性により時刻をt(>0)として、tが平方数または(1+4*t)が平方数のときに曲がり角にあたることを利用する。
int main() {
  initHash();

  int N;
  scanf("%d", &N);
  CIE dwarf[N_MAX];
  for (int i = 0; i < N; i++) {
    scanf("%d%d", &dwarf[i].x, &dwarf[i].y);
    insert(dwarf[i].x, dwarf[i].y);  // 時刻0での印付け
    dwarf[i].flag = true;
  }

  int time = 0, counter = 0;
  while (1) {
    if (time != 0 && (isSquare(time) || isSquare(1 + 4 * time)))
      counter = (counter + 1) % 4;

    for (int i = 0; i < N; i++) {
      if (dwarf[i].flag) {
        // ここで全小人が動けなくなる可能性があるので、timeの更新は後にする。
        if (!(find(dwarf[i].x + dx[counter], dwarf[i].y + dy[counter]) ==
              NULL)) {
          dwarf[i].flag = false;
        } else {
          dwarf[i].x += dx[counter];
          dwarf[i].y += dy[counter];
          insert(dwarf[i].x, dwarf[i].y);
        }
      }
    }
    int cnt_false = 0;
    for (int i = 0; i < N; i++) {
      if (dwarf[i].flag == false) cnt_false++;
    }
    if (cnt_false == N) break;
    time++;
  }
  printf("%d\n", time);
  return 0;
}