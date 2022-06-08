#include <stack>
#include <string>
#include <iostream>
#include <algorithm>
using namespace std;

int main(){
	string a;
    getline(cin,a);
    //while(getline(cin,a) != NULL){
        stack <double> s;
        double x,y; int i;
        for(int j = 0; j < a.size(); j++){
            if(a[j] == ' ') continue;
            else{
                if(a[j] >= 48 && a[j] <= 57) s.push(a[j]-48);
                else{
                    if(a[j] == '+'){
                        x = s.top(); s.pop();
                        y = s.top(); s.pop();
                        s.push(x+y);
                    } else if(a[j] == '-'){
                        x = s.top(); s.pop();
                        y = s.top(); s.pop();
                        s.push(y-x);
                    } else if(a[j] == '*'){
                        x = s.top(); s.pop();
                        y = s.top(); s.pop();
                        s.push(x*y);
                    } else if(a[j] == '/'){
                        x = s.top(); s.pop();
                        y = s.top(); s.pop();
                        s.push(y/x);
                    }
                }
            }
        }
        if(s.size() > 1) cout << "ERROR\n" << endl;
        else printf("%.4lf\n", s.top());
    //}

    return 0;
}
