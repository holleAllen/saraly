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
void read()          //读取职工工资数据
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
	cout<<"               "<<"................共有"<<n<<"个人"<<endl;
	fclose(fp);

}
void write()
{

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
	
	cout<<"工号"<<" "<<"姓名"<<" "<<"岗位工资"<<" "
		<<"薪级工资"<<" "<<"职务津贴"<<" "<<"绩效工资"<<" "
		<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资\n";
	read();
	return 0;
}