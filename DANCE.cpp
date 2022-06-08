#include <stack>
#include <cstdio>
using namespace std;
int n,i;
char s[100000000];

int main(){
    for(int t = 1; t <= 10; t++)
    {
        scanf("%d %s", &n,&s);
        stack<bool> st; //1 = 'S', 0 = 'R'
        i = 0;
        while(i < n)
        {
            if(st.empty())
            {
                if(s[i] == 'S') st.push(1);
                st.push(0);
            }
            else if(st.size() == 1)
            {
                if(st.top() == 0)
                {
                    if(s[i] == 'R') st.pop();
                }
                else
                {
                    if(s[i] == 'S') st.pop();
                    else st.push(0);
                }
            }
            else if(st.top() == 0)
            {
                st.pop();
                if(s[i] == 'S')
                {
                    st.push(1);
                    st.push(0);
                    st.push(1);
                    st.push(0);
                }
            }
            else
            {
                if(s[i] == 'R') st.push(0);
                else st.pop();
            }
            i++;
        }
        printf("%d\n", (int)st.size());
    }
    return 0;
}