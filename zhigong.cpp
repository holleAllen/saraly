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
/*void find_num();
void grsds();
int main();*/
void list();
int n=0;
int read()
{
	FILE *fp; 
	int i;
	if((fp=fopen("gz10.dat","rb"))==NULL)
	{
		printf("Cannot open file strike any key exit!\n");
		getch();
		exit(-1);
	}
	for(i=0;i<100;i++)
	{
		
		fread(&zggz[i],sizeof(struct member),1,fp);	
		if(feof(fp))
		/*cout<<" "<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gg<<" "<<zggz[i].xj<<" "<<zggz[i].jt
		<<" "<<zggz[i].jx<<" "<<zggz[i].yf<<" "<<zggz[i].gere<<" "<<zggz[i].sf<<endl;*/
	
		break;
		n++ ;
	}
	fclose(fp);
	//printf("%d",n);
	

	return 0;
}
void write()
{
	int i;
	FILE*fp;
	if((fp=fopen("gz10.dat","wb+"))==NULL)
	{
		printf("Cannot open file strike any key exit!");
		getch();
		exit(-1);
	}
	for(i=0;i<n;i++)
	{
		fwrite(&zggz[i],sizeof(struct member),1,fp);  
	}
	fclose(fp);
}
/*void find()
{
	 
	int t,kongzi;
	
	system("cls");
	do
	{
		printf("\n��1�򰴹��Ų�ѯ\n��2 ����\n");
		scanf("%d",&t);
		if(t>=1&&t<=2)
		{
			kongzi=1;
			break;
		}
		else
		{
			kongzi=2;
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
			main();
			break;
		default:break;
			
		}
	}

}*/
void find_num()
{
	char num1[20];
	int i,t;
	printf("������Ҫ���ҵĹ���\n");
	scanf("%s",num1);
	for(i=0;i<n;i++)
	{
	
		if(strcmp(num1,zggz[i].num)==0)
		{
			printf("����  ����  ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
			printf("\n %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
		
			printf("\n\n");
		//	cout<<n<<endl;
			break;
		}
		/*else
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
			    main();
			    break;
			default:break;
			}
		}*/
	}
				

}
void add()
{
	//system("cls");
    printf("\nԭ����ְ����Ϣ:\n");
//	list();
    printf("\n"); 
    //fp=fopen("gz10.dat","a"); 
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
	//grsds();

	printf("\n"); 
	printf("\n��ӳɹ�\n");  
	n++; 
 
	printf("\n"); 

	write(); //ֱ�ӱ���
	//list();//��ʾ��Ӻ����Ϣ 
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
			printf("\n %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2",zggz[i].num,zggz[i].name,zggz[i].gg,
			    	zggz[i].xj,zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
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
					//write();
					kongzi=0;
				}
		}
	}
	if(!kongzi)
		n=n-1;
	else
	{
		printf("���޴���...\n");
	   // write();           //������Ϣ
		printf("����ɾ���밴1������ɾ���밴2\n");
		scanf("%d",&t);
		switch(t)
		{
		case 1:del();
			break;
		case 2:
			break;
		default:
			break;
		}
	}
	
}
void modify()
{

	int i,j;
	char num2[20];
	printf("ԭ����ְ����Ϣ:\n");
	list();
	//printf("%d",n);
	printf("������Ҫ�޸ĵ�ְ������(1001~1050)��\n");
	scanf("%s",num2);
	for(i=0;i<n;i++)
	{
		if(strcmp(zggz[i].num,num2)==0)   //   if(strcmp(zggz[i].name,name)==0)
		{
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
			//grsds();
		}
		/*else
		{
			//printf("\n");
			printf("����������������룺\n");
   		 	scanf("%d",&j);
		    switch(j)
			{
		     case 1:modify();
	 		   	break;
   	 	    case 2:main();
	 		   	break;
    		default:
	  		  	break;
			}
		}*/
	}
	
	//write();         //������Ϣ
 
}
void list()    //�������
{
	

	int i;
	//system("cls");
	printf("����  ����  ��λ����  н������  ְλ����  ��Ч����  Ӧ������  ����˰  ʵ������\n");
	for(i=0;i<n;i++)
	{
		printf("\n %s %s %.2f %.2f %.2f %.2f %.2f %.2f %.2f",zggz[i].num,zggz[i].name,zggz[i].gg,zggz[i].xj,
				zggz[i].jt,zggz[i].xj,zggz[i].yf,zggz[i].gere,zggz[i].sf);
	}
	printf("\n");

}
/*void grsds()
{  
	int i;
	for(i=0;i<n;i++)
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
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+(zggz[i].yf-40000)*0.3;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}
		else if(zggz[i].yf>=60000&&zggz[i].yf<80000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+(zggz[i].yf-60000)*0.35;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}
		else if(zggz[i].yf>=80000&&zggz[i].yf<100000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+20000*0.35+(zggz[i].yf-80000)*0.4;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}
		else if(zggz[i].yf>100000)
		{
			zggz[i].gere=500*0.05+1500*0.1+3000*0.15+15000*0.2+20000*0.25+20000*0.3+20000*0.35+20000*0.4+(zggz[i].yf-100000)*0.45;
			zggz[i].sf=zggz[i].yf-zggz[i].gere;
		}
		write();
	//	fclose(fp);


}*/
int main()
{
	int count;
	read();
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
            find_num();
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
	
	write();*/
    //read();
	/*for(int i=0;i<n;i++)
	{cout<<" "<<zggz[i].num<<" "<<zggz[i].name<<" "<<zggz[i].gg<<" "<<zggz[i].xj<<" "<<zggz[i].jt
		<<" "<<zggz[i].jx<<" "<<zggz[i].yf<<" "<<zggz[i].gere<<" "<<zggz[i].sf<<endl;
	}*/
	return 0;
}

