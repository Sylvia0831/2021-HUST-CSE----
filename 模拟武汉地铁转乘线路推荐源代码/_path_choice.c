/**************************************** 
���ڲ�ͬ�����·��ѡ�� 
****************************************/ 
#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "build.h" 
#include "path_find.h"
#include "system.h" 
#include "help.h" 
#include "basic.h"
#include "path_choice.h"

#define INF  989898
/*����Ϊ���̵�ȫ�ֱ���������鿴�ʷ��ڴ�*/ 

/*typedef struct PATH{
	int rail;
	int point;
	int time_ride;  //�˳�ʱ�� ÿվ2����   ����վ�³�ʹ�õ� �˳�ʱ�䣬��ʼվĬ��Ϊ0  �Լ� ��ת���ɵ�ʱ���Ƿ��еȴ�ʱ�� 
	double time_walk;  //����ʱ��   ת�˲��� 
	int time_wait;  // �ȳ�ʱ��  ��һվ֮ǰ�ȴ�ʱ�䣬 ת�˵ȴ�ʱ�� 
	double time_sum_weight
	int time_sum;  // ʱ���ܺ� 
	
//	int flag;
	int crowd;   //ӵ���� 
	int now_time;  //��ǰʱ��  ��ǰվ�³�ʱ�� 
	int dist;    //�ķѾ���  ��ǰվ�³��ķѾ��� 
	//int Flag[9];
	int price;
	inr flag;
}PATH;
extern PATH path[1000][250];
int path_num;
*/ 
struct MIN_MARK{
	int num;// ��� 
	int elem1;   //��������  
	int elem2;  //��֮���� 
	double elem3;  //��������ĸ�����    ��Ȩʱ�����ƽ��ӵ���� 
}minn[1000];
PATH path_time[4][250];  //ʱ�����ޣ�Ʊ�۴�֮ ��3��·���洢 
PATH path_crowd[4][250];  //ӵ�����ȣ�Ʊ�۴�֮ ��3��·���洢 
PATH path_weight[4][250];  //��Ȩ ʱ�䣬3��·���洢 
PATH path_crowdo[4][250];  //���˹���ӵ��·�����3��·��

int for_next_time,rev_next_time;
int for_next_time_tmp,rev_next_time_tmp;
int crowd_num[9][3700]={0};  //ӵ������������ 

void crowd_seting(){  //�޸�ӵ������ 
	int i;
	for (i=0;i<=1440;i++){
		crowd_num[1][i]=crowd_num[3][i]=40;
		crowd_num[8][i]=20;
		crowd_num[2][i]=crowd_num[4][i]=50;
		crowd_num[6][i]=crowd_num[7][i]=15;
	}
	for (i=450;i<=540;i++){
		crowd_num[1][i]=crowd_num[3][i]=80;
	}
	for (i=990;i<=1110;i++){
		crowd_num[1][i]=crowd_num[3][i]=75;
	}
	for(i=570;i<=900;i++){
		crowd_num[8][i]=65;
	}
	for (i=1140;i<=1320;i++){
		crowd_num[6][i]=crowd_num[7][i]=65;
	}

}
void next_ug(int num_s,int flag_s,int hour,int minute){  //��ѯ��������һ�г���վʱ�� ,���������� 

	int i;

	for_next_time=rev_next_time=hour*60+minute;
	int for_first_time=6*60+(flag_s-2)*3+2;
	if (flag_s==1) for_first_time=6*60;
	if (6*60>for_next_time) printf("��ǰʱ�䲻���г���Ӫʱ���ڣ� �г���Ӫʱ��Ϊ6:00-23:00\n");
	 else {
	 	while(for_first_time<for_next_time-1){
	 		for_first_time+=3;
	 	}
	 	for_next_time=for_first_time;  //Լ��ͣ���ļ��һ��������ʱ�̾������ϳ� 
	 	if (time_last(num_s,flag_s,0)<for_next_time) {
	 		printf("��ǰʱ�䵱ǰվ�����������г����У�\n");
	 	}else{
	 	
		int for_hour=for_next_time/60;
		int for_minute=for_next_time %60;
	 	int for_hour_leave=(for_next_time+1)/60;
		int for_minute_leave=(for_next_time+1)%60;
		
		if (flag_s==1 ) printf("���һ�������г�����ʱ��Ϊ%dʱ%d��\n",for_hour,for_minute); else printf("���һ�����е�����%dʱ%d�ֵ�վ,%dʱ%d��������վ\n",for_hour,for_minute,for_hour_leave,for_minute_leave); }
	 }

	int rev_first_time=6*60+(sites[num_s]-flag_s-1)*3+2;   //�����ѯ��һ�г���վʱ�� 
	if (flag_s==sites[num_s] ) rev_first_time=6*60;
	
	if (6*60>rev_next_time)  printf("��ǰʱ��Ϊ�г�����Ӫʱ�䣡 �г���Ӫʱ��Ϊ6:00-23:00\n");
	 else {
	 	while(rev_first_time<rev_next_time-1){
	 		rev_first_time+=3;
	 	}
	 	if (time_last(num_s,flag_s,1)<rev_next_time) {
	 		printf("��ǰʱ�䵱ǰվ�����������г����У�\n");
  
	 	}else {
	 	
	 	rev_next_time=rev_first_time;  //Լ��ͣ���ļ��һ��������ʱ�̾������ϳ� 
	 	int rev_hour=rev_next_time/60;
		int rev_minute=rev_next_time %60;
		int rev_hour_leave=(rev_next_time+1)/60;
		int rev_minute_leave=(rev_next_time+1)%60;
		if (flag_s==sites[num_s] ) printf("���һ�������г�����ʱ��Ϊ%dʱ%d��\n",rev_hour,rev_minute); else printf("���һ�����е�����%dʱ%d�ֵ�վ,%dʱ%d��������վ\n",rev_hour,rev_minute,rev_hour_leave,rev_minute_leave); }
	 }

	
	
}
void next_ug_fun  (int num_s,int flag_s,int hour ,int minute){   //Ϊ����·��ɸѡ�����ĸ������� 
	int i;
	for_next_time_tmp=rev_next_time_tmp=hour*60+minute;
	int for_first_time=6*60+(flag_s-2)*3+2;
	if (flag_s==1) for_first_time=6*60;
 	while(for_first_time<for_next_time_tmp-1){
 		for_first_time+=3;
 	}
 	for_next_time_tmp=for_first_time;  //Լ��ͣ���ļ��һ��������ʱ�̾������ϳ� 


	int rev_first_time=6*60+(sites[num_s]-flag_s-1)*3+2;   //�����ѯ��һ�г���վʱ�� 
	if (flag_s==sites[num_s] ) rev_first_time=6*60;
	

 	while(rev_first_time<rev_next_time_tmp-1){
 		rev_first_time+=3;
 	}
 	rev_next_time_tmp=rev_first_time;  //Լ��ͣ���ļ��һ��������ʱ�̾������ϳ� 
}

int time_last(int rail,int point,int flag){  //flag ���ڱ������������Ϊ0������Ϊ1��  
//���ص�ǰվĩ�೵ʱ�� ,����ͣ����һ���� 
	if (flag==0){
		if (point==1) return 23*60; 
		return (point-1)*3+23*60;	
	}
	else{
		if(point==sites[rail]) return 23*60;
		return (sites[rail]-point)*3+23*60;
		
	}
}


void PathTime(){   //���п���·����Ϣ��������Ԥ��ʱ�䡢ӵ���ȡ���Ȩʱ�䡢Ʊ��  
	int i,j,k;
	double x;
	for (i=1;i<=path_num;i++){   //��ÿ������·����ͳ�� 
		path[i][0].flag=1;
		int line_tmp,num_tmp;	//  ��һ���ڵ����⴦��  
		if(path[i][1].rail!=path[i][2].rail){// �����ǰ����һ���ǻ��ߣ���ô���������ж���Ҫ���� 
			line_tmp=path[i][2].rail;
			num_tmp=Line[path[i][1].rail][path[i][1].point].Flag[path[i][2].rail];
			path[i][1].last_time_for=time_last(line_tmp,num_tmp,0);
			path[i][1].last_time_rev=time_last(line_tmp,num_tmp,1);
			if(path[i][2].point>Line[line_tmp][num_tmp].Num) {  //���� 
				if(path[i][1].last_time_for<hour*60+minute) path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //�ж��Ƿ�ɴ� 
				path[i][1].time_wait=for_next_time-hour*60-minute;
				if(path[i][1].time_wait<0) path[i][1].time_wait=0;
				path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
				if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				
			}
			else {
				if(path[i][2].point<Line[line_tmp][num_tmp].Num){  //���� 
					if(path[i][1].last_time_rev<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //�ж��Ƿ�ɴ� 
					path[i][1].time_wait=rev_next_time-hour*60-minute;   
					if(path[i][1].time_wait<0) path[i][1].time_wait=0; 
					path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
					if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				}
			}
		}else {
			path[i][1].last_time_for=time_last(path[i][1].rail,path[i][1].point,0);
			path[i][1].last_time_rev=time_last(path[i][1].rail,path[i][1].point,1);
			if(path[i][2].point>path[i][1].point) {  //���� 
				if(path[i][1].last_time_for<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //�ж��Ƿ�ɴ� 
				path[i][1].time_wait=for_next_time-hour*60-minute;
				if(path[i][1].time_wait<0) path[i][1].time_wait=0;
				path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
				if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
			}
			else {
				if(path[i][2].point<path[i][1].point){  //���� 
					if(path[i][1].last_time_rev<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //�ж��Ƿ�ɴ� 
					path[i][1].time_wait=rev_next_time-hour*60-minute;  
					if(path[i][1].time_wait<0) path[i][1].time_wait=0;
					path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
					if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				}
			}
		}
		path[i][1].time_walk=0;
		path[i][1].dist=0;
		path[i][1].crowd=crowd_num[path[i][1].rail][path[i][1].now_time];//��ǰվ��ӵ��ϵ�� 
		path[i][1].crowd_sum=path[i][1].crowd;
		if (path[i][1].crowd<=20) x=0.6; else x=1.5;
		path[i][1].time_sum_weight=path[i][1].time_wait+path[i][1].time_ride*x;
		for(j=2;j<=path[i][0].rail;j++){  //ÿ��·��ÿ���ڵ���м��� ,�ӵڶ�����ʼ  
			path[i][j].flag=1;//Ĭ��Ϊ�ɴ����ʼվ����Ҫ�ж��⣬���˻���Ҫ�жϣ���������Ҫ�����ձ���·�Ƿ�ɴ��¼��path[i][0].flag�� 
		 	path[i][j].last_time_for=time_last(path[i][j].rail,path[i][j].point,0);
		 	path[i][j].last_time_rev=time_last(path[i][j].rail,path[i][j].point,1);
		  	path[i][j].dist=path[i][j-1].dist + dist_site[path[i][j].rail];  //�������ֻ��Ҫ�ۼ�֮ǰ�ľ��룬������һվ����վ�ľ��� 
			if(j!=path[i][0].rail)	path[i][j].time_ride=3;   //�����յ�վ�˳�ʱ��Ϊ3min 
				else path[i][j].time_ride=2;  //���յ�վ��վ�³����˳�ʱ��Ϊ2min 
			if(j!=path[i][0].rail&&path[i][j].rail!=path[i][j+1].rail){   //��վ���� 
				path[i][j].time_ride--;  //����Ҳ�ǵ�վ�³����˳�ʱ��Ϊ 2min
				path[i][j].time_walk=3.5;
				line_tmp=path[i][j+1].rail;
				num_tmp=Line[path[i][j].rail][path[i][j].point].Flag[path[i][j+1].rail];	
				path[i][j].last_time_for=time_last(line_tmp,num_tmp,0);
		 		path[i][j].last_time_rev=time_last(line_tmp,num_tmp,1);//������Ҫ���ߣ���������ĩ�೵ʱ�� 
				if(path[i][j+1].point>path[line_tmp][num_tmp].point){  //���� 
					int now_time_hour;
					int now_time_minute;
					path[i][j].now_time=path[i][j-1].now_time+4+path[i][j].time_ride;
					if (path[i][j].now_time>path[i][j].last_time_for) path[i][j].flag=path[i][0].flag=0; else path[i][j].flag=1;
					now_time_hour=path[i][j].now_time/60;
					now_time_minute=path[i][j].now_time %60;
					next_ug_fun(path[i][j+1].rail,path[i][j+1].point,now_time_hour,now_time_minute);
					if(for_next_time_tmp==path[i][j].now_time) {  //��0.5���� 
						path[i][j].time_wait=0.5;
						path[i][j].time_ride=1;
						path[i][j].now_time+=1;
					} else{
						if(for_next_time_tmp==path[i][j].now_time-1) {  //ֱ���ϳ� 
							path[i][j].time_wait=0;
							path[i][j].time_ride=0.5;
						}
						else {
							if (for_next_time_tmp==path[i][j].now_time+1){  //��1.5���� 
								path[i][j].time_wait=1.5;
								path[i][j].time_ride=1;
								path[i][j].now_time+=2;
							}
						}
					}	
				}
				else{  //���� 
					int now_time_hour;
					int now_time_minute;
					path[i][j].now_time=path[i][j-1].now_time+4+path[i][j].time_ride;
					if (path[i][j].now_time>path[i][j].last_time_rev)  path[i][j].flag=path[i][0].flag=0; else path[i][j].flag=1;
					now_time_hour=path[i][j].now_time/60;
					now_time_minute=path[i][j].now_time %60;
					next_ug_fun(path[i][j+1].rail,path[i][j+1].point,now_time_hour,now_time_minute);
					if(rev_next_time_tmp==path[i][j].now_time) {  //��0.5���� 
						path[i][j].time_wait=0.5;
						path[i][j].time_ride=1;
						path[i][j].now_time+=1;
					} else{
						if(rev_next_time_tmp==path[i][j].now_time-1) {  //ֱ���ϳ� 
							path[i][j].time_wait=0;
							path[i][j].time_ride=0.5;	
						}
						else {
							if (rev_next_time_tmp==path[i][j].now_time+1){  //��1.5���� 
								path[i][j].time_wait=1.5;
								path[i][j].time_ride=1;
								path[i][j].now_time+=2;
							}
						}
					}	
				}

			}else{  //��վ������ 
				 	 path[i][j].time_wait=0;
				 	 path[i][j].time_walk=0;
					 path[i][j].now_time=path[i][j-1].now_time+path[i][j].time_ride;
			}
			path[i][j].crowd=crowd_num[path[i][j].rail][path[i][j].now_time];//��һվ����ǰվ��ӵ��ϵ�� 
			if (path[i][j].crowd<=20) x=0.6; else x=1.5;  //Ȩ�ظ�ֵ 
			path[i][j].crowd_sum=path[i][j-1].crowd_sum+path[i][j].crowd;
			path[i][j].time_sum_weight=path[i][j-1].time_sum_weight+path[i][j].time_walk+path[i][j].time_wait+path[i][j].time_ride*x;
		} 
		path[i][path[i][0].rail].time_sum=path[i][path[i][0].rail].now_time-hour*60-minute;  //Ԥ��ʹ��ʱ�� 
		path[i][path[i][0].rail].crowd_sum=path[i][path[i][0].rail].crowd_sum/(path[i][0].rail);  //ƽ��ӵ���� 
		if (path[i][path[i][0].rail].dist<=4){  //����Ʊ�� 
			path[i][path[i][0].rail].price=2;
		}else if (path[i][path[i][0].rail].dist>4&&path[i][path[i][0].rail].dist<=12){
			path[i][path[i][0].rail].price=2+ceil((path[i][path[i][0].rail].dist-4)/4);
		}else if(path[i][path[i][0].rail].dist>12&&path[i][path[i][0].rail].dist<=24){
			path[i][path[i][0].rail].price=4+ceil((path[i][path[i][0].rail].dist-12)/6);
		}else if (path[i][path[i][0].rail].dist>24&&path[i][path[i][0].rail].dist<=40){
			path[i][path[i][0].rail].price=6+ceil((path[i][path[i][0].rail].dist-24)/8);
		}else if (path[i][path[i][0].rail].dist>40&&path[i][path[i][0].rail].dist<=50){
			path[i][path[i][0].rail].price=8+ceil((path[i][path[i][0].rail].dist-40)/10);
		}else if (path[i][path[i][0].rail].dist>50){
			path[i][path[i][0].rail].price=9+ceil((path[i][path[i][0].rail].dist-50)/20);
		}
	}
}
int  cmp( const   void   * a,  const   void   * b){          //rel�Ӵ�С,no��С����   �ȽϺ���1 �������Ƚϣ� 
     struct  MIN_MARK  *c  =  (struct MIN_MARK *)a ;
     struct  MIN_MARK  *d  =  (struct MIN_MARK *)b ;
     if (c -> elem1 != d -> elem1)   return  c -> elem1  -  d -> elem1 ;
     else      return  c -> elem2  -  d -> elem2 ;
}
int cmp_d ( const   void   * a,  const   void   * b){   //˫�ؼ��ֱȽϺ���2�������ͱȽϣ� 
	struct  MIN_MARK  *c  =  (struct MIN_MARK *)a ;
     struct  MIN_MARK  *d  =  (struct MIN_MARK *)b ;
     if (c -> elem3 != d -> elem3)   return  c->elem3 > d->elem3 ?1:-1 ;
     else      return  c -> elem1  -  d -> elem1 ;
}


int Path_undertime(){   //ɸѡ��ʱ����С������·�� 
	int i,j; 

	for (i=1;i<=path_num;i++){
		minn[i-1].elem3=path[i][path[i][0].rail].crowd_sum;
		minn[i-1].elem1=path[i][path[i][0].rail].time_sum;
		minn[i-1].elem2=path[i][path[i][0].rail].price;
		minn[i-1].num=i;
	}
	qsort(minn,path_num,sizeof(minn[0]),cmp);
	int k=1;
	for (i=1;i<=3;i++){
		while (minn[k-1].elem1==minn[k].elem1&&minn[k-1].elem2==minn[k].elem2){
			k++;
		}
		while (path[minn[k-1].num][0].flag==0&&k<=path_num) k++;
		if (k>=path_num) return 0;
		for(j=1;j<=path[minn[k-1].num][0].rail;j++){
			path_time[i][j].rail=path[minn[k-1].num][j].rail;
			path_time[i][j].point=path[minn[k-1].num][j].point;
		}
		path_time[i][j-1].crowd_sum=minn[k-1].elem3;
		path_time[i][j-1].time_sum=minn[k-1].elem1;
		path_time[i][j-1].price=minn[k-1].elem2;
		path_time[i][0].rail=path[minn[k-1].num][0].rail;
		path_time[i][0].point=minn[k-1].num;
		k++;
	}

	return 1;
	

}
int path_underweight(){  //ɸѡ��3����Ȩʱ����С�ĵ�·�� 
	int i,j;

	for (i=1;i<=path_num;i++){
		minn[i-1].elem3=path[i][path[i][0].rail].time_sum_weight;
		minn[i-1].elem2=path[i][path[i][0].rail].price;
		minn[i-1].elem1=path[i][path[i][0].rail].time_sum;
		minn[i-1].num=i;
	}
	qsort(minn,path_num,sizeof(minn[0]),cmp_d);
	int k=1;
	for (i=1;i<=3;i++){
		while (minn[k-1].elem1==minn[k].elem1&&minn[k-1].elem2==minn[k].elem2&&minn[k-1].elem3==minn[k].elem3){
			k++;
		}
		while (path[minn[k-1].num][0].flag==0&&k<=path_num) k++;
		if (k>path_num) return 0;
		for(j=1;j<=path[minn[k-1].num][0].rail;j++){
			path_weight[i][j].rail=path[minn[k-1].num][j].rail;
			path_weight[i][j].point=path[minn[k-1].num][j].point;
		}
		path_weight[i][j-1].time_sum_weight=minn[k-1].elem3;
		path_weight[i][j-1].time_sum=minn[k-1].elem1;
		path_weight[i][j-1].price=minn[k-1].elem2;
		path_weight[i][0].rail=path[minn[k-1].num][0].rail;
		path_weight[i][0].point=minn[k-1].num;
		k++;
	}
	return 1;
}
int path_undercrowd(){  //ɸѡ��3��ӵ������С�ĵ�·�� 
	int i,j;
	
	for (i=1;i<=path_num;i++){
		minn[i-1].elem3=path[i][path[i][0].rail].crowd_sum;
		minn[i-1].elem2=path[i][path[i][0].rail].price;
		minn[i-1].elem1=path[i][path[i][0].rail].time_sum;
		minn[i-1].num=i;
	}
	qsort(minn,path_num,sizeof(minn[0]),cmp_d);

	int k=1;
	for (i=1;i<=3;i++){
		while (minn[k-1].elem1==minn[k].elem1&&minn[k-1].elem2==minn[k].elem2&&minn[k-1].elem3==minn[k].elem3){
			k++;
		}
		while (path[minn[k-1].num][0].flag==0&&k<=path_num) k++;
		if (k>path_num) return 0;
		for(j=1;j<=path[minn[k-1].num][0].rail;j++){
			path_crowd[i][j].rail=path[minn[k-1].num][j].rail;
			path_crowd[i][j].point=path[minn[k-1].num][j].point;
		}
		path_crowd[i][j-1].crowd_sum=minn[k-1].elem3;
		path_crowd[i][j-1].time_sum=minn[k-1].elem1;
		path_crowd[i][j-1].price=minn[k-1].elem2;
		path_crowd[i][0].rail=path[minn[k-1].num][0].rail;
		k++;
	}
	return 1;
}
int path_underovercrowd(){  //ɸѡ��3�����˹���ӵ�����·�� 
	int i,j;
	for (i=1;i<=path_num;i++){
		minn[i-1].elem3=path[i][path[i][0].rail].crowd_sum;
		minn[i-1].elem2=path[i][path[i][0].rail].price;
		minn[i-1].elem1=path[i][path[i][0].rail].time_sum;
		minn[i-1].num=i;
	}
	qsort(minn,path_num,sizeof(minn[0]),cmp);

	int k=1;
	for (i=1;i<=3;i++){
		while (minn[k-1].elem3>55){   //��60Ϊӵ���ȱ�׼ 
			k++;
		}
		while (path[minn[k-1].num][0].flag==0&&k<=path_num) k++;
		if (k>path_num) return 0;
	
		for(j=1;j<=path[minn[k-1].num][0].rail;j++){
			path_crowdo[i][j].rail=path[minn[k-1].num][j].rail;
			path_crowdo[i][j].point=path[minn[k-1].num][j].point;
		}
		path_crowdo[i][j-1].crowd_sum=minn[k-1].elem3;
		path_crowdo[i][j-1].time_sum=minn[k-1].elem1;
		path_crowdo[i][j-1].price=minn[k-1].elem2;
		path_crowdo[i][0].rail=path[minn[k-1].num][0].rail;
		k++;
	}
	return 1;

}






