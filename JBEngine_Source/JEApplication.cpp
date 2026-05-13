#include "JEApplication.h"


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
	}
	void Application::Run()
	{
		Update();

		LateUpdate();

		Render();
	}
	void Application::Update()
	{
	
		mSpeed += 0.01f;
	}
	void Application::LateUpdate()
	{
	}

	void Application::Render()
	{
		HBRUSH brush = CreateSolidBrush(RGB(0, 0, 255));
		HBRUSH oldBrush = (HBRUSH)SelectObject(mHdc, brush);

		Rectangle(mHdc, 100+mSpeed, 100, 200+mSpeed, 200);


		(HBRUSH)SelectObject(mHdc, oldBrush);

		DeleteObject(brush);

		
	}
}
