#pragma once
#include <Angine.h>
#include "Particles.h"
#include <random>  
#include "QuadTree.h"
#define G 0.005 //6.674e-11
#define DeltaT 0.05;
class Game : public Angine::Core::Scene
{
public:
	Game();
	~Game();
private:
	void init() override;
	void update() override;
	void tick() override;
	void onRender() override;
private:
	void addParticle(const glm::vec3 & pos, const glm::vec3 & vel, float r);
	void initparticles();
	void checkBoxCollision(Particle * particle);
	void applyGPull(Particle* p1 , Particle* p2);
	bool pInp(const glm::vec3& pos );
	inline float getRandom(float max, float  min)
	{
		static std::default_random_engine e;
		std::uniform_real_distribution<> dis(min, max); // rage 0 - 1
		return dis(e);
	}
private:

	int m_width, m_height;
	Model *m_model;
	Material * m_material;
	std::vector<Particle*> m_entities;
	float m_box_r, m_max_velocity;
	QuadTree * m_octree;
};