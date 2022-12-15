//
// Tomás Oliveira e Silva, AED, November 2021
//
// Generic queue (First In First Out) implementation based on an linked list
//

#ifndef _AED_lQueue_
#define _AED_lQueue_

#include "sList.h"
#include <cassert>

template <typename T>
class lQueue
{
  private:
  public:
    lQueue(void)
    {
      sList<int> fila;
    }
    ~lQueue(void)
    {
      delete fila;
    }
    void clear(void)
    {

    }
    int size(void) const
    {
      return fila.size();
    }
    int is_full(void) const
    {
      return (fila.size() == size());
    }
    int is_empty(void) const
    {
      return (fila.size() == 0);
    }
    void enqueue(T &v)
    {
    }
    T dequeue(void)
    {
    }
    T peek(void)
    {
    }
};

#endif
