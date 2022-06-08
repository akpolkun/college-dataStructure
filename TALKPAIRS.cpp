#include <stdio.h>
#include <stack>
using namespace std;

int getNum(){
    int res = 0;
    char c;
    int b = 0;
    while(1){
        c = getchar_unlocked();
        if(c == '-') b = 1;
        if(c == ' ' || c == '\n') continue;
        else break;
    }
    if(c != '-') res = c - '0';
    while(1){
        c = getchar_unlocked();
        if(c >= '0' && c <= '9') res = 10 *  res + c - '0';
        else break;
    }
    if(b == 1) res *= -1;
    return res;
}

stack <int> s;
int main(){
    int T, ans = 0;
    T = getNum();
    while(T--){
        int a = -1;
        int temp = getNum();

        while(!s.empty()){
            if((s.top() <= a) || (temp <= a)) break;

            ans++;

            if(temp >= s.top()){
                a = s.top(); s.pop();
            }
            else if(temp < s.top()) break;
        }

        s.push(temp);
    }
    printf("%d\n", ans);
}