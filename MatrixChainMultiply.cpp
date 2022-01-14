//
// Created by 86184 on 2021-06-22.
//
#include <iostream>

using namespace std;

struct TA
{
    long m;//��С�˷�������
    int k;//�ָ
    TA():k(0),m(0){}//��ʼ��
};

void matrixchain(int num,int r[],TA **A){
    for (int l = 1; l <=num; ++l) {
        A[l][l].m=0;//�ɿ�����һ���Խ���
        A[l][l].k=l;
    }
    for (int l = 2; l <=num ; ++l) {//�ӵڶ����Խ��߿�ʼ
        for (int i = 1; i <=num-l+1; ++i) {
            int j=i+(l-1);
            int kk=i;
            int m=A[i][i].m+A[i+1][j].m+r[i-1]*r[i]*r[j];
            //��������Сֵ
            for (int k=i+1;k<j;k++){
                long mm=A[i][k].m+A[k+1][j].m+r[i-1]*r[k]*r[j];
                if(mm<m)
                {
                    m=mm;
                    kk=k;
                }
            }
            A[i][j].m=m;
            A[i][j].k=kk;
        }
    }
}

void traceback(int i,int j,TA **A){
    if (i==j)
    {
        cout<<"A"<<i;
        return;
    }
    cout<<"(";
    traceback(i,A[i][j].k,A);
    traceback(A[i][j].k+1,j,A);
    cout<<")";
}

int main()
{
    int n=0;
    cout<<"�������������"<<endl;
    cin>>n;
    TA **A=new TA*[n+1];
    for (int i = 0; i <n ; ++i) {
        A[i]= new TA[n+1];
    }
    int *r=new int[n+1];
    cout<<"������"<<n+1<<"�������������"<<endl;
    for(int i=0;i<=n;i++)
    {
        cin>>r[i];
    }

    matrixchain(n,r,A);
    cout<<A[1][n].m<<endl;
    traceback(1,n,A);
}

//��������
//
// 6
//30 35 15 5 10 20 25
