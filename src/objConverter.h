/**
 *  @file    objConverter.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef JINJA2CONVERTER_H
#define JINJA2CONVERTER_H

#include <utility>
#include <vector>
#include <string>
#include <jsonItems.hpp>

namespace Kitsune
{
namespace Obj
{
class ObjParserInterface;

class ObjConverter
{
public:
    ObjConverter(const bool traceParsing = false);
    ~ObjConverter();

    std::pair<Json::JsonItem*, bool> convert(const std::string &templateString);

private:

    ObjParserInterface* m_driver = nullptr;

    std::string createErrorMessage(Json::JsonArray* jsonPath);
};

}  // namespace Obj
}  // namespace Kitsune

#endif // JINJA2CONVERTER_H
