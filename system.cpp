#include <stdio.h>

#include <stdlib.h>

#include <string.h>

#include <conio.h>

#include <windows.h>

#define MAX 1000


/*�ṹ������*/

typedef struct

{
	int num;/*ѧ��*/

	char name[20];/*����*/

	char sex[5];/*�Ա�*/

	int age;/*����*/

	char studentclass[20];/*�༶*/

	int dorm;/*�����*/

}STUDENTS;

//����ָ�� 
typedef struct Points
{
	int a;
	struct Points* points;
}Points;

char xiugai[10] = "�޸�";
char chaxun[10] = "��ѯ";
char xuehao[] = "ѧ��";
char xingming[] = "����";
char xingbie[] = "�Ա�";
char nianling[] = "����";
char banji[] = "�༶";
char sushe[] = "����";



/*���õĹ��ܿ� */


void pause() {
	int i;
	printf("\n\n��������ӻس��������˵�!");
	scanf_s("%d", &i);
	getchar();
}

void print(STUDENTS stu[], int point) {
	printf("\n\n\nѧ�ţ�%d,������%s,�Ա�%s,���䣺%d,�༶��%s,�����: %d\n",
		stu[point].num, stu[point].name, stu[point].sex, stu[point].age, stu[point].studentclass, stu[point].dorm);
}

void printfNotFound() {
	printf("�Ҳ���������\n");
}

void printSearch(STUDENTS stu[], int i) {
	printf("		     %7d%11s%10s%10d%12s%12d\n\n", stu[i].num, stu[i].name, stu[i].sex, stu[i].age, stu[i].studentclass, stu[i].dorm);
}

void printHead() {
	printf(" 		-------------------------------------------------------------------------------\n");
	printf("		-------------------------------------------------------------------------------\n");
	printf("			ѧ�ţ�     ������     �Ա�     ���䣺     �༶��     ����ţ�     \n");
	printf(" 		-------------------------------------------------------------------------------\n");
	printf(" 		-------------------------------------------------------------------------------\n\n\n");

}

//Ĭ�ϼ��� 
int a = 1;
void selectOperate() {

button:
	printf("���������밴1,�������˵��밴0  ");
	scanf_s("%d", &a);
	if (!(a == 1 || a == 0))
	{
		printf("��������ȷ��ָ��");
		goto button;
	}
}






//��ȡ�ļ������ص����ܸ��� 
int read_file(STUDENTS stu[])
{
	FILE* fp;
	int point = -1;
	fopen_s(&fp, "stu.txt", "rt");
	if (fp == NULL)
	{
		printf("\n\n*****����ļ������ڣ��봴��");
		return 0;
	}
	while (!feof(fp))
	{
		point++;
		fread(&stu[point], sizeof(STUDENTS), 1, fp);
	}
	fclose(fp);
	return point;

}

//�洢���ݵ��ļ��� 
void save_file(STUDENTS stu[], int sum)//sum���ܸ��� 
{
	FILE* fp;
	int i=0;
	fopen_s(&fp, "stu.txt", "a+");
	fwrite(&stu[i], sizeof(STUDENTS), 1, fp);
	/*for (i = 0; i < sum; i++)
		if (fwrite(&stu[i], sizeof(STUDENTS), 1,fp) != 1)
			printf("д�ļ�����!\n");

	if ((fopen_s(&fp, "temp.txt", "w")) == NULL)
	{
		printf("д�ļ�����!\n");
		return;
	}
	*/
	fclose(fp);
	

}


/*����ѧ����Ϣ*/
//���ص������� 
int input(STUDENTS stu[], int sum)
{
	int x;
	for (; sum < MAX; sum++)
	{
		system("cls");

		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                             �{\n");
		printf("                   �{        ����ѧ��������Ϣ     �{\n");
		printf("                   �{                             �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

		printf("\n\n                 ¼��ѧ����Ϣ  (���%d��)\n", MAX);
		printf("               ----------------------------\n");
		printf("\n                     ��%d��ѧ��\n", sum + 1);
		printf("\n ������ѧ����ѧ��:");
		scanf_s("%d", &stu[sum].num);
		printf("\n ������ѧ��������:");
		scanf_s("%s", stu[sum].name, 10);
		printf("\n ������ѧ�����Ա�:");
		scanf_s("%s", stu[sum].sex, 10);
		printf("\n ������ѧ��������:");
		scanf_s("%d", &stu[sum].age);
		printf("\n ������ѧ���İ༶:");
		scanf_s("%s", stu[sum].studentclass, 10);
		printf("\n ������ѧ���������:");
		scanf_s("%d", &stu[sum].dorm, 10);
		printf("		�����ɹ���");

		//ѡ����� 
		selectOperate();
		if (a == 0)
			return sum + 1;
	}
	return sum + 1;

}


/*��ӡѧ����Ϣ*/
void output(STUDENTS stu[], int sum)
{
	int i;
	system("cls");
	printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
	printf("                   �{                                �{\n");
	printf("                   �{        ��ӡѧ��������Ϣ        �{\n");
	printf("                   �{                                �{\n");
	printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

	printHead();
	for (i = 0; i < sum; i++)
		printSearch(stu, i);

	pause();

}


/*����  */



/*����student*/
//���źõ�װ��һ���µ�students������ ����Ҫ�浽�ļ��� 
void cpStu(STUDENTS stu0[], STUDENTS stu[], int sum) {
	int i;
	for (i = 0; i < sum; i++) {
		stu[i].num = stu0[i].num;
		strcpy_s(stu[i].name, stu0[i].name);
		strcpy_s(stu[i].sex, stu0[i].sex);
		stu[i].age = stu0[i].age;
		strcpy_s(stu[i].studentclass, stu0[i].studentclass);
		stu[i].dorm = stu0[i].dorm;
	}
}

/*������Ԫ������*/
void exchangeData(STUDENTS* stu1, STUDENTS* stu2) {
	stu1->num = stu2->num;

	stu1->dorm = stu2->dorm;

	stu1->age = stu2->age;

	strcpy_s(stu1->name, stu2->name);

	strcpy_s(stu1->sex, stu2->sex);

	strcpy_s(stu1->studentclass, stu2->studentclass);
}


int selectSort() {

	int choice;

	printf("\n\n\n     ********����ѡ��������������********\n\n");
	printf("                1. ѧ��\n\n");
	printf("                2. �༶\n\n");
	printf("                3. �����\n\n");
	printf("                4. ����\n\n");
	printf("                0. �������˵�\n\n");
	printf("                 ��ѡ��0-3��:");
	scanf_s("%d", &choice);
	return choice;
}


/*��������Ŵ�С��������   ð��*/

void sortByDorm(STUDENTS stu0[], int sum, STUDENTS stup[])

{
	STUDENTS stu1;  //�м���� 
	int i, j;

	cpStu(stu0, stup, sum);

	for (i = 0; i < sum - 1; i++)
		for (j = 0; j < sum - 1 - i; j++)
			if (stup[j].dorm > stup[j + 1].dorm)
			{
				exchangeData(&stu1, &stup[j]);
				exchangeData(&stup[j], &stup[j + 1]);
				exchangeData(&stup[j + 1], &stu1);
			}

}

/*���ݰ༶��С��������   ѡ��*/

void sortByClass(STUDENTS stu0[], int sum, STUDENTS stup[])

{

	STUDENTS stu1;			//�м���� 
	int i, j, k;

	cpStu(stu0, stup, sum);

	for (i = 0; i < sum - 1; i++)
	{
		k = i;
		for (j = i + 1; j < sum; j++)
			if (strcmp(stup[k].studentclass, stup[j].studentclass) > 0)
				k = j;


		if (k != i)
		{
			exchangeData(&stu1, &stup[i]);
			exchangeData(&stup[i], &stup[k]);
			exchangeData(&stup[k], &stu1);
		}
	}


}

/*���������Ӵ�С����   �۰��������*/
 //��Ϊ�����Ǵ�stu[1]��ʼ������,���Ե��ٴ����м���� 
void sortByName(STUDENTS stu0[], int sum, STUDENTS stup[])

{
	STUDENTS stu1;			//�м���� 
	STUDENTS stu[1000];
	int i, j, low, high, mid;

	for (i = 0; i < sum; i++) {
		stu[i + 1].num = stu0[i].num;
		strcpy_s(stu[i + 1].name, stu0[i].name);
		strcpy_s(stu[i + 1].sex, stu0[i].sex);
		stu[i + 1].age = stu0[i].age;
		strcpy_s(stu[i + 1].studentclass, stu0[i].studentclass);
		stu[i + 1].dorm = stu0[i].dorm;
	}


	for (i = 2; i < sum + 1; i++) {
		exchangeData(&stu1, &stu[i]);    /*���������Ԫ�ص�stu1*/
		low = 1; high = i - 1;
		while (low <= high)
		{
			mid = (low + high) / 2;
			if (strcmp(stu1.name, stu[mid].name) > 0)
				low = mid + 1;
			else
				high = mid - 1;

		}
		for (j = i - 1; j >= high + 1; j--)
			exchangeData(&stu[j + 1], &stu[j]);//����Ԫ�أ����������λ 
		exchangeData(&stu[high + 1], &stu1);
	}

	for (i = 0; i < sum; i++) {
		stup[i].num = stu[i + 1].num;
		strcpy_s(stup[i].name, stu[i + 1].name);
		strcpy_s(stup[i].sex, stu[i + 1].sex);
		stup[i].age = stu[i + 1].age;
		strcpy_s(stup[i].studentclass, stu[i + 1].studentclass);
		stup[i].dorm = stu[i + 1].dorm;
	}

}




/*����ѧ�ŴӴ�С����   �����ϣ������*/

void ShellInsert(STUDENTS stup[], int sum, int dk) {
	int i, j, k;
	STUDENTS stu1;//�м���� 
	for (k = 0; k < dk; k++)
		for (i = dk + k; i < sum; i = i + dk)
			if (stup[i].num < stup[i - dk].num)
			{

				exchangeData(&stu1, &stup[i]);

				for (j = i - dk; j >= 0 && stu1.num < stup[j].num; j = j - dk)//��¼�����    			
					exchangeData(&stup[j + dk], &stup[j]);

				exchangeData(&stup[j + dk], &stu1);
			}
}
void sortByNum(STUDENTS stu[], int sum, STUDENTS stup[])
{

	int i, x;

	cpStu(stu, stup, sum);

	int dlta[5] = { 5,4,3,2,1 };
	for (x = 0; x < 5; x++)
		ShellInsert(stup, sum, dlta[x]);


}

//�ܵĺ��� 
void sortStudent(STUDENTS stu[], int sum) {
	STUDENTS stup[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	int choice, x, i;
	do {
		system("cls");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ѧ��������Ϣ����        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

	select:
		choice = selectSort();

		system("cls");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ѧ��������Ϣ����        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

		switch (choice)
		{
		case 1: sortByNum(stu, sum, stup); break;/*ѧ��ѧ����Ϣ˳��*/
		case 2: sortByClass(stu, sum, stup); break;/*ѧ���༶��Ϣ˳��*/
		case 3: sortByDorm(stu, sum, stup); break;/*ѧ��������Ϣ˳��*/
		case 4: sortByName(stu, sum, stup); break;/*ѧ��������Ϣ˳��*/
		case 0: break;
		}
		//��ӡ�ź���� 
		printHead();
		for (i = 0; i < sum; i++)
			printSearch(stup, i);


		if (choice == 1 || choice == 2 || choice == 3 || choice == 4)
		{
			printf("\n\n");
		button:
			printf("������ѯ�밴1,�������˵��밴0  ");
			scanf_s("%d", &x);
			if (x == 1)
				x = 1;
			else if (x == 0)
				continue;
			else
			{
				printf("��������ȷ��ָ��\n");
				goto button;
			}
		}
		else if (choice == 0)
			x = 0;
		else
		{
			printf("\n\t\t��������ȷ��ָ��\n");
			goto select;
		}

	} while (x == 1);

}








/* ������������ָ��point*/
///


//��ѯ�����޸ĵ�ѡ�� 
int selectChoice(char tiaojian[20]) {

	int choice;


	printf("\n\n\n     ********��������ĸ�����%s********\n\n", tiaojian);
	printf("                1. ѧ��\n\n");
	printf("                2. ����\n\n");
	printf("                3. �Ա�\n\n");
	printf("                4. ����\n\n");
	printf("                5. �༶\n\n");
	printf("                6. �����\n\n");
	printf("                0. �������˵�\n\n");
	printf("                 ��ѡ��0-6��:");
	scanf_s("%d", &choice);
	return choice;
}


///????????????????????????????Ϊʲô�����ָ��÷��ز˿��У���������ָ�룬�������ǵ�ַ�ģ������� 
Points* connectPoint(Points* r, Points* p, int i) {
	p = (Points*)malloc(sizeof(Points));
	p->a = i;
	r->points = p;
	r = p;
	return r;
}

//choice��ָ���˵��еĹ���ѡ��ַ�����tiaojianΪ��Ӧ���ַ����������ѡ���ѯ�Ļ���
//tiaojian���ν�����Ӧ��Ϊ "��ѯ"��������Ϊ����ߺ����ĸ����ԡ� 
Points* findPoint(STUDENTS stu[], int sum, int choice, char tiaojian[])
{
	int i, j = 0; Points* p = 0, * q, * r; q = (Points*)malloc(sizeof(Points)); r = q;
	int num, age, dorm; char classs[20], sex[5], name[20];

	printf("     \n\n��������Ҫ���ҵ�ѧ����%s", tiaojian);
	switch (choice)
	{
	case 1: scanf_s("%d", &num);
		for (i = 0; i < sum; i++)
			if (num == stu[i].num)
				r = connectPoint(r, p, i);
		break;
	case 2: scanf_s("%s", name, 10); for (i = 0; i < sum; i++)if (strcmp(name, stu[i].name) == 0)r = connectPoint(r, p, i); break;
	case 3: scanf_s("%s", sex, 10); for (i = 0; i < sum; i++)if (strcmp(sex, stu[i].sex) == 0)r = connectPoint(r, p, i); break;
	case 4: scanf_s("%d", &age); for (i = 0; i < sum; i++)if (age == stu[i].age)r = connectPoint(r, p, i); break;
	case 5: scanf_s("%s", classs, 10); for (i = 0; i < sum; i++)if (strcmp(classs, stu[i].studentclass) == 0)r = connectPoint(r, p, i); break;
	case 6: scanf_s("%d", &dorm); for (i = 0; i < sum; i++)if (dorm == stu[i].dorm)r = connectPoint(r, p, i); break;
	}

	r->points = NULL;

	return q;

}



// 



/*��ѯѧ����Ϣ*/
void inquire(STUDENTS stu[], int sum) {

	int choice;
	Points* p;

	do {
		system("cls");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ��ѯѧ��������Ϣ        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

	button:
		choice = selectChoice(chaxun);

		system("cls");

		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ��ѯѧ��������Ϣ        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");


		//switch���治�ܵ��������ܣ�Ϊʲô������������������
		switch (choice)
		{
		case 1:p = findPoint(stu, sum, choice, xuehao); break;
		case 2:p = findPoint(stu, sum, choice, xingming); break;
		case 3:p = findPoint(stu, sum, choice, xingbie); break;
		case 4:p = findPoint(stu, sum, choice, nianling); break;
		case 5:p = findPoint(stu, sum, choice, banji); break;
		case 6:p = findPoint(stu, sum, choice, sushe); break;
		case 0:return;
		default:printf("��������ȷ��ָ��"); goto button;//����ѭ����	
		}

		if (p->points != NULL)
		{
			p = p->points;

			printHead();

			while (p != NULL)
			{
				printSearch(stu, p->a);
				p = p->points;
			}
		}
		else
			printfNotFound();
		//ѡ����� 
		selectOperate();
	} while (a);

}


//���ַ�ֻ�����ڲ���һ��     Ŀǰֻ��ѧ�ţ��������������� 
Points* findPoint2(STUDENTS stu[], int sum, int choice, char tiaojian[])
{
	int i, j = 0; Points* p = 0, * q, * r; q = (Points*)malloc(sizeof(Points)); r = q;
	int num, age, dorm; char classs[20], sex[5], name[20];



	printf("     \n\n��������Ҫ���ҵ�ѧ����%s", tiaojian);

	switch (choice)
	{
	case 1: scanf_s("%d", &num); break;
	case 2: scanf_s("%s", &name); break;
	case 3: scanf_s("%d", &dorm); break;
	}


	int flag = 0;
	int low = 0, high = sum - 1, mid;
	while (low <= high) {
		mid = (low + high) / 2;


		switch (choice)
		{
		case 1:if (num == stu[mid].num) { r = connectPoint(r, p, mid); printf("mid==%d", mid); flag = 1; }
			  else if (stu[mid].num > num)high = mid - 1; else low = mid + 1;
			break;
		case 2: if (strcmp(name, stu[mid].name) == 0) { r = connectPoint(r, p, mid); flag = 1; } if (strcmp(stu[mid].name, name) > 0)high = mid - 1; else low = mid + 1; break;
		case 3: if (dorm == stu[mid].dorm) { r = connectPoint(r, p, mid); flag = 1; } if (stu[mid].dorm > dorm)high = mid - 1; else low = mid + 1; break;
		}
		//����ҵ���������ѭ�� 
		if (flag)
			break;

	}

	r->points = NULL;

	return q;

}


/*���ַ���ѯѧ����Ϣ*/
void inquire2(STUDENTS stu[], int sum) {
	STUDENTS stup1[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	STUDENTS stup2[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	STUDENTS stup3[1000];//���ã����ź���ķ����������ԭ���Ļ��� 
	//���ַ��������� 
	sortByNum(stu, sum, stup1);
	sortByName(stu, sum, stup2);
	sortByDorm(stu, sum, stup3);

	int choice;
	Points* p;


	do {
		system("cls");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ��ѯѧ��������Ϣ        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

	button:
		printf("\n\n\n     ********��������ĸ�������ѯ********\n\n");
		printf("                1. ѧ��\n\n");
		printf("                2. ����\n\n");
		printf("                3. �����\n\n");
		printf("                0. �������˵�\n\n");
		printf("                 ��ѡ��0-3��:");
		scanf_s("%d", &choice);

		system("cls");

		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        ��ѯѧ��������Ϣ        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");


		//switch���治�ܵ��������ܣ�Ϊʲô������������������
		switch (choice)
		{
		case 1:p = findPoint2(stup1, sum, choice, xuehao); break;//���ַ���ѯ 
		case 2:p = findPoint2(stup2, sum, choice, xingming); break;//���ַ���ѯ 
		case 3:p = findPoint2(stup3, sum, choice, sushe); break;//���ַ���ѯ 
		case 0:return;
		default:printf("��������ȷ��ָ��"); goto button;//����ѭ����	
		}

		if (p->points != NULL)
		{
			p = p->points;

			printHead();

			while (p != NULL)
			{
				if (choice == 1) {
					printSearch(stup1, p->a);
					p = p->points;
				}
				if (choice == 2) {
					printSearch(stup2, p->a);
					p = p->points;
				}
				if (choice == 3) {
					printSearch(stup3, p->a);
					p = p->points;
				}
			}
		}
		else
			printfNotFound();
		//ѡ����� 
		selectOperate();
	} while (a);

}


//�޸ĺ�ɾ���ж�����ѧ������ 
int operateNum(int sum) {
	int n;
	printf("��������Ҫ������ѧ���ĸ�����");
	scanf_s("%d", &n);
	if (n > sum)
	{
		printf("\n\n	����ѧ��������������������ʧ��\n");
		selectOperate();
		return 0;
	}
	else if (n <= 0)
	{
		printf("\n\n	����ѧ����������С�ڻ����0������ʧ��\n");
		selectOperate();
		return 0;
	}
	return n;
}



/*ֻ�ܸ���ѧ��ɾ��ѧ����Ϣ*/

void exchangeData(STUDENTS* stu1, STUDENTS* stu2);

//�������� 
int deletel(STUDENTS stu[], int sum)
{
	a = 1;
	system("cls");
	int i, j = 0, n = 0, flag = 1;
	Points* p;
	printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
	printf("                   �{                                �{\n");
	printf("                   �{        ɾ��ѧ��������Ϣ        �{\n");
	printf("                   �{                                �{\n");
	printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

	while (n == 0)//������յ�����������n�ж�ѧ��������a�ж��Ƿ񷵻����˵� 
	{
		n = operateNum(sum);
		//ѡ����� 
		if (a == 0)
			return sum;  //0�ͷ������˵�	
	}

	do {

		if (flag) {

			system("cls");
			Points* p;
			printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
			printf("                   �{                                �{\n");
			printf("                   �{        ɾ��ѧ��������Ϣ        �{\n");
			printf("                   �{                                �{\n");
			printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		}

		//��һ��ɾһ�� 
		p = findPoint(stu, sum, 1, xuehao);
		p = p->points;
		if (p != NULL)
		{
			i = p->a;
			//�Ѻ����һ�θ��ǵ�ǰ��һ�� 
			for (; i < sum - 1; i++)
				exchangeData(&stu[i], &stu[i + 1]);

			printf("ɾ���ɹ�\n");
			flag = 0;
			j++;
			if (j == n)
			{
				printf("\n\nɾ�����������\n");
				//ѡ����� 
				selectOperate();
				if (a == 0)
					return sum - n;
				else
					deletel(stu, sum - n);
			}
		}
		else {
			printf("�����ѧ�Ų����ڣ�����ʧ��\n");

			//ѡ����� 
			selectOperate();
			if (a == 0)
				return sum - j;
		}
	} while (a == 1 && j < n);

}



/*ֻ�ܸ���ѧ���޸�ѧ����Ϣ*/

void change(STUDENTS stu[], int sum)
{
	int choice;
	Points* p;

	do {
		system("cls");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		printf("                   �{                                �{\n");
		printf("                   �{        �޸�ѧ��������Ϣ        �{\n");
		printf("                   �{                                �{\n");
		printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
		p = findPoint(stu, sum, 1, xuehao);

		p = p->points;

		if (p != NULL)
		{
			system("cls");
			printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");
			printf("                   �{                                �{\n");
			printf("                   �{        �޸�ѧ��������Ϣ        �{\n");
			printf("                   �{                                �{\n");
			printf("                   �~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~�~\n");

			int i = p->a;

			print(stu, i);
		button:
			choice = selectChoice(xiugai);

			switch (choice)
			{
			case 1:printf("\n   ��������ĵ���ѧ��"); scanf_s("%d", &stu[i].num); break;
			case 2:printf("\n   ��������ĵ�������"); scanf_s("%s", stu[i].name); break;
			case 3:printf("\n   ��������ĵ����Ա�"); scanf_s("%s", stu[i].sex);  break;
			case 4:printf("\n   ��������ĵ�������"); scanf_s("%d", &stu[i].age);  break;
			case 5:printf("\n   ��������ĵ��°༶"); scanf_s("%s", stu[i].studentclass); break;
			case 6:printf("\n   ��������ĵ�������"); scanf_s("%d", &stu[i].dorm); break;
			case 0:return;
			default:printf("��������ȷ��ָ��"); goto button;
			}

			printf("\n   �޸ĳɹ���");
			print(stu, i);
		}
		else
			printfNotFound();

		//ѡ����� 
		selectOperate();
		if (a == 0)
			return;
	} while (a);
}



void pagedis()
{
	printf(" \n\n\n                   **********************************\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *  ��ӭ����ѧ��������Ϣ����ϵͳ  *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   *                                *\n");
	printf("                   **********************************\n");
}
//��ӭ 
void welcome() {

	char heart[30][150] = {
"                           ************                           ************",
"                        ******************         	        ******************",
"                    ******************#*******        	    **************************",
"                 **********************#*********       ********************************",
"                **********************##########***   **************#********************  ",
"               **********************#*********#**** **##********#************************   ",
"               *********##########**#****#****#**********##****#**************************  ",
"               **********#*******#*#*****#***#***************#********#########***********  ",
"                **********#*****#********#***********#####***#********#*******#**********  ",
"                 ***********#***#********#***************#***#******#*#****#**#*********  ",
"                  ***********##**********#**************#*****#****#***#*****#*#*******   ",
"                   **********##*********#*#************#*****####*****#*******#*******  ",
"                    ********#**#*******#***#************#*************#**************    ",
"                      *****#****#*****#*****#************#************#************    ",
"                        **#**********#*******#******######************#**********     ",
"                          **********#*********#*****###########################     ",
"                            **************************************************      ",
"                              **********************************************     ",
"                                ******************************************     ",
"                                  **************************************    ",
"                                    **********************************      ",
"                                      ******************************   ",
"                                        **************************   ",
"                                          **********************  ",
"                                            ******************  ",
"                                              **************      ",
"                                                **********       ",
"                                                  ******    ",
"                                                    **  "
	};

	int i;
	for (i = 0; i < 29; i++)   //���д�ӡ
		printf("%s\n", heart[i]);
}



void bye() {
	system("cls");
	char heart[11][150] = {
"\t\t  _____   _                        _             ",
"\t\t |_   _| | |_     __ _    _ _     | |__    ___     o O O   ",
"\t\t   | |   | ' \\   / _` |  | ' \\    | / /   (_-<    o        ",
"\t\t  _|_|_  |_||_|  \\__,_|  |_||_|   |_\\_\\   /__/_   TS__[O]  ",
"\t\t_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"|_|\"\"\"\"\"| {======| ",
"\t\t\"`-0-0-\'\"`-0-0-\'\"`-0-0-\'\"`-0-0-\'\"`-0-0-\'\"`-0-0-\'./o--000'  "
	};

	int i;
	printf("\n\n");
	for (i = 0; i < 6; i++)   //���д�ӡ
		printf("%s\n", heart[i]);
}

void designer() {
	printf("\n\n\t\t������������������Ϣ�����������\n\n");
	printf("\t\t	���	                         ���\n\n");
	printf("\t\t	���	������                   ���\n\n");
	printf("\t\t	���	                         ���\n\n");
	printf("\t\t	���	�༶��                   ���\n\n");
	printf("\t\t	���	                         ���\n\n");
	printf("\t\t	���	ѧ�ţ�                   ���\n\n");
	printf("\t\t	���	                         ���\n\n");
	printf("\t\t���������������������������\n");
}

void check()
{
	char userName[5];/*�û���*/

	char userPWD[5];/*����*/

	int i;

	system("color 2C");

	for (i = 1; i < 4; i++)
	{
		/*�û����������Ϊ123;*/

		printf("\n       �����������û�����123��:");

		gets(userName);

		printf("\n       �������������루123��:");

		gets(userPWD);

		if ((strcmp(userName, "123") == 0) && (strcmp(userPWD, "123") == 0))/*��֤�û���������*/
		{

			system("cls");
			welcome();
			printf("\n      3����Զ���ת");
			Sleep(3000);
			return;
		}
		else
		{
			if (i < 3)
				printf("�û����������������������!");
			else
			{
				printf("��������3�ν��û������������ϵͳ���˳�!");
				exit(1);
			}
		}
	}

}


void menu()
{


	STUDENTS stu[20];
	int choice, sum;

	sum = read_file(stu);

	if (sum == 0)
	{
		printf("����¼����������Ϣ�����س������*****\n");
		getchar();

		sum = input(stu, sum);
	}

	system("cls");

	do
	{
		system("cls");

	button:
		printf("\n\n\n               ********ѧ��������Ϣ����ϵͳ********\n\n");
		printf("                      1. ����ѧ��������Ϣ\n\n");
		printf("                      2. ��ӡѧ��������Ϣ\n\n");
		printf("                      3. ��ѯѧ��������Ϣ\n\n");
		printf("                      4. �޸�ѧ��������Ϣ\n\n");
		printf("                      5. ɾ��ѧ��������Ϣ\n\n");
		printf("                      6. ѧ��������Ϣ����\n\n");
		printf("                      0. �˳�ϵͳ\n\n");
		printf("                       ��ѡ��0-6��:");

		scanf_s("%d", &choice);


		switch (choice)
		{
		case 1: sum = input(stu, sum); break;/*����ѧ����Ϣ*/
		case 2: output(stu, sum); break;/*��ӡѧ����Ϣ*/
		case 3: inquire(stu, sum); break;/*��ѯѧ����Ϣ*/
		case 4: change(stu, sum); break;/*�޸�ѧ����Ϣ*/
		case 5: sum = deletel(stu, sum); break;/*ɾ��ѧ����Ϣ*/
		case 6: sortStudent(stu, sum); break;/*ѧ����Ϣ˳��*/
		case 0:  bye(); designer(); break;
		default:system("cls"); printf("\n		��������ȷ��ָ�\n");
			goto button;
		}

	} while (choice != 0);

	save_file(stu, sum);
}


int main()
{
	pagedis();

	check();

	menu();

	return 0;

}
