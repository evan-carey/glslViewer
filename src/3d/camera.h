/*
Copyright (c) 2014, Patricio Gonzalez Vivo
All rights reserved.
Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:
    * Redistributions of source code must retain the above copyright
      notice, this list of conditions and the following disclaimer.
    * Redistributions in binary form must reproduce the above copyright
      notice, this list of conditions and the following disclaimer in the
      documentation and/or other materials provided with the distribution.
    * Neither the name of the copyright holder nor the
      names of its contributors may be used to endorse or promote products
      derived from this software without specific prior written permission.
THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE FOR ANY
DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
(INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
(INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include "node.h"

enum class CameraType {
    ORTHO, FREE
};

class Camera : public Node {
public:
    Camera();
    virtual ~Camera();

    void    setMode(CameraType cam_mode);
    void    setFOV(double fov);
    void    setViewport(int width, int height);
    void    setClipping(double near_clip_distance, double far_clip_distance);

    //Getting Functions
    const CameraType&   getType() const;
    const glm::mat3&    getNormalMatrix() const;
    const glm::mat4&    getViewMatrix() const { return getTransformMatrix(); }
    const glm::mat4&    getProjectionMatrix() const;
    const glm::mat4&    getProjectionViewMatrix() const;

protected:

    virtual void onPositionChanged();
    virtual void onOrientationChanged();
    virtual void onScaleChanged();

    void    updateCameraSettings();
    void    updateProjectionViewMatrix();

private:
    glm::mat4 m_projectionViewMatrix;

    glm::mat4 m_projectionMatrix;
    glm::mat4 m_viewMatrix;
    glm::mat3 m_normalMatrix;

    double m_aspect;
    double m_fov;
    double m_nearClip;
    double m_farClip;

    CameraType m_type;
};