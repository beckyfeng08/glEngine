#pragma once
#include <string>

struct ShaderProgramSource
{
    std::string VertexSource;
    std::string FragmentSource;
};


class Shader
{
private:
    std::string m_FilePath;
    unsigned int m_RendererID;
    //caching for uniforms

public:
    Shader(const std::string& filepath);
    ~Shader();

    void Bind() const;
    void Unbind() const;
    
    // Set uniforms
    void SetUniform4f(const std::string& name, float v0, float v1, float f2, float f3);
private:
    unsigned int GetUniformLocation(const std::string& name);
    unsigned int CompileShader(const std::string& source, unsigned int type) ;
    unsigned int CreateShader(const std::string& vertexShader, const std::string& fragmentShader);
    ShaderProgramSource ParseShader(const std::string& filepath);

};