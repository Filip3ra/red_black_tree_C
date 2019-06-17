#ifndef TREE_H
#define TREE_H

typedef struct no TNo;
struct no
{
    int  cor; /* 1 = preto, 2 = vermelho */
    void *elem;
    TNo  *pai;
    TNo  *left;
    TNo  *right;
};

void insert_tree( TNo **t, TNo *z, int (*comp)(), void (*print)() );
int   empty_tree( TNo *t );

TNo *fulfill_node( void *elem );
void insert_fixup( TNo **t, TNo *z );
void left_rotate ( TNo **t, TNo *p);
void right_rotate( TNo **t, TNo *p);
void print_tree( TNo *t, void (*print)() );


#endif /* TREE_H */
