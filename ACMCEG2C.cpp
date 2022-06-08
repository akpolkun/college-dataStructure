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
    int t, k, candy, sweet, ans;
    t = getNum();
    while(t--){
        vector<int> var;
        deque<int> temp;
        candy = getNum(); k = getNum();
        for(int i = 0; i < candy; i++){
            sweet = getNum();
            var.push_back(sweet);
            temp.push_back(i);
        }

        for(int i = 0; i < var.size(); i++){
            ans = var.at(i);
            for(int j = i+1; j < i+k; j++){
                if(ans < var.at(j)) ans = var.at(j);
            }
            temp.pop_front();
            printf("%d ", ans);
            if(temp.size() < k ) break;
        }
    }
    return 0;
}