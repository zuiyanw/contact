
#define _CRT_SECURE_NO_WARNINGS
#include "contact.h"
void menu()
{
	printf("***********************\n");
	printf("***1.add     2.del*****\n");
	printf("***3.search  4.modify**\n");//modify-�޸�
	printf("***5.show    6.sort****\n");//sort-����
	printf("***0.exit          ****\n");
	printf("***********************\n");

}
int main()
{
	int input = 0;
	struct Contact con;//con����ͨѶ¼ �������1000��Ԫ�� ��size
	InitContact(&con);//��ʼ��ͨѶ¼
	do{
		menu();//1.�����˵� 
		printf("��ѡ��\n");
		scanf("%d", &input);
		switch (input)
		{
		case add:
			addContact(&con);//���Ӻ���
			break;
		case del:
			delContact(&con);//del ɾ������
			break;
		case search:
			seacontact(&con);
			break;
		case modify:
			modifycontact(&con);
			break;
		case show:
			showcontact(&con);//��ӡ����
			break;
		case sort:
			sortcontact(&con);
			break;
		case exit1:
			printf("�˳�\n");
			break;
		default:
			printf("����������������룺\n");
		}

	} while (input);

	return 0;
}