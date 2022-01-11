/************************************ 
���п���·������ģ�飨dfs�� 
*************************************/ 
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "build.h"
#include "path_find.h"
#include "system.h"
#include "path_choice.h"

PATH path[1000][250]={0};  //����ϵͳ�У�ÿ�β�ѯ��ϼǵ����·�� 

char start[30],dest[30];
int num_s,flag_s,num_d,flag_d;

PATH stack[500]={0};  //dfs����ջ   
int visit[9][40]={0}; //����Ƿ���ʹ� 

int path_num=0,top=0;//��¼·���� ,ջ�� 
int flag_empty=0;
int path_len[50];
int len_i=0,len=200;   //5�����з��� 
int len_sum=0;

int judge_transfer(int num,int flag){  //�ж��Ƿ�Ϊת�˵� 
	int i,j,f;
	for(i=1;i<=8;i++){
		if (Line[num][flag].Flag[i]>=1)	{f=1;break;}
	}
	if (f) return 1;
	return 0;	
}
void input_S(){   //�������վ 
	printf("\n��ǰʱ��Ϊ");
	color(14);
	printf("%dʱ%d��\n",hour,minute);
	color(7);
	printf("�����������·�ţ�"); 
	scanf("%d",&num_s);
	while (num_s>8||num_s<1||num_s==5){
		printf("�������������������·�ţ�\n");
		scanf("%d",&num_s);
	}
	printf("���������վ����ţ�");
	scanf("%d",&flag_s);
	while (flag_s<1||flag_s>sites[num_s]){
		printf("�����������������վ��ţ�\n");
		scanf("%d",&flag_s);
	}
	if(judge_transfer(num_s,flag_s)) printf ("���������ʼվΪ��%s,Ϊ����վ��.\n",Line[num_s][flag_s].Name);
	 else  printf ("���������ʼվΪ��%s,�ǻ���վ��.\n",Line[num_s][flag_s].Name);
	next_ug(num_s,flag_s,hour,minute);	
}
void input_D(){  //�����յ�վ 
	printf("�������յ���·�ţ�");
	scanf("%d",&num_d);
	while (num_d>8||num_d<1||num_d==5){
		printf("�������������������·�ţ�\n");
		scanf("%d",&num_d);
	}
	printf("�������յ�վ����ţ�");
	scanf("%d",&flag_d);
	while (flag_d<1||flag_d>sites[num_d]){
		printf("�����������������վ��ţ�\n");
		scanf("%d",&flag_d);
	}
	if(Line[num_s][flag_s].Flag[num_d]==flag_d) {
		printf("��������յ���ͬ�����������룡") ;
		system("pause");
		system("cls");
		input_D();
		return;
	}
	 
	if(judge_transfer(num_d,flag_d)) printf ("��������յ�վΪ��%s,Ϊ����վ��.\n",Line[num_d][flag_d].Name);
	 else  printf ("��������յ�վΪ��%s,�ǻ���վ��.\n",Line[num_d][flag_d].Name);
	system("pause");
	path_menu(); 
	 
}



void push(int rail,int point){  //��ջ���� 
	int i;
	top++;
	stack[top].rail=rail;
	stack[top].point=point;//��ջ
	
	visit[rail][point]=1;
	for (i=1;i<=8;i++){
		if (Line[rail][point].Flag[i]>1) {
			visit[i][Line[rail][point].Flag[i]]=1;
		}
	}   //���� 
	if (!flag_empty) flag_empty=1; 
	 
	  
}

void pop(int rail,int point){  //��ջ���� 
	int i;
	stack[top].rail=0;
	stack[top].point=0;//��ջ
	top--; 
	
	visit[rail][point]=0;
	for (i=1;i<=8;i++){
		if (Line[rail][point].Flag[i]>1) {
			visit[i][Line[rail][point].Flag[i]]=0;
		}
	}   //������� 
	
}

int judge_visit(int rail,int point){  //����0��ʾδ���� 
	int i;
	int ff=0;
	if(visit[rail][point]) ff=1;  //���ʹ�Ϊ1 
		 else {
			 for  (i=1;i<=8;i++){
			 	if (visit[i][Line[rail][point].Flag[i]]) ff=1;
			 }
		}
		return ff;
}
void dfs(int rail,int point,int d_rail,int d_point){  //dfs��������·�� 
	if (stack[1].rail==0&&flag_empty) return;
	push(rail,point);//��ջ�������,Ҫ��ͬ�㲻ͬ��·��һ���� 
	if (judge_visit(d_rail,d_point) ){  //�����յ� 
		path_num++;
		path[path_num][0].rail=top;  //��һ����rail�洢��ǰ·����վ���� 
		if (path_num>=20&&path_num<=25) len--;   //���м�֦ 
		if (path_num>6) len=(len*(path_num-1)+top)/(path_num);
		if(path_num==6) len=(top+len_sum)/6; else len_sum+=top;
		int ii=1;
		while (stack[ii].rail){
			path[path_num][ii].rail=stack[ii].rail;
			path[path_num][ii].point=stack[ii].point;  //��¼·�� 
			ii++;
		}
		pop(rail,point);//�յ��ջ 
		return;
	}
	
	int i,j;
	NODE *p=Line[rail][point].next;

	while (p){

		if (!judge_visit(p->Rail,p->Num)&&top<=len) dfs(p->Rail,p->Num,d_rail,d_point);  //�����ǰ��û�б����ʹ�������dfs 

		p=p->next;
	
	}
	
	pop(rail,point);  //��·ʱ��ջ��������ǣ� 
	return; 		
}


void path_output_undertime(){   //���ʱ����̵�·�� 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("�Ƽ�·��%d :\n",i);
		printf("\tԤ��ʱ��:");
		color(14);
		printf("%dmin",path_time[i][path_time[i][0].rail].time_sum);
		color(7);
		printf("\tƱ��:");
		color(14);
		printf("%dr",path_time[i][path_time[i][0].rail].price);
		color(7);
		printf("\tƽ��ӵ���̶�:");
		color(14);
		printf("%.1lf%%\n\n",path_time[i][path_time[i][0].rail].crowd_sum);
		color(7);

		while (path_time[i][j+1].rail>0){
			if(path_time[i][j].rail!=path_time[i][j+1].rail&&j!=1) printf("%s (ת%d����) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j+1].rail);
			 else if (j==1&&path_time[i][j].rail!=path_time[i][j+1].rail) printf("%s(%d����) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j+1].rail); else printf("%s(%d����) -> ",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j].rail);
			j++;
		}
		printf("%s(%d����)\n\n",Line[path_time[i][j].rail][path_time[i][j].point].Name,path_time[i][j].rail);
		
	}
	system("pause");
}
void path_output_weight(){  //�����Ȩ���·�� 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("�Ƽ�·��%d :\n",i);
		printf("\t��Ȩʱ��:");
		color(14);
		printf("%.2lfmin",path_weight[i][path_weight[i][0].rail].time_sum_weight);
		color(7);
		printf("\tԤ��ʱ��:");
		color(14);
		printf("%dmin",path_weight[i][path_weight[i][0].rail].time_sum);
		color(7);
		printf("\tƱ��:");
		color(14);
		printf("%dr\n",path_weight[i][path_weight[i][0].rail].price);
		color(7);


		while (path_weight[i][j+1].rail>0){
			if(path_weight[i][j].rail!=path_weight[i][j+1].rail&&j!=1) printf("%s (ת%d����) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j+1].rail);
			 else if (j==1&&path_weight[i][j].rail!=path_weight[i][j+1].rail) printf("%s (%d����) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j+1].rail); 
				else printf("%s (%d����) -> ",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j].rail);
			j++;
		}
		printf("%s (%d����) \n\n",Line[path_weight[i][j].rail][path_weight[i][j].point].Name,path_weight[i][j].rail );
		
	}


	system("pause");
	
}
void path_output_crowd(){ //�������ӵ���ȵ�·�� 
	int i,j;
	
	for (i=1;i<=3;i++){
		j=1;
		
		
		printf("�Ƽ�·��%d :\n",i);
		printf("\tԤ��ʱ��:");
		color(14);
		printf("%dmin",path_crowd[i][path_crowd[i][0].rail].time_sum);
		color(7);
		printf("\tƱ��:");
		color(14);
		printf("%dr",path_crowd[i][path_crowd[i][0].rail].price);
		color(7);
		printf("\tƽ��ӵ���̶�:");
		color(14);
		printf("%.2lf%%\n\n",path_crowd[i][path_crowd[i][0].rail].crowd_sum);

		color(7);
		while (path_crowd[i][j+1].rail>0){
			if(path_crowd[i][j].rail!=path_crowd[i][j+1].rail&&j!=1) printf("%s (ת%d����) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j+1].rail);
			 else if (j==1&&path_crowd[i][j].rail!=path_crowd[i][j+1].rail) printf("%s (%d����) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j+1].rail); 
				else printf("%s (%d����) -> ",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j].rail);
			j++;
		}
		printf("%s (%d����) \n\n",Line[path_crowd[i][j].rail][path_crowd[i][j].point].Name,path_crowd[i][j].rail );
		
	}
	system("pause");
}
void path_output_overcrowd(){  //������˹���ӵ��·�ߺ��·�� 
	int i,j;
	for (i=1;i<=3;i++){
		j=1;
		printf("�Ƽ�·��%d :\n",i);
		printf("\tԤ��ʱ��:");
		color(14);
		printf("%dmin",path_crowdo[i][path_crowdo[i][0].rail].time_sum);
		color(7);
		printf("\tƱ��:");
		color(14);
		printf("%dr",path_crowdo[i][path_crowdo[i][0].rail].price);
		color(7);
		printf("\tƽ��ӵ���̶�:");
		color(14);
		printf("%.1lf%%\n\n",path_crowdo[i][path_crowdo[i][0].rail].crowd_sum);

		color(7);
		while (path_crowdo[i][j+1].rail>0){
			if(path_crowdo[i][j].rail!=path_crowdo[i][j+1].rail&&j!=1) printf("%s (ת%d����) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j+1].rail);
			 else if (j==1&&path_crowdo[i][j].rail!=path_crowdo[i][j+1].rail) printf("%s (%d����) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j+1].rail); 
				else printf("%s (%d����) -> ",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j].rail);
			j++;
		}
		printf("%s (%d����) \n\n",Line[path_crowdo[i][j].rail][path_crowdo[i][j].point].Name,path_crowdo[i][j].rail );
	} 
	system("pause");
}

