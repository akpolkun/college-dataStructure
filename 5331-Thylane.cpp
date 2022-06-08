#include <stdio.h>
#include <algorithm>
using namespace std;
#define oo 1000000000000ll

int main(){
    int n,A;
    long int ans = -oo, sum = 0ll;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &A);
        sum = sum >= 0 ? (sum + A) : A;
        ans = max(sum,ans);
    }
    printf("%lld\n", ans);
    return 0;
}