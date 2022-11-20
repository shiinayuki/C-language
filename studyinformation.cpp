#include<stdio.h>
#include<string>
#include<string.h>
#include<iostream>
const int N=1e3+10;
using namespace std;
/*
给出n个学生的考试成绩表，每条信息由姓名和成绩组成，
试运用各种排序思想设计算法并比较其性能，要求实现：
a．按分数高低次序，打印出每个学生在考试中获得的名次，分数相同的为同一名次；
b．按名次列出每个学生的姓名与分数。*/
typedef struct Node{
    double S;
    string name;
    bool operator > (const Node & p)const {
        return S>p.S;
    }
    bool operator < (const Node & p)const {
        return S<p.S;
    }
    bool operator <=(const Node & p)const {
        return S<=p.S;
    }
    bool operator >=(const Node & p)const {
        return S>=p.S;
    }
}Student;
typedef Node Type;
Student a[N];
int n;
void swap(Student &a, Student &b){
    Student tmp=a;
    a=b;
    b=tmp;
}
void CreateTable(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i].S>>a[i].name;
    }
}
void Output(){
    for(int i=1;i<=n;i++){
        int No=i;
        if(a[i].S==a[i-1].S){
            No--;
        }
        cout<<"第"<<No<<"名 为：";
        cout<<a[i].S<<"   "<<a[i].name<<endl;
    }
}
void InsertSort(){
    for(int i=1;i<=n;i++){
        if(a[i].S>a[i-1].S){
            int k=i-1;
            Student tmp=a[i];
            for(int j=k;j>=1&&tmp>a[j];j--){
                a[j+1]=a[j];
                k--;
            }
            a[k+1]=tmp;
        }
    }
    Output();
}
void BubbleSort(){
    for(int i=1;i<n;i++){
        for(int j=1;j<=n-i;j++){
            Student tmp;
            if(a[j]<a[j+1]){
                swap(a[j],a[j+1]);
            }
        }
    }
    Output();
}
void QuickSort(int L,int R){
    if(L<R){
        int i=L,j=R;
        Node x=a[L];
        while(i<j){
            while( i<j && a[j]<x ){
                j--;
            }
            if(i<j)
                a[i++]=a[j];
            while(i<j&&a[i]>=x){
                i++;
            }
            if(i<j)
                a[j--]=a[i];
        }
        a[i]=x;
        QuickSort(L,i-1);
        QuickSort(i+1,R);
    }
}
void SelectSort(){
    for(int i=1;i<n;i++){
        int k=i;
        for(int j=k+1;j<=n;j++){
            if(a[k]<a[j]){
                k=j;
            }
        }
        if(i!=k){
            swap(a[i],a[k]);
        }
    }
    Output();
}
void MergeSort(Type *t,int L, int R){
    int i,j,k;
    int mid;
    if(L>=R){
        return ;
    }
     
    Type *tmp=new Type[R-L+1];
    if(t==NULL){
        return ;
    }
 
    if(tmp==NULL){
        return;
    }
    mid=(L+R)/2;
    MergeSort(t,L,mid);
    MergeSort(t,mid+1,R);
 
    i=L; j=mid+1; k=0;
    while( i<=mid && j<=R ){
        if(t[i]>t[j]){
            tmp[k++]=t[i++];
        }else{
            tmp[k++]=t[j++];
        }
    }
    while(i<=mid){
        tmp[k++]=t[i++];
    }
    while(j<=R){
 
        tmp[k++]=t[j++];
    }
    for(i=0;i<=R-L;i++){
        t[L+i]=tmp[i];
 
    }
    delete tmp;
    return;
}
void AdjustDown(Type a[], int i, int n){
    int j=i*2+1;
    while(j<n){
        if(j+1<n&&a[j]>a[j+1]){
            j++;
        }
        if(a[i]<a[j]) break;
        swap(a[i],a[j]);
        i=j;
        j=i*2+1;
    }
}
void MakeHeap(Type *a, int n){
    int i=0;
    for(i=n/2-1;i>=0;i--){
        AdjustDown(a,i,n);
    }
}
void HeapSort(Type a[], int n){
    int i=0;
    MakeHeap(a,n);
    for(i=n-1;i>=0;i--){
        swap(a[i],a[0]);
        AdjustDown(a,0,i);
    }
}
 
int main()
{
    CreateTable();
    Student b[N];
    for(int i=0;i<n;i++){
        b[i]=a[i+1];
    }
    HeapSort(b,n);
    for(int i=0;i<n;i++){
        int No=i+1;
        if(b[i].S==b[i-1].S){
            No--;
        }
        cout<<"第"<<No<<"名 为：";
        cout<<b[i].S<<"   "<<b[i].name<<endl;
    }
    return 0;
}
