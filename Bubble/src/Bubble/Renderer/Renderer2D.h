#pragma once

#include "Bubble/Renderer/OrthographicCamera.h"

#include "Bubble/Renderer/Texture.h"
#include "Bubble/Renderer/SubTexture2D.h"

#include "Bubble/Renderer/Camera.h"
#include "Bubble/Renderer/EditorCamera.h"
//#include "Bubble/Renderer/Font.h"

#include "Bubble/Scene/Components.h"
#include "Bubble/Math/Math.h"

namespace Bubble {

	class Renderer2D
	{
	public:
		static void Init();
		static void Shutdown();

		static void BeginScene(const Camera& camera, const glm::mat4& transform);
		static void BeginScene(const EditorCamera& camera);
		static void BeginScene(const OrthographicCamera& camera); // TODO: Remove
		static void EndScene();
		static void Flush();

		static void DrawCube(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color = glm::vec4(1.f));
		static void DrawCubeOutlines(const glm::vec3& position, const glm::vec3& size, const glm::vec4& color = glm::vec4(0.f, 0.f, 0.f, 1.f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec3& rotation, const glm::vec4& color = glm::vec4(1.f));

		// Primitives
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.f));
		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		static void DrawQuad(const glm::mat4& transform, const glm::vec4& color, int entityID = -1);
		static void DrawQuad(const glm::mat4& transform, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f), int entityID = -1);

		static void DrawQuad(const glm::vec2& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawQuad(const glm::vec3& position, const glm::vec2& size, const Ref<SubTexture2D>& subtexture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		// Rotation in radians
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const glm::vec4& color);
		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<Texture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		static void DrawRotatedQuad(const glm::vec2& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));
		static void DrawRotatedQuad(const glm::vec3& position, const glm::vec2& size, float rotation, const Ref<SubTexture2D>& texture, float tilingFactor = 1.0f, const glm::vec4& tintColor = glm::vec4(1.0f));

		//static void DrawTriangleFilled(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec4 color = glm::vec4(1.f), int entityID = -1);
		static void DrawTriangle(const glm::vec3& a, const glm::vec3& b, const glm::vec3& c, const glm::vec4& color = glm::vec4(1.f), int entityID = -1);

		static void DrawCircle(const glm::vec3 pos, const float r, const glm::vec4 color = glm::vec4(1.f), int entityID = -1);
		static void DrawCircleFilled(const glm::vec3 pos, const float r, const glm::vec4 color = glm::vec4(1.f), int entityID = -1);
		static void DrawCircleFilled(const glm::mat4& transform, const glm::vec4& color = glm::vec4(1.f), float thickness = 1.0f, float fade = 0.005f, int entityID = -1);

		static void DrawArc(const glm::vec3& pos, float r, float startAngle, float endAngle, const glm::vec4& color);
		static void DrawSemiCircle(const glm::vec3& position, float radius = 1.f, float angle = 0.f, float startAngle = 0.f, float endAngle = 180.f, const glm::vec4& color = glm::vec4(1.f), int segments = 50);

		static void DrawSphere(const glm::vec3& pos, float r, const glm::vec4 color = glm::vec4(1.f), int entityID = -1);
		static void DrawSphere(const glm::mat4& transform, const glm::vec4& color = glm::vec4(1.f), float thickness = 1.0f, float fade = 0.005f, int entityID = -1);

		static void DrawLine(const glm::vec2& p0, const glm::vec2& p1, const glm::vec4& color = glm::vec4(1.f), int entityID = -1);
		static void DrawLine(const glm::vec3& p0, const glm::vec3& p1, const glm::vec4& color = glm::vec4(1.f), int entityID = -1);

		static void DrawQuadraticBezier(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec4& color = glm::vec4(1.f), int segments = 20, int entityID = -1);
		static void DrawCubicBezier(const glm::vec3& p0, const glm::vec3& p1, const glm::vec3& p2, const glm::vec3& p3, const glm::vec4& color = glm::vec4(1.f), int segments = 20, int entityID = -1);

		static void DrawRect(const glm::vec3& position, const glm::vec2& size, const glm::vec4& color = glm::vec4(1.f), int entityID = -1);
		static void DrawRect(const glm::mat4& transform, const glm::vec4& color = glm::vec4(1.f), int entityID = -1);

		static void DrawFrustum(const TransformComponent& tc, float verticalFOV, float aspectRatio, float nearClip, float farClip, int entityID = -1);
		static void DrawFrustum(const TransformComponent& tc, const SceneCamera& camera, int entityID = -1);

		static void DrawSprite(const glm::mat4& transform, const SpriteRendererComponent& src, int entityID);
		static void DrawMesh(const glm::mat4& transform, const MeshComponent& mesh, int entityID);
		static void DrawMeshWireframe(const glm::mat4& transform, const MeshComponent& mesh, int entityID);

		struct TextParams
		{
			glm::vec4 Color{ 1.0f };
			float Kerning = 0.0f;
			float LineSpacing = 0.0f;
		};
		//static void DrawString(const std::string& string, Ref<Font> font, const glm::mat4& transform, const TextParams& textParams, int entityID = -1);
		//static void DrawString(const std::string& string, const glm::mat4& transform, const TextComponent& component, int entityID = -1);

		static float GetLineWidth();
		static void SetLineWidth(float width);

		// Stats
		struct Statistics
		{
			uint32_t DrawCalls = 0;
			uint32_t QuadCount = 0;
			uint32_t TriCount = 0;
			uint32_t LineCount = 0;

			uint32_t GetTotalVertexCount() const { return QuadCount * 4 + TriCount * 3 + LineCount * 2; }
			uint32_t GetTotalIndexCount() const { return QuadCount * 6 + TriCount * 3 + LineCount * 2; }
		};
		static void ResetStats();
		static Statistics GetStats();

	private:
		static void StartBatch();
		static void NextBatch();
	};

}
