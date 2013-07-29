#include <QString>
#include <QtTest>
#include "chinesenumber.h"

class ChineseNumberTest : public QObject
{
    Q_OBJECT
    
public:
    ChineseNumberTest();
    
private Q_SLOTS:
    void testCaseSimplifiedNumber();
    void testCaseSimplifiedNumber_data();


    void testCaseFormalSimplifiedNumber();
    void testCaseFormalSimplifiedNumber_data();

    void testCaseFormalSimplifiedPrice();
    void testCaseFormalSimplifiedPrice_data();
};

ChineseNumberTest::ChineseNumberTest()
{

}

void ChineseNumberTest::testCaseSimplifiedNumber()
{
    QFETCH(double, number);
    QFETCH(QString, result);
    QCOMPARE(ChineseNumber::doubleToChineseNumber(number),result);

}

void ChineseNumberTest::testCaseSimplifiedNumber_data()
{
    QTest::addColumn<double>("number");
    QTest::addColumn<QString>("result");
    QTest::newRow("0.0")<<0.0<<"零";
    QTest::newRow("100.0")<<100.0<<"一百";
    QTest::newRow("0.01")<<0.01<<"点零一";
    QTest::newRow("100000.0")<<100000.0<<"一十万";
    QTest::newRow("19073.1")<<19073.1<<"一万九千零七十三点一";
    QTest::newRow("23432.65")<<23432.65<<"二万三千四百三十二点六五";
    QTest::newRow("1000.0")<<1000.0<<"一千";
    QTest::newRow("35754249.73")<<35754249.73<<"三千五百七十五万四千二百四十九点七三";
    QTest::newRow("-5.0")<<-5.0<<"负数";
    QTest::newRow("100000000.0")<<100000000.0<<"过大";
}

void ChineseNumberTest::testCaseFormalSimplifiedNumber()
{
    QFETCH(double, number);
    QFETCH(QString, result);
    QCOMPARE(ChineseNumber::doubleToChineseNumber(number,true),result);

}
// oracle : http://www.mandarintools.com/numbers.html
void ChineseNumberTest::testCaseFormalSimplifiedNumber_data()
{
    QTest::addColumn<double>("number");
    QTest::addColumn<QString>("result");
    QTest::newRow("0.0")<<0.0<<"零";
    QTest::newRow("100.0")<<100.0<<"壹佰";
    QTest::newRow("0.01")<<0.01<<"点零壹";
    QTest::newRow("100000.0")<<100000.0<<"壹拾万";
    QTest::newRow("19073.1")<<19073.1<<"壹万玖仟零柒拾叁点壹";
    QTest::newRow("23432.65")<<23432.65<<"贰万叁仟肆佰叁拾贰点陆伍";
    QTest::newRow("1000.0")<<1000.0<<"壹仟";
    QTest::newRow("35754249.73")<<35754249.73<<"叁仟伍佰柒拾伍万肆仟贰佰肆拾玖点柒叁";
    QTest::newRow("-5.0")<<-5.0<<"负数";
    QTest::newRow("100000000.0")<<100000000.0<<"过大";
}


void ChineseNumberTest::testCaseFormalSimplifiedPrice()
{
    QFETCH(double, number);
    QFETCH(QString, result);
    QCOMPARE(ChineseNumber::doubleToChineseNumber(number,true,true),result);

}

void ChineseNumberTest::testCaseFormalSimplifiedPrice_data()
{
    QTest::addColumn<double>("number");
    QTest::addColumn<QString>("result");
    QTest::newRow("0.0")<<0.0<<"零元";
    QTest::newRow("100.0")<<100.0<<"壹佰元";
    QTest::newRow("0.01")<<0.01<<"零壹角";
    QTest::newRow("100000.0")<<100000.0<<"壹拾万元";
    QTest::newRow("19073.1")<<19073.1<<"壹万玖仟零柒拾叁元壹角";
    QTest::newRow("23432.65")<<23432.65<<"贰万叁仟肆佰叁拾贰元陆伍角";
    QTest::newRow("1000.0")<<1000.0<<"壹仟元";
    QTest::newRow("35754249.73")<<35754249.73<<"叁仟伍佰柒拾伍万肆仟贰佰肆拾玖元柒叁角";
    QTest::newRow("-5.0")<<-5.0<<"负数";
    QTest::newRow("100000000.0")<<100000000.0<<"过大";
}

QTEST_APPLESS_MAIN(ChineseNumberTest)

#include "tst_chinesenumbertest.moc"
