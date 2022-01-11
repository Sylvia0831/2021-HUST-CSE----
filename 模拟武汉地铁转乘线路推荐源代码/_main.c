/**************** 
主函数入口 
*****************/ 

//Project： Simulation of Wuhan Metro Traffic inquiry system
// Name：Li Xinyu
// Class: CSE1901
// Student ID: U201911658

#include <stdio.h>
#include <stdlib.h>
#include<windows.h>
#include "build.h" 
#include "path_find.h"
#include "system.h" 
#include "help.h" 
#include "basic.h"
#include "path_choice.h"

int main(int argc, char *argv[]) {  //入口函数 
	int i;
	Build_Site();   //建模 
	Welcome_menu();  //欢迎界面 
	main_menu();  //主菜单 
	return 0;
}
