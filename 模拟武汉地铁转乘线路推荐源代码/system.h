
#ifndef _SYSTEM_H
#define _SYSTEM_H


extern int Operation_Num; 

extern int hour,minute;
extern int TimeOper_Num;
 
void Welcome_menu(void);  // ���ֱܷ�Ϊ��ʾ��ӭ���棻 
void Exit_System(void);	// �˳�ϵͳ����ʾ�˳����棻 
int main_menu(void);	// ���˵����棻
void SetingTime_Menu(void);	// ����ʱ��˵���
void color(char x); 	// ���������ɫ������ 
void BasicInformation_Menu(void);	// ������Ϣ�˵��� 

#endif


