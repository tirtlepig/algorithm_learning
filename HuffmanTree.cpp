//
// Created by 86184 on 2021-06-23.
//
#include <iostream>
#include<algorithm>
#include<fstream>
#include<queue>
#include<functional>
#include<string>
#include<vector>
#include <sstream>

using namespace std;
struct TN
{
    char c;
    int f;
    int idx;//���Ա���λ���������
    int p;//�������Ա��еı��
    int l, r;//���ҽڵ��������
    TN() :p(-1), l(-1), r(-1) {}
};
struct CN
{
    char c;//�ַ�
    int num;//����
    int len;//���볤��
    CN() :num(0), len(0) {}
};
class CHuffman
{
public:
    CHuffman();
    ~CHuffman();
    CHuffman(char *c); //���ļ�����Ϊ���캯���Ĳ���
    void CreateTree();//���ɱ�����
    void OutputTree();//��ӡ������
    void OutputCode();//��ӡ����
    void XCode();//Huffman����
    //void DeCode(int b[], int m);
    void INCH() { h_c = new CN[260]; h_n = h_sum = 0; }//��ʼ�� ���256��ASCII��
    int printCode(TN node);//��ӡĳ���ַ��ı���
    void OutputInformation();
private:
    TN *h_t;//���Ա�
    int h_n;//�ַ��������
    int h_sum;//�ַ��ܸ���
    CN *h_c;//ͳ���ַ����������
};
CHuffman::CHuffman() {}
CHuffman::~CHuffman()
{
    delete[]h_t;
    delete[]h_c;
}
bool operator>(const TN &x, const TN &y) { return x.f > y.f; }
void CHuffman::XCode()
{
    h_t = new TN[2 * h_n];//n���ַ�����2n-1�����
    for (int i = 0; i < h_n; i++)//��ʼ������
    {
        h_t[i].c = h_c[i + 1].c;
        h_t[i].f = h_c[i + 1].num;
        h_t[i].idx = i;
        //����c,f,idx
    }
    std::priority_queue<TN, std::vector<TN>, std::greater<TN> >PQ;//���ȶ���
    for (int i = 0; i < h_n; i++)
    {
        PQ.push(h_t[i]);
    }
    int next = h_n;//��һ��Ҫ���ɵĽڵ�
    while (!PQ.empty())
    {
        TN l = PQ.top();
        PQ.pop();
        TN r = PQ.top();
        PQ.pop();
        TN p;
        p.l = l.idx; p.r = r.idx;
        p.f = l.f + r.f;
        p.idx = next;
        h_t[next] = p;
        h_t[l.idx].p = h_t[r.idx].p = next;
        PQ.push(p);
        next++;
        if (next == 2 * h_n - 1) { break; }
    }
}
int CHuffman::printCode(TN node)
{
    cout << "(" << node.c << ":";
    std::vector<int> v;
    while (node.p != -1)
    {
        if (node.idx == h_t[node.p].l)//������
        {
            v.push_back(0);
        }
        else
        {
            v.push_back(1);
        }
        node = h_t[node.p];
    }
    int cc = v.size();
    for (int k = v.size() - 1; k >= 0; k--)
    {
        cout << v[k];
    }
    cout << ") ";
    return cc;
}
CHuffman::CHuffman(char *c)
{
    INCH();
    int n(0);//���б�־����Ϊ1����Ϊ0

    ifstream fin("C:/Users/86184/Desktop/test.txt", ios::in);
    if (!fin)
    {
        cout << "File open error!\n";
        return;
    }
    char ch;
    while ((ch = fin.get()) != EOF)
    {
        //cout << ch;
        h_sum++;
        for (int i = 1; i <= h_n; i++)
        {
            if (h_c[i].c == ch)//ƥ���ַ�
            {
                h_c[i].num++;
                n = 1;
                i = h_n + 1;//����ѭ��
            }
        }
        if (n == 0)
        {
            h_n++;
            h_c[h_n].c = ch;//���ַ�
            h_c[h_n].num++;
        }
        else
        {
            n = 0;
        }

    }
    //cout << endl;
    cout<<"�������ַ�ͳ������:"<<endl;
    cout << "�ַ�����Ϊ: " << h_n <<"��"<< endl;
    cout << "�ַ�����Ϊ:" << h_sum << endl;
    cout << "(char,frequency):" << endl;
    int j = 0;
    for (int i = 1; i <= h_n; i++)
    {
        j++;
        cout << " (" << h_c[i].c << "," << h_c[i].num << ")";
        if (j == 10) { cout << endl; j = 0; }
    }
    cout << endl;
    fin.close();
}
void CHuffman::OutputCode()
{
    int j = 0;
    for (int i = 0; i < h_n; i++)
    {
        j++;
        h_c[i + 1].len = printCode(h_t[i]);
        if (j == 10) { cout << endl; j = 0; }
    }
    cout << endl;
}
void CHuffman::OutputInformation()
{
    float lv(0);
    for (int i = 1; i <= h_n; i++)
    {
        lv = lv + float(h_c[i].num)*h_c[i].len / h_sum;
    }
    cout << "ƽ�����������볤��Ϊ:" << lv << endl;
}

int main(void)
{
    char c[] = "C:/Users/86184/Desktop/test.txt";
    CHuffman  hm(c);
    hm.XCode();
    cout << endl;
    cout << "�����ǹ���������:" << endl;
    hm.OutputCode();
    cout << endl;
    cout << "�����ǹ������������Ϣ:" << endl;
    hm.OutputInformation();

}
