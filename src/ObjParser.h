#pragma once
#include <string>
#include <vector>

class ObjParser
{
    // only positions as of now
private:
    std::string m_FilePath;
    std::vector<float> positions;
public:
    ObjParser(const std::string& filepath);
    float* GetPositions();
    unsigned int* GetIndexBuffer();
};