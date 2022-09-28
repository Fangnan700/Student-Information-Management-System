#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"

void modify_module(){
    char stu_num[20];
    char name[20];

    continue_modify:
    //学生信息修改菜单界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n");
    printf("->当前位置：学生信息修改\n\n");
    printf("->1、按学号查询并修改\n");
    printf("->2、按姓名查询并修改\n");
    printf("->3、返回上级菜单\n");

    //把学生信息读入内存
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
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->next=NULL;

    //读取用户输入，判断执行方向
    char modify_menu_input;
    printf("\n->请输入选项（1/2/3）");
    fflush(stdin);
    scanf("%c",&modify_menu_input);
    switch (modify_menu_input) {
        //按学号查询并删除
        case '1':{
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：学生信息修改\n\n");
            printf("->请输入学生学号：");
            scanf("%s",&stu_num);
            t=head->next;

            t=head->next;
            int whether_find=0;
            while (t!=NULL){
                if(strcmp(stu_num,t->stu_num)==0){
                    whether_find=1;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息修改\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    printf("请输入修改后的学生学号：");
                    fflush(stdin);
                    scanf("%s",&t->stu_num);
                    printf("请输入修改后的学生姓名：");
                    fflush(stdin);
                    scanf("%s",&t->name);
                    printf("请输入修改后的学生性别：");
                    fflush(stdin);
                    scanf("%s",&t->gender);
                    printf("请输入修改后的学生年龄：");
                    fflush(stdin);
                    scanf("%d",&t->age);
                    printf("请输入修改后的语文成绩：");
                    fflush(stdin);
                    scanf("%f",&t->chinese);
                    printf("请输入修改后的数学成绩：");
                    fflush(stdin);
                    scanf("%f",&t->math);
                    printf("请输入修改后的英语成绩：");
                    fflush(stdin);
                    scanf("%f",&t->english);
                }
                t=t->next;
            }
            if(whether_find==0){
                printf("未查询到该学生的信息！\n");
                Sleep(2000);
                goto continue_modify;
            }
            else{
                //把修改后的信息写入文件
                t=head->next;
                fp= fopen("../stu_info/stu_info.txt","w");

                for (int i = 1; i < count; i++) {
                    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    t=t->next;
                }
                printf("修改成功！\n");
                Sleep(2000);
                modify_menu_re1:
                printf("是否继续修改？（y/n）");
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
                        printf("输入不合法，请重新输入！\n\n");
                        fflush(stdin);
                        Sleep(2000);
                        goto modify_menu_re1;
                    }
                }
            }
            break;
        }

        //按姓名查询并删除
        case '2':{
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：学生信息修改\n\n");
            printf("->请输入学生姓名：");
            scanf("%s",&name);

            t=head->next;
            int whether_find=0;
            while (t!=NULL){
                if(strcmp(name,t->name)==0){
                    whether_find=1;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息修改\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    printf("请输入修改后的学生学号：");
                    fflush(stdin);
                    scanf("%s",&t->stu_num);
                    printf("请输入修改后的学生姓名：");
                    fflush(stdin);
                    scanf("%s",&t->name);
                    printf("请输入修改后的学生性别：");
                    fflush(stdin);
                    scanf("%s",&t->gender);
                    printf("请输入修改后的学生年龄：");
                    fflush(stdin);
                    scanf("%d",&t->age);
                    printf("请输入修改后的语文成绩：");
                    fflush(stdin);
                    scanf("%f",&t->chinese);
                    printf("请输入修改后的数学成绩：");
                    fflush(stdin);
                    scanf("%f",&t->math);
                    printf("请输入修改后的英语成绩：");
                    fflush(stdin);
                    scanf("%f",&t->english);
                }
                t=t->next;
            }
            if(whether_find==0){
                printf("未查询到该学生的信息！\n");
                Sleep(2000);
                goto continue_modify;
            }
            else{
                //把修改后的信息写入文件
                t=head->next;
                fp= fopen("../stu_info/stu_info.txt","w");

                for (int i = 1; i < count; i++) {
                    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                    t=t->next;
                }
                printf("修改成功！\n");
                Sleep(2000);
                modify_menu_re2:
                printf("是否继续修改？（y/n）");
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
                        printf("输入不合法，请重新输入！\n\n");
                        fflush(stdin);
                        Sleep(2000);
                        goto modify_menu_re2;
                    }
                }
            }
            break;
        }

        //返回上级菜单
        case '3':{
            secondary_menu();
            break;
        }

        default: {
            printf("输入不合法，请重新输入！\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_modify;
        }
    }

}