/**
 *  @file    libKitsuneObj.h
 *
 *  @author  Tobias Anker
 *  Contact: tobias.anker@kitsunemimi.moe
 *
 *  MIT License
 */

#ifndef LIBKITSUNEJINJA2_H
#define LIBKITSUNEJINJA2_H

#include <utility>
#include <string>
#include <jsonItems.hpp>

namespace Kitsune
{
namespace Obj
{
class ObjConverter;

class KitsuneObjConverter
{
public:
    KitsuneObjConverter();
    ~KitsuneObjConverter();

    std::pair<Json::JsonItem *, bool> convert(const std::string &templateString);

private:
    ObjConverter* m_converter = nullptr;
};

}  // namespace Obj
}  // namespace Kitsune

#endif // LIBKITSUNEJINJA2_H
