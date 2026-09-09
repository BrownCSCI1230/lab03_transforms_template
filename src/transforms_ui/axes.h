#pragma once

#include <vector>
#include "GL/glew.h"
#include "glm/glm.hpp"

namespace TransformDemo {
// Forward Declaration of glrenderer
class GLRenderer;

class Axes {
   public:
    void applyTransform(glm::mat4 transform);
    void init(glm::mat4 model, glm::vec3 color);
    void draw(GLRenderer* context);
    void reset();

   private:
    std::vector<float> coneData;
    glm::mat4 m_model;
    glm::vec3 m_color;
    unsigned int m_axesVbo;
    unsigned int m_axesVao;
    unsigned int m_arrowVbo;
    unsigned int m_arrowVao;
};
};  // namespace TransformDemo