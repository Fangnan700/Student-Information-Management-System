#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"

void statistic_module(){

    float chinese_av();
    float math_av();
    float english_av();

    continue_statistic:
    //�ɼ�ͳ�Ʋ˵�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
    printf("->��ǰλ�ã�ѧ���ɼ�ͳ��\n\n");
    printf("->1�����ĳɼ�ͳ��\n");
    printf("->2����ѧ�ɼ�ͳ��\n");
    printf("->3��Ӣ��ɼ�ͳ��\n");
    printf("->4�������ϼ��˵�\n");

    //��ѧ����Ϣ�����ڴ�
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t,*r;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int info_num=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        info_num+=1;
        p->prev=q;
        q->next=p;
        q=p;
    }
    fclose(fp);
    //���ݱ�����һ��Ϊ���У�������������һ���ڵ�Ϊ��
    p->prev->next=NULL;
    //��¼��
    info_num=info_num-1;



    //��ȡ�û����룬�ж�ִ�з���
    char statistic_menu_input;
    printf("\n->������ѡ�1/2/3/4��");
    fflush(stdin);
    scanf("%c",&statistic_menu_input);
    switch (statistic_menu_input) {
        //ͳ�����ĳɼ�
        case '1':{
            chinese_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã����ĳɼ�ͳ��\n\n");
            printf("->1���������ѯ\n");
            printf("->2���������ѯ\n");
            printf("->3���������β�ѯ\n");
            printf("->4�������ϼ��˵�\n");

            //��ȡ�û����룬�ж�ִ�з���
            char chinese_menu_input;
            printf("\n->������ѡ�1/2/3/4��");
            fflush(stdin);
            scanf("%c",&chinese_menu_input);
            switch (chinese_menu_input) {
                //�������ѯ
                case '1':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->chinese<p->chinese)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->����ƽ����Ϊ��%.2f\n\n",chinese_av());

                    chinese_statistic_re1:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            //break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto chinese_statistic_re1;
                            //break;
                        }
                    }
                    //break;
                }


                //�������ѯ
                case '2':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->chinese>p->chinese)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->����ƽ����Ϊ��%.2f\n\n",chinese_av());

                    chinese_statistic_re2:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto chinese_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //�������β�ѯ
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    chinese_query_by_fractional_segment:
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã����ĳɼ������β�ѯ\n\n");
                    printf("->������Ҫ��ѯ�����ĳɼ�������:\n");
                    printf("->��ͷ֣�");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->��߷֣�");
                    fflush(stdin);
                    scanf("%f",&max);

                    //����û�����������Ƿ�Ϸ�
                    if(min>max){
                        printf("���벻�Ϸ������������룡\n\n");
                        fflush(stdin);
                        goto chinese_query_by_fractional_segment;
                    }
                    else{
                        q=head;
                        p=head->next;
                        while (p!=NULL){
                            if(p->chinese<min||p->chinese>max){
                                r=p;
                                p=p->next;
                                q->next=p;
                                free(r);
                            }
                            else{
                                p=p->next;
                                q=q->next;
                            }
                        }
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->����ƽ����Ϊ��%.2f\n\n",chinese_av());

                    chinese_query_by_fractional_segment_re:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y': {
                            goto continue_statistic;
                            //break;
                        }
                        case 'n': {
                            secondary_menu();
                            break;
                        }
                        default: {
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto chinese_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                //�����ϼ��˵�
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                //���벻�Ϸ�
                default:{
                    printf("���벻�Ϸ������������룡\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto chinese_statistic;
                    //break;
                }
            }
        }
        //ͳ����ѧ�ɼ�
        case '2':{
            math_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã���ѧ�ɼ�ͳ��\n\n");
            printf("->1���������ѯ\n");
            printf("->2���������ѯ\n");
            printf("->3���������β�ѯ\n");
            printf("->4�������ϼ��˵�\n");

            //��ȡ�û����룬�ж�ִ�з���
            char math_menu_input;
            printf("\n->������ѡ�1/2/3/4��");
            fflush(stdin);
            scanf("%c",&math_menu_input);
            switch (math_menu_input) {
                //�������ѯ
                case '1':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->math<p->math)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->��ѧƽ����Ϊ��%.2f\n\n",math_av());

                    math_statistic_re1:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto math_statistic_re1;
                            //break;
                        }
                    }
                    break;
                }


                //�������ѯ
                case '2':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->math>p->math)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->��ѧƽ����Ϊ��%.2f\n\n",math_av());

                    math_statistic_re2:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto math_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //�������β�ѯ
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    math_query_by_fractional_segment:
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã��ɼ������β�ѯ\n\n");
                    printf("->������Ҫ��ѯ����ѧ�ɼ�������:\n");
                    printf("->��ͷ֣�");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->��߷֣�");
                    fflush(stdin);
                    scanf("%f",&max);

                    //����û�����������Ƿ�Ϸ�
                    if(min>max){
                        printf("���벻�Ϸ������������룡\n\n");
                        fflush(stdin);
                        goto math_query_by_fractional_segment;
                    }
                    else{
                        q=head;
                        p=head->next;
                        while (p!=NULL){
                            if(p->math<min||p->math>max){
                                r=p;
                                p=p->next;
                                q->next=p;
                                free(r);
                            }
                            else{
                                p=p->next;
                                q=q->next;
                            }
                        }
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->��ѧƽ����Ϊ��%.2f\n\n",math_av());

                    math_query_by_fractional_segment_re:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y': {
                            goto continue_statistic;
                            //break;
                        }
                        case 'n': {
                            secondary_menu();
                            break;
                        }
                        default: {
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto math_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                    //�����ϼ��˵�
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                    //���벻�Ϸ�
                default:{
                    printf("���벻�Ϸ������������룡\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto math_statistic;
                    //break;
                }
            }
            break;
        }
        //ͳ��Ӣ��ɼ�
        case '3':{
            english_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
            printf("->��ǰλ�ã�Ӣ��ɼ�ͳ��\n\n");
            printf("->1���������ѯ\n");
            printf("->2���������ѯ\n");
            printf("->3���������β�ѯ\n");
            printf("->4�������ϼ��˵�\n");

            //��ȡ�û����룬�ж�ִ�з���
            char english_menu_input;
            printf("\n->������ѡ�1/2/3/4��");
            fflush(stdin);
            scanf("%c",&english_menu_input);
            switch (english_menu_input) {
                //�������ѯ
                case '1':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->english<p->english)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->Ӣ��ƽ����Ϊ��%.2f\n\n",english_av());

                    english_statistic_re1:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto english_statistic_re1;
                            //break;
                        }
                    }
                    break;
                }


                    //�������ѯ
                case '2':{
                    //����������
                    p=head->next;
                    r=p->next;
                    p->next=NULL;
                    p=r;

                    while(p!=NULL)
                    {
                        r=p->next;
                        q=head;
                        while(q->next!=NULL&&q->next->english>p->english)
                        {
                            q=q->next;
                        }
                        p->next=q->next;
                        q->next=p;
                        p=r;
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->Ӣ��ƽ����Ϊ��%.2f\n\n",english_av());

                    english_statistic_re2:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y':{
                            goto continue_statistic;
                            //break;
                        }
                        case 'n':{
                            secondary_menu();
                            break;
                        }
                        default:{
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto english_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //�������β�ѯ
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    english_query_by_fractional_segment:
                    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n");
                    printf("->��ǰλ�ã��ɼ������β�ѯ\n\n");
                    printf("->������Ҫ��ѯ��Ӣ��ɼ�������:\n");
                    printf("->��ͷ֣�");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->��߷֣�");
                    fflush(stdin);
                    scanf("%f",&max);

                    //����û�����������Ƿ�Ϸ�
                    if(min>max){
                        printf("���벻�Ϸ������������룡\n\n");
                        fflush(stdin);
                        goto english_query_by_fractional_segment;
                    }
                    else{
                        q=head;
                        p=head->next;
                        while (p!=NULL){
                            if(p->english<min||p->english>max){
                                r=p;
                                p=p->next;
                                q->next=p;
                                free(r);
                            }
                            else{
                                p=p->next;
                                q=q->next;
                            }
                        }
                    }

                    //��������Ľ��
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------ѧ����Ϣ����ϵͳ-------------------------------------------------\n");
                    printf("->��ǰλ�ã�ѧ����Ϣ��ѯ\n\n");
                    printf("ѧ��                 ����                 �Ա�       ����       ���ĳɼ�             ��ѧ�ɼ�             Ӣ��ɼ�\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->Ӣ��ƽ����Ϊ��%.2f\n\n",english_av());

                    english_query_by_fractional_segment_re:
                    //��ȡ�û����룬�ж�ִ�з���
                    printf("->�Ƿ������ѯ����y/n��");
                    fflush(stdin);
                    scanf("%c",&statistic_menu_input);
                    switch (statistic_menu_input) {
                        case 'y': {
                            goto continue_statistic;
                            //break;
                        }
                        case 'n': {
                            secondary_menu();
                            break;
                        }
                        default: {
                            printf("���벻�Ϸ������������룡\n\n");
                            fflush(stdin);
                            goto english_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                    //�����ϼ��˵�
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                    //���벻�Ϸ�
                default:{
                    printf("���벻�Ϸ������������룡\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto math_statistic;
                    //break;
                }
            }
            break;
        }
        //�����ϼ��˵�
        case '4':{
            secondary_menu();
            break;
        }
        //���벻�Ϸ�
        default:{
            printf("���벻�Ϸ������������룡\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_statistic;
        }
    }
}


float chinese_av(){
    float chinese_sum=0,chinese_av;

    //��ѧ����Ϣ�����ڴ�
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t,*r;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int info_num=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        chinese_sum+=p->chinese;
        info_num+=1;
        p->prev=q;
        q->next=p;
        q=p;
    }
    fclose(fp);
    //���ݱ�����һ��Ϊ���У�������������һ���ڵ�Ϊ��
    p->prev->next=NULL;
    //��¼��
    info_num=info_num-1;
    chinese_av=chinese_sum/info_num;
    return chinese_av;
}

float math_av(){
    float math_sum=0,math_av;

    //��ѧ����Ϣ�����ڴ�
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t,*r;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int info_num=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        math_sum+=p->math;
        info_num+=1;
        p->prev=q;
        q->next=p;
        q=p;
    }
    fclose(fp);
    //���ݱ�����һ��Ϊ���У�������������һ���ڵ�Ϊ��
    p->prev->next=NULL;
    //��¼��
    info_num=info_num-1;
    math_av=math_sum/info_num;
    return math_av;
}

float english_av(){
    float english_sum=0,english_av;

    //��ѧ����Ϣ�����ڴ�
    FILE *fp=fopen("../stu_info/stu_info.txt","r");
    struct stu *head,*p,*q,*t,*r;
    head=(struct stu *) malloc(sizeof(struct stu));
    head->prev=NULL;
    q=head;
    int info_num=0;
    while (!feof(fp)){
        p=(struct stu *) malloc(sizeof(struct stu));
        fscanf(fp,"%s %s %s %d %f %f %f",&p->stu_num,&p->name,&p->gender,&p->age,&p->chinese,&p->math,&p->english);
        english_sum+=p->english;
        info_num+=1;
        p->prev=q;
        q->next=p;
        q=p;
    }
    fclose(fp);
    //���ݱ�����һ��Ϊ���У�������������һ���ڵ�Ϊ��
    p->prev->next=NULL;
    //��¼��
    info_num=info_num-1;
    english_av=english_sum/info_num;
    return english_av;
}