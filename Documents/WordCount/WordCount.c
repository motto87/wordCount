#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int character, count = 1;
    FILE* test;
    //�ж��Ƿ������ļ�
    if (argc != 3) 
	{
        printf("��������ȷ�ļ�����");
        //�������� 
        exit(1); 
    }
    //�ж��ܷ�ɹ����ļ����ļ���ʧ�� 
    if ((test = fopen(argv[2], "r")) == NULL)
	{
        printf("���ļ�ʧ��", argv[2]);
        exit(1);
    }

	//���ļ��ɹ���Ϊ��-c�� 
    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C")==0)  
	{
        count = 0;
        while ((character = getc(test)) != EOF) {
            count++;
        }
        printf("���ļ����ַ�����%d��\n", count);
    }
    
    //���ļ��ɹ���Ϊ��-w�� 
    else if (strcmp(argv[1], "-w")==0 || strcmp(argv[1], "-W")==0)
	{
        while ((character = getc(test)) != EOF) 
		{
            if ((character == ' ') || (character == ','))
            {
           	   count++;
			}   
        }
        printf("���ļ��ĵ�������%d��\n", count);
    }
    fclose(test);
    return 0;
}

