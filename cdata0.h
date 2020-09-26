#ifndef CDATA0_H
#define CDATA0_H

#include "cdata.h"

//int comp1(int a, int b)
//{
//    if((((a)&0xFF000000)>>24) < (((b)&0xFF000000)>>24))
//    {
//        return -1;
//    }
//    else if ((((a)&0xFF000000)>>24) == (((b)&0xFF000000)>>24))
//    {
//        return 0;
//    }
//    else
//    {
//        return 1;
//    }
//}


int comp0 (int a, int b)
{
    char aTemp = a&0xFF000000>>24;
    char bTemp = b&0xFF000000>>24;
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

class CData0 : public CData
{
    public:

        CData0(int len) : CData (len)
        {
            if(numbers != nullptr)
                numbers[0] = 0;
        }

        CData0(const CData &obj) : CData(obj)
        {
            return;
        }

        virtual void sort() override
        {
            for (int i = 0; i < len - 1; i++)
            {
                for (int j = 0; j < len - i - 1; j++)
                {
                    if (comp0(numbers[j], numbers[j + 1]) > 0)
                    {
                        int temp = numbers[j];
                        numbers[j] = numbers[j + 1];
                        numbers[j + 1] = temp;
                    }
                }
            }
        }

        CData0 operator+(const CData0 &obj)
        {
            int lenTemp = len + obj.len;
            CData0 temp (lenTemp);

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



#endif // CDATA0_H
