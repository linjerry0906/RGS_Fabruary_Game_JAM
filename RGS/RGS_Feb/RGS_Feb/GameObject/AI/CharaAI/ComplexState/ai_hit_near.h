//-------------------------------------------------------------
// ์ฌาFัภb
// ์ฌ๚F2018.2.21
// เe@F฿ข^[QbgฦํคAiState
//-------------------------------------------------------------
#pragma once
#include <GameObject\AI\CharaAI\ai_state.h>

namespace Character
{
	class CharacterBase;
}

namespace AI
{
	class HitNear : public AiState
	{
	public:
		HitNear(std::shared_ptr<Character::CharacterBase> my_character, int difficulty);
		HitNear(const HitNear&);
		~HitNear();

		virtual void GetBattleInfo(MetaAI* meta_ai);
		virtual void Update(std::shared_ptr<Character::AiController> controller);
		virtual std::shared_ptr<AiState> NextState(int difficulty);

	private:
		std::shared_ptr<Character::CharacterBase> m_character;		//ฉ@
		std::shared_ptr<Character::CharacterBase> m_target;			//Target

		std::shared_ptr<AiState> m_trace;							//ว๖Ai
		std::shared_ptr<AiState> m_attack;							//UAi

		float m_difficulty;
	};
}
