/**
 *  @file    main.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include <obj_parser_test.h>

#include <libKitsunemimiPersistence/logger/logger.h>

int main()
{
    Kitsunemimi::Persistence::initConsoleLogger(true);

    ObjParser_Test test1;
}
