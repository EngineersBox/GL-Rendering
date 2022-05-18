#pragma once

#ifndef GL_COLOUR_GRADING_FBO_HPP
#define GL_COLOUR_GRADING_FBO_HPP

#include <array>

#include "../shaders/shader.hpp"
#include "../bindableResource.hpp"

namespace GLCG::GPU::Buffers {
    class FBO: public BindableResource {
        public:
            FBO(int width, int height);
            virtual ~FBO() = default;

            void activate();
            void finalise();
            void bind() override;
            void unbind() override {
                throw std::exception("Cannot unbind FBO");
            };
            void destroy() override;
        private:
            GLCG::GPU::Shaders::Shader shader;
            unsigned int rectVAO;
            unsigned int rectVBO;
            unsigned int fbo;
            unsigned int framebufferTexture;
            unsigned int rbo;
            static constexpr std::array<float, 24> rectangleVertices = {
                1.0f, -1.0f,  1.0f, 0.0f,
                -1.0f, -1.0f,  0.0f, 0.0f,
                -1.0f,  1.0f,  0.0f, 1.0f,
                1.0f,  1.0f,  1.0f, 1.0f,
                1.0f, -1.0f,  1.0f, 0.0f,
                -1.0f,  1.0f,  0.0f, 1.0f
            };
    };
}

#endif //GL_COLOUR_GRADING_FBO_HPP