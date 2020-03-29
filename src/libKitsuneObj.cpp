/**
 *  @file    libKitsuneObj.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include "libKitsuneObj.h"

#include <objConverter.h>

namespace Kitsune
{
namespace Obj
{

/**
 * constructor
 */
KitsuneObjConverter::KitsuneObjConverter()
{
    m_converter = new ObjConverter();
}

/**
 * destructor
 */
KitsuneObjConverter::~KitsuneObjConverter()
{
    delete m_converter;
}

/**
 * Public convert-method for the external using. At first it parse the template-string
 * and then it merge the parsed information with the content of the json-input.
 *
 * @return Pair of string and boolean where the boolean shows
 *         if the parsing and converting were successful
 *         and the string contains the output-string, if the search was successful
 *         else the string contains the error-message
 */
std::pair<Json::JsonItem*, bool>
KitsuneObjConverter::convert(const std::string &templateString)
{
    return m_converter->convert(templateString);
}

}  // namespace Obj
}  // namespace Kitsune
