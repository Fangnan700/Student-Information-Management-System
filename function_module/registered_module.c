#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "../heads/for_function_module.h"
#include "../heads/users.h"

void registered_module() {
    re_registered:
    //ע�����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n\n");
    printf("->��ǰλ�ã�ע��\n\n");

    char account[20];
    char password1[20];
    char password2[20];
    printf("->�������˺ţ�");
    fflush(stdin);
    scanf("%s",&account);

    //����û����Ƿ��Ѿ�����
    struct user *head,*p,*q;
    head=(struct user *) malloc(sizeof(struct user));
    q=head;

    //�����˺��ļ��������ڴ�
    FILE *fp;
    fp = fopen("../users/users.txt", "r");
    while (!feof(fp)){
        p=(struct user *)malloc(sizeof(struct user));
        fscanf(fp,"%s %s",&p->account,&p->password);
        q->next=p;
        q=p;
    }
    fclose(fp);
    p->next=NULL;

    //�ж��˺��Ƿ����
    p=head->next;
    while (p!=NULL){
        //�˺Ŵ���
        if(strcmp(account,p->account)==0){
            printf("�˺��Ѿ����ڣ��뻻��һ���˺ţ�\n\n");
            Sleep(2000);
            goto re_registered;
        }
        p=p->next;
    }

    //�˺Ų�����
    printf("���������룺");
    scanf("%s",&password1);
    printf("��ȷ�����룺");
    scanf("%s",&password2);

    //�ж���������������Ƿ�һ��
    if(strcmp(password1,password2)==0){
        FILE *fp;
        fp = fopen("../users/users.txt", "a");
        fprintf(fp,"%-20s %-20s",account,password1);
        fclose(fp);
        printf("ע��ɹ���\n");
        Sleep(2000);
        main();
    }
    else{
        printf("������������벻һ�£������ԣ�\n\n");
        Sleep(2000);
        goto re_registered;
    }
}
