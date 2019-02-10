#include <iostream>
using namespace std;
int n;
void enqueue(int a[], int &rear, int &front){
    int x;cin>>x;if(rear==n)cout<<"Overflow"<<endl;
    else{
    a[rear]=x;rear++;
        cout<<rear-front<<endl;
    }
}
void dequeue(int a[], int &rear, int &front){
    if(front==rear){
        cout<<"-1 "<<rear-front<<endl;}
        else{
            cout<<a[front]<<" ";
            a[front]=0;front++;cout<<rear-front<<endl;
        }
    }

int main()
{
    cin>>n;
    char ch;int a[n];int rear,front;rear=front=0;
    for(int i=0;i<n;i++){
        cin>>ch;
        if(ch=='E')
        enqueue(a, rear, front);
        else if(ch=='D')
        dequeue(a, rear, front);
        ch=0;
    }
}
