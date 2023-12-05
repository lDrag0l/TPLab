#pragma once
#include "Group.h"

typedef struct Node {
    Group* data;
    Node* next;
} Node;


class Keeper {
private:
    int len = 0;
    Node* head = NULL;
public:
    Keeper();
    Keeper(int size);
    Keeper(const Keeper& keeper_copy);
    ~Keeper();

    int get_len();

    void getByGrade();

    Group* operator[](int index);
    void add(Group* n_data);
    void edit(int index);
    void remove(int index);
    void clear();

    void save();
    void load();
    void show();
};

