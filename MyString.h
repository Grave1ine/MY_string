#ifndef MYSTRING_H
#define MYSTRING_H

#include <cstdlib>
#include <ostream>

class String
{
    public:
        String();                                       //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ Р±РµР· РїР°СЂР°РµС‚СЂРѕРІ
        String(const String & name);                    //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РєРѕРїРёСЂРѕРІР°РЅРёСЏ
        String(String && name);                         //РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїРµСЂРµРјРµС‰РµРЅРёСЏ (Р·Р°Р±СЂР°С‚СЊ РёР· РІСЂРµРјРµРЅРЅРѕРіРѕ РѕР±СЉРµРєС‚Р°)
        String(const char * name);                      //РїСЂРёРЅРёРјР°РµС‚ РЎРёСЃС‚СЂРѕРєСѓ
        ~String();                                      //РґРёСЃС‚СЂСѓРєС‚РѕСЂ

        /*РєРѕРЅСЃС‚СЂСѓРєС‚РѕСЂ РїСЂРёРЅРёРјР°СЋС‰РёР№ РЎРё СЃС‚СЂРѕРєСѓ, РјРµС‚РѕРґ РІРѕР·РІСЂР°С‰Р°СЋС‰РёР№ РЎРё СЃС‚СЂРѕРєСѓ, РјРµС‚РѕРґ РєРѕРЅРєР°С‚РµРЅР°С†РёРё*/

        size_t size() const;
        size_t capacity() const;

        void push_back(char value);                         //РґРѕР±Р°РІРёС‚СЊ РІ РєРѕРЅРµС† СЃС‚СЂРѕРєРё
        char *get_C_str() const;                            //Вывод строки. const не модифицирует поля
        size_t get_size();
        void concatenation(const char *value);
        void concatenation(const String &);
        char operator[](size_t value) const;                //РћРїРµСЂР°С‚РѕСЂ[] СЂР°Р±РѕС‚Р°РµС‚ РєР°Рє РјРµС‚РѕРґ РєР»Р°СЃСЃР° (РІ РґР°РЅРЅРѕРј СЃР»СѓС‡Р°Рµ Р±СЂР°С‚СЊ Р·РЅР°С‡РµРЅРёСЏ)
    private:
        size_t _size;                                       //size_t СЌС‚Рѕ unsigned int
        size_t _capacity;
        char * _data;                                       //СѓРєР°Р·Р°С‚РµР»СЊ С‚РёРїР° char?

        friend std::ostream & operator << (std::ostream &os, const String &value);
};

inline std::ostream & operator << (std::ostream &os, const String &value)
{
    os << value._data;
    return os;
}

#endif // MYSTRING_H
