/**
 *  @file       main.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <obj_item_test.h>

#include <libKitsunemimiPersistence/logger/logger.h>

int main()
{
    Kitsunemimi::Persistence::initConsoleLogger(true);

    ObjItem_Test test1;
}
