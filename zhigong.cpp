#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct stu{
	char num[20];
	char name[40];
    float gangwei;
    float xinji;
    float jintie;
    float jixiao;
    float yingfa;
    float gere;
    float shifa;
}gx[100],*p;
int n=0;
void read()          //��ȡְ����������
{
	FILE *fp;
	int i;
    p=gx;
	if((fp=fopen("gz5","rb"))==NULL)
	{
		cout<<"Cannot open file strike any key exit!";
		getch();
		exit(-1);
	}
	for(i=0;i<52;i++,p++)
	{
		fread(p,sizeof(struct stu),52,fp);
		n++ ; 
		cout<<" "<<p->num<<" "<<p->name<<" "<<p->gangwei<<" "
			     <<p->xinji<<" "<<p->jintie<<" "<<p->jixiao<<" "
				 <<p->yingfa<<" "<<p->gere<<" "<<p->shifa<<endl;
	}
	cout<<"               "<<"................����"<<n<<"����"<<endl;
	fclose(fp);

}
void write()
{

}

/*void write()   //д���ļ�
{
	������zggz[n]д��gz.dat�ļ�������
}

void find()   //��ѯ��Ϣ
{
	ͨ������Ĺ���ʵ�ֲ�ѯ;
}

void list()    //ʵ�����
{
	������zggz[0]��ʼ�����ȫ��ְ������Ϣ
}

void modify()    //�޸Ĺ��ʼ�¼
{
	ͨ�����Ų�ѯ�������Ϣ
		����grsds()�����������˰
}

void del()    //ɾ����¼
{
	ɾ��ָ������ְ���ļ�¼
}

void add()    //�����Ϣ
{
	���ְ����Ϣ������zggzĩβ;
}

void grsds()
{
	�����������˰
}

int main()
{
	void read();
	void write();
	void find();
	void list();
	void modify();
	void del();
	void add();
	void grsds();

}*/
int main()
{
	
	cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "
		<<"н������"<<" "<<"ְ�����"<<" "<<"��Ч����"<<" "
		<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������\n";
	read();
	return 0;
}