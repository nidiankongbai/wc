#include"stdafx.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>



void countcharacter(char *filename);
void countword(char *filename);
void countline(char *filename);

int main(char argc, char *argv[]) {
	switch (argv[1][1]) {		//���������в���ѡ�����
	case 'c': countcharacter(argv[2]); break;
	case 'w': countword(argv[2]); break;
	case 'l': countline(argv[2]); break;
	}
	
	system("pause");
	return 0;
}

//�����ַ���
void countcharacter(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int count = 0;
	
	char str[20] = { 0 };      
	while (fgets(str, sizeof(str), fp))
	{
		count += strlen(str);	
	}
	fclose(fp);
	printf("number of character is %d\n", count+1); //�����ַ������� ���͡�\n'�����������'\n'
}

//���㵥����
void countword(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int count, tag, i;
	count = 0; tag = 0;
	char str[20];
	while (fgets(str, sizeof(str), fp))
	{

		for (i = 0; i<strlen(str); i++)
		{

			if (isalpha(str[i]) && tag == 0) { count++; tag = 1; }
			else if (isalpha(str[i]) == 0) { tag = 0; }
		}
	}
	fclose(fp);
	printf("number of word is %d\n", count);
}

//��������
void countline(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int count = 0, i;
	char str[20];
	while (fgets(str, sizeof(str), fp))
	{
		i = 0;
		while (str[i] != '\n') i++;
		count++;
	}
	fclose(fp);
	printf("number of line is %d\n", count);
}