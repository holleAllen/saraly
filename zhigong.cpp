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
void read()    //读取文件
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

/*void write()   //写入文件
{
	将数组zggz[n]写入gz.dat文件并保存
}

void find()   //查询信息
{
	通过输入的工号实现查询;
}

void list()    //实现浏览
{
	在数组zggz[0]开始，浏览全部职工的信息
}

void modify()    //修改工资记录
{
	通过工号查询到相关信息
		调用grsds()计算个人所得税
}

void del()    //删除记录
{
	删除指定工号职工的记录
}

void add()    //添加信息
{
	添加职工信息到数组zggz末尾;
}

void grsds()
{
	计算个人所得税
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