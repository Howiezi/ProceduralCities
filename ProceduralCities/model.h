#ifndef MODEL_H_INCLUDED
#define MODEL_H_INCLUDED

#include "mesh.h"

#include "renderInfo.h"

class Model{
public:
	Model() = default;
	Model(const Mesh& mesh);
	~Model();

	Model(Model&& other);
	Model& operator=(Model&& other);

	void addData(const Mesh& mesh);

	void deleteData();

	void genVAO();
	void addEBO(const std::vector<GLuint>& indices);
	void addVBO(int dimensions, const std::vector<GLfloat>& data);
	void bindVAO() const;

	int getIndicesCount() const;
	const std::string& textureFile() const;

	const RenderInfo& getRenderInfo() const;

private:
	RenderInfo m_renderInfo;

	int m_vboCount = 0;
	std::vector<GLuint> m_buffers;
};

#endif // !MODEL_H_INCLUDED
