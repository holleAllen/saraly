#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
struct member
{
	char num[20];
	char name[40];
    float gg;
    float xj;
    float jt;
    float jx;
    float yf;
    float gere;
    float sf;
}zggz[100];
void read();     
void write();
void find();
void find_num();
void modify();
void del();
void add();
void grsde();   //定义函数

int n=0;
void read()
{
	FILE *fp;
	int i;
    
	if((fp=fopen("gz5.dat","rb"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}
	for(i=0;i<5;i++)
	{
		fread(&zggz[100],sizeof(struct member),1,fp);
		n++ ; 
		/*cout<<" "<<p->num<<" "<<p->name<<" "<<p->gangwei<<" "
			     <<p->xinji<<" "<<p->jintie<<" "<<p->jixiao<<" "
				 <<p->yingfa<<" "<<p->gere<<" "<<p->shifa<<endl;
	}
	cout<<"               "<<"................共有"<<n<<"个人"<<endl;
	printf("            .......共有\n");*/   //这里有错！
	fclose(fp);
}
void write()
{
	int i;
	FILE*fp;
	if((fp=fopen("gz5.dat","wb"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}
	for(i<0;i<5;i++)
	{
		if(fwrite(&zggz[i],sizeof(struct member),1,fp)!=1)
		{	printf("文件读写错误\n");
		    fclose(fp);
		}
	}
}
void find()
{
	int t,kongzi;
	system("cls");
	do
	{
		printf("\n按1则按工号查询\n按2 回主菜单\n");
		scanf("%d,&t");
		if(t>=1&&t<=3)
		{
			kongzi=1;
			break;
		}
		else
		{
			kongzi=0;
			printf("输入错误");
		}
	}
	while(kongzi=0);
	while(kongzi=1)
	{
		switch(t)
		{
		case 1:printf("按工号查询\n");
			find_num();
			break;
		case 2:
			main();
			break;
		default:break;
			
		}
	}
}
void find_num()
{
	int num1;
	int i,t;
	printf("请输入要查找的职工号\n");
	scanf("%d,&num1");
	for(i<0;i<5;i++)
	{
		if(num1=zggz[i].num)
		{
			printf("工号  姓名  岗位工资  薪级工资  职位津贴  绩效工资  应发工资  所得税  实发工资\n");
			printf("\n %s%s %d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
			break;
		}
		else
		{
			printf("对不起，查无此人\n");
			printf("\n");
			printf("返回主菜单请按1，继续查询职工请按2\n");
			scanf("%d,&t");
			switch(t)
			{
			case 1:find_num();
				break;
			case 2:main();
				break;
			default:break;
			}
		}
	}

}

void add()
{
	 FILE*fp; 

  int n1; 


printf("原来的职工信息:\n"); 
  
    printf("\n"); 

     fp=fopen("gz5.dat","a"); 



   printf("\n 请输入新增加职工的信息:\n"); 

   printf("请输入职工号:  "); 

   scanf("%s",&zggz[i].num); 

   printf("\n"); 

         printf("请输入姓名:  "); 

      scanf("%s",&zggz[i].name); 

         getchar(); 

         printf("请输入岗位工资:  "); 

      scanf("\t%d",&zggz[i].gg); 

         printf("请输入薪级工资:  "); 

      scanf("%d",&zggz[i].xj); 

      printf("请输入津贴:  "); 

      scanf("%d",&zggz[i].jt); 

      printf("请输入绩效工资:  "); 

      scanf("\t%d",&zggz[i].jx); 

       printf("请输入应发工资:  "); 

      scanf("%d",&zggz[i].yf); 

       printf("请输入个人所得税:  "); 

      scanf("%d",&zggz[i].gere);  

       printf("请输入实发工资:  "); 

      scanf("%d",&zggz[i].sf); 
 

         printf("\n"); 


     printf("\n添加成功\n");  


  printf("\n增加后的所有职工信息:\n"); 

  printf("\n"); 

  write(); //直接保存

     list();//显示添加后的信息 

    fclose(fp); 

} 
}
void del()
{}
void modify()
{}
void grsde()
{}
int main()
{
	int count;
	
	printf("              欢迎使用职工工资管理系统！\n\n");
	do{
		system("cls");
	    printf("              ————————功能菜单选择   ————————\n");
    	printf("              ————————1、查询员工信息————————\n");
	    printf("              ————————2、修改员工信息————————\n");
    	printf("              ————————3、添加员工信息————————\n");
	    printf("              ————————4、删除员工信息————————\n");
	    printf("              ————————5、保存        ————————\n");
	    printf("              ————————6、浏览全部信息————————\n");
	    printf("              ————————7、退出        ————————\n");
	    printf("                请输入您的选择：\n");
	    scanf("%d,&count");
	    switch(count)
		{
        case 1:
            read();
			break;
		case 2:
			write();
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
			printf("\n谢谢使用！\n");
			return 0;
		default:
			printf("\n输入有误，请重新输入：");
			scanf("%d,&count");
			break;

		}
	}while(count!=-1);
	
	/*cout<<"工号"<<" "<<"姓名"<<" "<<"岗位工资"<<" "
		<<"薪级工资"<<" "<<"职务津贴"<<" "<<"绩效工资"<<" "
		<<"应发工资"<<" "<<"个人所得税"<<" "<<"实发工资\n";
	//read();
	write();*/
	return 0;
}

