/**
 *  @file       obj_creator.cpp
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include "obj_creator.h"

namespace Kitsunemimi
{
namespace Obj
{

/**
 * @brief constructor
 */
ObjCreator::ObjCreator() {}

/**
 * @brief converts an obj-item into a string
 *
 * @param input obj-item, which should be converted
 *
 * @return resulting string
 */
const std::string
ObjCreator::create(const ObjItem &input)
{
    std::string result = "";

    // convert vertizes
    for(uint32_t i = 0; i < input.vertizes.size(); i++)
    {
        result += "v ";
        result += std::to_string(input.vertizes.at(i).x) + " ";
        result += std::to_string(input.vertizes.at(i).y) + " ";
        result += std::to_string(input.vertizes.at(i).z) + "\n";
    }

    // convert normals
    for(uint32_t i = 0; i < input.normals.size(); i++)
    {
        result += "vn ";
        result += std::to_string(input.normals.at(i).x) + " ";
        result += std::to_string(input.normals.at(i).y) + " ";
        result += std::to_string(input.normals.at(i).z) + "\n";
    }

    // convert faces
    for(uint32_t i = 0; i < input.faces.size(); i++)
    {
        result += "f ";
        for(uint32_t j = 0; j < input.faces.at(i).size(); j++)
        {
            // v
            int32_t v = input.faces.at(i).at(j).v;
            result += std::to_string(v) + "/";

            // vt
            int32_t vt = input.faces.at(i).at(j).vt;
            if(vt > 0) {
                result += std::to_string(vt) + " ";
            }

            // vn
            int32_t vn = input.faces.at(i).at(j).vn;
            if(vn > 0)
            {
                result += "/";
                result += std::to_string(vn) + " ";
            }
        }
    }

    return result;
}

}
}
