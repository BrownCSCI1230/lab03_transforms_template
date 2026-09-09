#include "sceneparser.h"
#include <glm/gtx/transform.hpp>
#include "scenefilereader.h"

#include <chrono>
#include <iostream>

using namespace Parsing;

bool SceneParser::parse(std::string filepath, RenderData& renderData) {
    ScenefileReader fileReader = ScenefileReader(filepath);
    bool success = fileReader.readJSON();
    if (!success) {
        return false;
    }

    // Task 10: populate renderData with global data, lights, and camera data

    // Task 11: populate renderData's list of primitives and their transforms.
    //          This will involve traversing the scene graph, and we recommend
    //          you create a helper function to do so!

    return true;
}
