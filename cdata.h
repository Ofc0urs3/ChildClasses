#ifndef CDATA_H
#define CDATA_H

#include<stdio.h>
#include<cstdlib>
#include<math.h>
#include<time.h>

class CData0;
class CData1;

class CData
{
    private:
        int *numbers;
        int len;

    public:
        CData(int len = 1); //+
        CData(const CData & obj); //+
        ~CData(); //+

        //virtual CData& operator+(const CData &obj) = 0;
        CData& operator=(const CData &obj);
        CData& operator=(CData &&obj);
        void print(FILE * output = stdout);//+
        virtual void sort() = 0;
        friend class CData0;
        friend class CData1;

};

CData::CData(int lenIn)
{
    len = lenIn;
    numbers = new int[len];

    for(int i = 0; i < len; i++)
    {
        int tmp = -128 + rand()%255;
        numbers[i] = tmp;// * int(pow(-1, tmp % 2));
    }
    numbers[len - 1] = 255;
}

CData::CData(const CData & obj)
{
    len = obj.len;
    numbers = new int[len];

    for(int i = 0; i < len; i++)
    {
        numbers[i] = obj.numbers[i];
    }
}


CData::~CData()
{
    delete []numbers;
}

CData& CData::operator=(const CData &obj)
{
    if(this != &obj)
    {
        if(numbers != nullptr) delete [] numbers;
        len = obj.len;
        numbers = new int[len];
        for(int i = 0; i < len; i++)
        {
            numbers[i] = obj.numbers[i];
        }
    }
    return *this;
}

CData& CData::operator=(CData &&obj)
{
    if(this != &obj)
    {
        if(numbers != nullptr)
        {
            delete [] numbers;
        }
        len = obj.len;
        numbers = obj.numbers;

        obj.len = 0;
        obj.numbers = nullptr;
    }
    return *this;
}





void CData::print(FILE* output)
{
    for(int i = 0; i < len; i ++)
    {
        fprintf(output, "%d ", numbers[i]);
    }
    fprintf(output, "\n");
}

#endif // CDATA_H

