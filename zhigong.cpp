#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
struct company{
	char num[20];
	char name[40];
    float post;
    float xinji;
    float allowance;
    float jixiao;
    float yingfa;
    float gere;
    float shifa;
}staff[100],*sta;
void read()    //��ȡ�ļ�
{
	int i=1;
	FILE *fp;
	sta=staff;
	if((fp=fopen("gz1.dat","rt"))==NULL){
		cout<<"\nCannot open file strike any key exit!";
		getch();
		exit(-1);
	}
	
	fread(sta,sizeof(struct company),5,fp);
	for(i=1;)
	fclose(fp);
	cout<<"\n";

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
	read();
	return 0;
}