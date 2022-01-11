/**************************************** 
设置站点信息，并建立邻接表，完成无向图建模 
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
	//计算每个站点间距离 
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
	strcpy (Line[1][1].Name,"径河站");
	strcpy (Line[1][2].Name,"三店站");
	strcpy (Line[1][3].Name,"码头潭公园站");
	Line[1][3].Flag[6]=2;
	strcpy (Line[1][4].Name,"东吴大道站");
	strcpy (Line[1][5].Name,"五环大道站");
	strcpy (Line[1][6].Name,"额头湾站");
	strcpy (Line[1][7].Name,"竹叶海站");
	strcpy (Line[1][8].Name,"舵落口站");
	strcpy (Line[1][9].Name,"古田一路站");
	strcpy (Line[1][10].Name,"古田二路站");
	strcpy (Line[1][11].Name,"古田三路站");
	strcpy (Line[1][12].Name,"古田四路站");
	strcpy (Line[1][13].Name,"汉西一路站");
	strcpy (Line[1][14].Name,"宗关站");
	Line[1][14].Flag[3]=15;  
	strcpy (Line[1][15].Name,"太平洋站");
	strcpy (Line[1][16].Name,"硚口路站");
	strcpy (Line[1][17].Name,"崇仁路站");
	strcpy (Line[1][18].Name,"利济北路站");
	strcpy (Line[1][19].Name,"友谊路站");
	strcpy (Line[1][20].Name,"循礼门站");
	Line[1][20].Flag[2]=16;
	strcpy (Line[1][21].Name,"大智路站");
	Line[1][21].Flag[6]=17;
	strcpy (Line[1][22].Name,"三阳路站");
	Line[1][22].Flag[7]=19;
	strcpy (Line[1][23].Name,"黄浦路站");
	Line[1][23].Flag[8]=7;
	strcpy (Line[1][24].Name,"头道街站");
	strcpy (Line[1][25].Name,"二七路站");
	strcpy (Line[1][26].Name,"徐州新村站");
	strcpy (Line[1][27].Name,"丹水池站");
	strcpy (Line[1][28].Name,"新荣站");
	strcpy (Line[1][29].Name,"堤角站");
	strcpy (Line[1][30].Name,"滕子岗站");
	strcpy (Line[1][31].Name,"滠口新城站");
	strcpy (Line[1][32].Name,"汉口北站");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[1][2];
	Line[1][1].next=tmp1;//第一站点的邻接表	
	tmp1->Dist=dist_site[1];
	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[1][31];
	Line[1][32].next=tmp2;//最后站点的邻接表
	tmp2->Dist=dist_site[1];
	
	for (i=2;i<=31;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[1][i-1];
		Line[1][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[1][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[1][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[2][1].Name,"天河机场站");
	strcpy (Line[2][2].Name,"航空总部站");
	strcpy (Line[2][3].Name,"宋家岗站");
	strcpy (Line[2][4].Name,"巨龙大道站");
	Line[2][4].Flag[7]=9; 
	strcpy (Line[2][5].Name,"盘龙城站");
	strcpy (Line[2][6].Name,"宏图大道站");
	Line[2][6].Flag[3]=1;
	Line[2][6].Flag[8]=2;
	strcpy (Line[2][7].Name,"常青城站");
	strcpy (Line[2][8].Name,"金银潭站");
	strcpy (Line[2][9].Name,"常青花园站");
	Line[2][9].Flag[6]=10;
	strcpy (Line[2][10].Name,"长港路站");
	strcpy (Line[2][11].Name,"汉口火车站");
	strcpy (Line[2][12].Name,"范湖站");
	Line[2][12].Flag[3]=11;
	strcpy (Line[2][13].Name,"王家墩东站");
	Line[2][13].Flag[7]=16;
	strcpy (Line[2][14].Name,"青年路站");
	strcpy (Line[2][15].Name,"中山公园站");
	strcpy (Line[2][16].Name,"循礼门站");
	Line[2][16].Flag[1]=16;
	strcpy (Line[2][17].Name,"江汉路站");
	Line[2][17].Flag[6]=18;
	strcpy (Line[2][18].Name,"积玉桥站");
	strcpy (Line[2][19].Name,"螃蟹岬站");
	Line[2][19].Flag[7]=23;
	strcpy (Line[2][20].Name,"小龟山站");
	strcpy (Line[2][21].Name,"洪山广场站");
	Line[2][21].Flag[4]=12;
	strcpy (Line[2][22].Name,"中南路站");
	Line[2][22].Flag[4]=13;
	strcpy (Line[2][23].Name,"宝通寺站");
	strcpy (Line[2][24].Name,"街道口站");
	Line[2][24].Flag[8]=18;
	strcpy (Line[2][25].Name,"广埠屯站");
	strcpy (Line[2][26].Name,"虎泉站");
	strcpy (Line[2][27].Name,"杨家湾站");
	strcpy (Line[2][28].Name,"光谷广场站");
	strcpy (Line[2][29].Name,"珞雄路站");
	strcpy (Line[2][30].Name,"华中科技大学站");
	strcpy (Line[2][31].Name,"光谷大道站");
	strcpy (Line[2][32].Name,"佳园路站");
	strcpy (Line[2][33].Name,"光谷火车站");
	strcpy (Line[2][34].Name,"黄龙山路站");
	strcpy (Line[2][35].Name,"金融港北站");
	strcpy (Line[2][36].Name,"秀湖站");
	strcpy (Line[2][37].Name,"藏龙东街站");
	strcpy (Line[2][38].Name,"佛祖岭站");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[2][2];
	Line[2][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[2][37];
	Line[2][38].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[2];
	tmp2->Dist=dist_site[2];
	
	for (i=2;i<=37;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[2][i-1];
		Line[2][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[2][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[2][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[3][1].Name,"宏图大道站");
	Line[3][1].Flag[2]=6;
	Line[3][1].Flag[8]=2;
	strcpy (Line[3][2].Name,"市民之家站");
	strcpy (Line[3][3].Name,"后湖大道站");
	strcpy (Line[3][4].Name,"兴业路站");
	strcpy (Line[3][5].Name,"二七小路站");
	strcpy (Line[3][6].Name,"罗家庄站");
	strcpy (Line[3][7].Name,"赵家条站");
	Line[3][7].Flag[8]=6;
	strcpy (Line[3][8].Name,"惠济二路站");
	strcpy (Line[3][9].Name,"香港路站");
	Line[3][9].Flag[6]=15;
	Line[3][9].Flag[7]=18;
	strcpy (Line[3][10].Name,"菱角湖站");
	strcpy (Line[3][11].Name,"范湖站");
	Line[3][11].Flag[2]=12;
	strcpy (Line[3][12].Name,"云飞路站");
	strcpy (Line[3][13].Name,"武汉商务区站");
	Line[3][13].Flag[7]=15;
	strcpy (Line[3][14].Name,"双墩站"); 
	strcpy (Line[3][15].Name,"宗关站");
	Line[3][15].Flag[1]=14;
	strcpy (Line[3][16].Name,"王家湾站");
	Line[3][16].Flag[4]=24;
	strcpy (Line[3][17].Name,"龙阳村站");
	strcpy (Line[3][18].Name,"陶家岭站");
	strcpy (Line[3][19].Name,"四新大道站");
	strcpy (Line[3][20].Name,"汉阳客运站");
	strcpy (Line[3][21].Name,"三角湖站");

	strcpy (Line[3][22].Name,"体育中心站");
	strcpy (Line[3][23].Name,"东风公司站");
	Line[3][23].Flag[6]=32;
	strcpy (Line[3][24].Name,"沌阳大道站");
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[3][2];
	Line[3][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[3][23];
	Line[3][24].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[3];
	tmp2->Dist=dist_site[3];
	
	for (i=2;i<=23;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[3][i-1];
		Line[3][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[3][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[3][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[4][1].Name,"武汉火车站站");
	strcpy (Line[4][2].Name,"杨春湖站");
	strcpy (Line[4][3].Name,"工业四路站");
	strcpy (Line[4][4].Name,"仁和路站");
	strcpy (Line[4][5].Name,"园林路站");
	strcpy (Line[4][6].Name,"罗家港站");
	strcpy (Line[4][7].Name,"铁机路站");
	strcpy (Line[4][8].Name,"岳家嘴站");
	Line[4][8].Flag[8]=11;
	strcpy (Line[4][9].Name,"东亭站");
	strcpy (Line[4][10].Name,"青鱼嘴站");
	strcpy (Line[4][11].Name,"楚河汉街站");
	strcpy (Line[4][12].Name,"洪山广场站");
	Line[4][12].Flag[2]=21;
	strcpy (Line[4][13].Name,"中南路站");
	Line[4][13].Flag[2]=22;
	strcpy (Line[4][14].Name,"梅苑小区站");
	strcpy (Line[4][15].Name,"武昌火车站站");
	Line[4][15].Flag[7]=25;
	strcpy (Line[4][16].Name,"首义路站");
	strcpy (Line[4][17].Name,"复兴路站");
	strcpy (Line[4][18].Name,"拦江路站");
	strcpy (Line[4][19].Name,"钟家村站");
	Line[4][19].Flag[6]=23;
	strcpy (Line[4][20].Name,"汉阳火车站站");
	strcpy (Line[4][21].Name,"五里墩站");
	strcpy (Line[4][22].Name,"七里庙站");
	strcpy (Line[4][23].Name,"十里铺站");
	strcpy (Line[4][24].Name,"王家湾站");
	Line[4][24].Flag[3]=16;
	
	strcpy (Line[4][25].Name,"玉龙路站");

	strcpy (Line[4][26].Name,"永安堂站");
	strcpy (Line[4][27].Name,"孟家铺站");
	strcpy (Line[4][28].Name,"黄金口站 ");
	strcpy (Line[4][29].Name,"新天站");
	strcpy (Line[4][30].Name,"集贤站");
	strcpy (Line[4][31].Name,"知音站");
	strcpy (Line[4][32].Name,"新农站");
	strcpy (Line[4][33].Name,"凤凰路站");
	strcpy (Line[4][34].Name,"蔡甸广场站");
	strcpy (Line[4][35].Name,"临嶂大道站");
	strcpy (Line[4][36].Name,"新庙村站");
	strcpy (Line[4][37].Name,"藏柏林站");
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[4][2];
	Line[4][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[4][36];
	Line[4][37].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[4];
	tmp2->Dist=dist_site[4];
	
	for (i=2;i<=36;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[4][i-1];
		Line[4][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[4][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[4][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[6][1].Name,"富民南路站");
	strcpy (Line[6][2].Name,"码头潭公园站");
	Line[6][2].Flag[1]=3;
	strcpy (Line[6][3].Name,"临空港大道站");
	strcpy (Line[6][4].Name,"二雅路站");
	strcpy (Line[6][5].Name,"金银湖停车场站");
	strcpy (Line[6][6].Name,"金银湖公园站");
	strcpy (Line[6][7].Name,"金银湖站");
	strcpy (Line[6][8].Name,"园博园北站");
	Line[6][8].Flag[7]=12;
	
	strcpy (Line[6][9].Name,"轻工大学站");
	strcpy (Line[6][10].Name,"常青花园站");
	Line[6][10].Flag[2]=9;
	strcpy (Line[6][11].Name,"杨汊湖站");
	strcpy (Line[6][12].Name,"石桥站");
	strcpy (Line[6][13].Name,"唐家墩站");

	strcpy (Line[6][14].Name,"三眼桥站");
	strcpy (Line[6][15].Name,"香港路站");
	Line[6][15].Flag[3]=9;
	Line[6][15].Flag[7]=18;
	strcpy (Line[6][16].Name,"苗栗路站");
	strcpy (Line[6][17].Name,"大智路站");
	Line[6][17].Flag[1]=21;
	strcpy (Line[6][18].Name,"江汉路站");
	Line[6][18].Flag[2]=17;
	strcpy (Line[6][19].Name,"六渡桥站");
	strcpy (Line[6][20].Name,"汉正街站");
	strcpy (Line[6][21].Name,"武胜路站");
	strcpy (Line[6][22].Name,"琴台站");
	strcpy (Line[6][23].Name,"钟家村站");
	Line[6][23].Flag[4]=19;
	strcpy (Line[6][24].Name,"马鹦路站");
	
	strcpy (Line[6][25].Name,"建港站");

	strcpy (Line[6][26].Name,"前进村站");
	strcpy (Line[6][27].Name,"国博中心北站");
	strcpy (Line[6][28].Name,"国博中心南站 ");
	strcpy (Line[6][29].Name,"老关村站");
	strcpy (Line[6][30].Name,"江城大道站");
	strcpy (Line[6][31].Name,"车城东路站");
	strcpy (Line[6][32].Name,"东风公司站");
	Line[6][32].Flag[3]=23;
	
	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[6][2];
	Line[6][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[6][31];
	Line[6][32].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[6];
	tmp2->Dist=dist_site[6];
	
	for (i=2;i<=31;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[6][i-1];
		Line[6][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[6][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[6][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[7][1].Name,"黄陂广场站");
	strcpy (Line[7][2].Name,"百泰路站");
	strcpy (Line[7][3].Name,"北车基地站");
	strcpy (Line[7][4].Name,"余彭塆站");
	strcpy (Line[7][5].Name,"横店站");
	strcpy (Line[7][6].Name,"临空北路站");
	strcpy (Line[7][7].Name,"天阳路站");
	strcpy (Line[7][8].Name,"腾龙大道站");
	strcpy (Line[7][9].Name,"巨龙大道站");
	Line[7][9].Flag[2]=4;
	
	strcpy (Line[7][10].Name,"汤云海站");
	strcpy (Line[7][11].Name,"马池站");
	strcpy (Line[7][12].Name,"园博园北站");
	Line[7][12].Flag[6]=8;
	strcpy (Line[7][13].Name,"园博园站");
	strcpy (Line[7][14].Name,"常码头站");
	strcpy (Line[7][15].Name,"武汉商务区站");
	Line[7][15].Flag[3]=13;
	strcpy (Line[7][16].Name,"王家墩东站");
	Line[7][16].Flag[2]=13;
	strcpy (Line[7][17].Name,"取水楼站");
	strcpy (Line[7][18].Name,"香港路站");
	Line[7][18].Flag[3]=9;
	Line[7][18].Flag[6]=15;
	strcpy (Line[7][19].Name,"三阳路站");
	Line[7][19].Flag[1]=22;
	strcpy (Line[7][20].Name,"徐家棚站");
	Line[7][20].Flag[8]=8;
	strcpy (Line[7][21].Name,"湖北大学站");
	strcpy (Line[7][22].Name,"新河街站");
	strcpy (Line[7][23].Name,"螃蟹岬站");
	Line[7][23].Flag[2]=19;
	strcpy (Line[7][24].Name,"小东门站");
	strcpy (Line[7][25].Name,"武昌火车站站");
	Line[7][25].Flag[4]=15;
	strcpy (Line[7][26].Name,"瑞安街站");
	strcpy (Line[7][27].Name,"建安街站");
	strcpy (Line[7][28].Name,"湖工大站");
	strcpy (Line[7][29].Name,"板桥站");
	strcpy (Line[7][30].Name,"野芷湖站");
	Line[7][30].Flag[8]=24;
	strcpy (Line[7][31].Name,"新路村站");
	strcpy (Line[7][32].Name,"大花岭站");
	strcpy (Line[7][33].Name,"江夏客厅站");
	strcpy (Line[7][34].Name,"谭鑫培公园站");
	strcpy (Line[7][35].Name,"北华街站");
	strcpy (Line[7][36].Name,"纸坊大街站");
	strcpy (Line[7][37].Name,"青龙山地铁小镇站");

	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[7][2];
	Line[7][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[7][36];
	Line[7][37].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[7];
	tmp2->Dist=dist_site[7];
	
	for (i=2;i<=36;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[7][i-1];
		Line[7][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[7][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[7][i].next->next=tmp2;//下一站点的邻接表
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
	strcpy (Line[8][1].Name,"金潭路站");
	strcpy (Line[8][2].Name,"宏图大道站");
	Line[8][2].Flag[2]=6;
	Line[8][2].Flag[3]=1;
	strcpy (Line[8][3].Name,"塔子湖站");
	strcpy (Line[8][4].Name,"中一路站");
	strcpy (Line[8][5].Name,"竹叶山站");
	strcpy (Line[8][6].Name,"赵家条站");
	Line[8][6].Flag[3]=7;
	strcpy (Line[8][7].Name,"黄浦路站");
	Line[8][7].Flag[1]=23;
	strcpy (Line[8][8].Name,"徐家棚站");
	Line[8][8].Flag[7]=20;
	strcpy (Line[8][9].Name,"徐东站");
	strcpy (Line[8][10].Name,"汪家墩站");
	strcpy (Line[8][11].Name,"岳家嘴站");
	Line[8][11].Flag[4]=8;
	strcpy (Line[8][12].Name,"梨园站");
	strcpy (Line[8][13].Name,"省博湖北日报站");
	strcpy (Line[8][14].Name,"中南医院站");
	strcpy (Line[8][15].Name,"水果湖站");
	strcpy (Line[8][16].Name,"洪山路站");
	strcpy (Line[8][17].Name,"小洪山站");
	strcpy (Line[8][18].Name,"街道口站");
	Line[8][18].Flag[2]=24;
	strcpy (Line[8][19].Name,"马房山站");
	strcpy (Line[8][20].Name,"文治街站");
	strcpy (Line[8][21].Name,"文昌路站");
	strcpy (Line[8][22].Name,"省农科院站");
	strcpy (Line[8][23].Name,"马湖站");
	strcpy (Line[8][24].Name,"野芷湖站");
	Line[8][24].Flag[7]=30;
	strcpy (Line[8][25].Name,"黄家湖地铁小镇站");
	strcpy (Line[8][26].Name,"军运村");
	///Line 8

	tmp1 = (NODE*)malloc(sizeof(NODE));
	(*tmp1) = Line[8][2];
	Line[8][1].next=tmp1;//第一站点的邻接表	
	tmp2 = (NODE*)malloc(sizeof(NODE));
	(*tmp2) = Line[8][25];
	Line[8][26].next=tmp2;//最后站点的邻接表
	tmp1->Dist=dist_site[8];
	tmp2->Dist=dist_site[8];
	
	for (i=2;i<=25;i++){
		tmp1 = (NODE*)malloc(sizeof(NODE));
		(*tmp1) = Line[8][i-1];
		Line[8][i].next=tmp1;//上一站点的邻接表
		tmp2 = (NODE*)malloc(sizeof(NODE));
		(*tmp2) = Line[8][i+1];
		tmp2->next=NULL;
		tmp1->next=tmp2;
		Line[8][i].next->next=tmp2;//下一站点的邻接表
		tmp1->Dist=dist_site[8];
		tmp2->Dist=dist_site[8];
	} 
	NODE *tmp_p1,*tmp_p2,*tmp_p3,*tmp5,*tmp6;

	// 码头潭公园站
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
	// 宗关站
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
	
	// 循礼门站
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
	//大智路站
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
	
	//三阳路站
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
	
	
	//黄浦路站
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
// 巨龙大道
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
 //三条线路的转乘点 宏图大道 
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
	
	//常青花园 
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
	//范湖站
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
	
	//王家墩东站
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
	
	//江汉路
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
	//螃蟹岬
	
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
	//洪山广场
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
	// 中南路站
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
	//街道口站
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
// 赵家条站
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
//香港路站  3点 
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




//武汉商务区 
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

//王家湾站
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

//东风公司  终点站！！ 
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
//岳家嘴
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
//武昌火车站
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
//钟家村
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
//园博园北站
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
// 徐家棚站
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
// 野芷湖站
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

