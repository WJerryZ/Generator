# 学号生成器

> 一个供有选择困难症的教师上课时使用的~~杀人利器~~学号生成器

---

## 使用说明

* 建议在 Windows 系统的电子触屏白板上使用

* 在 \"人数\" 一项后的灰色文本框中输入班级的总人数，输入时，使用键盘或右侧虚拟键盘都可。点击 \"确定\" 后方可开始生成，此时窗口会变小，并总是浮于屏幕最上方

* 点击 \"生成\" 后，将在结果一项后的灰色文本框中显示随机生成结果

* \"允许重复抽取\" 一项标志着是否会在全班未抽完一轮的情况下，重复抽到同一个人。注意，此项默认为 \"是\"

* 双击窗体任意位置即可最小化为半透明悬浮窗，总是浮于屏幕最上方，双击悬浮窗可还原

* 图标为江苏省苏州中学附属苏州湾学校校徽（是不可以胡乱用的）

* 你可以从[这里](https://github.com/WJerryZ/Generator/releases/)获取程序

---

## 技术性说明

* GUI 使用 MFC (微软基础类库) 编写，可能写得不那么规范

* 随机算法直接使用了 C++ 标准库的`<random>`

