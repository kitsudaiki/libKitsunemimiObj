/**
 *  @file    objConverterTest.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef OBJCONVERTERTEST_H
#define OBJCONVERTERTEST_H

#include <testing/commonTest.hpp>
#include <utility>
#include <string>
#include <vector>

namespace Kitsune
{
namespace Obj
{
class KitsuneObjConverter;
}
}

class ObjConverterTest: public Kitsune::CommonTest
{

public:
    ObjConverterTest();

private:
    Kitsune::Obj::KitsuneObjConverter* m_converter = nullptr;
    std::string m_testObjString;

    void initTestCase();

    void testInput();

    void cleanupTestCase();
};

#endif // OBJCONVERTERTEST_H
