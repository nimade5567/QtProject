#include <QCoreApplication>
#include <QMqttClient>
#include <QMqttTopicFilter>
#include <QMqttTopicName>
#include <QTimer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    QMqttClient client;
    client.setHostname("192.168.31.154");
    client.setPort(1883);
    client.setClientId("mqttx_8da0a9c3");

    QObject::connect(&client, &QMqttClient::connected, [&]() {
        qDebug() << "✅ MQTT connected";
        auto sub = client.subscribe(QMqttTopicFilter("a"));
        if (!sub) {
            qDebug() << "❌ Subscribe failed";
            return;
        }

        QObject::connect(sub, &QMqttSubscription::messageReceived,
                         [](const QMqttMessage &msg) {
            qDebug() << "📩 Received:"
                     << msg.topic().name()
                     << msg.payload();
        });

        QTimer::singleShot(1000, [&]() {
            client.publish(
                QMqttTopicName("a"),
                QByteArray("Hello from QtMqtt Console!")
            );
            qDebug() << "📤 Message published";
        });
    });

    QObject::connect(&client, &QMqttClient::disconnected, []() {
        qDebug() << "⚠️ MQTT disconnected";
    });

    client.connectToHost();

    return app.exec();
}
