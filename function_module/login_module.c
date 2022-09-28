#include "stdio.h"
#include "string.h"
#include "windows.h"
#include "stdlib.h"
#include "../heads/for_function_module.h"
#include "../heads/users.h"
#include "../heads/secondary_menu.h"
#include "../heads/registered_module.h"

void login_module(){
    //登录界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n\n");
    printf("-> 当前位置：登录\n\n");
    printf("-> 请输入账号：");

    //读取用户输入的账号
    char account_input[20];
    fflush(stdin);
    scanf("%s",&account_input);

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
    int account_exist=0;
    p=head->next;
    while (p!=NULL){
        //账号存在
        if(strcmp(account_input,p->account)==0){
            //读取用户输入的密码
            char password[20];
            int password_input_count=0;
            re_input_password:
            printf("-> 请输入密码：");
            fflush(stdin);
            scanf("%s",&password);
            //密码正确
            if(strcmp(password,p->password)==0){
                //跳转到二级菜单
                account_exist=1;
                secondary_menu();
                break;
            }
            //密码错误
            else{
                password_input_count++;
                if(password_input_count<3){
                    printf("->密码错误！请重试！\n");
                    fflush(stdin);
                    goto re_input_password;
                }
                else{
                    printf("->密码错误次数过多，请稍后再试。\n");
                    fflush(stdin);
                    Sleep(2000);
                    main();
                }
            }
        }
        p=p->next;
    }
    //账号不存在
    if(account_exist!=1){
        re_input_whether_registered:
        printf("->账号不存在，是否现在注册？（y/n）");
        char whether_registered;
        fflush(stdin);
        scanf("%c",&whether_registered);
        switch (whether_registered) {
            //跳转到注册模块
            case 'y':{
                registered_module();
                break;
            }
                //返回主菜单
            case 'n':{
                main();
            }
                //输入不合法
            default:{
                printf("->输入不合法，请重新输入！\n");
                fflush(stdin);
                goto re_input_whether_registered;
            }
        }
    }
}