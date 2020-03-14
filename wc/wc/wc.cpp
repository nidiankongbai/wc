#include"stdafx.h"
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<ctype.h>
#include<stdlib.h>



int countcharacter(char *filename);
void countword(char *filename);
void countline(char *filename);

int main(char argc, char *argv[]) {
	int x;
	switch (argv[1][1]) {		//根据命令行参数选择操作
	case 'c': x = countcharacter(argv[2]); printf("number of character is %d\n",x); break;
	case 'w': countword(argv[2]); break;
	case 'l': countline(argv[2]); break;
	}
	
	system("pause");
	return 0;
}

//计算字符数
int countcharacter(char *filename)
{
	FILE *fp = fopen(filename, "r");
	int count = 0,i;
	
	char str[20];
	while (fgets(str, sizeof(str), fp))
	{
		for (i = 0; i<strlen(str); i++)
		{
			if (str[i] < 0&& str[i+1] < 0) { count++; i++;continue; }
			else count++;
		}
	}
	fclose(fp);
	//printf("number of character is %d\n", count); //计算字符包括‘ ’和‘\n'
	return count;
}

//计算单词数
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
			if (str[i] < 0) continue;
			if (isalpha(str[i]) && tag == 0) { count++; tag = 1; }
			else if (isalpha(str[i]) == 0) { tag = 0; }
		}
	}
	fclose(fp);
	printf("number of word is %d\n", count);
}

//计算行数
void countline(char *filename)
{
	if (countcharacter(filename) == 0) { printf("number of line is 0\n"); return; }
	FILE *fp = fopen(filename, "r");
	int count = 1, i;
	char str[20];
	while (fgets(str, sizeof(str), fp))
	{
		
		i = 1;
		for (i = 0; i<strlen(str); i++)
		{
			if (str[i] < 0) continue;
			if (str[i] == '\n') count++;
		}

	}
	fclose(fp);
	printf("number of line is %d\n", count);
}