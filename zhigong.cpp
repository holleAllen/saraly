/**************************************************************************
 Copyright (C)
 File name: zhigong.cpp
 Author: �»���  Version: 0.9   Date:2018.7.4 
 Description: ְ�����ʹ���ϵͳ�����ڹ���ְ�����ʣ�  
 Function List: 1��read���������ڶ�ȡ�ļ����ݡ�
                2��write���������ڱ����ļ����ݡ�
				3��find������ʵ�����ļ��в�ѯ���ݹ��ܡ�
				4��add���������ְ����Ϣ�����ݵ��ļ��С�
				5��del������ɾ���ļ���ĳԱ�������ݡ�
				6��modify�������޸��ļ����ݡ�
				7��list����������ļ�ȫ�����ݡ�
				8��grsds�����������������˰��
				9��main��������ʵ�ֹ���ģ���ѡ��
 History: // �޸���ʷ��¼�б�ÿ���޸ļ�¼Ӧ�����޸����ڡ��޸�
 // �߼��޸����ݼ���
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
void list();    //��������
int n = 0;        //ȫ�ֱ���n

int read()      //��ȡ�ļ�����
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
		grsds();    //����grsds���������������˰��Ӧ��ʵ���������
		if(feof(fp))	
		break;
		n++ ;
	}

	fclose(fp);
	return 0;
}

void write()    //��������
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

void find()    //ʵ�ֲ�ѯְ����Ϣ����
{
	char num1[20];
	int i;
	int flag=0;
	printf("������Ҫ���ҵĹ���(1001~1100)��\n");
	scanf("%s",num1);
	for(i = 0;i<n;i++)
	{
		if(strcmp(num1,zggz[i].num)==0)
		{   flag = 1;
			printf("����  ����   ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
			printf("\n %s %s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num, zggz[i].name, zggz[i].gg,
				zggz[i].xj, zggz[i].jt, zggz[i].xj, zggz[i].yf, zggz[i].gere, zggz[i].sf);
		
			printf("\n\n");
			break;
		}
	}

	if(flag==0)
		{	
			printf("�Բ��𣬲��޴���\n");
			printf("\n");
			printf("����������:\n");
			find();
		}				
}

void add()    //���ְ�����ݵ��ļ�
{
    printf("\n"); 
	printf("\n             ������������ְ������Ϣ:\n"); 
    printf("������ְ����:  "); 
    scanf("%s",zggz[n].num); 
	getchar();
    printf("\n"); 
    printf("����������:  "); 
    scanf("%s",zggz[n].name); 
	getchar(); 
	printf("�������λ����:  "); 
    scanf("%f",&zggz[n].gg);
	printf("������н������:  "); 
	scanf("%f",&zggz[n].xj);
	printf("���������:  "); 
	scanf("%f",&zggz[n].jt);
	printf("�����뼨Ч����:  "); 
	scanf("%f",&zggz[n].jx);
	printf("\n"); 
	printf("��ӳɹ�������\n");  
	n++;
	printf("\n"); 
	grsds();
	write(); //ֱ�ӱ��� 
}

void del()    //ɾ���ļ���ָ��ְ������
{	
	int put = n;
	int i, j, k, t, kongzi;
	char name[20];
	printf("������ɾ��\n");
	scanf("%s",name);
	for(kongzi = 1, i = 0;kongzi&&i<put;i++)
	{
		if(strcmp(zggz[i].name,name)==0)
		{
			printf("����ԭʼ��¼Ϊ��\n");
			printf("����  ����   ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
			printf("\n %s %s    %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num,    zggz[i].name,   
				zggz[i].gg,   zggz[i].xj,   zggz[i].jt,   zggz[i].xj,   zggz[i].yf,   zggz[i].gere, 
				zggz[i].sf);
			printf("\nȷ��ɾ���밴1�������밴0\n");
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

					printf("ɾ���ɹ���\n");
					kongzi=0;
				}
		}
	}

	if(!kongzi)
		n=n-1;
	else
	{
		printf("���޴���...\n");
		printf("����ɾ���밴1������ɾ���밴0\n");
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

void modify()    //�޸��ļ���ְ����Ϣ
{

	int i;
	int flag = 0;
	char num2[20];
	printf("������Ҫ�޸ĵ�ְ������(1001~1100)��\n");
	scanf("%s",num2);
	for(i = 0;i<n;i++)
	{
		if(strcmp(zggz[i].num,num2)==0)  
		{
			flag=1;
			printf("�޸ĺ������Ϊ��");
			scanf("%s",zggz[i].name);
			printf("�޸ĺ�ĸ�λ����Ϊ��");
			scanf("%f",&zggz[i].gg);
			printf("�޸ĺ��н������Ϊ��");
			scanf("%f",&zggz[i].xj);
			printf("�޸ĺ��ְ�����Ϊ��");
			scanf("%f",&zggz[i].jt);
			printf("�޸ĺ��Ч������Ϊ��");
			scanf("%f",&zggz[i].xj);
			printf("�޸ĳɹ���\n");
			
		}	
	}
	grsds();

	if(flag==0)
		{
			printf("\n");
			printf("����������������룺\n\n");
			modify();
		}

}

void list()    //����ļ�ȫ������
{
	int i;
	printf("����  ����   ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
	for(i = 0;i<n;i++)
	{
		printf("\n %s %s %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f %8.2f", zggz[i].num, zggz[i].name, zggz[i].gg,
			zggz[i].xj,	zggz[i].jt, zggz[i].xj, zggz[i].yf, zggz[i].gere, zggz[i].sf);
	}

	printf("\n");
}

void grsds()    //�����������˰
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

		write();    //ֱ�ӱ���
	}
}

int main()    //������ʵ�����Ӹ�ģ�鹦��
{
	int count;
	read();
	printf("\n\n");
	printf("      ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ��  ###\n\n");
	printf("\n");
	do{
	    printf("          ��ѡ��<1 - 7>:\n");
		printf("      ===================================================================\n");
    	printf("      |            1����ѯְ��������Ϣ                                  |\n");
	    printf("      |            2���޸�ְ��������Ϣ                                  |\n");
    	printf("      |            3�����ְ��������Ϣ                                  |\n");
	    printf("      |            4��ɾ��ְ��������Ϣ                                  |\n");
	    printf("      |            5���������ݵ��ļ�                                    |\n");
	    printf("      |            6�����ְ����¼                                      |\n");
	    printf("      |            7���˳�ϵͳ                                          |\n");
		printf("      ===================================================================");
		printf("\n");
		printf("ע��    ȷ����ɺ��뱣�棡\n");
		printf("        ����������ѡ��\n");
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
			printf("����ɹ���\n");
			break;
		case 6:
			list();
			break;
		case 7:
			printf("\nллʹ�ã�\n");
			return 0;
		default:
			printf("\n������������������");
			break;
		}
	}while(count!=-1);
	
	return 0;
}

