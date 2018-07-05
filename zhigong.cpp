/**************************************************************************
 Copyright (C)
 File name: zhigong.cpp
 Author: 陈欢成  Version: 0.9   Date:2018.7.4 
 Description: 职工工资管理系统，用于管理职工工资，  
 Function List: 1、read函数，用于读取文件数据。
                2、write函数，用于保存文件数据。
				3、find函数，实现在文件中查询数据功能。
				4、add函数，添加职工信息等数据到文件中。
				5、del函数，删除文件中某员工的数据。
				6、modify函数，修改文件数据。
				7、list函数，浏览文件全部数据。
				8、grsds函数，计算个人所得税。
				9、main主函数，实现功能模块的选择。
 History: // 修改历史记录列表，每条修改记录应包括修改日期、修改
 // 者及修改内容简述
**************************************************************************/

#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct member{
	char num[20];
	char name[20];
    float gg;
    float xj;
    float jt;
    float jx;
    float yf;
    float gere;
    float sf;
}zggz[100];
void grsds();
void list();    //函数声明
int n = 0;        //全局变量n

int read()      //读取文件数据
{
	FILE *fp; 
	int i;
	if((fp=fopen("gz10.dat","rb"))==NULL)
	{
		printf("Cannot open file strike any key exit!\n");
		getch();
		exit(-1);
	}

	for(i = 0;i<100;i++)
	{
		
		fread(&zggz[i],sizeof(struct member),1,fp);	
		grsds();    //调用grsds函数计算个人所得税及应发实发工资情况
		if(feof(fp))	
		break;
		n++ ;
	}

	fclose(fp);
	return 0;
}

void write()    //保存数据
{
	int i;
	FILE*fp;
	if((fp=fopen("gz10.dat","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}

	for(i = 0;i<n;i++)
	{
		fwrite(&zggz[i],sizeof(struct member),1,fp);  
	}

	fclose(fp);
}

void find()    //实现查询职工信息功能
{
	char num1[20];
	int i;
	int flag=0;
	printf("请输入要查找的工号(1001~1100)：\n");
	scanf("%s",num1);
	for(i = 0;i<n;i++)
	{
		if(strcmp(num1,zggz[i].num)==0)
		{   flag = 1;
			printf("工号  姓名   岗位工资  薪级工资  职位津贴  绩效工资  应发工资  所得税  实发工资\n");
			printf("\n %s %s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num, zggz[i].name, zggz[i].gg,
				zggz[i].xj, zggz[i].jt, zggz[i].xj, zggz[i].yf, zggz[i].gere, zggz[i].sf);
		
			printf("\n\n");
			break;
		}
	}

	if(flag==0)
		{	
			printf("对不起，查无此人\n");
			printf("\n");
			printf("请重新输入:\n");
			find();
		}				
}

void add()    //添加职工数据到文件
{
    printf("\n"); 
	printf("\n             请输入新增加职工的信息:\n"); 
    printf("请输入职工号:  "); 
    scanf("%s",zggz[n].num); 
	getchar();
    printf("\n"); 
    printf("请输入姓名:  "); 
    scanf("%s",zggz[n].name); 
	getchar(); 
	printf("请输入岗位工资:  "); 
    scanf("%f",&zggz[n].gg);
	printf("请输入薪级工资:  "); 
	scanf("%f",&zggz[n].xj);
	printf("请输入津贴:  "); 
	scanf("%f",&zggz[n].jt);
	printf("请输入绩效工资:  "); 
	scanf("%f",&zggz[n].jx);
	printf("\n"); 
	printf("添加成功并保存\n");  
	n++;
	printf("\n"); 
	grsds();
	write(); //直接保存 
}

void del()    //删除文件中指定职工数据
{	
	int put = n;
	int i, j, k, t, kongzi;
	char name[20];
	printf("按姓名删除\n");
	scanf("%s",name);
	for(kongzi = 1, i = 0;kongzi&&i<put;i++)
	{
		if(strcmp(zggz[i].name,name)==0)
		{
			printf("此人原始记录为：\n");
			printf("工号  姓名   岗位工资  薪级工资  职位津贴  绩效工资  应发工资  所得税  实发工资\n");
			printf("\n %s %s    %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num,    zggz[i].name,   
				zggz[i].gg,   zggz[i].xj,   zggz[i].jt,   zggz[i].xj,   zggz[i].yf,   zggz[i].gere, 
				zggz[i].sf);
			printf("\n确认删除请按1，返回请按0\n");
			scanf("%d",&k);
			    if(k==1)
				{
					for(j=i;j<n-1;j++)
					{
						strcpy(zggz[j].num,zggz[j+1].num);
						strcpy(zggz[j].name,zggz[j+1].name);
							   zggz[j].gg=zggz[j+1].gg;
							   zggz[j].xj=zggz[j+1].xj;
							   zggz[j].jt=zggz[j+1].jt;
							   zggz[j].jx=zggz[j+1].jx;
							   zggz[j].yf=zggz[j+1].yf;
							   zggz[j].gere=zggz[j+1].gere;
							   zggz[j].sf=zggz[j+1].sf;
					}

					printf("删除成功！\n");
					kongzi=0;
				}
		}
	}

	if(!kongzi)
		n=n-1;
	else
	{
		printf("查无此人...\n");
		printf("继续删除请按1，不再删除请按0\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:del();
			break;
		default:
			break;
		}
	}
	
}

void modify()    //修改文件中职工信息
{

	int i;
	int flag = 0;
	char num2[20];
	printf("请输入要修改的职工工号(1001~1100)：\n");
	scanf("%s",num2);
	for(i = 0;i<n;i++)
	{
		if(strcmp(zggz[i].num,num2)==0)  
		{
			flag=1;
			printf("修改后的姓名为：");
			scanf("%s",zggz[i].name);
			printf("修改后的岗位工资为：");
			scanf("%f",&zggz[i].gg);
			printf("修改后的薪级工资为：");
			scanf("%f",&zggz[i].xj);
			printf("修改后的职务津贴为：");
			scanf("%f",&zggz[i].jt);
			printf("修改后的效绩工资为：");
			scanf("%f",&zggz[i].xj);
			printf("修改成功！\n");
			
		}	
	}
	grsds();

	if(flag==0)
		{
			printf("\n");
			printf("输入错误，请重新输入：\n\n");
			modify();
		}

}

void list()    //浏览文件全部数据
{
	int i;
	printf("工号  姓名   岗位工资  薪级工资  职位津贴  绩效工资  应发工资  所得税  实发工资\n");
	for(i = 0;i<n;i++)
	{
		printf("\n %s %s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num, zggz[i].name, zggz[i].gg,
			zggz[i].xj,	zggz[i].jt, zggz[i].xj, zggz[i].yf, zggz[i].gere, zggz[i].sf);
	}

	printf("\n");
}

void grsds()    //计算个人所得税
{  
	int i;
	for(i = 0;i<n;i++)
	{
		zggz[i].yf=zggz[i].gg+zggz[i].xj+zggz[i].jt+zggz[i].jx;
		if(zggz[i].yf<500)
		{
			zggz[i].gere=zggz[i].yf*0.05;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=500&&zggz[i].yf<2000)
		{
			zggz[i].gere=500*0.05+(zggz[i].yf-500)*0.1;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=2000&&zggz[i].yf<5000)
		{
			zggz[i].gere=500*0.05+1500*0.1+(zggz[i].yf-2000)*0.15;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=5000&&zggz[i].yf<20000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+(zggz[i].yf-5000)*0.2;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=20000&&zggz[i].yf<40000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+(zggz[i].yf-20000)*0.25;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=40000&&zggz[i].yf<60000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25
				      +(zggz[i].yf-40000)*0.3;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=60000&&zggz[i].yf<80000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25
				      +20000*0.3+(zggz[i].yf-60000)*0.35;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>=80000&&zggz[i].yf<100000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25
				      +20000*0.3+20000*0.35+(zggz[i].yf-80000)*0.4;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		else if(zggz[i].yf>100000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25
				      +20000*0.3+20000*0.35+20000*0.4+(zggz[i].yf-100000)*0.45;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}

		write();    //直接保存
	}
}

int main()    //主函数实现连接各模块功能
{
	int count;
	read();
	printf("\n\n");
	printf("      ###  欢迎使用广西民族大学软件与信息安全学院职工工资管理系统！  ###\n\n");
	printf("\n");
	do{
	    printf("          请选择<1 - 7>:\n");
		printf("      ===================================================================\n");
    	printf("      |            1、查询职工工资信息                                  |\n");
	    printf("      |            2、修改职工工资信息                                  |\n");
    	printf("      |            3、添加职工工资信息                                  |\n");
	    printf("      |            4、删除职工工资信息                                  |\n");
	    printf("      |            5、保存数据到文件                                    |\n");
	    printf("      |            6、浏览职工记录                                      |\n");
	    printf("      |            7、退出系统                                          |\n");
		printf("      ===================================================================");
		printf("\n");
		printf("注：    确认完成后请保存！\n");
		printf("        请输入您的选择：\n");
	    scanf("%d",&count);
	    switch(count)
		{
        case 1:
            find();
			break;
		case 2:
			modify();
			break;
		case 3:
			add();
			break;
		case 4:
			del();
			break;
		case 5:
			write();
			printf("保存成功！\n");
			break;
		case 6:
			list();
			break;
		case 7:
			printf("\n谢谢使用！\n");
			return 0;
		default:
			printf("\n输入有误，请重新输入");
			break;
		}
	}while(count!=-1);
	
	return 0;
}

