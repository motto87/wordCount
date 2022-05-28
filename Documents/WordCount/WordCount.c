#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int character, count = 1;
    FILE* test;
    //判断是否输入文件
    if (argc != 3) 
	{
        printf("请输入正确文件名！");
        //结束程序 
        exit(1); 
    }
    //判断能否成功打开文件，文件打开失败 
    if ((test = fopen(argv[2], "r")) == NULL)
	{
        printf("打开文件失败", argv[2]);
        exit(1);
    }

	//打开文件成功且为‘-c’ 
    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C")==0)  
	{
        count = 0;
        while ((character = getc(test)) != EOF) {
            count++;
        }
        printf("该文件的字符数：%d个\n", count);
    }
    
    //打开文件成功且为‘-w’ 
    else if (strcmp(argv[1], "-w")==0 || strcmp(argv[1], "-W")==0)
	{
        while ((character = getc(test)) != EOF) 
		{
            if ((character == ' ') || (character == ','))
            {
           	   count++;
			}   
        }
        printf("该文件的单词数：%d个\n", count);
    }
    fclose(test);
    return 0;
}

