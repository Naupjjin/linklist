#include <bits/stdc++.h>
#define int long long

struct Node {
    int data;
    Node* next;

    Node(int val) : data(val), next(nullptr) {}
};

class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    // 在連結列表的頭部插入節點
    void insertAtHead(int n) {
        Node* newNode = new Node(n);
        newNode->next = head;
        head = newNode;
    }

    // 在連結列表的尾部插入節點
    void insertAtTail(int n) {
        Node* newNode = new Node(n);
        if (!head) {
            head = newNode;
            return;
        }
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }

    // 在節點a前插入整數n
    void insertBefore(int n, int a) {
        if (!head) {
            std::cout << "peko" << std::endl;
            return;
        }

        Node* newNode = new Node(n);
        if (head->data == a) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == a) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        std::cout << "peko" << std::endl;
    }

    // 在節點a後插入整數n
    void insertAfter(int n, int a) {
        if (!head) {
            std::cout << "peko" << std::endl;
            return;
        }

        Node* newNode = new Node(n);
        Node* current = head;
        while (current) {
            if (current->data == a) {
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        }

        std::cout << "peko" << std::endl;
    }

    // 印出節點a前面的整數
    void printBefore(int a) {
        if (!head) {
            std::cout << "peko" << std::endl;
            return;
        }

        if (head->data == a) {
            std::cout << "NULL" << std::endl;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == a) {
                std::cout << current->data << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "peko" << std::endl;
    }

    // 印出節點a後面的整數
    void printAfter(int a) {
        if (!head) {
            std::cout << "peko" << std::endl;
            return;
        }

        Node* current = head;
        while (current) {
            if (current->data == a && current->next) {
                std::cout << current->next->data << std::endl;
                return;
            }
            current = current->next;
        }

        std::cout << "peko" << std::endl;
    }

    // 刪除節點a
    void deleteNode(int a) {
        if (!head) {
            std::cout << "peko" << std::endl;
            return;
        }

        if (head->data == a) {
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        Node* current = head;
        while (current->next) {
            if (current->next->data == a) {
                Node* temp = current->next;
                current->next = current->next->next;
                delete temp;
                return;
            }
            current = current->next;
        }

        std::cout << "peko" << std::endl;
    }

private:
    Node* head;
};

signed main() {
    
    int m;
    std::cin >> m;
    
    LinkedList list;

    for (int i = 0; i < m; ++i) {
        int cmd;
        std::cin >> cmd;

        if (cmd == 1) {
            int n;
            std::cin >> n;
            list.insertAtHead(n);
        } else if (cmd == 2) {
            int n;
            std::cin >> n;
            list.insertAtTail(n);
        } else if (cmd == 3) {
            int n, a;
            std::cin >> n >> a;
            list.insertBefore(n, a);
        } else if (cmd == 4) {
            int n, a;
            std::cin >> n >> a;
            list.insertAfter(n, a);
        } else if (cmd == 5) {
            int a;
            std::cin >> a;
            list.printBefore(a);
        } else if (cmd == 6) {
            int a;
            std::cin >> a;
            list.printAfter(a);
        } else if (cmd == 7) {
            int a;
            std::cin >> a;
            list.deleteNode(a);
        }
    }

    return 0;
}
