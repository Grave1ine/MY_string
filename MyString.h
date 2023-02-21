#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <ostream>
#include <cstring>

class String
{
    public:
        String();                                       //Пустой конструктор инициализации полей
        String(const String & name);                    //Конструктор копирования
        String(String && name);                         //Конструктор перемещения (Р·Р°Р±СЂР°С‚СЊ РёР· РІСЂРµРјРµРЅРЅРѕРіРѕ РѕР±СЉРµРєС‚Р°)
        String(const char * name);                      //РїСЂРёРЅРёРјР°РµС‚ РЎРёСЃС‚СЂРѕРєСѓ
        ~String();                                      //РґРёСЃС‚СЂСѓРєС‚РѕСЂ

        /*РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїСЂРёРЅРёРјР°СЋС‰РёР№ РЎРё СЃС‚СЂРѕРєСѓ, РјРµС‚РѕРґ РІРѕР·РІСЂР°С‰Р°СЋС‰РёР№ РЎРё СЃС‚СЂРѕРєСѓ, РјРµС‚РѕРґ РєРѕРЅРєР°С‚РµРЅР°С†РёРё*/

        void push_back(char value);                         //РґРѕР±Р°РІРёС‚СЊ РІ РєРѕРЅРµС† СЃС‚СЂРѕРєРё
        char *get_C_str() const;                            //Вывод строки. const не модифицирует поля
        size_t get_size();
        void concatenation(const char * value);
        void concatenation(const String &);
        char operator[](size_t value) const;                //РћРїРµСЂР°С‚РѕСЂ[] СЂР°Р±РѕС‚Р°РµС‚ РєР°Рє РјРµС‚РѕРґ РєР»Р°СЃСЃР° (РІ РґР°РЅРЅРѕРј СЃР»СѓС‡Р°Рµ Р±СЂР°С‚СЊ Р·РЅР°С‡РµРЅРёСЏ)


        String & operator = (const String & word1)
        {
            if(_data == word1._data)
            {
                return *this;
            }
            delete _data;
            std::strcpy(_data, word1._data);
            _size = word1._size;
            _capacity = word1._capacity;
            return *this;
        }


    private:
        friend bool operator != (const String & wordLeft, const String & wordRight);
        friend bool operator < (const String & word1, const String & word2);
        friend bool operator == (const String & wordLeft, const String & wordRighr);

        size_t _size;                                       //size_t СЌС‚Рѕ unsigned int
        size_t _capacity;
        char * _data;                                       //СѓРєР°Р·Р°С‚РµР»СЊ С‚РёРїР° char?

        friend std::ostream & operator << (std::ostream &os, const String &value);    //пользовательским оператор потока вывода

};
inline bool operator != (const String & wordLeft, const String & wordRight)
{
    return std::strcmp(wordLeft._data, wordRight._data) != 0;
}

inline bool operator < (const String & word1, const String & word2)
{
    return word1._data < word2._data;
}

inline bool operator == (const String & wordLeft, const String & wordRighr)              //пользовательский оператор сравнения
{
    return std::strcmp(wordLeft._data, wordRighr._data) == 0;
}

inline std::ostream & operator << (std::ostream &os, const String &value)
{
    os << value._data;
    return os;
}


#endif // MYSTRING_H
