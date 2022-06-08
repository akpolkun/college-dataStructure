#include <stdio.h>
#include <deque>
#include <vector>

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

int main(){
    deque<int> Unum;
    deque<int> idealNum;

    int n, num, total = 0;
    n = getNum();
    for(int i = 0; i < n; i++){
        num = getNum(); Unum.push_back(num);
    }    
    for(int i = 0; i < n; i++){
        num = getNum(); idealNum.push_back(num);
    }
    while(Unum.size() != 0){
        if(Unum.front() != idealNum.front()){
            Unum.push_back(Unum.front());
            Unum.pop_front();
            total++;
        }
        else{
            Unum.pop_front();
            idealNum.pop_front();
            total++;
        }
    }
    printf("%d", total);
    return 0;
}