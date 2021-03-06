/*
 *   Copyright 2007-2008 Aaron Seigo <aseigo@kde.org>
 *   Copyright 2009 Marco Martin <notmart@gmail.com>
 *
 *   This program is free software; you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as
 *   published by the Free Software Foundation; either version 2,
 *   or (at your option) any later version.
 *
 *   This program is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details
 *
 *   You should have received a copy of the GNU Library General Public
 *   License along with this program; if not, write to the
 *   Free Software Foundation, Inc.,
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301, USA.
 */

#ifndef SINGLEVIEW_H
#define SINGLEVIEW_H

#include <QGraphicsView>

#include <Plasma/Plasma>

namespace Plasma
{
    class Containment;
    class Applet;
    class Corona;
} // namespace Plasma

class SingleView;

class SingleView : public QGraphicsView
{
    Q_OBJECT

public:
    SingleView(Plasma::Corona *corona, Plasma::Containment *containment, const QString &pluginName, int appletId, const QVariantList &appletArgs, QWidget *parent=0);
    ~SingleView();


    Plasma::Applet *applet();
    Plasma::Location location() const;
    Plasma::FormFactor formFactor() const;

public Q_SLOTS:
    void setContainment(Plasma::Containment *containment);
    void updateGeometry();

Q_SIGNALS:
    void locationChanged(const SingleView *view);
    void geometryChanged();
    void containmentActivated();
    void storeApplet(Plasma::Applet *applet);

protected:
    void resizeEvent(QResizeEvent *event);
    void closeEvent(QCloseEvent *event);

private:
    Plasma::Applet *m_applet;
    Plasma::Containment *m_containment;
    Plasma::Corona *m_corona;
};

#endif // multiple inclusion guard
