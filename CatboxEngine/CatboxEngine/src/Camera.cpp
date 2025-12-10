#include "Camera.h"

Camera::Camera()
{
	m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	m_Target = glm::vec3(0.0f, 0.0f, 0.0f);
	m_Up = glm::vec3(0.0f, 1.0f, 0.0f);
}

void Camera::SetPosition(const glm::vec3& pos)
{
	m_Position = pos;
}

void Camera::LookAt(const glm::vec3& target, const glm::vec3& up)
{
	m_Target = target;
	m_Up = up;
}

glm::mat4 Camera::GetView() const
{
	return glm::lookAt(m_Position, m_Target, m_Up);
}

glm::mat4 Camera::GetProjection() const
{
	return glm::perspective(glm::radians(m_Fov), m_AspectRatio, m_NearPlane, m_FarPlane);
}
