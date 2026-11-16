/*
    SPDX-FileCopyrightText: 2023 Vlad Zahorodnii <vlad.zahorodnii@kde.org>

    SPDX-License-Identifier: GPL-2.0-or-later
*/

#pragma once

#include <Plasma/Plasma>
#include <QPointer>

class PanelView;

class AutoHideScreenEdge : public QObject
{
    Q_OBJECT

public:
    static AutoHideScreenEdge *create(PanelView *view);

    virtual void activate() = 0;
    virtual void deactivate() = 0;

    /**
     * Sets the minimum speed, in logical pixels per second, the pointer has to hit
     * the screen edge with to show the panel. 0 means any speed shows it.
     */
    virtual void setRevealVelocity(int velocity) = 0;

protected:
    AutoHideScreenEdge(PanelView *view);

    QPointer<PanelView> m_view;
};
