#include<bits/stdc++.h>
using namespace std;
void heapify(int a[],int i,int n){
  int largest=i;
  int left=2*i+1;
  int right=2*i+2;
  if(left < n && a[left] > a[largest])
  largest=left;
  if(right < n && a[right] > a[largest])
  largest=right;
  if(largest!=i)
  {
    swap(a[largest],a[i]);
    heapify(a,largest,n);
  }
   
}
void buildheap(int a[],int n){
    int startind=(n/2)-1;
    for(int i=startind;i>=0;i--)
    heapify(a,i,n);
}
int main(){
   int n;
   int a[10000];
   cin>>n;
   for(int i=0;i<n;i++)
   cin>>a[i];
   buildheap(a,n);
   for(int i=0;i<n;i++)
   cout<<a[i]<<" ";
   cout<<endl;
}