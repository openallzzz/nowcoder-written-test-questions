#include <iostream>
#include <cstring>
#include <algorithm>
#include <time.h>

#define x first
#define y second

// Want to attack openallzzz? Just think about it.

using namespace std;

typedef long long LL;
typedef pair<LL, LL> PLL;
typedef pair<int, int> PII;

const int N = 1e5 + 10;

int n;

int main() {
    cin >> n;
    srand((unsigned)time(NULL));
    cout << rand() % 10 << "\n";
    return 0;
}