#include<stdio.h>
#include<conio.h>
#include<string.h>
#include<iostream>
using namespace std;
struct member{
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
void list();
void grsde();   //��������
int n=0;
void read()
{
	FILE *fp;
	int i;
    
	if((fp=fopen("gz10.dat","rb"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}
	for(i=0;i<3;i++)
	{
		fread(&zggz[3],sizeof(struct member),3,fp);
		n++ ; 
		/*cout<<" "<<p->num<<" "<<p->name<<" "<<p->gangwei<<" "
			     <<p->xinji<<" "<<p->jintie<<" "<<p->jixiao<<" "
				 <<p->yingfa<<" "<<p->gere<<" "<<p->shifa<<endl;
	}
	cout<<"               "<<"................����"<<n<<"����"<<endl;
	printf("            .......����\n");*/  //�����д�
	}
	fclose(fp);
}
void write()
{
	int i;
	FILE*fp;
	if((fp=fopen("gz10.dat","wb"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}
	for(i=0;i<3;i++)
	{
		if(fwrite(&zggz[i],sizeof(struct member),3,fp)!=1)
		{	printf("�ļ���д����\n");
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
		printf("\n��1�򰴹��Ų�ѯ\n��2 ����\n");
		scanf("%d",&t);
		if(t>=1&&t<=3)
		{
			kongzi=1;
			break;
		}
		else
		{
			kongzi=0;
			printf("�������");
			find();	
		}
	}
	while(kongzi=2);
	while(kongzi=1)
	{
		switch(t)
		{
		case 1:printf("�����Ų�ѯ\n");
			find_num();
			break;
		case 2:
		//	main();
			break;
		default:break;
			
		}
	}
}
void find_num()
{
	char num1[20];
	int i,t;
	printf("������Ҫ���ҵ�ְ����\n");
	scanf("%s",&num1);
	for(i=0;i<3;i++)
	{
		if(strcmp(num1,zggz[i].num)==0)
		{
			printf("����  ����  ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
			printf("\n %s%s %d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
			break;
		}
		else
		{
			printf("�Բ��𣬲��޴���\n");
			printf("\n");
			printf("������ѯְ���밴1���������˵��밴2\n");
			scanf("%d",&t);
			switch(t)
			{
			case 1:find_num();
				break;
			case 2:
				find();
				break;
			default:break;
			}
		}
	}

}
void add()
{
	FILE*fp; 
    //int n1; 
    printf("ԭ����ְ����Ϣ:\n");
    printf("\n"); 
    fp=fopen("gz10.dat","a"); 
	printf("\n ������������ְ������Ϣ:\n"); 

    printf("������ְ����:  "); 
    scanf("%s",&zggz[n+1].num); 
    printf("\n"); 
    printf("����������:  "); 
    scanf("%s",&zggz[n+1].name); 

	getchar(); 

	printf("�������λ����:  "); 
    scanf("\t%d",&zggz[n+1].gg);
	printf("������н������:  "); 
	scanf("%d",&zggz[n+1].xj);
	printf("���������:  "); 
	scanf("%d",&zggz[n+1].jt);
	printf("�����뼨Ч����:  "); 
	scanf("\t%d",&zggz[n+1].jx);
	printf("������Ӧ������:  "); 
	scanf("%d",&zggz[n+1].yf);
	printf("�������������˰:  "); 
	scanf("%d",&zggz[n+1].gere);  
	printf("������ʵ������:  "); 
	scanf("%d",&zggz[n+1].sf); 
	
	printf("\n"); 
	printf("\n��ӳɹ�\n");  
	printf("\n���Ӻ������ְ����Ϣ:\n"); 
	printf("\n"); 
	write(); //ֱ�ӱ���
	list();//��ʾ��Ӻ����Ϣ 

    fclose(fp); 
}
void del()
{
	int put=n;
	int i,j,k,t,kongzi;
	char name[20];
	printf("������ɾ��\n");
	scanf("%s",name);
	for(kongzi=1,i=0;kongzi&&i<put;i++)
	{
		if(strcmp(zggz[i].name,name)==0)
		{
			printf("����ԭʼ��¼Ϊ��\n");
			printf("����  ����  ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
			printf("\n %s%s %d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
			printf("ȷ��ɾ���밴1�������밴0\n");
			scanf("%d",&k);
			    if(k==1)
				{
					for(j=i;j<n-1;j++)
					{
						strcpy(zggz[j].name,zggz[j+1].name);
						       zggz[j].num,zggz[j+1].num;
							   zggz[j].gg,zggz[j+1].gg;
							   zggz[j].xj,zggz[j+1].xj;
							   zggz[j].jt,zggz[j+1].jt;
							   zggz[j].jx,zggz[j+1].jx;
							   zggz[j].yf,zggz[j+1].yf;
							   zggz[j].gere,zggz[j+1].gere;
							   zggz[j].sf,zggz[j+1].sf;
					}
					kongzi=0;
				}
		}
	}
	if(!kongzi)
		n=n-1;
	else
	{
		printf("���޴���...\n");
	    write();           //������Ϣ
		printf("����ɾ���밴1������ɾ���밴0\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:del();
			break;
		case 0:
			break;
		default:
			break;
		}
	}
}
void modify()
{
	int i;
	char num[20];
	printf("������Ҫ�޸ĵ�ְ�����ţ�\n");
	scanf("%s",num);
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].num,num)==0)
		{
			printf("�޸ĺ������Ϊ��\n");
			scanf("%s",&zggz[i].name);
			printf("�޸ĺ�ĸ�λ����Ϊ��\n");
			scanf("%d",&zggz[i].gg);
			printf("�޸ĺ��н������Ϊ��\n");
			scanf("%d",&zggz[i].xj);
			printf("�޸ĺ��ְ�����Ϊ��\n");
			scanf("%d",&zggz[i].jt);
			printf("�޸ĺ��Ч������Ϊ��\n");
			scanf("%d",&zggz[i].xj);
			printf("�޸ĺ��Ӧ������Ϊ��\n");
			scanf("%d",&zggz[i].yf);
		}
	}
	write();         //������Ϣ
}
void list()
{
	int i;
	system("cls");
	printf("����  ����  ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
	for(i=0;i<n;i++)
	{
		printf("\n %s%s %d%d%d%d%d%d%d",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
	}
}
void grsde()
{}
int main()
{
	int count;
	printf("\n\n");
	printf("      ###  ��ӭʹ�ù��������ѧ�������Ϣ��ȫѧԺְ�����ʹ���ϵͳ��  ###\n\n");
	printf("\n");
	do{
		//system("cls");
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
	    printf("      ����������ѡ��\n");
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
			break;
		case 6:
			list();
			break;
		case 7:
			printf("\nллʹ�ã�\n");
			return 0;

		default:
			printf("\n�����������������룺");
			scanf("%d",&count);
			break;

		}
	}while(count!=-1);
	
	/*cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "
		<<"н������"<<" "<<"ְ�����"<<" "<<"��Ч����"<<" "
		<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������\n";
	//read();
	write();*/
	return 0;
}

