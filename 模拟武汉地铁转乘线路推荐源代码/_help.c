/**************************************** 
该系统的使用帮助，二级菜单使用帮助内容 
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



void Help_Note(void){  //使用帮助
	system("cls");
	color(12);
	printf("\t\t   使用帮助\n");
	color(7);
	printf("  每一个界面可会根据提示输入相应的功能序号进行相应操作。\n\n");
	color(14);
	printf("\t\t●●基本信息●●\t\n\n");
	color(7);
	printf("  在<线路概况>中可查询线路运行时间、基本票价、线路基本信息\n\n");
	
	printf("  在<线路总览>中可查询所有已开通的轨道交通的运行路线\n\n");
	
	printf("  在<站点浏览>中您可通过输入起始站点依次浏览可行进站点\n\n");
	color(14);
	printf("\t\t●●设置时间●●\t\n\n");
	color(7);
	printf("  本功能中您可设置当前时间，方便本系统为您后续推荐线路\n\n"); 

	color(14);
	printf("\t\t●●线路推荐●●\t\n\n");
	color(7);
	printf("  本功能中您输入起始线路与站点与终点线路与站点，在此界面下，您\n  可以随时跳转 上一级菜单的基本信息 中的<线路全览>查询站点序号\n");
	
	printf("  本系统将按照以下三种筛选方式为您推荐最佳线路供您选择\n\n");
	printf("\t------------- 总时间最短 -------------\n\t|\t\t\t\t      |\n");
	color(7);
	printf("\t| 该算法会为您计算用时最短的1-3条线路,|\n\t| 按照票价递增的顺序给出推荐\t      |\n\t|\t\t\t\t      |\n");
	printf("\t---------- 优先考虑拥挤程度 ----------- \t\t\n\t|\t\t\t\t      |\n");
	color(7);
	printf("\t|\t该算法会优先考虑拥挤程度，    |\n\t|\t为您推荐舒适宽松的路线\t      |\n\t|\t\t\t\t      |\n");

	printf("\t--------- 过滤过度拥挤的线路  ---------\t\n\t|\t\t\t\t      |\n");
	color(7);
	printf("\t|  本算法避开过度拥挤的线路，\t      |\n\t|  为您推荐较为舒适且时间较短的路线   |\n\t|\t\t\t\t      |");
	printf("\t\n\t---------------------------------------\n");

	system("pause");
	main_menu();
	
}
