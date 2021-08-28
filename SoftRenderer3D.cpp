
#include "Precompiled.h"
#include "SoftRenderer.h"
#include <vector>
#include <random>
using namespace CK::DDD;

// ����� �׸��� �Լ�
void SoftRenderer::DrawGizmo3D()
{
	auto& r = GetRenderer();
	const GameEngine& g = Get3DGameEngine();

	// �� ����� �׸���
	std::vector<Vertex3D> viewGizmo = {
		Vertex3D(Vector4(Vector3::Zero)),
		Vertex3D(Vector4(Vector3::UnitX * _GizmoUnitLength)),
		Vertex3D(Vector4(Vector3::UnitY * _GizmoUnitLength)),
		Vertex3D(Vector4(Vector3::UnitZ * _GizmoUnitLength)),
	};

	Matrix4x4 viewMatRotationOnly = g.GetMainCamera().GetViewMatrixRotationOnly();
	VertexShader3D(viewGizmo, viewMatRotationOnly);

	// �� �׸���
	Vector2 v0 = viewGizmo[0].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v1 = viewGizmo[1].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v2 = viewGizmo[2].Position.ToVector2() + _GizmoPositionOffset;
	Vector2 v3 = viewGizmo[3].Position.ToVector2() + _GizmoPositionOffset;
	r.DrawLine(v0, v1, LinearColor::Red);
	r.DrawLine(v0, v2, LinearColor::Green);
	r.DrawLine(v0, v3, LinearColor::Blue);
}

// ���� ������Ʈ ���
static const std::string PlayerGo = "Player"; //player gameobject의 약자인건가 싶다.
//플레이어의 이름을 따로 만들어서 오브젝트를 추가하는 방식인 것 같다.
//그래서 이렇게 추가를 해서 오므젝트를 여럿 만들어 보았다.
static const std::string playernames[11] = { "player0", "player1", "player2", "player3", "player4", "player5", "player6", "player7", "player8", "player9","player10" };


// ���� �� �ε��� ����ϴ� �Լ�
// 최초 씬 로딩을 담당하는 함수
void SoftRenderer::LoadScene3D()
{
	GameEngine& g = Get3DGameEngine();
	GameObject& goPlayer1 = g.CreateNewGameObject(playernames[0]);
	GameObject& goPlayer2 = g.CreateNewGameObject(playernames[1]);
	GameObject& goPlayer3 = g.CreateNewGameObject(playernames[2]);
	GameObject& goPlayer4 = g.CreateNewGameObject(playernames[3]);
	GameObject& goPlayer5 = g.CreateNewGameObject(playernames[4]);
	GameObject& goPlayer6 = g.CreateNewGameObject(playernames[5]);
	GameObject& goPlayer7 = g.CreateNewGameObject(playernames[6]);
	GameObject& goPlayer8 = g.CreateNewGameObject(playernames[7]);
	GameObject& goPlayer9 = g.CreateNewGameObject(playernames[8]);
	GameObject& goPlayer10 = g.CreateNewGameObject(playernames[9]);
	GameObject& goPlayer11 = g.CreateNewGameObject(playernames[10]);

	// 플레이어
	constexpr float playerScale = 100.f;

	// 플레이어 설정
	goPlayer1.SetMesh(GameEngine::CubeMesh);
	goPlayer1.GetTransform().SetPosition(Vector3::Zero);
	goPlayer1.GetTransform().SetScale(Vector3(1.0f, 1.0f, 0.5f) * playerScale);
	goPlayer1.GetTransform().SetRotation(Rotator(0.f, 0.f, 0.f));
	goPlayer1.SetColor(LinearColor::Blue);

	goPlayer2.SetMesh(GameEngine::CubeMesh);
	goPlayer2.GetTransform().SetPosition(Vector3(1.0f, 1.0f, 100.f));
	goPlayer2.GetTransform().SetScale(Vector3(2.0f, 2.0f, 0.5f) * playerScale);
	goPlayer2.GetTransform().SetRotation(Rotator(0.f, 15.f, 15.f));
	goPlayer2.SetColor(LinearColor::Red);

	goPlayer3.SetMesh(GameEngine::CubeMesh);
	goPlayer3.GetTransform().SetPosition(Vector3(2.0f, 2.f, 200.f));
	goPlayer3.GetTransform().SetScale(Vector3(4.f, 4.f, 0.3f) * playerScale);
	goPlayer3.GetTransform().SetRotation(Rotator(0.f, 30.f, 30.f));
	goPlayer3.SetColor(LinearColor::Cyan);

	goPlayer4.SetMesh(GameEngine::CubeMesh);
	goPlayer4.GetTransform().SetPosition(Vector3(2.f, 2.f, 300.f));
	goPlayer4.GetTransform().SetScale(Vector3(6.f, 6.f, 0.3f) * playerScale);
	goPlayer4.GetTransform().SetRotation(Rotator(0.f, 45.f, 45.f));
	goPlayer4.SetColor(LinearColor::Black);

	goPlayer5.SetMesh(GameEngine::CubeMesh);
	goPlayer5.GetTransform().SetPosition(Vector3(3.f, 3.f, 400.f));
	goPlayer5.GetTransform().SetScale(Vector3(8.f, 8.f, 0.6f) * playerScale);
	goPlayer5.GetTransform().SetRotation(Rotator(0.f, 60.f, 60.f));
	goPlayer5.SetColor(LinearColor::Green);

	goPlayer6.SetMesh(GameEngine::CubeMesh);
	goPlayer6.GetTransform().SetPosition(Vector3(5.f, 5.f, 500.f));
	goPlayer6.GetTransform().SetScale(Vector3(10.f, 10.f, 1.0f) * playerScale);
	goPlayer6.GetTransform().SetRotation(Rotator(0.f, 75.f, 75.f));
	goPlayer6.SetColor(LinearColor::Magenta);

	goPlayer7.SetMesh(GameEngine::CubeMesh);
	goPlayer7.GetTransform().SetPosition(Vector3(7.f, 7.f, 600.f));
	goPlayer7.GetTransform().SetScale(Vector3(8.f, 8.f, 0.6f) * playerScale);
	goPlayer7.GetTransform().SetRotation(Rotator(0.f, 90.f, 90.f));
	goPlayer7.SetColor(LinearColor::Green);

	goPlayer8.SetMesh(GameEngine::CubeMesh);
	goPlayer8.GetTransform().SetPosition(Vector3(9.f, 9.f, 700.f));
	goPlayer8.GetTransform().SetScale(Vector3(6.f, 6.f, 0.3f) * playerScale);
	goPlayer8.GetTransform().SetRotation(Rotator(0.f, 105.f,105.f));
	goPlayer8.SetColor(LinearColor::Black);

	goPlayer9.SetMesh(GameEngine::CubeMesh);
	goPlayer9.GetTransform().SetPosition(Vector3(11.0f, 11.f, 800.f));
	goPlayer9.GetTransform().SetScale(Vector3(4.f, 4.f, 0.3f) * playerScale);
	goPlayer9.GetTransform().SetRotation(Rotator(0.f, 120.f, 120.f));
	goPlayer9.SetColor(LinearColor::Cyan);

	goPlayer10.SetMesh(GameEngine::CubeMesh);
	goPlayer10.GetTransform().SetPosition(Vector3(13.0f, 13.0f, 900.f));
	goPlayer10.GetTransform().SetScale(Vector3(2.0f, 2.0f, 0.5f) * playerScale);
	goPlayer10.GetTransform().SetRotation(Rotator(0.f, 135.f, 135.f));
	goPlayer10.SetColor(LinearColor::Red);

	goPlayer11.SetMesh(GameEngine::CubeMesh);
	goPlayer11.GetTransform().SetPosition(Vector3(15.0f, 15.0f, 1000.f));
	goPlayer11.GetTransform().SetScale(Vector3(1.0f, 1.0f, 0.5f) * playerScale);
	goPlayer11.GetTransform().SetRotation(Rotator(0.f, 150.f, 150.f));
	goPlayer11.SetColor(LinearColor::Blue);

	// 카메라 설정
	CameraObject& mainCamera = g.GetMainCamera();
	mainCamera.GetTransform().SetPosition(Vector3(0.f, 0.f, 500.f));
	mainCamera.GetTransform().SetRotation(Rotator(0.f, 30.f, 30.f));
}


// ���� ������ ������ ������ �����ϴ� ����

// ���� ������ ����ϴ� �Լ�
void SoftRenderer::Update3D(float InDeltaSeconds)
{
	// 게임 로직에서 사용하는 모듈 내 주요 레퍼런스
	GameEngine& g = Get3DGameEngine();
	const InputManager& input = g.GetInputManager();

	// 게임 로직의 로컬 변수
	static float moveSpeed = 300.f;
	static float rotateSpeed = 100.f;

	// 게임 로직에서 사용할 게임 오브젝트 레퍼런스
	GameObject& goPlayer = g.GetGameObject(playernames[5]); //gameobject 중심의 카메라를 가져와서 회전시키는 것이니.
	//5번의 카메라를 가져와서 중심을 기준으로 회전하게 만듬.
	CameraObject& camera = g.GetMainCamera();

	// 입력에 따른 플레이어 트랜스폼의 변경
	goPlayer.GetTransform().AddPosition(Vector3::UnitZ * input.GetAxis(InputAxis::ZAxis) * moveSpeed * InDeltaSeconds);
	goPlayer.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::WAxis) * rotateSpeed * InDeltaSeconds);

	// 입력에 따른 카메라 트랜스폼의 변경
	camera.GetTransform().AddYawRotation(-input.GetAxis(InputAxis::XAxis) * rotateSpeed * InDeltaSeconds);
	camera.GetTransform().AddPitchRotation(-input.GetAxis(InputAxis::YAxis) * rotateSpeed * InDeltaSeconds);
}

// �ִϸ��̼� ������ ����ϴ� �Լ�
void SoftRenderer::LateUpdate3D(float InDeltaSeconds)
{
	// �ִϸ��̼� �������� ����ϴ� ��� �� �ֿ� ���۷���
	GameEngine& g = Get3DGameEngine();

	// �ִϸ��̼� ������ ���� ����
}

// ������ ������ ����ϴ� �Լ�
void SoftRenderer::Render3D()
{
	// ������ �������� ����ϴ� ��� �� �ֿ� ���۷���
	const GameEngine& g = Get3DGameEngine();
	auto& r = GetRenderer();
	const CameraObject& mainCamera = g.GetMainCamera();

	// ��濡 ����� �׸���
	DrawGizmo3D();

	// ������ ������ ���� ����
	const Matrix4x4 vMatrix = mainCamera.GetViewMatrix();

	for (auto it = g.SceneBegin(); it != g.SceneEnd(); ++it)
	{
		const GameObject& gameObject = *(*it);
		if (!gameObject.HasMesh() || !gameObject.IsVisible())
		{
			continue;
		}

		// �������� �ʿ��� ���� ������Ʈ�� �ֿ� ���۷����� ���
		const Mesh& mesh = g.GetMesh(gameObject.GetMeshKey());
		const TransformComponent& transform = gameObject.GetTransform();

		Matrix4x4 finalMatrix = vMatrix * transform.GetModelingMatrix();

		// �޽� �׸���
		DrawMesh3D(mesh, finalMatrix, gameObject.GetColor());

		// �� ���������� �÷��̾� ��ġ�� ȭ�鿡 ǥ��
		if (gameObject == PlayerGo)
		{
			Vector3 viewPosition = vMatrix * transform.GetPosition();
			r.PushStatisticText("View : " + viewPosition.ToString());
		}
	}
}

// �޽ø� �׸��� �Լ�
void SoftRenderer::DrawMesh3D(const Mesh& InMesh, const Matrix4x4& InMatrix, const LinearColor& InColor)
{
	size_t vertexCount = InMesh.GetVertices().size();
	size_t indexCount = InMesh.GetIndices().size();
	size_t triangleCount = indexCount / 3;

	// �������� ����� ���� ���ۿ� �ε��� ���۷� ��ȯ
	std::vector<Vertex3D> vertices(vertexCount);
	std::vector<size_t> indice(InMesh.GetIndices());
	for (size_t vi = 0; vi < vertexCount; ++vi)
	{
		vertices[vi].Position = Vector4(InMesh.GetVertices()[vi]);

		if (InMesh.HasColor())
		{
			vertices[vi].Color = InMesh.GetColors()[vi];
		}

		if (InMesh.HasUV())
		{
			vertices[vi].UV = InMesh.GetUVs()[vi];
		}
	}

	// ���� ��ȯ ����
	VertexShader3D(vertices, InMatrix);

	// �ﰢ�� ���� �׸���
	for (int ti = 0; ti < triangleCount; ++ti)
	{
		int bi0 = ti * 3, bi1 = ti * 3 + 1, bi2 = ti * 3 + 2;
		std::vector<Vertex3D> tvs = { vertices[indice[bi0]] , vertices[indice[bi1]] , vertices[indice[bi2]] };

		size_t triangles = tvs.size() / 3;
		for (size_t ti = 0; ti < triangles; ++ti)
		{
			size_t si = ti * 3;
			std::vector<Vertex3D> sub(tvs.begin() + si, tvs.begin() + si + 3);
			DrawTriangle3D(sub, InColor, FillMode::Color);
		}
	}
}

// �ﰢ���� �׸��� �Լ�
void SoftRenderer::DrawTriangle3D(std::vector<Vertex3D>& InVertices, const LinearColor& InColor, FillMode InFillMode)
{
	auto& r = GetRenderer();
	const GameEngine& g = Get3DGameEngine();

	LinearColor finalColor = _WireframeColor;
	if (InColor != LinearColor::Error)
	{
		finalColor = InColor;
	}

	r.DrawLine(InVertices[0].Position, InVertices[1].Position, finalColor);
	r.DrawLine(InVertices[0].Position, InVertices[2].Position, finalColor);
	r.DrawLine(InVertices[1].Position, InVertices[2].Position, finalColor);
}

