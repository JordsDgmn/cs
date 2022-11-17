/*
CCC121 Laboratory Exercise No. 1
Due: November 20, 2022 (Sunday) at 11:55PM
*/

#include <iostream>
#include <assert.h>

using namespace std;

/*
The structure to be used for representing a doubly-linked link. This struct
declaration should not be modified in any way.
*/
template <class E>
struct DLink
{
    E theElement;
    DLink<E> *nextPtr;
    DLink<E> *prevPtr;
};

/*
Complete this implementation variant of the doubly-linked list. Use the same
convention as described in the slides. The DLink declaration to be used here is
just a struct and should not be modified in any way. All of the operations of
the original DLink class must be done in the methods of this class. Use
assertions to ensure the correct operation of this ADT. All memory allocations
should be checked with assertions and all discarded memory must be properly
deallocated.
*/
template <class E>
class DList
{
    DLink<E> *head;
    DLink<E> *tail;
    DLink<E> *curr;
    int cnt;

public:
    // Return the size of the list
    int length() const
    {
        return cnt;
    }

    // The constructor with initial list size
    DList(int size)
    {
        this();
    }

    // The default constructor
    DList()
    {
       head = new DLink<E>;
       tail = new DLink<E>;

       head->prevPtr = nullptr;
       head->nextPtr = tail;

       tail->prevPtr = head;
       tail->nextPtr = nullptr;

       curr = head;
       cnt = 0;
    }

    // The copy constructor
    DList(const DList &source)
    {
        head = source->head;
        tail = source->tail;
        curr = source->curr;
        cnt = source->cnt;
    }

    // The class destructor
    ~DList()
    {
        //
        // ??? - implement this method
        //
    }

    // Empty the list
    void clear()
    {
        curr = head->nextPtr;
        DLink<E> *temp;
        while (curr != tail)
        {
         
          delete ;    
          curr = temp
        }
    }

    // Set current to first element
    void moveToStart()
    {
        curr = head;
    }

    // Set current element to end of list
    void moveToEnd()
    {
        curr = tail;
    }

    // Advance current to the next element
    void next()
    {
        curr = curr->nextPtr;
    }

    // Return the current element
    E & getValue() const
    {
        return curr->nextPtr->theElement;
    }

    // Insert value at current position
    void insert(const E &it)
    {
        DLink<E> *newLink = new DLink<E>;
        newLink->theElement = it;
        newLink->prevPtr = curr;
        newLink->nextPtr = curr->nextPtr;

        curr->nextPtr->prevPtr = newLink;
        curr->nextPtr = newLink;

        cnt++;
    }


    // Append value at the end of the list
    void append(const E &it)
    {
        DLink<E> *newLink = new DLink<E>;
        newLink->theElement = it;
        newLink->nextPtr = tail;
        newLink->prevPtr = tail->prevPtr;

        tail->prevPtr->nextPtr = newLink;
        tail->prevPtr = newLink;
        
        cnt++;
    }

    // Remove and return the current element
    E remove()
    {
        //
        // ??? - implement this method
        //
    }

    // Advance current to the previous element
    void prev()
    {
        curr = curr->prevPtr;
    }

    // Return position of the current element
    int currPos() const
    {
       DLink<E> *temp = head;
       int i;
       for (i = 0; curr != temp; i++)
         temp = temp->nextPtr;
       return i;
    }

    // Set current to the element at the given position
    void moveToPos(int pos)
    {
        curr = head;
        for (int i = 0; i < pos; i++)
          curr = curr->nextPtr;
    }

  void debug()
  {
    cout << endl;
    
    DLink<E> *temp = head;

    cout << "CURRENT POINTER: ";
    if (temp == head)
        cout << "HEAD" << endl;
    else if (temp == tail)
        cout << "TAIL" << endl;
    else
        cout << endl;
    
    int index = 0;

    while (temp != nullptr)
    {
      cout << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << "| Index: " << index << endl;
      cout << "| PrevPtr: " << temp->prevPtr << endl;
      cout << "| [Ptr-Value]: " << temp << " - ";
      if (temp == head)
        cout << "HEAD" << endl;
      else if (temp == tail)
        cout << "TAIL" << endl;
      else
        cout << temp->theElement << endl;
      cout << "| NextPtr: " << temp->nextPtr << endl;
      cout << "|---------------------------------------------|" << endl;
      cout << endl;
      temp = temp->nextPtr;
      index++;
    }
  }
};

/*
This is the main function for testing the implementation of the DList class.
This function can be freely modified.
*/
int main(void)
{
    int i;
    DList<int> theList;

    theList.insert(2);
    theList.insert(1);
    theList.append(3);

    theList.debug();

    theList.moveToPos(1);

    cout << "CURRENT POSITION: " << theList.currPos() << endl;
    cout << "CURRENT VALUE: " << theList.getValue() << endl;

    // // populate the list
    // for (i = 0; i < 10; ++i)
    // {
    //     theList.append(i);
    // }
    // while (i < 20)
    // {
    //     theList.insert(i);

    //     ++i;
    // }

    // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     cout << theList.getValue() << " ";

    //     theList.next();
    // }
    // cout << "\n";

    // // display the contents of the list in reverse order
    // theList.moveToEnd();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     theList.prev();

    //     cout << theList.getValue() << " ";
    // }
    // cout << "\n";

    // // replace the contents of the list
    // theList.clear();
    // for (i = 0; i < 10; ++i)
    // {
    //     theList.append(i + 100);
    // }

    // // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     cout << theList.getValue() << " ";

    //     theList.next();
    // }
    // cout << "\n";

    // // remove two elements at the specified position
    // theList.moveToPos(5);
    // cout << theList.currPos() << "\n";

    // theList.remove();
    // theList.remove();

    // // display the contents of the list
    // theList.moveToStart();
    // for (i = 0; i < theList.length(); ++i)
    // {
    //     cout << theList.getValue() << " ";

    //     theList.next();
    // }
    // cout << "\n";

    return 0;
}
