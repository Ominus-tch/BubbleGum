#pragma once

#include <string>
#include <glm/glm.hpp>

#include <unordered_map>

#include "Buffer.h"
#include "UniformBuffer.h"
#include "Texture.h"

namespace Bubble {

	class Shader
	{
	public:
		virtual ~Shader() = default;

		virtual void Bind() const = 0;
		virtual void Unbind() const = 0;

		virtual void SetBool(const std::string& name, bool value) = 0;
		virtual void SetInt(const std::string& name, int value) = 0;
		virtual void SetIntArray(const std::string& name, int* values, uint32_t count) = 0;
		virtual void SetFloat(const std::string& name, float value) = 0;
		virtual void SetFloat2(const std::string& name, const glm::vec2& value) = 0;
		virtual void SetFloat3(const std::string& name, const glm::vec3& value) = 0;
		virtual void SetFloat4(const std::string& name, const glm::vec4& value) = 0;
		virtual void SetMat4(const std::string& name, const glm::mat4& value) = 0;

		virtual void DispatchCompute(uint32_t x, uint32_t y, uint32_t z) = 0;

		virtual void SetBuffer(uint32_t slot, const std::string& name, const Ref<ComputeBuffer>& buffer) = 0;
		virtual void SetTexture(uint32_t slot, const std::string& name, const Ref<Texture2D>& texture) = 0;
		virtual void SetUniformBuffer(const std::string& name, const Ref<UniformBuffer>& buffer) = 0;

		virtual const std::string& GetName() const = 0;

		virtual void TestFunction() = 0;

		static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc);
		//static Ref<Shader> Create(const std::string& name, const std::string& vertexSrc, const std::string& fragmentSrc, const std::string& computeSrc);
		static Ref<Shader> Create(const std::string& filepath);
	};

	class ShaderLibrary
	{
	public:
		void Add(const std::string& name, const Ref<Shader>& shader);
		void Add(const Ref<Shader>& shader);
		Ref<Shader> Load(const std::string& filepath);
		Ref<Shader> Load(const std::string& name, const std::string& filepath);

		Ref<Shader> Get(const std::string& name);

		bool Exists(const std::string& name) const;
	private:
		std::unordered_map<std::string, Ref<Shader>> m_Shaders;
	};
}
