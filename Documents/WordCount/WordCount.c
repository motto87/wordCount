#pragma warning(disable:4996)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main(int argc, char* argv[])
{
    int ch, count = 1;
    FILE* pt;

    //�ж��Ƿ������ļ�
    if (argc != 3) {
        printf("��ʹ�ø�ʽ��%s + -c��-w  +  �ļ��� (-c��ʾͳ���ַ�������-w��ʾͳ�Ƶ��ʸ���)", argv[0]);
        exit(1); //�������� 
    }

    //�ܷ�ɹ����ļ�
    if ((pt = fopen(argv[2], "r")) == NULL) {
        printf("���ļ�ʧ��", argv[2]);
        exit(1);
    }

    if (strcmp(argv[1], "-c") == 0 || strcmp(argv[1], "-C")==0)  {
        count = 0;
        while ((ch = getc(pt)) != EOF) {
            count++;
        }
        printf("�ַ�����%d��\n", count);
    }
    else if (strcmp(argv[1], "-w")==0 || strcmp(argv[1], "-W")==0){
        while ((ch = getc(pt)) != EOF) {
            if ((ch == ' ') || (ch == ','))
                count++;
        }
        printf("��������%d��\n", count);
    }
    fclose(pt);
    return 0;
}

