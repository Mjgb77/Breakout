#include "input_manager.hpp"

//
#include <algorithm>

namespace Engine
{
	namespace Input
	{
		InputManager* InputManager::s_instance = nullptr;

		InputManager::InputManager()
			: m_isKeyPressed(false)
		{
			// Initialize internal structures
			//
			std::generate(m_currentKeys, m_currentKeys + 256, []() { return false; });
			std::generate(m_previousKeys, m_previousKeys + 256, []() { return false; });
		}

		void InputManager::Update()
		{
			// Copy current keys to previous keys.
			//
			std::copy(m_currentKeys, m_currentKeys + KEYCOUNT, m_previousKeys);

		}

		void InputManager::Create()
		{
			if (!s_instance)
			{
				s_instance = new InputManager;
			}
		}

		void InputManager::Destroy()
		{
			if (s_instance)
			{
				// Delete the instance
				//
				delete s_instance;
				s_instance = nullptr;
			}
		}

		InputManager& InputManager::Instance()
		{
			if (!s_instance)
			{
				Create();
			}

			return *s_instance;
		}

		bool InputManager::is_key_down(unsigned char key)
		{
			return m_currentKeys[key];
		}

		bool InputManager::is_key_released(unsigned char key) const
		{
			return (m_currentKeys[key] == false && m_previousKeys[key] == true);
		}

		void InputManager::key_down(unsigned char key)
		{
			m_currentKeys[key] = true;
		}

		bool InputManager::is_key_pressed(unsigned char key)
		{
			return m_currentKeys[key] == true && !m_previousKeys[key];
		}

		void InputManager::key_up(unsigned char key)
		{
			m_previousKeys[key] = true;
			m_currentKeys[key] = false;
		}

		void InputManager::reset_input()
		{
			std::generate(m_previousKeys, m_previousKeys + 256, []() { return false; });
		}
	}
}

void on_keyboard_down_event(unsigned char key)
{
	Engine::Input::InputManager::Instance().set_key_pressed(true);
	Engine::Input::InputManager::Instance().key_down(key);
}

void on_keyboard_release_event(unsigned char key)
{
	Engine::Input::InputManager::Instance().set_key_pressed(false);
	Engine::Input::InputManager::Instance().key_up(key);
}

void KeyboardPollEvent()
{
	Engine::Input::InputManager::Instance().Update();
}


