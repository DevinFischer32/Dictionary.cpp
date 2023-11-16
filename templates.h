#include <iostream>
using namespace std;

template <typename TKey, TValue>
class Dictionary
{
private:
    struct Node
    {
        TKey key;
        TValue value;
        Node *next;
    };
    Node *head;

public:
    Dictionary(){};
    ~Dictionary()
    {
        Node *temp = head;
        while (temp != NULL)
        {
            Node *next = temp->next;
            delete temp;
            temp = next;
        }
    }
    void add(Tkey key, TValue value)
    {
        Node *temp = new Node;
        temp->key = key;
        temp->value = value;
        temp->next = head;
        Node *cur = head;
        Node *prev = cur;
        if (head == NULL)
        {
            head = temp;
            temp->next = NULL;
            return;
        }
        else
        {
            while (cur != NULL && cur->key < key)
            {
                prev = cur;
                cur = cur->next
            }
            if (cur == head)
            {
                temp->next = head;
                head = temp;
            }
            else
            {
                prev->next = temp;
                temp->next = cur;
            }
        }
    }
    TValue get(Tkey key)
    {
        Node *temp = head;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                return temp->value;
            }
            temp = temp->next;
        }
        return 0;
    }
    void remove(TKey key)
    {
        Node *temp = head;
        Node *prev = NULL;
        while (temp != NULL)
        {
            if (temp->key == key)
            {
                if (prev == NULL)
                {
                    head = temp->next;
                }
                else
                {
                    prev->next = temp->next;
                    delete temp;
                    return;
                }
            }
            prev = temp;
            temp = temp->next;
        }
    }
    TValue operator[](Tkey key)
    {
        return get(key);
    }
};
