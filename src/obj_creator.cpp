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

    // convert textures
    for(uint32_t i = 0; i < input.textures.size(); i++)
    {
        result += "vt ";
        result += std::to_string(input.textures.at(i).x) + " ";
        result += std::to_string(input.textures.at(i).y) + "\n";
    }

    // convert normals
    for(uint32_t i = 0; i < input.normals.size(); i++)
    {
        result += "vn ";
        result += std::to_string(input.normals.at(i).x) + " ";
        result += std::to_string(input.normals.at(i).y) + " ";
        result += std::to_string(input.normals.at(i).z) + "\n";
    }

    // convert points
    for(uint32_t i = 0; i < input.points.size(); i++)
    {
        result += "p " + std::to_string(input.points.at(i)) + "\n";
    }

    // convert lines
    for(uint32_t i = 0; i < input.lines.size(); i++)
    {
        result += "l";
        for(uint32_t j = 0; j < input.lines.at(i).size(); j++)
        {
            const uint32_t id = input.lines.at(i).at(j);
            result += " " + std::to_string(id);
        }
        result += "\n";
    }

    // convert faces
    for(uint32_t i = 0; i < input.faces.size(); i++)
    {
        result += "f";
        for(uint32_t j = 0; j < input.faces.at(i).size(); j++)
        {
            // v
            const int32_t v = input.faces.at(i).at(j).v;
            result += " " + std::to_string(v) + "/";

            // vt
            const int32_t vt = input.faces.at(i).at(j).vt;
            if(vt > 0) {
                result += std::to_string(vt);
            }

            // vn
            const int32_t vn = input.faces.at(i).at(j).vn;
            if(vn > 0)
            {
                result += "/";
                result += std::to_string(vn);
            }
        }
        result += "\n";
    }

    return result;
}

}
}
