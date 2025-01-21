#pragma once
#include "Task.h"
#include "BulletBase.h"
#include <vector>
#include <unordered_map>

class BulletManager : public Task
{
public:
  enum class BulletKind
  {
    //’e‚Ìí—Ş‚Í‚±‚±‚ÅŠÇ—
    kPlayer,
    kEnemy,
  };

  BulletManager();
  ~BulletManager() = default;

  void Update(float delta_time) override;
  void Render() override;
  
  void Initialize(int player_bullet_num, int enemy_bullet_num);

  void FireBullet(BulletKind bullet_kind, int bullet_x, int bullet_y);

  void AddBullet(BulletKind bullet_kind, BulletBase *bullet);

  void Destroy();

  void LoadBulletImageHandle();

  using BulletList = std::vector<BulletBase *>;
  // BulletList‚Í“n‚·‚ªA’e‚Ì’Ç‰ÁAíœ‚Í‚³‚¹‚È‚¢
  // ‚½‚¾‚µA’e‚ÌXVA•`‰æ‚Í‹–‰Â
  const BulletList &GetBulletList(BulletKind bullet_kind) const;

private:
  std::unordered_map<BulletKind, BulletList> bullet_list_map_;

};