#include "../heads/for_function_module.h"
#include "../heads/add_module.h"
#include "../heads/query_module.h"
#include "../heads/delete_module.h"
#include "../heads/statistic_module.h"
#include "../heads/modify_module.h"
#include "stdio.h"
#include "windows.h"

void secondary_menu(){
    //�����˵�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n\n");
    printf("->��ǰλ�ã�ѧ����Ϣ����\n\n");
    printf("-> 1�����ѧ����Ϣ\n");
    printf("-> 2����ѯѧ����Ϣ\n");
    printf("-> 3���޸�ѧ����Ϣ\n");
    printf("-> 4��ɾ��ѧ����Ϣ\n");
    printf("-> 5���ɼ�ͳ��\n");
    printf("-> 6���������˵�\n");

    //��ȡ�û����룬�ж�ִ�з���
    char secondary_menu_input;
    re_input_secondary_menu_choice:
    printf("\n->������ѡ�1/2/3/4/5/6��");
    fflush(stdin);
    scanf("%c",&secondary_menu_input);
    switch (secondary_menu_input) {
        //���ѧ����Ϣ
        case '1':{
            add_module();
            break;
        }
        //��ѯѧ����Ϣ
        case '2':{
            query_module();
            break;
        }
        //�޸�ѧ����Ϣ
        case '3':{
            modify_module();
            break;
        }
        //ɾ��ѧ����Ϣ
        case '4':{
            delete_module();
            break;
        }
        //�ɼ�ͳ��
        case '5':{
            statistic_module();
            break;
        }
        //�������˵�
        case '6':{
            main();
        }
        //���벻�Ϸ�
        default:{
            printf("���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            goto re_input_secondary_menu_choice;
        }
    }
}