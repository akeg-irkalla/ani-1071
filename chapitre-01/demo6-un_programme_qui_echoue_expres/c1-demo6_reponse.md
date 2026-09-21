#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    if (n % 2 == 0) {
        return 0;
    } else {
        return 1;
    }
}

Entrée | Code de sortie
0 | 0
1 | 1
2 | 0
3 | 1
10 | 0
17 | 1
42 | 0
100 | 0
-3 | 1
-8 | 0
