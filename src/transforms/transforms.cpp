#include "transforms.h"
#include <math.h>
#include <iostream>
#include "glm/gtx/transform.hpp"

using namespace TransformDemo;

glm::mat3 Transforms::getScalingMatrix(float sx, float sy, float sz) {
    // Task 1: return the transformation matrix for 3D scaling
    // Task 4: modify the function to return a 4x4 matrix

    return glm::mat3(1.f);
}

glm::mat3 Transforms::getRotationMatrixX(float angle) {
    // Task 2: return the matrix for rotation about the x-axis
    // Task 4: modify the function to return a 4x4 matrix

    return glm::mat3(1.f);
}

glm::mat3 Transforms::getRotationMatrixY(float angle) {
    // Task 2: return the matrix for rotation about the y-axis
    // Task 4: modify the function to return a 4x4 matrix

    return glm::mat3(1.f);
}

glm::mat3 Transforms::getRotationMatrixZ(float angle) {
    // Task 2: return the matrix for rotation about the z-axis
    // Task 4: modify the function to return a 4x4 matrix

    return glm::mat3(1.f);
}

glm::mat4 Transforms::getTranslationMatrix(float dx, float dy, float dz) {
    // Task 3: return the matrix for translation

    return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixA() {
    // Task 5: return matrix A using the previous functions

    return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixB() {
    // Task 5: return matrix B using the previous functions

    return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixC() {
    // Task 5: return matrix C using the previous functions

    return glm::mat4(1.f);
}

glm::mat4 Transforms::getMatrixD() {
    // Task 5: return matrix D using the previous functions

    return glm::mat4(1.f);
}

// Task 7: Debug the following function
glm::mat4 Transforms::getInverseRotation(glm::mat4 rot) {
    // We know that the inverse of a rotation matrix is simply its transpose,
    //  so let's try to turn rows of the input matrix into columns of the
    //  inverse.
    glm::vec4 col0(rot[0][0], rot[0][1], rot[0][2], rot[0][3]);
    glm::vec4 col1(rot[1][0], rot[1][1], rot[1][2], rot[1][3]);
    glm::vec4 col2(rot[2][0], rot[2][1], rot[2][2], rot[2][3]);
    glm::vec4 col3(rot[3][0], rot[3][1], rot[3][2], rot[3][3]);

    return glm::mat4(col0, col1, col2, col3);
}

glm::mat4 Transforms::getViewMatrix(glm::vec3 pos,
                                    glm::vec3 look,
                                    glm::vec3 up) {
    // Task 8: return the camera view matrix
    return glm::mat4(1.f);
}