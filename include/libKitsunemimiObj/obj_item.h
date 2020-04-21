/**
 *  @file    libKitsuneObj.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef OBJ_ITEM_H
#define OBJ_ITEM_H

#include <utility>
#include <string>

namespace Kitsunemimi
{
namespace Obj
{

class ObjItem
{
public:
    ObjItem();
    ~ObjItem();

    bool convert(const std::string &input);
};

}  // namespace Obj
}  // namespace Kitsunemimi

#endif // OBJ_ITEM_H
