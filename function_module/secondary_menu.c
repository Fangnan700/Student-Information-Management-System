#include "../heads/for_function_module.h"
#include "../heads/add_module.h"
#include "../heads/query_module.h"
#include "../heads/delete_module.h"
#include "../heads/statistic_module.h"
#include "../heads/modify_module.h"
#include "stdio.h"
#include "windows.h"

void secondary_menu(){
    //二级菜单界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n\n");
    printf("->当前位置：学生信息管理\n\n");
    printf("-> 1、添加学生信息\n");
    printf("-> 2、查询学生信息\n");
    printf("-> 3、修改学生信息\n");
    printf("-> 4、删除学生信息\n");
    printf("-> 5、成绩统计\n");
    printf("-> 6、返回主菜单\n");

    //读取用户输入，判断执行方向
    char secondary_menu_input;
    re_input_secondary_menu_choice:
    printf("\n->请输入选项（1/2/3/4/5/6）");
    fflush(stdin);
    scanf("%c",&secondary_menu_input);
    switch (secondary_menu_input) {
        //添加学生信息
        case '1':{
            add_module();
            break;
        }
        //查询学生信息
        case '2':{
            query_module();
            break;
        }
        //修改学生信息
        case '3':{
            modify_module();
            break;
        }
        //删除学生信息
        case '4':{
            delete_module();
            break;
        }
        //成绩统计
        case '5':{
            statistic_module();
            break;
        }
        //返回主菜单
        case '6':{
            main();
        }
        //输入不合法
        default:{
            printf("输入不合法，请重新输入！\n\n");
            fflush(stdin);
            goto re_input_secondary_menu_choice;
        }
    }
}