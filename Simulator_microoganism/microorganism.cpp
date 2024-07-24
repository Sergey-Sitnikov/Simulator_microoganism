#include "microorganism.h"

Microorganism::Microorganism(const Microorganism* parent) {
    if (parent) {
        lifeTime = parent->lifeTime;
        reproductionTime = parent->reproductionTime;
    } else {
        lifeTime = QRandomGenerator::global()->bounded(5000, 15000);
        reproductionTime = QRandomGenerator::global()->bounded(2000, 5000);
    }
}

uint Microorganism::GetCountBak() {
    return _count_bak;
}

void Microorganism::SetCountBak(uint i) {
    _count_bak = i;
}

void Microorganism::run() {
    QTimer::singleShot(lifeTime, this, &Microorganism::die);
    reproductionTimer = new QTimer(this);
    connect(reproductionTimer, &QTimer::timeout, this, &Microorganism::reproduce);
    reproductionTimer->start(reproductionTime);
    emit sendStatus(QString("Микроорганизм создан. Время жизни: %1, Время до потомства: %2")
                    .arg(lifeTime).arg(reproductionTime));
}

void Microorganism::die() {
    emit sendStatus("Микроорганизм умер.");
    reproductionTimer->stop();
    emit organismDied();
    emit finished();
}

void Microorganism::reproduce() {
    emit sendStatus("Микроорганизм дал потомство.");
    emit organismBorn();
}

void Microorganism::applyAntibiotic() {
    int chance = QRandomGenerator::global()->bounded(0, 100);
    if (chance < 50) {
        die();
    }
}
