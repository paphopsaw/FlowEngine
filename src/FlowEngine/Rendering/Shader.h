#pragma once

#include <glad/glad.h>
#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

class Shader {
private:
    unsigned int ID;
public:
    //Constructor
    Shader(const char* vertexPath, const char* fragmentPath);
    ~Shader();

    unsigned int getId() { return ID; }
    //Use shader
    void bind() const;
    void unbind() const;

    //Add uniforms
    void setBool(const std::string &name, bool value) const;
    void setInt(const std::string &name, int value) const;
    void setFloat(const std::string &name, float value) const;
    void setVec2(const std::string& name, float x, float y) const;
    void setVec2(const std::string& name, glm::vec2& value) const;
    void setVec3(const std::string &name, float x, float y, float z) const;
    void setVec3(const std::string& name, glm::vec3& value) const;
    void setVec4(const std::string& name, float x, float y, float z, float w) const;
    void setVec4(const std::string& name, glm::vec4& value) const;
    void setMat4(const std::string& name, glm::mat4& value) const;
private:
    void checkCompileErrors(unsigned int shader, std::string type);

};