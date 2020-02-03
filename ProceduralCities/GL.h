#ifndef GL_H_INCLUDED
#define GL_H_INCLUDED

#include "glad/glad.h"

namespace GL {
	void drawElements(GLuint indicesCount) noexcept;
	void bindVAO(GLuint vao) noexcept;

	namespace Enum {
		enum Texture {Tex2D = GL_TEXTURE_2D,TexCubeMap = GL_TEXTURE_CUBE_MAP};
	}
} // namespace GL

#endif // !GL_H_INCLUDED
