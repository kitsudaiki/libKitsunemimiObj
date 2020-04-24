/**
 *  @file    libKitsuneObj.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include <libKitsunemimiObj/obj_item.h>
#include <obj_parser.h>

namespace Kitsunemimi
{
namespace Obj
{

/**
 * @brief objParse
 * @param result
 * @param input
 * @return
 */
bool
objParse(obj_item &result, const std::string &input)
{
    ObjParser parser;
    return parser.parse(result, input);
}

/**
 * @brief objToString
 * @param result
 * @return
 */
const std::string
objToString(obj_item &result)
{

}

}  // namespace Obj
}  // namespace Kitsunemimi
