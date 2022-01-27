#include<iostream>
#include<stack>
#include<cmath>
using namespace std;
typedef struct Node
{
	int data;
	struct Node *lchild;
	struct Node *rchild;
} *TreeNode;
void creatbitree(TreeNode &root)//����������
{
	int data;
	cin>>data;
	if(data==0)
	{	
		root=NULL;
	}
	else 
	{
		TreeNode q=new Node;
		q->data=data;
		q->lchild=NULL;
		q->rchild=NULL;
		root=q;
		creatbitree(root->lchild);
		creatbitree(root->rchild);//�ݹ鷽������������
	}
}

void preorder(TreeNode root)//�������
{
	if(root)
	{
		cout<<root->data<<" ";//�����������ֵ
		preorder(root->lchild);//����������
		preorder(root->rchild);//����������
	}
} 
void midorder(TreeNode root)//�������
{
	if(root)
	{
		midorder(root->lchild);//�ȱ���������
		cout<<root->data<<" ";//�ٱ������
		midorder(root->rchild);//������������
	}
}
void postorder(TreeNode root)//�������
{
	if(root)
	{
		postorder(root->lchild);//�ȱ���������
		postorder(root->rchild);//�ٱ���������
		cout<<root->data<<" ";//���������
	}	
} 
//����Ϊ�ǵݹ��㷨
void nrpreorder(TreeNode root)
{
	stack<TreeNode> assiststack;//��������ջ
	TreeNode p=new Node;//
	if(!root)
	{
		return;//����
	}
	else
	{
		p=root; 
	}
	do
	{
		while(p)
		{
			cout<<p->data<<" ";
			if(p->rchild)
			{
				assiststack.push(p->rchild);//�ҽ����ջ
			}
			p=p->lchild;
		}
		if(!assiststack.empty())//�ж�ջ�Ƿ�Ϊ��
		{
			p=assiststack.top();//ȡջ�׽��
			assiststack.pop();//��ջ
		}
	}while((!assiststack.empty())||(p!=NULL));
} 
void nrmidorder(TreeNode root)//�ǵݹ��������
{
	stack<TreeNode> assiststack;//����ջ
	TreeNode p=new Node;
	if(!root)
	{
		return;
	}
	else
	{
		p=root;
	}
	do
	{
		while(p)
		{
			assiststack.push(p);
			p=p->lchild;
		}
		if(!assiststack.empty())
		{
			p=assiststack.top();
			cout<<p->data<<" ";
			assiststack.pop();
			p=p->rchild;
		}
	}while((!assiststack.empty())||(p!=NULL));
}
void nrpostorder(TreeNode root)//�ǵݹ�������
{
	stack<TreeNode> assiststack1;//��������ջ1
	stack<int> assiststack2;//��������ջ2�������ж϶��ν�ջ
	TreeNode p=new Node;
	int k;//
	if(!root)
	{
		return;
	}
	else
	{
		p=root;
	}
	do
	{
//		if(t<0)
//		t=-t;
		while(p)
		{	
			assiststack1.push(p);
			assiststack2.push(::abs(p->data)); 
			p=p->lchild;
		}
		while((!assiststack1.empty())&&(p==NULL))
		{
			p=assiststack1.top();
			k=assiststack2.top();
			assiststack1.pop();
			assiststack2.pop();
			if(k>0)
			{
				assiststack1.push(p);
				assiststack2.push(-(p->data));
				p=p->rchild;		
			}
			else //�Ѿ����������ν�ջ������ֱ�����
			{
				cout<<p->data<<" ";
				p=NULL;
			}	
		} 
	}while((!assiststack1.empty())||(p!=NULL));
}
void leafnum(TreeNode root,int &num)//�ж�Ҷ�ӽ��ĸ���
{
    if (root!=NULL)
    {
        if (root->lchild==NULL&&root->rchild==NULL)
            num++;
        leafnum(root->lchild,num);
        leafnum(root->rchild,num);
    }
}
void depth_of_tree(TreeNode root,int k,int &h)
{
    if (root!=NULL)
    {
        k++;
        if (k>h)
            h=k;
        depth_of_tree(root->lchild,k,h);
        depth_of_tree(root->rchild,k,h);
    }
}
int main()
{
	TreeNode root=new Node;
	creatbitree(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	midorder(root);
	cout<<endl;
	postorder(root);
	cout<<endl<<"����Ϊ�ǵݹ��㷨����"<<endl;
	nrpreorder(root);
	cout<<endl;
	nrmidorder(root);
	cout<<endl;
	nrpostorder(root);
	cout<<endl;
	int num=0;
	cout<<"ͳ��Ҷ�ӽ�����"<<endl;
	leafnum(root,num);
	cout<<num<<endl;
	cout<<"������������"<<endl;
    int k=0;
    int h=0;
    depth_of_tree(root,k,h);
    cout<<h;
	return 0;
} 
//1 2 3 0 0 4 5 0 0 6 7 0 0 0 8 9 0 0 10 11 12 0 0 13 0 0 14 0 0