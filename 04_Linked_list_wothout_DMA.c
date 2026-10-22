#include <stdio.h>
#define MAX 100
#define NULL_IDX (-1)

typedef struct{
    int data;
    int next;
} Node;

Node pool[MAX];
int head = NULL_IDX;
int used = 0;

int create_node(int data){
    if (used >= MAX)
        return NULL_IDX;

    int idx = used++;
    pool[idx].data = data;
    pool[idx].next = NULL_IDX;

    return idx;
}

void insert_begin(int data)
{
    int idx = create_node(data);
    if (idx == NULL_IDX)
        return;

    pool[idx].next = head;
    head = idx;
}

void insert_tail(int data)
{
    int idx = create_node(data);
    if (idx == NULL_IDX)
        return;

    if (head == NULL_IDX)
    {
        head = idx;
        return;
    }

    int cur = head;
    while (pool[cur].next != NULL_IDX)
        cur = pool[cur].next;

    pool[cur].next = idx;
}

/* Insert at a zero-based position */
void insert_mid(int data, int pos)
{
    if (pos < 0)
        return;

    if (pos == 0)
    {
        insert_begin(data);
        return;
    }

    int cur = head;

    for (int i = 0; cur != NULL_IDX && i < pos - 1; i++)
        cur = pool[cur].next;

    if (cur == NULL_IDX)
        return;

    int idx = create_node(data);
    if (idx == NULL_IDX)
        return;

    pool[idx].next = pool[cur].next;
    pool[cur].next = idx;
}

void delete_begin(void)
{
    if (head == NULL_IDX)
        return;

    head = pool[head].next;
}

void delete_tail(void)
{
    if (head == NULL_IDX)
        return;

    if (pool[head].next == NULL_IDX)
    {
        head = NULL_IDX;
        return;
    }

    int cur = head;

    while (pool[pool[cur].next].next != NULL_IDX)
        cur = pool[cur].next;

    pool[cur].next = NULL_IDX;
}

/* Delete the node at a zero-based position */
void delete_mid(int pos)
{
    if (pos < 0 || head == NULL_IDX)
        return;

    if (pos == 0)
    {
        delete_begin();
        return;
    }

    int cur = head;

    for (int i = 0; cur != NULL_IDX && i < pos - 1; i++)
        cur = pool[cur].next;

    if (cur == NULL_IDX || pool[cur].next == NULL_IDX)
        return;

    pool[cur].next = pool[pool[cur].next].next;
}

void traverse(void)
{
    int cur = head;

    while (cur != NULL_IDX)
    {
        printf("%d -> ", pool[cur].data);
        cur = pool[cur].next;
    }

    printf("NULL\n");
}

int main(void)
{
    insert_begin(20);
    insert_begin(10);
    insert_tail(40);
    insert_mid(30, 2);

    traverse();       /* 10 -> 20 -> 30 -> 40 -> NULL */

    delete_begin();
    delete_mid(1);
    delete_tail();

    traverse();       /* 20 -> NULL */

    return 0;
}