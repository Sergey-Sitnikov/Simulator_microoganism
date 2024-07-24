#include <QApplication>
#include <QThread>
#include <QVBoxLayout>
#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QTextEdit>
#include <QRandomGenerator>
#include <QLineEdit>
#include "microorganism.h"

uint totalBacteria = 0;

class MainWindow : public QWidget {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr) : QWidget(parent) {
        QVBoxLayout *layout = new QVBoxLayout(this);

        QLabel *label = new QLabel("Количество микроорганизмов (от 1 до 20):");
        layout->addWidget(label);

        QLineEdit *input = new QLineEdit();
        layout->addWidget(input);

        QPushButton *startButton = new QPushButton("Запустить Симулятор");
        layout->addWidget(startButton);
        connect(startButton, &QPushButton::clicked, this, [this, input]() {
            int count = input->text().toInt();
            startSimulation(count);
        });


        layout->addWidget(count_bak_t);

        statsTextEdit = new QTextEdit();
        layout->addWidget(statsTextEdit);

        QPushButton *antibioticButton = new QPushButton("Применить Антибиотик");
        layout->addWidget(antibioticButton);
        connect(antibioticButton, &QPushButton::clicked, this, &MainWindow::applyAntibiotic);

        setLayout(layout);
    }

private slots:
    void updateStatistics(const QString &stats) {
        statsTextEdit->append(stats);
    }

    void applyAntibiotic() {
        emit antibioticApplied();
    }

public slots:
    void updateTotalBacteriaText(uint count) {
        QString text = QString("Общее количество микроорганизмов: %1").arg(count);
        count_bak_t->setText(text);
    }

    void onOrganismDied() {
        totalBacteria--;
        emit updateTotalBacteria(totalBacteria);
    }

private:

    QLabel *count_bak_t = new QLabel("Количество микроорганизмов: 0");
    void startSimulation(int count) {
        if (count < 1 || count > 20) {
            return;
        }

        for (int i = 0; i < count; ++i) {
            Microorganism *org = new Microorganism();
            organisms.append(org);
            QThread *thread = new QThread();
            org->moveToThread(thread);

            connect(thread, &QThread::started, org, &Microorganism::run);
            connect(org, &Microorganism::finished, thread, &QThread::quit);
            connect(org, &Microorganism::sendStatus, this, &MainWindow::updateStatistics);
            connect(this, &MainWindow::antibioticApplied, org, &Microorganism::applyAntibiotic);
            connect(org, &Microorganism::organismBorn, this, &MainWindow::onOrganismBorn);
            connect(org, &Microorganism::organismDied, this, &MainWindow::onOrganismDied);

            thread->start();
            totalBacteria = i+1;
            emit updateTotalBacteriaText(totalBacteria);
        }
    }
    void onOrganismBorn() {
        totalBacteria++;
        emit updateTotalBacteria(totalBacteria);

        Microorganism *newOrg = new Microorganism(static_cast<Microorganism*>(sender()));
        QThread *thread = new QThread();
        newOrg->moveToThread(thread);

        connect(thread, &QThread::started, newOrg, &Microorganism::run);
        connect(newOrg, &Microorganism::finished, thread, &QThread::quit);
        connect(newOrg, &Microorganism::sendStatus, this, &MainWindow::updateStatistics);
        connect(this, &MainWindow::antibioticApplied, newOrg, &Microorganism::applyAntibiotic);
        connect(newOrg, &Microorganism::organismBorn, this, &MainWindow::onOrganismBorn);
        connect(newOrg, &Microorganism::organismDied, this, &MainWindow::onOrganismDied);

        thread->start();
    }


signals:
    void antibioticApplied();

    void updateTotalBacteria(uint count);

private:
    QTextEdit *statsTextEdit;
    QList<Microorganism*> organisms;
};

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);
    MainWindow mainWindow;
    QObject::connect(&mainWindow, &MainWindow::updateTotalBacteria, &mainWindow, &MainWindow::updateTotalBacteriaText);
    mainWindow.show();
    return app.exec();
}

#include "main.moc"
