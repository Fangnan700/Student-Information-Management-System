#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"


void add_module(){
    continue_add:
    //二级菜单界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n");
    printf("->当前位置：添加学生信息\n");

    char stu_num[20];
    char name[20];
    char gender[10];
    int age;
    float chinese,math,english;

    //读取用户输入的学生信息并写入文件
    printf("->请输入学生学号：");
    scanf("%s",&stu_num);
    printf("->请输入学生姓名：");
    scanf("%s",&name);
    printf("->请输入学生性别：");
    scanf("%s",&gender);
    printf("->请输入学生年龄：");
    scanf("%d",&age);
    printf("->请输入学生的语文成绩：");
    scanf("%f",&chinese);
    printf("->请输入学生的数学成绩：");
    scanf("%f",&math);
    printf("->请输入学生的英语成绩：");
    scanf("%f",&english);

    FILE *fp= fopen("../stu_info/stu_info.txt","a");
    fprintf(fp,"%-20s %-20s %-20s %-20d %-20f %-20f %-20f\n",stu_num,name,gender,age,chinese,math,english);
    fclose(fp);
    printf("\n->学生信息添加成功！\n\n");
    Sleep(2000);

    re_input_add_menu_choice:
    //询问用户下一步操作
    printf("->是否需要继续添加学生信息？（y/n）");
    char whether_continue_add;
    fflush(stdin);
    scanf("%c",&whether_continue_add);
    switch (whether_continue_add) {
        //继续添加
        case 'y':{
            goto continue_add;
            break;
        }
        //不继续添加
        case 'n':{
            secondary_menu();
            break;
        }
        //输入不合法
        default:{
            printf("->输入不合法，请重新输入！\n\n");
            fflush(stdin);
            goto re_input_add_menu_choice;
            break;
        }
    }
}