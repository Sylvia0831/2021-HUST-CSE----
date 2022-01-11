/********************* 
各菜单设置模块 
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
void Exit_System(void){  //0.退出系统 
	system("cls"); 

	printf("\n---------------------------------------------\n");
	printf("\n\t感谢您使用本系统，欢迎下次使用！\n");
	printf("\n---------------------------------------------\n\n");
	system("pause");
	return;

}

void BasicInformation_Menu(){  //1.基本信息 
	system("cls");
	int Opera_Num;
	printf("\n\n\t\t基 本 信 息\t");
	printf("\n---------------------------------------------\n");
	printf("\t1.线路概况\t  2.线路总览\n");
	printf("\t3.站点浏览\t  4.返回上级\n");
	printf("\t\t0.退出系统");
	printf("\n---------------------------------------------\n\n");
	printf("\t请输入您的操作序号:");
	scanf("%d",&Opera_Num);
	while(Opera_Num!=1&&Opera_Num!=2&&Opera_Num!=3&&Opera_Num!=4&&Opera_Num!=0) {
		printf("输入有误，请重新输入:"); 
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
void SetingTime_Menu(){  //2.设置时间 
	system("cls"); 
	
	if (hour==-1) printf("\n您当前未设置时间！\n");
		else {
			
			printf("\n当前时间为");
			color(14);
			printf("%d时%d分\n",hour,minute);
			color(7);
			
		} 
	printf("是否要设置时间表？\n");
	printf("1.设置  2.返回上级 0.退出系统 \n");
	printf("请输入操作序号:\n");
	scanf("%d",&TimeOper_Num);
	while (TimeOper_Num!=1&&TimeOper_Num!=2&&TimeOper_Num!=0){
		printf("输入有误，请重新输入:");
		scanf("%d",&TimeOper_Num);
	}
	switch(TimeOper_Num){
		case 1:{
				printf("请输入时(0-23整数): ");
				scanf("%d",&hour); 
				while(hour>=24 ||hour<=-1) {
					printf("输入有误，请重新输入0-23的整数:");
					scanf("%d",&hour);
				}
				printf("请输入分(0-59整数): ");
				scanf("%d",&minute);
				while(hour>=60 ||hour<=-1) {
					printf("输入有误，请重新输入0-59的整数:"); 
					scanf("%d",&minute);
				}
				printf("\n时间设置成功！\n当前时间为");
				color(14);
				printf("%d时%d分\n",hour,minute);
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

void Welcome_menu(){    //欢迎界面 
	printf("\n\n---------------------------------------------\n\n");
	printf("\t欢迎使用武汉轨道交通查询系统！\t");
	printf("\n\n---------------------------------------------\n\n\n");
	system("pause");
	system("cls");
}
int main_menu(){   //主菜单
	system("cls");
	printf("\n\n\t\t主  菜  单\t");
	printf("\n---------------------------------------------\n");
	printf("\t1.基本信息\t  2.设置时间\n");
	printf("\t3.线路推荐\t  4.使用帮助\n");
	printf("\t\t0.退出系统");
	printf("\n---------------------------------------------\n\n");
	printf("\t请输入您的操作序号:");
	scanf("%d",&Operation_Num);
	while(Operation_Num!=1&&Operation_Num!=2&&Operation_Num!=3&&Operation_Num!=4&&Operation_Num!=0) {
		printf("输入有误，请重新输入:"); 
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
				printf("您当前未设置时间，请先设置时间！\n");
				system("pause"); 
				main_menu();
				break;
			} 
			if(hour*60+minute<60*6){
				printf("当前不在列车运行时间内！\n列车运行时间为6：00-23：00\n请重新设置时间！\n"); 
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
int path_menu(){   //路径推荐三级菜单 
	int m;
	system("cls");
	printf("\n\n---------------------------------------------\n\n");
	printf("   请输入您需要的路线推荐方式序号\t\n");
	printf("\t1.时间最短\n");
	printf("\t2.拥挤度最小\n");
	printf("\t3.综合拥挤度与时间后的加权最小\n");
	printf("\t4.过滤过度拥挤路线后时间最短\n");
	printf("\t0.返回主菜单\n");
	printf("\n\n---------------------------------------------\n\n\n");
	scanf("%d",&m);
	while (!(m==1||m==2||m==3||m==4||m==0)){
		printf("输入错误，请重新输入！\n");
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
	top=0;//记录路线数 ,栈顶 
	flag_empty=0;
 	path_len[50];
	len_i=0;
	len=200;   //5条进行放缩 
	len_sum=0;
	dfs(num_s,flag_s,num_d,flag_d);

	switch(m){
		case 0:{
			main_menu();
			break;
		}
		case 1:{
			PathTime();
			if (!Path_undertime()) {printf("您要查询的时间不在列车运行时间内！\n");system("pause");path_menu();return;} else	path_output_undertime();
			break;
		}
		case 2:{
			PathTime();
			if (!path_undercrowd()) {printf("您要查询的时间不在列车运行时间内！\n");system("pause");path_menu();return;} else path_output_crowd();
			break;
		}
		case 3:{
			PathTime();
			if (!path_underweight()) {printf("您要查询的时间不在列车运行时间内！\n");system("pause");path_menu();return;} else path_output_weight();
			break;
		}
		case 4:{
			PathTime();
			if (!path_underovercrowd()) {printf("您要查询的时间不在列车运行时间内！\n");system("pause");path_menu();return;} else	path_output_overcrowd(); 
			break;
		}
	}
	
	system("cls");
	path_menu();
}
void color(char x)   //字体颜色设置简化函数 
{
	if(x>=0 && x<=15)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
	else
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
 } 
 



