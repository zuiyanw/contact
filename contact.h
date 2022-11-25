#include <stdio.h>//函数声明
#include<string.h>
#include <stdlib.h>
#define name_max 10
#define sex_max 10
#define tele_max 12
#define adds_max 20
#define MAX 1000
enum MyEnum
{
	exit1,//0
	add,//1
	del,//2
	search,//3
	modify,//4
	show,//5
	sort,//6  增加代码可读性

};
struct PeoInfo//PeoInfo-人的信息 这个是表述一个人的信息类型
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char tele[tele_max];
	char adds[adds_max];
};
struct Contact
{
	struct PeoInfo date[MAX];//创建1000个struct PeoInfo结构体数组  可以存放1000个人的信息
	//date类型是struct PeoInfo
	int size;//记录当前已经有的元素个数 当通讯录一个人也没有的时候size=0 有一个 size++
};
void InitContact(struct Contact *ps);//把1000个元素 还有size全部初始化成0
void addContact(struct Contact *ps);
void showcontact(const struct Contact *ps);//表示指针的内容不能被修改
void delContact(struct Contact *ps);//删除指定的联系人
void seacontact(const struct Contact *ps);//查找指定人的信息
void modifycontact(struct Contact *ps);//修改人的信息
void sortcontact(struct Contact *ps);