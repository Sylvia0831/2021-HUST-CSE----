#ifndef _PATH_FIND_H
#define _PATH_FIND_H


typedef struct PATH{
	int rail;//��·�� 
	int point;   //��վ�����к� 
	double time_ride;  //��վҪ�õĳ˳�ʱ�䣨����Ϊ2��������Ϊ3�� 
	double time_walk;  //��վ��ʹ�õĲ���ʱ�䣨���˲����� 
	double time_wait;   //��վ���õĵȴ�ʱ�䣨��ҪΪ���˺͵�һվ�ȳ��������� 
	int time_sum;   //����վ���õ���ʱ�� 
	double time_sum_weight;   //����վ��ʱ���Ȩ�ܺ� 
	int crowd;   //��һվ����վ��ӵ���� 
	double crowd_sum;   //ӵ�����ܺ� 
	int now_time;  //��ǰվ�³���ʱ�� 
	double dist;   //����վ�ľ��� 
	int price;   //����վ��Ʊ�� 
	int last_time_for;  //����վ������ĩ�೵ʱ��
	int last_time_rev; //����վ�ķ���ĩ�೵ʱ��
	int flag;  //��ǰվ�Ƿ�ɴ�  1Ϊ���ԣ�0Ϊ������(��ҪΪ�ж�ĩ�೵�� 
}PATH;
extern PATH path[1000][250];

extern char start[30],dest[30];
extern int num_s,flag_s,num_d,flag_d;

extern PATH stack[500];  //dfs����ջ   
extern int visit[9][40]; //����Ƿ���ʹ� 

extern int path_num,top;//��¼·���� ,ջ�� 
extern int flag_empty;
extern int path_len[50];
extern int len_i,len;
extern int len_sum;

int judge_transfer(int num,int flag);	// �ж��Ƿ�ת�ˣ�
void input_S();	// ������㣻
void input_D();	// �����յ㣻
void push(int rail,int point);	// ��ջ��
void pop(int rail,int point);	// ��ջ��
int judge_visit(int rail,int point);	// �жϵ�ǰ�ڵ��Ƿ���ʹ���

void dfs(int rail,int point,int d_rail,int d_point);	// DFS�ݹ�����·��

void path_output_undertime();	// �������ʱ�������·�� 
void path_output_weight();	// ������ڼ�Ȩ������·�� 
void path_output_crowd();	// �������ӵ���ȵ�����·�� 
void path_input_co();	// ������˹���ӵ��·�ߺ�ʱ�����������·�� 


#endif
