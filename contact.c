#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
//����
void InitContact(struct Contact* ps)
{
	memset(ps->date, 0, sizeof(ps->date));
	ps->size = 0;//����ͨѶ¼���ֻ��0��Ԫ��
}
void addContact(struct Contact *ps)//���Ӻ��� ��һ�����ж�ͨѶ¼�����Ƿ�����
{
	if (ps->size == MAX)
	{
		printf("ͨѶ¼����\n");
	}
	else
	{
		printf("������������\n");
		scanf("%s", ps->date[ps->size].name);//ps->date�ҵ�struct Contact�е�date���� �±�Ϊps->size
		printf("���������䣺\n");
		scanf("%d", &(ps->date[ps->size].age));
		printf("�������Ա�\n");
		scanf("%s", ps->date[ps->size].sex);
		printf("������绰��\n");
		scanf("%s", ps->date[ps->size].tele);
		printf("�������ַ��\n");
		scanf("%s", ps->date[ps->size].adds);
		ps->size++;
		printf("��ӳɹ�\n");
	}
}
void showcontact(const struct Contact *ps)//��ӡ֮ǰ��Ҫ�ж�1.ͨѶ¼�Ƿ������� ����size�ж�
{                                         //2.������ڶ���˵����� ��Ҫforѭ�����δ�ӡ ѭ������ȡ����size
	if (ps->size == 0)
	{
		printf("ͨѶ¼Ϊ��\n");
	}
	else
	{
		int i = 0;
		printf("%-10s\t%-4s\t%-5s\t%-12s\t%-20s\n", "����", "����", "�Ա�", "�绰", "��ַ");//�ȴ�ӡ����
		for (i = 0; i < ps->size; i++)
		{
			printf("%-10s\t%-4d\t%-5s\t%-12s\t%-20s\n",
				ps->date[i].name,
				ps->date[i].age,
				ps->date[i].sex,
				ps->date[i].tele,
				ps->date[i].adds);//����û��д��date[ps->size].adds��ԭ���� ps->size�����Ӻ������Ѿ�++�� �����date[ps->size]�ǻ�û��������Ϣ���Ǹ��±� ���Բ���ʾ��Ϣ
		}
	}

}
static int search_(const struct Contact *ps, char name[name_max])//�β�name������һ��Ҫ��ʵ��name����һ��
{//���static��ԭ�򣺲���ɾ����ʾ��ͨѶ¼�Ĺ��� �������search_����Ϊ��Щ���ܶ��õ��˲��� ���ﵥ��������һ�����Һ�����֧����Щ������ʵ��
	
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		if (0 == strcmp(name, ps->date[i].name))
			return i;//�����±�
	}
		return -1;
}

void delContact(struct Contact *ps)//1.����Ҫɾ��������ʲôλ�� 2.ɾ��
{
	char name[name_max];
	printf("������Ҫɾ���˵����֣�\n");
	scanf("%s", name);
	
	//for (i = 0; i < ps->size; i++)//1.����
	//{
	//	if (0 == strcmp(name, ps->date[i].name))
	//	{
	//		break;
	//	}
	//}
	int ret = search_(ps, name);
	if (ret == -1)//2.ɾ��

	{
		printf("Ҫɾ�����˲�����\n");
	}
	else
	{
		int j = 0;
		for (j = ret; j < ps->size - 1; j++)
		{
			ps->date[j] = ps->date[j + 1];
		}
		ps->size--;
		printf("ɾ���ɹ�\n");
	}
	
}
void seacontact(const struct Contact *ps)
{
	char name[name_max];
	printf("������Ҫ�����˵����֣�\n");
	scanf("%s", name);
	int ret = search_(ps, name);
	if (ret == -1)
	{
		printf("��Ҫ�����˵���Ϣ������\n");
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
	printf("������Ҫ�޸��˵����֣�\n");
	scanf("%s", name);
	int ret = search_(ps, name);
	if (ret == -1)
	{
		printf("��Ҫ�����˵���Ϣ������\n");
	}
	else
	{
		printf("������������\n");
		scanf("%s", ps->date[ret].name);//ps->date�ҵ�struct Contact�е�date���� �±�Ϊps->size
		printf("���������䣺\n");
		scanf("%d", &(ps->date[ret].age));
		printf("�������Ա�\n");
		scanf("%s", ps->date[ret].sex);
		printf("������绰��\n");
		scanf("%s", ps->date[ret].tele);
		printf("�������ַ��\n");
		scanf("%s", ps->date[ret].adds);
		ps->size++;
		printf("�޸ĳɹ�\n");
	}
}

int cmp_name(const void *e1, const void *e2)
{
	//return ((struct PeoInfo*)e1)->age - ((struct PeoInfo*)e2)->age; ������������
	return strcmp(((struct  PeoInfo*)e1)->name, ((struct  PeoInfo*)e2)->name);
}
void sortcontact(struct Contact *ps)
{
	qsort(ps->date, ps->size, sizeof(ps->date[0]), cmp_name);
	
	
	printf("����ɹ�\n");
}