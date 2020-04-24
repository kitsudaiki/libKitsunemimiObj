#ifndef OBJ_PARSER_H
#define OBJ_PARSER_H

#include <libKitsunemimiObj/obj_item.h>

namespace Kitsunemimi
{
namespace Obj
{

class ObjParser
{
public:
    ObjParser();

    bool parse(obj_item &result,
               const std::string &inputString);

private:
    bool parseIndizes(obj_item &result,
                      const std::string &inputString);

    bool parseVector(vec4 &result,
                     const std::vector<std::string> &lineContent);
    bool parseIndexList(std::vector<index> &result,
                        const std::vector<std::string> &lineContent);
    bool parseIndex(index &result,
                    const std::vector<std::string> &indexContent);

    bool parseFloat(float &result,
                    const std::string &input);
    bool parseInt(int &result,
                  const std::string &input);
};

}
}

#endif // OBJ_PARSER_H
