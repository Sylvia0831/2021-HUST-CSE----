/************************************************* 
������Ϣ�����˵�������վ���������·�����������ſ� 
************************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "build.h"
#include "path_find.h"
#include "system.h"
#include "help.h"
#include "basic.h"
#include "path_choice.h"

int n1,n2;   //��¼��ת�˵�·�ߺ� 


void all_path_output(){  //��·���� 
	
	system("cls");
	int i,j,k;
	for (i=1;i<=8;i++){
		if (i==5) continue;
		color(2);
		printf("****�人�����ͨ%d����****\n\n",i);
		color(8);
		printf("������·������%dվ�㣬ȫ��%.2lfǧ��,����ؿ���Ϊ%d��\n\n",sites[i],dist[i],people[i]);
		color(7);
		for (j=1;j<sites[i];j++){
			printf("[%d] %s -> ",Line[i][j].Num,Line[i][j].Name);
			if (j % 6 ==0) printf("\n");
			
		} 
		printf("[%d] %s\n\n",Line[i][sites[i]].Num,Line[i][sites[i]].Name);
	}
	system("pause");
	BasicInformation_Menu();
}

void general_situation(){  //��·�ſ� 
	system("cls");
	color(12); 
	printf("��ӭʹ�ø�ϵͳ��������·�����ſ����£�\n\n");
	color(14);
	printf("����·��ͨ\n\n");
	color(7);
	printf("Ŀǰ�ѿ�ͨ7����·���ֱ�Ϊ1���ߣ�2���ߣ�3���ߣ�4���ߣ�6���ߣ�7���ߣ�8����\n���������Ϣ�ɲ鿴��һ�˵�����·����ѡ��\n\n");
	color(14);
	printf("���г�����ʱ��\n\n") ;
	color(7);
	printf("����·������ʱ���Ϊ6:00-23:00\n\n");
	color(14);
	printf("��Ʊ��\n\n");
	color(7);
	printf("4�������ڣ���4���,2Ԫ\n");
	printf("4-12�����12�����1Ԫ/4����\n");
	printf("12-24�����24�����1Ԫ/6����\n");
	printf("24-40�����40�����1Ԫ/8����\n");
	printf("40-50�����50�����1Ԫ/10����\n");
	printf("50�������ϣ�1Ԫ/20����\n\n");
	color(14);
	printf("��ӵ�����\n\n");
	color(7);
	printf("�����°�����·�ߣ�1���ߣ�3����\n");
	printf("\t7:30-9:00��ӵ����80%%\n\t16:30-18:30��ӵ����75%%\n\t����ʱ��ӵ����40%%\n\n");
	printf("����������·�ߣ�8����\n");
	printf("\t9:30-15:00��ӵ����65%%\n\t����ʱ��ӵ����20%%\n\n");
	printf("����������·�ߣ�6���ߣ�7����\n");
	printf("\t19:00-22:00��ӵ����65%%��\n\t����ʱ��ӵ����15%%\n\n");
	printf("���Ǽʽ�ͨ����·�ߣ�2���ߣ�4����\n");
	printf("\tȫ��ӵ����50%%\n\n");
	system("pause");
	BasicInformation_Menu();
	
	

}
void forward_dir(int line_,int num_){  //������ʻ��һվ 
	if (num_>=sites[line_])	{
	
	printf("��ǰվ��Ϊ%d�����յ�վ����������ʻ��һվ��\n",line_);
	}
	else {
		printf("����%d����������ʻ����%s������һվΪ:",line_,Line[line_][sites[line_]].Name);

		color(14);
		printf("%s,",Line[line_][num_+1].Name);
		color(7);
		int i;
		n1=n2=0;
		for (i=1;i<=8;i++){
			if (Line[line_][num_+1].Flag[i]) {
				if (n1==0) n1=i; else n2=i;
			}
		}
		if (n1!=0&&n2==0) printf("�ɻ���%d����\n",n1); 
		else{
			if(n2!=0) printf("�ɻ���%d��%d����\n",n1,n2);
			 	else printf("�ǻ��˵�\n"); 
			 }
	}

}
void reverse_dir(int line_,int num_){  //������ʻ��һվ 
	if (num_<=1){
		printf("��ǰվ��Ϊ%d�������վ����������ʻ��һվ��\n",line_); 
	 }
	else {
		printf("����%d����������ʻ����%s������һվΪ��",line_,Line[line_][1].Name);
		color(14);
		printf("%s,",Line[line_][num_-1].Name);
		color(7);
			int i;
			n1=n2=0;
			for (i=1;i<=8;i++){
				if (Line[line_][num_-1].Flag[i]) {
					if (n1==0) n1=i; else n2=i;
				}
			}
			if (n1!=0&&n2==0) printf("�ɻ���%d����\n",n1); else
			{
				if (n2!=0) printf("�ɻ���%d��%d����\n",n1,n2);
					else printf("�ǻ��˵�\n"); 
			}
			 
	}
	
} 
void site_browsing(){ //վ����� 
	int new_line;
	int line_,num_,c=200;
	system("cls");
	printf("�ù��ܿ�ģ��˳�·�ߣ�����վ�����\n") ;
	printf("��ָ����·��\n");
	scanf("%d",&line_);
	
	printf("��ָ��վ���ţ�\n");
	scanf("%d",&num_);
	printf("\n��ǰվ��Ϊ��");
	color(14);
	printf("%s",Line[line_][num_].Name);
	color(7);
	int i;
	n1=n2=0;
	for (i=1;i<=8;i++){
		if (Line[line_][num_].Flag[i]) {
			if (n1==0) n1=i; else n2=i;
		}
	}
	if (n1!=0&&n2==0) printf(",�ɻ���%d����\n",n1); else
	{
		if (n2!=0) printf(",�ɻ���%d��%d����\n",n1,n2);
			else printf(",�ǻ��˵�\n"); 
	}
	forward_dir(line_,num_);
	reverse_dir(line_,num_);
	while (c){	
		printf("\n��������Ҫ�����һվ��ķ�ʽ��ţ�\n");
		printf("1.�����������· 2.�����������· 3.���� 0.�����ϼ�\n");
		scanf("%d",&c);
		while (c!=1&&c!=2&&c!=3&&c!=0){
			printf("����������������룡\n");
			scanf("%d",&c);
		}
		switch (c){
			case 0:{
				BasicInformation_Menu();
				break;
			}
			case 1:
				{
					system("cls");
					num_++;
					if(num_>sites[line_]) {
						printf("�ѵ����յ�վ����������ʻ��һվ\n");
						num_--;
						system("pause");
						system("cls");
					}
					printf("��ǰվ��Ϊ��");
					color(14);
					printf("%s",Line[line_][num_].Name);
					color(7);
					int i;
					n1=n2=0;
					for (i=1;i<=8;i++){
						if (Line[line_][num_].Flag[i]) {
							if (n1==0) n1=i; else n2=i;
						}
					}
					if (n1!=0&&n2==0) printf(",�ɻ���%d����\n",n1); else
					{
						if (n2!=0) printf(",�ɻ���%d��%d����\n",n1,n2);
							else printf(",�ǻ��˵�\n"); 
					}
					
					forward_dir(line_,num_);
					reverse_dir(line_,num_);
					break;
				}
			case 2:
				{
					system("cls");
					num_--;
					if(num_<1) {
						printf("�ѵ������վ����������ʻ��һվ\n");
						num_++;
						system("pause");
						system("cls");
					}
					printf("��ǰվ��Ϊ��");
					color(14);
					printf("%s",Line[line_][num_].Name);
					color(7);
					int i;
					n1=n2=0;
					for (i=1;i<=8;i++){
						if (Line[line_][num_].Flag[i]) {
							if (n1==0) n1=i; else n2=i;
						}
					}
					if (n1!=0&&n2==0) printf(",�ɻ���%d����\n",n1); else 
					{
						if (n2!=0) printf(",�ɻ���%d��%d����\n",n1,n2);
							else printf(",�ǻ��˵�\n"); 
					}
					forward_dir(line_,num_);
					reverse_dir(line_,num_);
					break;
				}
			case 3:
				{ 
					printf("��������Ҫ���˵�·�ߣ�\n");
					scanf("%d",&new_line);
					n1=n2=0;
					for (i=1;i<=8;i++){
						if (Line[line_][num_].Flag[i]) {
							if (n1==0) n1=i; else n2=i;
						}
					}
					while (new_line!=n1 && new_line!=n2){
						printf("��վ�㲻��ת�˸���·�����������룡(����0�ɷ���)\n");
						scanf("%d",&new_line); 
					}
					if(new_line!=0) {
						num_=Line[line_][num_].Flag[new_line]; 
						line_=new_line;
						
					}
					system("cls");
					printf("��ǰվ��Ϊ��");
					color(14);
					printf("%s",Line[line_][num_].Name);
					color(7);
					int i;
					n1=n2=0;
					for (i=1;i<=8;i++){
						if (Line[line_][num_].Flag[i]) {
							if (n1==0) n1=i; else n2=i;
						}
					}
					if (n1!=0&&n2==0) printf(",�ɻ���%d����\n",n1); else 
					{
						if (n2!=0) printf(",�ɻ���%d��%d����\n",n1,n2);
							else printf(",�ǻ��˵�\n"); 
					}
					forward_dir(line_,num_);
					reverse_dir(line_,num_);
					
					break; 
				}
		}
	}	
	
}
