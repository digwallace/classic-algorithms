#ifndef __ARRAYLIST_INCLUDED__
#define __ARRAYLIST_INCLUDED__

class ArrayList{
  
    public:
        int     length;
        int     last;
        int     objectSize;
        void*   array;
        
        ArrayList();
        ArrayList(int size, void* element);
        
        bool add(void* element);
        void add(int index, void* element);
        bool addAll(void* startOfList);
        void clear();
        bool contains(void* element);
        void ensureCapacity(int minCapacity);
        //void forEach(action);
        void* get(int index);
        int indexOf(void* element);
        bool isEmpty();
        //Iterator<E> iterator();
        int lastIndexOf(void* element);
        //Iterator<E> listIterator();
        //Iterator<E> listIterator(int startingIndex);
        void* remove(int index);
        bool remove(void* element);
        bool removeAll(void* start, int count);
        //bool removeIf(Predicate<? super E> filter);
        void removeRance(int fromIndex, int toIndex);
        //void replaceAll(UnaryOperator<E> operator);
        bool retainAll(void* start, int count);
        void* set(int index, void* element);
        int size()
        //void sort(Comparator<? super E> c);
        void* subList(int fromIndex, int toIndex);
        void* toArray();
        void trimToSize();
        
    private:
    
        int increaseSize();
    
};

#endif