#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

class Camera
{
public:
	Camera();

	void SetPosition(const glm::vec3& pos);
	void LookAt(const glm::vec3& target, const glm::vec3& up);

	glm::mat4 GetView() const;
	glm::mat4 GetProjection() const;

	const glm::vec3& GetPosition() { return m_Position; }

	void SetFov(float fov) { m_Fov = fov; }
	void SetAspectRatio(float aspect) { m_AspectRatio = aspect; }
	void SetNearFar(float nearPlane, float farPlane) {
		m_NearPlane = nearPlane; m_FarPlane = farPlane;
	}

private:
	glm::vec3 m_Position = glm::vec3(0.0f, 0.0f, 3.0f);
	glm::vec3 m_Target = glm::vec3(0.0f,0.0f,0.0f);
	glm::vec3 m_Up = glm::vec3(0.0f,1.0f,0.0f);
	float m_Fov = 45.0f;
	float m_AspectRatio = 128.0f/720.0f;
	float m_NearPlane = 0.1f;
	float m_FarPlane = 100.0f;
};

