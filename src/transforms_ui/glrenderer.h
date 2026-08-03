#pragma once

// clang-format off
// order of these includes matter
#include "GL/glew.h"
#include <QOpenGLWidget>
// clang-format on

#include "glm/glm.hpp"
#include "glm/gtc/constants.hpp"
#include "glm/gtc/matrix_transform.hpp"
#include "glm/gtx/transform.hpp"

#include "axes.h"
#include "gridlines.h"

namespace TransformDemo {

enum Button {
    A,
    B,
    C,
    D,
    VIEW,
    A_INV,
    B_INV,
    C_INV,
    D_INV,
    VIEW_INV,
    ROTATION,
    ROTATION_INV,
    RESET
};

class GLRenderer : public QOpenGLWidget {
   public:
    GLRenderer(QWidget* parent = nullptr);
    ~GLRenderer();

    void buttonPressed(Button button);

   protected:
    void initializeGL() override;  // Called once at the start of the program
    void paintGL() override;       // Called every frame in a loop
    void resizeGL(int width,
                  int height) override;  // Called when window size changes

    void mousePressEvent(QMouseEvent* e) override;  // used for camera movement
    void mouseMoveEvent(QMouseEvent* e) override;   // used for camera movement
    void wheelEvent(QWheelEvent* e) override;       // used for camera movement
    void rebuildMatrices();                         // used for camera movement

   private:
    GLuint m_gridshader;   // Stores id for shader program
    GLuint m_axesshader;   // Stores id for shader program
    GLuint m_arrowshader;  // Stores id for shader program

    Axes m_student;
    Axes m_obj1;
    Axes m_obj2;
    Axes m_obj3;
    Axes m_cam;
    Gridlines m_grid;

    glm::mat4 m_view;
    glm::mat4 m_projection;

    friend class Gridlines;
    friend class Axes;

    QPoint m_prevMousePos;
    float m_angleX;
    float m_angleY;
    float m_zoom;
};
};  // namespace TransformDemo