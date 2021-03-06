//-------------------------------------------------------------
// 作成者：林佳叡
// 作成日：2018.2.19
// 内容　：PunchCombo（小）のAiState
//-------------------------------------------------------------
#include <GameObject\AI\CharaAI\Combo\ai_combo_punch_less.h>

using namespace AI;

PunchComboWeak::PunchComboWeak()
{
	m_end_flag = false;
	m_random = Device::GameDevice::GetInstance()->GetRandom();
	m_timer = Utility::Timer(m_random->Next(3, 12) / 60.0f);
	m_current_combo = Combo::kPunch1;
}

PunchComboWeak::PunchComboWeak(const PunchComboWeak&)
{
}

PunchComboWeak::~PunchComboWeak()
{
	m_random = NULL;
}

void PunchComboWeak::GetBattleInfo(MetaAI* meta_ai)
{
	return;
}

void PunchComboWeak::ResetTimer()
{
	m_timer = Utility::Timer(m_random->Next(3, 13) / 60.0f);	//Combo接続時間は最大10フレーム
}

void PunchComboWeak::Update(std::shared_ptr<Character::AiController> controller)
{
	m_timer.Update();
	if (!m_timer.IsTime())										//行動フレーム以外はリターン
		return;

	if (m_current_combo == Combo::kPunch1 ||
		m_current_combo == Combo::kPunch2 ||
		m_current_combo == Combo::kPunch3)
	{
		controller->TriggerPunch();
		m_current_combo = static_cast<Combo>((int)m_current_combo + 1);
		ResetTimer();
		return;
	}
	if (m_current_combo == Combo::kDefence)
	{
		controller->Defence();
		m_current_combo = static_cast<Combo>((int)m_current_combo + 1);
		ResetTimer();
		return;
	}
	if (m_current_combo == Combo::kEnd)
	{
		m_end_flag = true;
		return;
	}
}

std::shared_ptr<AiState> PunchComboWeak::NextState(int difficulty)
{
	return make_shared<PunchComboWeak>();						//仮
}