/**************** 
��������� 
*****************/ 

//Project�� Simulation of Wuhan Metro Traffic inquiry system
// Name��Li Xinyu
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

int main(int argc, char *argv[]) {  //��ں��� 
	int i;
	Build_Site();   //��ģ 
	Welcome_menu();  //��ӭ���� 
	main_menu();  //���˵� 
	return 0;
}
