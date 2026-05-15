#pragma once
#include "CommonInclude.h"
/// <summary>
/// 언리얼의 Actor와 비슷한 개념으로, 게임에서 존재하는 모든 객체의 부모 클래스
/// </summary>

namespace je
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		void Update();
		void LateUpdate();
		void Render(HDC hdc);

		void SetPosition(float x, float y);

		float GetX() const { return mX; }
		float GetY() const { return mY; }

	private:
		// 게임 오브젝트의 좌표 정보 
		float mX;
		float mY;
	};
}

