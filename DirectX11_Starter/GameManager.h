#pragma once
#include "Ball.h"
#include "Boundary.h"
#include "Mesh.h"
#include "Material.h"
#include "SimpleShader.h"
#include "Camera.h"
#include "GameEntity.h"
#include "Collisions.h"
#include <WICTextureLoader.h>
#include <vector>
#include "Player.h"
#include "GameController.h"
#include "Light.h"

class GameManager
{
public:

	GameManager(ID3D11Device* d, ID3D11DeviceContext* dc);
	~GameManager();

	//Methods to create Mesh, Ball, Player, Material, Walls
	//To create additional crap, add more methods here
	void CreatePlayer(XMFLOAT3 pos, float w, float h, Mesh* m, Material* ma);
	void CreateComputer(XMFLOAT3 pos, float w, float h, Mesh* m, Material* ma);
	void CreateBall(float r, Mesh*, Material*);
	void CreateWall(int l, int w, XMFLOAT3 p, XMFLOAT3 r, XMFLOAT3 s, XMFLOAT3 u, Mesh* m, Material* ma);
	void CreateMesh(char* file);
	void CreateMaterial(SimpleVertexShader* vs, SimplePixelShader* ps, ID3D11ShaderResourceView* rv, ID3D11SamplerState* ss);
	void CreateMaterial(SimpleVertexShader* vs, SimplePixelShader* ps, ID3D11ShaderResourceView* rv, ID3D11SamplerState* ss, const wchar_t* psn, const wchar_t* vsn);
	void CreatePixelShader();
	void CreateVertexShader();
	void CreateResourceView(const wchar_t*);
	void CreateSamplerState();
	void CreateCamera(int w, int h);
	void CreateGameController(Ball* ball, Player* player);
	void CreateGameController(Ball* ball, Player* player, Computer* computer, int cL, int pL, int l);
	void CreateLight(int _lightType, XMFLOAT4 _ambient, XMFLOAT4 _diffuse, float _range, XMFLOAT3 _pos, XMFLOAT3 _att, XMFLOAT3 _dir, float _cone);

	//Lots of getters. Setters are generally in the object's class.
	Player* GetPlayer();
	Computer* GetComputer();
	std::vector<Ball*> GetBalls();
	std::vector<Boundary*> GetWalls();
	std::vector<Mesh*> GetMeshes();
	std::vector<Material*> GetMaterials();
	std::vector<SimplePixelShader*> GetPixelShaders();
	std::vector<SimpleVertexShader*> GetVertexShaders();
	std::vector<ID3D11ShaderResourceView*> GetResourceViews();
	std::vector<ID3D11SamplerState*> GetSamplerStates();
	std::vector<D3D11_SAMPLER_DESC> GetSamplerDescs();
	std::vector<GameEntity*> GetGameEntities();
	GameController* GetGameController();

private:

	//vectors holding everything we could want to create
	//Even if we think we will only have one, make it a vector
	//Prevents redoing crap later if we have new ideas

	//GameController manages game logic, needs ref to ball, player, and ai player.
	GameController* gameController;

	Player* player;
	Computer* computer;
	std::vector<Ball*> balls;
	std::vector<Boundary*> walls;
	std::vector<Mesh*> meshes;
	std::vector<Material*> materials;
	std::vector<Light*> lights;

	std::vector<SimplePixelShader*> pixelShaders;
	std::vector<SimpleVertexShader*> vertexShaders;

	//Used to create materials, could save duplication
	std::vector<ID3D11ShaderResourceView*> resourceViews;
	std::vector<ID3D11SamplerState*> samplerStates;
	std::vector<D3D11_SAMPLER_DESC> samplerDescs;

	ID3D11Device* device;
	ID3D11DeviceContext* deviceContext;

	//All entities to be cleaned up
	std::vector<GameEntity*> entities;
};

