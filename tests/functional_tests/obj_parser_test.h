/**
 *  @file    obj_parser_test.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef OBJPARSER_TEST_H
#define OBJPARSER_TEST_H

#include <libKitsunemimiCommon/test_helper/compare_test_helper.h>
#include <utility>
#include <string>
#include <vector>

class ObjParser_Test
        : public Kitsunemimi::CompareTestHelper
{

public:
    ObjParser_Test();

private:
    void parse_test();

    const std::string getTestString();
};

#endif // OBJPARSER_TEST_H
