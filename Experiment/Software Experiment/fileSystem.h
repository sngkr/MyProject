#include <malloc.h>
#include <stdio.h>
#include <string.h>
#define MAX_NODE 64  //最多结点个数
#define MAX_TREE_SIZE 100
typedef struct Catalog  //目录结构类型
{
  char Key[20];      //编号
  char Caption[80];  //标题，类名
  char Parent[20];   //父类编号
} Catalog;
typedef struct CatalogTree  //目录顺序存储结构类型
{
  Catalog node[MAX_TREE_SIZE];
  int root;  //根节点位置，根节点默认在0号单元；
  int num;   //最后一个结点的数组编号
} CatalogTree;

#define ElemType Catalog
typedef struct Ptnode {
  ElemType data;  // 数据域
  int parent;     //双亲指示域
} Ptnode;
typedef struct {
  Ptnode nodes[MAX_NODE];
  int n;  //结点个数
} Ptree;

void menu();

/* 查找 */
int FindCatalog();

/* 增加新分类信息，保存至文件 */
void AddCatalog();

/*修改分类信息，保存至文件  */
void AlterCatalog();

/* 从文件中删除分类信息 */
void DeleteCatalog();

/*顺序输出文件中所有分类信息  */
void PrintCatalog();

/*  将分类信息用双亲表示法存储。调用PrintCatalogTree()*/
void CreatCatalogTree();

/* 调用PreOrder()函数 */
void PrintCatalogTree(const CatalogTree *);

/* 递归输出分类树 */
void PreOrder(const CatalogTree *, int, int);

int FindCatalog(const char *fiKey) {
  FILE *fp = fopen("catalog3.dat", "rb");
  Catalog *man = (Catalog *)malloc(sizeof(Catalog));
  while (fread(man, sizeof(Catalog), 1, fp)) {
    if (strcmp(man->Key, fiKey) == 0) {
      return 1;
    }
  }
  free(man);
  fclose(fp);
  return 0;
}

void AddCatalog() {
  FILE *fp;
  Catalog *temp = (Catalog *)malloc(sizeof(Catalog));
  printf("Key Caption Parent\n");
  scanf("%s %s %s", temp->Key, temp->Caption, temp->Parent);
  fp = fopen("catalog3.dat", "ab+ ");
  fwrite(temp, sizeof(Catalog), 1, fp);
  fclose(fp);
  free(temp);
}

void AlterCatalog() {
  FILE *fp, *fp1;
  fp = fopen("catalog3.dat", "rb+");
  fp1 = fopen("temp.dat", "w+");
  int flag = 0;
  Catalog *temp = (Catalog *)malloc(sizeof(Catalog));
  Catalog *man = (Catalog *)malloc(sizeof(Catalog));
  printf("Key Caption Parent\n");
  scanf("%s %s %s", temp->Key, temp->Caption, temp->Parent);
  while (fread(man, sizeof(Catalog), 1, fp)) {
    if (strcmp(man->Key, temp->Key) != 0) {
      fwrite(man, sizeof(Catalog), 1, fp1);
    } else {
      strcpy(man->Key, temp->Key);
      strcpy(man->Caption, temp->Caption);
      strcpy(man->Parent, temp->Parent);
      fwrite(man, sizeof(Catalog), 1, fp1);
      flag = 1;
    }
  }
  if (!flag) printf("alter  error!\n");
  fclose(fp1);
  fclose(fp);
  remove("catalog3.dat");
  rename("temp.dat", "catalog3.dat");
  free(man);

  // FILE *fp;
  // fp = fopen("catalog3.dat", "wb+");
  // int num = 0;
  // Catalog *temp = (Catalog *)malloc(sizeof(Catalog));
  // while (!feof(fp)) {
  //   fseek(fp, num * sizeof(Catalog), 0);
  //   if (fread(temp, sizeof(Catalog), 1, fp)) {
  //     if (strcmp(temp->Key, alKey->Key) == 0) {
  //       fwrite(alKey, sizeof(Catalog), 1, fp);
  //     }
  //     num++;
  //   }
  // }
  // fclose(fp);
  // free(temp);
}

void DeleteCatalog() {
  FILE *fp, *fp1;
  fp = fopen("catalog3.dat", "rb+");
  fp1 = fopen("temp.dat", "w+");
  int flag = 0;
  char temp[20];
  memset(&temp, 0, sizeof(temp));
  printf("Key\n");
  scanf("%s", temp);
  Catalog *man = (Catalog *)malloc(sizeof(Catalog));
  while (fread(man, sizeof(Catalog), 1, fp)) {
    if (strcmp(man->Key, temp) != 0) {
      fwrite(man, sizeof(Catalog), 1, fp1);
    } else {
      flag = 1;
    }
  }
  if (!flag) printf("delete  error!\n");
  fclose(fp1);
  fclose(fp);
  remove("catalog3.dat");
  rename("temp.dat", "catalog3.dat");
  free(man);
}

void PrintCatalog() {
  FILE *fp;
  fp = fopen("catalog3.dat", "rb");
  int num = 0;
  Catalog *temp = (Catalog *)malloc(sizeof(Catalog));
  while (!feof(fp)) {
    fseek(fp, num * sizeof(Catalog), 0);
    if (fread(temp, sizeof(Catalog), 1, fp)) {
      printf("%s %s %s\n", temp->Key, temp->Caption, temp->Parent);
      num++;
    }
  }
  fclose(fp);
  free(temp);
}

void CreatCatalogTree() {
  FILE *fp;
  CatalogTree *tree = (CatalogTree *)malloc(sizeof(CatalogTree));
  fp = fopen("catalog3.dat", "rb");
  if (fp < 0) printf("fopen error!\n");
  int num = 0;
  while (!feof(fp)) {
    fseek(fp, num * sizeof(Catalog), 0);
    if (fread(&tree->node[num], sizeof(Catalog), 1, fp)) {
      num++;
    }
  }
  tree->num = num;
  tree->root = 0;
  fclose(fp);
  PrintCatalogTree(tree);
  free(tree);
}
void PrintCatalogTree(const CatalogTree *tree) {
  printf("|--%s %s %s\n", tree->node[0].Key, tree->node[0].Caption,
         tree->node[0].Parent);
  PreOrder(tree, 0, 3);
}
void PreOrder(const CatalogTree *tree, int index, int depth) {
  for (int j = index; j < tree->num; j++) {
    if (strcmp(tree->node[j].Parent, tree->node[index].Key) == 0) {
      for (int i = 0; i < depth; i++) printf(" ");
      printf("|--%s %s %s\n", tree->node[j].Key, tree->node[j].Caption,
             tree->node[j].Parent);
      PreOrder(tree, j, depth + 3);
    }
  }
  // for (int j = index; j < tree->num; j++)
  //   //在数组中逐个比对找到结点i的所有子结点
  //   if (strcmp(tree->node[j].Parent, tree->node[index].Key) == 0) {
  //     printf("%s ", tree->node[j].Key);
  //     PreOrder(tree, j);  //探索该子结点的子结点
  //   }
}
