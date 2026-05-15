#include "JEGameObject.h"
#include "JEInput.h"
#include "JETime.h"
namespace je
{
	GameObject::GameObject()
		:mX(0)
		,mY(0)
	{
	}

	GameObject::~GameObject()
	{
	}

	void GameObject::SetPosition(float x, float y)
	{
		mX = x;
		mY = y;
	}

	void GameObject::Update()
	{

		if (Input::GetKey(eKeyCode::A) == true)
		{
			mX -= 0.01f* Time::DeltaTime();
		}
		if (Input::GetKey(eKeyCode::D) == true)
		{
			mX += 0.01f* Time::DeltaTime();
		}
		if(Input::GetKey(eKeyCode::W) == true)
		{
			mY -= 0.01f * Time::DeltaTime();
		}
		if(Input::GetKey(eKeyCode::S) == true)
		{
			mY += 0.01f * Time::DeltaTime();
		}

	}

	void GameObject::LateUpdate()
	{

	}

	void GameObject::Render(HDC hdc)
	{

		Rectangle(hdc, 100 + mX, 100 + mY, 200 + mX, 200 + mY);
	}

}