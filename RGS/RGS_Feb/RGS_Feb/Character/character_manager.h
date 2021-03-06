//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.17
// 内容　：キャラクターマネージャー
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Character\character_base.h>
#include <GameObject\UI\chara_hp_ui.h>
#include <Math\vector3.h>

namespace Character
{
	class CharacterManager
	{
	public:
		CharacterManager();					//コンストラクタ
		void Initialize();					//初期化
		std::shared_ptr<CharacterBase> Add(Math::Vector3 position, Side side, 
			std::shared_ptr<VirtualController> controller,std::shared_ptr<Job::JobBase> job, 
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator);	//オブジェクトの追加
		void Update();						//更新
		void Draw();						//描画
		void Clear();						//キャラクターを全員削除
		bool GetEnd();
		std::vector<std::shared_ptr<CharacterBase>>& GetCharacterList();//キャラクターリストの取得
		std::vector<std::shared_ptr<CharacterBase>>& GetWinnerList();	//勝利キャラクターリストの取得

	private:
		void RemoveDeadCharacters();		//死亡キャラを削除

	private:
		std::vector<std::shared_ptr<CharacterBase>> m_character_list;	//キャラクターリスト
		std::vector<std::shared_ptr<CharacterBase>> m_add_characters;	//追加キャラクター
		std::vector<std::shared_ptr<CharacterBase>> m_winner_list;		//勝利キャラクター
		std::vector<std::shared_ptr<CharacterBase>> m_ui_list;			//HP,MPのUI用キャラクターリスト
		std::shared_ptr<UI::HpUI>					m_hp_ui;			//HP,MPのUIリスト

		bool m_isEnd;
		int m_id;
	};
}
