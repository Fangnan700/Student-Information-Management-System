#include "../heads/for_function_module.h"
#include "../heads/secondary_menu.h"
#include "stdio.h"
#include "windows.h"

void statistic_module(){

    float chinese_av();
    float math_av();
    float english_av();

    continue_statistic:
    //成绩统计菜单界面
    system("cls");
    fflush(stdin);
    printf("------------------------------学生信息管理系统------------------------------\n");
    printf("->当前位置：学生成绩统计\n\n");
    printf("->1、语文成绩统计\n");
    printf("->2、数学成绩统计\n");
    printf("->3、英语成绩统计\n");
    printf("->4、返回上级菜单\n");

    //把学生信息读入内存
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
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->prev->next=NULL;
    //记录数
    info_num=info_num-1;



    //读取用户输入，判断执行方向
    char statistic_menu_input;
    printf("\n->请输入选项（1/2/3/4）");
    fflush(stdin);
    scanf("%c",&statistic_menu_input);
    switch (statistic_menu_input) {
        //统计语文成绩
        case '1':{
            chinese_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：语文成绩统计\n\n");
            printf("->1、按升序查询\n");
            printf("->2、按降序查询\n");
            printf("->3、按分数段查询\n");
            printf("->4、返回上级菜单\n");

            //读取用户输入，判断执行方向
            char chinese_menu_input;
            printf("\n->请输入选项（1/2/3/4）");
            fflush(stdin);
            scanf("%c",&chinese_menu_input);
            switch (chinese_menu_input) {
                //按升序查询
                case '1':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->语文平均分为：%.2f\n\n",chinese_av());

                    chinese_statistic_re1:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto chinese_statistic_re1;
                            //break;
                        }
                    }
                    //break;
                }


                //按降序查询
                case '2':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->语文平均分为：%.2f\n\n",chinese_av());

                    chinese_statistic_re2:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto chinese_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //按分数段查询
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    chinese_query_by_fractional_segment:
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：语文成绩分数段查询\n\n");
                    printf("->请输入要查询的语文成绩分数段:\n");
                    printf("->最低分：");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->最高分：");
                    fflush(stdin);
                    scanf("%f",&max);

                    //检测用户输入的数据是否合法
                    if(min>max){
                        printf("输入不合法，请重新输入！\n\n");
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->语文平均分为：%.2f\n\n",chinese_av());

                    chinese_query_by_fractional_segment_re:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto chinese_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                //返回上级菜单
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                //输入不合法
                default:{
                    printf("输入不合法，请重新输入！\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto chinese_statistic;
                    //break;
                }
            }
        }
        //统计数学成绩
        case '2':{
            math_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：数学成绩统计\n\n");
            printf("->1、按升序查询\n");
            printf("->2、按降序查询\n");
            printf("->3、按分数段查询\n");
            printf("->4、返回上级菜单\n");

            //读取用户输入，判断执行方向
            char math_menu_input;
            printf("\n->请输入选项（1/2/3/4）");
            fflush(stdin);
            scanf("%c",&math_menu_input);
            switch (math_menu_input) {
                //按升序查询
                case '1':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->数学平均分为：%.2f\n\n",math_av());

                    math_statistic_re1:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto math_statistic_re1;
                            //break;
                        }
                    }
                    break;
                }


                //按降序查询
                case '2':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->数学平均分为：%.2f\n\n",math_av());

                    math_statistic_re2:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto math_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //按分数段查询
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    math_query_by_fractional_segment:
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：成绩分数段查询\n\n");
                    printf("->请输入要查询的数学成绩分数段:\n");
                    printf("->最低分：");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->最高分：");
                    fflush(stdin);
                    scanf("%f",&max);

                    //检测用户输入的数据是否合法
                    if(min>max){
                        printf("输入不合法，请重新输入！\n\n");
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->数学平均分为：%.2f\n\n",math_av());

                    math_query_by_fractional_segment_re:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto math_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                    //返回上级菜单
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                    //输入不合法
                default:{
                    printf("输入不合法，请重新输入！\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto math_statistic;
                    //break;
                }
            }
            break;
        }
        //统计英语成绩
        case '3':{
            english_statistic:
            system("cls");
            fflush(stdin);
            printf("------------------------------学生信息管理系统------------------------------\n");
            printf("->当前位置：英语成绩统计\n\n");
            printf("->1、按升序查询\n");
            printf("->2、按降序查询\n");
            printf("->3、按分数段查询\n");
            printf("->4、返回上级菜单\n");

            //读取用户输入，判断执行方向
            char english_menu_input;
            printf("\n->请输入选项（1/2/3/4）");
            fflush(stdin);
            scanf("%c",&english_menu_input);
            switch (english_menu_input) {
                //按升序查询
                case '1':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->英语平均分为：%.2f\n\n",english_av());

                    english_statistic_re1:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto english_statistic_re1;
                            //break;
                        }
                    }
                    break;
                }


                    //按降序查询
                case '2':{
                    //对链表排序
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->英语平均分为：%.2f\n\n",english_av());

                    english_statistic_re2:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto english_statistic_re2;
                            //break;
                        }
                    }
                    break;
                }


                //按分数段查询
                case '3':{
                    system("cls");
                    fflush(stdin);
                    float min,max;
                    english_query_by_fractional_segment:
                    printf("------------------------------学生信息管理系统------------------------------\n");
                    printf("->当前位置：成绩分数段查询\n\n");
                    printf("->请输入要查询的英语成绩分数段:\n");
                    printf("->最低分：");
                    fflush(stdin);
                    scanf("%f",&min);
                    printf("->最高分：");
                    fflush(stdin);
                    scanf("%f",&max);

                    //检测用户输入的数据是否合法
                    if(min>max){
                        printf("输入不合法，请重新输入！\n\n");
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

                    //输出排序后的结果
                    t=head->next;
                    system("cls");
                    fflush(stdin);
                    printf("-------------------------------------------------学生信息管理系统-------------------------------------------------\n");
                    printf("->当前位置：学生信息查询\n\n");
                    printf("学号                 姓名                 性别       年龄       语文成绩             数学成绩             英语成绩\n\n");
                    while (t!=NULL){
                        printf("%-20s %-20s %-10s %-10d %-20.2f %-20.2f %-20.2f\n",t->stu_num,t->name,t->gender,t->age,t->chinese,t->math,t->english);
                        t=t->next;
                    }

                    printf("\n");
                    printf("->英语平均分为：%.2f\n\n",english_av());

                    english_query_by_fractional_segment_re:
                    //读取用户输入，判断执行方向
                    printf("->是否继续查询？（y/n）");
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
                            printf("输入不合法，请重新输入！\n\n");
                            fflush(stdin);
                            goto english_query_by_fractional_segment_re;
                            //break;
                        }
                    }
                    break;
                }
                    //返回上级菜单
                case '4':{
                    goto continue_statistic;
                    //break;
                }
                    //输入不合法
                default:{
                    printf("输入不合法，请重新输入！\n\n");
                    fflush(stdin);
                    Sleep(2000);
                    goto math_statistic;
                    //break;
                }
            }
            break;
        }
        //返回上级菜单
        case '4':{
            secondary_menu();
            break;
        }
        //输入不合法
        default:{
            printf("输入不合法，请重新输入！\n\n");
            fflush(stdin);
            Sleep(2000);
            goto continue_statistic;
        }
    }
}


float chinese_av(){
    float chinese_sum=0,chinese_av;

    //把学生信息读入内存
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
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->prev->next=NULL;
    //记录数
    info_num=info_num-1;
    chinese_av=chinese_sum/info_num;
    return chinese_av;
}

float math_av(){
    float math_sum=0,math_av;

    //把学生信息读入内存
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
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->prev->next=NULL;
    //记录数
    info_num=info_num-1;
    math_av=math_sum/info_num;
    return math_av;
}

float english_av(){
    float english_sum=0,english_av;

    //把学生信息读入内存
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
    //数据表的最后一行为空行，导致链表的最后一个节点为空
    p->prev->next=NULL;
    //记录数
    info_num=info_num-1;
    english_av=english_sum/info_num;
    return english_av;
}