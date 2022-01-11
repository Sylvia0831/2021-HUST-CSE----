/**************************************** 
����վ����Ϣ���������ڽӱ��������ͼ��ģ 
****************************************/ 

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<windows.h>
#include "build.h" 
#include "path_find.h"
#include "system.h" 
#include "help.h" 
#include "basic.h"
#include "path_choice.h"

NODE Line[9][40],*tmp1,*tmp2,*tmp3,*tmp4;
double dist[10]={0,38.540,60.80,30.00,50.00,0,43.00,84.00,34.00} ;
int sites[10]={0,32,38,24,37,0,32,37,26};
int people[10]={0,1276,2590,2000,2000,0,2590,2528,2590};
double dist_site[10]; 

void Build_Site(){
	int i,j;
	//����ÿ��վ������ 
	for (i=1;i<=8;i++){
		if (i==5) continue;
		dist_site[i]=dist[i]/(sites[i]-1);

	}
	
	//line1

	
	for (i=1;i<=32;i++){
		Line[1][i].Num=i;
		Line[1][i].Dist=0;
		for (j=1;j<=8;j++) Line[1][i].Flag[j]=0;
		Line[1][i].next=NULL;
		Line[1][i].Rail=1;
	}
	strcpy (Line[1][1].Name,"����վ");
	strcpy (Line[1][2].Name,"����վ");
	strcpy (Line[1][3].Name,"��ͷ̶��԰վ");
	Line[1][3].Flag[6]=2;
	strcpy (Line[1][4].Name,"������վ");
	strcpy (Line[1][5].Name,"�廷���վ");
	strcpy (Line[1][6].Name,"��ͷ��վ");
	strcpy (Line[1][7].Name,"��Ҷ��վ");
	strcpy (Line[1][8].Name,"�����վ");
	strcpy (Line[1][9].Name,"����һ·վ");
	strcpy (Line[1][10].Name,"�����·վ");
	strcpy (Line[1][11].Name,"������·վ");
	strcpy (Line[1][12].Name,"������·վ");
	strcpy (Line[1][13].Name,"����һ·վ");
	strcpy (Line[1][14].Name,"�ڹ�վ");
	Line[1][14].Flag[3]=15;  
	strcpy (Line[1][15].Name,"̫ƽ��վ");
	strcpy (Line[1][16].Name,"�~��·վ");
	strcpy (Line[1][17].Name,"����·վ");
	strcpy (Line[1][18].Name,"���ñ�·վ");
	strcpy (Line[1][19].Name,"����·վ");
	strcpy (Line[1][20].Name,"ѭ����վ");
	Line[1][20].Flag[2]=16;
	strcpy (Line[1][21].Name,"����·վ");
	Line[1][21].Flag[6]=17;
	strcpy (Line[1][22].Name,"����·վ");
	Line[1][22].Flag[7]=19;
	strcpy (Line[1][23].Name,"����·վ");
	Line[1][23].Flag[8]=7;
	strcpy (Line[1][24].Name,"ͷ����վ");
	strcpy (Line[1][25].Name,"����·վ");
	strcpy (Line[1][26].Name,"�����´�վ");
	strcpy (Line[1][27].Name,"��ˮ��վ");
	strcpy (Line[1][28].Name,"����վ");
	strcpy (Line[1][29].Name,"�̽�վ");
	strcpy (Line[1][30].Name,"���Ӹ�վ");
	strcpy (Line[1][31].Name,"�ܿ��³�վ");
	strcpy (Line[1][32].Name,"���ڱ�վ");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[1][2];
	Line[1][1].next=tmp1;//��һվ����ڽӱ�	
	tmp1->Dist=dist_site[1];
	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[1][31];
	Line[1][32].next=tmp2;//���վ����ڽӱ�
	tmp2->Dist=dist_site[1];
	
	for (i=2;i<=31;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[1][i-1];
		Line[1][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[1][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[1][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[1];
		tmp2->Dist=dist_site[1];
		
	} 

	//*************Line[2]*************// 
	for (i=1;i<=38;i++){
		Line[2][i].Num=i;
		Line[2][i].Dist=0;
		for (j=1;j<=8;j++) Line[2][i].Flag[j]=0;
		Line[2][i].next=NULL;
		Line[2][i].Rail=2;
	}
	strcpy (Line[2][1].Name,"��ӻ���վ");
	strcpy (Line[2][2].Name,"�����ܲ�վ");
	strcpy (Line[2][3].Name,"�μҸ�վ");
	strcpy (Line[2][4].Name,"�������վ");
	Line[2][4].Flag[7]=9; 
	strcpy (Line[2][5].Name,"������վ");
	strcpy (Line[2][6].Name,"��ͼ���վ");
	Line[2][6].Flag[3]=1;
	Line[2][6].Flag[8]=2;
	strcpy (Line[2][7].Name,"�����վ");
	strcpy (Line[2][8].Name,"����̶վ");
	strcpy (Line[2][9].Name,"���໨԰վ");
	Line[2][9].Flag[6]=10;
	strcpy (Line[2][10].Name,"����·վ");
	strcpy (Line[2][11].Name,"���ڻ�վ");
	strcpy (Line[2][12].Name,"����վ");
	Line[2][12].Flag[3]=11;
	strcpy (Line[2][13].Name,"���Ҷն�վ");
	Line[2][13].Flag[7]=16;
	strcpy (Line[2][14].Name,"����·վ");
	strcpy (Line[2][15].Name,"��ɽ��԰վ");
	strcpy (Line[2][16].Name,"ѭ����վ");
	Line[2][16].Flag[1]=16;
	strcpy (Line[2][17].Name,"����·վ");
	Line[2][17].Flag[6]=18;
	strcpy (Line[2][18].Name,"������վ");
	strcpy (Line[2][19].Name,"�з�վ");
	Line[2][19].Flag[7]=23;
	strcpy (Line[2][20].Name,"С��ɽվ");
	strcpy (Line[2][21].Name,"��ɽ�㳡վ");
	Line[2][21].Flag[4]=12;
	strcpy (Line[2][22].Name,"����·վ");
	Line[2][22].Flag[4]=13;
	strcpy (Line[2][23].Name,"��ͨ��վ");
	strcpy (Line[2][24].Name,"�ֵ���վ");
	Line[2][24].Flag[8]=18;
	strcpy (Line[2][25].Name,"�㲺��վ");
	strcpy (Line[2][26].Name,"��Ȫվ");
	strcpy (Line[2][27].Name,"�����վ");
	strcpy (Line[2][28].Name,"��ȹ㳡վ");
	strcpy (Line[2][29].Name,"����·վ");
	strcpy (Line[2][30].Name,"���пƼ���ѧվ");
	strcpy (Line[2][31].Name,"��ȴ��վ");
	strcpy (Line[2][32].Name,"��԰·վ");
	strcpy (Line[2][33].Name,"��Ȼ�վ");
	strcpy (Line[2][34].Name,"����ɽ·վ");
	strcpy (Line[2][35].Name,"���ڸ۱�վ");
	strcpy (Line[2][36].Name,"���վ");
	strcpy (Line[2][37].Name,"��������վ");
	strcpy (Line[2][38].Name,"������վ");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[2][2];
	Line[2][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[2][37];
	Line[2][38].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[2];
	tmp2->Dist=dist_site[2];
	
	for (i=2;i<=37;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[2][i-1];
		Line[2][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[2][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[2][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[2];
		tmp2->Dist=dist_site[2];
	} 
	
	
	
	//*************Line[3]*************// 
	
	for (i=1;i<=24;i++){
		Line[3][i].Num=i;
		Line[3][i].Dist=0;
		for (j=1;j<=8;j++) Line[3][i].Flag[j]=0;
		Line[3][i].next=NULL;
		Line[3][i].Rail=3;
	}
	strcpy (Line[3][1].Name,"��ͼ���վ");
	Line[3][1].Flag[2]=6;
	Line[3][1].Flag[8]=2;
	strcpy (Line[3][2].Name,"����֮��վ");
	strcpy (Line[3][3].Name,"������վ");
	strcpy (Line[3][4].Name,"��ҵ·վ");
	strcpy (Line[3][5].Name,"����С·վ");
	strcpy (Line[3][6].Name,"�޼�ׯվ");
	strcpy (Line[3][7].Name,"�Լ���վ");
	Line[3][7].Flag[8]=6;
	strcpy (Line[3][8].Name,"�ݼö�·վ");
	strcpy (Line[3][9].Name,"���·վ");
	Line[3][9].Flag[6]=15;
	Line[3][9].Flag[7]=18;
	strcpy (Line[3][10].Name,"��Ǻ�վ");
	strcpy (Line[3][11].Name,"����վ");
	Line[3][11].Flag[2]=12;
	strcpy (Line[3][12].Name,"�Ʒ�·վ");
	strcpy (Line[3][13].Name,"�人������վ");
	Line[3][13].Flag[7]=15;
	strcpy (Line[3][14].Name,"˫��վ"); 
	strcpy (Line[3][15].Name,"�ڹ�վ");
	Line[3][15].Flag[1]=14;
	strcpy (Line[3][16].Name,"������վ");
	Line[3][16].Flag[4]=24;
	strcpy (Line[3][17].Name,"������վ");
	strcpy (Line[3][18].Name,"�ռ���վ");
	strcpy (Line[3][19].Name,"���´��վ");
	strcpy (Line[3][20].Name,"��������վ");
	strcpy (Line[3][21].Name,"���Ǻ�վ");

	strcpy (Line[3][22].Name,"��������վ");
	strcpy (Line[3][23].Name,"���繫˾վ");
	Line[3][23].Flag[6]=32;
	strcpy (Line[3][24].Name,"�������վ");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[3][2];
	Line[3][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[3][23];
	Line[3][24].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[3];
	tmp2->Dist=dist_site[3];
	
	for (i=2;i<=23;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[3][i-1];
		Line[3][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[3][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[3][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[3];
		tmp2->Dist=dist_site[3];
	} 
//*************Line[4]*************// 
	
	for (i=1;i<=37;i++){
		Line[4][i].Num=i;
		Line[4][i].Dist=0;
		for (j=1;j<=8;j++) Line[4][i].Flag[j]=0;
		Line[4][i].next=NULL;
		Line[4][i].Rail=4;
	}
	strcpy (Line[4][1].Name,"�人��վվ");
	strcpy (Line[4][2].Name,"���վ");
	strcpy (Line[4][3].Name,"��ҵ��·վ");
	strcpy (Line[4][4].Name,"�ʺ�·վ");
	strcpy (Line[4][5].Name,"԰��·վ");
	strcpy (Line[4][6].Name,"�޼Ҹ�վ");
	strcpy (Line[4][7].Name,"����·վ");
	strcpy (Line[4][8].Name,"������վ");
	Line[4][8].Flag[8]=11;
	strcpy (Line[4][9].Name,"��ͤվ");
	strcpy (Line[4][10].Name,"������վ");
	strcpy (Line[4][11].Name,"���Ӻ���վ");
	strcpy (Line[4][12].Name,"��ɽ�㳡վ");
	Line[4][12].Flag[2]=21;
	strcpy (Line[4][13].Name,"����·վ");
	Line[4][13].Flag[2]=22;
	strcpy (Line[4][14].Name,"÷ԷС��վ");
	strcpy (Line[4][15].Name,"�����վվ");
	Line[4][15].Flag[7]=25;
	strcpy (Line[4][16].Name,"����·վ");
	strcpy (Line[4][17].Name,"����·վ");
	strcpy (Line[4][18].Name,"����·վ");
	strcpy (Line[4][19].Name,"�ӼҴ�վ");
	Line[4][19].Flag[6]=23;
	strcpy (Line[4][20].Name,"������վվ");
	strcpy (Line[4][21].Name,"�����վ");
	strcpy (Line[4][22].Name,"������վ");
	strcpy (Line[4][23].Name,"ʮ����վ");
	strcpy (Line[4][24].Name,"������վ");
	Line[4][24].Flag[3]=16;
	
	strcpy (Line[4][25].Name,"����·վ");

	strcpy (Line[4][26].Name,"������վ");
	strcpy (Line[4][27].Name,"�ϼ���վ");
	strcpy (Line[4][28].Name,"�ƽ��վ ");
	strcpy (Line[4][29].Name,"����վ");
	strcpy (Line[4][30].Name,"����վ");
	strcpy (Line[4][31].Name,"֪��վ");
	strcpy (Line[4][32].Name,"��ũվ");
	strcpy (Line[4][33].Name,"���·վ");
	strcpy (Line[4][34].Name,"�̵�㳡վ");
	strcpy (Line[4][35].Name,"���ִ��վ");
	strcpy (Line[4][36].Name,"�����վ");
	strcpy (Line[4][37].Name,"�ذ���վ");
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[4][2];
	Line[4][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[4][36];
	Line[4][37].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[4];
	tmp2->Dist=dist_site[4];
	
	for (i=2;i<=36;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[4][i-1];
		Line[4][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[4][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[4][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[4];
		tmp2->Dist=dist_site[4];
	} 
	
	//*************Line[6]*************// 
	
	for (i=1;i<=32;i++){
		Line[6][i].Num=i;
		Line[6][i].Dist=0;
		for (j=1;j<=8;j++) Line[6][i].Flag[j]=0;
		Line[6][i].next=NULL;
		Line[6][i].Rail=6;
	}
	strcpy (Line[6][1].Name,"������·վ");
	strcpy (Line[6][2].Name,"��ͷ̶��԰վ");
	Line[6][2].Flag[1]=3;
	strcpy (Line[6][3].Name,"�ٿո۴��վ");
	strcpy (Line[6][4].Name,"����·վ");
	strcpy (Line[6][5].Name,"������ͣ����վ");
	strcpy (Line[6][6].Name,"��������԰վ");
	strcpy (Line[6][7].Name,"������վ");
	strcpy (Line[6][8].Name,"԰��԰��վ");
	Line[6][8].Flag[7]=12;
	
	strcpy (Line[6][9].Name,"�Ṥ��ѧվ");
	strcpy (Line[6][10].Name,"���໨԰վ");
	Line[6][10].Flag[2]=9;
	strcpy (Line[6][11].Name,"�����վ");
	strcpy (Line[6][12].Name,"ʯ��վ");
	strcpy (Line[6][13].Name,"�ƼҶ�վ");

	strcpy (Line[6][14].Name,"������վ");
	strcpy (Line[6][15].Name,"���·վ");
	Line[6][15].Flag[3]=9;
	Line[6][15].Flag[7]=18;
	strcpy (Line[6][16].Name,"����·վ");
	strcpy (Line[6][17].Name,"����·վ");
	Line[6][17].Flag[1]=21;
	strcpy (Line[6][18].Name,"����·վ");
	Line[6][18].Flag[2]=17;
	strcpy (Line[6][19].Name,"������վ");
	strcpy (Line[6][20].Name,"������վ");
	strcpy (Line[6][21].Name,"��ʤ·վ");
	strcpy (Line[6][22].Name,"��̨վ");
	strcpy (Line[6][23].Name,"�ӼҴ�վ");
	Line[6][23].Flag[4]=19;
	strcpy (Line[6][24].Name,"����·վ");
	
	strcpy (Line[6][25].Name,"����վ");

	strcpy (Line[6][26].Name,"ǰ����վ");
	strcpy (Line[6][27].Name,"�������ı�վ");
	strcpy (Line[6][28].Name,"����������վ ");
	strcpy (Line[6][29].Name,"�Ϲش�վ");
	strcpy (Line[6][30].Name,"���Ǵ��վ");
	strcpy (Line[6][31].Name,"���Ƕ�·վ");
	strcpy (Line[6][32].Name,"���繫˾վ");
	Line[6][32].Flag[3]=23;
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[6][2];
	Line[6][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[6][31];
	Line[6][32].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[6];
	tmp2->Dist=dist_site[6];
	
	for (i=2;i<=31;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[6][i-1];
		Line[6][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[6][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[6][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[6];
		tmp2->Dist=dist_site[6];
	} 
		//*************Line[7]*************// 
	
	for (i=1;i<=37;i++){
		Line[7][i].Num=i;
		Line[7][i].Dist=0;
		for (j=1;j<=8;j++) Line[7][i].Flag[j]=0;
		Line[7][i].next=NULL;
		Line[7][i].Rail=7;
	}
	strcpy (Line[7][1].Name,"����㳡վ");
	strcpy (Line[7][2].Name,"��̩·վ");
	strcpy (Line[7][3].Name,"��������վ");
	strcpy (Line[7][4].Name,"����Gվ");
	strcpy (Line[7][5].Name,"���վ");
	strcpy (Line[7][6].Name,"�ٿձ�·վ");
	strcpy (Line[7][7].Name,"����·վ");
	strcpy (Line[7][8].Name,"�������վ");
	strcpy (Line[7][9].Name,"�������վ");
	Line[7][9].Flag[2]=4;
	
	strcpy (Line[7][10].Name,"���ƺ�վ");
	strcpy (Line[7][11].Name,"���վ");
	strcpy (Line[7][12].Name,"԰��԰��վ");
	Line[7][12].Flag[6]=8;
	strcpy (Line[7][13].Name,"԰��԰վ");
	strcpy (Line[7][14].Name,"����ͷվ");
	strcpy (Line[7][15].Name,"�人������վ");
	Line[7][15].Flag[3]=13;
	strcpy (Line[7][16].Name,"���Ҷն�վ");
	Line[7][16].Flag[2]=13;
	strcpy (Line[7][17].Name,"ȡˮ¥վ");
	strcpy (Line[7][18].Name,"���·վ");
	Line[7][18].Flag[3]=9;
	Line[7][18].Flag[6]=15;
	strcpy (Line[7][19].Name,"����·վ");
	Line[7][19].Flag[1]=22;
	strcpy (Line[7][20].Name,"�����վ");
	Line[7][20].Flag[8]=8;
	strcpy (Line[7][21].Name,"������ѧվ");
	strcpy (Line[7][22].Name,"�ºӽ�վ");
	strcpy (Line[7][23].Name,"�з�վ");
	Line[7][23].Flag[2]=19;
	strcpy (Line[7][24].Name,"С����վ");
	strcpy (Line[7][25].Name,"�����վվ");
	Line[7][25].Flag[4]=15;
	strcpy (Line[7][26].Name,"�𰲽�վ");
	strcpy (Line[7][27].Name,"������վ");
	strcpy (Line[7][28].Name,"������վ");
	strcpy (Line[7][29].Name,"����վ");
	strcpy (Line[7][30].Name,"Ұ�ƺ�վ");
	Line[7][30].Flag[8]=24;
	strcpy (Line[7][31].Name,"��·��վ");
	strcpy (Line[7][32].Name,"����վ");
	strcpy (Line[7][33].Name,"���Ŀ���վ");
	strcpy (Line[7][34].Name,"̷���๫԰վ");
	strcpy (Line[7][35].Name,"������վ");
	strcpy (Line[7][36].Name,"ֽ�����վ");
	strcpy (Line[7][37].Name,"����ɽ����С��վ");

	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[7][2];
	Line[7][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[7][36];
	Line[7][37].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[7];
	tmp2->Dist=dist_site[7];
	
	for (i=2;i<=36;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[7][i-1];
		Line[7][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[7][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[7][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[7];
		tmp2->Dist=dist_site[7];
	} 
	
			//*************Line[8]*************// 
	
	for (i=1;i<=26;i++){
		Line[8][i].Num=i;
		Line[8][i].Dist=0;
		for (j=1;j<=8;j++) Line[8][i].Flag[j]=0;
		Line[8][i].next=NULL;
		Line[8][i].Rail=8;
	}
	strcpy (Line[8][1].Name,"��̶·վ");
	strcpy (Line[8][2].Name,"��ͼ���վ");
	Line[8][2].Flag[2]=6;
	Line[8][2].Flag[3]=1;
	strcpy (Line[8][3].Name,"���Ӻ�վ");
	strcpy (Line[8][4].Name,"��һ·վ");
	strcpy (Line[8][5].Name,"��Ҷɽվ");
	strcpy (Line[8][6].Name,"�Լ���վ");
	Line[8][6].Flag[3]=7;
	strcpy (Line[8][7].Name,"����·վ");
	Line[8][7].Flag[1]=23;
	strcpy (Line[8][8].Name,"�����վ");
	Line[8][8].Flag[7]=20;
	strcpy (Line[8][9].Name,"�춫վ");
	strcpy (Line[8][10].Name,"���Ҷ�վ");
	strcpy (Line[8][11].Name,"������վ");
	Line[8][11].Flag[4]=8;
	strcpy (Line[8][12].Name,"��԰վ");
	strcpy (Line[8][13].Name,"ʡ�������ձ�վ");
	strcpy (Line[8][14].Name,"����ҽԺվ");
	strcpy (Line[8][15].Name,"ˮ����վ");
	strcpy (Line[8][16].Name,"��ɽ·վ");
	strcpy (Line[8][17].Name,"С��ɽվ");
	strcpy (Line[8][18].Name,"�ֵ���վ");
	Line[8][18].Flag[2]=24;
	strcpy (Line[8][19].Name,"��ɽվ");
	strcpy (Line[8][20].Name,"���ν�վ");
	strcpy (Line[8][21].Name,"�Ĳ�·վ");
	strcpy (Line[8][22].Name,"ʡũ��Ժվ");
	strcpy (Line[8][23].Name,"���վ");
	strcpy (Line[8][24].Name,"Ұ�ƺ�վ");
	Line[8][24].Flag[7]=30;
	strcpy (Line[8][25].Name,"�ƼҺ�����С��վ");
	strcpy (Line[8][26].Name,"���˴�");
	///Line 8

	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[8][2];
	Line[8][1].next=tmp1;//��һվ����ڽӱ�	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[8][25];
	Line[8][26].next=tmp2;//���վ����ڽӱ�
	tmp1->Dist=dist_site[8];
	tmp2->Dist=dist_site[8];
	
	for (i=2;i<=25;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[8][i-1];
		Line[8][i].next=tmp1;//��һվ����ڽӱ�
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[8][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[8][i].next->next=tmp2;//��һվ����ڽӱ�
		tmp1->Dist=dist_site[8];
		tmp2->Dist=dist_site[8];
	} 
	NODE *tmp_p1,*tmp_p2,*tmp_p3,*tmp5,*tmp6;

	// ��ͷ̶��԰վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][2].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][2].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][3].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][3].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][3].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][2].next->next;
	tmp_p2->next=tmp3;
/*	free(tmp1);
	free(tmp2);
	free(tmp3);
	free(tmp4);*/
	//	printf("%s1",Line[3][15].Name);
	// �ڹ�վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
//	printf("%s2",Line[1][14].Name);
	(*tmp1) =*( Line[3][15].next);
	//printf("%s3",Line[3][15].Name);
	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	//printf("%s4",Line[3][15].Name);
	//if (Line[3][15])
	(*tmp2) =*( Line[3][15].next->next);
//	printf("%s5",Line[1][14].Name);
	tmp1->next=tmp2;
//	printf("%s",Line[1][14].Name);

	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][14].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][14].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][14].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[3][15].next->next;
	tmp_p2->next=tmp3;
//	printf("%s %s %s %s %s",Line[1][14].Name,Line[1][14].next->Name,Line[1][14].next->next->Name,tmp_p1->next->Name,tmp_p1->next->next->Name);
	
	// ѭ����վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[2][16].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[2][16].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][20].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][20].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][20].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[2][16].next->next;
	tmp_p2->next=tmp3;
	//����·վ
		tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][17].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][17].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][21].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][21].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][21].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][17].next->next;
	tmp_p2->next=tmp3;
	
	//����·վ
		tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][19].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][19].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][22].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][22].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][22].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][19].next->next;
	tmp_p2->next=tmp3;
	
	
	//����·վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][7].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][7].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[1][23].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[1][23].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[1][23].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][7].next->next;
	tmp_p2->next=tmp3;
	
//Line[2]
// �������
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][9].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][9].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][4].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][4].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][4].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][9].next->next;
	tmp_p2->next=tmp3;
 //������·��ת�˵� ��ͼ��� 
  	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[3][1].next);
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[8][2].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[8][2].next->next);
	tmp3->next=tmp4;
	
	tmp5 = (NODE*)malloc(sizeof(NODE));
	(*tmp5) =*( Line[2][6].next);
	tmp6 = (NODE*)malloc(sizeof(NODE));
	(*tmp6) =*( Line[2][6].next->next);
	tmp5->next=tmp6;
	
	tmp_p1=Line[3][1].next;//->next;
	tmp_p1->next=tmp3;
	tmp_p1=tmp_p1->next->next;
	tmp_p1->next=tmp5;
	
	tmp_p2=Line[8][2].next->next;
	tmp_p2->next=tmp5;
	tmp_p2=tmp_p2->next->next;
	tmp_p2->next=tmp1;
	
	tmp_p3=Line[2][6].next->next;
	tmp_p3->next=tmp3;
	tmp_p3=tmp_p3->next->next;
	tmp_p3->next=tmp1;
	
	//���໨԰ 
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][10].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][10].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][9].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][9].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][9].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][10].next->next;
	tmp_p2->next=tmp3;
	//����վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[3][11].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[3][11].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][12].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][12].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][12].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[3][11].next->next;
	tmp_p2->next=tmp3; 
	
	//���Ҷն�վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][16].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][16].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][13].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][13].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][13].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][16].next->next;
	tmp_p2->next=tmp3;
	
	//����·
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][18].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][18].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][17].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][17].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][17].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][18].next->next;
	tmp_p2->next=tmp3;
	//�з�
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][23].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][23].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][19].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][19].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][19].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][23].next->next;
	tmp_p2->next=tmp3; 
	//��ɽ�㳡
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[4][12].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[4][12].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][21].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][21].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][21].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[4][12].next->next;
	tmp_p2->next=tmp3; 
	// ����·վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[4][13].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[4][13].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][22].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][22].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][22].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[4][13].next->next;
	tmp_p2->next=tmp3; 
	//�ֵ���վ
		tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][18].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][18].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[2][24].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[2][24].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[2][24].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][18].next->next;
	tmp_p2->next=tmp3;
//Line[3]
// �Լ���վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][6].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][6].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[3][7].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[3][7].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[3][7].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][6].next->next;
	tmp_p2->next=tmp3;
//���·վ  3�� 
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][15].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][15].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[7][18].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[7][18].next->next);
	tmp3->next=tmp4;
	
	tmp5 = (NODE*)malloc(sizeof(NODE));
	(*tmp5) =*( Line[3][9].next);
	tmp6 = (NODE*)malloc(sizeof(NODE));
	(*tmp6) =*( Line[3][9].next->next);
	tmp5->next=tmp6;
	
	tmp_p1=Line[6][15].next->next;
	tmp_p1->next=tmp3;
	tmp_p1=tmp_p1->next->next;
	tmp_p1->next=tmp5;
	
	tmp_p2=Line[7][18].next->next;
	tmp_p2->next=tmp5;
	tmp_p2=tmp_p2->next->next;
	tmp_p2->next=tmp1;
	
	tmp_p3=Line[3][9].next->next;
	tmp_p3->next=tmp3;
	tmp_p3=tmp_p3->next->next;
	tmp_p3->next=tmp1;




//�人������ 
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][15].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][15].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[3][13].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[3][13].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[3][13].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][15].next->next;
	tmp_p2->next=tmp3;

//������վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[4][24].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[4][24].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[3][16].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[3][16].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[3][16].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[4][24].next->next;
	tmp_p2->next=tmp3;

//���繫˾  �յ�վ���� 
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][32].next);
//	tmp2 = (NODE*)malloc(sizeof(NODE));
//	(*tmp2) =*( Line[8][6].next->next);
	//tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[3][23].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[3][23].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[3][23].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][32].next;
	tmp_p2->next=tmp3;
	
//Line 4
//������
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][11].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][11].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[4][8].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[4][8].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[4][8].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][11].next->next;
	tmp_p2->next=tmp3;
//�����վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][25].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][25].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[4][15].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[4][15].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[4][15].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][25].next->next;
	tmp_p2->next=tmp3;
//�ӼҴ�
 	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[6][23].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[6][23].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[4][19].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[4][19].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[4][19].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[6][23].next->next;
	tmp_p2->next=tmp3;
//Line[6]
//԰��԰��վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[7][12].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[7][12].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[6][8].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[6][8].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[6][8].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[7][12].next->next;
	tmp_p2->next=tmp3;
// Line[7]
// �����վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][8].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][8].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[7][20].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[7][20].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[7][20].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][8].next->next;
	tmp_p2->next=tmp3;
// Ұ�ƺ�վ
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) =*( Line[8][24].next);
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) =*( Line[8][24].next->next);
	tmp1->next=tmp2;
	
	tmp3 = (NODE*)malloc(sizeof(NODE));
	(*tmp3) =*( Line[7][30].next);
	tmp4 = (NODE*)malloc(sizeof(NODE));
	(*tmp4) =*( Line[7][30].next->next);
	tmp3->next=tmp4;
	
	tmp_p1=Line[7][30].next->next;
	tmp_p1->next=tmp1;
	
	tmp_p2=Line[8][24].next->next;
	tmp_p2->next=tmp3;


}

