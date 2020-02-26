#include <iostream>

class ListNode
{
public:
    int data;
    ListNode* next;
    ListNode* prev;

    ListNode() :
        data(0),
        next(NULL),
        prev(NULL)
    {}
};

ListNode* reverseList( ListNode* head )
{
    ListNode* newHead = head;
    ListNode* _prev;
    ListNode* _next;

    while (newHead!=NULL) {
        _prev = newHead->prev;
        _next = newHead->next;
        
        newHead->prev = _next;
        newHead->next = _prev;
        
        newHead = _next;
    }
    
    return _prev->prev;
}

// Example function that calls reverseList.
ListNode* doSomeWork()
{
    ListNode* listHead = new ListNode[5];
    for( int i=0; i<5; i++ )
    {
        listHead[i].data = i;
        listHead[i].next = ( i < 4 ) ? listHead + i + 1 : NULL;
        listHead[i].prev = ( i > 0 ) ? listHead + i - 1 : NULL;
    }

    listHead = reverseList( listHead );
    return listHead;
}

int main()
{
    ListNode* listHead = doSomeWork();
    
    while (listHead!=NULL) {
        std::cout << listHead->data << " ";
        listHead = listHead->next;
    }

    return 0;
}
