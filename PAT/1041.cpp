    #include <cstdio>
    using namespace std;
    int a[100001], b[100001];
    int main()
    {
        int num;
        scanf("%d", &num);

        for (int i = 0, temp; i < num; i++)
        {
            scanf("%d", &a[i]);
            b[a[i]]++;
        }

        for (int i = 0; i < num; i++)
        {
            if (b[a[i]] == 1)
            {
                printf("%d", a[i]);
                return 0;
            }
        }

        printf("None");
        return 0;
    }