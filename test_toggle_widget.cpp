#include <QtTest/QtTest>
#include <QtWidgets>
#include <QDebug>

#include "toggle_widget.h"

class TestToggleWidget : public QObject {
  Q_OBJECT

private slots:

  void buttonTogglesLight();
};

void TestToggleWidget::buttonTogglesLight(){
  ToggleWidget widget;
  QPushButton * button = widget.findChild<QPushButton *>();
  QVERIFY(button != nullptr);

  widget.show();
  QVERIFY(!widget.isOn());

  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(widget.isOn());

  QTest::mouseClick(button, Qt::LeftButton);
  QVERIFY(!widget.isOn());
}

QTEST_MAIN(TestToggleWidget)
#include "test_toggle_widget.moc"
