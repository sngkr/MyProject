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

void HideCursor();  //���ع��

void toxy(short x, short y);  //������ƶ���X,Y���괦
void color(short x);          //������ɫ

void over();  //�˳�

void menu();  //�˵�

void input_reader();  //ͼ�����
void save_reader(reader);
void find_reader();
void print_reader();
void lost_reader();
void amend_reader();
reader ss();

void FindReader_Name();
void FindReader_Code();

void HideCursor();  //���ع��

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

void menu()  //�˵�
{
  do {
    system("cls");  //����
    // HideCursor();   //���ع��
    color(15);  //����һ���ÿ�����ɫ
    char t;
    toxy(50, 5);  //������ƶ�����50��5�����괦
    printf(" ���߹���ϵͳ");
    toxy(48, 8);

    printf("| 1.������ж��� |");

    toxy(48, 10);

    printf("| 2.���Ӷ��� |");

    toxy(48, 12);

    printf("| 3.��ѯ���� |");

    toxy(48, 14);

    printf("| 4.�޸Ķ��� |");

    toxy(48, 16);

    printf("| 5.֤����ʧ |");

    toxy(48, 18);

    printf("| 0.������һ�� |");

    t = getch();  //�����Ժ���

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
    p = (reader)malloc(R);  //����ռ�
    toxy(48, 8);
    printf("��������ߺ�(<13)��");
    scanf("%s", p->number);
    getchar();

    toxy(48, 10);

    printf("�������������");
    scanf("%s", p->name);
    getchar();

    toxy(48, 12);

    printf("����������Ա�F/M����");
    scanf("%c", &p->gender);
    getchar();

    toxy(48, 14);

    printf("�������������ѧԺ��");
    scanf("%s", p->school);
    getchar();

    toxy(48, 16);

    printf("���������Ȩ�ޣ�0,1����");
    scanf("%d", &p->root);
    getchar();

    toxy(48, 18);

    save_reader(p);

    toxy(48, 24);
    while (1) {
      toxy(48, 30);

      printf("�������enter����ʼ�޸�");
      if (getchar()) break;
    }
    printf("���ڱ���....");

    Sleep(500);  //��ͣ0.5��

    system("cls");

    toxy(46, 8);

    printf("-------------------------");

    toxy(46, 9);

    printf("| |");

    toxy(46, 10);

    printf("| ����ɹ����Ƿ������ |");

    toxy(46, 12);

    printf("| 1.�� 2.�� |");

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
  FILE *fp;  //�ļ�ָ��

  fp = fopen("mybook", "ab");  //��׷�ӵķ�ʽ������Ϊmybook�Ķ������ļ�
  if (fp == NULL) {
    printf("cannot open file");
  }

  if (fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender, p->school,
              p->root) != 0) {
    printf("write ok");
  }
  fclose(fp);  //�ر��ļ�
}

void print_reader() {
  system("cls");
  color(6);
  reader head, p;
  int i = 11;
  int sum = 0;

  head = ss();

  printf("ѧ�� ���� �Ա� ѧԺ Ȩ��\n");

  if (head == NULL) {
    // toxy(45, 11);
    printf("����Ϣ\n");
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
  printf("�����������\n");
  getch();  //�����Ժ���
}

void find_reader() {
  do

  {
    system("cls");  //����

    color(8);

    char t;

    toxy(50, 5);

    printf(" ���߲�ѯ");

    toxy(48, 8);

    printf("| 1.ѧ�� ��ѯ |");

    toxy(48, 10);

    printf("| 2.���� ��ѯ |");

    toxy(48, 12);

    printf("��0�������˵�");

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
  printf("��������Ҫ��ѯ�Ķ���ѧ�ţ�");
  gets(number);
  toxy(48, 10);
  printf("���ڲ�ѯ....");
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
  printf("����������أ�");
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
  printf("��������Ҫ��ѯ�Ķ�������");
  gets(name);
  toxy(48, 10);
  printf("���ڲ�ѯ....");
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
  printf("����������أ�");
  getch();
  find_reader();
}

reader ss() {
  FILE *fp;  //�ļ�ָ��
  int n = 0;
  reader head = NULL;
  reader p2, p, pr = NULL;

  fp = fopen("mybook", "ab+");  //��ֻ���ķ�ʽ���ļ�

  if (fp == NULL) {
    printf("cannot open file\n");
  }

  while (!feof(fp))  //�ж��ļ�λ�ñ�־�Ƿ��ƶ����ļ�ĩβ
  {
    n++;
    p = (reader)malloc(R);  //���ڴ�����һ�οռ�

    // fread(p, R, 1, fp);  //��fp��ָ����ļ��е����ݸ���
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
  fclose(fp);   //�ر��ļ�
  return head;  //����ͷָ��
}
void amend_reader() {
  do {
    system("cls");

    color(10);

    reader head, p;

    int i = 11, j = 0, x;

    char ch, t;

    FILE *fp;  //�ļ�ָ��

    char _name[12];
    char number[12];
    char name[10];
    char gender;
    char school[30];
    int root;

    head = ss();
    p = head;
    toxy(48, 10);

    printf("��������Ҫ�޸Ķ���ѧ�ţ�");
    gets(_name);

    while (p != NULL) {
      p->x = 0;
      p = p->next;
    }

    p = head;  //��p����ָ���ͷ

    toxy(20, 5);

    printf(
        "***********************************************������Ϣ***************"
        "***************************************");

    toxy(20, 8);

    printf(
        "----------------------------------------------------------------------"
        "---------------------------------------");

    toxy(20, 9);

    printf("ѧ�� ���� �Ա� ѧԺ Ȩ��");

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
        p->x = j;  //�����ϲ�ѯ��׼�Ľ����
        i++;
      }

      p = p->next;
    }

    if (j == 0)  //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ
    {
      toxy(50, i);

      printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");

      while (1)  //��ѭ����Ϊ�˷�ֹ��0��1��������������
      {
        ch = getch();
        if (ch == '0') {
          menu();
          break;
        } else if (ch == '1') {
          break;
        }
      }
      if (ch == '1')  //��������ch����1�����������ѭ��

        continue;
    }

    while (1) {
      toxy(45, i);

      printf("�������enter����ʼ�޸�");
      if (getchar()) break;
    }

    p = head;  //��p����ָ���ͷ

    while (p != NULL && p->x != j)  //���������ѯ���������Ľ��
    {
      p = p->next;
    }

    if (p)  //���p��Ϊ��
    {
      system("cls");
      //����Ҫ�޸ĵ���Ϣ
      toxy(48, 8);
      printf("������ѧ�ţ�");

      scanf("%s", number);
      getchar();
      strcpy(p->number, number);

      toxy(48, 10);

      printf("�������������");

      scanf("%s", name);
      getchar();
      strcpy(p->name, name);

      toxy(48, 12);

      printf("�������Ա�");

      scanf("%c", &gender);
      getchar();
      p->gender = gender;

      toxy(48, 14);

      printf("������ѧԺ��");

      scanf("%s", school);
      getchar();
      strcpy(p->school, school);

      toxy(48, 16);

      printf("������Ȩ��");

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

    printf("| �Ƿ�ȷ���޸ģ� |");

    toxy(46, 12);

    printf("| 1.�� 2.�� |");

    toxy(46, 13);

    printf("| |");

    toxy(46, 14);

    printf("-------------------------");

    while (1)  //������ѭ����ֹ������������
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

    printf("�����޸ģ����Ժ�....");

    fp = fopen(
        "mybook",
        "wb");  //��ֻд�ķ�ʽ����Ϊmybook�Ķ������ļ����򿪵�ͬʱ����ļ��е�����

    if (fp == NULL) {
      printf("cannot open file");
      fprintf(fp, "%s %s %c %s %d\n", head->number, head->name, head->gender,
              head->school, head->root);
    }

    fclose(fp);  //�ر��ļ�

    if (head != NULL)  //���head��Ϊ��
    {
      p = head->next;  //��pָ��ڶ������

      fp = fopen("mybook", "ab");  //��׷�ӵķ�ʽ���ļ�

      if (fp == NULL)

      {
        printf("cannot open file");
      }

      while (p != NULL) {
        fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender,
                p->school, p->root);
        p = p->next;
      }

      fclose(fp);  //�ر��ļ�
    }
    Sleep(500);  //��ͣ0.5��

    system("cls");

    toxy(46, 10);

    printf("�޸ĳɹ��������Զ��������˵�....");

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

    FILE *fp;  //�ļ�ָ��

    char _name[12];
    char number[12];
    char name[10];
    char gender;
    char school[30];
    int root;

    head = ss();
    p = head;
    toxy(48, 10);

    printf("�����붪ʧ����ѧ�ţ�");
    gets(_name);

    while (p != NULL) {
      p->x = 0;
      p = p->next;
    }

    p = head;  //��p����ָ���ͷ

    toxy(20, 5);

    printf("****************************������Ϣ***************");

    toxy(20, 8);

    printf(
        "--------------------------------------------------------------------"
        "-");

    toxy(20, 9);

    printf("ѧ�� ���� �Ա� ѧԺ Ȩ��");

    toxy(20, 10);

    printf(
        "--------------------------------------------------------------------");

    while (p != NULL) {
      if (p != NULL && strcmp(p->number, _name) == 0) {
        toxy(20, i);

        j++;
        printf("%12s %12s %c %20s %4d\n", p->number, p->name, p->gender,
               p->school, p->root);
        p->x = j;  //�����ϲ�ѯ��׼�Ľ����
        i++;
      }

      p = p->next;
    }

    if (j == 0)  //���j=0����û�н���ǰ�������ѭ����Ҳ����û���ҵ���Ӧ����Ϣ
    {
      toxy(50, i);

      printf("û���ҵ���Ӧ����Ϣ��(��0���أ���1��������)");

      while (1)  //��ѭ����Ϊ�˷�ֹ��0��1��������������
      {
        ch = getch();
        if (ch == '0') {
          menu();
          break;
        } else if (ch == '1') {
          break;
        }
      }
      if (ch == '1')  //��������ch����1�����������ѭ��

        continue;
    }

    while (1) {
      toxy(45, i);

      printf("��enter����ʼ�޸�");
      if (getchar()) break;
    }

    p = head;  //��p����ָ���ͷ

    while (p != NULL && p->x != j)  //���������ѯ���������Ľ��
    {
      p = p->next;
    }

    if (p)  //���p��Ϊ��
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

    printf("| �Ƿ�ȷ���޸ģ� |");

    toxy(46, 12);

    printf("| 1.�� 2.�� |");

    toxy(46, 13);

    printf("| |");

    toxy(46, 14);

    printf("-------------------------");

    while (1)  //������ѭ����ֹ������������
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

    printf("�����޸ģ����Ժ�....");

    fp = fopen(
        "mybook",
        "wb");  //��ֻд�ķ�ʽ����Ϊmybook�Ķ������ļ����򿪵�ͬʱ����ļ��е�����

    if (fp == NULL) {
      printf("cannot open file");
      fprintf(fp, "%s %s %c %s %d\n", head->number, head->name, head->gender,
              head->school, head->root);
    }

    fclose(fp);  //�ر��ļ�

    if (head != NULL)  //���head��Ϊ��
    {
      p = head->next;  //��pָ��ڶ������

      fp = fopen("mybook", "ab");  //��׷�ӵķ�ʽ���ļ�

      if (fp == NULL)

      {
        printf("cannot open file");
      }

      while (p != NULL) {
        fprintf(fp, "%s %s %c %s %d\n", p->number, p->name, p->gender,
                p->school, p->root);
        p = p->next;
      }

      fclose(fp);  //�ر��ļ�
    }
    Sleep(500);  //��ͣ0.5��

    system("cls");

    toxy(46, 10);

    printf("�޸ĳɹ��������Զ��������˵�....");

    Sleep(500);

    break;

  } while (1);
}
int main() { menu(); }