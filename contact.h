#include <stdio.h>//��������
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
	sort,//6  ���Ӵ���ɶ���

};
struct PeoInfo//PeoInfo-�˵���Ϣ ����Ǳ���һ���˵���Ϣ����
{
	char name[name_max];
	int age;
	char sex[sex_max];
	char tele[tele_max];
	char adds[adds_max];
};
struct Contact
{
	struct PeoInfo date[MAX];//����1000��struct PeoInfo�ṹ������  ���Դ��1000���˵���Ϣ
	//date������struct PeoInfo
	int size;//��¼��ǰ�Ѿ��е�Ԫ�ظ��� ��ͨѶ¼һ����Ҳû�е�ʱ��size=0 ��һ�� size++
};
void InitContact(struct Contact *ps);//��1000��Ԫ�� ����sizeȫ����ʼ����0
void addContact(struct Contact *ps);
void showcontact(const struct Contact *ps);//��ʾָ������ݲ��ܱ��޸�
void delContact(struct Contact *ps);//ɾ��ָ������ϵ��
void seacontact(const struct Contact *ps);//����ָ���˵���Ϣ
void modifycontact(struct Contact *ps);//�޸��˵���Ϣ
void sortcontact(struct Contact *ps);