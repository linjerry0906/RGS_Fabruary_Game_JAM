//-------------------------------------------------------------
// �쐬�ҁF�щ��b
// �쐬���F2018.2.19
// ���e�@�FKeyboard�Ő��䂷��L�����R���g���[���[
//-------------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\Controller\character_controller.h>

namespace Character 
{
	class KeyboardController : public VirtualController
	{
	public:
		KeyboardController();
		KeyboardController(const KeyboardController&);
		~KeyboardController();

		///<summary>�ړ���</summary>
		Math::Vector3 virtual Velocity();
		///<summary>Punch�����������H</summary>
		bool virtual IsPunchTrigger();
		///<summary>Kick�����������H</summary>
		bool virtual IsKickTrigger();
		///<summary>Run��������Ă��邩�H</summary>
		bool virtual IsRun();
		///<summary>Jump�����������H</summary>
		bool virtual IsJumpTrigger();
		///<summary>Defence��������Ă��邩�H</summary>
		bool virtual IsDefence();

	private:
		std::shared_ptr<Core::InputState> m_input;
	};
}