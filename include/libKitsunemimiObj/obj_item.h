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

#include <vector>
#include <string>

namespace Kitsunemimi
{
namespace Obj
{

struct vec4
{
    float x = 0.0f;
    float y = 0.0f;
    float z = 0.0f;
    float w = 0.0f;
};

struct index
{
    int32_t id1 = -1;
    int32_t id2 = -1;
    int32_t id3 = -1;
};

struct obj_item
{
    std::vector<vec4> vertizes;
    std::vector<vec4> normals;
    std::vector<vec4> textures;
    std::vector<std::vector<index>> points;
    std::vector<std::vector<index>> lines;
    std::vector<std::vector<index>> faces;

    obj_item() {}
};

bool objParse(obj_item &result, const std::string &input);
const std::string objToString(obj_item &result);

}  // namespace Obj
}  // namespace Kitsunemimi

#endif // OBJ_ITEM_H
