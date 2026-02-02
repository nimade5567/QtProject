#include <QApplication>
#include <QWidget>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QCryptographicHash>
#include <QDebug>

// SHA256 加密函数（核心逻辑）
QString sha256Encrypt(const QString& input) {
    if (input.isEmpty()) return "";
    // 字符串转 UTF-8 字节数组，计算 SHA256 哈希，转十六进制字符串
    QByteArray hashResult = QCryptographicHash::hash(input.toUtf8(), QCryptographicHash::Sha256);
    return hashResult.toHex(); // 小写结果，如需大写：hashResult.toHex().toUpper()
}

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);

    // ========== 1. 创建主窗口 ==========
    QWidget window;
    window.setWindowTitle("SHA256 加密工具");
    window.resize(600, 200); // 窗口大小

    // ========== 2. 创建 UI 控件 ==========
    // 输入框（待加密文本）
    QLineEdit* inputEdit = new QLineEdit(&window);
    inputEdit->setPlaceholderText("请输入需要加密的文本（例如：123）");
    inputEdit->setStyleSheet("font-size: 14px; padding: 8px;");

    // 输出标签（加密结果）
    QLabel* outputLabel = new QLabel(&window);
    outputLabel->setStyleSheet("font-size: 14px; padding: 8px; color: #2196F3;");
    outputLabel->setText("加密结果：");

    // 按钮：转化 + 清除
    QPushButton* convertBtn = new QPushButton("转化", &window);
    QPushButton* clearBtn = new QPushButton("清除", &window);
    convertBtn->setStyleSheet("font-size: 14px; padding: 8px 20px; margin-right: 10px;");
    clearBtn->setStyleSheet("font-size: 14px; padding: 8px 20px;");

    // ========== 3. 布局排版 ==========
    // 按钮行布局
    QHBoxLayout* btnLayout = new QHBoxLayout();
    btnLayout->addWidget(convertBtn);
    btnLayout->addWidget(clearBtn);
    btnLayout->setAlignment(Qt::AlignCenter);

    // 主布局（垂直）
    QVBoxLayout* mainLayout = new QVBoxLayout(&window);
    mainLayout->addWidget(inputEdit);        // 第一行：输入框
    mainLayout->addWidget(outputLabel);      // 第二行：输出结果
    mainLayout->addLayout(btnLayout);        // 第三行：按钮
    mainLayout->setSpacing(20);              // 控件间距
    mainLayout->setContentsMargins(30, 30, 30, 30); // 窗口内边距

    window.setLayout(mainLayout);

    // ========== 4. 信号槽绑定（核心逻辑） ==========
    // 点击「转化」：加密并显示结果
    QObject::connect(convertBtn, &QPushButton::clicked, [&]() {
        QString inputText = inputEdit->text().trimmed(); // 获取输入文本（去空格）
        if (inputText.isEmpty()) {
            outputLabel->setText("加密结果：请输入有效文本！");
            return;
        }
        // 执行加密并更新输出
        QString encryptResult = sha256Encrypt(inputText);
        outputLabel->setText(QString("加密结果：%1").arg(encryptResult));
        qDebug() << "原始文本：" << inputText << " | SHA256结果：" << encryptResult;
    });

    // 点击「清除」：清空输入和输出
    QObject::connect(clearBtn, &QPushButton::clicked, [&]() {
        inputEdit->clear(); // 清空输入框
        outputLabel->setText("加密结果："); // 清空输出标签
    });

    // ========== 5. 显示窗口 ==========
    window.show();

    return a.exec();
}