#include "JEApplication.h"
#include "JEInput.h"
#include "JETime.h"

namespace je
{
	Application::Application()
		:mHwnd(nullptr)
		,mHdc(nullptr)
		,mSpeed(0)
	{

	}
	Application::~Application()
	{

	}
	void Application::Initialize(HWND hwnd)
	{
		mHwnd = hwnd;
		mHdc = GetDC(mHwnd);

		mPlayer.SetPosition(100, 100);

		Input::Initialize();
		Time::Initialize();
	}
	void Application::Run()
	{
		Update();

		LateUpdate();

		Render();
	}
	void Application::Update()
	{
		Input::Update();

		Time::Update();

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		Time::Render(mHdc);
		mPlayer.Render(mHdc);
			
	}
}
