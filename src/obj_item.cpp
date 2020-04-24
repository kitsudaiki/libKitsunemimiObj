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
 * @brief parse an obj-string
 *
 * @param result empty obj-item for the parsed information
 * @param input input-string, which should be parsed
 *
 * @return true, if successful, else false
 */
bool
parseString(ObjItem &result,
            const std::string &input)
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
convertToString(ObjItem &result)
{

}

}  // namespace Obj
}  // namespace Kitsunemimi
