//
//  array.hpp
//  Lab 4
//
//  Created by Зухраб Асаханов on 03.12.2022.
//  Copyright © 2022 Зухраб Асаханов. All rights reserved.
//

#ifndef array_hpp
#define array_hpp

#include <iostream>
#include <typeinfo>
#include <string>

template <typename T, size_t size>
class MyArray
{
    private:
        T myArray[size];
    
    public:
        //constructors
        MyArray() = default;
        ~MyArray() = default;
    
    
        //setters...
    
    
        //getters
        std::string getType() const { return typeid(T).name(); }
        int getSize() const { return size; }
    
    
        //base methods
        T Front() const
        {
            return myArray[0];
        }
    
        T Back() const
        {
            return myArray[size - 1];
        }
    
        void Fill(T value)
        {
            for (int i = 0; i < size; i++)
                myArray[i] = value;
        }

        const T& At(int number) const
        {
            if (number >= size || number < 0)
                throw std::out_of_range("\nThe number must be in the range.\nIt doesn't happen");
            return myArray[number];
        }
    
        T& At(int number)
        {
            if (number >= size || number < 0)
                throw std::out_of_range("\nThe number must be in the range.\nIt doesn't happen");
            return myArray[number];
        }
    
        
        //additional methods
    
//        T* Data() const
//        {
//            return &myArray[0];
//        }
    
        bool Empty() const
        {
            if(size == 0)
                return true;
            else
                return false;
        }
    
        void Swap(MyArray& obj) const
        {
            
        }
        
        MyArray Select(T& At(int number))
        {
            MyArray<int, size> result;
            for(int i = 0; i < size; i++)
                result[i] = myArray.At(i);
            
        }
        
    
        //overloaders
        MyArray& operator [](size_t lv) const
        {
            return myArray [lv];
        }
    
        MyArray& operator =(const MyArray& obj)
        {
            delete[] myArray;
            size = obj.getSize();
            
            for(int i = 0; i < size; i++)
                myArray[i] = obj[i];
            
            return *this->myArray;
        }
};

#endif /* array_hpp */
