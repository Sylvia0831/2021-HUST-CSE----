#ifndef _PATH_CHOICE_H
#define _PATH_CHOICE_H

extern PATH path_time[4][250];  //ʱ�����ޣ�Ʊ�۴�֮ 
extern PATH path_crowd[4][250];  //ӵ�����ȣ�Ʊ�۴�֮ 
extern PATH path_weight[4][250];
extern PATH path_crowdo[4][250];

extern int for_next_time,rev_next_time;
void next_ug(int num_s,int flag_s,int hour,int minute); 	//��ѯ��������һ�г���վʱ�䣬������������ 
void next_ug_fun(int num_s,int flag_s,int hour,int minute);	// ͬ�ϣ������Ӻ�����
void PathTime();	// ��ÿһ��·�ߵ�ÿһվ�����ӵ���ȡ���վʱ����м��㣬Ϊ������·��ɸѡ������������ 
int Path_undertime();	// ɸѡ����������ʱ���·����
void crowd_seting();	// ӵ�������ã�
int path_underweight();	// ɸѡ����������ӵ���Ⱥ�ʱ���Ȩ��·����
int path_undercrowd();	// ɸѡ������ӵ���ȵ�������С·����
int path_underovercrowd();	// ɸѡ�����ȹ��˹���ӵ��·�ߵ�·���� 
int time_last (int rail,int point,int flag);	// ���ص�ǰվĩ�೵ʱ�䣻

#endif

