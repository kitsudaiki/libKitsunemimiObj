/**
 *  @file    objConverterTest.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include "objConverterTest.h"
#include <obj_item.h>
#include <jsonItems.hpp>

ObjConverterTest::ObjConverterTest(): Kitsune::CommonTest("ObjConverterTest")
{
    initTestCase();

    testInput();

    cleanupTestCase();
}

void ObjConverterTest::initTestCase()
{
    m_converter = new Kitsune::Obj::KitsuneObjConverter();

    m_testObjString = std::string("v 2.000000 -1.000000 -1.000000"
                                  "v 1.000000 -1.000000 1.000000"
                                  "v -1.000000 -1.000000 1.000000"
                                  "v -1.000000 -1.000000 -1.000000"
                                  "v 1.000000 1.000000 -0.999999"
                                  "v 0.999999 1.000000 1.000001"
                                  "v -1.000000 1.000000 1.000000"
                                  "v -1.000000 1.000000 -1.000000"
                                  "vn 0.0000 -1.0000 0.0000"
                                  "vn 0.0000 1.0000 0.0000"
                                  "vn 1.0000 0.0000 0.0000"
                                  "vn -0.0000 -0.0000 1.0000"
                                  "vn -1.0000 -0.0000 -0.0000"
                                  "vn 0.0000 0.0000 -1.0000"
                                  "f 1//1 2//1 3//1 4//1"
                                  "f 5//2 8//2 7//2 6//2"
                                  "f 1//3 5//3 6//3 2//3"
                                  "f 2//4 6//4 7//4 3//4"
                                  "f 3//5 7//5 8//5 4//5"
                                  "f 5//6 1//6 4//6 8//6");
}

void ObjConverterTest::testInput()
{
    std::pair<Kitsune::Json::JsonItem*, bool> result = m_converter->convert(m_testObjString);

    UNITTEST(result.second, true);
    Kitsune::Json::JsonObject* obj = dynamic_cast<Kitsune::Json::JsonObject*>(result.first);
    UNITTEST(obj->get("v")->get(0)->get(0)->toValue()->toFloat(), 2.0f);
    UNITTEST(obj->get("v")->get(0)->get(1)->toValue()->toFloat(), -1.0f);
}

void ObjConverterTest::cleanupTestCase()
{
    delete m_converter;
}
