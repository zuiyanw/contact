#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//函数
void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//设置通讯录最初只有0个元素
}
void addContact(struct Contact *ps)//增加函数 第一步先判断通讯录容量是否已满
{
	if (ps->size == MAX)
	{
		printf("通讯录已满\n");
	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", ps->date[ps->size].name);//ps->date找到struct Contact中的date数组 下标为ps->size
		printf("请输入年龄：\n");
		scanf("%d", &(ps->date[ps->size].age));
		printf("请输入性别：\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("请输入电话：\n");
		scanf("%s", ps->date[ps->size].tele);
		printf("请输入地址：\n");
		scanf("%s", ps->date[ps->size].adds);
		ps->size++;
		printf("添加成功\n");
	}
}
void showcontact(const struct Contact *ps)//打印之前需要判断1.通讯录是否有内容 根据size判断
{                                         //2.如果存在多个人的数据 需要for循环依次打印 循环条件取决于size
	if (ps->size == 0)
	{
		printf("通讯录为空\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "姓名", "年龄", "性别", "电话", "地址");//先打印标题
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].adds);//这里没有写成date[ps->size].adds的原因是 ps->size在增加函数中已经++了 这里的date[ps->size]是还没有输入信息的那个下标 所以不显示信息
		}
	}

}
static int search_(const struct Contact *ps, char name[name_max])//形参name的类型一定要和实参name类型一致
{//添加static的原因：查找删除显示是通讯录的功能 但这里的search_是因为这些功能都用到了查找 这里单独建立了一个查找函数来支撑这些功能来实现
	
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(name, ps->date[i].name))
			return i;//返回下标
	}
		return -1;
}

void delContact(struct Contact *ps)//1.查找要删出的人在什么位置 2.删除
{
	char name[name_max];
	printf("请输入要删除人的名字：\n");
	scanf("%s", name);
	
	//for (i = 0; i < ps->size; i++)//1.查找
	//{
	//	if (0 == strcmp(name, ps->date[i].name))
	//	{
	//		break;
	//	}
	//}
	int ret = search_(ps, name);
	if (ret == -1)//2.删除

	{
		printf("要删除的人不存在\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("删除成功\n");
	}
	
}
void seacontact(const struct Contact *ps)
{
	char name[name_max];
	printf("请输入要查找人的名字：\n");
	scanf("%s", name);
	int ret = search_(ps, name);
	if (ret == -1)
	{
		printf("你要查找人的信息不存在\n");
	}
	else
	{
		printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
			ps->date[ret].name,
			ps->date[ret].age,
			ps->date[ret].sex,
			ps->date[ret].tele,
			ps->date[ret].adds);
	}
}

void modifycontact(struct Contact *ps)
{
	char name[name_max];
	printf("请输入要修改人的名字：\n");
	scanf("%s", name);
	int ret = search_(ps, name);
	if (ret == -1)
	{
		printf("你要查找人的信息不存在\n");
	}
	else
	{
		printf("请输入姓名：\n");
		scanf("%s", ps->date[ret].name);//ps->date找到struct Contact中的date数组 下标为ps->size
		printf("请输入年龄：\n");
		scanf("%d", &(ps->date[ret].age));
		printf("请输入性别：\n");
		scanf("%s", ps->date[ret].sex);
		printf("请输入电话：\n");
		scanf("%s", ps->date[ret].tele);
		printf("请输入地址：\n");
		scanf("%s", ps->date[ret].adds);
		ps->size++;
		printf("修改成功\n");
	}
}

int cmp_name(const void *e1, const void *e2)
{
	//return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age; 按照年龄排序
	return strcmp(((struct  PeoInfo*)e1)->name, ((struct  PeoInfo*)e2)->name);
}
void sortcontact(struct Contact *ps)
{
	qsort(ps->date, ps->size, sizeof(ps->date[0]), cmp_name);
	
	
	printf("排序成功\n");
}