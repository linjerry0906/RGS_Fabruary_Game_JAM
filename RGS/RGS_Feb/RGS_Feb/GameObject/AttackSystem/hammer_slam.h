//-------------------------------------------------------
// 作成者：シスワントレサ
// 作成日：2018.02.23
// 内容　：攻撃（ハンマースラム）の当たり判定
//-------------------------------------------------------

#pragma once
#include <GameObject\AttackSystem\attack.h>
#include <Utility\timer.h>
#include <Device\MotionSystem\motion.h>

namespace AttackSystem
{
	class HammerSlam : public Attack
	{
	public :
		///<summary>コンストラクタ</summary>
		///<param name = "side">キャラクターはどんなチームに属する</param>
		///<param name = "position">キャラクターの位置</param>
		///<param name = "size">攻撃の大きさ</param>
		///<param name = "side">キャラクターはどんなチームに属する</param>
		///<param name = "attack">攻撃ポイント</param>
		///<param name = "knockdown">敵を倒せられるか？</param>
		///<param name = "knockback">敵を押されるか？</param>
		///<param name = "life span">何秒に実現させるのか？</param>
		HammerSlam(Math::Vector3 position, Math::Vector2 size, Side side, int attack, int knockdown, int knockback, int dbreak, float life_span_timer);
		~HammerSlam();
		virtual std::vector<std::shared_ptr<Attack>> Collide();
		virtual void Update();
		virtual void Draw();

	private :
		int m_c_attack;
		int m_c_knockback;
		int m_c_dbreak;
		Utility::Timer m_life_span_timer;

		std::shared_ptr<MotionSystem::Motion> m_motion;
	};
}
