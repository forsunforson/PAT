#include <iostream>
#include <stdio.h>
using namespace std;

int main() {
    int n,d,num[1000],price[1000];
    float buf[1000],result=0.0;
    cin>>n>>d;
    for(int i=0;i<n;++i) {
        cin>>num[i];
    }
    for(int i=0;i<n;++i) {
        cin>>price[i];
        buf[i]=1.0*price[i]/num[i];
    }
    int count=0;
    while(d>0) {
        int maxidx=0;
        float maxnum=0.0;
        for(int i=0;i<n;++i) {
            if(buf[i]>maxnum) {
                maxidx=i;
                maxnum=buf[i];
            }
        }
        if(num[maxidx]>=d) {
            result += d*buf[maxidx];
            d=0;
        }
        else {
            d-=num[maxidx];
            result += price[maxidx];
            buf[maxidx]=0.0;
        }
    }
    printf("%.2f",result);

    return 0;
}