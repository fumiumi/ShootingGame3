#include "pch.h"
#include "gtest/gtest.h"

/* Testクラスのテスト
* 要件
* メインループの処理を担当：タスクシステム
* 各タスクはタスクマネージャーで管理する
* タスクマネージャーで管理するすべてのオブジェクトの基底クラス
* プレイヤー、エネミー、エフェクトなど
* 必要なメソッド：
*   Update()
*   Render()
* 抽象クラスとして定義する。
* なので、Taskのテストは作らない
*/