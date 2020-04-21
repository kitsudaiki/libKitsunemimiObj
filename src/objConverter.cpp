/**
 *  @file    objConverter.cpp
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#include <obj_converter.h>
#include <obj_parsing/obj_parserInterface.h>
#include <jsonItems.hpp>

namespace Kitsunemimi
{
namespace Obj
{

ObjConverter::ObjConverter(const bool traceParsing)
{
    m_driver = new ObjParserInterface(traceParsing);
}

ObjConverter::~ObjConverter()
{
    delete m_driver;
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
ObjConverter::convert(const std::string &templateString)
{
    std::pair<Json::JsonItem*, bool> result;

    // parse obj-template into a json-tree
    result.second = m_driver->parse(templateString);
    result.first = m_driver->getOutput();

    // process a failure
    if(result.second == false) {
        result.first = new Json::JsonValue(m_driver->getErrorMessage());
    }
    return result;
}


}  // namespace Obj
}  // namespace Kitsunemimi
