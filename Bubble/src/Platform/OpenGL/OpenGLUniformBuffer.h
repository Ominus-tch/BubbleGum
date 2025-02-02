#pragma once

#include "Bubble/Renderer/UniformBuffer.h"

namespace Bubble {

	class OpenGLUniformBuffer : public UniformBuffer
	{
	public:
		OpenGLUniformBuffer(uint32_t size, uint32_t binding);
		virtual ~OpenGLUniformBuffer();

		virtual uint32_t GetSize() override;
		virtual uint32_t GetBinding() override;

		virtual void SetData(const void* data, uint32_t offset = 0) override;
	private:
		uint32_t m_RendererID = 0;

		uint32_t m_Size;
		uint32_t m_Binding;
	};

}
