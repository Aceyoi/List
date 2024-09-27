//���������� ���� ���-22
#pragma once

#include <iostream>
using namespace std;

// ��������� ���� ������
template <typename T>
class Node {
public:
    T data;         // ������ ���� (��������� ���)
    Node* next;     // ��������� �� ��������� ����

    Node(T val) : data(val), next(nullptr) {}
};

// ��������� ����� ������������ ������
template <typename T>
class LinkedList {
private:
    Node<T>* head; // ��������� �� ������ ������

public:
    // �����������
    LinkedList() : head(nullptr) {}

    // ���������� ��� ������� ������
    ~LinkedList() {
        clear();
    }

    // ������� ���������� �������� � ����� ������
    void append(T value) {
        Node<T>* newNode = new Node<T>(value);
        if (head == nullptr) {
            head = newNode;
        }
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        cout << "������� " << value << " �������� � ������.\n";
    }

    // ������� ������ �������� �� ��������
    bool search(T value) {
        Node<T>* temp = head;
        while (temp != nullptr) {
            if (temp->data == value) {
                return true;
            }
            temp = temp->next;
        }
        return false;
    }

    // ������� �������� �������� �� ��������
    void remove(T value) {
        if (head == nullptr) {
            cout << "������ ����.\n";
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            cout << "������� " << value << " ������ �� ������.\n";
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "������� " << value << " �� ������.\n";
        }
        else {
            Node<T>* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "������� " << value << " ������ �� ������.\n";
        }
    }

    // ������� ������� ������
    void clear() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "������ ������.\n";
    }

    // ������� ������ ������
    void print() {
        if (head == nullptr) {
            cout << "������ ����.\n";
            return;
        }

        Node<T>* temp = head;
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "nullptr\n";
    }
};