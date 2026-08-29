# stc8-learning

STC8 增强型单片机课程的平时练习与实验记录。

## 目录结构

工程按课程进度编号（`demoNN_主题`），按主题归类如下：

- **基础外设**：demo00 工程模板、demo01 点灯、demo04 定时器、demo12 独立按键、demo13 数码管、demo14/15 蜂鸣器（Timer / PWM 驱动）
- **串口**：demo02 双设备透传、demo03 寄存器开发与中断、demo06 串口控制灯开关
- **PWM**：demo07 串口控制 LED 亮度、demo08 震动马达、demo09 舵机
- **ADC**：demo10 电位器电压采集、demo11 NTC 热敏电阻测温
- **RTC 与中断**：demo17/18 RTC 读写与 BCD 转换、demo20 RTC 闹钟、demo19 外部中断 EXTI
- **其他**：demo05 LED 灯组走马灯、demo16 阶段考试（8 月 26 日）

## 环境

- IDE：Keil C51（STC8 增强型系列）
- 烧录：STC-ISP

## 硬件

- STC8H8K64U芯片
- 为最小开发板，包含了最小系统，以及部分外设，所有引脚都已经引出，方便后续扩展使用。

## 说明

- 仓库只保留源代码与工程配置，编译产物（`Objects/`、`Listings/` 等）由 `.gitignore` 排除

- `.hex` 烧录文件保留提交，方便换电脑后直接用 STC-ISP 烧录

  
