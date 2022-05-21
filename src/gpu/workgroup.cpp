#include "workgroup.hpp"

#include <glad/glad.h>

namespace GLCG::GPU {
    WorkGroup::WorkGroup() {
        int glMajorVersion;
        int glMinorVersion;
        glGetIntegerv(GL_MAJOR_VERSION, &glMajorVersion);
        glGetIntegerv(GL_MINOR_VERSION, &glMinorVersion);
        if (glMajorVersion < 4 || (glMajorVersion >= 4 && glMinorVersion < 3)) {
            // Compute shaders are not supported in versions older than 4.3
            return;
        }

        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 0, &this->count.x);
        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 1, &this->count.y);
        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_COUNT, 2, &this->count.z);

        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 0, &this->size.x);
        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 1, &this->size.y);
        glGetIntegeri_v(GL_MAX_COMPUTE_WORK_GROUP_SIZE, 2, &this->size.z);

        glGetIntegerv(GL_MAX_COMPUTE_WORK_GROUP_INVOCATIONS, &this->invocations);

        glGetIntegerv(GL_MAX_COMPUTE_SHARED_MEMORY_SIZE, &this->sharedMemorySizeBytes);
    }
}