/**
 *  @file    obj_parser_test.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include "obj_parser_test.h"
#include <libKitsunemimiObj/obj_item.h>

ObjParser_Test::ObjParser_Test()
    : Kitsunemimi::CompareTestHelper("ObjParseTest")
{
    parse_test();
}

/**
 * @brief parse_test
 */
void
ObjParser_Test::parse_test()
{
    Kitsunemimi::Obj::obj_item restult;
    bool ret = Kitsunemimi::Obj::objParse(restult, getTestString());
    TEST_EQUAL(ret, true);

    TEST_EQUAL(restult.vertizes.at(0).x, 2.0f);
    TEST_EQUAL(restult.vertizes.at(6).y, 1.0f);

    TEST_EQUAL(restult.normals.at(1).y, 1.0f);
    TEST_EQUAL(restult.normals.at(4).x, -1.0f);

    TEST_EQUAL(restult.faces.at(0).at(0).id1, 1);
    TEST_EQUAL(restult.faces.at(1).at(1).id3, 2);
}

/**
 * @brief get a test-string
 * @return test-string
 */
const std::string
ObjParser_Test::getTestString()
{
    return std::string("v 2.000000 -1.000000 -1.000000\n"
                       "v 1.000000 -1.000000 1.000000\n"
                       "v -1.000000    -1.000000 1.000000\n"
                       "v -1.000000 -1.000000 -1.000000\n"
                       "v     1.000000 1.000000 -0.999999\n"
                       "v 0.999999 1.000000 1.000001\n"
                       "v -1.000000 1.000000 1.000000\n"
                       "v -1.000000    1.000000 -1.000000\n"
                       "\n"
                       "vn 0.0000 -1.0000 0.0000\n"
                       "vn \t    0.0000 1.0000 0.0000\n"
                       "vn 1.0000 0.0000 0.0000\n"
                       "vn -0.0000 -0.0000 1.0000\n"
                       "vn -1.0000 -0.0000 -0.0000\n"
                       "vn 0.0000 0.0000 -1.0000\n"
                       "\n"
                       "f  \t  1//1 2//1 3//1 4//1\n"
                       "f 5//2 8//2   7//2 6//2\n"
                       "f 1//3 5//3 6//3 2//3\n"
                       "f 2//4 6//4 7//4 3//4\n"
                       "f 3//5 7//5 8//5 4//5\n"
                       "f 5//6   1//6 4//6 8//6\n");
}
