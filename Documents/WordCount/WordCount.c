#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int ch, count = 1;
    FILE* pt;

    //判断是否输入文件
    if (argc != 3) {
        printf("请使用格式：%s + -c或-w  +  文件名 (-c表示统计字符个数，-w表示统计单词个数)", argv[0]);
        exit(1); //结束程序 
    }

    //能否成功打开文件
    if ((pt = fopen(argv[2], "r")) == NULL) {
        printf("打开文件失败", argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C")==0)  {
        count = 0;
        while ((ch = getc(pt)) != EOF) {
            count++;
        }
        printf("字符数：%d个\n", count);
    }
    else if (strcmp(argv[1], "-w")==0 || strcmp(argv[1], "-W")==0){
        while ((ch = getc(pt)) != EOF) {
            if ((ch == ' ') || (ch == ','))
                count++;
        }
        printf("单词数：%d个\n", count);
    }
    fclose(pt);
    return 0;
}

