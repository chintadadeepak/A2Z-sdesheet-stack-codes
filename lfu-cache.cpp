#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    int value;
    int frequency;
    Node *prev;
    Node *next;
    Node(int data, int value)
    {
        this->data = data;
        this->value = value;
        this->frequency = 1;
    }
};

struct List
{
public:
    Node *head;
    Node *tail;
    int size;
    List()
    {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->prev = head;
        head->prev = tail->next = NULL;
        size = 0;
    }
    void addFront(Node *node)
    {
        Node *headNext = head->next;
        node->next = headNext;
        node->prev = head;
        headNext->prev = node;
        head->next = node;
        size++;
    }
    void deleteNode(Node *node)
    {
        Node *nodePrev = node->prev;
        Node *nodeNext = node->next;
        nodePrev->next = nodeNext;
        nodeNext->prev = nodePrev;
        size--;
    }
};

class LFUCache
{
private:
    int capacity;
    int minFreq;
    unordered_map<int, Node *> keyNode;
    map<int, List *> freqList;

public:
    LFUCache(int capacity)
    {
        this->capacity = capacity;
        minFreq = 0;
    }

    void updateFreqList(Node *node)
    {
        List *list = freqList[node->frequency];
        list->deleteNode(node);
        if (minFreq == node->frequency && freqList[node->frequency]->size == 0)
            minFreq++;
        List *newList = new List();
        if (freqList.find(node->frequency + 1) != freqList.end())
            newList = freqList[node->frequency + 1];
        node->frequency += 1;
        newList->addFront(node);
        freqList[node->frequency] = newList;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            Node *curr = keyNode[key];
            updateFreqList(curr);
            return curr->value;
        }
        return -1;
    }

    void put(int data, int value)
    {
        if (capacity == 0)
            return;
        else if (keyNode.find(data) != keyNode.end())
        {
            Node *node = keyNode[data];
            node->value = value;
            updateFreqList(node);
        }
        else
        {
            if (keyNode.size() == capacity)
            {
                List *list = freqList[minFreq];
                keyNode.erase(list->tail->prev->data);
                list->deleteNode(list->tail->prev);
            }
            Node *node = new Node(data, value);
            minFreq = 1;
            List *list = new List();
            if (freqList.find(minFreq) != freqList.end())
                list = freqList[minFreq];
            list->addFront(node);
            freqList[minFreq] = list;
            keyNode[data] = node;
        }
    }
};

