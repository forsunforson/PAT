#include <iostream>
using namespace std;

int main() {
    int a,b,c,d;
    int buf[32];
    cin >> a >> b >> d;
    c = a+b;
    int i=0;
    while(c!=0) {
        buf[i++] = c%d;
        c = c/d;
    }
    for(int j=i-1;j>=0;--j) {
        cout<<buf[j];
    }
    cout<<endl;
    return 0;
}