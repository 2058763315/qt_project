# qt_project

基于 **Qt 6.11.1 / C++17 / MinGW 64-bit** 的 Qt 桌面开发学习与练手项目合集。仓库以单个独立的小工程为单位，覆盖 Qt Widgets 的常用控件、绘图、多媒体、网络、数据库、串口与多线程等主题，每个工程都可在 Qt Creator 中直接打开编译运行。

---

## 目录结构

```
qt_project/
├── calculator        # 标准计算器
├── car               # 汽车仪表盘绘制（QPainter + Dial 联动）
├── wheel             # 方向盘/转轮旋转（QGraphicsScene 图形组）
├── sinewave          # 正弦波形绘制动画
├── text              # 文字水平滚动字幕
├── imgviewer         # 图片查看器（手动/自动轮播）
├── noclickbutton     # “捉弄人”的不可点击按钮（事件过滤器）
├── noclickbutton2    # “捉弄人”的不可点击按钮（重写按钮类）
├── notebook          # 记事本（新建/打开/保存/另存为）
├── csveditor         # CSV 表格编辑器
├── csveditor2        # CSV 表格编辑器（改进版）
├── sql               # SQLite 数据库增删查演示
├── mp3player         # MP3 音乐播放器（列表 + 播放模式）
├── mp3player_struct  # 基于结构体的 MP3 播放器（列表持久化）
├── mp4player         # 视频播放器
├── test              # 多媒体播放综合测试
├── server            # TCP 聊天服务器（监听 10086）
├── client            # TCP 聊天客户端
├── carserver         # 汽车远程控制服务器（TCP + SQL，监听 10086）
├── carclient         # 汽车远程控制客户端（仪表盘界面）
├── ProConThread      # 生产者-消费者多线程模型
└── driver            # 串口上位机调试工具
```

---

## 项目说明

### 基础控件与绘图

| 工程 | 说明 | 关键技术点 |
|------|------|-----------|
| `calculator` | 标准四则运算计算器，支持连续运算、退格、清屏、清零。 | 状态机式输入逻辑、连续等号运算 |
| `car` | 用 QPainter 绘制简易汽车仪表盘，拨动 Dial 控件联动指针角度。 | `QPainter` / `QPainterPath`、`paintEvent` |
| `wheel` | 用 Graphics 框架绘制可旋转的“方向盘/转轮”，通过 Dial 累计旋转角度。 | `QGraphicsScene` / `QGraphicsItemGroup`、累计角度计算 |
| `sinewave` | 动态绘制正弦波形，随时间变化形成滚动曲线动画。 | 定时器驱动 `paintEvent`、`QPainterPath` |
| `text` | 文本水平滚动显示（跑马灯字幕效果）。 | `QTimer`、文字宽度计算与偏移更新 |
| `imgviewer` | 图片查看器：上一张/下一张切换、自动轮播、停止。 | `QTimerEvent`、`QStringList` 播放列表 |
| `noclickbutton` | 鼠标靠近/按下时按钮会“逃跑”的趣味演示。 | 事件过滤器 `QObject::eventFilter` |
| `noclickbutton2` | 与 `noclickbutton` 功能一致，但通过重写按钮类实现。 | 自定义按钮类重写鼠标事件 |

### 文档与表格编辑

| 工程 | 说明 | 关键技术点 |
|------|------|-----------|
| `notebook` | 简易记事本：新建、打开、保存、另存为、退出。 | `QFileDialog` / `QFile`、未保存状态提示 |
| `csveditor` | CSV 表格编辑器：打开/保存 CSV，支持增删行/列、单元格编辑。 | `QStandardItemModel` + `QTableView` |
| `csveditor2` | 上一版改进版，界面与交互进一步完善。 | 同上 |
| `sql` | SQLite 数据库演示：向表中添加数据、执行查询并刷新表格。 | `QSqlDatabase` / `QSqlQuery` |

### 多媒体播放

| 工程 | 说明 | 关键技术点 |
|------|------|-----------|
| `mp3player` | MP3 音乐播放器：列表播放、播放/暂停/停止、静音、音量/进度控制。 | `QMediaPlayer` / `QAudioOutput` |
| `mp3player_struct` | 基于结构体管理的 MP3 播放器，播放列表支持持久化保存/读取。 | `QMediaPlayer`、列表序列化 |
| `mp4player` | 视频播放器：打开视频、列表管理、多种播放模式。 | `QMediaPlayer` / `QVideoWidget` / `QAudioOutput` |
| `test` | 多媒体播放综合测试工程（含多种控件与事件演示）。 | 控件交互、播放控制 |

### 网络通信

| 工程 | 说明 | 关键技术点 |
|------|------|-----------|
| `server` | TCP 聊天服务器，监听本机 `10086` 端口，接受客户端连接。 | `QTcpServer` / `QTcpSocket` |
| `client` | TCP 聊天客户端，可填写服务器 IP 与端口进行连接、收发消息。 | `QTcpSocket` |
| `carserver` | 汽车远程控制服务器，监听 `10086`，为每个连接弹出数据对话框。 | `QTcpServer`、多连接管理 |
| `carclient` | 汽车远程控制客户端：以图形仪表盘呈现车速、油门、刹车、档位、灯光、车门、安全带等状态。 | `QTcpSocket`、`QGraphicsScene` 仪表盘绘制 |

> 说明：`server`/`client` 与 `carserver`/`carclient` 是两组独立示例，但端口均为 `10086`，不要同时占用同一端口。

### 并发与串口

| 工程 | 说明 | 关键技术点 |
|------|------|-----------|
| `ProConThread` | 生产者-消费者多线程模型示例。 | 多线程、生产者-消费者同步 |
| `driver` | 串口上位机调试工具：选择串口、发送指令、按行解析并回显状态。 | `QSerialPort`、粘包拆行、正则解析 |

---

## 环境要求

- **Qt 6.11.1**（或兼容的 Qt 6.x）
- **MinGW 64-bit** 工具链
- **C++17**
- 建议使用 **Qt Creator** 打开各工程的 `.pro` 文件直接构建运行

> 提示：`mp3player`、`mp3player_struct`、`mp4player` 中默认音乐/视频目录路径硬编码为 `D:/音乐/music`，如需在其他机器运行请自行调整。

---

## 如何构建与运行

1. 使用 Qt Creator 打开任一工程的 `.pro` 文件（如 `calculator/calculator.pro`）。
2. 选择 **Desktop Qt 6.11.1 MinGW 64-bit** 套件。
3. 点击「构建」→「运行」。

或者使用命令行（以 `calculator` 为例）：

```bash
cd calculator
qmake
mingw32-make        # 或 make
./calculator
```

---

## 相关说明

- 各工程相互独立，无相互依赖，可单独拷贝使用。
- 源码均以 `main.cpp + 窗口类(.h/.cpp/.ui)` 的经典 Qt Widgets 结构组织。
- 仓库已使用 Git 管理（当前仅有两个提交）。
- `build/` 与 `.qtcreator` 等目录为 Qt Creator 的本地构建缓存产物，不属于源码。

---

## License

本项目为个人学习与练手代码，仅用于学习交流。
