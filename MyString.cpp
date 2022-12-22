#include "MyString.h"
#include <iostream>
#include <cstring>


String::String():
    _size(0),
    _capacity(0),
    _data(nullptr)   //инициализация полей класса (в данном случае нулями)
{
    std::cout << "String()" << std::endl;
}

String::String(const String & name): _size(name._size), _capacity(name._capacity)//копирование?
{   //указатели копируются особым образом
    _data = new char[name._capacity];               //выделяется память размером с _capacity
    memcpy(_data, name._data, _size * sizeof(char));//[куда, откуда, размерность] сигнатура memcpy()
    std::cout << "String(const String & name)" << std::endl;
}

String::String(String && name):                 //перемещение?
    _size(name._size),                          //перемещение старых даннах
    _capacity(name._capacity),                  //
    _data(name._data)                           //перемещение указателя
{
    name._size = 0;                             //уничтожение старого объекта
    name._capacity = 0;                         //
    name._data = nullptr;                       //уничтожение старого указателя

    std::cout << "String(String && name)" << std::endl;
}

String::String(const char * value)                //принимает СИ строку
{
    _size = strlen(value);                        //получение и запись размера строки
    _data = new char[_size + 1];                  //выделение памяти размером с  _size + 1
    strcpy(_data, value);                         //запись value в _data
}

void String::concatenation(const char * value)
{
    _size = _size + strlen(value);
    char * temp = new char[_size + 1];
    strcpy(temp,_data);
    strcat(temp, value);                          //добавляет новое значение в конец строки
    delete [] _data;
    _data = temp;
}

void String::concatenation(const String & value)
{
    return concatenation(value.get_C_str());
}

/*
void String::concatenation(const String & value)
{
    _size = _size + value._size;
    char * temp = new char[_size + 1];
    strcpy(temp, _data);
    strcat(temp, value._data);
    delete [] _data;
    _data = temp;
}
*/

String::~String()
{
    delete [] _data;                              //удаление динамической памяти
    std::cout << "~String()" << std::endl;
}

void String::push_back(char value)                //запись в конец
{
    if(_capacity <= _size)
    {
        _capacity = _capacity * 2 + 1;
        char * tem = new char[_capacity];         //выделение новой памяти
        memcpy(tem, _data, _size * sizeof (char));//копирование старой памяти в новую
        delete [] _data;                          //удаляется старый указатель
        _data = tem;                              //присваение нового адреса в указатель
    }
    _data[_size] = value;
    ++ _size;                                     //увиличение занятой памяти?
    std::cout << "String::push_back" << "\t" << value << std::endl;
}

char *String::get_C_str() const                   //вывод строки?
{
    return _data;
}

size_t String::get_size()
{
    return _size;
}

char String::operator[](size_t value) const       //принимает значение??
{
    if(value < _size)
    {
        return _data[value];
    }
    return 0;
}
