你们多干点，我就少干点，狠狠当帕鲁吧大家
## 1. 引言
### 1.1. 编写目的
通过此次课程设计使小组成员熟悉团队开发过程，在实践中学习相关技术并正确地转化为实践成果。在此次协同开发过程中我们不仅要积累开发技术，同时还要习惯在实际开发场景中如何与小组成员完成分工与合作，如何清晰地划分分工边界保证工作效率和准确性，以及准确高效地交流。项目的圆满完成，需要每一个小组成员理解传统的软件开发流程，掌握软件开发方法，理解设计思路，保证对接口意见统一避免冲突。
### 1.2. 背景
在本次项目的挑选中由于大部分小组成员在过往的专业实训中有过开发游戏类项目的经验，因此本次本小组选择的项目为飞行射击类游戏”雷霆战机“。
### 1.3. 定义
”雷霆战机“是一款飞行射击类游戏。在此游戏中，玩家需操控自己的战机发射子弹击毁敌对战机，同时控制自己的战机躲避来自敌方战机的子弹，在战胜一系列敌人后通过关卡获得胜利，涵盖飞行、射击、防御等多个方面。
## 2. 任务概述
## <a name="_toc33515634"></a>**2.1目标**
### 2.1.1 开发意图

雷霆战机作为一种国内经典的飞行射击小游戏，旨在为玩家提供一个有趣而又较简单的游戏环境。开发团队创造一个让玩家迅速沉浸其中的游戏体验，通过简单又不失难度的游戏机制和丰富的关卡内容，满足不同玩家的需求。

### 2.1.2. 应用目标

该游戏的目标用户包括怀旧游戏爱好者、寻求短暂娱乐的休闲玩家以及喜欢挑战和竞争的硬核玩家。

### 2.1.3.作用范围

游戏的作用范围广泛，提供了单人闯关、无尽模式和BOSS模式等多种玩法，在经典的基础上有所创新。

### 2.1.4. 开发背景

关于开发背景，雷霆战机继承了经典飞行射击游戏，并在此基础上进行了创新，添加了新的玩法元素。
## <a name="_toc33515635"></a>**2.2用户的特点**
《雷霆战机》的最终用户特点可以从以下几个方面进行分析：

操作人员的特点：

游戏爱好者：最终用户通常是对经典游戏有兴趣的玩家。

技术熟练度不一：操作人员的技术专长各不相同，有的是游戏高手，能够快速掌握游戏技巧，而有的可能只是寻求娱乐的普通玩家。

学习能力强：由于游戏中引入了用户操作的部分，虽然游戏内容简单易懂，但难度会不断上升，因此预期用户应具备一定的练习能力，能够通过练习获得成长。

维护人员的特点：

技术支持团队：维护人员通常是指游戏的技术支持团队，他们需要理解游戏内容与机制，以便对游戏进行持续的优化和维护。

软件的预期使用频度：

频繁使用：《雷霆战机》作为一款电子游戏，预期会有较高的使用频度，尤其是在游戏完成后，使用频率可能会显著增加。

持续参与：游戏设计上偏向于单机玩法，用户交互内容较少，这意味着玩家可能会更多地进行单人游戏，而不是频繁的多人互动。

综上所述，《雷霆战机》的最终用户特点包括对用户游戏偏好的理解、不同技术熟练度的操作人员、以及需要提供持续技术支持和维护的专业团队。这些特点对于软件的设计工作是重要的约束，需要在开发过程中予以充分考虑。

## 3.需求规定
 ### 3.1对功能的规定 

| 功能编号 | 1.1                                                              | 功能简述 | 子弹打中敌人 |
| -------- | ---------------------------------------------------------------- | -------- | ------------ |
| 前置条件 | 敌人未态且未死亡处于特殊状态                                     |          |
| 触发因素 | 玩家发射子弹                                                     |          |              |
| 执行动作 | 1.  检测子弹与敌人的碰撞。                                       |          |              |
| ^        | 2.  若子弹击中敌人，则敌人生命值减少。                           |          |              |
|          | 3.  判断敌人生命值是否为零。                                     |          |              |
| 例外情况 | 暂无                                                             |          |              |
| 后置条件 | 若敌人生命值为零，则判定玩家得分。                               |          |              |
| 备注     | 1.  若敌人生命值为零，弹出提示框用绿色字体显示"EnemyDefeated!"。 |          |              |
|          | 2.若玩家得分根据游戏模式弹出相应提示框。                         |          |              |


| 功能编号 | 1.2                                                 | 功能简述 | 玩家被打中 |
| -------- | --------------------------------------------------- | -------- | ---------- |
| 前置条件 | 玩家未处于特殊状态且未死亡                          |          |            |
| 触发因素 | 敌人发射子弹                                        |          |            |
| 执行动作 | 1.  检测敌人子弹与玩家的碰撞。                      |          |            |
|          | 2.  若敌人子弹击中玩家，则玩家生命值减少。          |          |            |
|          | 3.  判断玩家生命值是否为零。                        |          |            |
| 例外情况 | 暂无                                                |          |            |
| 后置条件 | 若玩家生命值为零，则判定玩家失败。                  |          |            |
| 备注     | 1.生命值为零，弹出提示框用红色字体显示"Game Over"。 |          |            |

| 功能编号 | 1.3                                                                  | 功能简述 | 玩家吃到特殊物品 |
| -------- | -------------------------------------------------------------------- | -------- | ---------------- |
| 前置条件 | 玩家未死亡                                                           |          |                  |
| 触发因素 | 玩家与特殊物品的碰撞                                                 |          |                  |
| 执行动作 | 1.  检测玩家与特殊物品的碰撞。                                       |          |                  |
|          | 2.  若玩家吃到特殊物品，则应用特殊效果，如增加生命值、提升攻击力等。 |          |                  |
| 例外情况 | 暂无                                                                 |          |                  |
| 后置条件 | 根据特殊效果调整玩家状态                                             |          |                  |
| 备注     | 1.  若特殊效果生效，弹出提示框显示特殊效果的内容。                   |          |                  |


| 功能编号 | 1.4                                                                                                            | 功能简述 | 玩家和敌人的移动 |
| -------- | -------------------------------------------------------------------------------------------------------------- | -------- | ---------------- |
| 前置条件 | 该局并未结束                                                                                                   |          |                  |
| 触发因素 | 玩家控制指令或游戏规定的敌人移动规则                                                                           |          |                  |
| 执行动作 | 1.  接收玩家控制指令，如键盘或手柄输入。                                                                       |          |                  |
|          | 2.  根据玩家输入调整玩家战机的位置和角度。                                                                     |          |                  |
|          | 3.  根据游戏规定的敌人移动规则，调整敌人战机的位置和角度。                                                     |          |                  |
| 例外情况 | 无                                                                                                             |          |                  |
| 后置条件 | 玩家和敌人移动到新位置                                                                                         |          |                  |
| 备注     | 1.玩家和敌人的移动应在游戏地图范围内进行，避免出界。2.  玩家战机的移动应具有实时响应性，以提供流畅的游戏体验。 |          |                  |

注：功能将根据后续开发需求进行完善

## 3.2对性能的规定 

### 3.2.1精度

**输入数据精度要求：**\
对于用户输入的控制指令，要求接收并解析的精度应达到至少小数点后两位的精确度，以确保准确的战机移动和射击操作。对于随机生成的道具位置，要求生成的坐标精度应至少保持在整数级别，以确保道具的准确出现在地图上的随机位置。

**输出数据精度要求：**

对于战机和子弹的位置信息，要求输出的精度应至少保持小数点后两位，以确保战机和子弹在地图上的移动轨迹显示流畅，不产生抖动或错位现象。

**传输过程中的精度：**

在客户端和服务器之间进行数据传输时，要求传输过程中的精度不损失，确保在不同端上的游戏状态和数据保持一致。

### 3.2.2时间特性要求

**响应时间：**

对用户输入的响应时间要求在100毫秒以内，以确保玩家操作的即时性和流畅性。

**更新处理时间：**

对于战机和子弹的更新处理时间要求在每帧不超过16毫秒，以确保游戏画面的流畅度和稳定性。 {#b.-更新处理时间对于战机和子弹的更新处理时间要求在每帧不超过16毫秒以确保游戏画面的流畅度和稳定性 .unnumbered}

**数据的转换和传送时间：**

在客户端和服务器之间进行数据转换和传送的时间要求在100毫秒以内，以确保游戏状态同步的及时性。 {#c.-数据的转换和传送时间在客户端和服务器之间进行数据转换和传送的时间要求在100毫秒以内以确保游戏状态同步的及时性 .unnumbered}

**解题时间：**

若游戏包含解谜或者计算类功能，要求解题时间在合理范围内，不超过5秒，以确保玩家体验的流畅和快捷。 {#d.-解题时间若游戏包含解谜或者计算类功能要求解题时间在合理范围内不超过5秒以确保玩家体验的流畅和快捷 .unnumbered}

### 3.2.3灵活性

**操作方式上的变化：**

软件应支持多种操作方式，包括键盘、鼠标、手柄等，以满足不同玩家的喜好和习惯。

**运行环境的变化：**

软件应能够在不同操作系统和平台上运行，包括Windows、macOS、Linux等，以适应不同用户的需求。

**同其他软件的接口的变化：**

软件应具有良好的接口设计，支持与其他软件的集成和交互，以实现更丰富的功能和用户体验。

**精度和有效时限的变化：**

软件应具有可配置的精度和有效时限参数，以便根据实际需求进行调整和优化。

**计划的变化或改进：**

软件应具有模块化和可扩展的设计，以便在需求变化或改进时能够快速灵活地进行调整和扩展。

## 3.3其他要求 

### 3.3.1 输人输出要求 

**输入数据类型：**

用户输入：控制指令、操作动作

随机生成：道具位置坐标

**输出数据类型：**

图形显示：战机、子弹、道具的位置和状态

控制输出量：游戏状态（胜利、失败、进行中）、提示信息

**输入媒体、格式、数值范围、精度：**

用户输入：键盘输入、鼠标输入，格式为ASCII码或相应编码，数值范围通常在游戏控制指令的范围内，精度保持至整数级别。

随机生成：随机数生成器生成，格式为整数坐标，数值范围在地图尺寸范围内，精度为整数级别。

**输出媒体、格式、数值范围、精度：**

图形显示：图形界面显示，格式为图形对象，数值范围根据地图尺寸和战机、子弹、道具的位置范围确定，精度为小数点后两位。

控制输出量：控制游戏状态和提示信息，格式为文本或弹窗，数值范围为游戏状态和提示信息的种类，精度为整数级别。

**必须标明的控制输出量及示例：**

游戏状态：胜利、失败、进行中

提示信息：击败敌方战机、获取道具

示例：弹出提示框显示"游戏结束，胜利！"、"获得加速道具！"

### 3.3.2 数据管理能力要求

**需要管理的文卷和记录个数：**

随着游戏进行，需要管理的战机、子弹、道具对象数量不断变化。

**表和文卷的大小规模：**

根据游戏地图大小和游戏对象数量估算，需要管理的数据规模通常在百至千级别。

**数据存储要求估算：**

根据游戏对象的增长趋势，进行存储容量的合理预估，以确保游戏的性能和稳定性。

### 3.3.3 故障处理要求

**可能的软件、硬件故障：**

软件：程序崩溃、逻辑错误、内存泄漏

硬件：硬盘故障、内存故障、显示器故障

**后果及处理要求：**

软件故障：可能导致游戏无法运行或运行异常，要求进行异常处理和错误提示，如记录错误日志并向用户显示错误信息。

硬件故障：可能导致数据丢失或游戏无法正常显示，要求在可能的情况下进行自动修复或提供用户手动修复选项，如重新加载游戏或重启系统。

### 3.3.4 其他专门要求 

**安全保密要求：**

确保用户数据和游戏信息的安全性和保密性，采取加密、权限控制等措施。

**使用方便要求：**

提供友好的用户界面和操作指南，确保用户可以轻松上手并享受游戏乐趣。

**可维护性、可补充性、易读性、可靠性、运行环境可转换性的特殊要求：**

采用模块化设计和清晰的代码结构，确保软件易于维护和扩展，具有良好的可读性和稳定性，能够在不同运行环境下运行并适应变化。

* ## 4. 运行环境规定
 * ### 4.1. 设备
  * 处理器：intel i3及以上
  * 内存容量：8G及以上
  * 外存容量：256G及以上
  * 联机或脱机：脱机
  * 媒体及其存储格式：exe文件
  * 输入设备：键盘、鼠标
  * 输出设备：显示屏

 * ### 4.2. 支持软件
  * 操作系统：windows 10及以上
  * 编译程序：VScode

 * ### 4.3. 接口
    暂无