#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdlib.h"
#include "stdio.h"
#include "windows.h"

void delete_module(){
    char stu_num[20];
    char name[20];
    char gender[10];
    int age;
    float chinese,math,english;
    continue_query:
    //�����˵�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
    printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
    printf("->1����ѧ�Ų�ѯ��ɾ��\n");
    printf("->2����������ѯ��ɾ��\n");
    printf("->3�����Ա��ѯ��ɾ��\n");
    printf("->4�������ϼ��˵�\n");

    //��ѧ����Ϣ�����ڴ�
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int count=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        p->prev=q;
        q->next=p;
        q=p;
        count++;
    }
    fclose(fp);
    //���ݱ�����һ��Ϊ���У�������������һ���ڵ�Ϊ��
    p->next=NULL;

    t=head->next;

    int whether_find=0;
    //��ȡ�û����룬�ж�ִ�з���
    char query_menu_input;
    printf("\n->������ѡ�1/2/3/4��");
    fflush(stdin);
    scanf("%c",&query_menu_input);
    switch (query_menu_input) {
        //��ѧ�Ų�ѯ
        case '1':{
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
            printf("->������ѧ��ѧ�ţ�");
            scanf("%s",&stu_num);
            t=head->next;
            while (t!=NULL){
                if(strcmp(stu_num,t->stu_num)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                }
                t=t->next;

            }
            printf("��ɾ��%d���¼\n\n",whether_find);
            //���޸ĺ����Ϣд���ļ�
            t=head->next;
            fp= fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count-1; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }

//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->ϵͳ��û�и�ѧ������Ϣ��\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
            //��������ѯ
        case '2':{
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
            printf("->������ѧ��������");
            scanf("%s",&name);
            t=head->next;
            while (t!=NULL){
                if(strcmp(name,t->name)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                }
                t=t->next;

            }
            printf("��ɾ��%d���¼\n\n",whether_find);
            //���޸ĺ����Ϣд���ļ�
            t=head->next;
            fp= fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count-1; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }
//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->ϵͳ��û�и�ѧ������Ϣ��\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
        //���Ա��ѯ
        case '3':{
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
            printf("->������ѧ���Ա�");
            scanf("%s",&gender);
            t=head->next;
            while (t!=NULL){
                if(strcmp(gender,t->gender)==0){
                    system("cls");
                    fflush(stdin);
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣɾ��\n\n");
                    p=t;
                    t->prev->next=t->next;
                    t->next->prev=t->prev;
                    whether_find+=1;
                    count--;
                }
                t=t->next;

            }
            printf("��ɾ��%d���¼\n\n",whether_find);

            //���޸ĺ����Ϣд���ļ�
            t=head->next;
            fp=fopen("../stu_info/stu_info.txt","w");

            for (int i = 1; i < count; i++) {
                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                t=t->next;
            }
//            while (t!=NULL){
//                fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
//                t=t->next;
//            }
            fclose(fp);
            count=0;

            if(whether_find==0){
                printf("->ϵͳ��û�и�ѧ������Ϣ��\n");
                Sleep(2000);
                whether_find=0;
                goto continue_query;
            }
            break;
        }
            //�����ϼ��˵�
        case '4':{
            secondary_menu();
        }
            //���벻�Ϸ�
        default:{
            printf("���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_query;
        }
    }
    //��ȡ�û����룬�ж�ִ�з���
    char whether_continue_query;
    printf("�Ƿ����ɾ������y/n��");
    scanf("%c",&whether_continue_query);
    switch (whether_continue_query) {
        //����ɾ��
        case 'y':{
            goto continue_query;
            break;
        }
            //������ɾ��
        case 'n':{
            secondary_menu();
            break;
        }
            //���벻�Ϸ�
        default:{
            printf("->���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_query;
            break;
        }
    }
}