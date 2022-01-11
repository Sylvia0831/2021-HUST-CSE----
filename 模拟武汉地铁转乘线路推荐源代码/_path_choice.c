/**************************************** 
基于不同需求的路径选择 
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
/*以下为工程的全局变量，方便查看故放在次*/ 

/*typedef struct PATH{
	int rail;
	int point;
	int time_ride;  //乘车时间 每站2分钟   到该站下车使用的 乘车时间，起始站默认为0  以及 在转换成的时候是否有等待时间 
	double time_walk;  //步行时间   转乘产生 
	int time_wait;  // 等车时间  第一站之前等待时间， 转乘等待时间 
	double time_sum_weight
	int time_sum;  // 时间总和 
	
//	int flag;
	int crowd;   //拥挤数 
	int now_time;  //当前时间  当前站下车时间 
	int dist;    //耗费距离  当前站下车耗费距离 
	//int Flag[9];
	int price;
	inr flag;
}PATH;
extern PATH path[1000][250];
int path_num;
*/ 
struct MIN_MARK{
	int num;// 序号 
	int elem1;   //优先排序  
	int elem2;  //次之排序 
	double elem3;  //优先排序的浮点型    加权时间或者平均拥挤度 
}minn[1000];
PATH path_time[4][250];  //时间有限，票价次之 ，3条路径存储 
PATH path_crowd[4][250];  //拥挤优先，票价次之 ，3条路径存储 
PATH path_weight[4][250];  //加权 时间，3条路径存储 
PATH path_crowdo[4][250];  //过滤过度拥挤路径后的3条路径

int for_next_time,rev_next_time;
int for_next_time_tmp,rev_next_time_tmp;
int crowd_num[9][3700]={0};  //拥挤度设置数组 

void crowd_seting(){  //修改拥挤因子 
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
void next_ug(int num_s,int flag_s,int hour,int minute){  //查询两方向下一列车到站时间 ,用于主程序 

	int i;

	for_next_time=rev_next_time=hour*60+minute;
	int for_first_time=6*60+(flag_s-2)*3+2;
	if (flag_s==1) for_first_time=6*60;
	if (6*60>for_next_time) printf("当前时间不在列车运营时间内！ 列车运营时间为6:00-23:00\n");
	 else {
	 	while(for_first_time<for_next_time-1){
	 		for_first_time+=3;
	 	}
	 	for_next_time=for_first_time;  //约定停车的间隔一分钟两个时刻均可以上车 
	 	if (time_last(num_s,flag_s,0)<for_next_time) {
	 		printf("当前时间当前站点已无正行列车运行！\n");
	 	}else{
	 	
		int for_hour=for_next_time/60;
		int for_minute=for_next_time %60;
	 	int for_hour_leave=(for_next_time+1)/60;
		int for_minute_leave=(for_next_time+1)%60;
		
		if (flag_s==1 ) printf("最近一趟正行列车发车时间为%d时%d分\n",for_hour,for_minute); else printf("最近一趟正行地铁于%d时%d分到站,%d时%d分启动离站\n",for_hour,for_minute,for_hour_leave,for_minute_leave); }
	 }

	int rev_first_time=6*60+(sites[num_s]-flag_s-1)*3+2;   //反向查询下一列车到站时间 
	if (flag_s==sites[num_s] ) rev_first_time=6*60;
	
	if (6*60>rev_next_time)  printf("当前时间为列车非运营时间！ 列车运营时间为6:00-23:00\n");
	 else {
	 	while(rev_first_time<rev_next_time-1){
	 		rev_first_time+=3;
	 	}
	 	if (time_last(num_s,flag_s,1)<rev_next_time) {
	 		printf("当前时间当前站点已无逆行列车运行！\n");
  
	 	}else {
	 	
	 	rev_next_time=rev_first_time;  //约定停车的间隔一分钟两个时刻均可以上车 
	 	int rev_hour=rev_next_time/60;
		int rev_minute=rev_next_time %60;
		int rev_hour_leave=(rev_next_time+1)/60;
		int rev_minute_leave=(rev_next_time+1)%60;
		if (flag_s==sites[num_s] ) printf("最近一趟逆行列车发车时间为%d时%d分\n",rev_hour,rev_minute); else printf("最近一趟逆行地铁于%d时%d分到站,%d时%d分启动离站\n",rev_hour,rev_minute,rev_hour_leave,rev_minute_leave); }
	 }

	
	
}
void next_ug_fun  (int num_s,int flag_s,int hour ,int minute){   //为后续路线筛选函数的辅助函数 
	int i;
	for_next_time_tmp=rev_next_time_tmp=hour*60+minute;
	int for_first_time=6*60+(flag_s-2)*3+2;
	if (flag_s==1) for_first_time=6*60;
 	while(for_first_time<for_next_time_tmp-1){
 		for_first_time+=3;
 	}
 	for_next_time_tmp=for_first_time;  //约定停车的间隔一分钟两个时刻均可以上车 


	int rev_first_time=6*60+(sites[num_s]-flag_s-1)*3+2;   //反向查询下一列车到站时间 
	if (flag_s==sites[num_s] ) rev_first_time=6*60;
	

 	while(rev_first_time<rev_next_time_tmp-1){
 		rev_first_time+=3;
 	}
 	rev_next_time_tmp=rev_first_time;  //约定停车的间隔一分钟两个时刻均可以上车 
}

int time_last(int rail,int point,int flag){  //flag 用于标记正向反向，正向为0，反向为1；  
//返回当前站末班车时间 ,包括停车的一分钟 
	if (flag==0){
		if (point==1) return 23*60; 
		return (point-1)*3+23*60;	
	}
	else{
		if(point==sites[rail]) return 23*60;
		return (sites[rail]-point)*3+23*60;
		
	}
}


void PathTime(){   //所有可行路径信息处理，包括预计时间、拥挤度、加权时间、票价  
	int i,j,k;
	double x;
	for (i=1;i<=path_num;i++){   //对每条可行路进行统计 
		path[i][0].flag=1;
		int line_tmp,num_tmp;	//  第一个节点特殊处理  
		if(path[i][1].rail!=path[i][2].rail){// 如果当前到下一点是换线，那么正向逆向判断需要换线 
			line_tmp=path[i][2].rail;
			num_tmp=Line[path[i][1].rail][path[i][1].point].Flag[path[i][2].rail];
			path[i][1].last_time_for=time_last(line_tmp,num_tmp,0);
			path[i][1].last_time_rev=time_last(line_tmp,num_tmp,1);
			if(path[i][2].point>Line[line_tmp][num_tmp].Num) {  //正向 
				if(path[i][1].last_time_for<hour*60+minute) path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //判断是否可达 
				path[i][1].time_wait=for_next_time-hour*60-minute;
				if(path[i][1].time_wait<0) path[i][1].time_wait=0;
				path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
				if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				
			}
			else {
				if(path[i][2].point<Line[line_tmp][num_tmp].Num){  //逆向 
					if(path[i][1].last_time_rev<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //判断是否可达 
					path[i][1].time_wait=rev_next_time-hour*60-minute;   
					if(path[i][1].time_wait<0) path[i][1].time_wait=0; 
					path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
					if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				}
			}
		}else {
			path[i][1].last_time_for=time_last(path[i][1].rail,path[i][1].point,0);
			path[i][1].last_time_rev=time_last(path[i][1].rail,path[i][1].point,1);
			if(path[i][2].point>path[i][1].point) {  //正向 
				if(path[i][1].last_time_for<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //判断是否可达 
				path[i][1].time_wait=for_next_time-hour*60-minute;
				if(path[i][1].time_wait<0) path[i][1].time_wait=0;
				path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
				if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
			}
			else {
				if(path[i][2].point<path[i][1].point){  //逆向 
					if(path[i][1].last_time_rev<hour*60+minute)  path[i][1].flag=path[i][0].flag=0; else path[i][1].flag=1;  //判断是否可达 
					path[i][1].time_wait=rev_next_time-hour*60-minute;  
					if(path[i][1].time_wait<0) path[i][1].time_wait=0;
					path[i][1].now_time=hour*60+minute+path[i][1].time_wait; 
					if(for_next_time>=hour*60+minute) path[i][1].time_ride=1; else path[i][1].time_ride=0;
				}
			}
		}
		path[i][1].time_walk=0;
		path[i][1].dist=0;
		path[i][1].crowd=crowd_num[path[i][1].rail][path[i][1].now_time];//当前站的拥挤系数 
		path[i][1].crowd_sum=path[i][1].crowd;
		if (path[i][1].crowd<=20) x=0.6; else x=1.5;
		path[i][1].time_sum_weight=path[i][1].time_wait+path[i][1].time_ride*x;
		for(j=2;j<=path[i][0].rail;j++){  //每条路的每个节点进行计算 ,从第二个开始  
			path[i][j].flag=1;//默认为可达，除初始站点需要判断外，换乘还需要判断，其他不需要。最终本条路是否可达，记录在path[i][0].flag中 
		 	path[i][j].last_time_for=time_last(path[i][j].rail,path[i][j].point,0);
		 	path[i][j].last_time_rev=time_last(path[i][j].rail,path[i][j].point,1);
		  	path[i][j].dist=path[i][j-1].dist + dist_site[path[i][j].rail];  //距离计算只需要累计之前的距离，加上上一站到本站的距离 
			if(j!=path[i][0].rail)	path[i][j].time_ride=3;   //不是终点站乘车时间为3min 
				else path[i][j].time_ride=2;  //是终点站到站下车，乘车时间为2min 
			if(j!=path[i][0].rail&&path[i][j].rail!=path[i][j+1].rail){   //本站换乘 
				path[i][j].time_ride--;  //换乘也是到站下车，乘车时间为 2min
				path[i][j].time_walk=3.5;
				line_tmp=path[i][j+1].rail;
				num_tmp=Line[path[i][j].rail][path[i][j].point].Flag[path[i][j+1].rail];	
				path[i][j].last_time_for=time_last(line_tmp,num_tmp,0);
		 		path[i][j].last_time_rev=time_last(line_tmp,num_tmp,1);//换乘需要换线，重新设置末班车时间 
				if(path[i][j+1].point>path[line_tmp][num_tmp].point){  //正向 
					int now_time_hour;
					int now_time_minute;
					path[i][j].now_time=path[i][j-1].now_time+4+path[i][j].time_ride;
					if (path[i][j].now_time>path[i][j].last_time_for) path[i][j].flag=path[i][0].flag=0; else path[i][j].flag=1;
					now_time_hour=path[i][j].now_time/60;
					now_time_minute=path[i][j].now_time %60;
					next_ug_fun(path[i][j+1].rail,path[i][j+1].point,now_time_hour,now_time_minute);
					if(for_next_time_tmp==path[i][j].now_time) {  //等0.5分钟 
						path[i][j].time_wait=0.5;
						path[i][j].time_ride=1;
						path[i][j].now_time+=1;
					} else{
						if(for_next_time_tmp==path[i][j].now_time-1) {  //直接上车 
							path[i][j].time_wait=0;
							path[i][j].time_ride=0.5;
						}
						else {
							if (for_next_time_tmp==path[i][j].now_time+1){  //等1.5分钟 
								path[i][j].time_wait=1.5;
								path[i][j].time_ride=1;
								path[i][j].now_time+=2;
							}
						}
					}	
				}
				else{  //逆向 
					int now_time_hour;
					int now_time_minute;
					path[i][j].now_time=path[i][j-1].now_time+4+path[i][j].time_ride;
					if (path[i][j].now_time>path[i][j].last_time_rev)  path[i][j].flag=path[i][0].flag=0; else path[i][j].flag=1;
					now_time_hour=path[i][j].now_time/60;
					now_time_minute=path[i][j].now_time %60;
					next_ug_fun(path[i][j+1].rail,path[i][j+1].point,now_time_hour,now_time_minute);
					if(rev_next_time_tmp==path[i][j].now_time) {  //等0.5分钟 
						path[i][j].time_wait=0.5;
						path[i][j].time_ride=1;
						path[i][j].now_time+=1;
					} else{
						if(rev_next_time_tmp==path[i][j].now_time-1) {  //直接上车 
							path[i][j].time_wait=0;
							path[i][j].time_ride=0.5;	
						}
						else {
							if (rev_next_time_tmp==path[i][j].now_time+1){  //等1.5分钟 
								path[i][j].time_wait=1.5;
								path[i][j].time_ride=1;
								path[i][j].now_time+=2;
							}
						}
					}	
				}

			}else{  //本站不换乘 
				 	 path[i][j].time_wait=0;
				 	 path[i][j].time_walk=0;
					 path[i][j].now_time=path[i][j-1].now_time+path[i][j].time_ride;
			}
			path[i][j].crowd=crowd_num[path[i][j].rail][path[i][j].now_time];//上一站到当前站的拥挤系数 
			if (path[i][j].crowd<=20) x=0.6; else x=1.5;  //权重赋值 
			path[i][j].crowd_sum=path[i][j-1].crowd_sum+path[i][j].crowd;
			path[i][j].time_sum_weight=path[i][j-1].time_sum_weight+path[i][j].time_walk+path[i][j].time_wait+path[i][j].time_ride*x;
		} 
		path[i][path[i][0].rail].time_sum=path[i][path[i][0].rail].now_time-hour*60-minute;  //预计使用时间 
		path[i][path[i][0].rail].crowd_sum=path[i][path[i][0].rail].crowd_sum/(path[i][0].rail);  //平均拥挤度 
		if (path[i][path[i][0].rail].dist<=4){  //计算票价 
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
int  cmp( const   void   * a,  const   void   * b){          //rel从大到小,no从小到大   比较函数1 （整数比较） 
     struct  MIN_MARK  *c  =  (struct MIN_MARK *)a ;
     struct  MIN_MARK  *d  =  (struct MIN_MARK *)b ;
     if (c -> elem1 != d -> elem1)   return  c -> elem1  -  d -> elem1 ;
     else      return  c -> elem2  -  d -> elem2 ;
}
int cmp_d ( const   void   * a,  const   void   * b){   //双关键字比较函数2（浮点型比较） 
	struct  MIN_MARK  *c  =  (struct MIN_MARK *)a ;
     struct  MIN_MARK  *d  =  (struct MIN_MARK *)b ;
     if (c -> elem3 != d -> elem3)   return  c->elem3 > d->elem3 ?1:-1 ;
     else      return  c -> elem1  -  d -> elem1 ;
}


int Path_undertime(){   //筛选出时间最小的三条路径 
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
int path_underweight(){  //筛选出3条加权时间最小的的路径 
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
int path_undercrowd(){  //筛选出3条拥挤度最小的的路径 
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
int path_underovercrowd(){  //筛选出3条过滤过度拥挤后的路径 
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
		while (minn[k-1].elem3>55){   //以60为拥挤度标准 
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






