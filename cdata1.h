#ifndef CDATA1_H
#define CDATA1_H

#include "cdata.h"

//int comp (const int* a, int* b)
//{
//    if((((*a)&0xFF000000)>>24) < (((*b)&0xFF000000)>>24))
//    {
//        return -1;
//    }
//    else if ((((*a)&0xFF000000)>>24) == (((*b)&0xFF000000)>>24))
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//}

int comp1(const int* a, const int* b)
{
    char aTemp = (*a)&0xFF000000>>24;
    char bTemp = (*b)&0xFF000000>>24;
    if(aTemp < bTemp)
    {
        return -1;
    }
    else if (aTemp == bTemp)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}

class CData1 : public CData
{
    public:

        CData1(const CData &obj) : CData(obj)
        {    
            return;            
        }

        CData1(int len) : CData (len)
        {
            if(numbers != nullptr)
            numbers[0] = 1;
        }

        virtual void sort() override
        {
            qsort(numbers, len, sizeof (int), (int(*) (const void *, const void *)) comp1);
        }

        CData1 operator+(const CData1 &obj)
        {
            int lenTemp = len + obj.len;
            CData1 temp (lenTemp);

            for(int i = 0; i < len; i++)
            {
                temp.numbers[i] = numbers[i];
            }
            for(int i = 0; i < obj.len; i ++)
            {
                temp.numbers[i + len] = obj.numbers[i];
            }

            temp.sort();

            return temp;
        }
};

#endif // CDATA1_H
