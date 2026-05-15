#pragma once
#include "CommonInclude.h"

namespace je
{

	enum class eKeyState
	{
		Down,
		Pressed,
		Up,
		None,
	};
	
	enum class eKeyCode
	{
		Q, W, E, R, T, Y, U, I, O, P,
		A, S, D, F, G, H, J, K, L,
		Z, X, C, V, B, N, M, 
		Left, Right, Down , Up,
		End,
	};

	class Input
	{
	public:

		struct Key
		{
			eKeyCode KeyCode;
			eKeyState state;
			bool bPressed;
		};
		
		static void Initialize();
		static void Update();

		static bool GetKeyDown(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Down; }
		static bool GetkeyUp(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Up; };
		static bool GetKey(eKeyCode code) { return Keys[(UINT)code].state == eKeyState::Pressed; };

	private:
		static void CreateKeys();
		static void UpdateKeys();

	

		static void UpdateKey(Key& key);
		static bool IsKeyDown(eKeyCode code);
		static void UpdateKeyDown(Key& key);
		static void UpdateKeyUp(Key& key);

	private:
		static std::vector<Key> Keys;
	};
}


