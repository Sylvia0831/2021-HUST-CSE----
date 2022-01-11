
#ifndef _SYSTEM_H
#define _SYSTEM_H


extern int Operation_Num; 

extern int hour,minute;
extern int TimeOper_Num;
 
void Welcome_menu(void);  // 功能分别为显示欢迎界面； 
void Exit_System(void);	// 退出系统，显示退出界面； 
int main_menu(void);	// 主菜单界面；
void SetingTime_Menu(void);	// 设置时间菜单；
void color(char x); 	// 设置输出颜色函数； 
void BasicInformation_Menu(void);	// 基本信息菜单； 

#endif


