#include <iostream>
#include <vector>
using namespace std;

vector<int> post, in;

struct NODE
{
    NODE *left, *right;
    int value;
    NODE(int value) : value(value), left(NULL), right(NULL){};
} * Root;

NODE *creatTree(int root, int start, int end)
{
    if (start > end)
        return NULL;
    int i = start;
    while (i < end && in[i] != post[root])
        i++;

    NODE *temp = new NODE(post[root]);

    temp->left = creatTree(root + 1, start, i - 1);

    temp->right = creatTree(root + 1, root - start + i + 1, end);

    return temp;
}

int main()
{
    int num;
    cin >> num;
    post.resize(num);
    in.resize(num);

    for (int i = 0; i < num; i++)
        cin >> in[i];

    for (int i = 0; i < num; i++)
        cin >> post[i];

    Root = creatTree(num - 1, 0, num - 1);
    // 层次遍历
    vector<NODE*> v;
    v.push_back(Root);
    int len, res[31], cnt = 0;
    bool reverse = true;
    while (!v.empty()) {
        len = (int)v.size();
        // 每次遍历一整层，将下一层加入遍历向量中
        for(int i = 0; i < len; i++){
            if(v[i]->left != NULL){
                v.push_back(v[i]->left);
            }
            if(v[i]->right != NULL){
                v.push_back(v[i]->right);
            }
        }
        
        // 根据reverse决定当前层是否逆置，逆置则将其反向加入结果向量中，否则正向加入
        if(reverse){
            for(int i = len - 1; i >= 0; i--){
                res[cnt++] = v[i]->value;
            }
        }else{
            for(int i = 0; i < len; i++){
                res[cnt++] = v[i]->value;
            }
        }
        
        // 在向量中擦除当前层的结点
        v.erase(v.begin(), v.begin() + len);
        
        // 将reverse取反，实现交替
        reverse = !reverse;
    }
    
    // 输出答案
    printf("%d", res[0]);
    for(int i = 1; i < num; i++){
        printf(" %d", res[i]);
    }
    return 0;

}