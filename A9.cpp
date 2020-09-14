#include <iostream>
using namespace std;
template <class T>
class Set;
template <class T>
class Node
{
    T data;
    Node *next;

public:
    Node()
    {
        data = 0;
        next = NULL;
    }
    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
    friend class Set<T>;
};
template <class T>
class Set
{
    Node<T> *head;
    Node<T> *tail;
    int length;

public:
    Set()
    {
        length = 0;
        head = NULL;
        tail = NULL;
    }
    void create();
    void insert(T element);
    void remove(T element);
    void showSet();
    void search(T element);
    int giveLength();
    Set<T> intersection(Set &s1, Set &s2);
    Set<T> unionSet(Set &s1, Set &s2);
    Set<T> difference(Set &s1, Set &s2);
    bool subSet(Set &s2);
};
template <class T>
bool Set<T>::subSet(Set &s2)
{
    int count = 0;
    for (Node<T> *current1 = head; current1 != NULL; current1 = current1->next)
        for (Node<T> *current2 = s2.head; current2 != NULL; current2 = current2->next)
            if (current1->data == current2->data)
                count++;
    if (count == s2.length)
        return 1;
    else
        return 0;
}
template <class T>
Set<T> Set<T>::unionSet(Set &s1, Set &s2)
{
    Set<T> s3;
    for (Node<T> *current1 = s1.head; current1 != NULL; current1 = current1->next)
        s3.insert(current1->data);
    for (Node<T> *current1 = s2.head; current1 != NULL; current1 = current1->next)
    {
        bool flag = 0;
        for (Node<T> *current2 = s3.head; current2 != NULL; current2 = current2->next)
        {
            if (current1->data == current2->data)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            s3.insert(current1->data);
    }
    return s3;
}
template <class T>
Set<T> Set<T>::difference(Set &s1, Set &s2)
{
    Set<T> s3;
    for (Node<T> *current1 = s1.head; current1 != NULL; current1 = current1->next)
    {
        bool flag = 0;
        for (Node<T> *current2 = s2.head; current2 != NULL; current2 = current2->next)
        {
            if (current1->data == current2->data)
            {
                flag = 1;
                break;
            }
        }
        if (flag == 0)
            s3.insert(current1->data);
    }
    return s3;
}
template <class T>
Set<T> Set<T>::intersection(Set &s1, Set &s2)
{
    Set<T> s3;
    for (Node<T> *current1 = s1.head; current1 != NULL; current1 = current1->next)
        for (Node<T> *current2 = s2.head; current2 != NULL; current2 = current2->next)
            if (current1->data == current2->data)
                s3.insert(current1->data);
    return s3;
}
template <class T>
int Set<T>::giveLength()
{
    return length;
}
template <class T>
void Set<T>::search(T element)
{
    for (Node<T> *current = head; current != NULL; current = current->next)
        if (current->data == element)
        {
            cout << "ELEMENT PRESENT!" << endl;
            return;
        }
    cout << "ELEMENT NOT FOUND!" << endl;
}
template <class T>
void Set<T>::create()
{
    cout << "ENTER NUMBER OF ELEMENTS:";
    int num;
    cin >> num;
    while (num--)
    {
        cout << "ENTER THE ELEMENT :";
        T element;
        cin >> element;
        insert(element);
    }
}
template <class T>
void Set<T>::insert(T element)
{
    if (head == NULL)
        head = tail = new Node<T>(element);
    else
    {
        tail->next = new Node<T>(element);
        tail = tail->next;
    }
    length++;
}
template <class T>
void Set<T>::remove(T element)
{
    if (head == NULL)
    {
        cout << "UnderFlow!" << endl;
        return;
    }
    if (head->data == element)
    {
        Node<T> *tmp = head;
        head = head->next;
        delete tmp;
    }
    Node<T> *current = NULL;
    for (current = head; current->next != NULL; current = current->next)
        if (current->next->data == element)
            break;
    Node<T> *tmp = current->next;
    current->next = current->next->next;
    delete tmp;
}
template <class T>
void Set<T>::showSet()
{
    cout << "THE SET:" << endl;
    if (head == NULL)
        cout << "UnderFlow!" << endl;
    else
        for (Node<T> *current = head; current != NULL; current = current->next)
            cout << current->data << endl;
}
template <class T>
void switchCase(Set<T> &s1, Set<T> &s2, Set<T> &s3)
{
    cout << "S1 :" << endl;
    s1.create();
    cout << "S2 :" << endl;
    s2.create();
    int choice;
    T element;
    do
    {
        cout << "\n***** SET OPERATIONS *****"
             << "\n1.Insert"
             << "\n2.Remove"
             << "\n3.Search"
             << "\n4.Size of Set"
             << "\n5.Intersection"
             << "\n6.Union"
             << "\n7.Difference"
             << "\n8.Check if Subset"
             << "\n9.EXIT"
             << "\nEnter Your Choice: ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "\nEnter Element: ";
            cin >> element;
            int ch;
            cout << "1.SET 1" << endl
                 << "2.SET 2" << endl;
            cin >> ch;
            if (ch == 1)
                s1.insert(element);
            else
                s2.insert(element);
            s1.showSet();
            s2.showSet();
            break;
        case 2:
            cout << "\nEnter Element: ";
            cin >> element;
            cout << "1.SET 1" << endl
                 << "2.SET 2" << endl;
            cin >> ch;
            if (ch == 1)
                s1.remove(element);
            else
                s2.remove(element);
            s1.showSet();
            s2.showSet();
            break;
        case 3:
            cout << "\nEnter Element: ";
            cin >> element;
            cout << "1.SET 1" << endl
                 << "2.SET 2" << endl;
            cin >> ch;
            if (ch == 1)
                s1.search(element);
            else
                s2.search(element);
            break;
        case 4:
            cout << "1.SET 1" << endl
                 << "2.SET 2" << endl;
            cin >> ch;
            if (ch == 1)
                cout << "\nSize = " << s1.giveLength();
            else
                cout << "\nSize = " << s2.giveLength();
            break;
        case 5:
            s3 = s1.intersection(s1, s2);
            cout << "\nSET 1's elements: ";
            s1.showSet();
            cout << "\nSET 2's elements: ";
            s2.showSet();
            cout << "\nIntersection: :";
            s3.showSet();
            break;

        case 6:

            s3 = s1.unionSet(s1, s2);
            cout << "\nSET 1's elements: ";
            s1.showSet();
            cout << "\nSET 2's elements: ";
            s2.showSet();
            cout << "\nUnion :";
            s3.showSet();
            break;
        case 7:
            s3 = s1.difference(s1, s2);
            cout << "\nSET 1's elements: ";
            s1.showSet();
            cout << "\nSET 2's elements: ";
            s2.showSet();
            cout << "\nDifference :";
            s3.showSet();
            break;
        case 8:
            cout << "SubSet? ";
            if (s1.subSet(s2))
                cout << "YES" << endl;
            else
                cout << "NO" << endl;
            break;
        case 9:
            choice = 0;
            break;
        default:
            cout << "WRONG CHOICE!" << endl;
        }
    } while (choice != 0);
}
int main()
{
    cout << "ENTER CHOICE: \n";
    cout << "1.INT\n";
    cout << "2.FLOAT\n";
    cout << "3.CHAR\n";
    cout << "4.STRING";
    int choice = 0;
    cin >> choice;
    if (choice == 1)
    {
        Set<int> s1, s2, s3;
        switchCase(s1, s2, s3);
    }
    else if (choice == 2)
    {
        Set<float> s1, s2, s3;
        switchCase(s1, s2, s3);
    }
    else if (choice == 3)
    {
        Set<char> s1, s2, s3;
        switchCase(s1, s2, s3);
    }
    else if (choice == 4)
    {
    Set<string> s1, s2, s3;
    switchCase(s1, s2, s3);
    }
    else
    {
        cout << "WRONG CHOICE!";
        exit(0);
    }
    return 0;
}