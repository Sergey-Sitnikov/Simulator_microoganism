#ifndef MICROORGANISM_H
#define MICROORGANISM_H

#include <QObject>
#include <QTimer>
#include <QRandomGenerator>

class Microorganism : public QObject {
    Q_OBJECT

public:
    Microorganism(const Microorganism* parent = nullptr);
    uint GetCountBak();
    void SetCountBak(uint i);

signals:
    void organismBorn();
    void organismDied();
    void sendStatus(const QString &status);
    void finished();

public slots:
    void run();
    void die();
    void reproduce();
    void applyAntibiotic();

private:
    uint _count_bak;
    int lifeTime;
    int reproductionTime;
    QTimer *reproductionTimer;
};

#endif // MICROORGANISM_H
