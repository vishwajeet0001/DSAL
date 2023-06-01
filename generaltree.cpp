#include <iostream>
using namespace std;

struct node
{
    char name[10];
    string label;
    int childcnt;
    node *child[10];
} *root;


class genTree
{
public:
    genTree()
    {
        root = NULL;
    }
    void create()
    {
        int chap_cnt;
        root = new node;
        cout << "enter title of the book : ";
        cin >> root->label;
        cout << "enter the no. of chapters : ";
        cin >> chap_cnt;
        root->childcnt = chap_cnt;
        for (int i = 0; i < root->childcnt; i++)
        {
            root->child[i] = new node;
            cout << "enter name of chapter: ";
            cin >> root->child[i]->label;
            cout << "enter number of sections :";
            cin >> root->child[i]->childcnt;
            for (int j = 0; j < root->child[i]->childcnt; j++)
            {
                root->child[i]->child[i] = new node;
                cout << "enter the name of sections : ";
                cin >> root->child[i]->child[i]->label;
                cout<<"enter number of subsection:";
                cin>>root->child[i]->child[i]->childcnt;
                for(int k=0;k<root->child[i]->child[i]->childcnt;k++)
                {
                    root->child[i]->child[i]->child[i] = new node;
                    cout<<"enter a name of subsection:";
                    cin>>root->child[i]->child[i]->child[i]->label;
                }
            }
        }
    }

    void display(node *r)
    {
        if (r != NULL)
        {
            int chap_cnt;
            cout << "Book title :" << r->label<<" ";
            chap_cnt = r->childcnt;
            for (int i = 0; i < chap_cnt; i++)
            {
                cout << "chapter " << i + 1<<":";
                cout << r->child[i]->label<<" ";
                cout << "sections :";
                for (int j = 0; j < r->child[i]->childcnt; j++)
                {
                    cout<<r->child[i]->child[j]->label<<" ";
                    cout<<"subsections :";
                    for(int k=0;k<r->child[i]->child[j]->childcnt;k++)
                    {
                        cout<<r->child[i]->child[j]->child[k]->label;
                    }
                }
            }
        }
    }
};

int main()
{
    genTree t;
    t.create();
    t.display(root);
}