#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int key;
    struct treenode* parent, * lchild, * rchild;
}treenode;

int isexternal(treenode* w) {
    return ((w->lchild == NULL) && (w->rchild == NULL));
}

int isinternal(treenode* w) {
    return ((w->lchild != NULL) || (w->rchild != NULL));
}

treenode* sibling(treenode* w) {
    if (w->parent == NULL)
        return NULL;
    if (w->parent->lchild == w)
        return w->parent->rchild;
    else
        return w->parent->lchild;
}

treenode* inordersucc(treenode* w) {
    w = w->rchild;
    if (isexternal(w))
        return NULL;
    while (isinternal(w->lchild)) {
        w = w->lchild;
    }

    return w;
}

void reduceexternal(treenode *root, treenode* z) {
    treenode* w, * g, * zs;
    w = z->parent;
    zs = sibling(z);
    if (w->parent==NULL) {
        root->lchild = zs->lchild;
        root->rchild = zs->rchild;
        root->lchild->parent = zs;
        root->rchild->parent = zs;
        zs->parent = NULL;
    }
    else {
        g = w->parent;
        zs->parent = g;
        if (w == g->lchild)
            g->lchild = zs;
        else if(w==g->rchild)
            g->rchild = zs;
    }
}

treenode* treesearch(treenode* root, int data) {
   
    if (isexternal(root))
        return root;

    if (root->key == data)
        return root;
    else if (root->key > data)
        return treesearch(root->lchild, data);
    else
        return treesearch(root->rchild, data);
}

void insertitem(treenode *w, int key) {
    treenode* lnode = (treenode*)malloc(sizeof(treenode));
    treenode* rnode = (treenode*)malloc(sizeof(treenode));
    treenode* p = treesearch(w, key);
    p->key = key;
    p->lchild = lnode;
    p->rchild = rnode;
    lnode->parent = p;
    rnode->parent = p;
    lnode->lchild = NULL;
    lnode->rchild = NULL;
    rnode->lchild = NULL;
    rnode->rchild = NULL;
}

int removeelement(treenode *w, int key) {
    treenode* p = treesearch(w, key);
    treenode* z, * y;
    int e;
    if (isexternal(p))
        return -1;
    e = p->key;
    z = p->lchild;
    if (!isexternal(z))
        z = p->rchild;
    if (isexternal(z))
        reduceexternal(p, z);
    else {
        y = inordersucc(p);
        z = y->lchild;
        p->key = y->key;
        reduceexternal(p, z);
    }
    return e;
}

void inorder(treenode* w) {
    if (isexternal(w))
        return;
    else {
        printf(" %d", w->key);
        inorder(w->lchild);
        inorder(w->rchild);
    }
}


int main() {
    
    int key, p;
    char ch;

    treenode* w = (treenode*)malloc(sizeof(treenode));
    w->parent = NULL;
    w->lchild = NULL;
    w->rchild = NULL;

    while (1) {
        scanf("%c", &ch);
        if (ch == 'q')
            break;
        else if (ch == 'i') {
            scanf("%d", &key);
            insertitem(w, key);
            getchar();
        }
        else if (ch == 's') {
            scanf("%d", &key);
            if (treesearch(w,key)->key !=key)
                printf("X\n");
            else
                printf("%d\n", treesearch(w,key)->key);
            getchar();
        }
        else if (ch == 'd') {
            scanf("%d", &key);
            p = removeelement(w, key);
            if (p == -1)
                printf("X\n");
            else
                printf("%d\n", p);
            getchar();
        }
        else if (ch == 'p') {
            inorder(w);
            printf("\n");
        }
    }

    return 0;
}
