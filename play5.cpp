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
void grsde();   //���庯��

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
	cout<<"               "<<"................����"<<n<<"����"<<endl;
	printf("            .......����\n");*/   //�����д�
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
		printf("\n��1�򰴹��Ų�ѯ\n��2 �����˵�\n");
		scanf("%d,&t");
		if(t>=1&&t<=3)
		{
			kongzi=1;
			break;
		}
		else
		{
			kongzi=0;
			printf("�������");
		}
	}
	while(kongzi=0);
	while(kongzi=1)
	{
		switch(t)
		{
		case 1:printf("�����Ų�ѯ\n");
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
	printf("������Ҫ���ҵ�ְ����\n");
	scanf("%d,&num1");
	for(i<0;i<5;i++)
	{
		if(num1=zggz[i].num)
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
			printf("�������˵��밴1��������ѯְ���밴2\n");
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


printf("ԭ����ְ����Ϣ:\n"); 
  
    printf("\n"); 

     fp=fopen("gz5.dat","a"); 



   printf("\n ������������ְ������Ϣ:\n"); 

   printf("������ְ����:  "); 

   scanf("%s",&zggz[i].num); 

   printf("\n"); 

         printf("����������:  "); 

      scanf("%s",&zggz[i].name); 

         getchar(); 

         printf("�������λ����:  "); 

      scanf("\t%d",&zggz[i].gg); 

         printf("������н������:  "); 

      scanf("%d",&zggz[i].xj); 

      printf("���������:  "); 

      scanf("%d",&zggz[i].jt); 

      printf("�����뼨Ч����:  "); 

      scanf("\t%d",&zggz[i].jx); 

       printf("������Ӧ������:  "); 

      scanf("%d",&zggz[i].yf); 

       printf("�������������˰:  "); 

      scanf("%d",&zggz[i].gere);  

       printf("������ʵ������:  "); 

      scanf("%d",&zggz[i].sf); 
 

         printf("\n"); 


     printf("\n��ӳɹ�\n");  


  printf("\n���Ӻ������ְ����Ϣ:\n"); 

  printf("\n"); 

  write(); //ֱ�ӱ���

     list();//��ʾ��Ӻ����Ϣ 

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
	
	printf("              ��ӭʹ��ְ�����ʹ���ϵͳ��\n\n");
	do{
		system("cls");
	    printf("              �������������������ܲ˵�ѡ��   ����������������\n");
    	printf("              ����������������1����ѯԱ����Ϣ����������������\n");
	    printf("              ����������������2���޸�Ա����Ϣ����������������\n");
    	printf("              ����������������3�����Ա����Ϣ����������������\n");
	    printf("              ����������������4��ɾ��Ա����Ϣ����������������\n");
	    printf("              ����������������5������        ����������������\n");
	    printf("              ����������������6�����ȫ����Ϣ����������������\n");
	    printf("              ����������������7���˳�        ����������������\n");
	    printf("                ����������ѡ��\n");
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
			printf("\nллʹ�ã�\n");
			return 0;
		default:
			printf("\n�����������������룺");
			scanf("%d,&count");
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

