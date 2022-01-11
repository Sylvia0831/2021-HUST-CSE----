/********************* 
���˵�����ģ�� 
**********************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "build.h"
#include "path_find.h"
#include "system.h"
#include "basic.h"
#include "help.h"
#include "path_choice.h" 

int Operation_Num;
int hour=-1,minute=0;
int TimeOper_Num;
void Exit_System(void){  //0.�˳�ϵͳ 
	system("cls"); 

	printf("\n---------------------------------------------\n");
	printf("\n\t��л��ʹ�ñ�ϵͳ����ӭ�´�ʹ�ã�\n");
	printf("\n---------------------------------------------\n\n");
	system("pause");
	return;

}

void BasicInformation_Menu(){  //1.������Ϣ 
	system("cls");
	int Opera_Num;
	printf("\n\n\t\t�� �� �� Ϣ\t");
	printf("\n---------------------------------------------\n");
	printf("\t1.��·�ſ�\t  2.��·����\n");
	printf("\t3.վ�����\t  4.�����ϼ�\n");
	printf("\t\t0.�˳�ϵͳ");
	printf("\n---------------------------------------------\n\n");
	printf("\t���������Ĳ������:");
	scanf("%d",&Opera_Num);
	while(Opera_Num!=1&&Opera_Num!=2&&Opera_Num!=3&&Opera_Num!=4&&Opera_Num!=0) {
		printf("������������������:"); 
		scanf("%d",&Opera_Num);
	}
	switch(Opera_Num){
		case 1:{
			general_situation();
			break;
		} 
		case 2:{
			all_path_output();
			break;
		}
		case 3:{
			site_browsing();
			break;
		}
		case 4:{
			main_menu();
			break;
		}
		case 0:{
			Exit_System();
			break;
		}
	}
	system("cls");
	printf("0");
}
void SetingTime_Menu(){  //2.����ʱ�� 
	system("cls"); 
	
	if (hour==-1) printf("\n����ǰδ����ʱ�䣡\n");
		else {
			
			printf("\n��ǰʱ��Ϊ");
			color(14);
			printf("%dʱ%d��\n",hour,minute);
			color(7);
			
		} 
	printf("�Ƿ�Ҫ����ʱ���\n");
	printf("1.����  2.�����ϼ� 0.�˳�ϵͳ \n");
	printf("������������:\n");
	scanf("%d",&TimeOper_Num);
	while (TimeOper_Num!=1&&TimeOper_Num!=2&&TimeOper_Num!=0){
		printf("������������������:");
		scanf("%d",&TimeOper_Num);
	}
	switch(TimeOper_Num){
		case 1:{
				printf("������ʱ(0-23����): ");
				scanf("%d",&hour); 
				while(hour>=24 ||hour<=-1) {
					printf("������������������0-23������:");
					scanf("%d",&hour);
				}
				printf("�������(0-59����): ");
				scanf("%d",&minute);
				while(hour>=60 ||hour<=-1) {
					printf("������������������0-59������:"); 
					scanf("%d",&minute);
				}
				printf("\nʱ�����óɹ���\n��ǰʱ��Ϊ");
				color(14);
				printf("%dʱ%d��\n",hour,minute);
				color(7);
				system("pause");
				system("cls");
				main_menu();
				break;
		}
		case 2:{
			main_menu();
			break;
		}
		case 0:{
			Exit_System();
			break;
		}
	}
	

}

void Welcome_menu(){    //��ӭ���� 
	printf("\n\n---------------------------------------------\n\n");
	printf("\t��ӭʹ���人�����ͨ��ѯϵͳ��\t");
	printf("\n\n---------------------------------------------\n\n\n");
	system("pause");
	system("cls");
}
int main_menu(){   //���˵�
	system("cls");
	printf("\n\n\t\t��  ��  ��\t");
	printf("\n---------------------------------------------\n");
	printf("\t1.������Ϣ\t  2.����ʱ��\n");
	printf("\t3.��·�Ƽ�\t  4.ʹ�ð���\n");
	printf("\t\t0.�˳�ϵͳ");
	printf("\n---------------------------------------------\n\n");
	printf("\t���������Ĳ������:");
	scanf("%d",&Operation_Num);
	while(Operation_Num!=1&&Operation_Num!=2&&Operation_Num!=3&&Operation_Num!=4&&Operation_Num!=0) {
		printf("������������������:"); 
		scanf("%d",&Operation_Num);
	}
	switch(Operation_Num){
		case 1:{
			BasicInformation_Menu();
			break;
		} 
		case 2:{
			SetingTime_Menu(); 
			break;
		}
		case 3:{
			if (hour==-1){
				printf("����ǰδ����ʱ�䣬��������ʱ�䣡\n");
				system("pause"); 
				main_menu();
				break;
			} 
			if(hour*60+minute<60*6){
				printf("��ǰ�����г�����ʱ���ڣ�\n�г�����ʱ��Ϊ6��00-23��00\n����������ʱ�䣡\n"); 
				system("pause");
				main_menu();
				break; 
			}
			crowd_seting();
			input_S();
			input_D();

			break;
		}
		case 4:{
			Help_Note(); 
			break;
		}
		case 0:{
			Exit_System();
			break;
		}
	}
	system("cls");
	return 1;
}
int path_menu(){   //·���Ƽ������˵� 
	int m;
	system("cls");
	printf("\n\n---------------------------------------------\n\n");
	printf("   ����������Ҫ��·���Ƽ���ʽ���\t\n");
	printf("\t1.ʱ�����\n");
	printf("\t2.ӵ������С\n");
	printf("\t3.�ۺ�ӵ������ʱ���ļ�Ȩ��С\n");
	printf("\t4.���˹���ӵ��·�ߺ�ʱ�����\n");
	printf("\t0.�������˵�\n");
	printf("\n\n---------------------------------------------\n\n\n");
	scanf("%d",&m);
	while (!(m==1||m==2||m==3||m==4||m==0)){
		printf("����������������룡\n");
		scanf("%d",&m);
	}
	int i,j;
	for (i=0;i<=500;i++){
		stack[i].rail=0;
		stack[i].point=0;
	} 
	for (i=0;i<9;i++){
		for (j=0;j<40;j++){
			visit[i][j]=0;
		}
	}

	path_num=0;
	top=0;//��¼·���� ,ջ�� 
	flag_empty=0;
 	path_len[50];
	len_i=0;
	len=200;   //5�����з��� 
	len_sum=0;
	dfs(num_s,flag_s,num_d,flag_d);

	switch(m){
		case 0:{
			main_menu();
			break;
		}
		case 1:{
			PathTime();
			if (!Path_undertime()) {printf("��Ҫ��ѯ��ʱ�䲻���г�����ʱ���ڣ�\n");system("pause");path_menu();return;} else	path_output_undertime();
			break;
		}
		case 2:{
			PathTime();
			if (!path_undercrowd()) {printf("��Ҫ��ѯ��ʱ�䲻���г�����ʱ���ڣ�\n");system("pause");path_menu();return;} else path_output_crowd();
			break;
		}
		case 3:{
			PathTime();
			if (!path_underweight()) {printf("��Ҫ��ѯ��ʱ�䲻���г�����ʱ���ڣ�\n");system("pause");path_menu();return;} else path_output_weight();
			break;
		}
		case 4:{
			PathTime();
			if (!path_underovercrowd()) {printf("��Ҫ��ѯ��ʱ�䲻���г�����ʱ���ڣ�\n");system("pause");path_menu();return;} else	path_output_overcrowd(); 
			break;
		}
	}
	
	system("cls");
	path_menu();
}
void color(char x)   //������ɫ���ü򻯺��� 
{
	if(x>=0 && x<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
 } 
 



