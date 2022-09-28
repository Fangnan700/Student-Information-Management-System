#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "../heads/for_function_module.h"
#include "../heads/users.h"

void registered_module() {
    re_registered:
    //注册界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n\n");
    printf("->当前位置：注册\n\n");

    char account[20];
    char password1[20];
    char password2[20];
    printf("->请输入账号：");
    fflush(stdin);
    scanf("%s",&account);

    //检测用户名是否已经存在
    struct user *head,*p,*q;
    head=(struct user *) malloc(sizeof(struct user));
    q=head;

    //检索账号文件，读入内存
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

    //判断账号是否存在
    p=head->next;
    while (p!=NULL){
        //账号存在
        if(strcmp(account,p->account)==0){
            printf("账号已经存在，请换另一个账号！\n\n");
            Sleep(2000);
            goto re_registered;
        }
        p=p->next;
    }

    //账号不存在
    printf("请输入密码：");
    scanf("%s",&password1);
    printf("请确认密码：");
    scanf("%s",&password2);

    //判断两次输入的密码是否一致
    if(strcmp(password1,password2)==0){
        FILE *fp;
        fp = fopen("../users/users.txt", "a");
        fprintf(fp,"%-20s %-20s",account,password1);
        fclose(fp);
        printf("注册成功！\n");
        Sleep(2000);
        main();
    }
    else{
        printf("两次输入的密码不一致，请重试！\n\n");
        Sleep(2000);
        goto re_registered;
    }
}
