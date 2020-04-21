/**
 *  @file    objConverter.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef OBJCONVERTER_H
#define OBJCONVERTER_H

#include <utility>
#include <vector>
#include <string>

namespace Kitsunemimi
{
namespace Obj
{
class ObjParserInterface;

class ObjConverter
{
public:
    ObjConverter(const bool traceParsing = false);
    ~ObjConverter();

    bool convert(const std::string &input);

private:

    ObjParserInterface* m_driver = nullptr;

    std::string createErrorMessage(Json::JsonArray* jsonPath);
};

}  // namespace Obj
}  // namespace Kitsune

#endif // OBJCONVERTER_H
