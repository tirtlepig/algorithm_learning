//
// Created by 86184 on 2020-12-09.
//
#include <iostream>
#include <stack>
#include <queue>
using namespace std;
#define Vnum 100
//������ڶ����ڽӱ�
typedef struct EdgeNode//�����ṹ
{
    int adjvex;//�ñ���ָ��Ķ�������
    struct EdgeNode *nextvex;//ָ����һ����
}*graphvex;
typedef struct//������ṹ
{
    int vertex;//������Ϣ
    struct EdgeNode *link;//ָ���һ�������ö���Ļ�
}VexNode;
int visted[Vnum]={0};
typedef VexNode adj_list[Vnum];
//���潨���ڽӱ�
void buildadjlist(adj_list &adjList,int n,int e)
{
    for (int i = 0; i < n; ++i)//��ʼ���ڽӱ�
    {
        adjList[i].vertex=i;
        adjList[i].link=NULL;
    }
    int i,j;//���嶥���
    for (int k = 0; k < e; ++k)//���붥���
    {
        cout<<"�����붥���:";
        cin>>i>>j;
        graphvex p=new EdgeNode;
        p->adjvex=j;
        p->nextvex=adjList[i].link;
        adjList[i].link=p;
        graphvex q=new EdgeNode;
        q->adjvex=i;
        q->nextvex=adjList[j].link;
        adjList[j].link=q;//�����ͽ�����������ͼ���α�����Ϊ����ͼ������֮ǰ�ı�������ǰ�������ͼ�ı�����ִ�е�
    }
}
//������ͼ�ı����㷨
//�����������
void dfsearch(adj_list adjList,int v0)//�ݹ��㷨
{
    cout<<"["<<v0<<"]";
    visted[v0]=1;
    graphvex p=adjList[v0].link;
    while (p!=NULL)
    {
        if (visted[p->adjvex]==0)
            dfsearch(adjList,p->adjvex);
        p=p->nextvex;
    }
}
void nrpdfsearch(adj_list adjList,int v0)//�ǵݹ��㷨
{
    stack<graphvex> assiststack;//��������ջ
    cout<<"["<<v0<<"]";
    visted[v0]=1;
    int num=0;//��������
    graphvex p=adjList[v0].link;
    while (p!=NULL||!assiststack.empty())
    {
        while (p!=NULL)
        {
            if (visted[p->adjvex]==1)
                p=p->nextvex;
            else
            {
                num=p->adjvex;
                cout<<"["<<num<<"]";
                visted[num]=1;
                assiststack.push(p);
                p=adjList[num].link;
            }
        }
        if (!assiststack.empty())
        {
            p=assiststack.top();
            assiststack.pop();
            p=p->nextvex;
        }
    }
}
//�����������
void bfsearch(adj_list adjList,int v0)
{
    queue<int> assistqueue;//������������
    int v=0;//��������
    visted[v0]=1;
    cout<<"["<<v0<<"]";
    graphvex p=new EdgeNode;
    p->nextvex=adjList[v0].link;
    do {
        while (p!=NULL)
        {
            v=p->adjvex;
            if (visted[v]==0)
            {
                cout<<"["<<v<<"]";
                assistqueue.push(v);
                visted[v]=1;
            }
            p=p->nextvex;
        }
        if (!assistqueue.empty())
        {
            v=assistqueue.front();
            assistqueue.pop();
            p=adjList[v].link;
        }
    }while ((p!=NULL)||(!assistqueue.empty()));
}
void count_component(adj_list adjList,int n) //��ͼ����ͨ������nΪ������
{
    int count=0;
    for (int i = 0; i <n ; ++i) {
        if (visted[i]==0)
        {
            cout<<"��ͨ����"<<count<<"�������¶���:";
            dfsearch(adjList,i);
            count++;
            cout<<endl;
        }
    }
    cout<<"����"<<count<<"����ͨ����"<<endl;
}
int main()
{
    VexNode adj_list[Vnum];
    int n,e;
    cout<<"�����붥�����ͱ���:";
    cin>>n>>e;
    buildadjlist(adj_list,n,e);
    int v0;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"������Ҫ�ı������:";
    cin>>v0;
    dfsearch(adj_list,v0);
    cout<<"����ͼ����������������ݹ��㷨��"<<endl;
    cout<<endl;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"������Ҫ����������:";
    cin>>v0;
    nrpdfsearch(adj_list,v0);
    cout<<"����ͼ�������������"<<endl;
    cout<<endl;
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    cout<<"������Ҫ����������:";
    cin>>v0;
    cout<<"����ͼ����ȹ������"<<endl;
    bfsearch(adj_list,v0);
    for (int i = 0; i < Vnum; i++)
    {
        visted[i] = 0;
    }
    count_component(adj_list,n);
    return 0;
}

