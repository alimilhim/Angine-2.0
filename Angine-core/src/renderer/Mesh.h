#pragma once
#include "../common.h"
#include "../renderer/Material.h"
#include "../renderer/VertexData.h"
#include "Texture2D.h"

namespace Angine {
	namespace Renderer {

		class Mesh {
		public:
			Mesh(GLuint vaoID, int indicesCount, GLuint vioID) {
				m_vaoID = vaoID; m_indicesCount = indicesCount;
				m_vioID = vioID;
			}
			~Mesh() {}
			inline GLuint getVAOID() { return m_vaoID; };
			int m_indicesCount;
			Material* m_material;

			std::vector<Texture2D> m_textures;
		private:
			GLuint m_vaoID, m_vioID;
		};
	}
}