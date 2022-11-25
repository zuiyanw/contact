
#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("***********************\n");
	printf("***1.add     2.del*****\n");
	printf("***3.search  4.modify**\n");//modify-修改
	printf("***5.show    6.sort****\n");//sort-排序
	printf("***0.exit          ****\n");
	printf("***********************\n");

}
int main()
{
	int input = 0;
	struct Contact con;//con就是通讯录 里面包含1000个元素 和size
	InitContact(&con);//初始化通讯录
	do{
		menu();//1.创建菜单 
		printf("请选择：\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addContact(&con);//增加函数
			break;
		case del:
			delContact(&con);//del 删除函数
			break;
		case search:
			seacontact(&con);
			break;
		case modify:
			modifycontact(&con);
			break;
		case show:
			showcontact(&con);//打印函数
			break;
		case sort:
			sortcontact(&con);
			break;
		case exit1:
			printf("退出\n");
			break;
		default:
			printf("输入错误，请重新输入：\n");
		}

	} while (input);

	return 0;
}