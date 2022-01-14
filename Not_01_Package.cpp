//
// Created by 86184 on 2021-06-23.
//
#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

struct TGods
{
    int id;//��Ʒ���
    float w,v;//���� ��ֵ
    float x;//����
    TGods():w(0),v(0),x(0){}//��ʼ��
};

bool bgreat(const TGods &x,TGods &y)
{
    return x.v/x.w > y.v/y.w;
}

template <typename T>//���������������ķ�װ
class solution{
public:
    int num;
    T limit;//�����������
    TGods *array;
    queue<int>ways;
    T value;//�ܼ�ֵ
    T weight;//������
    T cc;//ʣ������
    solution(){
        cout<<"�����������Ŀ����������"<<endl;
        cin>>num>>limit;
        array=new TGods[num];
        for (int i = 0; i < num; ++i) {
            array[i].id=i+1;
        }
        cout<<"�������������Ʒ����"<<endl;
        for (int i = 0; i < num; ++i) {
            cin>>array[i].w;
        }
        cout<<"�������������Ʒ��ֵ"<<endl;
        for (int i = 0; i < num; ++i) {
            cin>>array[i].v;
        }
        cc=limit;
    }
    void greedy_solution();
    void show();
    ~solution(){
        delete[] array;//�ͷ��ڴ�
    }
};

template<typename T>
void solution<T>::greedy_solution() {
    sort(array,array+num,bgreat);
    for (int i = 0; i < num; ++i) {
        if (cc==0)
            break;
        if (cc>array[i].w)
        {
            array[i].x=1;
            cc-=array[i].w;
            value+=array[i].v;
            weight+=array[i].w;
            continue;
        }
        float x=cc/array[i].w;//��ʱ�Ѿ�����һ��������ȡ����Ʒ��
        array[i].x=x;
        value+=array[i].v*x;
        weight+=array[i].w*x;
        break;
    }
}

template<typename T>
void solution<T>::show() {
    cout<<"max weight:"<<weight<<endl;
    cout<<"max value:"<<value<<endl;
    cout<<"The choice of package are :";
    for (int i = 0; i < num; ++i) {
        if (array[i].x<=0)
        {
            break;
        }
        cout<<"package"<<array[i].id<<"("<<array[i].x<<")"<<"--";
    }
    cout<<endl;
    cout<<"the form of packages is blow:"<<endl;

    for (int j = 0; j < num; ++j) {
        cout<<array[j].id<<"      ";
    }
    cout<<endl;
    for (int i = 0; i < num; ++i) {
        cout<<array[i].w<<"      ";
    }
    cout<<endl;
    for (int i = 0; i <num; ++i) {
        cout<<array[i].v<<"      ";
    }
    cout<<endl;
    for (int i = 0; i < num; ++i) {
        cout<<array[i].x<<"      ";
    }
}
int main()
{
    solution<float> test;
    test.greedy_solution();
    test.show();
    test.~solution();
}
//��������
//5 26
//5 6 9 3 5
//7 4 10 3 4