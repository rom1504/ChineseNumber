#include <cmath>
#include <QDebug>

#include "chinesenumber.h"


namespace ChineseNumber
{
    namespace
    {
        int firstDigit(int n)
        {
            while(n/10!=0) n/=10;
            return n;
        }

        QMap<int,QString> simplifiedNumber {{0,"零"},{1,"一"},{2,"二"},{3,"三"},{4,"四"},{5,"五"},{6,"六"},{7,"七"},{8,"八"},{9,"九"},{10,"十"},{100,"百"},{1000,"千"},{10000,"万"}};
        QMap<int,QString> formalSimplifiedNumber {{0,"零"},{1,"壹"},{2,"贰"},{3,"叁"},{4,"肆"},{5,"伍"},{6,"陆"},{7,"柒"},{8,"捌"},{9,"玖"},{10,"拾"},{100,"佰"},{1000,"仟"},{10000,"万"}};


        QString numToChineseNumber_(int n,bool formal)  // on va supposer que le nombre est strictement inférieur à 10^8
        {
            QMap<int,QString> & number=formal ? formalSimplifiedNumber : simplifiedNumber;
            if(number.contains(n)) return number[n];
            int num=n;
            int p=1;
            while(num/10>0 && (p<10000))
            {
                num=num/10;
                p*=10;
            }
            int f=n-num*p;
            QString beginingNumber=num!=1 ? numToChineseNumber_(num,formal) : "";
            QString power=numToChineseNumber_(p,formal);
            QString zero=(f!=0 && (double)p/(double)f>10.0 ? numToChineseNumber_(0,formal) : "");
            QString finishingNumber=(f!=0 ? numToChineseNumber_(f,formal) : "");
            return beginingNumber+power+zero+finishingNumber;
        }

        QString numToChineseNumber(int n,bool formal)
        {
            if(n>=100000000) return "过大";
            if(n<0) return "负数";
            QString additionnalFirstDigit=n>10 && firstDigit(n)==1 ? numToChineseNumber(1,formal) : "";
            return additionnalFirstDigit+numToChineseNumber_(n,formal);
        }


        QString decToChineseNumber(int n,int precision,bool formal)
        {
            QString chineseNumber="";
            bool nonZeroAppeared=false;
            while(n!=0)
            {
                int a=n%10;
                if(a!=0 && !nonZeroAppeared) nonZeroAppeared=true;
                if(a!=0 || nonZeroAppeared) chineseNumber=numToChineseNumber(a,formal)+chineseNumber;
                n/=10;
                precision-=1;
            }
            for(int i=0;i<precision;i++) chineseNumber=numToChineseNumber(0,formal)+chineseNumber;
            return chineseNumber;
        }
    }

    QString doubleToChineseNumber(double d,bool formal)
    {
        int num=std::floor(d);
        int dec=round((d-(double)num)*100.0);
        return (num!=0 || dec==0 ? numToChineseNumber(num,formal) : "")+(dec!=0 ? ("点"+decToChineseNumber(dec,2,formal)) : "");
    }
}
