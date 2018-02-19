//-------------------------------------------------------
// 作成者：廖啓勝
// 作成日：2018.02.05
// 内容：CollisionBoxの更新と描画
//-------------------------------------------------------
#include "attack_manager.h";
#include <Character\character_base.h>
#include "attack.h"

using namespace AttackSystem;
using namespace Math;

AttackManager::AttackManager()
{
	m_atk_list.clear();
	m_add_list.clear();
}

AttackManager::~AttackManager()
{
	m_atk_list.clear();
	m_add_list.clear();
}

void AttackManager::Initialize()
{
	m_atk_list.clear();
	m_add_list.clear();
}

void AttackManager::AddAttack(std::shared_ptr<Attack> atk)
{
	m_add_list.push_back(atk);
}

void AttackManager::AddAttack()
{
	for (auto atk : m_add_list)
	{
		m_atk_list.push_back(atk);
	}
	m_add_list.clear();
}

void AttackManager::Remove()
{
	//remove_ifは同じ
	for (std::vector<shared_ptr<Attack>>::iterator i = m_atk_list.begin(); i != m_atk_list.end();)
	{
		if ((*i)->IsEnd() == true) m_atk_list.erase(i);
		else ++i;
	}
}

bool AttackManager::IsCollision(std::shared_ptr<Attack> a, std::shared_ptr<Character::CharacterBase> c)
{
	//同じチームだったらreturn
	if (a->GetSide() == c->GetSide()) return false;

	//重複判定か？
	/*
	if (a->IsRepeat() == false)
	{
		int charaID = c->GetID();
		for (int ID : a->GetAttackedList)
		{
			if (ID == charaID) return false;
		}
	}
	*/

	//CollisionBox生成して判定
	CollisionBox atk_box = a->GetBox();
	CollisionBox c_box = CollisionBox(c->GetPosition() - Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2), c->GetPosition() + Vector3(Size::kCharaX / 2, Size::kCharaY / 2, Size::kCharaZ / 2));
	return atk_box.IsCollision(c_box);
}


void AttackManager::Update()
{
	AddAttack();

	for (auto atk : m_atk_list)
	{
		atk->Update();

		/*
		for (auto c : character_list)
		{
			if (IsCollision(a,c)
			{
				c.Collide();
				atk->Collide();
				atk->AddID(c.GetID());
			}
		}
		*/
	}

	Remove();
}

void AttackManager::Draw()
{
	for (auto atk : m_atk_list)
	{
		atk->Draw();
	}
}