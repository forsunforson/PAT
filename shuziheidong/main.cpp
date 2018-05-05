#include <iostream>
#include <algorithm>
using namespace std;

void printInt(int x) {
    int buf[4]={0,0,0,0};
    for(int i=0;i<4;++i) {
        buf[i]=x%10;
        x=x/10;
    }
    for(int j=3;j>=0;--j) {
        cout<<buf[j];
    }
}
int reverseInt(int x) {
    int result=0,buf[4]={0,0,0,0},num=0;
    for(int i=0;i<4;++i) {
        buf[i]=x%10;
        x=x/10;
    }
    sort(buf,buf+4);
    for(int j=0;j<4;++j) {
        result = 10*result+buf[j];
        num=10*num+buf[3-j];
    }
    if(num>result) {
        printInt(num);
        cout  << " - ";
        printInt(result);
        cout<< " = ";
    }
    else {
        printInt(result);
        cout  << " - ";
        printInt(num);
        cout<< " = ";
    }
    result=abs(num-result);
    printInt(result);
    cout<<endl;
    return result;
}
int main() {
    int n;
    cin >> n;
    while(true) {
        n=reverseInt(n);
        if(n==0) break;
        if(n==6174) break;
    }

    return 0;
}