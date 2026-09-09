#include "axes.h"
#include <iostream>
#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtx/string_cast.hpp"
#include "glrenderer.h"

using namespace TransformDemo;

void Axes::applyTransform(glm::mat4 transform) {
    m_model = transform * m_model;
}

void pushVec3(glm::vec3 vec, std::vector<float>& data) {
    data.push_back(vec.x);
    data.push_back(vec.y);
    data.push_back(vec.z);
}

void initializeConeData(std::vector<float>& data) {
    const int THETA_TESSELATIONS = 10;

    glm::vec3 p1 = glm::vec3(0, 0, 1);
    for (int i = 0; i < THETA_TESSELATIONS; i++) {
        float the1 = 1.0 * i / THETA_TESSELATIONS * 2 * glm::pi<float>();
        float the2 = 1.0 * (i + 1) / THETA_TESSELATIONS * 2 * glm::pi<float>();

        glm::vec3 p2 = glm::vec3(sin(the1), cos(the1), 0);
        glm::vec3 p3 = glm::vec3(sin(the2), cos(the2), 0);

        pushVec3(p1, data);
        pushVec3(p2, data);
        pushVec3(p3, data);
    }
}

void Axes::init(glm::mat4 model, glm::vec3 color) {
    m_model = model;
    m_color = color;

    // Axis buffer generation
    glGenBuffers(1, &m_axesVbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_axesVbo);
    std::vector<GLfloat> axes{0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f,
                              0.0f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f,
                              0.0f, 0.0f, 0.0f, 0.0f, 0.0f, 1.0f};
    glBufferData(GL_ARRAY_BUFFER, axes.size() * sizeof(GLfloat), axes.data(),
                 GL_STATIC_DRAW);

    // Axis VAO generation
    glGenVertexArrays(1, &m_axesVao);
    glBindVertexArray(m_axesVao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          reinterpret_cast<void*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);

    // Arrow buffer generation
    glGenBuffers(1, &m_arrowVbo);
    glBindBuffer(GL_ARRAY_BUFFER, m_arrowVbo);
    initializeConeData(coneData);
    glBufferData(GL_ARRAY_BUFFER, coneData.size() * sizeof(GLfloat),
                 coneData.data(), GL_STATIC_DRAW);

    // Arrow VAO generation
    glGenVertexArrays(1, &m_arrowVao);
    glBindVertexArray(m_arrowVao);

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(GLfloat),
                          reinterpret_cast<void*>(0));

    glBindBuffer(GL_ARRAY_BUFFER, 0);
    glBindVertexArray(0);
}

void Axes::draw(GLRenderer* context) {
    // Draw Axes
    glUseProgram(context->m_axesshader);
    glBindVertexArray(m_axesVao);

    // set model and color uniforms
    glUniformMatrix4fv(glGetUniformLocation(context->m_axesshader, "model"), 1,
                       GL_FALSE, &m_model[0][0]);
    glUniform3fv(glGetUniformLocation(context->m_axesshader, "inColor"), 1,
                 &m_color[0]);

    glLineWidth(4);

    glDrawArrays(GL_LINES, 0, 6);

    glBindVertexArray(0);
    glUseProgram(0);

    // Draw Arrows
    glUseProgram(context->m_arrowshader);
    glBindVertexArray(m_arrowVao);

    // set model and color uniforms
    glUniformMatrix4fv(glGetUniformLocation(context->m_arrowshader, "model"), 1,
                       GL_FALSE, &m_model[0][0]);
    glUniform3fv(glGetUniformLocation(context->m_arrowshader, "inColor"), 1,
                 &m_color[0]);

    // set offset axis uniform
    glm::vec3 coneAxis = glm::vec3(1, 0, 0);
    glUniform3fv(glGetUniformLocation(context->m_arrowshader, "offsetAxis"), 1,
                 &coneAxis[0]);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, coneData.size() / 3);

    // set offset axis uniform
    coneAxis = glm::vec3(0, 1, 0);
    glUniform3fv(glGetUniformLocation(context->m_arrowshader, "offsetAxis"), 1,
                 &coneAxis[0]);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, coneData.size() / 3);

    // set offset axis uniform
    coneAxis = glm::vec3(0, 0, 1);
    glUniform3fv(glGetUniformLocation(context->m_arrowshader, "offsetAxis"), 1,
                 &coneAxis[0]);
    // draw
    glDrawArrays(GL_TRIANGLES, 0, coneData.size() / 3);

    glBindVertexArray(0);
    glUseProgram(0);
}

void Axes::reset() {
    m_model = glm::mat4(1.f);
}
