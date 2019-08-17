#pragma once

#include "RE/Skyrim.h"


namespace Scaleform
{
	class LevelUpMenu : public RE::IMenu
	{
	public:
		using Base = RE::IMenu;
		using Result = RE::IMenu::Result;

		LevelUpMenu();
		virtual ~LevelUpMenu() = default;

		static void Register();
		static RE::IMenu* Create();
		static constexpr std::string_view Name();

		static void Open();
		static void Close();

		// IMenu
		virtual void Accept(RE::FxDelegateHandler::CallbackProcessor* a_cbReg) override;
		virtual Result ProcessMessage(RE::UIMessage* a_message) override;

	private:
		static void Close(const RE::FxDelegateArgs& a_params);
		static void Log(const RE::FxDelegateArgs& a_params);
		static void PlaySound(const RE::FxDelegateArgs& a_params);
		static void UpdatePlayerAV(const RE::FxDelegateArgs& a_params);

		void OnOpen();
		void OnClose();

		static constexpr char SWF_NAME[] = "levelupmenu";
	};


	constexpr std::string_view LevelUpMenu::Name()
	{
		return "LevelUp Menu";
	}
}