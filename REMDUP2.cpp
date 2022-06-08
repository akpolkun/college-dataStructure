#include <stdio.h>
#include <set>
#include <stack>
#define gc getchar_unlocked
using namespace std;

void Get(int &ret){
    ret = 0; char inp = gc(); int kl = 1;
    while(inp < '0' || inp > '9'){
        if(inp == '-') kl = -1; inp = gc();
    }
    while('0' <= inp && inp <= '9')
        ret = (ret << 3) + (ret << 1) + (int)(inp - '0'), inp = gc();
        if(kl < 1) ret = -ret;
}

int main(){
    int T, num;
    set <int> set_num;
    stack <int> stack_num;
    Get(T);
    for(int i = 0; i < T; i++){
        Get(num);
        if(set_num.count(num) == 0){
            set_num.insert(num); stack_num.push(num);
            printf("%d ", num);
        }
    }
    printf("\n");
    for(int i = 0; i < set_num.size(); i++){
        printf("%d ", stack_num.top()); stack_num.pop();
    }
    return 0;
}