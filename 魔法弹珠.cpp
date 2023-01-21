#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 100010;
int n, v[N];
LL sum[N];
int main() {
    scanf("%d", &n);
    for(int i = 1; i <= n; i ++) scanf("%d", &v[i]);
    sort(v + 1, v + n + 1);
    for(int i = 1; i <= n; i ++) sum[i] = sum[i - 1] + 0ll + v[i];
    int res = 0;
    for(int i = n; i >= 1; i --) {
        if(v[i] <= sum[i - 1]) res ++ ;
        else break;
    }
    printf("%d\n", res + 1);
    return 0;
}

