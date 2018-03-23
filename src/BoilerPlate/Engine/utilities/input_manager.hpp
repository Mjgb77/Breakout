#pragma once

#ifndef _INPUT_MANAGER_H_
#define _INPUT_MANAGER_H_

#define KEYCOUNT 256
#define _KEY_INVALID -2

namespace Engine
{
	namespace Input
	{

		class InputManager
		{
		public:
			/* =============================================================
			* STATIC FUNCTIONS
			* ============================================================= */
			static void Create();
			static void Destroy();
			static InputManager& Instance();

			/* =============================================================
			* PUBLIC FUNCTIONS
			* ============================================================= */
			bool is_key_down(unsigned char key);
			bool is_key_pressed(unsigned char key);
			bool is_key_released(unsigned char key) const;
			void key_down(unsigned char key);
			void key_up(unsigned char key);
			void reset_input();
			void Update();

			/* =============================================================
			* GETTER FUNCTIONS
			* ============================================================= */
			bool is_any_key_pressed() const { return m_isKeyPressed; }

			/* =============================================================
			* SETTER FUNCTIONS
			* ============================================================= */
			void set_key_pressed(bool isKeyPressed) { m_isKeyPressed = isKeyPressed; }

		private:
			/* =============================================================
			* CTOR
			* ============================================================= */
			InputManager();
			InputManager(InputManager const&) : m_isKeyPressed(false) {}

			/* =============================================================
			* OPERATORS
			* ============================================================= */
			InputManager& operator=(InputManager const&) {};

			/* =============================================================
			* MEMBERS
			* ============================================================= */
			bool m_currentKeys[KEYCOUNT];
			bool m_previousKeys[KEYCOUNT];
			bool m_isKeyPressed;
			static InputManager* s_instance;
		};
	}
}

/* =============================================================
* EXTERNS
* ============================================================= */
extern void OnKeyboardDownEvent(unsigned char key);
extern void OnKeyboardReleasedEvent(unsigned char key);
extern void KeyboardPollEvent();

#endif