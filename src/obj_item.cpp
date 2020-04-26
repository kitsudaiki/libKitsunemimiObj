/**
 *  @file       obj_item.h
 *
 *  @author     Tobias Anker <tobias.anker@kitsunemimi.moe>
 *
 *  @copyright  MIT License
 */

#include <libKitsunemimiObj/obj_item.h>

#include <obj_parser.h>
#include <obj_creator.h>

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
 * @brief converts an obj-item into a string
 *
 * @param convertedString reference to the resulting string
 * @param input obj-item, which should be converted
 *
 * @return resulting string
 */

bool
convertToString(std::string &convertedString,
                const ObjItem &input)
{
    ObjCreator creator;
    return creator.create(convertedString, input);
}

}  // namespace Obj
}  // namespace Kitsunemimi
