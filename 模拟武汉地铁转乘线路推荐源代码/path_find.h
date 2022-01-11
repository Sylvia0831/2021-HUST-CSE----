#ifndef _PATH_FIND_H
#define _PATH_FIND_H


typedef struct PATH{
	int rail;//线路号 
	int point;   //本站的序列号 
	double time_ride;  //本站要用的乘车时间（换乘为2，不换乘为3） 
	double time_walk;  //本站做使用的步行时间（换乘产生） 
	double time_wait;   //本站所用的等待时间（主要为换乘和第一站等车来产生） 
	int time_sum;   //到本站所用的总时间 
	double time_sum_weight;   //到本站的时间加权总和 
	int crowd;   //上一站到本站的拥挤度 
	double crowd_sum;   //拥挤度总和 
	int now_time;  //当前站下车的时间 
	double dist;   //到本站的距离 
	int price;   //到本站的票价 
	int last_time_for;  //到本站的正向末班车时间
	int last_time_rev; //到本站的反向末班车时间
	int flag;  //当前站是否可达  1为可以，0为不可以(主要为判断末班车） 
}PATH;
extern PATH path[1000][250];

extern char start[30],dest[30];
extern int num_s,flag_s,num_d,flag_d;

extern PATH stack[500];  //dfs辅助栈   
extern int visit[9][40]; //标记是否访问过 

extern int path_num,top;//记录路线数 ,栈顶 
extern int flag_empty;
extern int path_len[50];
extern int len_i,len;
extern int len_sum;

int judge_transfer(int num,int flag);	// 判断是否转乘；
void input_S();	// 输入起点；
void input_D();	// 输入终点；
void push(int rail,int point);	// 入栈；
void pop(int rail,int point);	// 出栈；
int judge_visit(int rail,int point);	// 判断当前节点是否访问过；

void dfs(int rail,int point,int d_rail,int d_point);	// DFS递归搜索路径

void path_output_undertime();	// 输出基于时间的三条路径 
void path_output_weight();	// 输出基于加权的三条路径 
void path_output_crowd();	// 输出基于拥挤度的三条路径 
void path_input_co();	// 输出过滤过度拥挤路线后按时间排序的三条路径 


#endif
