#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
typedef struct infromationNode
{
    string phonenum;
    string name;
    string address;
    struct infromationNode *next;
} *Pointer;
int Hash(string phonenum)//hash����
{
    int sum=0;
    for (int i = 0; i < 11; ++i)
    {
        sum+=phonenum[i];//11λ�����
    }
    int address=sum%7;//ģ7ȡ��
    return address;//����hash��ַ
}
Pointer Hashsearch(Pointer link_list[],string phonenum)
{
    int hashaddress;
    hashaddress=Hash(phonenum);
    Pointer p=link_list[hashaddress];
    while (p!=NULL&&p->phonenum!=phonenum)
    {
        p=p->next;
    }
    return p;
}
void Hashdelet(Pointer link_list[],string phonenum)
{
    int hashaddress=Hash(phonenum);
    Pointer s=link_list[hashaddress];
    if (s==NULL)
    {
        cout<<"����Ϣ������"<<endl;
        return;
    }
    else
    {
        Pointer p=new infromationNode;//pΪs��ǰһ�����
        p=NULL;
        while (s->phonenum!=phonenum&&s->next!=NULL)
        {
            p=s;
            s=s->next;
        }
        if (s->phonenum==phonenum)
        {
            if (p==NULL)//s���������еĵ�һ�����
            {
                link_list[hashaddress]=s->next;
            }
            else
            {
                p->next=s->next;
            }
            delete s;
            cout<<"��ϵ��ɾ���ɹ�"<<endl;
        }
        else
            cout<<"����Ϣ������"<<endl;
    }
}
void Hashinsert(Pointer link_list[],string phonenum)
{
    int hashaddress=Hash(phonenum);
    Pointer s=link_list[hashaddress];
    if (s==NULL)
    {
        Pointer information=new infromationNode;
        information->phonenum=phonenum;
        cout<<"������������Ϣ"<<endl;
        string name;
        cin>>name;
        information->name=name;
        cout<<"�������ַ��Ϣ"<<endl;
        string address;
        cin>>address;
        information->address=address;
        information->next=NULL;
        link_list[hashaddress]=information;
        cout<<"�µ���ϵ�˴����ɹ�"<<endl;
    }
    else
    {
        while (s->phonenum!=phonenum&&s->next!=NULL)
        {
            s=s->next;
        }
        if (s->phonenum==phonenum)
        {
            cout<<"����Ϣ�Ѵ���"<<endl;
            return;
        }
        else
        {
            Pointer information=new infromationNode;
            information->phonenum=phonenum;
            cout<<"������������Ϣ"<<endl;
            string name;
            cin>>name;
            information->name=name;
            cout<<"�������ַ��Ϣ"<<endl;
            string address;
            cin>>address;
            information->address=address;
            information->next=NULL;
            cout<<"�µ���ϵ�˴����ɹ�"<<endl;
            s->next=information;
        }
    }
}
void creathashtable(Pointer link_list[])//��ȡ�����ļ�����hash��
{
    ifstream in;
    in.open("Phonenuminforamtion.txt",ios::in);
    if(!in.is_open())
    {
        cout<<"�ļ���ʧ��"<<endl;
        return;
    }
    string strOne;
    while (getline(in,strOne))
    {
        stringstream information;
        information<< strOne;
        string name;
        string phonenum;
        string address;
        information>>name>>phonenum>>address;
        Pointer q=new infromationNode;
        q->name=name;
        q->phonenum=phonenum;
        q->address=address;
        q->next=NULL;
        Pointer p=link_list[Hash(phonenum)];
        while (p->next!=NULL)
            p=p->next;
        p->next=q;
    }
    in.close();
}
void savedata(Pointer link_list[])//��hash������ļ�
{
    ofstream out;
    out.open("Phonenuminforamtion.txt", ios::trunc);
    if (!out.is_open())
    {
        cout<<"���ļ�ʧ��"<<endl;
        return;
    }

    for (int i = 0; i < 8; i++)
    {
        Pointer p = link_list[i];
        p=p->next;
        while (p!= NULL)
        {
            out<< p->name<< "\t" << p->phonenum<<"\t "<< p->address<<"\n";
            p=p->next;
        }
    }
    out.close();
}
void printhash(Pointer link_list[])//��ӡ��ϣ��
{
    for (int i = 0; i < 8; i++)
    {
        Pointer p = link_list[i];
        p = p->next;
        while (p != NULL)
        {
            cout <<"����:"<<p->name<<",�绰����:"<< p->phonenum <<",��ַ:"<<p->address<<";"<<endl;
            p = p->next;
        }
    }
}
int main()
{
    Pointer link_list[8];
    for (int i = 0; i < 8; ++i)
    {
        Pointer p=new infromationNode;
        p->next=NULL;
        link_list[i]=p;
    }//��ʼ��
    creathashtable(link_list);
    while (true)
    {
        meau:
        cout << "��ӭʹ�õ绰�����ѯϵͳ"<<endl;
        cout << "-------------------------" << endl;
        cout << "��������ϣ�����еĲ���"<<endl;
        cout << "1.��ӡ��ϣ��" << endl;
        cout << "2.����Ԫ��" << endl;
        cout << "3.����Ԫ��" << endl;
        cout << "4.ɾ��Ԫ��" << endl;
        cout << "5.�˳�ϵͳ�������޸�" << endl;
        cout << "6.�˳�ϵͳ�������޸�" << endl;
        cout << "-------------------------" << endl;
        int num;
        cin>>num;
        switch (num)
        {
            case 1:
            {
                printhash(link_list);
                break;
            }
            case 2:
            {
                cout<<"������Ҫ���ҵĵ绰����"<<endl;
                string phonenum;
                cin>>phonenum;
                Pointer result=Hashsearch(link_list,phonenum);
                if (result==NULL)
                    cout<<"��Ч�ĵ绰���룬�˺��벻����"<<endl;
                else
                {
                    cout <<"����:"<<result->name<<",�绰����:"<<result->phonenum <<",��ַ:"<<result->address<<";"<<endl;
                }
                break;
            }
            case 3:
            {
                cout<<"������Ҫ����ĵ绰����"<<endl;
                string phonenum;
                cin>>phonenum;
                Hashinsert(link_list,phonenum);
                break;
            }
            case 4:
            {
                cout<<"������Ҫɾ���ĵ绰����"<<endl;
                string phonenum;
                cin>>phonenum;
                Hashdelet(link_list,phonenum);
                break;
            }
            case 5:
            {
                savedata(link_list);
                cout<<"�ļ�����ɹ�"<<endl;
                return 0;
            }
            case 6:
            {
                cout<<"�ɹ��˳���ллʹ��"<<endl;
                return 0;
            }
            default:cout<<"��Ч�����룬������"<<endl;
                goto meau;
        }
    }
}