#pragma once

#include <vector>
#include "glm/glm.hpp"

namespace TransformDemo {

// Forward Declaration of glrenderer
class GLRenderer;

class Gridlines {
   public:
    void init();
    void draw(GLRenderer* context);

   private:
    std::vector<float> lineData;
    glm::mat4 m_model;
    glm::vec3 m_color;
    unsigned int m_vbo;
    unsigned int m_vao;
};
};  // namespace TransformDemo