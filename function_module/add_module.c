#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"


void add_module(){
    continue_add:
    //�����˵�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
    printf("->��ǰλ�ã����ѧ����Ϣ\n");

    char stu_num[20];
    char name[20];
    char gender[10];
    int age;
    float chinese,math,english;

    //��ȡ�û������ѧ����Ϣ��д���ļ�
    printf("->������ѧ��ѧ�ţ�");
    scanf("%s",&stu_num);
    printf("->������ѧ��������");
    scanf("%s",&name);
    printf("->������ѧ���Ա�");
    scanf("%s",&gender);
    printf("->������ѧ�����䣺");
    scanf("%d",&age);
    printf("->������ѧ�������ĳɼ���");
    scanf("%f",&chinese);
    printf("->������ѧ������ѧ�ɼ���");
    scanf("%f",&math);
    printf("->������ѧ����Ӣ��ɼ���");
    scanf("%f",&english);

    FILE *fp= fopen("../stu_info/stu_info.txt","a");
    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",stu_num,name,gender,age,chinese,math,english);
    fclose(fp);
    printf("\n->ѧ����Ϣ��ӳɹ���\n\n");
    Sleep(2000);

    re_input_add_menu_choice:
    //ѯ���û���һ������
    printf("->�Ƿ���Ҫ�������ѧ����Ϣ����y/n��");
    char whether_continue_add;
    fflush(stdin);
    scanf("%c",&whether_continue_add);
    switch (whether_continue_add) {
        //�������
        case 'y':{
            goto continue_add;
            break;
        }
        //���������
        case 'n':{
            secondary_menu();
            break;
        }
        //���벻�Ϸ�
        default:{
            printf("->���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            goto re_input_add_menu_choice;
            break;
        }
    }
}