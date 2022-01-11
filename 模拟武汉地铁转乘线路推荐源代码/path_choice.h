#ifndef _PATH_CHOICE_H
#define _PATH_CHOICE_H

extern PATH path_time[4][250];  //时间有限，票价次之 
extern PATH path_crowd[4][250];  //拥挤优先，票价次之 
extern PATH path_weight[4][250];
extern PATH path_crowdo[4][250];

extern int for_next_time,rev_next_time;
void next_ug(int num_s,int flag_s,int hour,int minute); 	//查询两方向下一列车到站时间，用于主函数； 
void next_ug_fun(int num_s,int flag_s,int hour,int minute);	// 同上，用于子函数；
void PathTime();	// 对每一条路线的每一站的相关拥挤度、到站时间进行计算，为后续的路线筛选作基础函数； 
int Path_undertime();	// 筛选出三条基于时间的路径；
void crowd_seting();	// 拥挤度设置；
int path_underweight();	// 筛选出三条基于拥挤度和时间加权的路径；
int path_undercrowd();	// 筛选出基于拥挤度的三条最小路径；
int path_underovercrowd();	// 筛选出优先过滤过度拥挤路线的路径； 
int time_last (int rail,int point,int flag);	// 返回当前站末班车时间；

#endif

