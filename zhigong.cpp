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
void read()          //��ȡְ����������
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
	cout<<"               "<<"................����"<<n<<"����"<<endl;
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
		{	cout<<"�ļ���д����";
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
		printf("�ļ���ʧ��");
     	return;
	}
	if (out==0)
		{         printf("û����ϵ�˿ɶ�");    }       //д������       
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
	cout<<"������Ҫ��ѯԱ���Ĺ���\n";
	cin>>number;
	for(i=0;i<n;i++)
	{	if(gx[i].num==number){
			flag=1;
			break;
		}
	}
	if(flag)
	{
		cout<<"���� ���� ��λ���� н������ ְλ���� ��Ч Ӧ�� ��������˰ ʵ��\n";
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
		cout<<"û���ҵ��ù��ŵ�Ա��\n";
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
	
	cout<<"                 Ա������ϵͳ                 \n";
	do{
		system("cls");
		cout<<"\n\n\n";
		cout<<"               ******              ���ܲ˵�ѡ��           ******\n\n";
		cout<<"               ******           1����ʾ����Ա����Ϣ       ******\n";
		cout<<"               ******           2������Ա����Ϣ           ******\n";
		cout<<"               ******           3������Ա����Ϣ           ******\n";
		cout<<"               ******           4���޸�Ա����Ϣ           ******\n";
		cout<<"               ******           5��ɾ��Ա����Ϣ           ******\n";
		cout<<"               ******           6�����Ա����Ϣ           ******\n";
		cout<<"               ******           7���鿴��������           ******\n";
		cout<<"               ******           0���˳�����               ******\n";
		cout<<"\n\n\n";
		cout<<"           ���������ѡ��\n";
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
			cout<<"\nллʹ�ã�\n";
			return 0;
		default:
			cout<<"\n�����������������룺";
			cin>>out;
			break;

		}
	}while(out!=-1);
	
	/*cout<<"����"<<" "<<"����"<<" "<<"��λ����"<<" "
		<<"н������"<<" "<<"ְ�����"<<" "<<"��Ч����"<<" "
		<<"Ӧ������"<<" "<<"��������˰"<<" "<<"ʵ������\n";
	//read();
	write();*/
	return 0;
}