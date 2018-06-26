#include<stdlib.h>
#include<conio.h>
#include<iostream>
using namespace std;
void read();
void write(struct stu gx[],int out);
void find();
void modify();
void del();
void add();
void grsde();
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
/*void write()
{
	FILE *fp;
	int i;
	if((fp=fopen("gz5","wb"))==NULL)
	{
		cout<<"Cannot open file strike any key exit!";
		getch();
		exit(-1);
	}
	for(i=0;i<n;i++)
	{
		if(fwrite(p,sizeof(struct stu),1,fp)!=1)
		{	cout<<"文件读写错误";
		    fclose(fp);
		}
	}
}*/
void write(struct stu gx[],int out)
{
	FILE *fp;
	int i;
	if ((fp = fopen("gz5", "w")) == NULL)
	{
		printf("文件打开失败");
     	return;
	}
	if (out==0)
		{         printf("没有联系人可读");    }       //写入数据       
	for (i=0;i<out;i++)
	{      fprintf(fp, "%d\t", gx[i].num);
	       fprintf(fp, "%d\t", gx[i].name); 
		   fprintf(fp, "%d\t", gx[i].gangwei);
		   fprintf(fp, "%d\t", gx[i].xinji);
		   fprintf(fp, "%d\n", gx[i].jintie);
		   fprintf(fp, "%d\n", gx[i].jixiao);
		   fprintf(fp, "%d\n", gx[i].yingfa);
		   fprintf(fp, "%d\n", gx[i].gere);
		   fprintf(fp, "%d\n", gx[i].shifa);
	}
	       fclose(fp);
}

void find()
{
	int i;
	int flag=0;
	int j;
	int number;
	cout<<"请输入要查询员工的工号\n";
	cin>>number;
	for(i=0;i<n;i++)
	{	if(gx[i].num==number){
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<"工号 姓名 岗位工资 薪级工资 职位津贴 绩效 应发 个人所得税 实发\n";
		cout<<gx[i].num<<endl;
		cout<<gx[i].name<<endl;
	}
	for(j=i+1;j<n;j++)
	{
		if(gx[j].num==number)
		{
			cout<<gx[i].num<<endl;
		    cout<<gx[i].name<<endl;
		}
	}
	else
	{
		cout<<"没有找到该工号的员工\n";
	}
	system("pause");
}
void modify()
{}
void del()
{}
void add()
{}
void grsde()
{}
int main()
{
	int out;
	
	cout<<"                 员工管理系统                 \n";
	do{
		system("cls");
		cout<<"\n\n\n";
		cout<<"               ******              功能菜单选择           ******\n\n";
		cout<<"               ******           1、显示所有员工信息       ******\n";
		cout<<"               ******           2、保存员工信息           ******\n";
		cout<<"               ******           3、查找员工信息           ******\n";
		cout<<"               ******           4、修改员工信息           ******\n";
		cout<<"               ******           5、删除员工信息           ******\n";
		cout<<"               ******           6、添加员工信息           ******\n";
		cout<<"               ******           7、查看个人所得           ******\n";
		cout<<"               ******           0、退出程序               ******\n";
		cout<<"\n\n\n";
		cout<<"           请输入你的选择：\n";
		cin>>out;
		switch(out)
		{
        case 1:
            read();
			break;
		case 2:
			write(gx,out);
			break;
		case 3:
			find();
			break;
		case 4:
			modify();
			break;
		case 5:
			del();
			break;
		case 6:
			add();
			break;
		case 7:
			grsde();
			break;
		case 0:
			cout<<"\n谢谢使用！\n";
			return 0;
		default:
			cout<<"\n输入有误，请重新输入：";
			cin>>out;
			break;

		}
	}while(out!=-1);
	
	/*cout<<"工号"<<" "<<"姓名"<<" "<<"岗位工资"<<" "
		<<"薪级工资"<<" "<<"职务津贴"<<" "<<"绩效工资"<<" "
		<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资\n";
	//read();
	write();*/
	return 0;
}