#include <stdio.h>
#include <vector>

using namespace std;
vector<int> parent;

int find(int u){
    if(parent.at(u) == u) return u;
    else return parent.at(u) = find(parent.at(u));
}

int main(){
    int t, n, m, a, b;
    scanf("%d", &t);
    while(t--){
        parent.clear();
        scanf("%d%d", &n, &m);
        for(int i = 0; i <= n; i++) parent.push_back(i);
        for(int i = 0; i < m; i++){
            scanf("%d%d", &a, &b);
            int u = find(a), v = find(b);
            if(u != v){
                if(u > v) parent.at(u) = v;
                else parent.at(v) = u;
            }
        }
        int ans = 0; vector <int> temp;
        for(int i = 1; i <= n; i++) if(i == find(i)){
            temp.push_back(i);
        }
        for(int i = 1; i <= n; i++){
            if(temp)
        }
        if(ans == 1) puts("YES");
        else puts("NO");
    }
    return 0;
}