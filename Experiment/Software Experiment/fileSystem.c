#include "fileSystem.h"
void menuHelper() {
  printf("*************************\n");
  printf("      �������˵�        \n");
  printf("*      1.���ӷ���        * \n");
  printf("*      2.�������        * \n");
  printf("*      3.������η�����  *\n");
  printf("*      4.�޸ķ���        *\n");
  printf("*      5.ɾ������        *\n");
  printf("*      0.�����ϼ�        *\n");
}
void menu() {
  while (1) {
    char ca = getchar();
    switch (ca) {
      case '1':
        AddCatalog();
        break;

      case '2':
        PrintCatalog();
        break;

      case '3':
        CreatCatalogTree();
        break;

      case '4':
        AlterCatalog();
        break;

      case '5':
        DeleteCatalog();
        break;

      case '0':
        menuHelper();
        break;

      default:
        break;
    }
  }
}

int main() {
  menu();
  // CatalogTree *tree = (CatalogTree *)malloc(sizeof(CatalogTree));
  // Catalog *temp = (Catalog *)malloc(sizeof(Catalog));
  // char ke[20] = "SK";
  // char ca[80] = "dddddd";
  // char pa[20] = "O";
  // (FindCatalog("A")) printf("yes");
  // strcpy(temp->Key, ke);
  // strcpy(temp->Caption, ca);
  // strcpy(temp->Parent, pa);
  // // AddCatalog(temp);
  // PrintCatalog();
  // //   // DeleteCatalog(ke);
  // //   char pb[20] = "Ooooo";
  // //   strcpy(temp->Parent, pb);
  // //   printf("%s %s %s\n", temp->Key, temp->Caption, temp->Parent);
  // //AlterCatalog(temp);
  // //PrintCatalog();
  // //   CreatCatalogTree(tree);
  // //     for (int i = 0; i < tree->num; i++) {
  // //       printf("%s\n", tree->node[i].Key);
  // //     }

  // CreatCatalogTree(tree);
  getchar();
}
