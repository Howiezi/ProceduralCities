#ifndef TEXTURE_H_INCLUDED
#define TEXTURE_H_INCLUDED

#include "glad/glad.h"
#include <string>

class Texture {
public:
	Texture() = default;
	Texture(const std::string& file);

	~Texture();

	void loadFromFile(const std::string& file);

	void bindTexture() const;

private:
	GLuint m_id;
};

#endif // !TEXTURE_H_INCLUDED
