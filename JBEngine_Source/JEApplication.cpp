#include "JEApplication.h"
#include "JEInput.h"

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

		mPlayer.Update();
	}
	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{

		mPlayer.Render(mHdc);
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);

		(HBRUSH)SelectObject(mHdc, oldBrush);

		DeleteObject(brush);

		
	}
}
