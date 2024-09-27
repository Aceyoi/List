//Сапожников Юрий ИВТ-22
#pragma once

#include <iostream>
using namespace std;

// Шаблонный узел списка
template <typename T>
class Node {
public:
    T data;         // Данные узла (шаблонный тип)
    Node* next;     // Указатель на следующий узел

    Node(T val) : data(val), next(nullptr) {}
};

// Шаблонный класс односвязного списка
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Указатель на голову списка

public:
    // Конструктор
    LinkedList() : head(nullptr) {}

    // Деструктор для очистки памяти
    ~LinkedList() {
        clear();
    }

    // Функция добавления элемента в конец списка
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
        cout << "Элемент " << value << " добавлен в список.\n";
    }

    // Функция поиска элемента по значению
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

    // Функция удаления элемента по значению
    void remove(T value) {
        if (head == nullptr) {
            cout << "Список пуст.\n";
            return;
        }

        if (head->data == value) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
            cout << "Элемент " << value << " удален из списка.\n";
            return;
        }

        Node<T>* temp = head;
        while (temp->next != nullptr && temp->next->data != value) {
            temp = temp->next;
        }

        if (temp->next == nullptr) {
            cout << "Элемент " << value << " не найден.\n";
        }
        else {
            Node<T>* nodeToDelete = temp->next;
            temp->next = temp->next->next;
            delete nodeToDelete;
            cout << "Элемент " << value << " удален из списка.\n";
        }
    }

    // Функция очистки списка
    void clear() {
        Node<T>* temp;
        while (head != nullptr) {
            temp = head;
            head = head->next;
            delete temp;
        }
        cout << "Список очищен.\n";
    }

    // Функция вывода списка
    void print() {
        if (head == nullptr) {
            cout << "Список пуст.\n";
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