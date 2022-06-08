#include <cstdio>
#include <queue>
#include <functional>
using namespace std;

template <typename T> void getnum(T &val){
	char ch; bool bo=0; val=0;
	for(ch=gc();ch<'0'||'9'<ch;ch=gc()) if(ch=='-') bo=1;
	for(;'0'<=ch&&ch<='9';val=(val<<3)+(val<<1)+ch-48, ch=gc());
	if(bo) val=-val;
}

int main(){
    int T, sum, ans, n, x[2002];
    getnum(T);
    while(T--){
        sum = 0;
        getnum(n);
        priority_queue<int> q, p;
        for(int i = 0; i < n; i++){
            getnum(x[i]);
            sum += x[i];
        }

        if(sum%n != 0) printf("-1\n");
        else{
            ans = 0;
            int avg = sum/n;
            for(int i=0; i < n; i++){
                if(x[i] > avg) p.push(x[i]);
                else if(x[i] < avg) q.push(-x[i]);
            }
            while(!p.empty() || !q.empty()){
                int low, high;
                low = -q.top() , q.pop();
                high = p.top() , p.pop();
                int lif = (high - low) / 2;
                high -= lif;
                low += lif;
                ans++;
                if(low > avg) p.push(low);
                else if(low < avg) q.push(-low);
                if(high > avg) p.push(high);
                else if(high < avg) q.push(-high);
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}


