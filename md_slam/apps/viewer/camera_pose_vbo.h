// Copyright 2022 Luca Di Giammarino
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of the copyright holder nor the names of its contributors
//    may be used to endorse or promote products derived from this software
//    without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.

#pragma once
#include "vbo_base.h"
#include <Eigen/Core>
#include <iostream>

namespace srrg2_core {

  struct CameraPoseVBO : public VBOBase {
    EIGEN_MAKE_ALIGNED_OPERATOR_NEW
    CameraPoseVBO(float width, float height);
    ~CameraPoseVBO();

    void draw(const Eigen::Matrix4f& projection,
              const Eigen::Matrix4f& model_pose,
              const Eigen::Matrix4f& object_pose,
              const Eigen::Vector3f& light_direction,
              const CustomDraw& custom_draw) override;

  protected:
    static const char* vertex_shader_source;
    static const char* fragment_shader_source;
    static ShaderBasePtr _my_shader;
    static constexpr float _unscaled_vertices[] = {0, 0, -1, -1, -1, 0, 1,  -1, 0,

                                                   0, 0, -1, 1,  -1, 0, 1,  1,  0,

                                                   0, 0, -1, 1,  1,  0, -1, 1,  0,

                                                   0, 0, -1, -1, 1,  0, -1, -1, 0};
    static constexpr int num_coordinates        = sizeof(_unscaled_vertices) / (sizeof(float));
    static constexpr int num_vertices           = num_coordinates / 3;
    static float _vertices[num_coordinates];
    unsigned int _gl_vertex_buffer = 0, _gl_vertex_array = 0;
    static ShaderBasePtr getShader();
  };

} // namespace srrg2_core
