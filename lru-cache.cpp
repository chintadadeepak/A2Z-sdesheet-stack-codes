#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int key;
    int value;
    Node *prev;
    Node *next;
    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
    }
};

class LRUCache
{
private:
    int capacity;
    unordered_map<int, Node *> mpp;
    Node *head, *tail;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        head = new Node(-1, -1);
        tail = new Node(-1, -1);
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
    }

    int get(int key)
    {
        if (mpp.find(key) != mpp.end())
        {
            Node *curr = mpp[key];
            Node *currPrev = curr->prev;
            Node *currNext = curr->next;
            currPrev->next = currNext;
            currNext->prev = currPrev;
            Node *headNext = head->next;
            head->next = curr;
            curr->next = headNext;
            curr->prev = head;
            headNext->prev = curr;
            return curr->value;
        }
        return -1;
    }

    void put(int key, int value)
    {
        if ((mpp.size() < capacity) && (mpp.find(key) == mpp.end()))
        {
            Node *newNode = new Node(key, value);
            Node *headNext = head->next;
            head->next = newNode;
            newNode->next = headNext;
            newNode->prev = head;
            headNext->prev = newNode;
            mpp.insert({key, newNode});
        }
        else if ((mpp.size() <= capacity) && (mpp.find(key) != mpp.end()))
        {
            Node *curr = mpp[key];
            Node *currPrev = curr->prev;
            Node *currNext = curr->next;
            currPrev->next = currNext;
            currNext->prev = currPrev;
            Node *headNext = head->next;
            head->next = curr;
            curr->next = headNext;
            curr->prev = head;
            headNext->prev = curr;
            curr->value = value;
        }
        else
        {
            Node *nodeNeedToUpdate = tail->prev;
            Node *nodeNeedToUpdatePrev = nodeNeedToUpdate->prev;
            tail->prev = nodeNeedToUpdatePrev;
            nodeNeedToUpdatePrev->next = tail;
            mpp.erase(nodeNeedToUpdate->key);
            Node *headNext = head->next;
            head->next = nodeNeedToUpdate;
            nodeNeedToUpdate->next = headNext;
            nodeNeedToUpdate->prev = head;
            headNext->prev = nodeNeedToUpdate;
            nodeNeedToUpdate->key = key;
            nodeNeedToUpdate->value = value;
            mpp.insert({key, nodeNeedToUpdate});
        }
    }
};
