//-------------------------------------------------------
// 作成者：金　淳元
// 作成日：2018.02.05
// 内容　：キャラクターのベースクラス
//-------------------------------------------------------
#pragma once
#include <Device\game_device.h>
#include <Device\MotionSystem\motion.h>
#include <Math\vector3.h>
#include <Math\collision_box.h>
#include <Character\side.h>
#include <Character\Controller\character_controller.h>
#include <Character\character_state.h>
#include <GameObject\Job\job_base.h>
#include <GameObject\AttackSystem\attack_mediator.h>
#include <GameObject\AttackSystem\attack.h>
#include <System\gravity.h>

namespace Character
{
	class CharacterBase
	{
	public:
		//コンストラクタ（位置、チーム、ID、Hp,controller, job, attackMediator）
		CharacterBase(Math::Vector3 position,Side side,int id,
			std::shared_ptr<VirtualController> controller,
			std::shared_ptr<Job::JobBase> job,
			std::shared_ptr<AttackSystem::AttackMediator> attackMediator);
		~CharacterBase();			//デストラクタ
		void Initialize(Math::Vector3 position);//初期化
		void Update();				//更新
		void Draw();				//モーション
		void Collide(const AttackSystem::Attack& atk);//あたり判定

	public:							//取得関連
		Side	GetSide();			//チームの取得
		int		GetHp();			//Hpの取得
		int		GetMaxHp();			//MAXHpの取得
		int		GetMp();			//Mpの取得
		int		GetID();			//IDの取得
		int		GetFaceNum();		//キャラクター画像順番取得
		int		GetPlayerNum();		//
		bool	IsRight();			//向きを返す
		bool	IsDead();			//死んだか？
		bool	IsInvincible();		//無敵フラグ
		string  GetSheetName();		//sheet名取得
		void	SetPosition(Math::Vector3 position);//位置の設定
		Math::Vector3					GetPosition();//位置の取得
		Math::CollisionBox				GetBox();
		std::shared_ptr<Job::JobBase>	GetCharacterJob();//Jobの取得
		void	SetWinner(bool isWinner);//勝利キャラクター設定
		
	private:						//更新関連
		void IntroUpdate();			//登場更新
		void Attack();				//攻撃
		void Skill();				//スキール
		void MoveUpdate();			//移動更新
		void JumpUpdate();			//Jump更新
		void MpUpdate();			//ゲージ更新
		void MotionUpdate();		//モーションの更新
		void StateUpdate();			//状態の更新
		void KnockCntUpdate();		//倒れ値カウント更新
		void PositionUpdate();		//位置の更新
		void DeadUpdate();			//死亡更新
		void WinnerUpdate();		//勝利キャラクター更新
			
		void ChangeSheet();			//キャラクター画像判定
		void SetColor();			//色設定

	private:
		int		m_hp;				
		int		m_mp;
		int		m_knock_value;		//倒れ値
		int		m_knock_cnt;		//一定時間攻撃を受けないと倒れ値が下がる
		int		m_skill_num;		//スキール入力段階
		int		m_skill_cnt;		//スキール入力カウント
		int		m_defence_value;	//防御値
		int		m_defence_max;		//防御最大値
		int		m_intro_cnt;		//登場カウント
		float	m_speed;
		int		m_id;
		int		m_character_face;	//UI用

		bool	m_isIntro_end;		//登場が終わったか
		bool	m_isDead;
		bool	m_isJump;
		bool	m_isRight;
		bool	m_isInvincible;		//無敵フラグ
		bool	m_isStop;			//攻撃状態とか攻撃を受けた時、入力による移動を防ぐ
		bool	m_isHit;			//攻撃を受けたか？
		bool	m_isWinner;			//勝利したか？
		bool	m_isEnd;			//終わったか？

		string  m_sheet_name;		//sheet名

		Side	m_side;
		CharacterState m_state;

		Math::Vector3 m_position;
		Math::Vector3 m_velocity;
		Math::Vector3 m_velocity_jump;		//jump
		Math::Vector3 m_velocity_intro;		//登場移動量
		Math::Vector3 m_size;

		std::shared_ptr<VirtualController>		m_controller;
		std::shared_ptr<MotionSystem::Motion>	m_motion;
		std::shared_ptr<Job::JobBase>			m_job;
		std::shared_ptr<Device::Sound>			m_sound;
		std::shared_ptr<AttackSystem::AttackMediator> m_attack_mediator;
		std::shared_ptr<System::Gravity>		m_gravity;
	};


}