/************************************************* 
基本信息二级菜单，共有站点浏览、线路总览、基本概况 
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

int n1,n2;   //记录可转乘的路线号 


void all_path_output(){  //线路总览 
	
	system("cls");
	int i,j,k;
	for (i=1;i<=8;i++){
		if (i==5) continue;
		color(2);
		printf("****武汉轨道交通%d号线****\n\n",i);
		color(8);
		printf("该条线路，共设%d站点，全长%.2lf千米,最大载客量为%d人\n\n",sites[i],dist[i],people[i]);
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

void general_situation(){  //线路概况 
	system("cls");
	color(12); 
	printf("欢迎使用该系统，地铁线路基本概况如下：\n\n");
	color(14);
	printf("●线路开通\n\n");
	color(7);
	printf("目前已开通7条线路，分别为1号线，2号线，3号线，4号线，6号线，7号线，8号线\n具体相关信息可查看上一菜单中线路总览选项\n\n");
	color(14);
	printf("●列车运行时间\n\n") ;
	color(7);
	printf("所有路线运行时间均为6:00-23:00\n\n");
	color(14);
	printf("●票价\n\n");
	color(7);
	printf("4公里以内（含4公里）,2元\n");
	printf("4-12公里（含12公里），1元/4公里\n");
	printf("12-24公里（含24公里），1元/6公里\n");
	printf("24-40公里（含40公里），1元/8公里\n");
	printf("40-50公里（含50公里），1元/10公里\n");
	printf("50公里以上，1元/20公里\n\n");
	color(14);
	printf("●拥挤情况\n\n");
	color(7);
	printf("·上下班类型路线：1号线，3号线\n");
	printf("\t7:30-9:00，拥挤度80%%\n\t16:30-18:30，拥挤度75%%\n\t其余时间拥挤度40%%\n\n");
	printf("·购物类型路线：8号线\n");
	printf("\t9:30-15:00，拥挤度65%%\n\t其余时间拥挤度20%%\n\n");
	printf("·娱乐类型路线：6号线，7号线\n");
	printf("\t19:00-22:00，拥挤度65%%；\n\t其余时间拥挤度15%%\n\n");
	printf("·城际交通类型路线：2号线，4号线\n");
	printf("\t全天拥挤度50%%\n\n");
	system("pause");
	BasicInformation_Menu();
	
	

}
void forward_dir(int line_,int num_){  //正向行驶下一站 
	if (num_>=sites[line_])	{
	
	printf("当前站点为%d号线终点站，无正向行驶下一站点\n",line_);
	}
	else {
		printf("乘坐%d号线正向行驶（往%s方向）下一站为:",line_,Line[line_][sites[line_]].Name);

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
		if (n1!=0&&n2==0) printf("可换乘%d号线\n",n1); 
		else{
			if(n2!=0) printf("可换乘%d、%d号线\n",n1,n2);
			 	else printf("非换乘点\n"); 
			 }
	}

}
void reverse_dir(int line_,int num_){  //逆向行驶下一站 
	if (num_<=1){
		printf("当前站点为%d号线起点站，无逆向行驶下一站点\n",line_); 
	 }
	else {
		printf("乘坐%d号线逆向行驶（往%s方向）下一站为：",line_,Line[line_][1].Name);
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
			if (n1!=0&&n2==0) printf("可换乘%d号线\n",n1); else
			{
				if (n2!=0) printf("可换乘%d、%d号线\n",n1,n2);
					else printf("非换乘点\n"); 
			}
			 
	}
	
} 
void site_browsing(){ //站点浏览 
	int new_line;
	int line_,num_,c=200;
	system("cls");
	printf("该功能可模拟乘车路线，进行站点浏览\n") ;
	printf("请指定线路：\n");
	scanf("%d",&line_);
	
	printf("请指定站点编号：\n");
	scanf("%d",&num_);
	printf("\n当前站点为：");
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
	if (n1!=0&&n2==0) printf(",可换乘%d号线\n",n1); else
	{
		if (n2!=0) printf(",可换乘%d、%d号线\n",n1,n2);
			else printf(",非换乘点\n"); 
	}
	forward_dir(line_,num_);
	reverse_dir(line_,num_);
	while (c){	
		printf("\n请输入您要浏览下一站点的方式序号：\n");
		printf("1.正向乘坐该线路 2.反向乘坐该线路 3.换乘 0.返回上级\n");
		scanf("%d",&c);
		while (c!=1&&c!=2&&c!=3&&c!=0){
			printf("输入错误，请重新输入！\n");
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
						printf("已到达终点站，无正向行驶下一站\n");
						num_--;
						system("pause");
						system("cls");
					}
					printf("当前站点为：");
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
					if (n1!=0&&n2==0) printf(",可换乘%d号线\n",n1); else
					{
						if (n2!=0) printf(",可换乘%d、%d号线\n",n1,n2);
							else printf(",非换乘点\n"); 
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
						printf("已到达起点站，无逆向行驶下一站\n");
						num_++;
						system("pause");
						system("cls");
					}
					printf("当前站点为：");
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
					if (n1!=0&&n2==0) printf(",可换乘%d号线\n",n1); else 
					{
						if (n2!=0) printf(",可换乘%d、%d号线\n",n1,n2);
							else printf(",非换乘点\n"); 
					}
					forward_dir(line_,num_);
					reverse_dir(line_,num_);
					break;
				}
			case 3:
				{ 
					printf("请输入您要换乘的路线：\n");
					scanf("%d",&new_line);
					n1=n2=0;
					for (i=1;i<=8;i++){
						if (Line[line_][num_].Flag[i]) {
							if (n1==0) n1=i; else n2=i;
						}
					}
					while (new_line!=n1 && new_line!=n2){
						printf("该站点不可转乘该线路，请重新输入！(输入0可返回)\n");
						scanf("%d",&new_line); 
					}
					if(new_line!=0) {
						num_=Line[line_][num_].Flag[new_line]; 
						line_=new_line;
						
					}
					system("cls");
					printf("当前站点为：");
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
					if (n1!=0&&n2==0) printf(",可换乘%d号线\n",n1); else 
					{
						if (n2!=0) printf(",可换乘%d、%d号线\n",n1,n2);
							else printf(",非换乘点\n"); 
					}
					forward_dir(line_,num_);
					reverse_dir(line_,num_);
					
					break; 
				}
		}
	}	
	
}
