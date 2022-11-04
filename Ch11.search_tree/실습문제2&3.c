#pragma warning(disable:4996)
#include <stdio.h>
#include <stdlib.h>

typedef struct treenode {
    int key;
    int height;
    struct treenode* parent, * lchild, * rchild;
}treenode;

treenode* root;

int isexternal(treenode* w) {
    return ((w->lchild == NULL) && (w->rchild == NULL));
}

int isinternal(treenode* w) {
    return ((w->lchild != NULL) && (w->rchild != NULL));
}

int updateheight(treenode* w) {
    int h = w->lchild->height;
    if (w->rchild->height > w->lchild->height)
        h = w->rchild->height;
    h += 1;
    if (h != w->height) {
        w->height = h;
        return 1;
    }
    else
        return 0;
}

int isbalanced(treenode* w) {
    return (-2 < ((w->lchild->height) - (w->rchild->height)) && 2 > ((w->lchild->height) - (w->rchild->height)));
}

treenode* restructure(treenode* x, treenode* y, treenode* z) {
    treenode* a, * b, * c, * t0, * t1, * t2, * t3;
    if (z->key < y->key && y->key < x->key) {
        a = z;
        b = y;
        c = x;
        t0 = a->lchild;
        t1 = b->lchild;
        t2 = c->lchild;
        t3 = c->rchild;
    }
    else if (x->key < y->key && y->key < z->key) {
        a = x;
        b = y;
        c = z;
        t0 = a->lchild;
        t1 = a->rchild;
        t2 = b->rchild;
        t3 = c->rchild;
    }
    else if (z->key < x->key && x->key < y->key) {
        a = z;
        b = x;
        c = y;
        t0 = a->lchild;
        t1 = b->lchild;
        t2 = b->rchild;
        t3 = c->rchild;
    }
    else{
        a = y;
        b = x;
        c = z;
        t0 = a->lchild;
        t1 = b->lchild;
        t2 = b->rchild;
        t3 = c->rchild;
    }
    if (z->parent == NULL) {
        root = b;
        b->parent = NULL;
    }
    else if (z->parent->lchild == z) {
        z->parent->lchild = b;
        b->parent = z->parent;
    }
    else{
        z->parent->rchild = b;
        b->parent = z->parent;
    }
    a->lchild = t0;
    a->rchild = t1;
    t0->parent = a;
    t1->parent = a;
    updateheight(a);
    c->lchild = t2;
    c->rchild = t3;
    t2->parent = c;
    t3->parent = c;
    updateheight(c);

    b->lchild = a;
    b->rchild = c;
    a->parent = b;
    c->parent = b;
    updateheight(b);
    return b;
}

treenode* sibling(treenode* w) {
    if (w->parent == NULL)
        return;
    if (w->parent->lchild == w)
        return w->parent->rchild;
    else
        return w->parent->lchild;
}

treenode* inordersucc(treenode* w) {
    w = w->rchild;
    if (isexternal(w))
        return;
    while (isinternal(w->lchild)) {
        w = w->lchild;
    }

    return w;
}

void expandexternal(treenode* w) {
    treenode* l = (treenode*)malloc(sizeof(treenode));
    treenode* r = (treenode*)malloc(sizeof(treenode));
    l->lchild = NULL;
    l->rchild = NULL;
    l->parent = w;
    l->height = 0;

    r->lchild = NULL;
    r->rchild = NULL;
    r->parent = w;
    r->height = 0;

    w->lchild = l;
    w->rchild = r;
    w->height = 1;
}

treenode* reduceexternal(treenode* z) {
    treenode* w, * g, * zs;
    w = z->parent;
    zs = sibling(z);
    if (w->parent==NULL) {
        root = zs;
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
    return zs;
}

treenode* treesearch(treenode* w, int data) {
   
    if (isexternal(w))
        return w;

    if (w->key == data)
        return w;
    else if (w->key > data)
        return treesearch(w->lchild, data);
    else
        return treesearch(w->rchild, data);
}

void searchandfix(treenode* w) {
    treenode* x, * y, * z;
    w->lchild->height = 0;
    w->rchild->height = 0;
    w->height = 1;

    if (w->parent == NULL)
        return NULL;
    z = w->parent;
    while (updateheight(z) && isbalanced(z)) {
        if (z->parent == NULL)
            return;
        z = z->parent;
    }
    if (isbalanced(z))
        return;
    if (z->lchild->height > z->rchild->height)
        y = z->lchild;
    else
        y = z->rchild;
    if (y->lchild->height > y->rchild->height)
        x = y->lchild;
    else
        x = y->rchild;
    restructure(x, y, z);
}

void removal(treenode* w) {
    treenode* x, * y, *z, * b;
    if (w == NULL)
        return;
    z = w;
    while (updateheight(z) && isbalanced(z)) {
        if (z->parent == NULL)
            return;
        z = z->parent;
    }
    if (isbalanced(z))
        return;
    if (z->lchild->height > z->rchild->height)
        y = z->lchild;
    else
        y = z->rchild;
    if (y->lchild->height > y->rchild->height)
        x = y->lchild;
    else if (y->lchild->height < y->rchild->height)
        x = y->rchild;
    else {
        if (z->lchild == y)
            x = y->lchild;
        else
            x = y->rchild;
    }
    b = restructure(x, y, z);
    removal(b->parent);
}

void insertitem(treenode *w, int key) {
    treenode* p = treesearch(w, key);

    if (isinternal(p))
        return;
    else {
        p->key = key;
        expandexternal(p);
        searchandfix(p);
    }
}

int removeelement(treenode *w, int key) {
    treenode* p = treesearch(w, key);
    treenode* z, *zs, *y;
    int e;
    if (isexternal(p))
        return -1;
    e = p->key;
    z = p->lchild;
    if (!isexternal(z))
        z = p->rchild;
    if (isexternal(z))
        zs=reduceexternal(z);
    else {
        y = inordersucc(p);
        z = y->lchild;
        p->key = y->key;
        zs=reduceexternal(z);
    }
    removal(zs->parent);
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

    root = (treenode*)malloc(sizeof(treenode));
    root->parent = NULL;
    root->lchild = NULL;
    root->rchild = NULL;

    while (1) {
        scanf("%c", &ch);
        if (ch == 'q')
            break;
        else if (ch == 'i') {
            scanf("%d", &key);
            insertitem(root, key);
            getchar();
        }
        else if (ch == 's') {
            scanf("%d", &key);
            if (treesearch(root,key)->key !=key)
                printf("X\n");
            else
                printf("%d\n", treesearch(root,key)->key);
            getchar();
        }
        else if (ch == 'd') {
            scanf("%d", &key);
            p = removeelement(root, key);
            if (p == key)
                printf("%d\n", p);
            else
                printf("X\n");
            getchar();
        }
        else if (ch == 'p') {
            inorder(root);
            printf("\n");
        }
    }

    return 0;
}
