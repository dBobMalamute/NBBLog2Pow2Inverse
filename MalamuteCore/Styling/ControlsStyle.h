#ifndef CONTROLSSTYLE_H
#define CONTROLSSTYLE_H

#include <QObject>
#include <QColor>
#include <QFont>

class ControlsStyle : public QObject
{
    Q_OBJECT
public:
    explicit ControlsStyle(QObject *parent = nullptr);

    Q_INVOKABLE int radius() const;

    Q_INVOKABLE int borderWidth() const;
    Q_INVOKABLE QColor borderColor() const;

    Q_INVOKABLE QColor gradientTop() const;
    Q_INVOKABLE QColor gradientMid() const;
    Q_INVOKABLE QColor gradientBottom() const;

    Q_INVOKABLE QColor textColor() const;
    Q_INVOKABLE QFont textFont() const;

private:
    int m_radius = 16;

    int m_borderWidth = 6;
    QColor m_borderColor = QColor("black");

    QColor m_gradientTop = QColor(0x232323);
    QColor m_gradientMid = QColor(0x3b3b3b);
    QColor m_gradientBottom = QColor(0x232323);

    QColor m_textColor = QColor(0xd36f2c);
    QFont m_textFont;
};

#endif // CONTROLSSTYLE_H
