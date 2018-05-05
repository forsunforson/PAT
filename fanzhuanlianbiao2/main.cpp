#include <iostream>
using namespace std;

struct DuoLinkList {
    int data;
    int next,pre;
}ll[100001];

int reverse(int s,int k) {
    int count=0;
    int addr=s;
    while(true) {
        count++;
        if(count==k) break;
        if(addr==-1) break;
        addr=ll[addr].next;

    }
    if(count<k) {
        return s;
    }
    else if(count==k && addr==-1){
        int end=addr;
        for(int i=0;i<k-1;++i) {
            ll[addr].next=ll[addr].pre;
            addr=ll[addr].pre;
        }
        ll[addr].next=-1;
        return end;
    }
    else {
        int ns=ll[addr].next;
        int end=addr;
        for(int i=0;i<k-1;++i) {
            ll[addr].next=ll[addr].pre;
            addr=ll[addr].pre;
        }
        ll[addr].next=reverse(ns,k);
        return end;
    }
}
void printint(int x) {
    if(x==-1) {
        cout<<x;
    }
    else if(x==0) {
        cout<<"00000";
    }
    else if(x<10) {
        cout<<"0000"<<x;
    }
    else if(x<100) {
        cout<<"000"<<x;
    }
    else if(x<1000) {
        cout<<"00"<<x;
    }
    else if(x<10000) {
        cout<<'0'<<x;
    }
    else if(x>=10000){
        cout<<x;
    }
}
int main() {
    int start,n,k;
    cin>>start>>n>>k;
    ll[start].pre=-1;
    for(int i=0;i<n;++i) {
        int addr;
        cin>>addr>>ll[addr].data>>ll[addr].next;
        if(ll[addr].next!=-1) {
            ll[ll[addr].next].pre=addr;
        }
    }
    int addr=start;
    for(int i=1;i<k;++i) {
        addr=ll[addr].next;
    }
    reverse(start,k);
    while(addr!=-1) {
        printint(addr);
        cout<<" "<<ll[addr].data<<" ";
        printint(ll[addr].next);
        cout<<endl;
        addr=ll[addr].next;
    }

    return 0;
}