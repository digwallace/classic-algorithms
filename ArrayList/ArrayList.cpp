#include "ArrayList.h"

ArrayList::ArrayList(){
    length = last = 0;
    array = NULL;
}

ArrayList::ArrayList(int size, void* element){
    array = malloc(size * sizeof(*element));
    length = size;
    array[0] = *element;
}

bool add(void* element){
    // TODO
    return false;
}

void add(int index, void* element){
    // TODO
    return;
}

bool addAll(void* startOfList){
    // TODO
    return false;
}

void clear(){
    for(int i = 0; i < size; i++){
        delete array[i];
    }
    return;
}

bool contains(void* element){
    for(int i = 0; i < size; i++){
        if (*element == array[i]){
            return true;
        }
    }
    return false;
}

void ensureCapacity(int minCapacity){
    while(minCapacity > size){
        increaseSize();
    }
    return;
}

//void forEach(action);

void* get(int index){
    if(index > size){
        return NULL;
    }
    return array[index];
}

int indexOf(void* element){
    for(int i = 0; i < size; i++){
        if(array[i] == *element){
            return i;
        }
    }        
    return -1;
}

bool isEmpty(){
    for(int i = 0; i < size; i++){
        if(array[i] != NULL){
            return false;
        }
    }
    return true;    
}

//Iterator<E> iterator();

int lastIndexOf(void* element){
    int lastIndex = -1
    for(int i = 0; i < size; i++){
        if(*element == array[i]){
            lastIndex = i;
        }
    }
    return lastIndex;
}

//Iterator<E> listIterator();

//Iterator<E> listIterator(int startingIndex);

void remove(int index){
    if(index < 0){
        return NULL;
    }
    
    for(int i = index; i < size; i++){
        if(i + 1 == size){
            array[i] = NULL;
        }
        array[i] = array[i+1]
    }
}

bool remove(void* element){
    if(*element == NULL){
        return false;
    }
    for(int i = 0; i < size; i++){
        if(array[i] == *element){
            remove(i);
            return true;
        }
    }
    return false;
}

bool removeAll(void* start, int count){
    bool status = false;
    for(int i = 0; i < count; i++){
        if(status == true){
            remove(i);
        }else{
            status = remove(i);
        }
    }
    
    return true;
}

//bool removeIf(Predicate<? super E> filter);

void removeRange(int fromIndex, int toIndex){
    // TODO
    return;
}

//void replaceAll(UnaryOperator<E> operator);

bool retainAll(void* start, int count){
    // TODO
    return false;
}

void* set(int index, void* element){
    // TODO
    return NULL;
}

int size(){
    // TODO
    return size;
}

//void sort(Comparator<? super E> c);

void* subList(int fromIndex, int toIndex){
    // TODO
    return NULL;
}

void* toArray(){
    // TODO
    return NULL;
}

void trimToSize(){
    // TODO
    return NULL;
}

void increaseSize(){
    
}
