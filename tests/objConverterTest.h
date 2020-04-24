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

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>
#include <utility>
#include <string>
#include <vector>

class ObjParseTest
        : public Kitsunemimi::CompareTestHelper
{

public:
    ObjParseTest();

private:
    std::string m_testObjString;

    void initTestCase();

    void testInput();

    void cleanupTestCase();
};

#endif // OBJCONVERTERTEST_H
