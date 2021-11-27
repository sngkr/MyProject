#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#define R sizeof(struct READER)

struct READER {
  char number[50];
  char name[50];
  char gender;
  char school[100];
  int root;
  int x;
  struct READER *next;
};
typedef struct READER Reader;
typedef Reader *reader;

void HideCursor();  //隐藏光标

void toxy(short x, short y);  //将光标移动到X,Y坐标处
void color(short x);          //设置颜色

void over();  //退出

void menu();  //菜单

void input_reader();  //图书入库
void save_reader(reader);
void find_reader();
void print_reader();
void lost_reader();
void amend_reader();
reader ss();

void FindReader_Name();
void FindReader_Code();

void HideCursor();  //隐藏光标

void HideCursor() {
  CONSOLE_CURSOR_INFO cursor_info = {1, 0};
  SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &cursor_info);
}

void color(short x) {
  if (x >= 0 && x <= 15) {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
  } else {
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), x);
  }
}
void toxy(short x, short y) {
  COORD pos = {x, y};
  HANDLE Out = GetStdHandle(STD_OUTPUT_HANDLE);
  SetConsoleCursorPosition(Out, pos);
}

void menu()  //菜单
{
  do {
    system("cls");  //清屏
    // HideCursor();   //隐藏光标
    color(15);  //设置一个好看的颜色
    char t;
    toxy(50, 5);  //将光标移动到（50，5）坐标处
    printf(" 读者管理系统");
    toxy(48, 8);

    printf("| 1.浏览所有读者 |");

    toxy(48, 10);

    printf("| 2.增加读者 |");

    toxy(48, 12);

    printf("| 3.查询读者 |");

    toxy(48, 14);

    printf("| 4.修改读者 |");

    toxy(48, 16);

    printf("| 5.证件挂失 |");

    toxy(48, 18);

    printf("| 0.返回上一级 |");

    t = getch();  //不回显函数

    switch (t)

    {
      case '1':
        print_reader();
        break;

      case '2':
        input_reader();
        break;

      case '3':
        find_reader();
        break;

      case '4':
        amend_reader();
        break;

      case '5':
        // print_book();
        lost_reader();
        break;

        // case '0':
        //   over();
        //   break;

      default:
        break;
    }
  } while (1);
}

void input_reader() {
  do {
    system("cls");
    color(10);
    char t;
    reader p;
    p = (reader)malloc(R);  //申请空间
    toxy(48, 8);
    printf("请输入读者号(<13)：");
    scanf("%s", p->number);
    getchar();

    toxy(48, 10);

    printf("请输入读者名：");
    scanf("%s", p->name);
    getchar();

    toxy(48, 12);

    printf("请输入读者性别（F/M）：");
    scanf("%c", &p->gender);
    getchar();

    toxy(48, 14);

    printf("请输入读者所属学院：");
    scanf("%s", p->school);
    getchar();

    toxy(48, 16);

    printf("请输入读者权限（0,1）：");
    scanf("%d", &p->root);
    getchar();

    toxy(48, 18);

    save_reader(p);

    toxy(48, 24);
    while (1) {
      toxy(48, 30);

      printf("按任意键enter键开始修改");
      if (getchar()) break;
    }
    printf("正在保存....");

    Sleep(500);  //暂停0.5秒

    system("cls");

    toxy(46, 8);

    printf("-------------------------");

    toxy(46, 9);

    printf("| |");

    toxy(46, 10);

    printf("| 保存成功！是否继续？ |");

    toxy(46, 12);

    printf("| 1.是 2.否 |");

    toxy(46, 13);

    printf("| |");

    toxy(46, 14);

    printf("-------------------------");
    while (1) {
      t = getch();
      if (t == '1') {
        break;
      } else if (t == '2') {
        menu();
      }
    }

  } while (1);
}

void save_reader(reader p) {
  FILE *fp;  //文件指针

  fp = fopen("mybook", "ab");  //以追加的方式打开名字为mybook的二进制文件
  if (fp == NULL) {
    printf("cannot open file");
  }

  if (fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender, p->school,
              p->root) != 0) {
    printf("write ok");
  }
  fclose(fp);  //关闭文件
}

void print_reader() {
  system("cls");
  color(6);
  reader head, p;
  int i = 11;
  int sum = 0;

  head = ss();

  printf("学号 姓名 性别 学院 权限\n");

  if (head == NULL) {
    // toxy(45, 11);
    printf("无信息\n");
    getch();
    menu();
  }

  p = head;

  while (p != NULL) {
    // toxy(20, i);
    printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender, p->school,
           p->root);
    i++;
    p = p->next;
  }
  printf("按任意键返回\n");
  getch();  //不回显函数
}

void find_reader() {
  do

  {
    system("cls");  //清屏

    color(8);

    char t;

    toxy(50, 5);

    printf(" 读者查询");

    toxy(48, 8);

    printf("| 1.学号 查询 |");

    toxy(48, 10);

    printf("| 2.姓名 查询 |");

    toxy(48, 12);

    printf("按0返回主菜单");

    t = getch();

    switch (t) {
      case '0':
        menu();
        break;

      case '1':
        FindReader_Code();
        break;

      case '2':
        FindReader_Name();
        break;

      default:
        break;
    }

  } while (1);
}

void FindReader_Code() {
  system("cls");
  color(8);
  reader head, p;
  int i = 11;
  head = ss();
  char number[12];

  toxy(48, 8);
  printf("请输入您要查询的读者学号：");
  gets(number);
  toxy(48, 10);
  printf("正在查询....");
  Sleep(500);
  p = head;
  toxy(20, 10);

  while (p != NULL) {
    if (p != NULL && strcmp(p->number, number) == 0) {
      toxy(20, i);

      printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender,
             p->school, p->root);
      i++;
    }
    p = p->next;
  }

  toxy(45, i);
  printf("按任意键返回！");
  getch();
  find_reader();
}
void FindReader_Name() {
  system("cls");
  color(8);
  reader head, p;
  int i = 11;
  head = ss();
  char name[10];

  toxy(48, 8);
  printf("请输入您要查询的读者名：");
  gets(name);
  toxy(48, 10);
  printf("正在查询....");
  Sleep(500);
  p = head;
  toxy(20, 10);
  while (p != NULL) {
    if (p != NULL && strcmp(p->name, name) == 0) {
      toxy(20, i);

      printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender,
             p->school, p->root);
      i++;
    }

    p = p->next;
  }

  toxy(45, i);
  printf("按任意键返回！");
  getch();
  find_reader();
}

reader ss() {
  FILE *fp;  //文件指针
  int n = 0;
  reader head = NULL;
  reader p2, p, pr = NULL;

  fp = fopen("mybook", "ab+");  //以只读的方式打开文件

  if (fp == NULL) {
    printf("cannot open file\n");
  }

  while (!feof(fp))  //判断文件位置标志是否移动到文件末尾
  {
    n++;
    p = (reader)malloc(R);  //向内存申请一段空间

    // fread(p, R, 1, fp);  //将fp所指向的文件中的内容赋给
    fscanf(fp, "%s %s %c %s %d", p->number, p->name, &p->gender, p->school,
           &p->root);
    if (n == 1) {
      head = p;
      p2 = p;
    } else {
      pr = p2;
      p2->next = p;
      p2 = p;
    }
  }
  if (pr != NULL)
    pr->next = NULL;
  else
    head = NULL;
  fclose(fp);   //关闭文件
  return head;  //返回头指针
}
void amend_reader() {
  do {
    system("cls");

    color(10);

    reader head, p;

    int i = 11, j = 0, x;

    char ch, t;

    FILE *fp;  //文件指针

    char _name[12];
    char number[12];
    char name[10];
    char gender;
    char school[30];
    int root;

    head = ss();
    p = head;
    toxy(48, 10);

    printf("请输入你要修改读者学号：");
    gets(_name);

    while (p != NULL) {
      p->x = 0;
      p = p->next;
    }

    p = head;  //让p重新指向表头

    toxy(20, 5);

    printf(
        "***********************************************读者信息***************"
        "***************************************");

    toxy(20, 8);

    printf(
        "----------------------------------------------------------------------"
        "---------------------------------------");

    toxy(20, 9);

    printf("学号 姓名 性别 学院 权限");

    toxy(20, 10);

    printf(
        "----------------------------------------------------------------------"
        "---------------------------------------");

    while (p != NULL) {
      if (p != NULL && strcmp(p->number, _name) == 0) {
        toxy(20, i);

        j++;
        printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender,
               p->school, p->root);
        p->x = j;  //给符合查询标准的结点标号
        i++;
      }

      p = p->next;
    }

    if (j == 0)  //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息
    {
      toxy(50, i);

      printf("没有找到相应的信息！(按0返回，按1重新搜索)");

      while (1)  //死循环是为了防止除0和1的其他按键干扰
      {
        ch = getch();
        if (ch == '0') {
          menu();
          break;
        } else if (ch == '1') {
          break;
        }
      }
      if (ch == '1')  //如果输入的ch等于1，则结束本次循环

        continue;
    }

    while (1) {
      toxy(45, i);

      printf("按任意键enter键开始修改");
      if (getchar()) break;
    }

    p = head;  //让p重新指向表头

    while (p != NULL && p->x != j)  //遍历链表查询符合条件的结点
    {
      p = p->next;
    }

    if (p)  //如果p不为空
    {
      system("cls");
      //输入要修改的信息
      toxy(48, 8);
      printf("请输入学号：");

      scanf("%s", number);
      getchar();
      strcpy(p->number, number);

      toxy(48, 10);

      printf("请输入读者名：");

      scanf("%s", name);
      getchar();
      strcpy(p->name, name);

      toxy(48, 12);

      printf("请输入性别：");

      scanf("%c", &gender);
      getchar();
      p->gender = gender;

      toxy(48, 14);

      printf("请输入学院：");

      scanf("%s", school);
      getchar();
      strcpy(p->school, school);

      toxy(48, 16);

      printf("请输入权限");

      scanf("%d", &root);
      getchar();
      p->root = root;
    }

    color(7);
    toxy(46, 8);

    printf("-------------------------");
    toxy(46, 9);

    printf("| |");

    toxy(46, 10);

    printf("| 是否确认修改？ |");

    toxy(46, 12);

    printf("| 1.是 2.否 |");

    toxy(46, 13);

    printf("| |");

    toxy(46, 14);

    printf("-------------------------");

    while (1)  //利用死循环防止其他按键干扰
    {
      t = getch();

      if (t == '1') {
        break;

      } else if (t == '2') {
        menu();
      }
    }

    system("cls");

    toxy(46, 10);

    printf("正在修改，请稍后....");

    fp = fopen(
        "mybook",
        "wb");  //以只写的方式打开名为mybook的二进制文件，打开的同时清空文件中的内容

    if (fp == NULL) {
      printf("cannot open file");
      fprintf(fp, "%s %s %c %s %d\n", head->number, head->name, head->gender,
              head->school, head->root);
    }

    fclose(fp);  //关闭文件

    if (head != NULL)  //如果head不为空
    {
      p = head->next;  //让p指向第二个结点

      fp = fopen("mybook", "ab");  //以追加的方式打开文件

      if (fp == NULL)

      {
        printf("cannot open file");
      }

      while (p != NULL) {
        fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender,
                p->school, p->root);
        p = p->next;
      }

      fclose(fp);  //关闭文件
    }
    Sleep(500);  //暂停0.5秒

    system("cls");

    toxy(46, 10);

    printf("修改成功！即将自动返回主菜单....");

    Sleep(500);

    break;

  } while (1);
}

void lost_reader() {
  do {
    system("cls");

    color(10);

    reader head, p;

    int i = 11, j = 0, x;

    char ch, t;

    FILE *fp;  //文件指针

    char _name[12];
    char number[12];
    char name[10];
    char gender;
    char school[30];
    int root;

    head = ss();
    p = head;
    toxy(48, 10);

    printf("请输入丢失读者学号：");
    gets(_name);

    while (p != NULL) {
      p->x = 0;
      p = p->next;
    }

    p = head;  //让p重新指向表头

    toxy(20, 5);

    printf("****************************读者信息***************");

    toxy(20, 8);

    printf(
        "--------------------------------------------------------------------"
        "-");

    toxy(20, 9);

    printf("学号 姓名 性别 学院 权限");

    toxy(20, 10);

    printf(
        "--------------------------------------------------------------------");

    while (p != NULL) {
      if (p != NULL && strcmp(p->number, _name) == 0) {
        toxy(20, i);

        j++;
        printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender,
               p->school, p->root);
        p->x = j;  //给符合查询标准的结点标号
        i++;
      }

      p = p->next;
    }

    if (j == 0)  //如果j=0，即没有进入前面的搜索循环，也就是没有找到相应的信息
    {
      toxy(50, i);

      printf("没有找到相应的信息！(按0返回，按1重新搜索)");

      while (1)  //死循环是为了防止除0和1的其他按键干扰
      {
        ch = getch();
        if (ch == '0') {
          menu();
          break;
        } else if (ch == '1') {
          break;
        }
      }
      if (ch == '1')  //如果输入的ch等于1，则结束本次循环

        continue;
    }

    while (1) {
      toxy(45, i);

      printf("按enter键开始修改");
      if (getchar()) break;
    }

    p = head;  //让p重新指向表头

    while (p != NULL && p->x != j)  //遍历链表查询符合条件的结点
    {
      p = p->next;
    }

    if (p)  //如果p不为空
    {
      system("cls");

      toxy(48, 8);
      p->root = 1;
    }

    color(7);
    toxy(46, 8);

    printf("-------------------------");
    toxy(46, 9);

    printf("| |");

    toxy(46, 10);

    printf("| 是否确认修改？ |");

    toxy(46, 12);

    printf("| 1.是 2.否 |");

    toxy(46, 13);

    printf("| |");

    toxy(46, 14);

    printf("-------------------------");

    while (1)  //利用死循环防止其他按键干扰
    {
      t = getch();

      if (t == '1') {
        break;

      } else if (t == '2') {
        menu();
      }
    }

    system("cls");

    toxy(46, 10);

    printf("正在修改，请稍后....");

    fp = fopen(
        "mybook",
        "wb");  //以只写的方式打开名为mybook的二进制文件，打开的同时清空文件中的内容

    if (fp == NULL) {
      printf("cannot open file");
      fprintf(fp, "%s %s %c %s %d\n", head->number, head->name, head->gender,
              head->school, head->root);
    }

    fclose(fp);  //关闭文件

    if (head != NULL)  //如果head不为空
    {
      p = head->next;  //让p指向第二个结点

      fp = fopen("mybook", "ab");  //以追加的方式打开文件

      if (fp == NULL)

      {
        printf("cannot open file");
      }

      while (p != NULL) {
        fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender,
                p->school, p->root);
        p = p->next;
      }

      fclose(fp);  //关闭文件
    }
    Sleep(500);  //暂停0.5秒

    system("cls");

    toxy(46, 10);

    printf("修改成功！即将自动返回主菜单....");

    Sleep(500);

    break;

  } while (1);
}
int main() { menu(); }