#ifndef _BUILD_H
#define _BUILD_H

typedef struct Node{
	char Name[30];  //站点名称 
	int Rail;  //线路号 
	int Num;   //当前线路的站点序号 
	double Dist;  //距离 
	int Flag[9];   //标记转乘，下标表示转乘线路，内容为转乘站点序列号 
	struct Node* next;  //邻接表
 
}NODE;
extern NODE Line[9][40],*tmp1,*tmp2,*tmp3,*tmp4;
extern double dist[10];
extern int sites[10];
extern int people[10];
extern double dist_site[10]; 



void Build_Site(void);  //建立邻接表，完成无向图建图 



#endif
