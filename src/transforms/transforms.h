#pragma once

#include "glm/glm.hpp"

namespace TransformDemo {

class Transforms {
   public:
    static glm::mat4 getMatrixA();
    static glm::mat4 getMatrixB();
    static glm::mat4 getMatrixC();
    static glm::mat4 getMatrixD();
    static glm::mat4 getInverseRotation(glm::mat4 rot);
    static glm::mat4 getViewMatrix(glm::vec3 pos, glm::vec3 look, glm::vec3 up);

   private:
    // Task 4: modify function headers to return a 4x4 matrix
    static glm::mat3 getScalingMatrix(float sx, float sy, float sz);
    static glm::mat3 getRotationMatrixX(float angle);
    static glm::mat3 getRotationMatrixY(float angle);
    static glm::mat3 getRotationMatrixZ(float angle);

    static glm::mat4 getTranslationMatrix(float dx, float dy, float dz);
};
};  // namespace TransformDemo