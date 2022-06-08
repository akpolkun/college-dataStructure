#include <stdio.h>
#include <deque>

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
    int n,i;
    while(1){
        n = getNum();
        if(n == 0) break;
        std::deque<int> cards;
        for(i = 1; i <= n; i++) cards.push_back(i);

        printf("Discarded cards: ");
        while(cards.size() > 1){
                if(cards.size() != 2) printf("%d, ", cards.front());
                else printf("%d\n", cards.front());

                cards.pop_front();
                cards.push_back(cards.front());
                cards.pop_front();
        }
        printf("Remaining card: %d\n", cards.front());
    }
    return 0;
}