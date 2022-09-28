struct stu{
    char stu_num[20];
    char name[20];
    char gender[10];
    int age;
    float chinese,math,english;
    struct stu *prev,*next;
};
