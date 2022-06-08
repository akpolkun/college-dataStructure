#include <stdio.h>
#include <queue>
#include <string.h>
using namespace std;

int main(){
    long long T, number,sum, total;
    scanf("%d", &T); int num[T];
    priority_queue<long long, vector<long long>, greater<long long>> numList;
    for(int i = 0; i < T; i++){
        scanf("%lld", &number);
        numList.push(number);
    }
    for(int i = 0; i < T; i++){
        long long temp, temp1;
        if(numList.size() == 1) break;
        else{
            temp = numList.top(); numList.pop();
            temp1 = numList.top(); numList.pop();
            sum = temp + temp1;
            total += sum;
            numList.push(sum);
        }
    }
    printf("%lld", total);
    return 0;
}