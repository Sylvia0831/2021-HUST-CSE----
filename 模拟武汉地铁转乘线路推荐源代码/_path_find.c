/************************************ 
所有可行路径查找模块（dfs） 
*************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "build.h"
#include "path_find.h"
#include "system.h"
#include "path_choice.h"

PATH path[1000][250]={0};  //最终系统中，每次查询完毕记得清空路径 

char start[30],dest[30];
int num_s,flag_s,num_d,flag_d;

PATH stack[500]={0};  //dfs辅助栈   
int visit[9][40]={0}; //标记是否访问过 

int path_num=0,top=0;//记录路线数 ,栈顶 
int flag_empty=0;
int path_len[50];
int len_i=0,len=200;   //5条进行放缩 
int len_sum=0;

int judge_transfer(int num,int flag){  //判断是否为转乘点 
	int i,j,f;
	for(i=1;i<=8;i++){
		if (Line[num][flag].Flag[i]>=1)	{f=1;break;}
	}
	if (f) return 1;
	return 0;	
}
void input_S(){   //输入起点站 
	printf("\n当前时间为");
	color(14);
	printf("%d时%d分\n",hour,minute);
	color(7);
	printf("请输入起点线路号："); 
	scanf("%d",&num_s);
	while (num_s>8||num_s<1||num_s==5){
		printf("输入错误，请重新输入线路号！\n");
		scanf("%d",&num_s);
	}
	printf("请输入起点站点序号：");
	scanf("%d",&flag_s);
	while (flag_s<1||flag_s>sites[num_s]){
		printf("输入错误，请重新输入站点号！\n");
		scanf("%d",&flag_s);
	}
	if(judge_transfer(num_s,flag_s)) printf ("您输入的起始站为：%s,为换乘站点.\n",Line[num_s][flag_s].Name);
	 else  printf ("您输入的起始站为：%s,非换乘站点.\n",Line[num_s][flag_s].Name);
	next_ug(num_s,flag_s,hour,minute);	
}
void input_D(){  //输入终点站 
	printf("请输入终点线路号：");
	scanf("%d",&num_d);
	while (num_d>8||num_d<1||num_d==5){
		printf("输入错误，请重新输入线路号！\n");
		scanf("%d",&num_d);
	}
	printf("请输入终点站点序号：");
	scanf("%d",&flag_d);
	while (flag_d<1||flag_d>sites[num_d]){
		printf("输入错误，请重新输入站点号！\n");
		scanf("%d",&flag_d);
	}
	if(Line[num_s][flag_s].Flag[num_d]==flag_d) {
		printf("输入的起终点相同，请重新输入！") ;
		system("pause");
		system("cls");
		input_D();
		return;
	}
	 
	if(judge_transfer(num_d,flag_d)) printf ("您输入的终点站为：%s,为换乘站点.\n",Line[num_d][flag_d].Name);
	 else  printf ("您输入的终点站为：%s,非换乘站点.\n",Line[num_d][flag_d].Name);
	system("pause");
	path_menu(); 
	 
}



void push(int rail,int point){  //入栈函数 
	int i;
	top++;
	stack[top].rail=rail;
	stack[top].point=point;//入栈
	
	visit[rail][point]=1;
	for (i=1;i<=8;i++){
		if (Line[rail][point].Flag[i]>1) {
			visit[i][Line[rail][point].Flag[i]]=1;
		}
	}   //打标记 
	if (!flag_empty) flag_empty=1; 
	 
	  
}

void pop(int rail,int point){  //出栈函数 
	int i;
	stack[top].rail=0;
	stack[top].point=0;//出栈
	top--; 
	
	visit[rail][point]=0;
	for (i=1;i<=8;i++){
		if (Line[rail][point].Flag[i]>1) {
			visit[i][Line[rail][point].Flag[i]]=0;
		}
	}   //消除标记 
	
}

int judge_visit(int rail,int point){  //返回0表示未访问 
	int i;
	int ff=0;
	if(visit[rail][point]) ff=1;  //访问过为1 
		 else {
			 for  (i=1;i<=8;i++){
			 	if (visit[i][Line[rail][point].Flag[i]]) ff=1;
			 }
		}
		return ff;
}
void dfs(int rail,int point,int d_rail,int d_point){  //dfs进行深搜路径 
	if (stack[1].rail==0&&flag_empty) return;
	push(rail,point);//入栈且做标记,要把同点不同线路的一起标记 
	if (judge_visit(d_rail,d_point) ){  //到达终点 
		path_num++;
		path[path_num][0].rail=top;  //第一个的rail存储当前路径的站点数 
		if (path_num>=20&&path_num<=25) len--;   //进行剪枝 
		if (path_num>6) len=(len*(path_num-1)+top)/(path_num);
		if(path_num==6) len=(top+len_sum)/6; else len_sum+=top;
		int ii=1;
		while (stack[ii].rail){
			path[path_num][ii].rail=stack[ii].rail;
			path[path_num][ii].point=stack[ii].point;  //记录路径 
			ii++;
		}
		pop(rail,point);//终点出栈 
		return;
	}
	
	int i,j;
	NODE *p=Line[rail][point].next;

	while (p){

		if (!judge_visit(p->Rail,p->Num)&&top<=len) dfs(p->Rail,p->Num,d_rail,d_point);  //如果当前点没有被访问过，进行dfs 

		p=p->next;
	
	}
	
	pop(rail,point);  //无路时出栈，消除标记！ 
	return; 		
}


void path_output_undertime(){   //输出时间最短的路线 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("推荐路线%d :\n",i);
		printf("\t预计时间:");
		color(14);
		printf("%dmin",path_time[i][path_time[i][0].rail].time_sum);
		color(7);
		printf("\t票价:");
		color(14);
		printf("%dr",path_time[i][path_time[i][0].rail].price);
		color(7);
		printf("\t平均拥挤程度:");
		color(14);
		printf("%.1lf%%\n\n",path_time[i][path_time[i][0].rail].crowd_sum);
		color(7);

		while (path_time[i][j+1].rail>0){
			if(path_time[i][j].rail!=path_time[i][j+1].rail&&j!=1) printf("%s (转%d号线) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j+1].rail);
			 else if (j==1&&path_time[i][j].rail!=path_time[i][j+1].rail) printf("%s(%d号线) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j+1].rail); else printf("%s(%d号线) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j].rail);
			j++;
		}
		printf("%s(%d号线)\n\n",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j].rail);
		
	}
	system("pause");
}
void path_output_weight(){  //输出加权后的路线 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("推荐路线%d :\n",i);
		printf("\t加权时间:");
		color(14);
		printf("%.2lfmin",path_weight[i][path_weight[i][0].rail].time_sum_weight);
		color(7);
		printf("\t预计时间:");
		color(14);
		printf("%dmin",path_weight[i][path_weight[i][0].rail].time_sum);
		color(7);
		printf("\t票价:");
		color(14);
		printf("%dr\n",path_weight[i][path_weight[i][0].rail].price);
		color(7);


		while (path_weight[i][j+1].rail>0){
			if(path_weight[i][j].rail!=path_weight[i][j+1].rail&&j!=1) printf("%s (转%d号线) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j+1].rail);
			 else if (j==1&&path_weight[i][j].rail!=path_weight[i][j+1].rail) printf("%s (%d号线) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j+1].rail); 
				else printf("%s (%d号线) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j].rail);
			j++;
		}
		printf("%s (%d号线) \n\n",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j].rail );
		
	}


	system("pause");
	
}
void path_output_crowd(){ //输出基于拥挤度的路径 
	int i,j;
	
	for (i=1;i<=3;i++){
		j=1;
		
		
		printf("推荐路线%d :\n",i);
		printf("\t预计时间:");
		color(14);
		printf("%dmin",path_crowd[i][path_crowd[i][0].rail].time_sum);
		color(7);
		printf("\t票价:");
		color(14);
		printf("%dr",path_crowd[i][path_crowd[i][0].rail].price);
		color(7);
		printf("\t平均拥挤程度:");
		color(14);
		printf("%.2lf%%\n\n",path_crowd[i][path_crowd[i][0].rail].crowd_sum);

		color(7);
		while (path_crowd[i][j+1].rail>0){
			if(path_crowd[i][j].rail!=path_crowd[i][j+1].rail&&j!=1) printf("%s (转%d号线) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j+1].rail);
			 else if (j==1&&path_crowd[i][j].rail!=path_crowd[i][j+1].rail) printf("%s (%d号线) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j+1].rail); 
				else printf("%s (%d号线) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j].rail);
			j++;
		}
		printf("%s (%d号线) \n\n",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j].rail );
		
	}
	system("pause");
}
void path_output_overcrowd(){  //输出过滤过度拥挤路线后的路径 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("推荐路线%d :\n",i);
		printf("\t预计时间:");
		color(14);
		printf("%dmin",path_crowdo[i][path_crowdo[i][0].rail].time_sum);
		color(7);
		printf("\t票价:");
		color(14);
		printf("%dr",path_crowdo[i][path_crowdo[i][0].rail].price);
		color(7);
		printf("\t平均拥挤程度:");
		color(14);
		printf("%.1lf%%\n\n",path_crowdo[i][path_crowdo[i][0].rail].crowd_sum);

		color(7);
		while (path_crowdo[i][j+1].rail>0){
			if(path_crowdo[i][j].rail!=path_crowdo[i][j+1].rail&&j!=1) printf("%s (转%d号线) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j+1].rail);
			 else if (j==1&&path_crowdo[i][j].rail!=path_crowdo[i][j+1].rail) printf("%s (%d号线) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j+1].rail); 
				else printf("%s (%d号线) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j].rail);
			j++;
		}
		printf("%s (%d号线) \n\n",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j].rail );
	} 
	system("pause");
}

