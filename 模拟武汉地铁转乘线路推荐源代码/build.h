#ifndef _BUILD_H
#define _BUILD_H

typedef struct Node{
	char Name[30];  //վ������ 
	int Rail;  //��·�� 
	int Num;   //��ǰ��·��վ����� 
	double Dist;  //���� 
	int Flag[9];   //���ת�ˣ��±��ʾת����·������Ϊת��վ�����к� 
	struct Node* next;  //�ڽӱ�
 
}NODE;
extern NODE Line[9][40],*tmp1,*tmp2,*tmp3,*tmp4;
extern double dist[10];
extern int sites[10];
extern int people[10];
extern double dist_site[10]; 



void Build_Site(void);  //�����ڽӱ��������ͼ��ͼ 



#endif
