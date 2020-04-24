#include "obj_parser.h"

#include <libKitsunemimiCommon/common_methods/string_methods.h>
#include <libKitsunemimiCommon/common_methods/vector_methods.h>

#include <libKitsunemimiPersistence/logger/logger.h>

namespace Kitsunemimi
{
namespace Obj
{

/**
 * @brief ObjParser::ObjParser
 */
ObjParser::ObjParser() {}

/**
 * @brief ObjParser::parse
 * @param result
 * @param inputString
 * @return
 */
bool
ObjParser::parse(obj_item &result,
                 const std::string &inputString)
{
    std::string preparedString = inputString;

    Kitsunemimi::replaceSubstring(preparedString, "\t", " ");

    std::vector<std::string> splittedContent;
    Kitsunemimi::splitStringByDelimiter(splittedContent, preparedString, '\n');

    for(uint64_t i = 0; i < splittedContent.size(); i++)
    {
        if(splittedContent.at(i).size() == 0) {
            continue;
        }

        std::vector<std::string> splittedLine;
        Kitsunemimi::splitStringByDelimiter(splittedLine, splittedContent.at(i), ' ');
        Kitsunemimi::removeEmptyStrings(&splittedLine);

        bool state = false;

        if(splittedLine.at(0) == "v")
        {
            vec4 vertex;
            state = parseVector(vertex, splittedLine);
            result.vertizes.push_back(vertex);
        }

        if(splittedLine.at(0) == "vn")
        {
            vec4 normale;
            state = parseVector(normale, splittedLine);
            result.normals.push_back(normale);
        }

        if(splittedLine.at(0) == "f")
        {
            std::vector<index> indizes;
            state = parseIndexList(indizes, splittedLine);
            result.faces.push_back(indizes);
        }

        if(state == false)
        {
            LOG_ERROR("ERROR while parsing obj-file content in line " + std::to_string(i));
            return false;
        }
    }

    return true;
}

/**
 * @brief ObjParser::parseVector
 * @param result
 * @param lineContent
 * @return
 */
bool
ObjParser::parseVector(vec4 &result,
                       const std::vector<std::string> &lineContent)
{
    if(lineContent.size() < 4) {
        return false;
    }

    bool ret = false;

    ret = parseFloat(result.x, lineContent.at(1));
    if(ret == false) {
        return false;
    }

    ret = parseFloat(result.y, lineContent.at(2));
    if(ret == false) {
        return false;
    }

    ret = parseFloat(result.z, lineContent.at(3));
    if(ret == false) {
        return false;
    }

    return true;
}

/**
 * @brief ObjParser::parseIndexList
 * @param result
 * @param lineContent
 * @return
 */
bool
ObjParser::parseIndexList(std::vector<index> &result,
                     const std::vector<std::string> &lineContent)
{
    if(lineContent.size() < 4) {
        return false;
    }

    for(uint32_t i = 1; i < lineContent.size(); i++)
    {
        std::vector<std::string> indexList;
        Kitsunemimi::splitStringByDelimiter(indexList, lineContent.at(i), '/');

        index newIndex;
        bool ret = parseIndex(newIndex, indexList);
        if(ret == false) {
            return false;
        }
        result.push_back(newIndex);
    }

    return true;
}

/**
 * @brief ObjParser::parseIndex
 * @param result
 * @param indexContent
 * @return
 */
bool
ObjParser::parseIndex(index &result,
                      const std::vector<std::string> &indexContent)
{
    if(indexContent.size() > 0)
    {
        if(indexContent.at(0).size() > 0)
        {
            bool ret = parseInt(result.id1, indexContent.at(0));
            if(ret == false) {
                return false;
            }
        }
    }

    if(indexContent.size() > 1)
    {
        if(indexContent.at(1).size() > 0)
        {
            bool ret = parseInt(result.id2, indexContent.at(1));
            if(ret == false) {
                return false;
            }
        }
    }

    if(indexContent.size() > 2)
    {
        if(indexContent.at(2).size() > 0)
        {
            bool ret = parseInt(result.id3, indexContent.at(2));
            if(ret == false) {
                return false;
            }
        }
    }

    return true;
}

/**
 * @brief ObjParser::parseFloat
 * @param result
 * @param input
 * @return
 */
bool
ObjParser::parseFloat(float &result,
                      const std::string &input)
{
    char* err = nullptr;
    result = std::strtof(input.c_str(), &err);

    if(std::string(err).size() != 0) {
        return false;
    }

    return true;
}

/**
 * @brief ObjParser::parseInt
 * @param result
 * @param input
 * @return
 */
bool
ObjParser::parseInt(int &result,
                    const std::string &input)
{
    char* err = nullptr;
    result = static_cast<int32_t>(std::strtol(input.c_str(), &err, 10));

    if(std::string(err).size() != 0) {
        return false;
    }

    return true;
}

}
}
