#pragma once
#include <stdexcept>
#include <cstddef>

template <typename T>
class List
{
private:
    struct Node
    {
        Node(T value) : value(value), next(nullptr), prev(nullptr) {}
        T value;
        Node* next;
        Node* prev;
    };

    Node* head;
    Node* tail;
    size_t length;

public:
    List() noexcept : head(nullptr), tail(nullptr), length(0) {}

    ~List()
    {
        while (head != nullptr)
        {
            Node* tmp = head;
            head = head->next;
            delete tmp;
        }
    }

    bool empty() const noexcept
    {
       
        return head == nullptr; 
    }

    size_t size() const noexcept
    {
        return length;
    }

    void pushFront(T value)
    {
        Node* newNode = new Node(value);
        newNode->next = head;
        if (head != nullptr)
            head->prev = newNode;
        else
            tail = newNode;
        head = newNode;
        length++;
    }

    void pushBack(T value)
    {
        Node* newNode = new Node(value);
        newNode->prev = tail;
        if (tail != nullptr)
            tail->next = newNode;
        else
            head = newNode;
        tail = newNode;
        length++;
    }

    T popFront()
    {
        if (empty())
            throw std::runtime_error("List is empty, can't popFront.");

        Node* tmp = head;
        T value = tmp->value;
        head = head->next;
        if (head != nullptr)
            head->prev = nullptr;
        else
            tail = nullptr;
        delete tmp;
        length--;
        return value;
    }

    T popBack()
    {
        if (empty())
            throw std::runtime_error("List is empty, can't popBack.");

        Node* tmp = tail;
        T value = tmp->value;
        tail = tail->prev;
        if (tail != nullptr)
            tail->next = nullptr;
        else
            head = nullptr;
        delete tmp;
        length--;
        return value;
    }
};
