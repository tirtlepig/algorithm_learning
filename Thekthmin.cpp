//
// Created by 86184 on 2021-06-21.
//
#include <iostream>
#include <ctime>
#include <stdlib.h>
using namespace std;

template <typename T>
int partition(T *a, int p, int q){
    T x = a[p];
    int i = p;
    for(int j=p+1;j<=q;j++){
        if(!(x < a[j])){
            i++;
            swap(a[i], a[j]);
        }
    }
    swap(a[p], a[i]);
    return i;
}

template <typename T>
T kthElement(T *a, int l, int r, int k){
    if(r <= l){
        return a[l];
    }
    int m = partition<T>(a, l, r);
    int kk = m-l+1;
    if(k == kk){
        return a[m];
    }else if(k<kk){
        return kthElement(a, l, m-1, k);
    }else
    {
        return kthElement(a, m+1, r, k-kk);
    }
}

//����ָ����Χ������������ڲ���
template<typename T>
T *Random(int n,int l,int r)//���ɷ�Χ��l~r�������
{
    T *a=new T[n];
    srand(time(0));  //����ʱ������
    for(int i=0;i<n;i++){
        a[i]=rand()%(r-l+1)+l;//��������r~l�������
    }
    return a;
}

int main(){
   // int test[10] = {2,3,4,1,7,5,6,10,9,8};
    int k = 0;
    int min=0;
    int max=0;
    cout<<"���������ֵ��Сֵ��Χ:";
    cin>>min;
    cout<<"���������ֵ���ֵ��Χ:";
    cin>>max;
    int num=max-min+1;
    int *test=Random<int>(num,min,max);
    cout<<"���ɵ�����Ϊ:";
    for (int i = 0; i < num; ++i) {
        cout<<test[i]<<" ";
    }
    cout<<endl;
    cout<<"�����������Ԫ��Ϊ�ڼ�С:";
    cin>>k;
    cout<<endl;
    cout << kthElement<int>(test, 0, num-1, k)<<endl;
    cout<<"����������Ϊ:";
    for (int i = 0; i < num; ++i) {
        cout<<test[i]<<" ";
    }
    delete test;
}
