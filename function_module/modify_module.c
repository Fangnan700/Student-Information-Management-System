#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"

void modify_module(){
    char stu_num[20];
    char name[20];

    continue_modify:
    //ѧ����Ϣ�޸Ĳ˵�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
    printf("->��ǰλ�ã�ѧ����Ϣ�޸�\n\n");
    printf("->1����ѧ�Ų�ѯ���޸�\n");
    printf("->2����������ѯ���޸�\n");
    printf("->3�������ϼ��˵�\n");

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

    //��ȡ�û����룬�ж�ִ�з���
    char modify_menu_input;
    printf("\n->������ѡ�1/2/3��");
    fflush(stdin);
    scanf("%c",&modify_menu_input);
    switch (modify_menu_input) {
        //��ѧ�Ų�ѯ��ɾ��
        case '1':{
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�ѧ����Ϣ�޸�\n\n");
            printf("->������ѧ��ѧ�ţ�");
            scanf("%s",&stu_num);
            t=head->next;

            t=head->next;
            int whether_find=0;
            while (t!=NULL){
                if(strcmp(stu_num,t->stu_num)==0){
                    whether_find=1;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ�޸�\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    printf("�������޸ĺ��ѧ��ѧ�ţ�");
                    fflush(stdin);
                    scanf("%s",&t->stu_num);
                    printf("�������޸ĺ��ѧ��������");
                    fflush(stdin);
                    scanf("%s",&t->name);
                    printf("�������޸ĺ��ѧ���Ա�");
                    fflush(stdin);
                    scanf("%s",&t->gender);
                    printf("�������޸ĺ��ѧ�����䣺");
                    fflush(stdin);
                    scanf("%d",&t->age);
                    printf("�������޸ĺ�����ĳɼ���");
                    fflush(stdin);
                    scanf("%f",&t->chinese);
                    printf("�������޸ĺ����ѧ�ɼ���");
                    fflush(stdin);
                    scanf("%f",&t->math);
                    printf("�������޸ĺ��Ӣ��ɼ���");
                    fflush(stdin);
                    scanf("%f",&t->english);
                }
                t=t->next;
            }
            if(whether_find==0){
                printf("δ��ѯ����ѧ������Ϣ��\n");
                Sleep(2000);
                goto continue_modify;
            }
            else{
                //���޸ĺ����Ϣд���ļ�
                t=head->next;
                fp= fopen("../stu_info/stu_info.txt","w");

                for (int i = 1; i < count; i++) {
                    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    t=t->next;
                }
                printf("�޸ĳɹ���\n");
                Sleep(2000);
                modify_menu_re1:
                printf("�Ƿ�����޸ģ���y/n��");
                char whether_continue_modify;
                fflush(stdin);
                scanf("%c",&whether_continue_modify);
                switch (whether_continue_modify) {
                    case 'y':{
                        goto continue_modify;
                    }
                    case 'n':{
                        secondary_menu();
                    }
                    default: {
                        printf("���벻�Ϸ������������룡\n\n");
                        fflush(stdin);
                        Sleep(2000);
                        goto modify_menu_re1;
                    }
                }
            }
            break;
        }

        //��������ѯ��ɾ��
        case '2':{
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�ѧ����Ϣ�޸�\n\n");
            printf("->������ѧ��������");
            scanf("%s",&name);

            t=head->next;
            int whether_find=0;
            while (t!=NULL){
                if(strcmp(name,t->name)==0){
                    whether_find=1;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ�޸�\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    printf("�������޸ĺ��ѧ��ѧ�ţ�");
                    fflush(stdin);
                    scanf("%s",&t->stu_num);
                    printf("�������޸ĺ��ѧ��������");
                    fflush(stdin);
                    scanf("%s",&t->name);
                    printf("�������޸ĺ��ѧ���Ա�");
                    fflush(stdin);
                    scanf("%s",&t->gender);
                    printf("�������޸ĺ��ѧ�����䣺");
                    fflush(stdin);
                    scanf("%d",&t->age);
                    printf("�������޸ĺ�����ĳɼ���");
                    fflush(stdin);
                    scanf("%f",&t->chinese);
                    printf("�������޸ĺ����ѧ�ɼ���");
                    fflush(stdin);
                    scanf("%f",&t->math);
                    printf("�������޸ĺ��Ӣ��ɼ���");
                    fflush(stdin);
                    scanf("%f",&t->english);
                }
                t=t->next;
            }
            if(whether_find==0){
                printf("δ��ѯ����ѧ������Ϣ��\n");
                Sleep(2000);
                goto continue_modify;
            }
            else{
                //���޸ĺ����Ϣд���ļ�
                t=head->next;
                fp= fopen("../stu_info/stu_info.txt","w");

                for (int i = 1; i < count; i++) {
                    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    t=t->next;
                }
                printf("�޸ĳɹ���\n");
                Sleep(2000);
                modify_menu_re2:
                printf("�Ƿ�����޸ģ���y/n��");
                char whether_continue_modify;
                fflush(stdin);
                scanf("%c",&whether_continue_modify);
                switch (whether_continue_modify) {
                    case 'y':{
                        goto continue_modify;
                    }
                    case 'n':{
                        secondary_menu();
                    }
                    default: {
                        printf("���벻�Ϸ������������룡\n\n");
                        fflush(stdin);
                        Sleep(2000);
                        goto modify_menu_re2;
                    }
                }
            }
            break;
        }

        //�����ϼ��˵�
        case '3':{
            secondary_menu();
            break;
        }

        default: {
            printf("���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_modify;
        }
    }

}