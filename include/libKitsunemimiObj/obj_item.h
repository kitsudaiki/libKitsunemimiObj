/**
 *  @file       obj_item.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#ifndef OBJ_ITEM_H
#define OBJ_ITEM_H

#include <vector>
#include <string>

namespace Kitsunemimi
{
namespace Obj
{

struct Vec4
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;
};

struct Index
{
    int32_t id1 = -1;
    int32_t id2 = -1;
    int32_t id3 = -1;
};

struct ObjItem
{
    std::vector<Vec4> vertizes;
    std::vector<Vec4> normals;
    std::vector<Vec4> textures;
    std::vector<std::vector<Index>> points;
    std::vector<std::vector<Index>> lines;
    std::vector<std::vector<Index>> faces;

    ObjItem() {}
};

bool parseString(ObjItem &result, const std::string &input);
const std::string convertToString(ObjItem &result);

}  // namespace Obj
}  // namespace Kitsunemimi

#endif // OBJ_ITEM_H
