#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "stdlib.h"
#include "../heads/for_function_module.h"
#include "../heads/users.h"
#include "../heads/secondary_menu.h"
#include "../heads/registered_module.h"

void login_module(){
    //��¼����
    system("cls");
    fflush(stdin);
    printf("------------------------------ѧ����Ϣ����ϵͳ------------------------------\n\n");
    printf("-> ��ǰλ�ã���¼\n\n");
    printf("-> �������˺ţ�");

    //��ȡ�û�������˺�
    char account_input[20];
    fflush(stdin);
    scanf("%s",&account_input);

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
    int account_exist=0;
    p=head->next;
    while (p!=NULL){
        //�˺Ŵ���
        if(strcmp(account_input,p->account)==0){
            //��ȡ�û����������
            char password[20];
            int password_input_count=0;
            re_input_password:
            printf("-> ���������룺");
            fflush(stdin);
            scanf("%s",&password);
            //������ȷ
            if(strcmp(password,p->password)==0){
                //��ת�������˵�
                account_exist=1;
                secondary_menu();
                break;
            }
            //�������
            else{
                password_input_count++;
                if(password_input_count<3){
                    printf("->������������ԣ�\n");
                    fflush(stdin);
                    goto re_input_password;
                }
                else{
                    printf("->�������������࣬���Ժ����ԡ�\n");
                    fflush(stdin);
                    Sleep(2000);
                    main();
                }
            }
        }
        p=p->next;
    }
    //�˺Ų�����
    if(account_exist!=1){
        re_input_whether_registered:
        printf("->�˺Ų����ڣ��Ƿ�����ע�᣿��y/n��");
        char whether_registered;
        fflush(stdin);
        scanf("%c",&whether_registered);
        switch (whether_registered) {
            //��ת��ע��ģ��
            case 'y':{
                registered_module();
                break;
            }
                //�������˵�
            case 'n':{
                main();
            }
                //���벻�Ϸ�
            default:{
                printf("->���벻�Ϸ������������룡\n");
                fflush(stdin);
                goto re_input_whether_registered;
            }
        }
    }
}