# SVD-From-Scratch

> C++ BMP文件读写器 + SVD图像压缩可视化项目 | 大一数学系，纯手搓，学习算法原理

## 当前进度

- ✅ BMP 文件读写器（纯手搓，支持 24bit 真彩色）
- ✅ 矩阵类（纯手搓，支持基本运算）
- ✅ 幂迭代法SVD

## 下一步

- 实现其他算法求解 SVD

## 为什么手搓

* 希望真正从每一行代码理解整个过程，不只是SVD，还有BMP读写

## 可视化成果

* BMP读取器：显示读入图片的基本信息
* SVD压缩：使用自适应幂迭代法SVD进行分块的图像压缩和图像重建

## 编译方法

* 使用 VSCode 按 `Ctrl+Shift+B`

## 使用方法

* BMP读取器：
  * 在 `img\`目录下准备一张24位真彩位图文件，命名为   `img1.bmp`
  * 在项目根目录下打开终端，输入 `.\bin\bmpRead.exe`运行，在终端查看输出
  * 或者双击根目录下 `run_bmpRead.bat`运行
* SVD可视化：
  * 在当前目录下准备一张24位真彩位图文件，命名为 `img1.bmp`
  * 在项目根目录下打开终端，输入 `.\bin\svd-image.exe`文件运行
  * 依次输入四个数，其中$l$是纯小数，其余是正整数
    * 分块高度$h$
    * 分块宽度$w$
    * 目标损失率$l$(使用Frobenius 范数损失)
    * 幂迭代次数$t$(一般为5-10)
  * 或者双击根目录下 `run_svd-image.bat`运行

## 预期效果

* BMP读取器：终端中输出文件 `img1.bmp`的如下字段：
  * `Format` 格式
  * `File_size` 文件大小
  * `Width` 图片宽度
  * `Height` 图片高度
  * `Bit_depth` 位深度
  * `Compression` 压缩格式
  * `Sizeimage` 颜色数据大小
  * `XPelsPerMeter` 横向分辨率
  * `YPelsPerMeter` 纵向分辨率
* SVD可视化： `img\`目录下 生成 `out.bmp`，展示重建的图像
